set(FILES	"${CMAKE_CURRENT_SOURCE_DIR}/FrameRate.h"
		    "${CMAKE_CURRENT_SOURCE_DIR}/Resource Holder.h"
		    "${CMAKE_CURRENT_SOURCE_DIR}/NonCopyable.h"
            "${CMAKE_CURRENT_SOURCE_DIR}/Macros.h"
            "${CMAKE_CURRENT_SOURCE_DIR}/String.h"
	        "${CMAKE_CURRENT_SOURCE_DIR}/PreferencesManager.h"
	        "${CMAKE_CURRENT_SOURCE_DIR}/Paths.h"
	        "${CMAKE_CURRENT_SOURCE_DIR}/Thread.h"
		    "${CMAKE_CURRENT_SOURCE_DIR}/RAIIStream.h"
		    "${CMAKE_CURRENT_SOURCE_DIR}/ResourceManager.h"
		    "${CMAKE_CURRENT_SOURCE_DIR}/Resource.h"
		    "${CMAKE_CURRENT_SOURCE_DIR}/ProgramArguments.h"

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
