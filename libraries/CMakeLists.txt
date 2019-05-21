#Compile Features
set(GU_PRIVATE_COMPILE_FEATURES
"cxx_range_for"
"cxx_right_angle_brackets"
"cxx_auto_type"
)
set(GU_PUBLIC_COMPILE_FEATURES
"cxx_nullptr"
"cxx_defaulted_functions"
"cxx_deleted_functions"
"cxx_final"
"cxx_noexcept"
"cxx_override"
)

set(GU_CONFIG_BUILD_DIR "${GameUtilities_BINARY_DIR}/lib/cmake/${PROJECT_NAME}")
set(GU_CONFIG_INSTALL_DIR "${CMAKE_INSTALL_PREFIX}/lib/cmake/${PROJECT_NAME}")

#Build shared library by default
option(BUILD_SHARED_LIBS "True when building shared libraries" True)

#create a postfix for static libraries
if(NOT BUILD_SHARED_LIBS)
	set(STATIC_NAME_POSTFIX "-s")
endif()

add_subdirectory("Engin")

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

	set_property(TARGET "${VAR}" PROPERTY CXX_STANDARD 11)
endforeach()

add_subdirectory("include")
add_subdirectory("src")
target_link_libraries("ParticleSystem" PUBLIC "Math")

#install export file
install(FILES
        #"${CMAKE_CURRENT_BINARY_DIR}/gameutilities_export.h"
    DESTINATION
        "${CMAKE_INSTALL_PREFIX}/include"
    COMPONENT
        "libs"
)

#Define compiler features
target_compile_features("Core"
			PRIVATE
				${GU_PRIVATE_COMPILE_FEATURES}
			PUBLIC
				${GU_PUBLIC_COMPILE_FEATURES}
			)

target_compile_features("Event"
			PRIVATE
				${GU_PRIVATE_COMPILE_FEATURES}
			PUBLIC
				${GU_PUBLIC_COMPILE_FEATURES}
			)

#Define compiler features
target_compile_features("Engin"
			PRIVATE
				${GU_PRIVATE_COMPILE_FEATURES}
			PUBLIC
				${GU_PUBLIC_COMPILE_FEATURES}
			)


install(TARGETS ${GU_LIBS} DESTINATION ${CMAKE_INSTALL_PREFIX}/lib EXPORT "${PROJECT_NAME}-Exports" INCLUDES DESTINATION "include")

#Export to the install tree
install(EXPORT "${PROJECT_NAME}-Exports" DESTINATION "${GU_CONFIG_INSTALL_DIR}"  NAMESPACE "GU::" COMPONENT "libs")

#Export targets to the build tree
export(EXPORT "${PROJECT_NAME}-Exports" FILE "${GU_CONFIG_BUILD_DIR}/${PROJECT_NAME}-Exports.cmake" NAMESPACE "GU::")

#Export package to the user package registry
export(PACKAGE "${PROJECT_NAME}")

include(CMakePackageConfigHelpers)

#Create package version file
write_basic_package_version_file(	"${GU_CONFIG_BUILD_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
  									VERSION
										${${PROJECT_NAME}_VERSION}
  									COMPATIBILITY
										AnyNewerVersion
)

#Create package config file
configure_package_config_file(	"${GameUtilities_SOURCE_DIR}/cmake/${PROJECT_NAME}Config.cmake.in"
								"${GU_CONFIG_BUILD_DIR}/${PROJECT_NAME}Config.cmake"
                              	INSTALL_DESTINATION
									"lib/cmake/GameUtilities"
)




install(
	FILES
		"${GU_CONFIG_BUILD_DIR}/${PROJECT_NAME}Config.cmake"
		"${GU_CONFIG_BUILD_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
    DESTINATION
		"${GU_CONFIG_INSTALL_DIR}"
)
