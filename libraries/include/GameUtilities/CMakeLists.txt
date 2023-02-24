set(FILES ""
)

set(RELATIVE_PATH "include/GameUtilities")

set(SUB_DIRECTORIES
"Event"
"Core"
"ParticleSystem"
"Engin"
"TP"
"Log"
"Data"
"Algorithm"
"Window"
)

#Add subdirectories
foreach(LOOP_VAR ${SUB_DIRECTORIES})
    add_subdirectory("${LOOP_VAR}")
endforeach()

if(FILES)
	#Add source file to target
	target_sources(	"Core" PRIVATE ${FILES})

	#Install source files
	install(FILES ${FILES} DESTINATION "${RELATIVE_PATH}" COMPONENT "libs")
endif()
