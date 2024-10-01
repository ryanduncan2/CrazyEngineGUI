#include "CrazyEngineGUI/Transforms/Scales/PixelScale.h"
#include <iostream>

namespace CEGUI
{
    PixelScale::PixelScale() noexcept
        : m_ScaleFactor(0)
    {
    }

    PixelScale::PixelScale(std::uint32_t scaleFactor) noexcept
        : m_ScaleFactor(scaleFactor)
    {
    }

    PixelScale::~PixelScale()
    {
    }

    std::uint32_t PixelScale::ScaleWidth(const CrazyEngine::Rectanglef& compBounds, const CrazyEngine::Rectanglef& parentBounds) const noexcept
    {
        return m_ScaleFactor;
    }

    std::uint32_t PixelScale::ScaleHeight(const CrazyEngine::Rectanglef& compBounds, const CrazyEngine::Rectanglef& parentBounds) const noexcept
    {
        return m_ScaleFactor;
    }

    void PixelScale::Print() const noexcept
    {
        std::cout << "PixelScale:[Scale Factor: " << m_ScaleFactor << "]" << std::endl;
    }
}
