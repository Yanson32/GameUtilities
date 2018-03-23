set(FILES
"${CMAKE_CURRENT_SOURCE_DIR}/Engin.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/GameState.cpp"

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
"Engin_Default_Constructors"
"Engin_Move_Constructor"
"Engin_Move_Assignment_operator"
"Engin_Push"
"Engin_Pop"
"Engin_ChangeState"
"Engin_IsRunning"
"Engin_Quit"
"Engin_HandleEvents"
"Engin_Update"
"Engin_Draw"
"Engin_Stack_Methods"
)

add_boost_test("Engin" "${ENGIN_TESTS}")


set(GAMESTATE_TESTS
"GameState_Constructors"
"GameState_HandleEvents"
"GameState_Update"
"GameState_Draw"
)
add_boost_test("GameState" "${GAMESTATE_TESTS}")

