set(FILES
"${CMAKE_CURRENT_SOURCE_DIR}/Event.h"
"${CMAKE_CURRENT_SOURCE_DIR}/EventManager.h"
"${CMAKE_CURRENT_SOURCE_DIR}/Dispatcher.h"
"${CMAKE_CURRENT_SOURCE_DIR}/EventQueue.h"
"${CMAKE_CURRENT_SOURCE_DIR}/Listener.h"
"${CMAKE_CURRENT_SOURCE_DIR}/ChangeState.h"
"${CMAKE_CURRENT_SOURCE_DIR}/PlaySound.h"
"${CMAKE_CURRENT_SOURCE_DIR}/SoundVolumeChanged.h"
"${CMAKE_CURRENT_SOURCE_DIR}/MusicVolumeChanged.h"
"${CMAKE_CURRENT_SOURCE_DIR}/Pop.h"
"${CMAKE_CURRENT_SOURCE_DIR}/PlayMusic.h"
"${CMAKE_CURRENT_SOURCE_DIR}/PushState.h"
"${CMAKE_CURRENT_SOURCE_DIR}/Events.h"
"${CMAKE_CURRENT_SOURCE_DIR}/EventHandler.h"
"${CMAKE_CURRENT_SOURCE_DIR}/Click.h"
"${CMAKE_CURRENT_SOURCE_DIR}/Id.h"
)

set(RELATIVE_PATH "include/GameUtilities/Event")

set(SUB_DIRECTORIES "")

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
