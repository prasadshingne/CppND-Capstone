# C++ ND Final Project: Two person Pong Game

This is an implementation of the Pong game. The following resources provided inspiration and guidance for the implementation.

* [https://github.com/BassLC/Pong/blob/master/pong.cpp](https://github.com/BassLC/Pong/blob/master/pong.cpp)
* [https://github.com/gameprogcpp/code/blob/master/Chapter01/Game.cpp](https://github.com/gameprogcpp/code/blob/master/Chapter01/Game.cpp)
* [https://www.youtube.com/watch?v=DeKfZhwyFO4](https://www.youtube.com/watch?v=DeKfZhwyFO4)

<img src="pong.gif"/>

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source. 
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./Pong`.


## Play Instructions

This is a two player implementation of the Pong game. As seen in the GIF above Player 1 is to the left and Player 2 is to the right. Player 1 can move up and down respectively using "W" and "S" keys while Player 2 can move up and down respectively using "UP" and "DOWN" keys. You can also change some of the game specs readily by changing the following parameters in the [/src/sim_config.txt](https://github.com/prasadshingne/CppND-Capstone/blob/master/src/sim_config.txt) file.

Default parameter values - 

* window width=1000 // play window width in pixels
* window height=750 // play window height in pixels
* line thickness=20 // line thickness in pixels
* player height=120 // player 1 and 2 height in pixels
* simulation runtime=60 // game run time in seconds
* ball X velocity=-200.0f // ball velocity in x direction in pixels per second
* ball Y velocity=200.0f // ball velocity in y directio in pixels per second

More game parameters can be changed in - 

* Ball and player motion - [/src/pSim.cpp](https://github.com/prasadshingne/CppND-Capstone/blob/master/src/pSim.cpp)
* Background and goal specification - [/src/pRenderer.cpp](https://github.com/prasadshingne/CppND-Capstone/blob/master/src/pRenderer.cpp)

## File Structure

The source code is in the [/src](https://github.com/prasadshingne/CppND-Capstone/tree/master/src) folder.

* main.cpp - the driver file that initiates and runs the interactive simulation/game.
* pBall.h and pBall.cpp - the decleration and definition of the "Ball" which derives from pMovers class.
* pConfig.h and pConfig.cpp - reads and sets up the game based on parameters from sim_config.txt.
* pMove.h and pMove.cpp - reads the input from the keyboard.
* pMovers.h and pMovers.cpp - declares and defines the abstract class pMovers from which all "Movers", such as "Player" and "Ball", in the game are derived.
* pRenderer.h and pRenderer.cpp - this renders the background, walls, goals, players and the ball using the SDL2 library.
* pSim.h and pSim.cpp - contains code for the mechanisms on the game itself such as setting up, running and updating.
* sim_config.txt - contains game parameters described in the section above which are read at every startup/execution of the game.

## Rubric Points

### README (All Rubric Points REQUIRED)

- [x] A README with instructions is included with the project.
- [x] The README describes the project you have built.
- [x] The README includes information about each rubric point addressed - see below.

### Compiling and Testing (All Rubric Points REQUIRED)

- [x] The submission must compile and run.

### Loops, Function, I/O

- [x] The project demonstrates an understanding of C++ functions and control structures - All of the source code in /src use control structures and functions. [pSim.cpp](https://github.com/prasadshingne/CppND-Capstone/blob/master/src/pSim.cpp) contains the most number of control structures and functions.
- [x] The project reads data from a file and process the data, or the program writes data to a file - game parameters are read from file sim_config.txt within file [pConfig.cpp](https://github.com/prasadshingne/CppND-Capstone/blob/master/src/pConfig.cpp).
- [x] The project accepts user input and processes the input - pSim.cpp uses [pMove.cpp](https://github.com/prasadshingne/CppND-Capstone/blob/master/src/pMove.cpp) to read input from the keyboard and processes it to update the location of the players, at [line 120](https://github.com/prasadshingne/CppND-Capstone/blob/da7ab4f28ed1517ecdb8e8b27fc31f621c62a839/src/pSim.cpp#L120) and [line 136](https://github.com/prasadshingne/CppND-Capstone/blob/da7ab4f28ed1517ecdb8e8b27fc31f621c62a839/src/pSim.cpp#L136).

### Object Oriented Programming

- [x] The project uses Object Oriented Programming techniques. The project code is organized into classes with appropriate attributes and methods, namely in pBall.cpp, pMove.cpp, pMovers.cpp, pPlayer.cpp, pRenderer.cpp and pSim.cpp.
- [x] Classes use appropriate access specifiers for class members. All the classes in the previous point use appropriate access specifiers. Example - pMovers.cpp defines protected and public members and defines functions to access these.
- [x] Class constructors utilize member initialization lists. Class pPlayer and pBall use member initialization lists.
- [x] Classes encapsulate behavior. Classes pBall, pPlayer and pSim have appropriate data and functions grouped together. Class states are accessed via member functions.
- [x] Overloaded functions allow the same function to operate on different parameters. pMovers, pBall and pPlayer classes have overloaded constructors.

### Memory Management

- [x] The project makes use of references in function declarations. Pass-by-reference at [line 3](https://github.com/prasadshingne/CppND-Capstone/blob/da7ab4f28ed1517ecdb8e8b27fc31f621c62a839/src/pMove.cpp#L3) in pMove.cpp and [line 37](https://github.com/prasadshingne/CppND-Capstone/blob/da7ab4f28ed1517ecdb8e8b27fc31f621c62a839/src/pSim.cpp#L37) in pSim.cpp.
- [x] The project uses destructors appropriately. Class pRender uses desctructor as defined on [line 32](https://github.com/prasadshingne/CppND-Capstone/blob/da7ab4f28ed1517ecdb8e8b27fc31f621c62a839/src/pRenderer.cpp#L32) in pRenderer.cpp.