set(FILES
"${CMAKE_CURRENT_SOURCE_DIR}/OnCheck.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/OnComboChanged.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/OnTextChanged.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/OnSliderChanged.cpp"

)

set(RELATIVE_PATH "src/GameUtilities/Event/Events/Widget")

set(SUB_DIRECTORIES ""
)

#Add subdirectories
foreach(LOOP_VAR ${SUB_DIRECTORIES})
    add_subdirectory("${LOOP_VAR}")
endforeach()

if(FILES)
	#Add source file to target
	target_sources(	"Event" PRIVATE ${FILES})

	#Install source files
	install(FILES ${FILES} DESTINATION "${RELATIVE_PATH}" COMPONENT "libs")
endif()
