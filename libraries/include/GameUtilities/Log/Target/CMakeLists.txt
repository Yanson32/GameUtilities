set(FILES 	"${CMAKE_CURRENT_SOURCE_DIR}/LogTarget.h"
			"${CMAKE_CURRENT_SOURCE_DIR}/LogFileTarget.h"
)

set(RELATIVE_PATH "include/GameUtilities/Log/Target")

set(SUB_DIRECTORIES ""
)

#Add subdirectories
foreach(LOOP_VAR ${SUB_DIRECTORIES})
    add_subdirectory("${LOOP_VAR}")
endforeach()

if(FILES)
	#Add source file to target
	target_sources(	"Log" PRIVATE ${FILES})

	#Install source files
	install(FILES ${FILES} DESTINATION "${RELATIVE_PATH}" COMPONENT "libs")
endif()
