import { Font, CharInfo, Image, Color } from "./qjs-raylib.so";
import { FontType } from "./enums.js";

// Font loading/unloading functions
export function getFontDefault(): Font;
export function loadFont(fileName: string): Font;
export function loadFontEx(fileName: string, fontSize: number, fontChars: number[]): Font;
export function loadFontFromImage(image: Image, key: Color, firstChar: number): Font;
export function loadFontData(fileName: string, fontSize: number, fontChars: number[], type: FontType): CharInfo[];
export function getImageFontAtlas(chars: CharInfo[], fontSize: number, padding: number, packMethod: number): Image;
export function unloadFont(font: Font): void;

// Text drawing functions
export function drawText(text: string, x: number, y: number, size: number, color: Color | number): void;
export function drawFps(x: number, y: number): void;

// Text misc. functions


// Text strings management functions


