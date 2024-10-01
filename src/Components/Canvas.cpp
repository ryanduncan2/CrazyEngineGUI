#include "CrazyEngineGUI/Components/Canvas.h"

namespace CEGUI
{
    Canvas::Canvas(std::int32_t x, std::int32_t y, std::uint32_t width, std::uint32_t height)
        : UIComponent(x, y, width, height, nullptr)
    {
    }

    Canvas::~Canvas()
    {
    }
}