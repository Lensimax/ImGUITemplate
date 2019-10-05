add_subdirectory(glm)
add_subdirectory(glfw)

file(GLOB GLAD_SOURCES glad/src/glad.c)
file(GLOB GLAD_HEADERS glad/include/glad/glad.h)
set(GLAD_INCLUDE glad/include)

include_directories(${GLAD_INCLUDE})

add_library(glad STATIC ${GLAD_HEADERS} ${GLAD_SOURCES})


add_subdirectory(imgui)
