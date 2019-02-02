#for backwards compatibility
cmake_minimum_required(VERSION 3.5.1)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules")
set(CMAKE_ARCHIVE_OUPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/bin")
set(VALID_BUILD_TYPES "Release" "Debug" "MinSizeRel" "RelWithDebInfo")
option(BUILD_SHARED_LIBS "True when building shared libraries" True)
set(GU_LIBS "GameUtilities" "Event" "Engin")

#Give the project a name
project("GameUtilities" VERSION "0.0.0.0")

#determine if we are using a multi config generator
set(IS_MULTI_CONFIG_GENERATOR False)
if(CMAKE_CONFIGURATION_TYPES)
	set(IS_MULTI_CONFIG_GENERATOR True)
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


#create libraries
add_subdirectory("src")

#add unit tests
add_subdirectory("test")

#create documentation
add_subdirectory("doc")

#create examples
add_subdirectory("examples")

include(InstallRequiredSystemLibraries)
set(CPACK_COMPONENTS_ALL "GameUtilities" "libs")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "This library contains code for making 2d video games")
set(CPACK_PACKAGE_DESCRIPTION_FILE "${CMAKE_CURRENT_SOURCE_DIR}/README.md")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/COPYING.txt")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "${PROJECT_NAME}_${${PROJECT_NAME}_VERSION_MAJOR}_${${PROJECT_NAME}_VERSION_MINOR}_${${PROJECT_NAME}_VERSION_PATCH}")
set(CPACK_PACKAGE_VERSION_MAJOR "${${PROJECT_NAME}_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${${PROJECT_NAME}_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${${PROJECT_NAME}_VERSION_PATCH}")
include(CPack)
