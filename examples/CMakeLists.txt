#Build examples

set(GU_EXAMPLE_INCLUDES "${Boost_INCLUDE_DIRS}")
list(APPEND GU_EXAMPLE_INCLUDES "${CMAKE_CURRENT_SOURCE_DIR}/include")
list(APPEND GU_EXAMPLE_INCLUDES "${SFML_INCLUDE_DIR}")
set(GU_EXAMPLE_LIBRARIES "${Boost_LIBRARIES}")
list(APPEND GU_EXAMPLE_LIBRARIES "GameUtilities")
list(APPEND GU_EXAMPLE_LIBRARIES "${SFML_LIBRARIES}")
set(GU_EXAMPLES_PRIVATE_COMPILE_FEATURES ${GU_PRIVATE_COMPILE_FEATURES})
set(GU_EXAMPLES_PUBLIC_COMPILE_FEATURES ${GU_PUBLIC_COMPILE_FEATURES})


set(SUBDIRECTORIES "EnginExample"
		   "Particle System"
		   "Log"
		   "Core"
           "Algorithm"
           "Event"
           "Data"
           "Window"
)

foreach(LOOP_VAR ${SUBDIRECTORIES})
    add_subdirectory(${LOOP_VAR})
endforeach()
