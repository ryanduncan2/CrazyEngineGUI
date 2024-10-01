#ifndef CRAZYENGINEGUI_TEXTUREATLASFILL_H_
#define CRAZYENGINEGUI_TEXTUREATLASFILL_H_

#include "CrazyEngineGUI/Fill.h"

#include "CrazyEngine/Graphics/Texture.h"
#include "CrazyEngine/Graphics/Renderer2D.h"
#include "CrazyEngine/Math/Rectangle.h"

#include <vector>

namespace CEGUI
{
    class TextureAtlasFill : public Fill
    {
    private:
        CrazyEngine::Texture* m_Texture;
        std::vector<CrazyEngine::Rectanglef> m_Sources;

        std::uint32_t m_FrameCount;
        std::uint32_t m_CurrentFrame;

    public:
        TextureAtlasFill(CrazyEngine::Texture* texture, std::uint32_t frames);
        ~TextureAtlasFill();

        void SetSource(std::uint32_t index, CrazyEngine::Rectanglef source);
        void SetFrame(std::uint32_t frame);

        void Draw(CrazyEngine::Renderer2D& renderer, CrazyEngine::Rectanglef bounds, const CrazyEngine::Vector4& colourEffect, float depth = 0.0f, int flags = 0) const noexcept override;
    };
}

#endif