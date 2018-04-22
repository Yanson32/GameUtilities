cmake_minimum_required(VERSION 3.1.0)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules/")

project("Box2DExample")

add_executable("${PROJECT_NAME}" Main.cpp)

add_subdirectory("include")
add_subdirectory("src")

#Define compiler features
target_compile_features("${PROJECT_NAME}"
			PRIVATE
				${GU_EXAMPLES_PRIVATE_COMPILE_FEATURES}
			PUBLIC
				${GU_EXAMPLES_PUBLIC_COMPILE_FEATURES}
			)

#Add includes to target
target_include_directories("${PROJECT_NAME}"
	PUBLIC
  		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  		$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
  		$<INSTALL_INTERFACE:include>
		)

find_package(GameUtilities REQUIRED)
target_link_libraries("${PROJECT_NAME}" PRIVATE GameUtilities)


find_package(SFML 2 COMPONENTS system window graphics audio network REQUIRED)
target_include_directories("${PROJECT_NAME}" PUBLIC ${SFML_INCLUDE_DIR})
target_link_libraries("${PROJECT_NAME}" PUBLIC ${SFML_LIBRARIES})


find_package(Box2D REQUIRED)
target_include_directories("${PROJECT_NAME}" PUBLIC ${BOX2D_INCLUDE_DIRS})
target_link_libraries("${PROJECT_NAME}" PUBLIC ${BOX2D_LIBRARIES})


file(COPY "Resources" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
