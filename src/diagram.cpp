#include <doodle/diagram.hpp>

#include "svg.hpp"

namespace doodle
{
    Diagram::Diagram(unsigned int width, unsigned int height)
    {
        canvas_ = new SvgCanvas(width, height);
    }

    void Diagram::block(double x, double y,
                        double width, double height,
                        const std::string& label,
                        const Color& stroke,
                        const Color& fill)
    {
        canvas_->rectangle(x, y, width, height, stroke, fill);

        canvas_->text(
            x + width / 2.0,
            y + height / 2.0,
            label
        );
    }

    void Diagram::rounded_block(double x, double y,
                                double width, double height,
                                const std::string& label,
                                const Color& stroke,
                                const Color& fill)
    {
        canvas_->rounded_rectangle(
            x,
            y,
            width,
            height,
            12.0,
            stroke,
            fill
        );

        canvas_->text(
            x + width / 2.0,
            y + height / 2.0,
            label
        );
    }

    void Diagram::diamond(double cx, double cy,
                          double width, double height,
                          const std::string& label,
                          const Color& stroke,
                          const Color& fill)
    {
        canvas_->diamond(
            cx,
            cy,
            width,
            height,
            stroke,
            fill
        );

        canvas_->text(
            cx,
            cy,
            label
        );
    }

    void Diagram::connect(double x1, double y1,
                          double x2, double y2)
    {
        canvas_->arrow(
            x1,
            y1,
            x2,
            y2
        );
    }

    void Diagram::label(double x,
                        double y,
                        const std::string& text)
    {
        canvas_->text(
            x,
            y,
            text
        );
    }

    bool Diagram::export_svg(const std::string& filename) const
    {
        return canvas_->save(filename);
    }
}