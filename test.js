import { Color } from './qjs-raylib/qjs-raylib.so';
import * as rlCore from './qjs-raylib/core.js';
import * as rlTextures from './qjs-raylib/textures.js';
import { ConfigFlag } from './qjs-raylib/enums.js'

const screenWidth = 800;
const screenHeight = 450;

rlCore.initWindow(screenWidth, screenHeight, 'raylib [core] example - basic window');

rlCore.setTargetFps(60); // fps go between 8000 and 12000 if not set
rlCore.setConfigFlags(ConfigFlag.FLAG_MSAA_4X_HINT || ConfigFlag.FLAG_FULLSCREEN_MODE);

let textY = 200;
let textSize = 20;

let image = rlTextures.loadImage('grass_colored.png');
rlCore.setWindowIcon(image);

const bg = new Color(255, 128, 64);
const fg = Color(255, 255, 255, 192);

while (!rlCore.windowShouldClose()) {
	rlCore.beginDrawing();

	rlCore.clearBackground(bg);
	rlCore.drawFps(2, 0);
	rlCore.drawText("Welcome to QuickJS+raylib!", 264, textY, textSize, fg);
	
	textY++;
	
	if (textY > screenHeight)
		textY = -textSize;

	rlCore.endDrawing();
}

rlCore.closeWindow();