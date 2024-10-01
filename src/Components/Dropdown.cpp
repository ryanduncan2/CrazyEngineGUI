#include "CrazyEngineGUI/Components/Dropdown.h"

#include "CrazyEngineGUI/Transforms/Scales/RelativeScale.h"
#include "CrazyEngineGUI/Transforms/Translations/PixelTranslation.h"

namespace CEGUI
{
    Dropdown::Dropdown(std::int32_t x, std::int32_t y, std::uint32_t width, std::uint32_t height, CrazyEngine::Texture* texture, UIComponent* parent)
        : UIComponent(x, y, width, height, parent),
          m_Atlas(texture, 3),
          m_State(ComponentState::NEUTRAL),
          m_Expanded(false),
          m_ExpansionHeight(0),
          m_Contracting(false)
    {
        m_Atlas.SetSource(0, CrazyEngine::Rectanglef(0.0f, 0.0f, texture->GetWidth() / 3.0f, texture->GetHeight()));
        m_Atlas.SetSource(1, CrazyEngine::Rectanglef(texture->GetWidth() / 3.0f, 0.0f, texture->GetWidth() / 3.0f, texture->GetHeight()));
        m_Atlas.SetSource(2, CrazyEngine::Rectanglef(2.0f * texture->GetWidth() / 3.0f, 0.0f, texture->GetWidth() / 3.0f, texture->GetHeight()));
    }

    Dropdown::~Dropdown()
    {
    }

    ComponentState Dropdown::GetState()
    {
        return m_State;
    }

    bool Dropdown::IsClicked()
    {
        return m_State == ComponentState::CLICKED;
    }

    void Dropdown::Update(CrazyEngine::Input& input, CrazyEngine::Clock& clock)
    {
        // Updating Elements

        if (m_Expanded)
        {
            for (std::size_t i = 0; i < m_Elements.size(); ++i)
            {
                m_Elements[i]->Update(input, clock);
            }

            // Checking for Clicks

            if (input.IsMouseButtonReleased(CrazyEngine::MouseButton::MOUSE_LEFT))
            {
                m_Contracting = true;

                return;
            }
        }

        // Updating Dropdown State

        if (!GetBounds().Contains(input.GetMousePosition()))
        {
            m_State = ComponentState::NEUTRAL;
            m_Atlas.SetFrame(0);
        }
        else if (input.IsMouseButtonReleased(CrazyEngine::MouseButton::MOUSE_LEFT))
        {
            m_State = ComponentState::CLICKED;
            m_Expanded = !m_Expanded;
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

        UIComponent::Update(input, clock);

        // Checking for Closure

        if (m_Contracting)
        {
            m_Expanded = false;
            m_Contracting = false;
        }
    }

    void Dropdown::Draw(CrazyEngine::Renderer2D& renderer, const CrazyEngine::Vector4& colourEffect, float depth, int flags)
    {
        m_Atlas.Draw(renderer, GetBounds(), GetColourEffect() * colourEffect, depth, flags);
        UIComponent::Draw(renderer, colourEffect, depth, flags);

        if (m_Expanded)
        {
            for (std::size_t i = 0; i < m_Elements.size(); ++i)
            {
                m_Elements[i]->Draw(renderer, colourEffect * GetColourEffect(), depth + 0.1f + (0.1f * i), flags);
            }
        }
    }

    void Dropdown::AddElement(UIComponent* component)
    {
        m_Elements.push_back(component);
        RemoveChild(component);

        component->SetParent(this);
        component->GetTransformManager().SetWidth(new RelativeScale(1.0f, Direction::HORIZONTAL));
        component->GetTransformManager().SetX(new PixelTranslation(0));
        component->GetTransformManager().SetY(new PixelTranslation(m_ExpansionHeight + GetBounds().Height));

        component->Refresh();

        m_ExpansionHeight += component->GetBounds().Height;
    }
}