set(FILES 	"${CMAKE_CURRENT_SOURCE_DIR}/ThreadPool.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/ThreadQueue.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/ThreadTask.cpp"
)

set(RELATIVE_PATH "src/GameUtilities/TP")

set(SUB_DIRECTORIES ""
)

#Add subdirectories
foreach(LOOP_VAR ${SUB_DIRECTORIES})
    add_subdirectory("${LOOP_VAR}")
endforeach()

if(FILES)
	#Add source file to target
	target_sources(	"ThreadPool" PRIVATE ${FILES})

	#Install source files
	install(FILES ${FILES} DESTINATION "${RELATIVE_PATH}")
endif()
