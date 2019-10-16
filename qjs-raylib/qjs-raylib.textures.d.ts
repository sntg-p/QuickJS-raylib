export class Image
{
	pointer: number;
	get width(): number;
	get height(): number;
}

export function loadImage(fileName: string): Image;