

#find_package(SFML COMPONENTS system window graphics REQUIRED CONFIG)
add_executable("WindowExample" "WindowExample.cpp" )
target_link_libraries("WindowExample" PRIVATE Window)

