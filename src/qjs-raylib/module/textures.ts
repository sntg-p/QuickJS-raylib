import * as rl from './native/qjs-raylib.so';

// Image/Texture2D data loading/unloading/saving functions
export const loadImage = rl.loadImage;
export const loadImageEx = rl.loadImageEx;
export const loadImagePro = rl.loadImagePro;
export const loadImageRaw = rl.loadImageRaw;
export const exportImage = rl.exportImage;
export const exportImageAsCode = rl.exportImageAsCode;
export const loadTexture = rl.loadTexture;
export const loadTextureFromImage = rl.loadTextureFromImage;
export const loadTextureCubemap = rl.loadTextureCubemap;
export const loadRenderTexture = rl.loadRenderTexture;
export const unloadImage = rl.unloadImage;
export const unloadTexture = rl.unloadTexture;
export const unloadRenderTexture = rl.unloadRenderTexture;
export const getImageData = rl.getImageData;
export const getImageDataNormalized = rl.getImageDataNormalized;
export const getPixelDataSize = rl.getPixelDataSize;
export const getTextureData = rl.getTextureData;
export const getScreenData = rl.getScreenData;
export const updateTexture = rl.updateTexture;