import { Image, Vector4, Color, RenderTexture, Texture2D } from './native/qjs-raylib.so';
import { CubemapLayoutType } from './enums';

// Image/Texture2D data loading/unloading/saving functions
export function loadImage(fileName: string): Image;
export function loadImageEx(pixels: Color[], width: number, height: number): Image;
export function loadImagePro(pixels: number[], width: number, height: number, format: number): Image;
export function loadImageRaw(fileName: string, width: number, height: number, format: number, headerSize: number): Image;
export function exportImage(image: Image, fileName: string): void;
export function exportImageAsCode(image: Image, fileName: string): void;
export function loadTexture(fileName: string): Texture;
export function loadTextureFromImage(image: Image): Texture;
export function loadTextureCubemap(image: Image, layoutType: CubemapLayoutType): Texture;
export function loadRenderTexture(width: number, height: number): RenderTexture;
export function unloadImage(image: Image): void;
export function unloadTexture(texture: Texture): void;
export function unloadRenderTexture(texture: RenderTexture): void;
export function getImageData(image: Image): Color[];
export function getImageDataNormalized(image: Image): Vector4[];
export function getPixelDataSize(width: number, height: number, format: number): number;
export function getTextureData(texture: Texture): Image;
export function getScreenData(): Image;
export function updateTexture(texture: Texture, pixels: number[]): void;