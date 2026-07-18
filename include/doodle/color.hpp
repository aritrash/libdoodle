#pragma once

/**
 * @file color.hpp
 * @brief Color definitions for libdoodle.
 *
 * @author Aritrash Sarkar
 * @copyright Copyright (c) 2026
 */

#include <cstdint>

namespace doodle
{
    struct Color
    {
        std::uint8_t r;
        std::uint8_t g;
        std::uint8_t b;
    };

    namespace colors
    {
        inline constexpr Color Black      {  0,   0,   0};
        inline constexpr Color White      {255, 255, 255};

        inline constexpr Color Red        {220,  53,  69};
        inline constexpr Color Green      { 40, 167,  69};
        inline constexpr Color Blue       {  0, 123, 255};

        inline constexpr Color Orange     {253, 126,  20};
        inline constexpr Color Yellow     {255, 193,   7};
        inline constexpr Color Purple     {111,  66, 193};

        inline constexpr Color Cyan       { 23, 162, 184};
        inline constexpr Color Magenta    {214,  51, 132};

        inline constexpr Color Gray       {108, 117, 125};
        inline constexpr Color LightGray  {222, 226, 230};
        inline constexpr Color DarkGray   { 52,  58,  64};
    }
}