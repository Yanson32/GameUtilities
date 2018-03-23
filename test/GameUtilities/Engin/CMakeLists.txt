set(FILES "${CMAKE_CURRENT_SOURCE_DIR}/Engin.cpp"

)

set(SUB_DIRECTORIES "")

#Add subdirectories
foreach(LOOP_VAR ${SUB_DIRECTORIES})
    add_subdirectory("${LOOP_VAR}")
endforeach()


#Create test runners
foreach(LOOP_VAR ${FILES})
	boost_test_runner(${LOOP_VAR} "${TEST_SOURCES}" "${TEST_LIBRARIES}" "${TEST_PRIVATE_COMPILE_FEATURES}" "${TEST_PUBLIC_COMPILE_FEATURES}")
endforeach()


set(ENGIN_TESTS 
"Engin_Constructors"
"Engin_Push"
"Engin_Stack_Methods"
)

add_boost_test("Engin" "${ENGIN_TESTS}")



