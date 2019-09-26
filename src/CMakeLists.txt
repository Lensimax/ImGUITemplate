set(SRCS
    main.cpp
    )
    
# Notre exécutable
add_executable(main ${SRCS})

target_link_libraries(main imgui glm glfw)