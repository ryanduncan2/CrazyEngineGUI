#ifndef CRAZYENGINEGUI_COMPONENTS_CHECKBOX_H_
#define CRAZYENGINEGUI_COMPONENTS_CHECKBOX_H_

#include "CrazyEngineGUI/UIComponent.h"
#include "CrazyEngineGUI/Fills/TextureAtlasFill.h"

namespace CEGUI
{
    class Checkbox : public UIComponent
    {
    public:

        enum CheckboxState
        {
            NEUTRAL, HOVERED, PRESSED, CLICKED
        };

    private:

        bool m_Checked;
        CheckboxState m_State;
        TextureAtlasFill m_Atlas;

    public:

        Checkbox(std::int32_t x, std::int32_t y, std::uint32_t width, std::uint32_t height, CrazyEngine::Texture* texture, UIComponent* parent) noexcept;
        ~Checkbox() noexcept;

        CheckboxState GetState() const noexcept;
        bool IsClicked() const noexcept;
        bool IsChecked() const noexcept;

        void SetChecked(bool checked) noexcept;

        void Update(CrazyEngine::Input& input, CrazyEngine::Clock& clock) override;
        void Draw(CrazyEngine::Renderer2D& renderer, const CrazyEngine::Vector4& colourEffect, float depth = 0.0f, int flags = 0) override;
    };
}

#endif