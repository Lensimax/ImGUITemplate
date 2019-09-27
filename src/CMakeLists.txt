set(SRCS
    test.cpp
    )
    
# Notre exécutable
add_executable(template ${SRCS})

target_link_libraries(template glfw)