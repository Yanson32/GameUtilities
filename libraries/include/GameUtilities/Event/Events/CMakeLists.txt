set(FILES
"${CMAKE_CURRENT_SOURCE_DIR}/Event.h"
"${CMAKE_CURRENT_SOURCE_DIR}/OnChangeState.h"
"${CMAKE_CURRENT_SOURCE_DIR}/OnMessage.h"
"${CMAKE_CURRENT_SOURCE_DIR}/OnPlaySound.h"
"${CMAKE_CURRENT_SOURCE_DIR}/OnPop.h"
"${CMAKE_CURRENT_SOURCE_DIR}/OnPlayMusic.h"
"${CMAKE_CURRENT_SOURCE_DIR}/OnPushState.h"
"${CMAKE_CURRENT_SOURCE_DIR}/OnLog.h"
"${CMAKE_CURRENT_SOURCE_DIR}/OnRefresh.h"
#"${CMAKE_CURRENT_SOURCE_DIR}/OnStart.h"
#"${CMAKE_CURRENT_SOURCE_DIR}/OnUpdate.h"
#"${CMAKE_CURRENT_SOURCE_DIR}/OnPause.h"
#"${CMAKE_CURRENT_SOURCE_DIR}/OnResume.h"
#"${CMAKE_CURRENT_SOURCE_DIR}/OnStop.h"
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
