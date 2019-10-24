import { ConfigFlag, TraceLogType, KeyboardKey, GamepadButton, MouseButton } from './enums.js'
import { Camera2D, Camera3D, RenderTexture, Vector2, Vector3, Matrix, Color, Vector4 } from './native/qjs-raylib.so';

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
/** Open URL with default system browser (if available) */
export function openURL(url: string): void;

// Files management related functions
export function fileExists(fileName: string): boolean;
export function isFileExtension(fileName: string, ext: string): boolean;
export function getExtension(fileName: string): string;
export function getFileName(filePath: string): string;
export function getFileNameWithoutExt(fileName: string): string;
export function getDirectoryPath(fileName: string): string;
export function getWorkingDirectory(): string;
export function getDirectoryFiles(dirPath: string): string[];
export function changeDirectory(dir: string): boolean;
export function isFileDropped(): boolean;
export function getDroppedFiles(): string[];
export function getFileModTime(fileName: string): number;

// Persistent storage management
export function storageSaveValue(position: number, value: number): void;
export function storageLoadValue(position: number): number;

// Input-related functions: keyboard
export function isKeyPressed(key: KeyboardKey): boolean;
export function isKeyDown(key: KeyboardKey): boolean;
export function isKeyReleased(key: KeyboardKey): boolean;
export function isKeyUp(key: KeyboardKey): boolean;
export function getKeyPressed(): KeyboardKey;
export function setExitKey(key: KeyboardKey): void;

// Input-related functions: gamepads
export function isGamepadAvailable(gamepad: number): boolean;
export function isGamepadName(gamepad: number, name: string): boolean;
export function getGamepadName(gamepad: number): void;
export function isGamepadButtonPressed(gamepad: number, button: GamepadButton): boolean;
export function isGamepadButtonDown(gamepad: number, button: GamepadButton): boolean;
export function isGamepadButtonReleased(gamepad: number, button: GamepadButton): boolean;
export function isGamepadButtonUp(gamepad: number, button: GamepadButton): boolean;
export function getGamepadButtonPressed(): boolean;
export function getGamepadAxisCount(gamepad: number): number;
export function getGamepadAxisMovement(gamepad: number, axis: number): number;

// Input-related functions: mouse
export function isMouseButtonPressed(button: MouseButton): boolean;
export function isMouseButtonDown(button: MouseButton): boolean;
export function IsMouseButtonReleased(button: MouseButton): boolean;
export function isMouseButtonUp(button: MouseButton): boolean;
export function getMouseX(): number;
export function getMouseY(): number;
export function getMousePosition(): Vector2;
export function setMousePosition(x: number, y: number): void;
export function setMouseOffset(x: number, y: number): void;
export function setMouseScale(x: number, y: number): void;
export function getMouseWheelMove(): number;

// Input-related functions: touch
export function getTouchX(): number;
export function getTouchY(): number;
export function getTouchPosition(index: number): Vector2;

// Gestures and Touch Handling Functions
export function setGesturesEnabled(flags: number): void;
export function isGestureDetected(gesture: number): boolean;
export function getGestureDetected(): number;
export function getTouchPointsCount(): number;
export function getGestureHoldDuration(): number;
export function getGestureDragVector(): Vector2;
export function getGestureDragAngle(): number;
export function getGesturePinchVector(): Vector2;
export function getGesturePinchAngle(): number;

// Camera System Functions
export function setCameraMode(camera: Camera3D, mode: number): void;
export function updateCamera(camera: Camera3D): void;
export function setCameraPanControl(panKey: number): void;
export function setCameraAltControl(altKey: number): void;
export function setCameraSmoothZoomControl(szKey: number): void;
export function setCameraMoveControls(frontKey: number, backKey: number, rightKey: number, leftKey: number, upKey: number, downKey: number): void;

// asd
export function loadImage(fileName: string): number;
export function getImageWidth(pointer: number): number;
export function getImageHeight(pointer: number): number;