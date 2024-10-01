#ifndef CRAZYENGINEGUI_TRANSFORMS_UITRANSLATION_H
#define CRAZYENGINEGUI_TRANSFORMS_UITRANSLATION_H

#include "CrazyEngine/Math/Rectangle.h"
#include "CrazyEngineGUI/Transforms/MeasurementPoint.h"
#include <iostream>

namespace CEGUI
{
    class UITranslation
    {
    protected:

        MeasurementPoint m_MeasurementPoint;

    public:

        UITranslation(MeasurementPoint measurementPoint) noexcept;
        virtual ~UITranslation() noexcept { }

        virtual std::int32_t TranslateX(const CrazyEngine::Rectanglef& componentBounds, const CrazyEngine::Rectanglef& parentBounds) const noexcept = 0;
        virtual std::int32_t TranslateY(const CrazyEngine::Rectanglef& componentBounds, const CrazyEngine::Rectanglef& parentBounds) const noexcept = 0;

        virtual void Print() const noexcept = 0;
    };
}

#endif