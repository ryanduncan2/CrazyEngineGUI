#include "CrazyEngineGUI/Fills/TextureAtlasFill.h"

namespace CEGUI
{
    TextureAtlasFill::TextureAtlasFill(CrazyEngine::Texture* texture, std::uint32_t frameCount)
        : m_Texture(texture), m_FrameCount(frameCount), m_CurrentFrame(0)
    {
        m_Sources.resize(frameCount);
    }

    TextureAtlasFill::~TextureAtlasFill()
    {
    }

    void TextureAtlasFill::SetSource(std::uint32_t index, CrazyEngine::Rectanglef source)
    {
        if (index > m_FrameCount)
        {
            return;
        }

        if (source.X < 0 || source.Y < 0 || source.X + source.Width > m_Texture->GetWidth() || source.Y + source.Height > m_Texture->GetHeight())
        {
            return;
        }

        m_Sources[index] = source;
    }

    void TextureAtlasFill::SetFrame(std::uint32_t frame)
    {
        if (frame > m_FrameCount)
        {
            return;
        }

        m_CurrentFrame = frame;
    }

    void TextureAtlasFill::Draw(CrazyEngine::Renderer2D& renderer, CrazyEngine::Rectanglef bounds, const CrazyEngine::Vector4& colourEffect, float depth, int flags) const noexcept
    {
        renderer.Draw(bounds, m_Sources[m_CurrentFrame], m_Texture, colourEffect, depth, flags);
    }
}