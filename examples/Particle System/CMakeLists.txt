set(SUBDIRECTORIES "Particle Example 1"
)

foreach(LOOP_VAR ${SUBDIRECTORIES})
    add_subdirectory(${LOOP_VAR})
endforeach()
