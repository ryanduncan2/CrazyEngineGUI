#include "CrazyEngineGUI/TransformManager.h"

namespace CEGUI
{
    TransformManager::TransformManager(UITranslation* xTranslation, UITranslation* yTranslation, UIScale* widthScale, UIScale* heightScale)
    {
        m_XTranslation = xTranslation;
        m_MinXTranslation = nullptr;
        m_MaxXTranslation = nullptr;

        m_YTranslation = yTranslation;
        m_MinYTranslation = nullptr;
        m_MaxYTranslation = nullptr;

        m_WidthScale = widthScale;
        m_MinWidthScale = nullptr;
        m_MaxWidthScale = nullptr;

        m_HeightScale = heightScale;
        m_MinHeightScale = nullptr;
        m_MaxHeightScale = nullptr;
    }

    TransformManager::~TransformManager()
    {
        delete m_XTranslation;
        delete m_MinXTranslation;
        delete m_MaxXTranslation;
        delete m_YTranslation;
        delete m_MinYTranslation;
        delete m_MaxYTranslation;
        delete m_WidthScale;
        delete m_MinWidthScale;
        delete m_MaxWidthScale;
        delete m_HeightScale;
        delete m_MinHeightScale;
        delete m_MaxHeightScale;
    }

    void TransformManager::SetX(UITranslation* xTranslation)
    {
        if (m_XTranslation != nullptr)
        {
            delete m_XTranslation;
        }

        m_XTranslation = xTranslation;
    }

    void TransformManager::SetY(UITranslation* yTranslation)
    {
        if (m_YTranslation != nullptr)
        {
            delete m_YTranslation;
        }

        m_YTranslation = yTranslation;
    }

    void TransformManager::SetWidth(UIScale* widthScale)
    {
        if (m_WidthScale != nullptr)
        {
            delete m_WidthScale;
        }

        m_WidthScale = widthScale;
    }

    void TransformManager::SetHeight(UIScale* heightScale)
    {
        if (m_HeightScale != nullptr)
        {
            delete m_HeightScale;
        }

        m_HeightScale = heightScale;
    }

    std::int32_t TransformManager::GetX(const CrazyEngine::Rectanglef& componentBounds, const CrazyEngine::Rectanglef& parentBounds) const
    {
        std::int32_t value = m_XTranslation->TranslateX(componentBounds, parentBounds);

        if (m_MinXTranslation != nullptr)
        {
            std::int32_t min = m_MinXTranslation->TranslateX(componentBounds, parentBounds);

            if (value <= min)
            {
                return min;
            }
        }

        if (m_MaxXTranslation != nullptr)
        {
            std::int32_t max = m_MaxXTranslation->TranslateX(componentBounds, parentBounds);

            if (value >= max)
            {
                return max;
            }
        }

        return value;
    }

    std::int32_t TransformManager::GetY(const CrazyEngine::Rectanglef& componentBounds, const CrazyEngine::Rectanglef& parentBounds) const
    {
        std::int32_t value = m_YTranslation->TranslateY(componentBounds, parentBounds);

        if (m_MinYTranslation != nullptr)
        {
            std::int32_t min = m_MinYTranslation->TranslateY(componentBounds, parentBounds);

            if (value < min)
            {
                return min;
            }
        }

        if (m_MaxYTranslation != nullptr)
        {
            std::int32_t max = m_MaxYTranslation->TranslateY(componentBounds, parentBounds);

            if (value > max)
            {
                return max;
            }
        }

        return value;
    }

    std::uint32_t TransformManager::GetWidth(const CrazyEngine::Rectanglef& compBounds, const CrazyEngine::Rectanglef& parentBounds) const
    {
        std::uint32_t value = m_WidthScale->ScaleWidth(compBounds, parentBounds);

        if (m_MinWidthScale != nullptr)
        {
            std::uint32_t min = m_MinWidthScale->ScaleWidth(compBounds, parentBounds);

            if (value < min)
            {
                return min;
            }
        }

        if (m_MaxWidthScale != nullptr)
        {
            std::uint32_t max = m_MaxWidthScale->ScaleWidth(compBounds, parentBounds);

            if (value > max)
            {
                return max;
            }
        }

        return value;
    }

    std::uint32_t TransformManager::GetHeight(const CrazyEngine::Rectanglef& componentBounds, const CrazyEngine::Rectanglef& parentBounds) const
    {
        std::uint32_t value = m_HeightScale->ScaleHeight(componentBounds, parentBounds);

        if (m_MinHeightScale != nullptr)
        {
            std::uint32_t min = m_MinHeightScale->ScaleHeight(componentBounds, parentBounds);

            if (value < min)
            {
                return min;
            }
        }

        if (m_MaxHeightScale != nullptr)
        {
            std::uint32_t max = m_MaxHeightScale->ScaleHeight(componentBounds, parentBounds);

            if (value > max)
            {
                return max;
            }
        }

        return value;
    }
}
