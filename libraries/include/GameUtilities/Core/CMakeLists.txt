set(FILES	"${CMAKE_CURRENT_SOURCE_DIR}/FrameRate.h"
		"${CMAKE_CURRENT_SOURCE_DIR}/Resource Holder.h"
		"${CMAKE_CURRENT_SOURCE_DIR}/NonCopyable.h"
)

set(RELATIVE_PATH "include/GameUtilities/Core")

set(SUB_DIRECTORIES "")

#Add subdirectories
foreach(LOOP_VAR ${SUB_DIRECTORIES})
    add_subdirectory("${LOOP_VAR}")
endforeach()

if(FILES)
	#Add source file to target
	target_sources(	"Core" PRIVATE ${FILES})

	#Install source files
	install(FILES ${FILES} DESTINATION "${RELATIVE_PATH}")
endif()
