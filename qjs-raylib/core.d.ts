import * as rlTextures from './textures.js';
import { Camera2D, Camera3D, RenderTexture, Vector2, Vector3, Matrix, Color } from './qjs-raylib.so.js';

// Window-related functions
export function initWindow(width: number, height: number, title: string);
export function windowShouldClose(): boolean;
export function closeWindow();
export function isWindowReady(): boolean;
export function setWindowIcon(image: rlTextures.Image): void;
export function setWindowIconImpl(image: number): void;
export function setWindowTitle(title: string): void;
export function setWindowPosition(x: number, y: number): void;
export function setWindowMonitor(monitor: number): void;
export function setWindowMinSize(w: number, h: number): void;
export function setWindowSize(w: number, h: number): void;
export function getScreenWidth(): number;
export function getScreenHeight(): number;
export function getMonitorCount(): number;
export function getMonitorWidth(monitor: number): number;
export function getMonitorHeight(monitor: number): number;
export function getMonitorPhysicalWidth(monitor: number): number;
export function getMonitorPhysicalHeight(monitor: number): number;
export function getMonitorName(monitor: number): string;
export function getClipboardText(): string;
export function setClipboardText(text: string): void;

// Cursor-related functions
export function showCursor(): void;
export function hideCursor(): void;
export function isCursorHidden(): bool;
export function enableHidden(): void;
export function disableHidden(): void;

// Drawing-related functions
/**
 * Clears the background with the color passed as a parameter
 * @param color A color object or an integer in 0xRRGGBBAA form.
 */
export function clearBackground(color: Color | number): void;
export function beginDrawing(): void;
export function endDrawing(): void;
export function beginMode2D(camera: Camera2D): void;
export function endMode2D(): void;
export function beginMode3D(camera: Camera3D): void;
export function endMode3D(): void;
export function beginTextureMode(target: RenderTexture): void;
export function endTextureMode(): void;

// Screen-space-related functions
export function getMouseRay(mousePosition: Vector2, camera: Camera2D): Ray;
export function getWorldToScreen(position: Vector3, camera: Camera2D): Vector2;
export function getCameraMatrix(camera: Camera2D): Matrix;

// Timing-related functions
export function setTargetFps(fps: number): void;
export function getFps(): number;
export function getFrameTime(): number;
export function getTime(): number;

// Color-related functions
export function colorToInt(color: Color);
export function colorNormalize(color: Color);
export function colorToHSV(color: Color);
export function colorFromHSV(hsv: Vector3);
export function getColor(value: number);
export function fade(color: Color, alpha: number);

//
export function drawText(text: string, x: number, y: number, size: number, colorInt: number): void;
export function drawFps(x: number, y: number): void;

export function loadImage(fileName: string): number;
export function getImageWidth(pointer: number): number;
export function getImageHeight(pointer: number): number;