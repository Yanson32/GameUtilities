set(FILES "${CMAKE_CURRENT_SOURCE_DIR}/SAT.cpp")

set(RELATIVE_PATH "src/GameUtilities/Algorithm/SAT")

set(SUB_DIRECTORIES "")

#Add subdirectories
foreach(LOOP_VAR ${SUB_DIRECTORIES})
    add_subdirectory("${LOOP_VAR}")
endforeach()

if(FILES)
	#Add source file to target
	target_sources(	"Algorithm" PRIVATE ${FILES})

	#Install source files
	install(FILES ${FILES} DESTINATION "${RELATIVE_PATH}")
endif()
