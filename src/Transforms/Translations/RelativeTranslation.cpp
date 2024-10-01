#include "CrazyEngineGUI/Transforms/Translations/RelativeTranslation.h"

namespace CEGUI
{
    RelativeTranslation::RelativeTranslation(float translationFactor, Direction measurementDirection) noexcept
        : UITranslation(MeasurementPoint::MIN),
          m_TranslationFactor(translationFactor),
          m_MeasurementDirection(measurementDirection)
    {   
    }

    RelativeTranslation::RelativeTranslation(float translationFactor, Direction measurementDirection, MeasurementPoint measurementPoint) noexcept
        : UITranslation(measurementPoint),
          m_TranslationFactor(translationFactor),
          m_MeasurementDirection(measurementDirection)
    {   
    }

    std::int32_t RelativeTranslation::TranslateX(const CrazyEngine::Rectanglef& compBounds, const CrazyEngine::Rectanglef& parentBounds) const noexcept
    {
        switch (m_MeasurementPoint)
        {
            case MeasurementPoint::MIN:
                return parentBounds.X + (m_MeasurementDirection == HORIZONTAL ? parentBounds.Width : parentBounds.Height) * m_TranslationFactor;
            case MeasurementPoint::CENTRE:
                return parentBounds.X + (m_MeasurementDirection == HORIZONTAL ? parentBounds.Width : parentBounds.Height) * m_TranslationFactor - (compBounds.Width / 2);
            default:
                return parentBounds.X + (m_MeasurementDirection == HORIZONTAL ? parentBounds.Width : parentBounds.Height) * m_TranslationFactor - compBounds.Width;
        }
    }

    std::int32_t RelativeTranslation::TranslateY(const CrazyEngine::Rectanglef& compBounds, const CrazyEngine::Rectanglef& parentBounds) const noexcept
    {
        switch (m_MeasurementPoint)
        {
            case MeasurementPoint::MIN:
                return parentBounds.Y + (m_MeasurementDirection == VERTICAL ? parentBounds.Height : parentBounds.Width) * m_TranslationFactor;
            case MeasurementPoint::CENTRE:
                return parentBounds.Y + (m_MeasurementDirection == VERTICAL ? parentBounds.Height : parentBounds.Width) * m_TranslationFactor - (compBounds.Height / 2);
            default:
                return parentBounds.Y + (m_MeasurementDirection == VERTICAL ? parentBounds.Height : parentBounds.Width) * m_TranslationFactor - compBounds.Height;
        }
    }

    void RelativeTranslation::Print() const noexcept
    {
        std::cout << "RelativeTranslation:[Translation Factor:" << m_TranslationFactor << ", Measurement Point: " << m_MeasurementPoint << ", Measurement Direction: " << m_MeasurementDirection << "]" << std::endl;
    }
}