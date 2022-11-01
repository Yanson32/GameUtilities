#Make the GU_BUILD_DOC variable show up in the cmake gui

find_package(Doxygen REQUIRED)

set(DOXYGEN_INCLUDE_DIR "${${PROJECT_NAME}_SOURCE_DIR}/libraries/include/")
set(DOXYGEN_SRC_DIR "${${PROJECT_NAME}_SOURCE_DIR}/libraries/src/")
set(DOXYGEN_MAINPAGE "${${PROJECT_NAME}_SOURCE_DIR}/README.MD")
set(DOXYGEN_INPUT_DIR "${DOXYGEN_INCLUDE_DIR} ${DOXYGEN_SRC_DIR} ${DOXYGEN_MAINPAGE}")
set(DOXYGEN_EXCLUDE "${${PROJECT_NAME}_BINARY_DIR}")
set(DOXYGEN_OUTPUT_DIR ${PROJECT_BINARY_DIR}/doc)
set(DOXYGEN_RECURSIVE true)
set(DOXYGEN_USE_MDFILE_AS_MAINPAGE true)

configure_file("${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in" "${CMAKE_CURRENT_BINARY_DIR}/Doxyfile")

add_custom_target(doc ALL
                    COMMAND ${DOXYGEN_EXECUTABLE} ${Doxyfile}
                    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
                    COMMENT "Generating API documentation with Doxygen"
                    VERBATIM)


