# GameUtilities {#mainpage}
    The GameUtilities toolkit provides some commonly used data structures, and algorithms to make building your game faster, and esier.
The goal of the GameUtiliites toolkit is to provide infrastructure for making 2d games, while having verry few dependancies. 

## Features
- Basic Game Engin
- Event System
- Particle System
- Thread Pool
- Loging System
- Algorithms
- Data Structures
- Resource Manager

## Documentation can be found here
[GameUtilities](https://yanson32.github.io/GameUtilities/)

## Supported operating systems
- Ubuntu
- Arch Linux 
- Windows

## Dependencies
- [Math](https://github.com/Yanson32/Math)
- [Linux - xlib](https://www.x.org/releases/current/doc/libX11/libX11/libX11.html)

## Optional Dependencies
- [SFML](https://www.sfml-dev.org/)

## How to compile
	To build Multitheaded applications MULTITHREAD should be defined

    To build examples just set the cmake cache variable GU_BUILD_EXAMPLES to true. Remember that building the examples will add some additional dependancies to the build.
