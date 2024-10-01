#include "CrazyEngineGUI/Components/Checkbox.h"

namespace CEGUI
{
    Checkbox::Checkbox(std::int32_t x, std::int32_t y, std::uint32_t width, std::uint32_t height, CrazyEngine::Texture* texture, UIComponent* parent) noexcept
        : UIComponent(x, y, width, height, parent),
          m_Atlas(texture, 6),
          m_State(CheckboxState::NEUTRAL),
          m_Checked(false)
    {
        m_Atlas.SetSource(0, CrazyEngine::Rectanglef(0.0f, 0.0f, texture->GetWidth() / 6.0f, texture->GetHeight()));
        m_Atlas.SetSource(1, CrazyEngine::Rectanglef(texture->GetWidth() / 6.0f, 0.0f, texture->GetWidth() / 6.0f, texture->GetHeight()));
        m_Atlas.SetSource(2, CrazyEngine::Rectanglef(2.0f * texture->GetWidth() / 6.0f, 0.0f, texture->GetWidth() / 6.0f, texture->GetHeight()));
        m_Atlas.SetSource(3, CrazyEngine::Rectanglef(3.0f * texture->GetWidth() / 6.0f, 0.0f, texture->GetWidth() / 6.0f, texture->GetHeight()));
        m_Atlas.SetSource(4, CrazyEngine::Rectanglef(4.0f * texture->GetWidth() / 6.0f, 0.0f, texture->GetWidth() / 6.0f, texture->GetHeight()));
        m_Atlas.SetSource(5, CrazyEngine::Rectanglef(5.0f * texture->GetWidth() / 6.0f, 0.0f, texture->GetWidth() / 6.0f, texture->GetHeight()));
    }

    Checkbox::~Checkbox() noexcept
    {
    }

    Checkbox::CheckboxState Checkbox::GetState() const noexcept
    {
        return m_State;
    }

    bool Checkbox::IsClicked() const noexcept
    {
        return m_State == CheckboxState::CLICKED;
    }

    bool Checkbox::IsChecked() const noexcept
    {
        return m_Checked;
    }

    void Checkbox::SetChecked(bool checked) noexcept
    {
        m_Checked = checked;
        m_Atlas.SetFrame(m_Checked ? 3 : 0);
    }

    void Checkbox::Update(CrazyEngine::Input& input, CrazyEngine::Clock& clock)
    {
        if (!GetBounds().Contains(input.GetMousePosition()))
        {
            m_State = CheckboxState::NEUTRAL;
            m_Atlas.SetFrame(!m_Checked ? 0 : 3);
        }
        else if (input.IsMouseButtonReleased(CrazyEngine::MouseButton::MOUSE_LEFT))
        {
            m_State = CheckboxState::CLICKED;
            m_Checked = !m_Checked;
        }
        else if (input.IsMouseButtonDown(CrazyEngine::MouseButton::MOUSE_LEFT))
        {
            m_State = CheckboxState::PRESSED;
            m_Atlas.SetFrame(!m_Checked ? 2 : 5);
        }
        else
        {
            m_State = CheckboxState::HOVERED;
            m_Atlas.SetFrame(!m_Checked ? 1 : 4);
        }
    }

    void Checkbox::Draw(CrazyEngine::Renderer2D& renderer, const CrazyEngine::Vector4& colourEffect, float depth, int flags)
    {
        UIComponent::Draw(renderer, colourEffect, depth, flags);
        m_Atlas.Draw(renderer, GetBounds(), GetColourEffect() * colourEffect, depth, flags);
    }
}