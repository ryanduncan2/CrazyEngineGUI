#include "CrazyEngineGUI/Transforms/Scales/AspectRatioScale.h"
#include <iostream>

namespace CEGUI
{
    AspectRatioScale::AspectRatioScale(float aspectRatio) noexcept
        : m_AspectRatio(aspectRatio)
    {
    }

    AspectRatioScale::~AspectRatioScale() noexcept
    {
    }

    std::uint32_t AspectRatioScale::ScaleWidth(const CrazyEngine::Rectanglef& compBounds, const CrazyEngine::Rectanglef& parentBounds) const noexcept
    {
        return compBounds.Height * m_AspectRatio;
    }

    std::uint32_t AspectRatioScale::ScaleHeight(const CrazyEngine::Rectanglef& compBounds, const CrazyEngine::Rectanglef& parentBounds) const noexcept
    {
        return compBounds.Width * m_AspectRatio;
    }

    void AspectRatioScale::Print() const noexcept
    {
        std::cout << "AspectRatioScale:[Aspect Ratio: " << m_AspectRatio << "]" << std::endl;
    }
}
