export class ConfigFlag
{
	/** Set to show raylib logo at startup */
	static FLAG_SHOW_LOGO          = 1;
	/** Set to run program in fullscreen */
	static FLAG_FULLSCREEN_MODE    = 2;
	/** Set to allow resizable window */
	static FLAG_WINDOW_RESIZABLE   = 4;
	/** Set to disable window decoration (frame and buttons) */
	static FLAG_WINDOW_UNDECORATED = 8;
	/** Set to allow transparent window */
	static FLAG_WINDOW_TRANSPARENT = 16;
	/** Set to create the window initially hidden */
	static FLAG_WINDOW_HIDDEN      = 128;
	/** Set to try enabling MSAA 4X */
	static FLAG_MSAA_4X_HINT       = 32;
	/** Set to try enabling V-Sync on GPU */
	static FLAG_VSYNC_HINT         = 64;
}

export class TraceLogType
{
	/** Display all logs */
	static LOG_ALL = 0;
	static LOG_TRACE = 1;
	static LOG_DEBUG = 2;
	static LOG_INFO = 3;
	static LOG_WARNING = 4;
	static LOG_ERROR = 5;
	static LOG_FATAL = 6;
	/** Disable logging */
	static LOG_NONE = 7;
}

export class KeyboardKey
{
	// Alphanumeric keys
	static KEY_APOSTROPHE      = 39;
	static KEY_COMMA           = 44;
	static KEY_MINUS           = 45;
	static KEY_PERIOD          = 46;
	static KEY_SLASH           = 47;
	static KEY_ZERO            = 48;
	static KEY_ONE             = 49;
	static KEY_TWO             = 50;
	static KEY_THREE           = 51;
	static KEY_FOUR            = 52;
	static KEY_FIVE            = 53;
	static KEY_SIX             = 54;
	static KEY_SEVEN           = 55;
	static KEY_EIGHT           = 56;
	static KEY_NINE            = 57;
	static KEY_SEMICOLON       = 59;
	static KEY_EQUAL           = 61;
	static KEY_A               = 65;
	static KEY_B               = 66;
	static KEY_C               = 67;
	static KEY_D               = 68;
	static KEY_E               = 69;
	static KEY_F               = 70;
	static KEY_G               = 71;
	static KEY_H               = 72;
	static KEY_I               = 73;
	static KEY_J               = 74;
	static KEY_K               = 75;
	static KEY_L               = 76;
	static KEY_M               = 77;
	static KEY_N               = 78;
	static KEY_O               = 79;
	static KEY_P               = 80;
	static KEY_Q               = 81;
	static KEY_R               = 82;
	static KEY_S               = 83;
	static KEY_T               = 84;
	static KEY_U               = 85;
	static KEY_V               = 86;
	static KEY_W               = 87;
	static KEY_X               = 88;
	static KEY_Y               = 89;
	static KEY_Z               = 90;

	// Function keys
	static KEY_SPACE           = 32;
	static KEY_ESCAPE          = 256;
	static KEY_ENTER           = 257;
	static KEY_TAB             = 258;
	static KEY_BACKSPACE       = 259;
	static KEY_INSERT          = 260;
	static KEY_DELETE          = 261;
	static KEY_RIGHT           = 262;
	static KEY_LEFT            = 263;
	static KEY_DOWN            = 264;
	static KEY_UP              = 265;
	static KEY_PAGE_UP         = 266;
	static KEY_PAGE_DOWN       = 267;
	static KEY_HOME            = 268;
	static KEY_END             = 269;
	static KEY_CAPS_LOCK       = 280;
	static KEY_SCROLL_LOCK     = 281;
	static KEY_NUM_LOCK        = 282;
	static KEY_PRINT_SCREEN    = 283;
	static KEY_PAUSE           = 284;
	static KEY_F1              = 290;
	static KEY_F2              = 291;
	static KEY_F3              = 292;
	static KEY_F4              = 293;
	static KEY_F5              = 294;
	static KEY_F6              = 295;
	static KEY_F7              = 296;
	static KEY_F8              = 297;
	static KEY_F9              = 298;
	static KEY_F10             = 299;
	static KEY_F11             = 300;
	static KEY_F12             = 301;
	static KEY_LEFT_SHIFT      = 340;
	static KEY_LEFT_CONTROL    = 341;
	static KEY_LEFT_ALT        = 342;
	static KEY_LEFT_SUPER      = 343;
	static KEY_RIGHT_SHIFT     = 344;
	static KEY_RIGHT_CONTROL   = 345;
	static KEY_RIGHT_ALT       = 346;
	static KEY_RIGHT_SUPER     = 347;
	static KEY_KB_MENU         = 348;
	static KEY_LEFT_BRACKET    = 91;
	static KEY_BACKSLASH       = 92;
	static KEY_RIGHT_BRACKET   = 93;
	static KEY_GRAVE           = 96;

