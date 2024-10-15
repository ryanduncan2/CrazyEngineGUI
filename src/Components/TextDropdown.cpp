#include "CrazyEngineGUI/Components/TextDropdown.h"

#include "CrazyEngineGUI/Transforms/Scales/RelativeScale.h"
#include "CrazyEngineGUI/Transforms/Translations/PixelTranslation.h"
#include "CrazyEngineGUI/Components/Label.h"

namespace CEGUI
{
    TextDropdown::TextDropdown(std::int32_t x, std::int32_t y, std::uint32_t width, std::uint32_t height, CrazyEngine::Texture* dropdownTexture, CrazyEngine::Texture* elementTexture, CrazyEngine::TextureFont* font, UIComponent* parent)
        : Dropdown(x, y, width, height, dropdownTexture, parent),
          m_Font(font),
          m_ElementAtlas(elementTexture, 3),
          m_SelectedIndex(-1),
          m_TextAlignment(TextAlignment::TEXT_ALIGN_CENTRE)
    {
        m_ElementAtlas.SetSource(0, CrazyEngine::Rectanglef(0.0f, 0.0f, elementTexture->GetWidth() / 3.0f, elementTexture->GetHeight()));
        m_ElementAtlas.SetSource(1, CrazyEngine::Rectanglef(elementTexture->GetWidth() / 3.0f, 0.0f, elementTexture->GetWidth() / 3.0f, elementTexture->GetHeight()));
        m_ElementAtlas.SetSource(2, CrazyEngine::Rectanglef(2.0f * elementTexture->GetWidth() / 3.0f, 0.0f, elementTexture->GetWidth() / 3.0f, elementTexture->GetHeight()));

        m_TextScale = (GetBounds().Height * 0.5f) / m_Font->MeasureString("x", 1.0f).Y;
        m_TextYOffset = 1.0f - (0.5f / 2.0f);
    }

    TextDropdown::~TextDropdown()
    {
    }

    void TextDropdown::Update(CrazyEngine::Input& input, CrazyEngine::Clock& clock)
    {
        if (IsExpanded())
        {
            for (std::size_t i = 0; i < GetElements().size(); ++i)
            {
                GetElements()[i]->Update(input, clock);

                if (((Button*)GetElements()[i])->IsClicked())
                {
                    m_SelectedIndex = i;
                    break;
                }
            }
        }

        Dropdown::Update(input, clock);
    }

    void TextDropdown::Draw(CrazyEngine::Renderer2D& renderer, const CrazyEngine::Vector4& colourEffect, float depth, int flags)
    {
        Dropdown::Draw(renderer, colourEffect, depth, flags);

        if (m_SelectedIndex >= 0)
        {
            CrazyEngine::Vector2 pos = GetBounds().GetPosition() + CrazyEngine::Vector2(0, GetBounds().Height * m_TextYOffset);

            switch (m_TextAlignment)
            {
                case TextAlignment::TEXT_ALIGN_CENTRE: pos.X += (GetBounds().Width - m_Font->MeasureString(m_ElementLabels[m_SelectedIndex].c_str(), m_TextScale).X) / 2.0f; break;
                default: pos.X += 10; break;
            }

            renderer.DrawString(m_ElementLabels[m_SelectedIndex], pos, CrazyEngine::Vector4(1.0f, 1.0f, 1.0f, 1.0f), m_Font, m_TextScale, depth + 0.1f, flags);
        }

        if (IsExpanded())
        {
            for (std::size_t i = 0; i < m_ElementLabels.size(); ++i)
            {
                CrazyEngine::Vector2 pos = GetElements()[i]->GetBounds().GetPosition() + CrazyEngine::Vector2(0, GetElements()[i]->GetBounds().Height * m_TextYOffset);

                switch (m_TextAlignment)
                {
                    case TextAlignment::TEXT_ALIGN_CENTRE: pos.X += (GetElements()[i]->GetBounds().Width - m_Font->MeasureString(m_ElementLabels[i].c_str(), m_TextScale).X) / 2.0f; break;
                    default: pos.X += 10; break;
                }

                renderer.DrawString(m_ElementLabels[i], pos, CrazyEngine::Vector4(1.0f, 1.0f, 1.0f, 1.0f), m_Font, m_TextScale, depth + 0.5f, flags);
            }
        }
    }

    void TextDropdown::SetFontScale(float scale)
    {
        if (scale > 1.0f || scale <= 0.0f)
        {
            scale = 1.0f;
        }

        m_TextScale = (GetBounds().Height * scale) / m_Font->MeasureString("x", 1.0f).Y;
        m_TextYOffset = 0.5f + (scale / 2.0f);
        
        std::cout << m_TextYOffset << std::endl;
    }

    void TextDropdown::AddLabel(const std::string& label)
    {
        m_ElementLabels.push_back(label);

        Button* button = new Button(0, 0, 0, GetBounds().Height, m_ElementAtlas, this);
        AddElement(button);
    }
}