import { Color, Vector2, Vector3 } from './qjs-raylib/native/qjs-raylib.so';
import * as rlCore from './qjs-raylib/core.js';
import * as rlTextures from './qjs-raylib/textures.js';
import * as rlShapes from './qjs-raylib/shapes.js';
import * as rlText from './qjs-raylib/text.js';
import { ConfigFlag } from './qjs-raylib/enums.js'

const screenWidth = 800;
const screenHeight = 450;

rlCore.setConfigFlags(ConfigFlag.FLAG_WINDOW_RESIZABLE || ConfigFlag.FLAG_MSAA_4X_HINT);
rlCore.initWindow(screenWidth, screenHeight, 'raylib [core] example - basic window');

rlCore.setTargetFps(60); // fps go between 8000 and 12000 if not set

let textY = 200;
let textSize = 20;

const bg = new Color(255, 128, 64);
const fg = Color(255, 255, 255, 192);

let prevX, prevY, currX, currY, hue = 0;

// const darken = Color(0, 0, 0, 4);
const darken = Color(0, 0, 0, 128);

rlCore.beginDrawing();
rlCore.clearBackground(Color(0,0,0));
rlCore.endDrawing();

let textX = 0;

const msg = "Welcome to QuickJS+raylib!";

while (!rlCore.windowShouldClose()) {
	currX = rlCore.getMouseX();
	currY = rlCore.getMouseY();

	rlCore.beginDrawing();

	//rlCore.clearBackground(bg);
	//rlCore.drawFps(2, 0);

	let color = rlCore.colorFromHSV(Vector3(hue, 1, 1))
	hue += rlCore.getFrameTime() * 60;
	if (hue > 360)
		hue = 0;

	rlShapes.drawRectangle(0, 0, rlCore.getScreenWidth(), rlCore.getScreenHeight(), darken);
	rlShapes.drawLineEx(Vector2(prevX, prevY), Vector2(currX, currY), 32, color);
	rlShapes.drawCircle(currX, currY, 16, color);

	textX = rlCore.getScreenWidth() / 2 - 272 / 2;

	rlText.drawText(msg, textX, textY - 3, textSize, color);
	rlText.drawText(msg, textX, textY - 2, textSize, darken);
	rlText.drawText(msg, textX + 2, textY, textSize, darken);
	rlText.drawText(msg, textX - 2, textY, textSize, darken);
	rlText.drawText(msg, textX, textY, textSize, fg);
	
	textY += rlCore.getFrameTime() * 60;
	
	if (textY > rlCore.getScreenHeight())
		textY = -textSize;

	prevX = currX;
	prevY = currY;

	rlCore.endDrawing();
}

rlCore.closeWindow();