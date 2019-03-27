set(FILES "${CMAKE_CURRENT_SOURCE_DIR}/Id.h"
"${CMAKE_CURRENT_SOURCE_DIR}/Acceleration.h"
"${CMAKE_CURRENT_SOURCE_DIR}/LifeSpan.h"
"${CMAKE_CURRENT_SOURCE_DIR}/Position.h"
"${CMAKE_CURRENT_SOURCE_DIR}/Attribute.h"
"${CMAKE_CURRENT_SOURCE_DIR}/Velocity.h"
"${CMAKE_CURRENT_SOURCE_DIR}/Color.h"
)
set(SUB_DIRECTORIES ""
)

#Add subdirectories
foreach(LOOP_VAR ${SUB_DIRECTORIES})
    add_subdirectory("${LOOP_VAR}")
endforeach()

string(REGEX MATCH "(/|\\|\)(include|src|test)(/|\\|\).*" RELATIVE_PATH "${CMAKE_CURRENT_SOURCE_DIR}")
if(FILES)
	#Add source file to target
	target_sources(	"${PROJECT_NAME}" PRIVATE ${FILES})

	#Install source files
	install(FILES ${FILES} DESTINATION "${RELATIVE_PATH}")
endif()
