set(FILES
"${CMAKE_CURRENT_SOURCE_DIR}/FrameRate.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/PreferencesManager.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/String.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/Paths.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/ResourceManager.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/Resource.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/ProgramArguments.cpp"
)

set(RELATIVE_PATH "src/GameUtilities/Core")

set(SUB_DIRECTORIES "")

#Add subdirectories
foreach(LOOP_VAR ${SUB_DIRECTORIES})
    add_subdirectory("${LOOP_VAR}")
endforeach()

if(FILES)
	#Add source file to target
	target_sources(	"Core" PRIVATE ${FILES})

	#Install source files
	install(FILES ${FILES} DESTINATION "${RELATIVE_PATH}")
endif()
