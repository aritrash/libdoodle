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
        series_.push_back({x, y, ""});

        labels_.clear();

        return *this;
    }

    Plot& Plot::scatter(const std::vector<double>& x,
                        const std::vector<double>& y)
    {
        type_ = PlotType::Scatter;

        series_.clear();
        series_.push_back({x, y, ""});

        labels_.clear();

        return *this;
    }

    Plot& Plot::bar(const std::vector<std::string>& labels,
                    const std::vector<double>& values)
    {
        type_ = PlotType::Bar;

        labels_ = labels;
        y_ = values;

        x_.clear();

        return *this;
    }

    Plot& Plot::histogram(const std::vector<double>& values)
    {
        type_ = PlotType::Histogram;

        y_ = values;

        x_.clear();
        labels_.clear();

        return *this;
    }

    Plot& Plot::pie(const std::vector<std::string>& labels,
                    const std::vector<double>& values)
    {
        type_ = PlotType::Pie;

        labels_ = labels;
        y_ = values;

        x_.clear();

        return *this;
    }
}

namespace
{
    std::string terminal_string(const std::string& extension)
    {
        if (extension == "png")
            return "pngcairo enhanced size 1200,800";

        if (extension == "svg")
            return "svg size 1200,800 dynamic";

        if (extension == "pdf")
            return "pdfcairo";

        return "";
    }
}

bool doodle::Plot::export_png(const std::string& filename)
{
    return export_impl(filename, "png");
}

bool doodle::Plot::export_svg(const std::string& filename)
{
    return export_impl(filename, "svg");
}

bool doodle::Plot::export_pdf(const std::string& filename)
{
    return export_impl(filename, "pdf");
}