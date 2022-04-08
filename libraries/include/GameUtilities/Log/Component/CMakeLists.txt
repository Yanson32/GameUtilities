set(FILES 	"${CMAKE_CURRENT_SOURCE_DIR}/LogComponent.h"
			"${CMAKE_CURRENT_SOURCE_DIR}/MsgComponent.h"
			"${CMAKE_CURRENT_SOURCE_DIR}/DateComponent.h"
			"${CMAKE_CURRENT_SOURCE_DIR}/TimeComponent.h"
			"${CMAKE_CURRENT_SOURCE_DIR}/FileComponent.h"
			"${CMAKE_CURRENT_SOURCE_DIR}/SeverityComponent.h"
			"${CMAKE_CURRENT_SOURCE_DIR}/Components.h"
			"${CMAKE_CURRENT_SOURCE_DIR}/ComponentId.h"
)

set(RELATIVE_PATH "include/GameUtilities/Log/Component")

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
