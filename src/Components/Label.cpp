#include "CrazyEngineGUI/Components/Label.h"

namespace CEGUI
{
    Label::Label(std::int32_t x, std::int32_t y, const std::string& text, float scale, CrazyEngine::TextureFont* font, const CrazyEngine::Vector4& colour, UIComponent* parent) noexcept
        : UIComponent(x, y, 0, 0, parent),
          m_Text(text),
          m_Colour(colour),
          m_Font(font),
          m_Scale(scale)
    {
    }

    Label::~Label() noexcept
    {
    }

    std::string Label::GetText() const noexcept
    {
        return m_Text;
    }

    CrazyEngine::Vector4 Label::GetColour() const noexcept
    {
        return m_Colour;
    }

    void Label::SetText(std::string text) noexcept
    {
        m_Text = text;
    }

    void Label::SetColour(const CrazyEngine::Vector4& colour) noexcept
    {
        m_Colour = colour;
    }

    void Label::Update(CrazyEngine::Input& input, CrazyEngine::Clock& clock)
    {
    }

    void Label::Draw(CrazyEngine::Renderer2D& renderer, const CrazyEngine::Vector4& colourEffect, float depth, int flags)
    {
        UIComponent::Draw(renderer, colourEffect, depth, flags);
        renderer.DrawString(m_Text, GetBounds().GetPosition(), m_Colour * GetColourEffect() * colourEffect, m_Font, m_Scale, depth, flags);
    }
}