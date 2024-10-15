cmake_minimum_required(VERSION 3.24.2)
project(RobotInvasion VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# find_package(OpenGL REQUIRED)

set(SRC_FILES
    src/UIComponent.cpp
    src/TransformManager.cpp

    src/Fills/TextureFill.cpp
    src/Fills/TextureAtlasFill.cpp
    src/Fills/ColourFill.cpp

    src/Transforms/UITranslation.cpp
    
    src/Transforms/Scales/PixelScale.cpp
    src/Transforms/Scales/RelativeScale.cpp
    src/Transforms/Scales/AspectRatioScale.cpp

    src/Transforms/Translations/PixelTranslation.cpp
    src/Transforms/Translations/RelativeTranslation.cpp
    src/Transforms/Translations/CentreTranslation.cpp

    src/Components/Canvas.cpp
    src/Components/Image.cpp
    src/Components/Button.cpp
    src/Components/Checkbox.cpp
    src/Components/Label.cpp
    src/Components/Dropdown.cpp
    src/Components/TextDropdown.cpp
)

add_library(CrazyEngineGUI STATIC ${SRC_FILES})
target_include_directories(CrazyEngineGUI PRIVATE include "${CRAZYENGINE_INCLUDE_DIRS}")
target_link_libraries(CrazyEngineGUI PRIVATE "${CRAZYENGINE_LIBRARIES}")