#ifndef VORORAMER_H
#define VORORAMER_H

#include <vector>
#include <cstdint>
#include <cstddef>
#include <string>

namespace Vororamer
{

class Color
{
public:
    Color(uint8_t r = 0, uint8_t g = 0, uint8_t b = 0) : r(r), g(g), b(b) {}
    uint8_t r;
    uint8_t g;
    uint8_t b;
}; // class Color

const Color Red(255, 0, 0);
const Color Green(0, 255, 0);
const Color Blue(0, 0, 255);

class Processor
{
public:
    Processor(size_t width = 800, size_t height = 600);
    void Run();
    void FillImage(Color color = Color(255, 0, 0));
    bool SaveImage(const std::string& filePath = "./image.ppm");

private:
    size_t mWidth;
    size_t mHeight;
    std::vector<Color> mImage;
}; // class Processor

} // namespace Vororamer

#endif // VORORAMER_H
