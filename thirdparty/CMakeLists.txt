add_subdirectory(glm)
add_subdirectory(glfw)

file(GLOB GLAD_SOURCES glad/src/glad.c)
file(GLOB GLAD_HEADERS glad/include/glad/glad.h)
set(GLAD_INCLUDE_DIR glad/include)

include_directories(${GLAD_INCLUDE_DIR})


add_library(glad STATIC ${GLAD_HEADERS} ${GLAD_SOURCES})

set(GLAD_LIBRARIES glad)

if(NOT WIN32)
    set(GLAD_LIBRARIES ${GLAD_LIBRARIES} dl)
endif()

add_subdirectory(imgui)
