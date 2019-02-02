#Make the GU_BUILD_DOC variable show up in the cmake gui
option(GU_BUILD_DOC "Set to TRUE if you want to build library documentation" FALSE)
if(GU_BUILD_DOC)
	find_package(Doxygen REQUIRED)

	set(DOXYGEN_INPUT_DIR "${${PROJECT_NAME}_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/MainPage.h")
	set(DOXYGEN_OUTPUT_DIR ${PROJECT_BINARY_DIR}/doc)
	set(DOXYGEN_RECURSIVE true)

	configure_file("${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in" "${CMAKE_CURRENT_BINARY_DIR}/Doxyfile")

	add_custom_target(doc ALL
		              COMMAND ${DOXYGEN_EXECUTABLE} ${Doxyfile}
		              WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
		              COMMENT "Generating API documentation with Doxygen"
		              VERBATIM)

	file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/MainPage.h" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
endif()
