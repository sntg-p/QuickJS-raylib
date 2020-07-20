import { Vector3, Color, Texture, Vector2, Ray } from './qjs-raylib.so';
import { CubemapLayoutType } from '../enums';

// Basic geometric 3D shapes drawing functions
export function drawLine3d(start: Vector3, end: Vector3, color: Color): void;
export function drawPoint3d(position: Vector3, color: Color): void;
export function drawCircle3d(center: Vector3, radius: number, rotationAxis: Vector3, rotationAngle: number, color: Color): void;
export function drawCube(position: Vector3, width: number, height: number, length: number, color: Color): void;
export function drawCubeWires(position: Vector3, width: number, height: number, length: number, color: Color): void;
export function drawCubeV(position: Vector3, size: Vector3, color: Color): void;
export function drawCubeWiresV(position: Vector3, size: Vector3, color: Color): void;
export function drawCubeTexture(texture: Texture, position: Vector3, width: number, height: number, length: number, color: Color): void;
export function drawSphere(center: Vector3, radius: number, color: Color): void;
export function drawSphereEx(position: Vector3, radius: number, rings: number, slices: number, color: Color): void;
export function drawSphereWires(position: Vector3, radius: number, rings: number, slices: number, color: Color): void;
export function drawCylinder(position: Vector3, radiusTop: number, radiusBottom: number, height: number, slices: number, color: Color): void;
export function drawCylinderWires(position: Vector3, radiusTop: number, radiusBottom: number, height: number, slices: number, color: Color): void;
export function drawPlane(center: Vector3, size: Vector2, color: Color): void;
export function drawRay(ray: Ray, color: Color): void;
export function drawGrid(slices: number, spacing: number): void;
export function drawGizmo(position: Vector3): void;

// Model loading/unloading functions

// Mesh loading/unloading functions

// Material loading/unloading functions

// Model animations loading/unloading functions

// Mesh generation functions

// Mesh manipulation functions

// Model drawing functions

// Collision detection functions