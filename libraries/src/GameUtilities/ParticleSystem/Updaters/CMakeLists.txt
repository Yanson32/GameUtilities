set(FILES 	"${CMAKE_CURRENT_SOURCE_DIR}/UpdaterBase.cpp"
			"${CMAKE_CURRENT_SOURCE_DIR}/UpdateManager.cpp"
			"${CMAKE_CURRENT_SOURCE_DIR}/Position.cpp"
)
set(SUB_DIRECTORIES ""
)

set(RELATIVE_PATH "src/GameUtilities/ParticleSystem")

#Add subdirectories
foreach(LOOP_VAR ${SUB_DIRECTORIES})
    add_subdirectory("${LOOP_VAR}")
endforeach()

if(FILES)
	#Add source file to target
	target_sources(	"ParticleSystem" PRIVATE ${FILES})

	#Install source files
	install(FILES ${FILES} DESTINATION "${CMAKE_INSTALL_PREFIX}/${RELATIVE_PATH}")
endif()
