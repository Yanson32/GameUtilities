

find_package(SFML COMPONENTS sfml-system sfml-window sfml-graphics)
add_executable("EnginExample" "Main.cpp" "EnginExampleState.cpp")
target_link_libraries("EnginExample" PRIVATE Engin sfml-system sfml-window sfml-graphics)

