#ifndef CRAZYENGINEGUI_TRANSFORMS_TRANSLATIONS_RELATIVETRANSLATION_H
#define CRAZYENGINEGUI_TRANSFORMS_TRANSLATIONS_RELATIVETRANSLATION_H

#include "CrazyEngineGUI/Transforms/UITranslation.h"

#include "CrazyEngineGUI/Direction.h"

namespace CEGUI
{
    class RelativeTranslation : public UITranslation
    {
    private:

        float m_TranslationFactor;
        Direction m_MeasurementDirection;

    public:

        RelativeTranslation(float translationFactor, Direction measurementDirection) noexcept;
        RelativeTranslation(float translationFactor, Direction measurementDirection, MeasurementPoint measurementPoint) noexcept;
        ~RelativeTranslation() noexcept override { }

        std::int32_t TranslateX(const CrazyEngine::Rectanglef& compBounds, const CrazyEngine::Rectanglef& parentBounds) const noexcept override;
        std::int32_t TranslateY(const CrazyEngine::Rectanglef& compBounds, const CrazyEngine::Rectanglef& parentBounds) const noexcept override;

        void Print() const noexcept override;
    };
}

#endif