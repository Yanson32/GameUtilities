set(FILES "${CMAKE_CURRENT_SOURCE_DIR}/Manager.h"
"${CMAKE_CURRENT_SOURCE_DIR}/Base.h"
"${CMAKE_CURRENT_SOURCE_DIR}/LifeSpan.h"
"${CMAKE_CURRENT_SOURCE_DIR}/Position.h"
"${CMAKE_CURRENT_SOURCE_DIR}/Velocity.h"
"${CMAKE_CURRENT_SOURCE_DIR}/Id.h"
)
set(SUB_DIRECTORIES ""
)

set(RELATIVE_PATH "include/GameUtilities/ParticleSystem/Component")

#Add subdirectories
foreach(LOOP_VAR ${SUB_DIRECTORIES})
    add_subdirectory("${LOOP_VAR}")
endforeach()


if(FILES)
	#Add source file to target
	target_sources(	"ParticleSystem" PRIVATE ${FILES})

	#Install source files
	install(FILES ${FILES} DESTINATION "${RELATIVE_PATH}")
endif()
