add_executable("Test" "Main.cpp")

target_link_libraries("Test" "${PROJECT_NAME}")

#Define compiler features
target_compile_features("Test" 
			PRIVATE 
			cxx_nullptr
			cxx_right_angle_brackets
			)

add_test("Test" "Test")
