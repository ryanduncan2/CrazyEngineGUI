#ifndef CRAZYENGINEGUI_FILL_H_
#define CRAZYENGINEGUI_FILL_H_

#include "CrazyEngine/Math/Rectangle.h"
#include "CrazyEngine/Graphics/Renderer2D.h"

namespace CEGUI
{
    class Fill
    {   
    public:
        Fill() { }
        ~Fill() { }

        virtual void Draw(CrazyEngine::Renderer2D& renderer, CrazyEngine::Rectanglef bounds, const CrazyEngine::Vector4& colourEffect, float depth, int flags) const noexcept = 0;
    };
}

#endif