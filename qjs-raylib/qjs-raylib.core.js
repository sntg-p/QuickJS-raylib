// @ts-ignore
import * as rl from './qjs-raylib.so';
import * as rlTextures from './qjs-raylib.textures.js';

// Window-related functions
export const initWindow = rl.initWindow;
export const windowShouldClose = rl.windowShouldClose;
export const closeWindow = rl.closeWindow;
export const isWindowReady = rl.isWindowReady;

/**
 * @param {rlTextures.Image} image
 */
export function setWindowIcon(image)
{
	rl.setWindowIconImpl(image.pointer);
}

export const setWindowIconImpl = rl.setWindowIconImpl;

export const setWindowTitle = rl.setWindowTitle;
export const setWindowPosition = rl.setWindowPosition;
export const setWindowMonitor = rl.setWindowMonitor;
export const setWindowMinSize = rl.setWindowMinSize;
export const setWindowSize = rl.setWindowSize;
export const getScreenWidth = rl.getScreenWidth;
export const getScreenHeight = rl.getScreenHeight;
export const getMonitorCount = rl.getMonitorCount;
export const getMonitorWidth = rl.getMonitorWidth;
export const getMonitorHeight = rl.getMonitorHeight;
export const getMonitorPhysicalWidth = rl.getMonitorPhysicalWidth;
export const getMonitorPhysicalHeight = rl.getMonitorPhysicalHeight;
export const getMonitorName = rl.getMonitorName;
export const getClipboardText = rl.getClipboardText;
export const setClipboardText = rl.setClipboardText;

// Cursor-related functions
export const showCursor = rl.showCursor;
export const hideCursor = rl.hideCursor;
export const isCursorHidden = rl.isCursorHidden;
export const enableHidden = rl.enableHidden;
export const disableHidden = rl.disableHidden;

// Drawing-related functions
export const clearBackground = rl.clearBackground;
export const beginDrawing = rl.beginDrawing;
export const endDrawing = rl.endDrawing;

// Screen-space-related functions

// Timing-related functions
export const setTargetFps = rl.setTargetFps;

export const drawText = rl.drawText;
export const drawFps = rl.drawFps;

export const loadImage = rl.loadImage;
export const getImageWidth = rl.getImageWidth;
export const getImageHeight = rl.getImageHeight;