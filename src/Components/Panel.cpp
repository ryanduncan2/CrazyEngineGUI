#include "CrazyEngineGUI/Components/Panel.h"

namespace CEGUI
{
    Panel::Panel(std::int32_t x, std::int32_t y, std::uint32_t width, std::uint32_t height, UIComponent* parent)
        : UIComponent(x, y, width, height, parent)
    {
    }

    Panel::~Panel()
    {
    }
}