#ifndef CRAZYENGINEGUI_TRANSFORMS_SCALES_RELATIVESCALE_H
#define CRAZYENGINEGUI_TRANSFORMS_SCALES_RELATIVESCALE_H

#include "CrazyEngineGUI/Transforms/UIScale.h"

#include "CrazyEngineGUI/Direction.h"
#include "CrazyEngine/Math/Rectangle.h"

namespace CEGUI
{
    class RelativeScale : public UIScale
    {
    private:

        float m_ScaleFactor;
        Direction m_ScaleDirection;

    public:

        RelativeScale() noexcept;
        RelativeScale(const float translationFactor, Direction scaleDirection) noexcept;
        ~RelativeScale() noexcept override;

        std::uint32_t ScaleWidth(const CrazyEngine::Rectanglef& compBounds, const CrazyEngine::Rectanglef& parentBounds) const noexcept override;
        std::uint32_t ScaleHeight(const CrazyEngine::Rectanglef& compBounds, const CrazyEngine::Rectanglef& parentBounds) const noexcept override;

        std::uint32_t Scale(const CrazyEngine::Rectanglef& compBounds, const CrazyEngine::Rectanglef& parentBounds) const noexcept;
        
        void Print() const noexcept override;
    };
}

#endif