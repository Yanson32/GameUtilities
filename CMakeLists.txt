#for backwards compatibility
cmake_minimum_required(VERSION 3.9.0)

option(GU_BUILD_EXAMPLES "Set to TRUE if you want to build examples" FALSE)
option(GU_BUILD_DOC "Set to TRUE if you want to build library documentation" FALSE)
option(GU_BUILD_TESTING "Set to TRUE if you want to build unit tests" FALSE)

#custom variables
set(GU_VALID_BUILD_TYPES "Release" "Debug" "MinSizeRel" "RelWithDebInfo")
set(GU_LIBS "Core" "Window" "Event" "ParticleSystem" "Engin" "ThreadPool" "Log" "Data" "Algorithm")

#set custom module path
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules" CACHE PATH "All cmake modules can be found in this path")

#set cpack variables
include ("CPackConfig")

#Give the project a name
project("GameUtilities" VERSION "0.0.0.0")

include ("GNUInstallDirs")

#set output directory for binaries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin" CACHE PATH "Runtime output directory")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR}" CACHE PATH "Archive ouput directory")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR}" CACHE PATH "Library output directory")

#Set cmake version
set(CMAKE_CXX_STANDARD 11)

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
    add_subdirectory("extlibs")
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

# uninstall target
if(NOT TARGET uninstall)
  configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/cmake_uninstall.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
    IMMEDIATE @ONLY)

  add_custom_target(uninstall
    COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake)
endif()

#Install man pages on unix systems
if(UNIX)
    install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/man/" DESTINATION "${CMAKE_INSTALL_FULL_MANDIR}/")
endif()

include(CPack)
