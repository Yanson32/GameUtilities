set(FILES   "${CMAKE_CURRENT_SOURCE_DIR}/RGBA.h"
            "${CMAKE_CURRENT_SOURCE_DIR}/AABB.h"
            "${CMAKE_CURRENT_SOURCE_DIR}/PhysicsObject.h"
            "${CMAKE_CURRENT_SOURCE_DIR}/QuadTree.h"
            "${CMAKE_CURRENT_SOURCE_DIR}/Rectangle.h"
)

set(RELATIVE_PATH "include/GameUtilities/Data")

set(SUB_DIRECTORIES "" )

#Add subdirectories
foreach(LOOP_VAR ${SUB_DIRECTORIES})
    add_subdirectory("${LOOP_VAR}")
endforeach()

if(FILES)
	#Add source file to target
	target_sources(	"Data" PRIVATE ${FILES})

	#Install source files
	install(FILES ${FILES} DESTINATION "${RELATIVE_PATH}" COMPONENT "libs")
endif()
