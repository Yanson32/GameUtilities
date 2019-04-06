find_package(SFML COMPONENTS system window graphics REQUIRED CONFIG)
add_executable("Particle1" "Main.cpp")
target_link_libraries("Particle1" PRIVATE "ParticleSystem")
target_link_libraries("Particle1" PRIVATE Engin sfml-system sfml-window sfml-graphics)
