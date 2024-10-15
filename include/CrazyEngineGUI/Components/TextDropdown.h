#ifndef CRAZYENGINEGUI_COMPONENTS_TEXTDROPDOWN_H_
#define CRAZYENGINEGUI_COMPONENTS_TEXTDROPDOWN_H_

#include "CrazyEngineGUI/Components/Dropdown.h"
#include "CrazyEngineGUI/Components/Button.h"
#include "CrazyEngineGUI/Fills/TextureAtlasFill.h"

#include "CrazyEngine/Graphics/TextureFont.h"

namespace CEGUI
{
    class TextDropdown : public Dropdown
    {
    private:

        CrazyEngine::TextureFont* m_Font;
        TextureAtlasFill m_ElementAtlas;
        float m_TextScale;
        float m_TextOffset;

        std::int32_t m_SelectedIndex;
        std::vector<std::string> m_ElementLabels;

    public:

        TextDropdown(std::int32_t x, std::int32_t y, std::uint32_t width, std::uint32_t height, CrazyEngine::Texture* dropdownTexture, CrazyEngine::Texture* elementTexture, CrazyEngine::TextureFont* font, UIComponent* parent);
        ~TextDropdown();

        void Update(CrazyEngine::Input& input, CrazyEngine::Clock& clock) override;
        void Draw(CrazyEngine::Renderer2D& renderer, const CrazyEngine::Vector4& colourEffect, float depth = 0.0f, int flags = 0) override;

        void SetFontScale(float scale);

        void AddLabel(const std::string& label);
    };
}

#endif