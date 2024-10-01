#include "CrazyEngineGUI/Fills/TextureFill.h"

#include "CrazyEngine/Math/Vector4.h"

namespace CEGUI
{
    TextureFill::TextureFill(CrazyEngine::Texture* texture)
        : m_Texture(texture)
    {
    }

    TextureFill::~TextureFill()
    {
        delete m_Texture;
    }

    void TextureFill::Draw(CrazyEngine::Renderer2D& renderer, CrazyEngine::Rectanglef bounds, const CrazyEngine::Vector4& colourEffect, float depth, int flags) const noexcept 
    {
        renderer.Draw(bounds, m_Texture, colourEffect, depth, flags);
    }
}