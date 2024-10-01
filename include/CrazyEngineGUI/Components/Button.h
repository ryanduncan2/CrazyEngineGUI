#ifndef CRAZYENGINEGUI_COMPONENTS_BUTTON_H_
#define CRAZYENGINEGUI_COMPONENTS_BUTTON_H_

#include "CrazyEngineGUI/UIComponent.h"
#include "CrazyEngineGUI/ComponentState.h"
#include "CrazyEngineGUI/Fills/TextureAtlasFill.h"

namespace CEGUI
{
    class Button : public UIComponent
    {
    private:
        ComponentState m_State;
        TextureAtlasFill m_Atlas;

    public:
        Button(std::int32_t x, std::int32_t y, std::uint32_t width, std::uint32_t height, CrazyEngine::Texture* texture, UIComponent* parent);
        ~Button();

        ComponentState GetState();
        bool IsClicked();

        void Update(CrazyEngine::Input& input, CrazyEngine::Clock& clock) override;
        void Draw(CrazyEngine::Renderer2D& renderer, const CrazyEngine::Vector4& colourEffect, float depth = 0.0f, int flags = 0) override;
    };
}

#endif