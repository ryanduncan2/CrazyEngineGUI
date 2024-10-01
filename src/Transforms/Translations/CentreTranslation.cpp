#include "CrazyEngineGUI/Transforms/Translations/CentreTranslation.h"
#include <iostream>

namespace CEGUI
{
    CentreTranslation::CentreTranslation() noexcept
        : UITranslation(MeasurementPoint::CENTRE)
    {
    }

    CentreTranslation::CentreTranslation(MeasurementPoint measurementPoint) noexcept
        : UITranslation(measurementPoint)
    {
    }

    std::int32_t CentreTranslation::TranslateX(const CrazyEngine::Rectanglef& compBounds, const CrazyEngine::Rectanglef& parentBounds) const noexcept
    {
        switch (m_MeasurementPoint)
        {
            case MeasurementPoint::CENTRE:
                return parentBounds.X + (parentBounds.Width / 2.0f) - (compBounds.Width / 2.0f);
            case MeasurementPoint::MIN:
                return parentBounds.X + (parentBounds.Width / 2.0f);
            default:
                return parentBounds.X + (parentBounds.Width / 2.0f) - compBounds.Width;
        }
    }

    std::int32_t CentreTranslation::TranslateY(const CrazyEngine::Rectanglef& compBounds, const CrazyEngine::Rectanglef& parentBounds) const noexcept
    {
        switch (m_MeasurementPoint)
        {
            case MeasurementPoint::CENTRE:
                return parentBounds.Y + (parentBounds.Height / 2.0f) - (compBounds.Height / 2.0f);
            case MeasurementPoint::MIN:
                return parentBounds.Y + (parentBounds.Height / 2.0f);
            default:
                return parentBounds.Y + (parentBounds.Height / 2.0f) - compBounds.Height;
        }
    }

    void CentreTranslation::Print() const noexcept
    {
        std::cout << "CentreTranslation:[MeasureFrom: " << m_MeasurementPoint << "]" << std::endl;
    }
}
