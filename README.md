# QuickJS + raylib
[QuickJS](https://github.com/ldarren/QuickJS "QuickJS repo") is a small and embeddable Javascript engine. It can compile Javascript sources to executables with no external dependencies, and supports native modules using the QuickJS C API.
[raylib](https://github.com/raysan5/raylib "raylib repo") is a simple and easy-to-use library to enjoy videogames programming.

**QuickJS + raylib** consists in a module for QuickJS that enables you to use raylib from JavaScript and run your game with native performance.

## Progress
- [ ] Exposing functionality
	- [x] Core module
	- [x] Shapes module
	- [ ] Textures module
		- [x] Image/Texture2D data loading/unloading/saving functions
		- [ ] Image manipulation functions
		- [ ] Image generation functions
		- [ ] Texture2D configuration functions
		- [ ] Texture2D drawing functions
	- [ ] Text module
		- [x] Font loading/unloading functions
		- [ ] Text drawing functions
			- [x] drawText() and drawFPS()
			- [ ] Everything else
		- [ ] Text misc. functions
		- [ ] Text strings management functions
	- [ ] Models module
	- [ ] Shaders module
	- [ ] Audio module
	- [ ] Structs
		- [x] Vectors, Quaternion, Matrix and Color
		- [x] Image, Texture and RenderTexture
		- [x] Camera2D, Camera3D, Ray
		- [x] CharInfo, Font
		- [ ] Everything else
- [ ] Testing
	- [ ] Core module
		- Some testing has been made
	- [ ] Shapes module
		- Some testing has been made
	- [ ] Textures module
		- Very little testing has been made
	- [ ] Text module
		- Very little testing has been made
	- [ ] Models module
	- [ ] Shaders module
	- [ ] Audio module

## Disclaimer
- You are free and encouraged to make pull requests!
- The idea is to make this user friendly. However, this takes time and I'm learning a lot of things on the fly (mostly about QuickJS internals).
- This is a very early work in progress, everything is subject to changes. Even if I'm trying to replicate the original raylib functions exactly so you could just use the [raylib cheatsheet](https://www.raylib.com/cheatsheet/cheatsheet.html) to make whatever you want, there are still missing modules (as seen above).
- I didn't do too much testing but the default raylib example runs at about 8000-13000 fps on my desktop PC, if not setting the target to 60 fps.
- Currently, it was only tested on my machines:
	- Desktop
		- KDE neon 5.17
		- Intel i7-6700
		- GTX 1070
	- Laptop
		- KDE neon 5.16
		- Intel i5-6200U

## Requirements
- [Visual Studio Code](https://code.visualstudio.com/Download)
	- It is **HIGHLY RECOMMENDED** because of the integration with TypeScript (all functions and objects will have its own types, even when programming with JavaScript)
	- It is not really necessary to compile the project if you are able to read and understand the `.vscode/tasks.json`, and if you know or are willing to learn about C compilers/linkers.
- [raylib](https://github.com/raysan5/raylib/releases/tag/2.5.0) (download Linux binaries and copy them to `/usr/local/lib/`, copy header files to `/usr/local/include/raylib`)
- [QuickJS](https://github.com/ldarren/QuickJS) (compile and copy the binaries to `/usr/local/bin` and the libraries to `/usr/local/lib/quickjs`)
- gcc (this is if you are using the default `.vscode/tasks.json`, but you could probably make it work with any C compiler)
- Patience, as this is a wip and I'm probably missing lots of things

## Installation
In Linux and with Visual Studio Code installed:
1. Install QuickJS.
2. Install raylib.
3. Clone this repo.
4. Open cloned repo in VS Code.
5. Press `Ctrl+P` to invoke the command palette.
6. Type `task build lib` and press enter.
7. Repeat 5.
6. Type `task start` and press enter.
