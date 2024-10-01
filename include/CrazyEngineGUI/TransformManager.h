#ifndef CRAZYENGINEGUI_TRANSFORMMANAGER_H
#define CRAZYENGINEGUI_TRANSFORMMANAGER_H

#include "CrazyEngineGUI/Transforms/UIScale.h"
#include "CrazyEngineGUI/Transforms/UITranslation.h"
#include "CrazyEngine/Math/Rectangle.h"

namespace CEGUI
{
    class TransformManager
    {
    private:

        UITranslation* m_XTranslation;
        UITranslation* m_MinXTranslation;
        UITranslation* m_MaxXTranslation;

        UITranslation* m_YTranslation;
        UITranslation* m_MinYTranslation;
        UITranslation* m_MaxYTranslation;

        UIScale* m_WidthScale;
        UIScale* m_MinWidthScale;
        UIScale* m_MaxWidthScale;

        UIScale* m_HeightScale;
        UIScale* m_MinHeightScale;
        UIScale* m_MaxHeightScale;

    public:

        TransformManager() : TransformManager(nullptr, nullptr, nullptr, nullptr) { }
        TransformManager(UITranslation* xTranslation, UITranslation* yTranslation, UIScale* widthScale, UIScale* heightScale);
        ~TransformManager();

        void SetX(UITranslation* xTranslation);
        void SetMinX(UITranslation* xTranslation);
        void SetMaxX(UITranslation* xTranslation);

        void SetY(UITranslation* yTranslation);
        void SetMinY(UITranslation* yTranslation);
        void SetMaxY(UITranslation* yTranslation);

        void SetWidth(UIScale* widthScale);
        void SetMinWidth(UIScale* widthScale);
        void SetMaxWidth(UIScale* widthScale);

        void SetHeight(UIScale* heightScale);
        void SetMinHeight(UIScale* heightScale);
        void SetMaxHeight(UIScale* heightScale);

        std::int32_t GetX(const CrazyEngine::Rectanglef& compBounds, const CrazyEngine::Rectanglef& parentBounds) const;
        std::int32_t GetY(const CrazyEngine::Rectanglef& compBounds, const CrazyEngine::Rectanglef& parentBounds) const;
        std::uint32_t GetWidth(const CrazyEngine::Rectanglef& compBounds, const CrazyEngine::Rectanglef& parentBounds) const;
        std::uint32_t GetHeight(const CrazyEngine::Rectanglef& compBounds, const CrazyEngine::Rectanglef& parentBounds) const;
    };
}

#endif