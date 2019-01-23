#for backwards compatibility
cmake_minimum_required(VERSION 3.5.1)

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

#determine if we are using a multi config generator
set(IS_MULTI_CONFIG_GENERATOR False)
if(CMAKE_CONFIGURATION_TYPES)
	set(IS_MULTI_CONFIG_GENERATOR True)
	
	#cmake version 3.9 or higher
	#get_property(IS_MULTI_CONFIG_GENERATOR GLOBAL PROPERTY GENERATOR_IS_MULTI_CONFIG)
endif()

#set default build type
if(NOT IS_MULTI_CONFIG_GENERATOR)
	if(CMAKE_BUILD_TYPE STREQUAL "")
		set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Select build type [${VALID_BUILD_TYPES}]" FORCE)
	endif()
endif()

#set dropdown list in cmake gui
if(NOT IS_MULTI_CONFIG_GENERATOR)
	set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS ${VALID_BUILD_TYPES})
endif()

#Make sure the build type is valid
if(NOT IS_MULTI_CONFIG_GENERATOR)
	list(FIND VALID_BUILD_TYPES "${CMAKE_BUILD_TYPE}" INDEX)
	if(${INDEX} MATCHES -1)
		message(FATAL_ERROR "Invalid build type <${CMAKE_BUILD_TYPE}>. Valid types are [${VALID_BUILD_TYPES}]")
	endif()
endif()

#Give the project a name
project("GameUtilities" VERSION "0.0.0.0")
string(TOUPPER ${PROJECT_NAME} PROJECT_NAME_UPPER)
string(TOLOWER ${PROJECT_NAME} PROJECT_NAME_LOWER)

include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules/Depricated.cmake")
#Build shared library by default
option(BUILD_SHARED_LIBS "True for shared libraries" TRUE)

