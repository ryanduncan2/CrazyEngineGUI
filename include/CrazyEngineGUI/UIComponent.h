#ifndef CRAZYENGINEGUI_UICOMPONENT
#define CRAZYENGINEGUI_UICOMPONENT

#include <vector>

#include "CrazyEngine/Core/Input.h"
#include "CrazyEngine/Core/Clock.h"
#include "CrazyEngine/Graphics/Renderer2D.h"

#include "CrazyEngineGUI/TransformManager.h"

namespace CEGUI
{
    class UIComponent
    {
    private:

        UIComponent* m_Parent;
        TransformManager m_TransformManager;
        std::vector<UIComponent*> m_Children;
        CrazyEngine::Rectanglef m_Bounds;

        CrazyEngine::Vector4 m_ColourEffect;

    protected:

        UIComponent(UIComponent* parent = nullptr);
        UIComponent(const std::uint32_t width, const std::uint32_t height, UIComponent* parent = nullptr);
        UIComponent(const std::int32_t x, const std::int32_t y, const std::uint32_t width, const std::uint32_t height, UIComponent* parent = nullptr);

        void Initialise(const std::int32_t x, const std::int32_t y, const std::uint32_t width, const std::uint32_t height);

    public:

        ~UIComponent();

        void AddChild(UIComponent* child);
        void RemoveChild(UIComponent* child);
        void SetParent(UIComponent* parent);
        virtual void Refresh();

        virtual void Update(CrazyEngine::Input& input, CrazyEngine::Clock& clock);
        virtual void Draw(CrazyEngine::Renderer2D& renderer, const CrazyEngine::Vector4& colourEffect, float depth = 0.0f, int flags = 0);

        void SetColourEffect(const CrazyEngine::Vector4& colour);
        CrazyEngine::Vector4 GetColourEffect() const noexcept;

        CrazyEngine::Rectanglef GetBounds() { return m_Bounds; }
        TransformManager& GetTransformManager() { return m_TransformManager; }
        std::vector<UIComponent*>& GetChildren() { return m_Children; }
    };
}

#endif