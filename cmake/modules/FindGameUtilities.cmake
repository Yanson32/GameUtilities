#cmake defined variables
#${PROJECT_NAME}_FIND_REQUIRED 	        true if required REQUIRED option was set
#${PROJECT_NAME}_FIND_QUIETLY 		    true if the quiet option was set
#${PROJECT_NAME}_FIND_VERSION 		    full requested version string
#${PROJECT_NAME}_FIND_VERSION_MAJOR 	major version
#${PROJECT_NAME}_FIND_VERSION_MINOR 	minor version
#${PROJECT_NAME}_FIND_VERSION_PATCH 	patch version
#${PROJECT_NAME}_FIND_VERSION_TWEAK 	tweek version
#${PROJECT_NAME}_FIND_VERSION_COUNT 	the number of version counts
#${PROJECT_NAME}_FIND_VERSION_EXACT 	True if exact option was given
#${PROJECT_NAME}_FIND_COMPONENTS 	    requested components
#${PROJECT_NAME}_FIND_REQUIRED_<c> 	    true if component <c> is required, false if component <c> is optional


#The user can define a variable ${${PACKAGE_NAME}_UPPER}_ROOT which points to the
#directory where the library is installed
#Defined variable


set(PACKAGE_NAME "GameUtilities")
string(TOUPPER ${PACKAGE_NAME} ${PACKAGE_NAME}_UPPER)


#These Variables will be defined by this module
set(${${PACKAGE_NAME}_UPPER}_FOUND TRUE)        		#True if all components of the library were found.
set(${${PACKAGE_NAME}_UPPER}_DYNAMIC_RELEASE_FOUND TRUE)
set(${${PACKAGE_NAME}_UPPER}_DYNAMIC_DEBUG_FOUND TRUE)
set(${${PACKAGE_NAME}_UPPER}_STATIC_RELEASE_FOUND TRUE)
set(${${PACKAGE_NAME}_UPPER}_STATIC_DEBUG_FOUND TRUE)
set(${${PACKAGE_NAME}_UPPER}_INCLUDE_DIR "")    		#Include directory for the library.
set(${${PACKAGE_NAME}_UPPER}_LIBRARIES "")      		#Library directory path.
set(${${PACKAGE_NAME}_UPPER}_DYNAMIC_RELEASE_LIBRARIES "")
set(${${PACKAGE_NAME}_UPPER}_DYNAMIC_DEBUG_LIBRARIES "")
set(${${PACKAGE_NAME}_UPPER}_STATIC_RELEASE_LIBRARIES "")
set(${${PACKAGE_NAME}_UPPER}_STATIC_DEBUG_LIBRARIES "")
set(${${PACKAGE_NAME}_UPPER}_VERSION_OK TRUE)



#List of paths to check
set(${${PACKAGE_NAME}_UPPER}_PATHS
    $${${PACKAGE_NAME}_UPPER}_ROOT}
    $ENV{${${PACKAGE_NAME}_UPPER}_ROOT}}
    ~/Library/Frameworks
    /Library/Frameworks
    /usr/local
    /usr
    /sw
    /opt/local
    /opt/csw
    /opt)


# find the include directory
find_path(${${PACKAGE_NAME}_UPPER}_INCLUDE_DIR
          NAMES
          ${PACKAGE_NAME}/Config.h
          ${PACKAGE_NAME}/Config.hpp
          PATHS
          ${${PACKAGE_NAME}_UPPER}_PATHS}
          PATH_SUFFIXES
          include
          ${PACKAGE_NAME}/include
          )



if(${PACKAGE_NAME}_FIND_VERSION AND ${${PACKAGE_NAME}_UPPER}_INCLUDE_DIR)

    set(${${PACKAGE_NAME}_UPPER}_CONFIG_HPP_INPUT "${${PACKAGE_NAME}_UPPER}_INCLUDE_DIR/Config.h")
    FILE(READ "${${${PACKAGE_NAME}_UPPER}_CONFIG_HPP_INPUT}" ${${PACKAGE_NAME}_UPPER}_CONFIG_HPP_CONTENTS)
    STRING(REGEX REPLACE ".*const unsigned      VERSION_MAJOR = ([0-9]+).*" "\\1" ${${PACKAGE_NAME}_UPPER}_VERSION_MAJOR "${${${PACKAGE_NAME}_UPPER}_CONFIG_HPP_CONTENTS}")
    STRING(REGEX REPLACE ".*const unsigned      VERSION_MINOR = ([0-9]+).*" "\\1" ${${PACKAGE_NAME}_UPPER}_VERSION_MINOR "${${${PACKAGE_NAME}_UPPER}_CONFIG_HPP_CONTENTS}")
    STRING(REGEX REPLACE ".*const unsigned      VERSION_PATCH = ([0-9]+).*" "\\1" ${${PACKAGE_NAME}_UPPER}_VERSION_PATCH "${${${PACKAGE_NAME}_UPPER}_CONFIG_HPP_CONTENTS}")
    STRING(REGEX REPLACE ".*const unsigned      VERSION_TWEAK = ([0-9]+).*" "\\1" ${${PACKAGE_NAME}_UPPER}_VERSION_TWEAK "${${${PACKAGE_NAME}_UPPER}_CONFIG_HPP_CONTENTS}")


    set(${${PACKAGE_NAME}_UPPER}_FULL_VERSION "${${${PACKAGE_NAME}_UPPER}_VERSION_MAJOR}.${${${PACKAGE_NAME}_UPPER}_VERSION_MINOR}.${${${PACKAGE_NAME}_UPPER}_VERSION_PATCH}.${${${PACKAGE_NAME}_UPPER}_VERSION_TWEAK}")


    #True if the available version and the requested version are not the same
    if(NOT "${${PACKAGE_NAME}_UPPER}_FULL_VERSION" STREQUAL "${${PACKAGE_NAME}_UPPER}_FIND_VERSION}")

        #True if the EXACT option was passed to the find_package command
        if(${PACKAGE_NAME}_FIND_VERSION_EXACT)

            #True if the QUIET option has not been passed to find_package
            if(NOT ${PACKAGE_NAME}_FIND_QUIETLY)
                message(FATAL_ERROR "${PACKAGE_NAME} version ${${PACKAGE_NAME}_UPPER}_FULL_VERSION does not match requested version ${${PACKAGE_NAME}_FIND_VERSION}")
            endif()
            set(${${PACKAGE_NAME}_UPPER}_VERSION_OK FALSE)
        endif()

        #If the version MAJOR parts are not the same then library versions are not compatible
        if(NOT ${${${PACKAGE_NAME}_UPPER}_VERSION_MAJOR} MATCHES ${${PACKAGE_NAME}_FIND_VERSION_MAJOR})
            set(${${PACKAGE_NAME}_UPPER}_VERSION_OK FALSE)
        endif()
    endif()
