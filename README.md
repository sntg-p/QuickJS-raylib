# QuickJS + raylib
[QuickJS](https://github.com/ldarren/QuickJS "QuickJS repo") is a small and embeddable Javascript engine. It can compile Javascript sources to executables with no external dependencies, and supports native modules using the QuickJS C API.
[raylib](https://github.com/raysan5/raylib "raylib repo") is a simple and easy-to-use library to enjoy videogames programming.

**QuickJS + raylib** consists in a module for QuickJS that enables you to use raylib from JavaScript and run your game with native performance.

## Disclaimer
- The idea is to make this user friendly. However, this takes time.
- This is a very early work in progress, everything is subject to changes.
- I didn't do too much testing but the default raylib example runs at about 8000-13000 fps on my PC, if not setting the target to 60 fps.
- Currently, it was only tested on my machine:
	- KDE neon 5.17
	- Intel i7-6700
	- GTX 1070
- **Currently working on the core raylib module**.

## Requirements
- Visual Studio Code (not really necessary if you read the .vscode/tasks.json and know a bit/are willing to learn about C compilers)
- raylib (download Linux binaries and copy them to `/usr/local/lib/raylib/`)
- QuickJS (instructions in repo, but I just compiled it and copied the binaries to `/usr/local/bin`)
- gcc (probably works with another C compilers)
- Patience, as this is a wip and I'm probably missing lots of things

## Installation
In Linux and with Visual Studio Code installed:
1. Install QuickJS.
1. Install raylib.
1. Clone this repo.
1. Open cloned repo in VS Code.
1. Run the `build lib` task.
1. Run the `start` task.
