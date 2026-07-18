#pragma once

/**
 * @file style.hpp
 * @brief Plot and diagram styling definitions.
 *
 * @author Aritrash Sarkar
 * @copyright Copyright (c) 2026
 */

#include <string>

namespace doodle
{
    enum class Theme
    {
        Default,
        IEEE,
        Dark,
        Presentation
    };

    enum class LineStyle
    {
        Solid,
        Dashed,
        Dotted,
        DashDot
    };

    enum class MarkerStyle
    {
        None,
        Circle,
        Square,
        Triangle,
        Diamond,
        Cross,
        Plus
    };

    struct Style
    {
        Theme theme = Theme::Default;

        std::string font = "Arial";
        unsigned int font_size = 12;

        double line_width = 2.0;

        LineStyle line_style = LineStyle::Solid;
        MarkerStyle marker_style = MarkerStyle::None;

        bool grid = true;
        bool legend = true;
    };
}