endif()


if(NOT ${${PACKAGE_NAME}_UPPER}_VERSION_OK)
    set(${${PACKAGE_NAME}_UPPER}_FOUND FALSE)
endif()


	#Find the release version of the library
    find_library(${${PACKAGE_NAME}_UPPER}_RELEASE_LIBRARIES
                 NAMES
				 ${PACKAGE_NAME}.a
				 lib${PACKAGE_NAME}.a
                 ${PACKAGE_NAME}.dll.a
                 lib${PACKAGE_NAME}.dll.a
                 ${PACKAGE_NAME}.lib
                 lib${PACKAGE_NAME}.lib
                 PATH_SUFFIXES
                 lib
                 ${PACKAGE_NAME}/lib
                 PATHS ${${PACKAGE_NAME}_UPPER}_PATHS)


	#Find the Debug version of the library
    find_library(${${PACKAGE_NAME}_UPPER}_DEBUG_LIBRARIES
                 NAMES
				 ${PACKAGE_NAME}-d.a
				 lib${PACKAGE_NAME}-d.a
                 ${PACKAGE_NAME}-d.dll.a
                 lib${PACKAGE_NAME}-d.dll.a
                 ${PACKAGE_NAME}-d.lib
                 lib${PACKAGE_NAME}-d.lib
                 PATH_SUFFIXES
                 lib
                 ${PACKAGE_NAME}/lib
                 PATHS ${${PACKAGE_NAME}_UPPER}_PATHS)


	#Find the Static Release version of the library
    find_library(${${PACKAGE_NAME}_UPPER}_STATIC_RELEASE_LIBRARIES
                 NAMES
				 ${PACKAGE_NAME}-s.a
				 lib${PACKAGE_NAME}-s.a
                 ${PACKAGE_NAME}-s.dll.a
                 lib${PACKAGE_NAME}-s.dll.a
                 ${PACKAGE_NAME}-s.lib
                 lib${PACKAGE_NAME}-s.lib
                 PATH_SUFFIXES
                 lib
                 ${PACKAGE_NAME}/lib
                 PATHS ${${PACKAGE_NAME}_UPPER}_PATHS)


	#Find the Static Release version of the library
    find_library(${${PACKAGE_NAME}_UPPER}_STATIC_DEBUG_LIBRARIES
                 NAMES
				 ${PACKAGE_NAME}-s-d.a
				 lib${PACKAGE_NAME}-s-d.a
                 ${PACKAGE_NAME}-s-d.dll.a
                 lib${PACKAGE_NAME}-s-d.dll.a
                 ${PACKAGE_NAME}-s-d.lib
                 lib${PACKAGE_NAME}-s-d.lib
                 PATH_SUFFIXES
                 lib
                 ${PACKAGE_NAME}/lib
                 PATHS ${${PACKAGE_NAME}_UPPER}_PATHS)


    if(${PACKAGE_NAME}_FIND_REQUIRED)
        if("${${${PACKAGE_NAME}_UPPER}_LIBRARIES}" STREQUAL "")
            if(NOT ${PACKAGE_NAME}_FIND_QUIETLY )
                message(FATAL_ERROR "Unable to find library")
        endif()
    endif()
endif()

#include(FindPackageHandleStandardArgs.cmake)
#FIND_PACKAGE_HANDLE_STANDARD_ARGS(${PACKAGE_NAME} ${PACKAGE_NAME_UPPER}_LIBRARIES ${PACKAGE_NAME_UPPER}_INCLUDE_DIR)


unset(${${PACKAGE_NAME}_UPPER}_PATHS)
unset(PACKAGE_NAME)
unset(${PACKAGE_NAME}_UPPER)
