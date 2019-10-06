add_subdirectory(glm)
add_subdirectory(glfw)

file(GLOB GL3W_SOURCES gl3w/GL/gl3w.c)
file(GLOB GL3W_HEADERS gl3w/GL/*.h)
set(GL3W_INCLUDE gl3w/)

include_directories(${GL3W_INCLUDE})

add_library(gl3w STATIC ${GL3W_HEADERS} ${GL3W_SOURCES})
set_target_properties(gl3w PROPERTIES LINKER_LANGUAGE C)


add_subdirectory(imgui)
