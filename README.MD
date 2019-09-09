# GameUtilities

    The GameUtilities library provides a basic 2d game framework.

## Features

1. Basic Game Engin
2. Event System
3. Particle System

## Dependencies

1. SFML
2. Math
3. Box2D

## How to compile

	To build Multitheaded applications MULTITHREAD should be defined

    To build examples just set the cmake cache variable GU_BUILD_EXAMPLES to true. Remember that building the examples will add some additional dependancies to the build.

## To Do List

1. Change Events newLine default parameter from 0 to -1
2. Add Job Queue (thread pool) to the library
