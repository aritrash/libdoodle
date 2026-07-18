#include "gnuplot.hpp"

#include <cstdlib>
#include <filesystem>
#include <fstream>

namespace doodle
{
    GnuplotBackend::GnuplotBackend(std::string stem)
        : data_file_(std::move(stem) + ".dat"),
        script_file_(std::move(stem) + ".gp")
    {
    }
    const std::string& GnuplotBackend::data_file() const
    {
        return data_file_;
    }
    bool GnuplotBackend::write_xy_data(const std::vector<double>& x,
                                       const std::vector<double>& y)
    {
        if (x.size() != y.size())
            return false;

        std::ofstream out(data_file_);

        if (!out)
            return false;

        for (std::size_t i = 0; i < x.size(); ++i)
            out << x[i] << ' ' << y[i] << '\n';

        return true;
    }

    bool GnuplotBackend::write_bar_data(const std::vector<std::string>& labels,
                                        const std::vector<double>& values)
    {
        if (labels.size() != values.size())
            return false;

        std::ofstream out(data_file_);

        if (!out)
            return false;

        for (std::size_t i = 0; i < labels.size(); ++i)
            out << '"' << labels[i] << "\" " << values[i] << '\n';

        return true;
    }

    bool GnuplotBackend::write_single_data(const std::vector<double>& values)
    {
        std::ofstream out(data_file_);

        if (!out)
            return false;

        for (double value : values)
            out << value << '\n';

        return true;
    }

    bool GnuplotBackend::write_script(const std::string& script)
    {
        std::ofstream out(script_file_);

        if (!out)
            return false;

        out << script;

        return true;
    }

    bool GnuplotBackend::run_script()
    {
        std::string command = "gnuplot \"" + script_file_ + "\"";
        return std::system(command.c_str()) == 0;
    }

    void GnuplotBackend::cleanup()
    {
        std::filesystem::remove(data_file_);
        std::filesystem::remove(script_file_);
    }
}