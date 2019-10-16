import * as rlTextures from './qjs-raylib.textures';

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
export function clearBackground(colorInt: number): void;
export function beginDrawing(): void;
export function endDrawing(): void;

// Screen-space-related functions

// Timing-related functions
export function setTargetFps(fps: number): void;

export function drawText(text: string, x: number, y: number, size: number, colorInt: number): void;
export function drawFps(x: number, y: number): void;

export function loadImage(fileName: string): number;
export function getImageWidth(pointer: number): number;
export function getImageHeight(pointer: number): number;