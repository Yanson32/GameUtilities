add_executable("QuadTreeExample" "QuadTreeExample.cpp")
target_link_libraries("QuadTreeExample" PUBLIC Data)
target_link_libraries("QuadTreeExample" PRIVATE sfml-system sfml-window sfml-graphics)


set(SUBDIRECTORIES ""
)

foreach(LOOP_VAR ${SUBDIRECTORIES})
    add_subdirectory(${LOOP_VAR})
endforeach()
