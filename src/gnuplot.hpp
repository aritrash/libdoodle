#pragma once

/**
 * @file gnuplot.hpp
 * @brief Internal Gnuplot backend for libdoodle.
 *
 * This file is not part of the public API.
 *
 * @author Aritrash Sarkar
 * @copyright Copyright (c) 2026
 */

#include <string>
#include <vector>

namespace doodle
{
    class GnuplotBackend
    {
    public:
        explicit GnuplotBackend(std::string stem = "doodle");
        bool write_xy_data(const std::vector<double>& x,
                           const std::vector<double>& y);

        bool write_bar_data(const std::vector<std::string>& labels,
                            const std::vector<double>& values);

        bool write_single_data(const std::vector<double>& values);

        bool write_script(const std::string& script);

        bool run_script();
        const std::string& data_file() const;

        void cleanup();

    private:
            std::string data_file_;
            std::string script_file_;
    };
}