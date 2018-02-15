#Append all header files
set_property(
GLOBAL
APPEND
PROPERTY 
${PROJECT_NAME}_SOURCE_FILES
"${CMAKE_CURRENT_SOURCE_DIR}/ClickableText.cpp"
)


set(DIRECTORIES
"Screen"
)


#Add subdirectories
if(NOT ${FILES} STREQUAL "")
	install(FILES ${FILES} DESTINATION "${RELATIVE_PATH}")
endif()
