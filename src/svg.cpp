#include <doodle/svg.hpp>

#include <cmath>
#include <fstream>
#include <sstream>

namespace doodle
{
    SvgCanvas::SvgCanvas(unsigned int width, unsigned int height)
        : width_(width), height_(height)
    {
    }

    std::string SvgCanvas::rgb(const Color& color)
    {
        std::ostringstream ss;
        ss << "rgb("
           << static_cast<int>(color.r) << ","
           << static_cast<int>(color.g) << ","
           << static_cast<int>(color.b) << ")";
        return ss.str();
    }

    void SvgCanvas::rectangle(double x, double y, double width, double height,
                              const Color& stroke,
                              const Color& fill,
                              double stroke_width)
    {
        body_ += "<rect x=\"" + std::to_string(x) +
                 "\" y=\"" + std::to_string(y) +
                 "\" width=\"" + std::to_string(width) +
                 "\" height=\"" + std::to_string(height) +
                 "\" fill=\"" + rgb(fill) +
                 "\" stroke=\"" + rgb(stroke) +
                 "\" stroke-width=\"" + std::to_string(stroke_width) +
                 "\"/>\n";
    }

    void SvgCanvas::rounded_rectangle(double x, double y, double width, double height,
                                      double radius,
                                      const Color& stroke,
                                      const Color& fill,
                                      double stroke_width)
    {
        body_ += "<rect x=\"" + std::to_string(x) +
                 "\" y=\"" + std::to_string(y) +
                 "\" width=\"" + std::to_string(width) +
                 "\" height=\"" + std::to_string(height) +
                 "\" rx=\"" + std::to_string(radius) +
                 "\" ry=\"" + std::to_string(radius) +
                 "\" fill=\"" + rgb(fill) +
                 "\" stroke=\"" + rgb(stroke) +
                 "\" stroke-width=\"" + std::to_string(stroke_width) +
                 "\"/>\n";
    }

    void SvgCanvas::diamond(double cx, double cy, double width, double height,
                            const Color& stroke,
                            const Color& fill,
                            double stroke_width)
    {
        std::ostringstream pts;

        pts << cx << "," << cy - height / 2 << " "
            << cx + width / 2 << "," << cy << " "
            << cx << "," << cy + height / 2 << " "
            << cx - width / 2 << "," << cy;

        body_ += "<polygon points=\"" + pts.str() +
                 "\" fill=\"" + rgb(fill) +
                 "\" stroke=\"" + rgb(stroke) +
                 "\" stroke-width=\"" + std::to_string(stroke_width) +
                 "\"/>\n";
    }

    void SvgCanvas::line(double x1, double y1, double x2, double y2,
                         const Color& stroke,
                         double stroke_width)
    {
        body_ += "<line x1=\"" + std::to_string(x1) +
                 "\" y1=\"" + std::to_string(y1) +
                 "\" x2=\"" + std::to_string(x2) +
                 "\" y2=\"" + std::to_string(y2) +
                 "\" stroke=\"" + rgb(stroke) +
                 "\" stroke-width=\"" + std::to_string(stroke_width) +
                 "\"/>\n";
    }

    void SvgCanvas::arrow(double x1, double y1, double x2, double y2,
                          const Color& stroke,
                          double stroke_width)
    {
        line(x1, y1, x2, y2, stroke, stroke_width);

        constexpr double arrow_length = 12.0;
        constexpr double arrow_angle = 0.5;

        double theta = std::atan2(y2 - y1, x2 - x1);

        double x3 = x2 - arrow_length * std::cos(theta - arrow_angle);
        double y3 = y2 - arrow_length * std::sin(theta - arrow_angle);

        double x4 = x2 - arrow_length * std::cos(theta + arrow_angle);
        double y4 = y2 - arrow_length * std::sin(theta + arrow_angle);

        line(x2, y2, x3, y3, stroke, stroke_width);
        line(x2, y2, x4, y4, stroke, stroke_width);
    }

    void SvgCanvas::text(double x, double y,
                         const std::string& value,
                         unsigned int font_size,
                         const Color& color,
                         const std::string& font)
    {
        body_ += "<text x=\"" + std::to_string(x) +
                 "\" y=\"" + std::to_string(y) +
                 "\" font-family=\"" + font +
                 "\" font-size=\"" + std::to_string(font_size) +
                 "\" text-anchor=\"middle\" dominant-baseline=\"middle\" fill=\"" +
                 rgb(color) + "\">" + value + "</text>\n";
    }

    bool SvgCanvas::save(const std::string& filename) const
    {
        std::ofstream out(filename);

        if (!out)
            return false;

        out << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";

        out << "<svg xmlns=\"http://www.w3.org/2000/svg\" "
            << "width=\"" << width_
            << "\" height=\"" << height_
            << "\" viewBox=\"0 0 "
            << width_ << " "
            << height_ << "\">\n";

        out << body_;

        out << "</svg>\n";

        return true;
    }
}