#ifndef CRAZYENGINEGUI_COMPONENTS_PANEL_H_
#define CRAZYENGINEGUI_COMPONENTS_PANEL_H_

#include "CrazyEngineGUI/UIComponent.h"

namespace CEGUI
{
    class Panel : public UIComponent
    {
    public:

        Panel(std::int32_t x, std::int32_t y, std::uint32_t width, std::uint32_t height, UIComponent* parent);
        ~Panel();
    };
}

#endif