set(FILES
"${CMAKE_CURRENT_SOURCE_DIR}/Event.h"
"${CMAKE_CURRENT_SOURCE_DIR}/ChangeState.h"
"${CMAKE_CURRENT_SOURCE_DIR}/PlaySound.h"
"${CMAKE_CURRENT_SOURCE_DIR}/Pop.h"
"${CMAKE_CURRENT_SOURCE_DIR}/PlayMusic.h"
"${CMAKE_CURRENT_SOURCE_DIR}/PushState.h"
"${CMAKE_CURRENT_SOURCE_DIR}/LogEvent.h"
)

set(RELATIVE_PATH "include/GameUtilities/Event/Events")

set(SUB_DIRECTORIES "Mouse"
                    "Keyboard"
                    "Widget"
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
