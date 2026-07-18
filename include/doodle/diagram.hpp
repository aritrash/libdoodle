#pragma once

/**
 * @file diagram.hpp
 * @brief Block diagram generation for libdoodle.
 *
 * @author Aritrash Sarkar
 * @copyright Copyright (c) 2026
 */

#include <string>

#include <doodle/color.hpp>

namespace doodle
{
    class Diagram
    {
    public:
        explicit Diagram(unsigned int width = 1200, unsigned int height = 800);

        void block(double x, double y,
                   double width, double height,
                   const std::string& label,
                   const Color& stroke = colors::Black,
                   const Color& fill = colors::White);

        void rounded_block(double x, double y,
                           double width, double height,
                           const std::string& label,
                           const Color& stroke = colors::Black,
                           const Color& fill = colors::White);

        void diamond(double cx, double cy,
                     double width, double height,
                     const std::string& label,
                     const Color& stroke = colors::Black,
                     const Color& fill = colors::White);

        void connect(double x1, double y1,
                     double x2, double y2);

        void label(double x, double y,
                   const std::string& text);

        bool export_svg(const std::string& filename) const;

    private:
        class SvgCanvas;
        SvgCanvas* canvas_;
    };
}