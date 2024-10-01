#include "CrazyEngineGUI/Transforms/Scales/RelativeScale.h"

namespace CEGUI
{
    RelativeScale::RelativeScale() noexcept
        : m_ScaleFactor(0),
          m_ScaleDirection(Direction::HORIZONTAL)
    {
    }

    RelativeScale::RelativeScale(float scaleFactor, Direction scaleDirection) noexcept
        : m_ScaleFactor(scaleFactor),
          m_ScaleDirection(scaleDirection)
    {
    }

    RelativeScale::~RelativeScale() noexcept
    {
    }

    std::uint32_t RelativeScale::ScaleWidth(const CrazyEngine::Rectanglef& compBounds, const CrazyEngine::Rectanglef& parentBounds) const noexcept
    {
        return Scale(compBounds, parentBounds);
    }

    std::uint32_t RelativeScale::ScaleHeight(const CrazyEngine::Rectanglef& compBounds, const CrazyEngine::Rectanglef& parentBounds) const noexcept
    {
        return Scale(compBounds, parentBounds);
    }

    std::uint32_t RelativeScale::Scale(const CrazyEngine::Rectanglef& compBounds, const CrazyEngine::Rectanglef& parentBounds) const noexcept
    {
        return m_ScaleDirection == Direction::HORIZONTAL ? parentBounds.Width * m_ScaleFactor : parentBounds.Height * m_ScaleFactor;
    }

    void RelativeScale::Print() const noexcept
    {
        std::cout << "RelativeScale:[Factor: " << m_ScaleFactor << ", Direction: " << m_ScaleDirection << "]" << std::endl;
    }
}