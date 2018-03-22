#for backwards compatibility
cmake_minimum_required(VERSION 3.5.1)

#Compile Features
set(GU_PRIVATE_COMPILE_FEATURES "cxx_nullptr" "cxx_right_angle_brackets")
set(GU_PUBLIC_COMPILE_FEATURES "")

#Give the project a name
project("GameUtilities" VERSION "0.0.0.0")
string(TOUPPER ${PROJECT_NAME} PROJECT_NAME_UPPER)

include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/Modules/Depricated.cmake")
#Build shared library by default
option(BUILD_SHARED_LIBS "True for shared libraries" TRUE)

#Create our target
add_library("${PROJECT_NAME}" "")

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
	target_compile_definitions("${PROJECT_NAME}" PRIVATE "GameUtilities_EXPORTS")
endif()

install(FILES
	"${CMAKE_CURRENT_BINARY_DIR}/gameutilities_export.h"
	DESTINATION
	"${CMAKE_INSTALL_PREFIX}/include")



#Install Source Files
install(TARGETS "${PROJECT_NAME}" DESTINATION ${CMAKE_INSTALL_PREFIX}/lib EXPORT "${PROJECT_NAME}-Exports")
install(EXPORT "${PROJECT_NAME}-Exports" DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/${PROJECT_NAME}")

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
	
	include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/Modules/BoostTestHelpers.cmake")

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
option(GAMEUTILITIES_BUILD_DOC "Set to TRUE if you want to build library documentation" FALSE)
if(GAMEUTILITIES_BUILD_DOC)
	add_subdirectory("doc")
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
