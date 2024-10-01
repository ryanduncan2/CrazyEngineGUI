#ifndef CRAZYENGINEGUI_FILLS_TEXTUREFILL_H_
#define CRAZYENGINEGUI_FILLS_TEXTUREFILL_H_

#include "CrazyEngineGUI/Fill.h"

namespace CEGUI
{
    class TextureFill : public Fill
    {
    private:

        CrazyEngine::Texture* m_Texture;

    public:

        TextureFill(CrazyEngine::Texture* texture);
        ~TextureFill();

        void Draw(CrazyEngine::Renderer2D& renderer, CrazyEngine::Rectanglef bounds, const CrazyEngine::Vector4& colourEffect, float depth = 0.0f, int flags = 0) const noexcept override;
    };
}

#endif