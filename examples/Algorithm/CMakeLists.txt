
set(SUBDIRECTORIES "SAT"
)

foreach(LOOP_VAR ${SUBDIRECTORIES})
    add_subdirectory(${LOOP_VAR})
endforeach()
