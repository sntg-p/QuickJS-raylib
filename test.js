import * as rl from './qjs-raylib/qjs-raylib.so';
import * as rlCore from './qjs-raylib/core.js';
import * as rlTextures from './qjs-raylib/textures.js';

const screenWidth = 800;
const screenHeight = 450;

rlCore.initWindow(screenWidth, screenHeight, 'raylib [core] example - basic window');

rlCore.setTargetFps(60); // fps go between 8000 and 12000 if not set

let textY = 200;
let textSize = 20;

let image = rlTextures.loadImage('grass_colored.png');
rlCore.setWindowIcon(image);

let asd = new rl.Vector2(44, 33);
console.log(`${asd.x} ${asd.y}`)

while (!rlCore.windowShouldClose()) {
	rlCore.beginDrawing();
	//rlCore.beginDrawing();

	rlCore.drawFps(0,0);
	
	rlCore.clearBackground(0xFFFFFFFF);
	rlCore.drawText("Congrats! You created your first window!", 190, textY, textSize, 0xC8C8C8FF);
	textY++;
	if (textY > screenHeight) textY = -textSize;

	rlCore.endDrawing();
}

rlCore.closeWindow();