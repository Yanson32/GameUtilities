

find_package(SFML COMPONENTS system window graphics REQUIRED CONFIG)
add_executable("EnginExample" "Main.cpp" "EnginExampleState.cpp" "ExampleFrame.cpp")
target_link_libraries("EnginExample" PRIVATE Engin sfml-system sfml-window sfml-graphics)

