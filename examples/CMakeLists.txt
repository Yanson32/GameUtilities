set(FILES ""

)
set(SUB_DIRECTORIES "Engin")

#Add the Box2D sub directory only when GU_BUILD_BOX2D_EXAMPLES is set to true
option(GU_BUILD_BOX2D_EXAMPLES "Set to TRUE if you want to build box2d examples" FALSE)
if(GU_BUILD_BOX2D_EXAMPLES)
    list(APPEND SUB_DIRECTORIES "Box2D")
endif()

#Add subdirectories
foreach(LOOP_VAR ${SUB_DIRECTORIES})
    add_subdirectory("${LOOP_VAR}")
endforeach()

string(REGEX MATCH "(/|\\|\)(include|src|test)(examples)(/|\\|\).*" RELATIVE_PATH "${CMAKE_CURRENT_SOURCE_DIR}")
if(FILES)
	#Add source file to target
	target_sources(	"${PROJECT_NAME}" PRIVATE ${FILES})

	#Install source files
	install(FILES ${FILES} DESTINATION "${CMAKE_INSTALL_PREFIX}/${RELATIVE_PATH}")
endif()
