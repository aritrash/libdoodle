#pragma once

/**
 * @file plot.hpp
 * @brief Plotting interface for libdoodle.
 *
 * @author Aritrash Sarkar
 * @copyright Copyright (c) 2026
 */

#include <string>
#include <vector>

#include <doodle/style.hpp>

namespace doodle
{
    class Plot
    {
    public:
        Plot();

        Plot& title(const std::string& title);
        Plot& xlabel(const std::string& label);
        Plot& ylabel(const std::string& label);

        Plot& theme(Theme theme);
        Plot& grid(bool enable = true);
        Plot& legend(bool enable = true);

        Plot& line(const std::vector<double>& x,
                   const std::vector<double>& y);

        Plot& scatter(const std::vector<double>& x,
                      const std::vector<double>& y);

        Plot& bar(const std::vector<std::string>& labels,
                  const std::vector<double>& values);

        Plot& histogram(const std::vector<double>& values);

        Plot& pie(const std::vector<std::string>& labels,
                  const std::vector<double>& values);

        bool export_png(const std::string& filename);
        bool export_svg(const std::string& filename);
        bool export_pdf(const std::string& filename);

    private:

        struct Series
        {
            std::vector<double> x;
            std::vector<double> y;
            std::string label;
        };

        enum class PlotType
        {
            None,
            Line,
            Scatter,
            Bar,
            Histogram,
            Pie
        };

        PlotType type_;

        std::string title_;
        std::string xlabel_;
        std::string ylabel_;

        Style style_;

        std::vector<Series> series_;

        std::vector<std::string> labels_;
        std::vector<double> values_;
    };
}