	// Keypad keys
	static KEY_KP_0            = 320;
	static KEY_KP_1            = 321;
	static KEY_KP_2            = 322;
	static KEY_KP_3            = 323;
	static KEY_KP_4            = 324;
	static KEY_KP_5            = 325;
	static KEY_KP_6            = 326;
	static KEY_KP_7            = 327;
	static KEY_KP_8            = 328;
	static KEY_KP_9            = 329;
	static KEY_KP_DECIMAL      = 330;
	static KEY_KP_DIVIDE       = 331;
	static KEY_KP_MULTIPLY     = 332;
	static KEY_KP_SUBTRACT     = 333;
	static KEY_KP_ADD          = 334;
	static KEY_KP_ENTER        = 335;
	static KEY_KP_EQUAL        = 336;
}

export class MouseButton
{
	static MOUSE_LEFT_BUTTON   = 0;
	static MOUSE_RIGHT_BUTTON  = 1;
	static MOUSE_MIDDLE_BUTTON = 2;
}

export class GamepadNumber
{
	static GAMEPAD_PLAYER1     = 0;
	static GAMEPAD_PLAYER2     = 1;
	static GAMEPAD_PLAYER3     = 2;
	static GAMEPAD_PLAYER4     = 3;
}

export class GamepadButton
{
	// This is here just for error checking
	static GAMEPAD_BUTTON_UNKNOWN = 0;

	// This is normally [A,B,X,Y]/[Circle,Triangle,Square,Cross]
	// No support for 6 button controllers though..
	static GAMEPAD_BUTTON_LEFT_FACE_UP = 1;
	static GAMEPAD_BUTTON_LEFT_FACE_RIGHT = 2;
	static GAMEPAD_BUTTON_LEFT_FACE_DOWN = 3;
	static GAMEPAD_BUTTON_LEFT_FACE_LEFT = 4;

	// This is normally a DPAD
	static GAMEPAD_BUTTON_RIGHT_FACE_UP = 5;
	static GAMEPAD_BUTTON_RIGHT_FACE_RIGHT = 6;
	static GAMEPAD_BUTTON_RIGHT_FACE_DOWN = 7;
	static GAMEPAD_BUTTON_RIGHT_FACE_LEFT = 8;

	// Triggers
	static GAMEPAD_BUTTON_LEFT_TRIGGER_1 = 9;
	static GAMEPAD_BUTTON_LEFT_TRIGGER_2 = 10;
	static GAMEPAD_BUTTON_RIGHT_TRIGGER_1 = 11;
	static GAMEPAD_BUTTON_RIGHT_TRIGGER_2 = 12;

	// These are buttons in the center of the gamepad
	/** PS3 Select */
	static GAMEPAD_BUTTON_MIDDLE_LEFT = 13;
	/** PS Button/XBOX Button */
	static GAMEPAD_BUTTON_MIDDLE = 14;
	/** PS3 Start */
	static GAMEPAD_BUTTON_MIDDLE_RIGHT = 15;

	// These are the joystick press in buttons
	static GAMEPAD_BUTTON_LEFT_THUMB = 16;
	static GAMEPAD_BUTTON_RIGHT_THUMB = 17;
}

