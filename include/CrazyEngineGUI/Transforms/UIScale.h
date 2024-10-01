#ifndef CRAZYENGINEGUI_TRANSFORMS_UISCALE_H
#define CRAZYENGINEGUI_TRANSFORMS_UISCALE_H

#include "CrazyEngine/Math/Rectangle.h"
#include "CrazyEngineGUI/Transforms/MeasurementPoint.h"

namespace CEGUI
{
    class UIScale
    {
    public:
        virtual ~UIScale() noexcept { }

        virtual std::uint32_t ScaleWidth(const CrazyEngine::Rectanglef& componentBounds, const CrazyEngine::Rectanglef& parentBounds) const noexcept = 0;
        virtual std::uint32_t ScaleHeight(const CrazyEngine::Rectanglef& componentBounds, const CrazyEngine::Rectanglef& parentBounds) const noexcept = 0;

        virtual void Print() const noexcept = 0;
    };
}

#endif