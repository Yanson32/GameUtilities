# GameUtilities

    The GameUtilities library provides a basic 2d game framework.

## Features

- Basic Game Engin
- Event System
- Particle System
- Thread Pool

## Dependencies

- [SFML](https://www.sfml-dev.org/)
- [Math](https://github.com/Yanson32/Math)
- [Box2D](https://github.com/erincatto/Box2D)

## How to compile

	To build Multitheaded applications MULTITHREAD should be defined

    To build examples just set the cmake cache variable GU_BUILD_EXAMPLES to true. Remember that building the examples will add some additional dependancies to the build.

## To Do List

1. Change Events newLine default parameter from 0 to -1
2. Add Job Queue (thread pool) to the library
