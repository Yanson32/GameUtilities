set(FILES
"${CMAKE_CURRENT_SOURCE_DIR}/Event.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/Manager.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/Dispatcher.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/EventQueue.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/Listener.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/ChangeState.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/PlaySound.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/SoundVolumeChanged.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/MusicVolumeChanged.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/Pop.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/PlayMusic.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/PushState.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/EventHandler.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/Click.cpp"
)

set(RELATIVE_PATH "src/GameUtilities/Event")

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
