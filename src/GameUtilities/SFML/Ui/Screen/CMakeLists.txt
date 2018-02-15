#Append all header files
set_property(
GLOBAL
APPEND
PROPERTY 
${PROJECT_NAME}_SOURCE_FILES
"${CMAKE_CURRENT_SOURCE_DIR}/ContentPane.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/Footer.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/Header.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/TextHeader.cpp"
)


set(DIRECTORIES
""
)


#Add subdirectories
foreach(LOOP_VAR ${DIRECTORIES})
    add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/${LOOP_VAR}")
endforeach()
