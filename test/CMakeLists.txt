include("BoostTestHelpers")

#Find boost
find_package(Boost 1.60.0 COMPONENTS system unit_test_framework REQUIRED)

include(CTest)

set(TEST_INCLUDES "${Boost_INCLUDE_DIRS}")
list(APPEND TEST_INCLUDES "${CMAKE_CURRENT_SOURCE_DIR}/include")
set(TEST_LIBRARIES "${Boost_LIBRARIES}")
list(APPEND TEST_LIBRARIES "GameUtilities")
set(TEST_PRIVATE_COMPILE_FEATURES ${GU_PRIVATE_COMPILE_FEATURES})

add_definitions("-DBUILD_TESTING")


set(FILES ""

)

set(SUB_DIRECTORIES "GameUtilities")

#Add subdirectories
foreach(LOOP_VAR ${SUB_DIRECTORIES})
    add_subdirectory("${LOOP_VAR}")
endforeach()

#Create tests
foreach(LOOP_VAR ${FILES})
    boost_test_add(${LOOP_VAR} "${TEST_SOURCES}" "${TEST_LIBRARIES}" "${TEST_PRIVATE_COMPILE_FEATURES}")
endforeach()
