#ifndef CRAZYENGINEGUI_TRANSFORMS_SCALES_ASPECTRATIOSCALE_H
#define CRAZYENGINEGUI_TRANSFORMS_SCALES_ASPECTRATIOSCALE_H

#include "CrazyEngineGUI/Transforms/UIScale.h"
#include "CrazyEngine/Math/Rectangle.h"

namespace CEGUI
{
    class AspectRatioScale : public UIScale
    {
    private:

        float m_AspectRatio;

    public:

        AspectRatioScale(float aspectRatio) noexcept;
        ~AspectRatioScale() noexcept override;

        std::uint32_t ScaleWidth(const CrazyEngine::Rectanglef& compBounds, const CrazyEngine::Rectanglef& parentBounds) const noexcept override;
        std::uint32_t ScaleHeight(const CrazyEngine::Rectanglef& compBounds, const CrazyEngine::Rectanglef& parentBounds) const noexcept override;

        void Print() const noexcept override;
    };
}

#endif