add_executable("SATExample" "Main.cpp")
target_link_libraries("SATExample" PUBLIC Core Algorithm)
target_link_libraries("SATExample" PRIVATE sfml-system sfml-window sfml-graphics)

