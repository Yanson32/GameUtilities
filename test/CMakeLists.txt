#GIT_TAG        v3.0.1 # or a later release
include("git")
download_git_repo(Catch2 "git@github.com:catchorg/Catch2.git" devel)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR}/_deps/catch2-src/extras)

include(CTest)
include(Catch)

set(FILES ""

)
set(SUB_DIRECTORIES "GameUtilities")

#Add subdirectories
foreach(LOOP_VAR ${SUB_DIRECTORIES})
    add_subdirectory("${LOOP_VAR}")
endforeach()


#Create test runners
foreach(LOOP_VAR ${FILES})
	add_executable("${LOOP_VAR}" "${LOOP_VAR}.cpp" )
    target_link_libraries( ${LOOP_VAR} Catch2 Catch2WithMain ${GU_LIBS})
    set_property(TARGET ${LOOP_VAR} PROPERTY CXX_STANDARD 14)
    set_property(TARGET ${LOOP_VAR} PROPERTY CXX_EXTENSIONS OFF)
	set_target_properties("${LOOP_VAR}" PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}")
    catch_discover_tests("${LOOP_VAR}")
endforeach()