export class ShaderLocationIndex
{
	static LOC_VERTEX_POSITION = 0;
	static LOC_VERTEX_TEXCOORD01 = 1;
	static LOC_VERTEX_TEXCOORD02 = 2;
	static LOC_VERTEX_NORMAL = 3;
	static LOC_VERTEX_TANGENT = 4;
	static LOC_VERTEX_COLOR = 5;
	static LOC_MATRIX_MVP = 6;
	static LOC_MATRIX_MODEL = 7;
	static LOC_MATRIX_VIEW = 8;
	static LOC_MATRIX_PROJECTION = 9;
	static LOC_VECTOR_VIEW = 10;
	static LOC_COLOR_DIFFUSE = 11;
	static LOC_COLOR_SPECULAR = 12;
	static LOC_COLOR_AMBIENT = 13;
	static LOC_MAP_DIFFUSE = 14;
	static LOC_MAP_ALBEDO = 14;
	static LOC_MAP_SPECULAR = 15;
	static LOC_MAP_METALNESS = 15;
	static LOC_MAP_NORMAL = 16;
	static LOC_MAP_ROUGHNESS = 17;
	static LOC_MAP_OCCLUSION = 18;
	static LOC_MAP_EMISSION = 19;
	static LOC_MAP_HEIGHT = 20;
	static LOC_MAP_CUBEMAP = 21;
	static LOC_MAP_IRRADIANCE = 22;
	static LOC_MAP_PREFILTER = 23;
	static LOC_MAP_BRDF = 24;
}

export class ShaderUniformDataType
{
	static UNIFORM_FLOAT = 0;
	static UNIFORM_VEC2 = 1;
	static UNIFORM_VEC3 = 2;
	static UNIFORM_VEC4 = 3;
	static UNIFORM_INT = 4;
	static UNIFORM_IVEC2 = 5;
	static UNIFORM_IVEC3 = 6;
	static UNIFORM_IVEC4 = 7;
	static UNIFORM_SAMPLER2D = 8;
}

export class MaterialMapType
{
	static MAP_DIFFUSE = 0;
	static MAP_ALBEDO = 0;
	static MAP_SPECULAR = 1;
	static MAP_METALNESS = 1;
	static MAP_NORMAL    = 2;
	static MAP_ROUGHNESS = 3;
	static MAP_OCCLUSION = 4;
	static MAP_EMISSION = 5;
	static MAP_HEIGHT= 6;
	static MAP_CUBEMAP = 7;             // NOTE: Uses GL_TEXTURE_CUBE_MAP
	static MAP_IRRADIANCE = 8;          // NOTE: Uses GL_TEXTURE_CUBE_MAP
	static MAP_PREFILTER = 9;           // NOTE: Uses GL_TEXTURE_CUBE_MAP
	static MAP_BRDF = 10;
}

export class PixelFormat
{
	static UNCOMPRESSED_GRAYSCALE = 1;     // 8 bit per pixel (no alpha)
	static UNCOMPRESSED_GRAY_ALPHA = 2;        // 8*2 bpp (2 channels)
	static UNCOMPRESSED_R5G6B5 = 3;            // 16 bpp
	static UNCOMPRESSED_R8G8B8 = 4;            // 24 bpp
	static UNCOMPRESSED_R5G5B5A1 = 5;          // 16 bpp (1 bit alpha)
	static UNCOMPRESSED_R4G4B4A4 = 6;          // 16 bpp (4 bit alpha)
	static UNCOMPRESSED_R8G8B8A8 = 7;          // 32 bpp
	static UNCOMPRESSED_R32 = 8;               // 32 bpp (1 channel - float)
	static UNCOMPRESSED_R32G32B32 = 9;         // 32*3 bpp (3 channels - float)
	static UNCOMPRESSED_R32G32B32A32 = 10;      // 32*4 bpp (4 channels - float)
	static COMPRESSED_DXT1_RGB = 11;            // 4 bpp (no alpha)
	static COMPRESSED_DXT1_RGBA = 12;           // 4 bpp (1 bit alpha)
	static COMPRESSED_DXT3_RGBA = 13;           // 8 bpp
	static COMPRESSED_DXT5_RGBA = 14;           // 8 bpp
	static COMPRESSED_ETC1_RGB = 15;            // 4 bpp
	static COMPRESSED_ETC2_RGB = 16;            // 4 bpp
	static COMPRESSED_ETC2_EAC_RGBA = 17;       // 8 bpp
	static COMPRESSED_PVRT_RGB = 18;            // 4 bpp
	static COMPRESSED_PVRT_RGBA = 19;           // 4 bpp
	static COMPRESSED_ASTC_4x4_RGBA = 20;       // 8 bpp
	static COMPRESSED_ASTC_8x8_RGBA = 21;        // 2 bpp
}

