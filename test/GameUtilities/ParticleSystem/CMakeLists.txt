
add_executable("ParticleSytemContainerTest" "ParticleSytemContainerTest.cpp" )
set_target_properties("ParticleSytemContainerTest" PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}")
target_link_libraries("ParticleSytemContainerTest" PRIVATE ParticleSystem Catch2::Catch2)
catch_discover_tests("ParticleSytemContainerTest")




