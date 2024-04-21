# Game of Life
## Project Description
This project is an implementation of Conway's Game of Life.

## Setup
### Dependencies
On a Debian system you can install the needed dependencies using:
```shell
sudo apt install g++ cmake make libsdl2-dev -y
```

### Clone Repository
```shell
git clone https://github.com/llikian/Game-Of-Life.git
cd Game-Of-Life
```

### Build
To build you can simply run the `build.sh` script at the root of the project using:
```shell
bash build.sh
```

You can also manually build it using:
```shell
cmake -B build && \
cmake --build build -j
```

Then you can run it using:
```shell
bin/GameOfLife
```

## Credits
The rendering is done using [SDL2](https://www.libsdl.org/).