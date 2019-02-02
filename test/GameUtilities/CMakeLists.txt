set(FILES ""

)

set(SUB_DIRECTORIES "EnginTests")

#Add subdirectories
foreach(LOOP_VAR ${SUB_DIRECTORIES})
    add_subdirectory("${LOOP_VAR}")
endforeach()

#Create tests
foreach(LOOP_VAR ${FILES})
	boost_test_add(${LOOP_VAR} "${TEST_SOURCES}" "${TEST_LIBRARIES}" "${TEST_PRIVATE_COMPILE_FEATURES}")
endforeach()
