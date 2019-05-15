set(TARGET_NAME "Engin")

project("${TARGET_NAME}")

add_library("${TARGET_NAME}" "")

#set targets output name
set_target_properties("${TARGET_NAME}" PROPERTIES
					DEBUG_POSTFIX "${STATIC_NAME_POSTFIX}-d"
					RELWITHDEBINFO_POSTFIX "${STATIC_NAME_POSTFIX}-d"
					RELEASE_POSTFIX "${STATIC_NAME_POSTFIX}"
                    MINSIZEREL_POSTFIX "${STATIC_NAME_POSTFIX}"

)

target_include_directories(${TARGET_NAME} PUBLIC
	"$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>"
	"$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>"
	"$<INSTALL_INTERFACE:include>"
)

include(GenerateExportHeader)
generate_export_header("${TARGET_NAME}")

#install export file
install(FILES
        "${CMAKE_CURRENT_BINARY_DIR}/engin_export.h"
    DESTINATION
        "${CMAKE_INSTALL_PREFIX}/include"
    COMPONENT
        "libs"
)
set_property(TARGET "${TARGET_NAME}" PROPERTY CXX_STANDARD 11)

add_subdirectory("include")
add_subdirectory("src")

install(TARGETS ${TARGET_NAME} DESTINATION ${CMAKE_INSTALL_PREFIX}/lib EXPORT "${TARGET_NAME}-Exports" INCLUDES DESTINATION "include" )

#Export targets to the build tree
export(EXPORT "${TARGET_NAME}-Exports" FILE "${GU_CONFIG_BUILD_DIR}/${TARGET_NAME}-Exports.cmake"  NAMESPACE "GU::")


#Export to the install tree
install(EXPORT "${TARGET_NAME}-Exports" DESTINATION "${GU_CONFIG_INSTALL_DIR}" NAMESPACE "GU::" COMPONENT "libs")

