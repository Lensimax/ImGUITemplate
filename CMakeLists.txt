project(TemplateImGui)
cmake_minimum_required(VERSION 2.8)

set(APP_TARGET imgui-template)

# affectation des variables pour les includes
set(GLM_INCLUDE_DIR thirdparty/glm)
set(GLFW_INCLUDE_DIR thirdparty/glfw/include)
set(IMGUI_INCLUDE_DIR thirdparty/imgui)
set(GL3W_INCLUDE_DIR thirdparty/gl3w)

# 3rd party libraries
add_subdirectory(thirdparty)

#find_package(glm)
#find_package(glfw)
#find_package(imgui)



# SRCS prends la valeur des sources
file(GLOB_RECURSE SRCS
	src/*.c
	src/*.cpp
)

# SRCS prends la valeur des headers
file(GLOB_RECURSE HEADERS
	src/*.h
	src/*.hpp
)



add_definitions(-DIMGUI_IMPL_OPENGL_LOADER_GLAD)
add_definitions(-DGLFW_INCLUDE_NONE)




add_executable(template ${HEADERS} ${SRCS})

# ajout des includes directory
include_directories(
        ${GLM_INCLUDE_DIR}
        ${GLFW_INCLUDE_DIR}
        ${GL3W_INCLUDE_DIR}
        ${IMGUI_INCLUDE_DIR}
        ${OPENGL_INCLUDE_DIR}
)

target_link_libraries(template glfw glm_static gl3w imgui ${OPENGL_LIBRARIES})
