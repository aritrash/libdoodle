#include <doodle/flowchart.hpp>

namespace doodle
{
    Flowchart::Flowchart(unsigned int width, unsigned int height)
        : diagram_(width, height)
    {
    }

    void Flowchart::start(double x, double y,
                          double width, double height,
                          const std::string& text)
    {
        diagram_.rounded_block(
            x,
            y,
            width,
            height,
            text
        );
    }

    void Flowchart::process(double x, double y,
                            double width, double height,
                            const std::string& text)
    {
        diagram_.block(
            x,
            y,
            width,
            height,
            text
        );
    }

    void Flowchart::decision(double x, double y,
                             double width, double height,
                             const std::string& text)
    {
        diagram_.diamond(
            x + width / 2.0,
            y + height / 2.0,
            width,
            height,
            text
        );
    }

    void Flowchart::end(double x, double y,
                        double width, double height,
                        const std::string& text)
    {
        diagram_.rounded_block(
            x,
            y,
            width,
            height,
            text
        );
    }

    void Flowchart::connect(double x1,
                            double y1,
                            double x2,
                            double y2)
    {
        diagram_.connect(
            x1,
            y1,
            x2,
            y2
        );
    }

    void Flowchart::label(double x,
                          double y,
                          const std::string& text)
    {
        diagram_.label(
            x,
            y,
            text
        );
    }

    bool Flowchart::export_svg(const std::string& filename) const
    {
        return diagram_.export_svg(
            filename
        );
    }
}