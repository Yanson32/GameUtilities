set(FILES
"${CMAKE_CURRENT_SOURCE_DIR}/Engin.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/GameState.cpp")

set(RELATIVE_PATH "src/GameUtilities/Engin")

set(SUB_DIRECTORIES "")

#Add subdirectories
foreach(LOOP_VAR ${SUB_DIRECTORIES})
    add_subdirectory("${LOOP_VAR}")
endforeach()

if(FILES)
	#Add source file to target
	target_sources(	"Engin" PRIVATE ${FILES})

	#Install source files
	install(FILES ${FILES} DESTINATION "${RELATIVE_PATH}" COMPONENT "libs")
endif()
