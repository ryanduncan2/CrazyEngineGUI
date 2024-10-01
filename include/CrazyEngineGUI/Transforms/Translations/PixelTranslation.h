#ifndef CRAZYENGINEGUI_TRANSFORMS_TRANSLATIONS_PIXELTRANSLATION_H
#define CRAZYENGINEGUI_TRANSFORMS_TRANSLATIONS_PIXELTRANSLATION_H

#include "CrazyEngineGUI/Transforms/UITranslation.h"
#include "CrazyEngine/Math/Rectangle.h"

namespace CEGUI
{
    class PixelTranslation : public UITranslation
    {
    protected:

        std::int32_t m_TranslationFactor;

    public:

        PixelTranslation() noexcept;
        PixelTranslation(std::int32_t translationFactor) noexcept;
        PixelTranslation(std::int32_t translationFactor, MeasurementPoint measurementPoint) noexcept;

        ~PixelTranslation() noexcept override { }

        std::int32_t TranslateX(const CrazyEngine::Rectanglef& compBounds, const CrazyEngine::Rectanglef& parentBounds) const noexcept override;
        std::int32_t TranslateY(const CrazyEngine::Rectanglef& compBounds, const CrazyEngine::Rectanglef& parentBounds) const noexcept override;

        void Print() const noexcept override;
    };
}

#endif