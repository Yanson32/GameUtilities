set(FILES
"${CMAKE_CURRENT_SOURCE_DIR}/OnKeyPressed.h"
"${CMAKE_CURRENT_SOURCE_DIR}/OnKeyReleased.h"
)

set(RELATIVE_PATH "include/GameUtilities/Event/Events/Keyboard")

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
