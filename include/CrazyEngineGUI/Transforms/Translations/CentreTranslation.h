#ifndef CRAZYENGINEGUI_TRANSFORMS_TRANSLATIONS_CENTRETRANSLATION_H
#define CRAZYENGINEGUI_TRANSFORMS_TRANSLATIONS_CENTRETRANSLATION_H

#include "CrazyEngineGUI/Transforms/UITranslation.h"

namespace CEGUI
{
    class CentreTranslation : public UITranslation
    {
    public:

        CentreTranslation() noexcept;
        CentreTranslation(MeasurementPoint measurementPoint) noexcept;
        ~CentreTranslation() noexcept override { }

        std::int32_t TranslateX(const CrazyEngine::Rectanglef& componentBounds, const CrazyEngine::Rectanglef& parentBounds) const noexcept override;
        std::int32_t TranslateY(const CrazyEngine::Rectanglef& componentBounds, const CrazyEngine::Rectanglef& parentBounds) const noexcept override;

        void Print() const noexcept override;
    };
}

#endif