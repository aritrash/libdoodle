#include <doodle/plot.hpp>
#include "gnuplot.hpp"

#include <sstream>

namespace doodle
{

Plot::Plot()
    : type_(PlotType::None)
{
}

Plot& Plot::title(const std::string& title)
{
    title_ = title;
    return *this;
}

Plot& Plot::xlabel(const std::string& label)
{
    xlabel_ = label;
    return *this;
}

Plot& Plot::ylabel(const std::string& label)
{
    ylabel_ = label;
    return *this;
}

Plot& Plot::theme(Theme theme)
{
    style_.theme = theme;
    return *this;
}

Plot& Plot::grid(bool enable)
{
    style_.grid = enable;
    return *this;
}

Plot& Plot::legend(bool enable)
{
    style_.legend = enable;
    return *this;
}

Plot& Plot::line(const std::vector<double>& x,
                 const std::vector<double>& y)
{
    type_ = PlotType::Line;

    series_.clear();

    Series s;
    s.x = x;
    s.y = y;

    series_.push_back(std::move(s));

    labels_.clear();
    values_.clear();

    return *this;
}

Plot& Plot::scatter(const std::vector<double>& x,
                    const std::vector<double>& y)
{
    type_ = PlotType::Scatter;

    series_.clear();

    Series s;
    s.x = x;
    s.y = y;

    series_.push_back(std::move(s));

    labels_.clear();
    values_.clear();

    return *this;
}

Plot& Plot::bar(const std::vector<std::string>& labels,
                const std::vector<double>& values)
{
    type_ = PlotType::Bar;

    series_.clear();

    labels_ = labels;
    values_ = values;

    return *this;
}

Plot& Plot::histogram(const std::vector<double>& values)
{
    type_ = PlotType::Histogram;

    series_.clear();

    labels_.clear();
    values_ = values;

    return *this;
}

Plot& Plot::pie(const std::vector<std::string>& labels,
                const std::vector<double>& values)
{
    type_ = PlotType::Pie;

    series_.clear();

    labels_ = labels;
    values_ = values;

    return *this;
}

bool Plot::export_png(const std::string& filename)
{
    return export_impl(
        filename,
        "pngcairo enhanced size 1200,800"
    );
}

bool Plot::export_svg(const std::string& filename)
{
    return export_impl(
        filename,
        "svg size 1200,800 dynamic"
    );
}

bool Plot::export_pdf(const std::string& filename)
{
    return export_impl(
        filename,
        "pdfcairo"
    );
}

bool Plot::export_impl(const std::string& filename,
                       const std::string& terminal)
{
    GnuplotBackend backend("plot");

    std::ostringstream script;

    script << "set terminal " << terminal << '\n';
    script << "set output '" << filename << "'\n";

    if (!title_.empty())
        script << "set title '" << title_ << "'\n";

    if (!xlabel_.empty())
        script << "set xlabel '" << xlabel_ << "'\n";

    if (!ylabel_.empty())
        script << "set ylabel '" << ylabel_ << "'\n";

    if (style_.grid)
        script << "set grid\n";

    const std::string& data = backend.data_file();

    switch (type_)
    {
                case PlotType::Line:
        {
            if (series_.empty())
                return false;

            if (!backend.write_xy_data(series_[0].x, series_[0].y))
                return false;

            script << "plot '" << data
                   << "' using 1:2 with lines "
                   << "lw " << style_.line_width
                   << " title '"
                   << (series_[0].label.empty() ? "Data" : series_[0].label)
                   << "'\n";

            break;
        }

        case PlotType::Scatter:
        {
            if (series_.empty())
                return false;

            if (!backend.write_xy_data(series_[0].x, series_[0].y))
                return false;

            script << "plot '" << data
                   << "' using 1:2 with points "
                   << "pt 7 ps 1.5 "
                   << "title '"
                   << (series_[0].label.empty() ? "Data" : series_[0].label)
                   << "'\n";

            break;
        }

        case PlotType::Bar:
        {
            if (!backend.write_bar_data(labels_, values_))
                return false;

            script << "set style data histograms\n";
            script << "set style fill solid 1.0 border -1\n";
            script << "set boxwidth 0.8\n";
            script << "plot '" << data
                   << "' using 2:xtic(1) notitle\n";

            break;
        }

        case PlotType::Histogram:
        {
            if (!backend.write_single_data(values_))
                return false;

            script << "set boxwidth 0.9\n";
            script << "set style fill solid\n";
            script << "binwidth = 1\n";
            script << "bin(x,width)=width*floor(x/width)+width/2.0\n";
            script << "plot '" << data
                   << "' using (bin($1,binwidth)):(1.0) smooth freq "
                   << "with boxes notitle\n";

            break;
        }

        case PlotType::Pie:
        {
            // Gnuplot has no native pie chart support.
            // For v0.1 we generate a simple labelled histogram instead.

            if (!backend.write_bar_data(labels_, values_))
                return false;

            script << "set style data histograms\n";
            script << "set style fill solid 1.0 border -1\n";
            script << "set boxwidth 0.8\n";
            script << "plot '" << data
                   << "' using 2:xtic(1) notitle\n";

            break;
        }

        case PlotType::None:
        default:
            return false;
    }

    if (!backend.write_script(script.str()))
        return false;

    bool success = backend.run_script();

    backend.cleanup();

    return success;
}

} // namespace doodle