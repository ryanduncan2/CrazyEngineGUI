#ifndef CRAZYENGINEGUI_CANVAS_H_
#define CRAZYENGINEGUI_CANVAS_H_

#include <cstdint>

#include "CrazyEngineGUI/UIComponent.h"

namespace CEGUI
{
    class Canvas : public UIComponent
    {
    public:
        Canvas(std::int32_t x, std::int32_t y, std::uint32_t width, std::uint32_t height);
        ~Canvas();
    };
}

#endif