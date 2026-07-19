#include <doodle/flowchart.hpp>

namespace doodle
{
    Flowchart::Flowchart(unsigned int width, unsigned int height)
        : diagram_(width, height)
    {
    }

    void Flowchart::connect_previous(double x,
                                     double y,
                                     double width,
                                     double height)
    {
        if (has_previous_)
        {
            diagram_.connect(
                previous_x_ + previous_width_ / 2.0,
                previous_y_ + previous_height_,
                x + width / 2.0,
                y
            );
        }

        previous_x_ = x;
        previous_y_ = y;
        previous_width_ = width;
        previous_height_ = height;

        has_previous_ = true;
    }

    void Flowchart::start(double x,
                          double y,
                          double width,
                          double height,
                          const std::string& text)
    {
        diagram_.rounded_block(
            x,
            y,
            width,
            height,
            text
        );

        connect_previous(
            x,
            y,
            width,
            height
        );
    }

    void Flowchart::process(double x,
                            double y,
                            double width,
                            double height,
                            const std::string& text)
    {
        diagram_.block(
            x,
            y,
            width,
            height,
            text
        );

        connect_previous(
            x,
            y,
            width,
            height
        );
    }

    void Flowchart::decision(double x,
                             double y,
                             double width,
                             double height,
                             const std::string& text)
    {
        diagram_.diamond(
            x + width / 2.0,
            y + height / 2.0,
            width,
            height,
            text
        );

        connect_previous(
            x,
            y,
            width,
            height
        );
    }

    void Flowchart::end(double x,
                        double y,
                        double width,
                        double height,
                        const std::string& text)
    {
        diagram_.rounded_block(
            x,
            y,
            width,
            height,
            text
        );

        connect_previous(
            x,
            y,
            width,
            height
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