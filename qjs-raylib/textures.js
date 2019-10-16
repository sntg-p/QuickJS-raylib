// @ts-ignore
import * as rl from './qjs-raylib.so';

export class Image
{
	/** @type {number} */
	pointer;
	
	// data;

	get width() { return rl.getImageWidth(this.pointer); }
	get height() { return rl.getImageHeight(this.pointer); }

	// mipmaps;
	// format;
}

/**
 * @param {string} fileName
 */
export function loadImage(fileName)
{
	const image = new Image();
	image.pointer = rl.loadImage(fileName);
	return image;
}