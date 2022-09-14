set(FILES   "${CMAKE_CURRENT_SOURCE_DIR}/RGBA.cpp"
            "${CMAKE_CURRENT_SOURCE_DIR}/AABB.cpp"
            "${CMAKE_CURRENT_SOURCE_DIR}/QuadTree.cpp"
            "${CMAKE_CURRENT_SOURCE_DIR}/Rectangle.cpp"
)

set(RELATIVE_PATH "src/GameUtilities/Data")

set(SUB_DIRECTORIES "")

#Add subdirectories
foreach(LOOP_VAR ${SUB_DIRECTORIES})
    add_subdirectory("${LOOP_VAR}")
endforeach()

if(FILES)
	#Add source file to target
	target_sources(	"Data" PRIVATE ${FILES})

	#Install source files
	install(FILES ${FILES} DESTINATION "${RELATIVE_PATH}")
endif()
