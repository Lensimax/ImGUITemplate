make_executable()


include_directories(
    ${GLM_INCLUDE_DIR}
    ${OPENGL_INCLUDE_DIR}
    ${GLFW_INCLUDE_DIR}
    ${IMGUI_INCLUDE_DIR}
    )
    
target_link_libraries(${PROJECT}
    ${OPENGL_LIBRARIES}
    ${GLFW_LIBRARIES}
    ${IMGUI_LIBRARIES}
    )