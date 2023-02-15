set(FILES   "${CMAKE_CURRENT_SOURCE_DIR}/Window.cpp"
            "${CMAKE_CURRENT_SOURCE_DIR}/WindowBase.cpp"
)

if(UNIX)
    list(APPEND FILES "${CMAKE_CURRENT_SOURCE_DIR}/WindowX11.cpp")
endif()

set(RELATIVE_PATH "src/GameUtilities/Window")

set(SUB_DIRECTORIES ""
)

#Add subdirectories
foreach(LOOP_VAR ${SUB_DIRECTORIES})
    add_subdirectory("${LOOP_VAR}")
endforeach()

if(FILES)
	#Add source file to target
	target_sources(	"Window" PRIVATE ${FILES})

	#Install source files
	install(FILES ${FILES} DESTINATION "${RELATIVE_PATH}")
endif()
