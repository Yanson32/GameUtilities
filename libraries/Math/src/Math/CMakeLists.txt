set(FILES "${CMAKE_CURRENT_SOURCE_DIR}/Degree.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/Radian.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/Point.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/Line.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/Ray.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/Vector.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/Functions.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/cVector.cpp"
)

set(SUB_DIRECTORIES "")

#Add subdirectories
foreach(LOOP_VAR ${SUB_DIRECTORIES})
    add_subdirectory("${LOOP_VAR}")
endforeach()

string(REGEX MATCH "(/|\\|\)(include|src|test)(/|\\|\).*" RELATIVE_PATH "${CMAKE_CURRENT_SOURCE_DIR}")
if(FILES)
	#Add source file to target
	target_sources(	"${PROJECT_NAME}" PRIVATE ${FILES})

	#Install source files
	install(FILES ${FILES} DESTINATION "${CMAKE_INSTALL_PREFIX}/${RELATIVE_PATH}")
endif()
