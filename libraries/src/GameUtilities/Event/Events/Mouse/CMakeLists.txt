set(FILES
"${CMAKE_CURRENT_SOURCE_DIR}/OnContextMenu.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/OnStartMouseDrag.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/OnEndMouseDrag.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/OnMouseButtonPressed.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/OnMouseButtonReleased.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/OnMouseWheel.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/OnClick.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/OnDoubleClick.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/OnMouseMoved.cpp"
)

set(RELATIVE_PATH "src/GameUtilities/Event/Events/Mouse")

set(SUB_DIRECTORIES "")

#Add subdirectories
foreach(LOOP_VAR ${SUB_DIRECTORIES})
    add_subdirectory("${LOOP_VAR}")
endforeach()

if(FILES)
	#Add source file to target
	target_sources(	"Event" PRIVATE ${FILES})

	#Install source files
	install(FILES ${FILES} DESTINATION "${RELATIVE_PATH}" COMPONENT "libs")
endif()
