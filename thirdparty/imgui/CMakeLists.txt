

file(GLOB_RECURSE SRCS_IMGUI
	*.cpp
	*.c
)


file(GLOB_RECURSE HEADERS_IMGUI
	*.h
	*.hpp
)

add_definitions( -ldl )


add_definitions(-DIMGUI_IMPL_OPENGL_LOADER_GLAD)
add_definitions(-DGLFW_INCLUDE_NONE)



add_library(imgui STATIC ${SRCS_IMGUI} ${HEADERS_IMGUI} )
