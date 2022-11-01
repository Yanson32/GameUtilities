#Make the GU_BUILD_DOC variable show up in the cmake gui

find_package(Doxygen REQUIRED)

set(DOXYGEN_INPUT_DIR "${${PROJECT_NAME}_SOURCE_DIR}/libraries/include/ ${${PROJECT_NAME}_SOURCE_DIR}/libraries/src/ ${CMAKE_CURRENT_SOURCE_DIR}")
set(DOXYGEN_EXCLUDE "${${PROJECT_NAME}_BINARY_DIR}")
set(DOXYGEN_OUTPUT_DIR ${PROJECT_BINARY_DIR}/doc)
set(DOXYGEN_RECURSIVE true)

configure_file("${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in" "${CMAKE_CURRENT_BINARY_DIR}/Doxyfile")

add_custom_target(doc ALL
                    COMMAND ${DOXYGEN_EXECUTABLE} ${Doxyfile}
                    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
                    COMMENT "Generating API documentation with Doxygen"
                    VERBATIM)

file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/MainPage.h" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")

