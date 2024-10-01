#ifndef CRAZYENGINEGUI_COMPONENTS_DROPDOWN_H_
#define CRAZYENGINEGUI_COMPONENTS_DROPDOWN_H_

#include "CrazyEngineGUI/UIComponent.h"
#include "CrazyEngineGUI/ComponentState.h"
#include "CrazyEngineGUI/Fills/TextureAtlasFill.h"

namespace CEGUI
{
    class Dropdown : public UIComponent
    {
    private:

        TextureAtlasFill m_Atlas;
        std::vector<UIComponent*> m_Elements;

        ComponentState m_State;
        bool m_Expanded;
        std::uint32_t m_ExpansionHeight;
        bool m_Contracting;

    public:

        Dropdown(std::int32_t x, std::int32_t y, std::uint32_t width, std::uint32_t height, CrazyEngine::Texture* texture, UIComponent* parent);
        ~Dropdown();

        bool IsClicked();
        ComponentState GetState();

        void Update(CrazyEngine::Input& input, CrazyEngine::Clock& clock) override;
        void Draw(CrazyEngine::Renderer2D& renderer, const CrazyEngine::Vector4& colourEffect, float depth = 0.0f, int flags = 0) override;

        void AddElement(UIComponent* component);
    };
}

#endif