#Create our target
add_library("${PROJECT_NAME}" "")
add_library(GU::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

#add subdirectories
add_subdirectory("include")
add_subdirectory("src")


#Change the library output path
set_target_properties( "${PROJECT_NAME}"
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY lib
    LIBRARY_OUTPUT_DIRECTORY lib
    RUNTIME_OUTPUT_DIRECTORY bin
)

#Define compiler features
target_compile_features("${PROJECT_NAME}"
			PRIVATE
				${GU_PRIVATE_COMPILE_FEATURES}
			PUBLIC
				${GU_PUBLIC_COMPILE_FEATURES}
			)

#Add includes to target
target_include_directories("${PROJECT_NAME}" PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
  $<INSTALL_INTERFACE:include>
	)




#Create export header for GameUtilities
include(GenerateExportHeader)
generate_export_header("${PROJECT_NAME}")

if(WIN32)
	target_compile_definitions("${PROJECT_NAME}" PRIVATE "${PROJECT_NAME}_EXPORTS")
endif()

#install export file
install(FILES
	"${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME_LOWER}_export.h"
	DESTINATION
	"${CMAKE_INSTALL_PREFIX}/include")



#Install Source Files
install(TARGETS "${PROJECT_NAME}" DESTINATION ${CMAKE_INSTALL_PREFIX}/lib EXPORT "${PROJECT_NAME}-Exports" INCLUDES DESTINATION "include")
install(EXPORT "${PROJECT_NAME}-Exports" DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/${PROJECT_NAME}"  NAMESPACE GU)

include(CMakePackageConfigHelpers)

#Create package version file
write_basic_package_version_file(	"${CMAKE_CURRENT_BINARY_DIR}/lib/cmake/${PROJECT_NAME}/${PROJECT_NAME}ConfigVersion.cmake"
  									VERSION
										${${PROJECT_NAME}_VERSION}
  									COMPATIBILITY
										AnyNewerVersion
)

#Create package config file

configure_package_config_file(	"${CMAKE_CURRENT_SOURCE_DIR}/cmake/${PROJECT_NAME}Config.cmake.in"
								"${CMAKE_CURRENT_BINARY_DIR}/lib/cmake/${PROJECT_NAME}/${PROJECT_NAME}Config.cmake"
                              	INSTALL_DESTINATION
									lib/cmake/${PROJECT_NAME}
)




install(
	FILES
	"${CMAKE_CURRENT_BINARY_DIR}/lib/cmake/${PROJECT_NAME}/${PROJECT_NAME}Config.cmake"
	"${CMAKE_CURRENT_BINARY_DIR}/lib/cmake/${PROJECT_NAME}/${PROJECT_NAME}ConfigVersion.cmake"
    DESTINATION
	"${CMAKE_INSTALL_PREFIX}/lib/cmake/${PROJECT_NAME}"
)


#Export package to the user package registry
export(PACKAGE "${PROJECT_NAME}")

#Export targets to the build tree
export(TARGETS "${PROJECT_NAME}" FILE "${CMAKE_CURRENT_BINARY_DIR}/lib/cmake/${PROJECT_NAME}/${PROJECT_NAME}-Exports.cmake")


#Make the BUILD_TESTING variable show up in the cmake gui
option(BUILD_TESTING "Set to TRUE if you want to build unit tests" FALSE)

if(BUILD_TESTING)

	include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules/BoostTestHelpers.cmake")

	#Find boost
	find_package(Boost 1.60.0 COMPONENTS system unit_test_framework REQUIRED)

	include(CTest)

	set(TEST_INCLUDES "${Boost_INCLUDE_DIRS}")
	list(APPEND TEST_INCLUDES "${CMAKE_CURRENT_SOURCE_DIR}/include")
	set(TEST_LIBRARIES "${Boost_LIBRARIES}")
	list(APPEND TEST_LIBRARIES "GameUtilities")
	set(TEST_PRIVATE_COMPILE_FEATURES ${GU_PRIVATE_COMPILE_FEATURES})

	add_subdirectory("test")
	add_definitions("-DBUILD_TESTING")
endif()


#Make the BUILD_TESTING variable show up in the cmake gui
option(GU_BUILD_DOC "Set to TRUE if you want to build library documentation" FALSE)
if(GU_BUILD_DOC)
	add_subdirectory("doc")
endif()


#Build examples
option(GU_BUILD_EXAMPLES "Set to TRUE if you want to build examples" FALSE)
if(GU_BUILD_EXAMPLES)
    set(GU_EXAMPLE_INCLUDES "${Boost_INCLUDE_DIRS}")
	list(APPEND GU_EXAMPLE_INCLUDES "${CMAKE_CURRENT_SOURCE_DIR}/include")
	list(APPEND GU_EXAMPLE_INCLUDES "${SFML_INCLUDE_DIR}")
	set(GU_EXAMPLE_LIBRARIES "${Boost_LIBRARIES}")
	list(APPEND GU_EXAMPLE_LIBRARIES "GameUtilities")
	list(APPEND GU_EXAMPLE_LIBRARIES "${SFML_LIBRARIES}")
	set(GU_EXAMPLES_PRIVATE_COMPILE_FEATURES ${GU_PRIVATE_COMPILE_FEATURES})
	set(GU_EXAMPLES_PUBLIC_COMPILE_FEATURES ${GU_PUBLIC_COMPILE_FEATURES})

    add_subdirectory("examples")
endif()

include(InstallRequiredSystemLibraries)
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "This library contains code for making 2d video games")
set(CPACK_PACKAGE_DESCRIPTION_FILE "${CMAKE_CURRENT_SOURCE_DIR}/README.md")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/COPYING.txt")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "${PROJECT_NAME}_${${PROJECT_NAME}_VERSION_MAJOR}_${${PROJECT_NAME}_VERSION_MINOR}_${${PROJECT_NAME}_VERSION_PATCH}")
set(CPACK_PACKAGE_VERSION_MAJOR "${${PROJECT_NAME}_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${${PROJECT_NAME}_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${${PROJECT_NAME}_VERSION_PATCH}")
include(CPack)