export class TextureFilterMode
{
	static FILTER_POINT = 1;                   // No filter, just pixel aproximation
	static FILTER_BILINEAR = 2;                // Linear filtering
	static FILTER_TRILINEAR = 3;               // Trilinear filtering (linear with mipmaps)
	static FILTER_ANISOTROPIC_4X = 4;          // Anisotropic filtering 4x
	static FILTER_ANISOTROPIC_8X = 5;          // Anisotropic filtering 8x
	static FILTER_ANISOTROPIC_16X = 6;         // Anisotropic filtering 16x
}

export class CubemapLayoutType
{
	static CUBEMAP_AUTO_DETECT = 0;            // Automatically detect layout type
	static CUBEMAP_LINE_VERTICAL = 1;          // Layout is defined by a vertical line with faces
	static CUBEMAP_LINE_HORIZONTAL = 2;        // Layout is defined by an horizontal line with faces
	static CUBEMAP_CROSS_THREE_BY_FOUR = 3;    // Layout is defined by a 3x4 cross with cubemap faces
	static CUBEMAP_CROSS_FOUR_BY_THREE = 4;    // Layout is defined by a 4x3 cross with cubemap faces
	static CUBEMAP_PANORAMA = 4;               // Layout is defined by a panorama image (equirectangular map)
}

export class TextureWrapMode
{
	static WRAP_REPEAT = 0;            // Repeats texture in tiled mode
	static WRAP_CLAMP = 1;             // Clamps texture to edge pixel in tiled mode
	static WRAP_MIRROR_REPEAT = 2;     // Mirrors and repeats the texture in tiled mode
	static WRAP_MIRROR_CLAMP = 3;      // Mirrors and clamps to border the texture in tiled mode
}

export class FontType
{
	static FONT_DEFAULT = 0;            // Default font generation, anti-aliased
	static FONT_BITMAP = 1;             // Bitmap font generation, no anti-aliasing
	static FONT_SDF = 2;                // SDF font generation, requires external shader
}

export class BlendMode
{
	static BLEND_ALPHA = 0;             // Blend textures considering alpha (default)
	static BLEND_ADDITIVE = 1;          // Blend textures adding colors
	static BLEND_MULTIPLIED = 2;        // Blend textures multiplying colors
}

export class GestureType
{
	static GESTURE_NONE        = 0;
	static GESTURE_TAP         = 1;
	static GESTURE_DOUBLETAP   = 2;
	static GESTURE_HOLD        = 4;
	static GESTURE_DRAG        = 8;
	static GESTURE_SWIPE_RIGHT = 16;
	static GESTURE_SWIPE_LEFT  = 32;
	static GESTURE_SWIPE_UP    = 64;
	static GESTURE_SWIPE_DOWN  = 128;
	static GESTURE_PINCH_IN    = 256;
	static GESTURE_PINCH_OUT   = 512;
}

export class CameraMode
{
	static CAMERA_CUSTOM = 0;
	static CAMERA_FREE = 1;
	static CAMERA_ORBITAL = 2;
	static CAMERA_FIRST_PERSON = 3;
	static CAMERA_THIRD_PERSON = 4;
}

export class CameraType
{
	static CAMERA_PERSPECTIVE = 0;
	static CAMERA_ORTHOGRAPHIC = 1;
}

export class NPatchType
{
	static NPT_9PATCH = 0;              // Npatch defined by 3x3 tiles
	static NPT_3PATCH_VERTICAL = 1;     // Npatch defined by 1x3 tiles
	static NPT_3PATCH_HORIZONTAL = 2;   // Npatch defined by 3x1 tiles
}
