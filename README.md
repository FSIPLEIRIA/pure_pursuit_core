# T24e Pure Pursuit Core Library

This is the core library of the pure pursuit core library. A ROS wrapper is under development, which may be
what you are looking for.

It receives a path and a configured speed. A point iterates the track at a constant speed,
announcing waypoints on the way.

## Requirements

- [lart_common](https://github.com/FSIPLEIRIA/lart_common.git)
- gtest (I know it is a pain in the ass to require gtest, still working on that fix)

## Build

- Create a subdirectory `lib` if not present. Clone [gtest](https://github.com/google/googletest) inside that directory.
- Create a `cmake-build-debug` subdirectory and navigate there.
- Run the command `cmake ..`.
- Run the command `make`.
- Run the command `sudo make install` to install the library on the system.
