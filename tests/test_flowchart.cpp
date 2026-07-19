#include <doodle.hpp>

#include <cstdlib>
#include <iostream>

int main()
{
    std::cout << "========================================\n";
    std::cout << "libdoodle Flowchart Test\n";
    std::cout << "========================================\n\n";

    doodle::Flowchart chart(700, 700);

    chart.start(
        250, 40,
        160, 60,
        "Start"
    );

    chart.process(
        250, 140,
        160, 60,
        "Read Input"
    );

    chart.decision(
        250, 260,
        140, 100,
        "x > 0 ?"
    );

    chart.process(
        250, 420,
        160, 60,
        "Print Result"
    );

    chart.end(
        250, 560,
        160, 60,
        "End"
    );

    if (!chart.export_svg("flowchart.svg"))
    {
        std::cerr << "ERROR: Failed to generate flowchart.svg\n";
        return EXIT_FAILURE;
    }

    std::cout << "Generated flowchart.svg successfully.\n";

    return EXIT_SUCCESS;
}