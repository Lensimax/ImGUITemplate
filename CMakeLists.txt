project(TemplateImGui)
cmake_minimum_required(VERSION 2.8)

set(APP_TARGET imgui-template)

# 3rd party libraries
add_subdirectory(thirdparty)

#find_package(ImGui)
#find_package(glm)
#find_package(glfw)


# projects
set(SRCS
    src/test.cpp
)

add_executable(template ${SRCS})

target_link_libraries(template glfw)

