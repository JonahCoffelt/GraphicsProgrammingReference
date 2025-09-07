# Graphics Programming Reference
A collection of notes for various graphics programming techniques and paradigms. This is not intended to be a guide for graphics programming or OpenGL beginners, but it will cover theory and implementation of beginner to advanced techniques. 


## Repo Contents

### OpenGL Reference
This section contains references on various topics regarding OpenGL theory and implementation. 

### Rendering Methods
...

### Examples
...


## Usage
This repo contains a number of examples. Use CMake to run these examples from source.

```bash
cd ./examples/build

cmake ..
```

This process will download all of the required dependencies to the build folder. This may take a few minutes. Once it has finished, you can build the executables. 

```bash
cmake --build .

```

This creates a seperate executable for every example. Simply run the desired example:

```bash
./example
```