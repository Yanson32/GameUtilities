set(FILES
"${CMAKE_CURRENT_SOURCE_DIR}/OnContextMenu.h"
"${CMAKE_CURRENT_SOURCE_DIR}/OnStartMouseDrag.h"
"${CMAKE_CURRENT_SOURCE_DIR}/OnEndMouseDrag.h"
"${CMAKE_CURRENT_SOURCE_DIR}/OnMouseButtonReleased.h"
"${CMAKE_CURRENT_SOURCE_DIR}/OnMouseButtonPressed.h"
"${CMAKE_CURRENT_SOURCE_DIR}/OnMouseWheel.h"
"${CMAKE_CURRENT_SOURCE_DIR}/OnClick.h"
"${CMAKE_CURRENT_SOURCE_DIR}/OnDoubleClick.h"
"${CMAKE_CURRENT_SOURCE_DIR}/OnMouseMoved.h"
)

set(RELATIVE_PATH "include/GameUtilities/Event/Events/Mouse")

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
