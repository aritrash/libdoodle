#pragma once

/**
 * @file flowchart.hpp
 * @brief Flowchart generation for libdoodle.
 *
 * @author Aritrash Sarkar
 * @copyright Copyright (c) 2026
 */

#include <string>

#include <doodle/color.hpp>
#include <doodle/diagram.hpp>

namespace doodle
{
    class Flowchart
    {
    public:
        explicit Flowchart(unsigned int width = 1200, unsigned int height = 800);

        void start(double x, double y,
                   double width, double height,
                   const std::string& text);

        void process(double x, double y,
                     double width, double height,
                     const std::string& text);

        void decision(double x, double y,
                      double width, double height,
                      const std::string& text);

        void end(double x, double y,
                 double width, double height,
                 const std::string& text);

        void connect(double x1, double y1,
                     double x2, double y2);

        void label(double x, double y,
                   const std::string& text);

        bool export_svg(const std::string& filename) const;

    private:
        Diagram diagram_;
    };
}