#include "CrazyEngineGUI/UIComponent.h"

#include "CrazyEngineGUI/Transforms/Translations/PixelTranslation.h"
#include "CrazyEngineGUI/Transforms/Scales/PixelScale.h"

#include "CrazyEngine/Application.h"

namespace CEGUI
{
    UIComponent::UIComponent(UIComponent* parent)
        : m_Parent(parent),
          m_Enabled(true)
    {
        Initialise(0, 0, 0, 0);
    }

    UIComponent::UIComponent(const std::uint32_t width, const std::uint32_t height, UIComponent* parent)
        : m_Parent(parent),
          m_Enabled(true)
    {
        Initialise(0, 0, width, height);
    }

    UIComponent::UIComponent(const std::int32_t x, const std::int32_t y, const std::uint32_t width, const std::uint32_t height, UIComponent* parent)
        : m_Parent(parent),
          m_Enabled(true)
    {
        Initialise(x, y, width, height);
    }

    UIComponent::~UIComponent()
    {
        for (std::uint32_t i = 0; i < m_Children.size(); ++i)
        {
            delete m_Children[i];
        }
    }

    void UIComponent::Initialise(const std::int32_t x, const std::int32_t y, const std::uint32_t width, const std::uint32_t height)
    {
        m_TransformManager.SetX(new PixelTranslation(x));
        m_TransformManager.SetY(new PixelTranslation(y));
        m_TransformManager.SetWidth(new PixelScale(width));
        m_TransformManager.SetHeight(new PixelScale(height));

        m_ColourEffect = CrazyEngine::Vector4(1.0f, 1.0f, 1.0f, 1.0f);

        if (m_Parent != nullptr)
        {
            m_Parent->AddChild(this);
        }

        Refresh();
    }

    void UIComponent::Refresh()
    {
        if (m_Parent == nullptr)
        {
            m_Bounds.Width = CrazyEngine::Application::s_Viewport.X;
            m_Bounds.Height = CrazyEngine::Application::s_Viewport.Y;
            m_Bounds.X = 0;
            m_Bounds.Y = 0;
        }
        else
        {
            m_Bounds.Width = m_TransformManager.GetWidth(m_Bounds, m_Parent->GetBounds());
            m_Bounds.Height = m_TransformManager.GetHeight(m_Bounds, m_Parent->GetBounds());
            m_Bounds.Width = m_TransformManager.GetWidth(m_Bounds, m_Parent->GetBounds());
            m_Bounds.X = m_TransformManager.GetX(m_Bounds, m_Parent->GetBounds());
            m_Bounds.Y = m_TransformManager.GetY(m_Bounds, m_Parent->GetBounds());
        }

        for (std::uint32_t i = 0; i < m_Children.size(); ++i)
        {
            m_Children[i]->Refresh();
        }
    }

    void UIComponent::AddChild(UIComponent* child)
    {
        m_Children.push_back(child);
    }

    void UIComponent::RemoveChild(UIComponent* child)
    {
        for (std::size_t i = 0; i < m_Children.size(); ++i)
        {
            if (m_Children[i] == child)
            {
                m_Children.erase(m_Children.begin() + i);
                
                return;
            }
        }
    }

    void UIComponent::SetParent(UIComponent* parent)
    {
        m_Parent = parent;
    }

    void UIComponent::Update(CrazyEngine::Input& input, CrazyEngine::Clock& clock)
    {
        for (std::uint32_t i = 0; i < m_Children.size(); ++i)
        {
            if (m_Children[i]->IsEnabled())
            {
                m_Children[i]->Update(input, clock);
            }
        }
    }

    void UIComponent::Draw(CrazyEngine::Renderer2D& renderer, const CrazyEngine::Vector4& colourEffect, float depth, int flags)
    {
        for (std::uint32_t i = 0; i < m_Children.size(); ++i)
        {
            if (m_Children[i]->IsEnabled())
            {
                m_Children[i]->Draw(renderer, colourEffect * m_ColourEffect, depth + 0.1f + (0.1f * i), flags);
            }
        }
    }

    void UIComponent::SetColourEffect(const CrazyEngine::Vector4& colour)
    {
        m_ColourEffect = colour;
    }

    CrazyEngine::Vector4 UIComponent::GetColourEffect() const noexcept
    {
        return m_ColourEffect;
    }

    bool UIComponent::IsEnabled() const noexcept
    {
        return m_Enabled;
    }
}