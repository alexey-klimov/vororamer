#include <iostream>
#include <fstream>

#include "Vororamer.h"

Vororamer::Processor::Processor(size_t width, size_t height) : 
    mWidth(width),
    mHeight(height),
    mImage(width * height)
{
}

void Vororamer::Processor::Run()
{
    std::cout << "Running Vororamer with width = " << mWidth << " and height = " << mHeight << std::endl;

    FillImage(Vororamer::Red);
    SaveImage();

    std::cout << "Vororamer finished" << std::endl;
}

void Vororamer::Processor::FillImage(Color color)
{
    for (size_t pixelIdx = 0; pixelIdx < mImage.size(); ++pixelIdx)
    {
        mImage[pixelIdx] = color;
    }
}

bool Vororamer::Processor::SaveImage(const std::string &filePath)
{
    std::ofstream imageFile(filePath, std::ios::binary);
    if (!imageFile.is_open())
    {
        std::cerr << "Failed to open file " << filePath << std::endl;
        return false;
    }

    imageFile << "P6" << std::endl;
    imageFile << mWidth << " " << mHeight << std::endl;
    imageFile << "255" << std::endl;

    for (size_t pixelIdx = 0; pixelIdx < mImage.size(); ++pixelIdx)
    {
        imageFile << mImage[pixelIdx].r
                  << mImage[pixelIdx].g
                  << mImage[pixelIdx].b;
    }

    return true;
}
