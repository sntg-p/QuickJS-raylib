import { Font, CharInfo, Image, Color, Vector2, Rectangle } from "./qjs-raylib.so";
import { FontType } from "../enums.js";

// Font loading/unloading functions
export function getFontDefault(): Font;
export function loadFont(fileName: string): Font;
export function loadFontEx(fileName: string, fontSize: number, fontChars: number[], charsCount: number): Font;
export function loadFontFromImage(image: Image, key: Color, firstChar: number): Font;
export function loadFontData(fileName: string, fontSize: number, fontChars: number[], type: FontType): CharInfo[];
export function unloadFont(font: Font): void;

// Text drawing functions
export function drawText(text: string, x: number, y: number, size: number, color: Color | number): void;
export function drawFps(x: number, y: number): void;
export function drawTextEx(font: Font, text: string, position: Vector2, fontSize: number, spacing: number, tint: Color): void;
export function drawTextRec(font: Font, text: string, rec: Rectangle, fontSize: number, spacing: number, wordWrap: boolean, tint: Color): void;
export function drawTextRecEx(font: Font, text: string, rec: Rectangle, fontSize: number, spacing: number, wordWrap: boolean, tint: Color, selectStart: number, selectLength: number, selectText: Color, selectBack: Color): void;

// Text misc. functions
export function measureText(text: string, fontSize: number): number;
export function measureTextEx(font: Font, text: string, fontSize: number, spacing: number): Vector2;
export function getGlyphIndex(font: Font, character: number): number;

// Text strings management functions

