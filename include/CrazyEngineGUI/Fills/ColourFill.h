#ifndef CRAZYENGINEGUI_FILLS_COLOURFILL_H_
#define CRAZYENGINEGUI_FILLS_COLOURFILL_H_

#include "CrazyEngineGUI/Fill.h"

namespace CEGUI
{
    class ColourFill : public Fill
    {
    private:

        CrazyEngine::Vector4 m_Colour;

    public:

        ColourFill(const CrazyEngine::Vector4& colour);

        void Draw(CrazyEngine::Renderer2D& renderer, CrazyEngine::Rectanglef bounds, const CrazyEngine::Vector4& colourEffect, float depth = 0.0f, int flags = 0) const noexcept override;
    };
}

#endif