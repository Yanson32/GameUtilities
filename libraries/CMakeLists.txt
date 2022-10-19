set(GU_CONFIG_BUILD_DIR "${GameUtilities_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}")
set(GU_CONFIG_INSTALL_DIR "${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}")
					
					
#Build shared library by default
option(BUILD_SHARED_LIBS "True when building shared libraries" True)


#create a postfix for static libraries
if(NOT BUILD_SHARED_LIBS)
	set(STATIC_NAME_POSTFIX "-s")
endif()


include("Depricated")
include(GenerateExportHeader)

#Create targets
foreach(VAR ${GU_LIBS})

	add_library("${VAR}" "")

	#set targets output name
	set_target_properties("${VAR}" PROPERTIES
						DEBUG_POSTFIX "${STATIC_NAME_POSTFIX}-d"
						RELWITHDEBINFO_POSTFIX "${STATIC_NAME_POSTFIX}-d"
						RELEASE_POSTFIX "${STATIC_NAME_POSTFIX}"
                        MINSIZEREL_POSTFIX "${STATIC_NAME_POSTFIX}"

	)

	#Add includes to target
	target_include_directories("${VAR}" PUBLIC
	  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	  $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
	  $<INSTALL_INTERFACE:include>
		)


    	generate_export_header("${VAR}")
	string(TOLOWER "${VAR}" LOWER_COMPONENT)
	install(FILES "${CMAKE_CURRENT_BINARY_DIR}/${LOWER_COMPONENT}_export.h" DESTINATION "include" COMPONENT "libs")
	target_compile_features("${VAR}" PUBLIC cxx_std_20)
endforeach()

add_subdirectory("include")
add_subdirectory("src")

find_package("Math" REQUIRED)
target_link_libraries("ParticleSystem" PUBLIC Math::Math)

#Link the log target against the Core target
target_link_libraries("Log" PUBLIC "Core")

#Link the log target against the Core target
target_link_libraries("Event" PUBLIC "Core" "Log")

find_package(X11)
if(X11_FOUND)
    target_include_directories("Window" PUBLIC ${X11_INCLUDE_DIR})
    target_link_libraries("Window" PUBLIC ${X11_LIBRARIES})
    add_definitions(-DX11)
endif()

#install export file
install(FILES
        #"${CMAKE_CURRENT_BINARY_DIR}/gameutilities_export.h"
    DESTINATION
        "${CMAKE_INSTALL_PREFIX}/include"
    COMPONENT
        "libs"
)


#Generate export files for each component
foreach(VAR ${GU_LIBS})
	#create a name for our exprot file
	set(EXPORT_FILE_NAME "${PROJECT_NAME}${VAR}-Exports")
	if(NOT BUILD_SHARED_LIBS)
		set(EXPORT_FILE_NAME "${PROJECT_NAME}${VAR}Static-Exports")
	endif() 
    install(TARGETS ${VAR} DESTINATION ${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_LIBDIR} EXPORT "${EXPORT_FILE_NAME}" INCLUDES DESTINATION "include")

	#Export to the install tree
	install(EXPORT "${EXPORT_FILE_NAME}" DESTINATION "${GU_CONFIG_INSTALL_DIR}"  NAMESPACE "GU::" COMPONENT "libs")

	#Export targets to the build tree
	export(EXPORT "${EXPORT_FILE_NAME}" FILE "${GU_CONFIG_BUILD_DIR}/${EXPORT_FILE_NAME}.cmake" NAMESPACE "GU::")

	unset(EXPROT_FILE_NAME)
endforeach()

#Export package to the user package registry
export(PACKAGE "${PROJECT_NAME}")

#Include helper functions for config file
include(CMakePackageConfigHelpers)

#Create package version file
write_basic_package_version_file("${GU_CONFIG_BUILD_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
VERSION
	${${PROJECT_NAME}_VERSION}
COMPATIBILITY
	AnyNewerVersion
)

#Create package config file
configure_package_config_file("${GameUtilities_SOURCE_DIR}/cmake/${PROJECT_NAME}Config.cmake.in"
	"${GU_CONFIG_BUILD_DIR}/${PROJECT_NAME}Config.cmake"
INSTALL_DESTINATION
"${CMAKE_INSTALL_DIR}/cmake/GameUtilities"
)




install(FILES
	"${GU_CONFIG_BUILD_DIR}/${PROJECT_NAME}Config.cmake"
	"${GU_CONFIG_BUILD_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
DESTINATION
	"${GU_CONFIG_INSTALL_DIR}"
)
