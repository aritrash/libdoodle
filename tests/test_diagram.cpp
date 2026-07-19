#include <doodle.hpp>

#include <cstdlib>
#include <iostream>

int main()
{
    std::cout << "========================================\n";
    std::cout << "libdoodle Diagram Test\n";
    std::cout << "========================================\n\n";

    doodle::Diagram diagram(800, 600);

    diagram.block(
        80, 80,
        160, 60,
        "Input"
    );

    diagram.rounded_block(
        320, 80,
        180, 60,
        "Process"
    );

    diagram.diamond(
        320, 220,
        140, 100,
        "Decision?"
    );

    diagram.block(
        580, 220,
        140, 60,
        "Output"
    );

    diagram.connect(160, 140, 410, 140);
    diagram.connect(410, 140, 390, 220);
    diagram.connect(460, 270, 580, 250);

    diagram.label(470, 210, "Yes");

    if (!diagram.export_svg("diagram.svg"))
    {
        std::cerr << "ERROR: Failed to generate diagram.svg\n";
        return EXIT_FAILURE;
    }

    std::cout << "Generated diagram.svg successfully.\n";

    return EXIT_SUCCESS;
}