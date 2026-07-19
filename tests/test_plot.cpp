#include <doodle.hpp>

#include <iostream>
#include <vector>

int main()
{
    std::cout << "========================================\n";
    std::cout << "libdoodle Plot Test\n";
    std::cout << "========================================\n\n";

    std::vector<double> x
    {
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
    };

    std::vector<double> y
    {
        0, 1, 4, 9, 16, 25, 36, 49, 64, 81, 100
    };

    doodle::Plot plot;

    plot.title("Quadratic Function")
        .xlabel("x")
        .ylabel("x²")
        .grid(true)
        .line(x, y);

    if (!plot.export_png("line_plot.png"))
    {
        std::cerr << "ERROR: Failed to generate line_plot.png\n";
        return EXIT_FAILURE;
    }

    std::cout << "Generated line_plot.png successfully.\n";

    doodle::Plot scatter;

    scatter.title("Scatter Plot")
           .xlabel("x")
           .ylabel("x²")
           .grid(true)
           .scatter(x, y);

    if (!scatter.export_png("scatter_plot.png"))
    {
        std::cerr << "ERROR: Failed to generate scatter_plot.png\n";
        return EXIT_FAILURE;
    }

    std::cout << "Generated scatter_plot.png successfully.\n";

    std::vector<std::string> labels
    {
        "CPU",
        "GPU",
        "FPGA",
        "ASIC"
    };

    std::vector<double> values
    {
        15,
        40,
        28,
        60
    };

    doodle::Plot bar;

    bar.title("Execution Performance")
       .ylabel("Score")
       .bar(labels, values);

    if (!bar.export_png("bar_chart.png"))
    {
        std::cerr << "ERROR: Failed to generate bar_chart.png\n";
        return EXIT_FAILURE;
    }

    std::cout << "Generated bar_chart.png successfully.\n";

    std::vector<double> histogram
    {
        1,2,2,3,3,3,4,4,4,4,
        5,5,5,6,6,7,7,8,9,10
    };

    doodle::Plot hist;

    hist.title("Histogram")
        .xlabel("Value")
        .ylabel("Frequency")
        .histogram(histogram);

    if (!hist.export_png("histogram.png"))
    {
        std::cerr << "ERROR: Failed to generate histogram.png\n";
        return EXIT_FAILURE;
    }

    std::cout << "Generated histogram.png successfully.\n";

    std::cout << "\n";
    std::cout << "========================================\n";
    std::cout << "All plot tests passed.\n";
    std::cout << "========================================\n";

    return EXIT_SUCCESS;
}