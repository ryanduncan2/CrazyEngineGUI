#ifndef CRAZYENGINEGUI_COMPONENTS_IMAGE_H_
#define CRAZYENGINEGUI_COMPONENTS_IMAGE_H_

#include "CrazyEngine/Graphics/Texture.h"

#include "CrazyEngineGUI/Fill.h"
#include "CrazyEngineGUI/UIComponent.h"

namespace CEGUI
{
    class Image : public UIComponent
    {
    private:

        Fill* m_Fill;

    public:
        Image(std::int32_t x, std::int32_t y, std::uint32_t width, std::uint32_t height, CrazyEngine::Texture* texture, UIComponent* parent = nullptr);
        Image(std::int32_t x, std::int32_t y, std::uint32_t width, std::uint32_t height, const CrazyEngine::Vector4& colour, UIComponent* parent = nullptr);
        ~Image();

        void Draw(CrazyEngine::Renderer2D& renderer, const CrazyEngine::Vector4& colourEffect, float depth = 0.0f, int flags = 1) override;
    };
}

#endif