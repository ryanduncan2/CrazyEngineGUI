#include "CrazyEngineGUI/Components/Image.h"

#include "CrazyEngineGUI/Fills/TextureFill.h"
#include "CrazyEngineGUI/Fills/ColourFill.h"

namespace CEGUI
{
    Image::Image(std::int32_t x, std::int32_t y, std::uint32_t width, std::uint32_t height, CrazyEngine::Texture* texture, UIComponent* parent)
        : UIComponent(x, y, width, height, parent)
    {
        m_Fill = new TextureFill(texture);
    }

    Image::Image(std::int32_t x, std::int32_t y, std::uint32_t width, std::uint32_t height, const CrazyEngine::Vector4& colour, UIComponent* parent)
        : UIComponent(x, y, width, height, parent)
    {
        m_Fill = new ColourFill(colour);
    }

    Image::~Image()
    {
        delete m_Fill;
    }

    void Image::Draw(CrazyEngine::Renderer2D& renderer, const CrazyEngine::Vector4& colourEffect, float depth, int flags)
    {
        UIComponent::Draw(renderer, colourEffect, depth, flags);
        m_Fill->Draw(renderer, GetBounds(), GetColourEffect() * colourEffect, depth, flags);
    }
}