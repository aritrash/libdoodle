#pragma once

/**
 * @file export.hpp
 * @brief Export definitions for libdoodle.
 *
 * @author Aritrash Sarkar
 * @copyright Copyright (c) 2026
 */

#include <string>

namespace doodle
{
    enum class ExportFormat
    {
        PNG,
        SVG,
        PDF
    };

    inline constexpr const char* extension(ExportFormat format)
    {
        switch (format)
        {
            case ExportFormat::PNG: return ".png";
            case ExportFormat::SVG: return ".svg";
            case ExportFormat::PDF: return ".pdf";
        }

        return "";
    }
}