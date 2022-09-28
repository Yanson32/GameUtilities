set(FILES
"${CMAKE_CURRENT_SOURCE_DIR}/EventManager.h"
"${CMAKE_CURRENT_SOURCE_DIR}/Dispatcher.h"
"${CMAKE_CURRENT_SOURCE_DIR}/EventQueue.h"
"${CMAKE_CURRENT_SOURCE_DIR}/Listener.h"
"${CMAKE_CURRENT_SOURCE_DIR}/Events.h"
"${CMAKE_CURRENT_SOURCE_DIR}/EventHandler.h"
"${CMAKE_CURRENT_SOURCE_DIR}/EventId.h"
)

set(RELATIVE_PATH "include/GameUtilities/Event")

set(SUB_DIRECTORIES "Events")

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
