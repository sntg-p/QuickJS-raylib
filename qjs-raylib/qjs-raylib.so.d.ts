type pointer = number;
const MAX_SHADER_LOCATIONS = 32;

export function Vector2(x: number, y: number);
export class Vector2
{
	x: number;
	y: number;
	constructor(x: number, y: number);
}

export function Vector3(x: number, y: number, z: number);
export class Vector3 extends Vector2
{
	z: number;
	constructor(x: number, y: number, z: number);
}

export function Vector4(x: number, y: number, z: number, w: number);
export class Vector4 extends Vector3
{
	w: number;
	constructor(x: number, y: number, z: number, w: number);
}

export type Quaternion = Vector4;

export function Matrix(m0: number, m1: number, m2: number, m3: number, m4: number, m5: number, m6: number, m7: number, m8: number, m9: number, m10: number, m11: number, m12: number, m13: number, m14: number, m15: number);
export class Matrix
{
	m0: number;
	m1: number;
	m2: number;
	m3: number;
	m4: number;
	m5: number;
	m6: number;
	m7: number;
	m8: number;
	m9: number;
	m10: number;
	m11: number;
	m12: number;
	m13: number;
	m14: number;
	m15: number;
	constructor(m0: number, m1: number, m2: number, m3: number, m4: number, m5: number, m6: number, m7: number, m8: number, m9: number, m10: number, m11: number, m12: number, m13: number, m14: number, m15: number)
}

export class Color
{
	r: number;
	g: number;
	b: number;
	a: number;
}

export interface Rectangle
{
	x: number;
	y: number;
	width: number;
	height: number;
}

export class Image
{
	get width(): number;
	get height(): number;
	get format(): number;
	get mipmaps(): number;
}

export class Texture
{
	get width(): number;
	get height(): number;
	get format(): number;
	get mipmaps(): number;
}

export class RenderTexture
{
	pointer: number;
	get id(): number;
	get texture(): Texture;
	get depth(): Texture;
	get depthTexture(): boolean;
	set depthTexture(value: boolean): void;
	constructor(width: number, height: number);
}

export interface NPatchInfo
{
	sourceRec: Rectangle;
	left: number;
	top: number;
	right: number;
	bottom: number;
	type: number;
}

export interface NPatchInfo
{
	sourceRec: Rectangle;
	left: number;
	top: number;
	right: number;
	bottom: number;
	type: number;
}

export class CharInfo
{
	value: number;
	rec: Rectangle;
	offsetX: number;
	offsetY: number;
	advanceX: number;
	data: pointer;
}

export class Font
{
	texture: Texture;
	baseSize: number;
	charsCount: number;
	chars: CharInfo;
}

export class Camera3D
{
	position: Vector3;
	target: Vector3;
	up: Vector3;
	fov: number;
	type: number;
	constructor(position: Vector3, target: Vector3, up: Vector3, fov: number, type: number);
}

export class Camera2D
{
	offset: Vector2;
	target: Vector2;
	rotation: number;
	zoom: number;
	constructor(offset: Vector2, target: Vector2, rotation: number, zoom: number);
}

export class Mesh
{
	vertexCount: number;
	triangleCount: number;

	// Default vertex data
	vertices: pointer;
	texcoords: pointer;
	texcoords2: pointer;
	normals: pointer;
	tangets: pointer;
	colors: pointer;
	indices: pointer;

	// Animation vertex data
	animVertices: pointer;
	animNormals: pointer;
	boneIds: pointer;
	boneWeights: pointer;

	// OpenGL identifiers
	vaoId: number | number[7];
}

export interface Shader
{
	id: number;
	locs: number[32];
}

export interface MaterialMap
{
	texture: Texture;
	color: Color;
	value: number;
}

export interface Material
{
	shader: Shader;
	maps: MaterialMap[32];
	params: pointer;
}

export interface Transform
{
	translation: Vector3;
	rotation: Quaternion;
	scale: Vector3;
}

export interface BoneInfo
{
	name: string;
	parent: number;
}

export class Model
{
	transform: Matrix;

	meshCount: number;
	meshes: pointer[];

	materialCount: number;
	materials: pointer[];
	meshMaterial: pointer;

	// Animation data
	boneCount: number;
	bones: pointer[];
	bindPose: pointer[];
}

export class ModelAnimation
{
	boneCount: number;
	bones: pointer;
	
	frameCount: number;
	framePoses: pointer[];
}

export interface Ray
{
	position: Vector3;
	direction: Vector3;
	constructor(position: Vector3, direction: Vector3);
}

export interface RayHitInfo
{
	hit: boolean;
	distance: number;
	position: Vector3;
	normal: Vector3;
}

export interface BoundingBox
{
	min: Vector3;
	max: Vector3;
}

export class Wave
{
	sampleCount: number;
	sampleRate: number;
	sampleSize: number;
	channels: number;
	data: pointer;
}

export class Sound
{
	audioBuffer: pointer;
	source: number;
	buffer: number;
	format: number;
}

export class AudioStream
{
	sampleRate: number;
	sampleSize: number;
	channels: number;

	audioBuffer: pointer;

	format: number;
	source: number;
	buffers: pointer;
}

export interface VrDeviceInfo
{
	hResolution: number;
	vResolution: number;
	hScreenSize: number;
	vScreenSize: number;
	vScreenCenter: number;
	eyeToScreenDistance: number;
	lensSeparationDistance: number;
	interpupullaryDistance: number;
	lensDistortionValues: number[4];
	chromaAbCorrection: number[4];
}
