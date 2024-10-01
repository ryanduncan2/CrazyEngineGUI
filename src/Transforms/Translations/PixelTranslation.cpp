#include "CrazyEngineGUI/Transforms/Translations/PixelTranslation.h"

namespace CEGUI
{
    PixelTranslation::PixelTranslation() noexcept
        : UITranslation(MeasurementPoint::MIN),
          m_TranslationFactor(0)
    {
    }

    PixelTranslation::PixelTranslation(std::int32_t translationFactor) noexcept
        : UITranslation(MeasurementPoint::MIN),
          m_TranslationFactor(translationFactor)
    {
    }

    PixelTranslation::PixelTranslation(std::int32_t translationFactor, MeasurementPoint measurementPoint) noexcept
        : UITranslation(measurementPoint),
          m_TranslationFactor(translationFactor)
    {
    }

    std::int32_t PixelTranslation::TranslateX(const CrazyEngine::Rectanglef& compBounds, const CrazyEngine::Rectanglef& parentBounds) const noexcept
    {
        switch (m_MeasurementPoint)
        {
            case MeasurementPoint::MIN:
                return parentBounds.X + m_TranslationFactor;
            case MeasurementPoint::CENTRE:
                return parentBounds.X - (compBounds.Width / 2) + m_TranslationFactor;
            default:
                return parentBounds.X + compBounds.Width + m_TranslationFactor;
        }
    }

    std::int32_t PixelTranslation::TranslateY(const CrazyEngine::Rectanglef& compBounds, const CrazyEngine::Rectanglef& parentBounds) const noexcept
    {
        switch (m_MeasurementPoint)
        {
            case MeasurementPoint::MIN:
                return parentBounds.Y + m_TranslationFactor;
            case MeasurementPoint::CENTRE:
                return parentBounds.Y - (compBounds.Height / 2) + m_TranslationFactor;
            default:
                return parentBounds.Y - compBounds.Height + m_TranslationFactor;
        }
    }

    void PixelTranslation::Print() const noexcept
    {
        std::cout << "PixelTranslation:[Translation Factor: " << m_TranslationFactor << ", MeasureFrom: " << m_MeasurementPoint << "]" << std::endl;
    }
}
