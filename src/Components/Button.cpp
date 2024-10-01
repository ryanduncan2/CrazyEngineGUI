#include "CrazyEngineGUI/Components/Button.h"

namespace CEGUI
{
    Button::Button(std::int32_t x, std::int32_t y, std::uint32_t width, std::uint32_t height, CrazyEngine::Texture* texture, UIComponent* parent)
        : UIComponent(x, y, width, height, parent),
          m_Atlas(texture, 3),
          m_State(ComponentState::NEUTRAL)
    {
        m_Atlas.SetSource(0, CrazyEngine::Rectanglef(0.0f, 0.0f, texture->GetWidth() / 3.0f, texture->GetHeight()));
        m_Atlas.SetSource(1, CrazyEngine::Rectanglef(texture->GetWidth() / 3.0f, 0.0f, texture->GetWidth() / 3.0f, texture->GetHeight()));
        m_Atlas.SetSource(2, CrazyEngine::Rectanglef(2.0f * texture->GetWidth() / 3.0f, 0.0f, texture->GetWidth() / 3.0f, texture->GetHeight()));
    }

    Button::~Button()
    {
    }

    ComponentState Button::GetState()
    {
        return m_State;
    }

    bool Button::IsClicked()
    {
        return m_State == ComponentState::CLICKED;
    }

    void Button::Update(CrazyEngine::Input& input, CrazyEngine::Clock& clock)
    {
        if (!GetBounds().Contains(input.GetMousePosition()))
        {
            m_State = ComponentState::NEUTRAL;
            m_Atlas.SetFrame(0);
        }
        else if (input.IsMouseButtonReleased(CrazyEngine::MouseButton::MOUSE_LEFT))
        {
            m_State = ComponentState::CLICKED;
        }
        else if (input.IsMouseButtonDown(CrazyEngine::MouseButton::MOUSE_LEFT))
        {
            m_State = ComponentState::PRESSED;
            m_Atlas.SetFrame(2);
        }
        else
        {
            m_State = ComponentState::HOVERED;
            m_Atlas.SetFrame(1);
        }
    }

    void Button::Draw(CrazyEngine::Renderer2D& renderer, const CrazyEngine::Vector4& colourEffect, float depth, int flags)
    {
        UIComponent::Draw(renderer, colourEffect, depth, flags);
        m_Atlas.Draw(renderer, GetBounds(), GetColourEffect() * colourEffect, depth, flags);
    }
}