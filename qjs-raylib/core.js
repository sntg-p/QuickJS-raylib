// @ts-nocheck
import * as rl from './qjs-raylib.so';

// Window-related functions

export const initWindow = rl.initWindow;
export const windowShouldClose = rl.windowShouldClose;
export const closeWindow = rl.closeWindow;
export const isWindowReady = rl.isWindowReady;
export const setWindowIcon = rl.setWindowIcon;
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
export const beginMode2D = rl.beginMode2D;
export const endMode2D = rl.endMode2D;
export const beginMode3D = rl.beginMode3D;
export const endMode3D = rl.endMode3D;
export const beginTextureMode = rl.beginTextureMode;
export const endTextureMode = rl.endTextureMode;

// Screen-space-related functions
export const getMouseRay = rl.getMouseRay;
export const getWorldToScreen = rl.getWorldToScreen;
export const getCameraMatrix = rl.getCameraMatrix;

// Timing-related functions
export const setTargetFps = rl.setTargetFps;
export const getFps = rl.getFps;
export const getFrameTime = rl.getFrameTime;
export const getTime = rl.getTime;

// Color-related functions
export const colorToInt = rl.colorToInt;
export const colorNormalize = rl.colorNormalize;
export const colorToHSV = rl.colorToHSV;
export const colorFromHSV = rl.colorFromHSV;
export const getColor = rl.getColor;
export const fade = rl.fade;

// Misc. functions
export const setConfigFlags = rl.setConfigFlags;
export const setTraceLogLevel = rl.setTraceLogLevel;
export const setTraceLogExit = rl.setTraceLogExit;
export const takeScreenshot = rl.takeScreenshot;
export const getRandomValue = rl.getRandomValue;
export const openURL = rl.openURL;

// Files management functions
export const fileExists = rl.fileExists;
export const isFileExtension = rl.isFileExtension;
export const getExtension = rl.getExtension;
export const getFileName = rl.getFileName;
export const getFileNameWithoutExt = rl.getFileNameWithoutExt;
export const getDirectoryPath = rl.getDirectoryPath;
export const getWorkingDirectory = rl.getWorkingDirectory;
export const getDirectoryFiles = rl.getDirectoryFiles;
export const changeDirectory = rl.changeDirectory;
export const isFileDropped = rl.isFileDropped;
export const getDroppedFiles = rl.getDroppedFiles;
export const getFileModTime = rl.getFileModTime;

// Persistent storage management
export const storageSaveValue = rl.storageSaveValue;
export const storageLoadValue = rl.storageLoadValue;

// Input handling functions
export const isKeyPressed = rl.isKeyPressed;
export const isKeyDown = rl.isKeyDown;
export const isKeyReleased = rl.isKeyReleased;
export const isKeyUp = rl.isKeyUp;
export const getKeyPressed = rl.getKeyPressed;
export const setExitKey = rl.setExitKey;

// Input-related functions: gamepads

// asd
export const drawText = rl.drawText;
export const drawFps = rl.drawFps;

export const loadImage = rl.loadImage;
export const getImageWidth = rl.getImageWidth;
export const getImageHeight = rl.getImageHeight;