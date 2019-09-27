

file(GLOB_RECURSE SRCS_GLEW 
	GL/*.cpp
	GL/*.c
)


file(GLOB_RECURSE HEADERS_GLEW
	GL/*.h
	GL/*.hpp
)

include_directories(
    ${GL3W_INCLUDE_DIR}
)



add_library(glew STATIC ${SRCS_GLEW} ${HEADERS_GLEW} )


