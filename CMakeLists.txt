project(TemplateImGui)
cmake_minimum_required(VERSION 2.8)

set(APP_TARGET imgui-template)

# 3rd party libraries
add_subdirectory(thirdparty)

#find_package(ImGui)
#find_package(glm)
#find_package(glfw)


# projects
#set(SRCS
#    src/test.cpp
#)

file(GLOB_RECURSE SRCS 
	src/*.c
	src/*.cpp
)


file(GLOB_RECURSE HEADERS 
	src/*.h
	src/*.hpp
)


add_executable(template ${HEADERS} ${SRCS})

target_link_libraries(template glfw glm_static)

