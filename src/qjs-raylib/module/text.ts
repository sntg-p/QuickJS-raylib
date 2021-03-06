import * as rl from './native/qjs-raylib.so';

// Font loading/unloading functions
export const getFontDefault = rl.getFontDefault;
export const loadFont = rl.loadFont;

export const loadFontEx = (fileName: string, fontSize: number, fontChars: number[]) => rl.loadFontEx(fileName, fontSize, fontChars, fontChars.length);

export const loadFontFromImage = rl.loadFontFromImage;
export const loadFontData = rl.loadFontData;
export const unloadFont = rl.unloadFont;

// Text drawing functions
export const drawText = rl.drawText;
export const drawFps = rl.drawFps;
export const drawTextEx = rl.drawTextEx;
export const drawTextRec = rl.drawTextRec;
export const drawTextRecEx = rl.drawTextRecEx;

// Text misc. functions
export const measureText = rl.measureText;
export const measureTextEx = rl.measureTextEx;
export const getGlyphIndex = rl.getGlyphIndex;

// Text strings management functions


