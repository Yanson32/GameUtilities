set(FILES 	"${CMAKE_CURRENT_SOURCE_DIR}/LogComponent.cpp"
	    "${CMAKE_CURRENT_SOURCE_DIR}/MsgComponent.cpp"
			"${CMAKE_CURRENT_SOURCE_DIR}/DateComponent.cpp"
			"${CMAKE_CURRENT_SOURCE_DIR}/TimeComponent.cpp"
			"${CMAKE_CURRENT_SOURCE_DIR}/FileComponent.cpp"
			"${CMAKE_CURRENT_SOURCE_DIR}/SeverityComponent.cpp"
			"${CMAKE_CURRENT_SOURCE_DIR}/LineComponent.cpp"

)

set(RELATIVE_PATH "include/GameUtilities/Log/Component")

set(SUB_DIRECTORIES ""
)

#Add subdirectories
foreach(LOOP_VAR ${SUB_DIRECTORIES})
    add_subdirectory("${LOOP_VAR}")
endforeach()

if(FILES)
	#Add source file to target
	target_sources(	"Log" PRIVATE ${FILES})

	#Install source files
	install(FILES ${FILES} DESTINATION "${RELATIVE_PATH}" COMPONENT "libs")
endif()
