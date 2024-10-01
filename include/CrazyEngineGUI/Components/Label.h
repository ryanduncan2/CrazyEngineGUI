#ifndef CRAZYENGINEGUI_COMPONENTS_LABEL_H_
#define CRAZYENGINEGUI_COMPONENTS_LABEL_H_

#include "CrazyEngineGUI/UIComponent.h"

#include <string>

#include "CrazyEngine/Math/Vector4.h"

namespace CEGUI
{
    class Label : public UIComponent
    {
    private:

        std::string m_Text;
        float m_Scale;
        CrazyEngine::Vector4 m_Colour;
        CrazyEngine::TextureFont* m_Font;

    public:

        Label(std::int32_t x, std::int32_t y, const std::string& text, float scale, CrazyEngine::TextureFont* font, const CrazyEngine::Vector4& colour, UIComponent* parent) noexcept;
        ~Label() noexcept;

        std::string GetText() const noexcept;
        CrazyEngine::Vector4 GetColour() const noexcept;

        void SetText(std::string text) noexcept;
        void SetColour(const CrazyEngine::Vector4& colour) noexcept;

        void Update(CrazyEngine::Input& input, CrazyEngine::Clock& clock) override;
        void Draw(CrazyEngine::Renderer2D& renderer, const CrazyEngine::Vector4& colourEffect, float depth = 0.0f, int flags = 0) override;
    };
}

#endif