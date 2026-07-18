#pragma once

/**
 * @file svg.hpp
 * @brief Internal SVG canvas for libdoodle.
 *
 * @author Aritrash Sarkar
 * @copyright Copyright (c) 2026
 */

#include <fstream>
#include <string>

#include <doodle/color.hpp>

namespace doodle
{
    class SvgCanvas
    {
    public:
        SvgCanvas(unsigned int width = 1200, unsigned int height = 800);

        void rectangle(double x, double y, double width, double height,
                       const Color& stroke = colors::Black,
                       const Color& fill = colors::White,
                       double stroke_width = 2.0);

        void rounded_rectangle(double x, double y, double width, double height,
                               double radius,
                               const Color& stroke = colors::Black,
                               const Color& fill = colors::White,
                               double stroke_width = 2.0);

        void diamond(double cx, double cy, double width, double height,
                     const Color& stroke = colors::Black,
                     const Color& fill = colors::White,
                     double stroke_width = 2.0);

        void line(double x1, double y1, double x2, double y2,
                  const Color& stroke = colors::Black,
                  double stroke_width = 2.0);

        void arrow(double x1, double y1, double x2, double y2,
                   const Color& stroke = colors::Black,
                   double stroke_width = 2.0);

        void text(double x, double y,
                  const std::string& value,
                  unsigned int font_size = 16,
                  const Color& color = colors::Black,
                  const std::string& font = "Arial");

        bool save(const std::string& filename) const;

    private:
        unsigned int width_;
        unsigned int height_;

        std::string body_;

        static std::string rgb(const Color& color);
    };
}