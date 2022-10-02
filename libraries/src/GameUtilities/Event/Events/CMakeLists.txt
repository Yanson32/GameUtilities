set(FILES
"${CMAKE_CURRENT_SOURCE_DIR}/Event.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/OnChangeState.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/OnPlaySound.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/OnPop.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/OnPlayMusic.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/OnPushState.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/OnLog.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/OnMessage.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/OnRefresh.cpp"
#"${CMAKE_CURRENT_SOURCE_DIR}/OnStart.cpp"
#"${CMAKE_CURRENT_SOURCE_DIR}/OnUpdate.cpp"
#"${CMAKE_CURRENT_SOURCE_DIR}/OnPause.cpp"
#"${CMAKE_CURRENT_SOURCE_DIR}/OnResume.cpp"
#"${CMAKE_CURRENT_SOURCE_DIR}/OnStop.cpp"

)

set(RELATIVE_PATH "src/GameUtilities/Event/Events")

set(SUB_DIRECTORIES "Mouse"
                    "Keyboard"
                    "Widget"
)

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
