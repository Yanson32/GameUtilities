set(FILES
"${CMAKE_CURRENT_SOURCE_DIR}/EventManager.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/Dispatcher.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/EventQueue.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/Listener.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/EventHandler.cpp"
)

set(RELATIVE_PATH "src/GameUtilities/Event")

set(SUB_DIRECTORIES "Events")

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
