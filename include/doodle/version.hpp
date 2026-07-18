#pragma once

/**
 * @file version.hpp
 * @brief Version information for libdoodle.
 *
 * @author Aritrash Sarkar
 * @copyright Copyright (c) 2026
 */

#include <cstdint>

namespace doodle
{
    inline constexpr std::uint32_t VersionMajor = 0;
    inline constexpr std::uint32_t VersionMinor = 1;
    inline constexpr std::uint32_t VersionPatch = 0;

    inline constexpr const char* VersionString = "0.1.0";
}