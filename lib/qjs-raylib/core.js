// @ts-nocheck
import * as rl from './native/qjs-raylib.so';

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

// Input-related functions: keyboard
export const isKeyPressed = rl.isKeyPressed;
export const isKeyDown = rl.isKeyDown;
export const isKeyReleased = rl.isKeyReleased;
export const isKeyUp = rl.isKeyUp;
export const getKeyPressed = rl.getKeyPressed;
export const setExitKey = rl.setExitKey;

// Input-related functions: gamepads
export const isGamepadAvailable = rl.isGamepadAvailable;
export const isGamepadName = rl.isGamepadName;
export const getGamepadName = rl.getGamepadName;
export const isGamepadButtonPressed = rl.isGamepadButtonPressed;
export const isGamepadButtonDown = rl.isGamepadButtonDown;
export const isGamepadButtonReleased = rl.isGamepadButtonReleased;
export const isGamepadButtonUp = rl.isGamepadButtonUp;
export const getGamepadButtonPressed = rl.getGamepadButtonPressed;
export const getGamepadAxisCount = rl.getGamepadAxisCount;
export const getGamepadAxisMovement = rl.getGamepadAxisMovement;

// Input-related functions: mouse
export const isMouseButtonPressed = rl.isMouseButtonPressed;
export const isMouseButtonDown = rl.isMouseButtonDown;
export const IsMouseButtonReleased = rl.IsMouseButtonReleased;
export const isMouseButtonUp = rl.isMouseButtonUp;
export const getMouseX = rl.getMouseX;
export const getMouseY = rl.getMouseY;
export const getMousePosition = rl.getMousePosition;
export const setMousePosition = rl.setMousePosition;
export const setMouseOffset = rl.setMouseOffset;
export const setMouseScale = rl.setMouseScale;
export const getMouseWheelMove = rl.getMouseWheelMove;

// Input-related functions: touch
export const getTouchX = rl.getTouchX;
export const getTouchY = rl.getTouchY;
export const getTouchPosition = rl.getTouchPosition;

// Gestures and Touch Handling Functions
export const setGesturesEnabled = rl.setGesturesEnabled;
export const isGestureDetected = rl.isGestureDetected;
export const getGestureDetected = rl.getGestureDetected;
export const getTouchPointsCount = rl.getTouchPointsCount;
export const getGestureHoldDuration = rl.getGestureHoldDuration;
export const getGestureDragVector = rl.getGestureDragVector;
export const getGestureDragAngle = rl.getGestureDragAngle;
export const getGesturePinchVector = rl.getGesturePinchVector;
export const getGesturePinchAngle = rl.getGesturePinchAngle;

// Camera System Functions
export const setCameraMode = rl.setCameraMode;
export const updateCamera = rl.updateCamera;
export const setCameraPanControl = rl.setCameraPanControl;
export const setCameraAltControl = rl.setCameraAltControl;
export const setCameraSmoothZoomControl = rl.setCameraSmoothZoomControl;
export const setCameraMoveControls = rl.setCameraMoveControls;

// asd
export const loadImage = rl.loadImage;
export const getImageWidth = rl.getImageWidth;
export const getImageHeight = rl.getImageHeight;