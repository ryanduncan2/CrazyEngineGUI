#ifndef CRAZYENGINEGUI_TRANSFORMS_SCALES_PIXELSCALE_H
#define CRAZYENGINEGUI_TRANSFORMS_SCALES_PIXELSCALE_H

#include "CrazyEngineGUI/Transforms/UIScale.h"
#include "CrazyEngine/Math/Rectangle.h"

namespace CEGUI
{
    class PixelScale : public UIScale
    {
    private:

        std::uint32_t m_ScaleFactor;

    public:

        PixelScale() noexcept;
        PixelScale(std::uint32_t scaleFactor) noexcept;
        ~PixelScale() noexcept override;

        std::uint32_t ScaleWidth(const CrazyEngine::Rectanglef& compBounds, const CrazyEngine::Rectanglef& parentBounds) const noexcept override;
        std::uint32_t ScaleHeight(const CrazyEngine::Rectanglef& compBounds, const CrazyEngine::Rectanglef& parentBounds) const noexcept override;

        void Print() const noexcept override;
    };
}

#endif