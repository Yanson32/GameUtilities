#for backwards compatibility
cmake_minimum_required(VERSION 3.5.1)

#set output directory for binaries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

option(GU_BUILD_EXAMPLES "Set to TRUE if you want to build examples" FALSE)
option(GU_BUILD_DOC "Set to TRUE if you want to build library documentation" FALSE)
option(GU_BUILD_TESTING "Set to TRUE if you want to build unit tests" FALSE)

#custom variables
set(GU_VALID_BUILD_TYPES "Release" "Debug" "MinSizeRel" "RelWithDebInfo")
set(GU_LIBS "Core" "Event" "ParticleSystem" "Engin" "ThreadPool")

#set custom module path
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules")

#set cpack variables
set(CPACK_COMPONENTS_ALL "${GU_LIBS}")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "This library contains code for making 2d video games")
set(CPACK_RESOURCE_FILE_README "${CMAKE_CURRENT_SOURCE_DIR}/README.MD")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/COPYING.txt")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "${PROJECT_NAME}_${${PROJECT_NAME}_VERSION_MAJOR}_${${PROJECT_NAME}_VERSION_MINOR}_${${PROJECT_NAME}_VERSION_PATCH}")
set(CPACK_PACKAGE_VERSION_MAJOR "${${PROJECT_NAME}_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${${PROJECT_NAME}_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${${PROJECT_NAME}_VERSION_PATCH}")

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
		set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Select build type [${GU_VALID_BUILD_TYPES}]" FORCE)
	endif()
endif()

#set dropdown list in cmake gui
if(NOT IS_MULTI_CONFIG_GENERATOR)
	set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS ${GU_VALID_BUILD_TYPES})
endif()

#Make sure the build type is valid
if(NOT IS_MULTI_CONFIG_GENERATOR)
	list(FIND GU_VALID_BUILD_TYPES "${CMAKE_BUILD_TYPE}" INDEX)
	if(${INDEX} MATCHES -1)
		message(FATAL_ERROR "Invalid build type <${CMAKE_BUILD_TYPE}>. Valid types are [${GU_VALID_BUILD_TYPES}]")
	endif()
endif()


#create libraries
add_subdirectory("libraries")

#add unit tests
if(GU_BUILD_TESTING)
    add_subdirectory("test")
endif()

#create documentation
if(GU_BUILD_DOC)
    add_subdirectory("doc")
endif()

#create examples
if(GU_BUILD_EXAMPLES)
    add_subdirectory("examples")
endif()

include(CPack)
