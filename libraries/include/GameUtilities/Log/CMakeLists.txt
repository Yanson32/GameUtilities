set(FILES 	"${CMAKE_CURRENT_SOURCE_DIR}/LogType.h"
			"${CMAKE_CURRENT_SOURCE_DIR}/LogManager.h"
			"${CMAKE_CURRENT_SOURCE_DIR}/LogFormatter.h"
			"${CMAKE_CURRENT_SOURCE_DIR}/LogEntry.h"
)

set(RELATIVE_PATH "include/GameUtilities/Log")

set(SUB_DIRECTORIES "Component"
										"Target"
										"Filter"
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
