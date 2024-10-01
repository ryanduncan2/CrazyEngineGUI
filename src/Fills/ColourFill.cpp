#include "CrazyEngineGUI/Fills/ColourFill.h"

#include "CrazyEngine/Math/Vector4.h"

namespace CEGUI
{
    ColourFill::ColourFill(const CrazyEngine::Vector4& colour)
        : m_Colour(colour)
    {
    }

    void ColourFill::Draw(CrazyEngine::Renderer2D& renderer, CrazyEngine::Rectanglef bounds, const CrazyEngine::Vector4& colourEffect, float depth, int flags) const noexcept 
    {
        renderer.Draw(bounds, m_Colour * colourEffect, depth, flags);
    }
}