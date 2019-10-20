import { ConfigFlag, TraceLogType } from './enums.js'
import { Camera2D, Camera3D, RenderTexture, Vector2, Vector3, Matrix, Color, Vector4 } from './qjs-raylib.so.js';

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
 * Set background color (framebuffer clear color)
 * @param color A color object or an integer in 0xRRGGBBAA form.
 */
export function clearBackground(color: Color | number): void;
/** Setup canvas (framebuffer) to start drawing */
export function beginDrawing(): void;
/** End canvas drawing and swap buffers (double buffering) */
export function endDrawing(): void;
/** Initialize 2D mode with custom camera (2D) */
export function beginMode2D(camera: Camera2D): void;
/** Ends 2D mode with custom camera */
export function endMode2D(): void;
/** Initializes 3D mode with custom camera (3D) */
export function beginMode3D(camera: Camera3D): void;
/** Ends 3D mode and returns to default 2D orthographic mode */
export function endMode3D(): void;
/** Initializes render texture for drawing */
export function beginTextureMode(target: RenderTexture): void;
/** Ends drawing to render texture */
export function endTextureMode(): void;

// Screen-space-related functions
/** Returns a ray trace from mouse position */
export function getMouseRay(mousePosition: Vector2, camera: Camera2D): Ray;
/** Returns the screen space position for a 3d world space position */
export function getWorldToScreen(position: Vector3, camera: Camera2D): Vector2;
/** Returns camera transform matrix (view matrix) */
export function getCameraMatrix(camera: Camera2D): Matrix;

// Timing-related functions
/** Set target FPS (maximum) */
export function setTargetFps(fps: number): void;
/** Returns current FPS */
export function getFps(): number;
/** Returns time in seconds for last frame drawn */
export function getFrameTime(): number;
/** Returns elapsed time in seconds since InitWindow() */
export function getTime(): number;

// Color-related functions
/** Returns hexadecimal value for a Color */
export function colorToInt(color: Color): number;
/** Returns color normalized as float [0..1] */
export function colorNormalize(color: Color): Vector4;
/** Returns HSV values for a Color */
export function colorToHSV(color: Color): Vector3;
/** Returns a Color from HSV values */
export function colorFromHSV(hsv: Vector3): Color;
/** Returns a Color struct from hexadecimal value */
export function getColor(value: number): Color;
/** Color fade-in or fade-out, alpha goes from 0.0f to 1.0f */
export function fade(color: Color, alpha: number): Color;

// Misc. functions
/**
 * Setup window configuration flags
 * @param flags Use the OR bitwise operator to combine various flags
 * @example setConfigFlags(ConfigFlag.FLAG_MSAA_4X_HINT || ConfigFlag.FLAG_WINDOW_RESIZABLE)
 */
export function setConfigFlags(flags: ConfigFlag): void;
/** Set the current threshold (minimum) log level */
export function setTraceLogLevel(logType: TraceLogType): void;
/** Set the exit threshold (minimum) log level */
export function setTraceLogExit(logType: TraceLogType): void;
/** Takes a screenshot of current screen (saved as .png) */
export function takeScreenshot(fileName: string): void;
/** Returns a random value between min and max (both included) */
export function getRandomValue(min: number, max: number): int;

// Files management related functions
export function fileExists(fileName: string): bool;
export function isFileExtension(fileName: string, ext: string): bool;
export function getExtension(fileName: string): string;
export function getFileName(filePath: string): string;
export function getFileNameWithoutExt(fileName: string): string;
export function getDirectoryPath(fileName: string): string;
export function getWorkingDirectory(): string;
export function getDirectoryFiles(dirPath: string): string[];
export function changeDirectory(dir: string): bool;
export function isFileDropped(): bool;
export function getDroppedFiles(): string[];
export function getFileModTime(fileName: string): number;

// Text drawing functions
export function drawText(text: string, x: number, y: number, size: number, color: Color | number): void;
export function drawFps(x: number, y: number): void;

export function loadImage(fileName: string): number;
export function getImageWidth(pointer: number): number;
export function getImageHeight(pointer: number): number;