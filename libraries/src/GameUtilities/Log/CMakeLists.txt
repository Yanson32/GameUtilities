set(FILES 	"${CMAKE_CURRENT_SOURCE_DIR}/LogManager.cpp"
			"${CMAKE_CURRENT_SOURCE_DIR}/LogFormatter.cpp"
			"${CMAKE_CURRENT_SOURCE_DIR}/LogEntry.cpp"
)

set(RELATIVE_PATH "src/GameUtilities/Log")

set(SUB_DIRECTORIES "Target"
		     "Component"
)

#Add subdirectories
foreach(LOOP_VAR ${SUB_DIRECTORIES})
    add_subdirectory("${LOOP_VAR}")
endforeach()

if(FILES)
	#Add source file to target
	target_sources(	"Log" PRIVATE ${FILES})

	#Install source files
	install(FILES ${FILES} DESTINATION "${RELATIVE_PATH}")
endif()
