#include "stdio.h"
#include "string.h"

#include "quickjs/quickjs.h"
#include "quickjs/cutils.h"
#include "raylib/raylib.h"

#include "structs.h"

// module: core
#pragma region Window-related functions

static JSValue rl_init_window(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv)
{
	int w, h;
	const char* title = NULL;

	if (JS_ToInt32(ctx, &w, argv[0]))
		return JS_EXCEPTION;
	
	if (JS_ToInt32(ctx, &h, argv[1]))
		return JS_EXCEPTION;

	title = JS_ToCString(ctx, argv[2]);
	if (title == NULL)
		return JS_EXCEPTION;

	InitWindow(w, h, title);

	return JS_UNDEFINED;
}

static JSValue rl_window_should_close(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv)
{
	return JS_NewBool(ctx, WindowShouldClose());
}

static JSValue rl_close_window(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv)
{
	CloseWindow();
	return JS_UNDEFINED;
}

static JSValue rl_is_window_ready(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv)
{
	return JS_NewBool(ctx, IsWindowReady());
}

static JSValue rl_is_window_minimized(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv)
{
	return JS_NewBool(ctx, IsWindowMinimized());
}

static JSValue rl_is_window_resized(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv)
{
	return JS_NewBool(ctx, IsWindowResized());
}

static JSValue rl_is_window_hidden(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv)
{
	return JS_NewBool(ctx, IsWindowHidden());
}

static JSValue rl_toggle_fullscreen(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv)
{
	ToggleFullscreen();
	return JS_UNDEFINED;
}

static JSValue rl_unhide_window(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv)
{
	UnhideWindow();
	return JS_UNDEFINED;
}

static JSValue rl_hide_window(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv)
{
	HideWindow();
	return JS_UNDEFINED;
}

static JSValue rl_set_window_icon(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv)
{
	Image *icon = (Image*)JS_GetOpaque2(ctx, argv[0], js_rl_image_class_id);

	if (!icon)
		return JS_EXCEPTION;

	SetWindowIcon(*icon);
	return JS_UNDEFINED;
}

static JSValue rl_set_window_title(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv)
{
	const char* title = NULL;

	title = JS_ToCString(ctx, argv[0]);
	if (title == NULL)
		return JS_EXCEPTION;

	SetWindowTitle(title);

	return JS_UNDEFINED;
}

static JSValue rl_set_window_position(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv)
{
	int x, y;

	if (JS_ToInt32(ctx, &x, argv[0]))
		return JS_EXCEPTION;
	
	if (JS_ToInt32(ctx, &y, argv[1]))
		return JS_EXCEPTION;

	SetWindowPosition(x, y);

	return JS_UNDEFINED;
}

static JSValue rl_set_window_monitor(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv)
{
	int m;

	if (JS_ToInt32(ctx, &m, argv[0]))
		return JS_EXCEPTION;

	SetWindowMonitor(m);

	return JS_UNDEFINED;
}

static JSValue rl_set_window_min_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv)
{
	int w, h;

	if (JS_ToInt32(ctx, &w, argv[0]))
		return JS_EXCEPTION;
	
	if (JS_ToInt32(ctx, &h, argv[1]))
		return JS_EXCEPTION;

	SetWindowMinSize(w, h);

	return JS_UNDEFINED;
}

static JSValue rl_set_window_size(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv)
{
	int w, h;

	if (JS_ToInt32(ctx, &w, argv[0]))
		return JS_EXCEPTION;
	
	if (JS_ToInt32(ctx, &h, argv[1]))
		return JS_EXCEPTION;

	SetWindowSize(w, h);

	return JS_UNDEFINED;
}

static JSValue rl_get_screen_width(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv)
{
	return JS_NewInt32(ctx, GetScreenWidth());
}

static JSValue rl_get_screen_height(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv)
{
	return JS_NewInt32(ctx, GetScreenHeight());
}

static JSValue rl_get_monitor_count(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv)
{
	return JS_NewInt32(ctx, GetMonitorCount());
}

static JSValue rl_get_monitor_width(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv)
{
	int m;

	if (JS_ToInt32(ctx, &m, argv[0]))
		return JS_EXCEPTION;

	return JS_NewInt32(ctx, GetMonitorWidth(m));
}

static JSValue rl_get_monitor_height(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv)
{
	int m;

	if (JS_ToInt32(ctx, &m, argv[0]))
		return JS_EXCEPTION;

	return JS_NewInt32(ctx, GetMonitorHeight(m));
}

static JSValue rl_get_monitor_physical_width(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv)
{
	int m;

	if (JS_ToInt32(ctx, &m, argv[0]))
		return JS_EXCEPTION;

	return JS_NewInt32(ctx, GetMonitorPhysicalWidth(m));
}

static JSValue rl_get_monitor_physical_height(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv)
{
	int m;

	if (JS_ToInt32(ctx, &m, argv[0]))
		return JS_EXCEPTION;

	return JS_NewInt32(ctx, GetMonitorPhysicalHeight(m));
}

static JSValue rl_get_monitor_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv)
{
	int m;

	if (JS_ToInt32(ctx, &m, argv[0]))
		return JS_EXCEPTION;

	return JS_NewString(ctx, GetMonitorName(m));
}

static JSValue rl_get_clipboard_text(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv)
{
	return JS_NewString(ctx, GetClipboardText());
}

static JSValue rl_set_clipboard_text(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv)
{
	const char* text = NULL;

	text = JS_ToCString(ctx, argv[0]);
	if (text == NULL)
		return JS_EXCEPTION;

	SetClipboardText(text);

	return JS_UNDEFINED;
}

#pragma endregion
#pragma region Cursor-related functions

static JSValue rl_show_cursor(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv)
{
	ShowCursor();
	return JS_UNDEFINED;
}

static JSValue rl_hide_cursor(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv)
{
	HideCursor();
	return JS_UNDEFINED;
}

static JSValue rl_is_cursor_hidden(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv)
{
	return JS_NewBool(ctx, IsCursorHidden());
}

static JSValue rl_enable_cursor(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv)
{
	EnableCursor();
	return JS_UNDEFINED;
}

static JSValue rl_disable_cursor(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv)
{
	DisableCursor();
	return JS_UNDEFINED;
}

#pragma endregion
#pragma region Drawing-related functions

static JSValue rl_clear_background(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv)
{
	Color color = BLACK;
	int colorInt;

	if (JS_IsNumber(argv[0]))
	{
		if (JS_ToInt32(ctx, &colorInt, argv[0])) {
			ClearBackground(color);
			return JS_UNDEFINED;
		}
		else
			color = GetColor(colorInt);
	}
	else if (JS_IsObject(argv[0]))
		color = *(Color*)JS_GetOpaque2(ctx, argv[0], js_rl_color_class_id);

	ClearBackground(color);	
	return JS_UNDEFINED;
}

static JSValue rl_begin_drawing(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv)
{
	BeginDrawing();
	return JS_UNDEFINED;
}

static JSValue rl_end_drawing(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv)
{
	EndDrawing();
	return JS_UNDEFINED;
}

static JSValue rl_begin_mode_2d(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv)
{
	Camera2D cam = *(Camera2D*)JS_GetOpaque2(ctx, argv[0], js_rl_camera2d_class_id);
	BeginMode2D(cam);
	return JS_UNDEFINED;
}

static JSValue rl_end_mode_2d(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv)
{
	EndMode2D();
	return JS_UNDEFINED;
}

static JSValue rl_begin_mode_3d(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv)
{
	Camera3D cam = *(Camera3D*)JS_GetOpaque2(ctx, argv[0], js_rl_camera3d_class_id);
	BeginMode3D(cam);
	return JS_UNDEFINED;
}

static JSValue rl_end_mode_3d(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv)
{
	EndMode3D();
	return JS_UNDEFINED;
}

static JSValue rl_begin_texture_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv)
{
	RenderTexture2D tex = *(RenderTexture2D*)JS_GetOpaque2(ctx, argv[0], js_rl_render_texture_class_id);
	BeginTextureMode(tex);
	return JS_UNDEFINED;
}

static JSValue rl_end_texture_mode(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv)
{
	EndTextureMode();
	return JS_UNDEFINED;
}

#pragma endregion
#pragma region Screen-space-related functions

static JSValue rl_get_mouse_ray(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv)
{
	JSValue obj = JS_NewObjectClass(ctx, js_rl_ray_class_id);
	Vector2 mousePosition = *(Vector2*)JS_GetOpaque2(ctx, argv[0], js_rl_vector2_class_id);
	Camera camera = *(Camera*)JS_GetOpaque2(ctx, argv[1], js_rl_camera3d_class_id);

	Ray* p = js_mallocz(ctx, sizeof(Ray));
	Ray ray = GetMouseRay(mousePosition, camera);

	if (!p) {
		JS_FreeValue(ctx, obj);
		return JS_EXCEPTION;
	}

	memcpy(p, &ray, sizeof(Ray));
	JS_SetOpaque(obj, p);

	return obj;
}

static JSValue rl_get_world_to_screen(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv)
{
	JSValue obj = JS_NewObjectClass(ctx, js_rl_ray_class_id);
	Vector3 spacePos = *(Vector3*)JS_GetOpaque2(ctx, argv[0], js_rl_vector3_class_id);
	Camera camera = *(Camera3D*)JS_GetOpaque2(ctx, argv[1], js_rl_camera3d_class_id);

	Vector2* p = js_mallocz(ctx, sizeof(Vector2));
	Vector2 screenPos = GetWorldToScreen(spacePos, camera);

	if (!p) {
		JS_FreeValue(ctx, obj);
		return JS_EXCEPTION;
	}

	memcpy(p, &screenPos, sizeof(Vector2));
	JS_SetOpaque(obj, p);

	return obj;
}

static JSValue rl_get_camera_matrix(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv)
{
	JSValue obj = JS_NewObjectClass(ctx, js_rl_matrix_class_id);
	Camera camera = *(Camera3D*)JS_GetOpaque2(ctx, argv[0], js_rl_camera3d_class_id);

	Matrix* p = js_mallocz(ctx, sizeof(Matrix));
	Matrix matrix = GetCameraMatrix(camera);

	if (!p) {
		JS_FreeValue(ctx, obj);
		return JS_EXCEPTION;
	}

	memcpy(p, &matrix, sizeof(Matrix));
	JS_SetOpaque(obj, p);

	return obj;
}

#pragma endregion
#pragma region Timing-related functions

static JSValue rl_set_target_fps(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv)
{
	int fps;

	if (JS_ToInt32(ctx, &fps, argv[0]))
		return JS_EXCEPTION;

	SetTargetFPS(fps);

	return JS_UNDEFINED;
}

static JSValue rl_get_fps(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv)
{
	return JS_NewInt32(ctx, GetFPS());
}

static JSValue rl_get_frame_time(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv)
{
	return JS_NewFloat64(ctx, GetFrameTime());
}

static JSValue rl_get_time(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv)
{
	return JS_NewFloat64(ctx, GetTime());
}

#pragma endregion
#pragma region Color-related functions

static JSValue rl_color_to_int(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv)
{
	Color color = *(Color*)JS_GetOpaque2(ctx, argv[0], js_rl_color_class_id);
	return JS_NewInt32(ctx, ColorToInt(color));
}

static JSValue rl_color_normalize(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv)
{
	Color color = *(Color*)JS_GetOpaque2(ctx, argv[0], js_rl_color_class_id);

	Vector4* p = js_mallocz(ctx, sizeof(Vector4));
	JSValue obj = JS_NewObjectClass(ctx, js_rl_vector3_class_id);

	if (!p) {
		JS_FreeValue(ctx, obj);
		return JS_EXCEPTION;
	}

	Vector4 vector4 = ColorNormalize(color);
	memcpy(p, &vector4, sizeof(Vector4));
	JS_SetOpaque(obj, p);

	return obj;
}

static JSValue rl_color_to_hsv(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv)
{
	Color color = *(Color*)JS_GetOpaque2(ctx, argv[0], js_rl_color_class_id);
	Vector3* p = js_mallocz(ctx, sizeof(Vector3));
	Vector3 hsv = ColorToHSV(color);

	JSValue obj = JS_NewObjectClass(ctx, js_rl_vector3_class_id);

	if (!p) {
		JS_FreeValue(ctx, obj);
		return JS_EXCEPTION;
	}

	memcpy(p, &hsv, sizeof(Vector3));
	JS_SetOpaque(obj, p);

	return obj;
}

static JSValue rl_color_from_hsv(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv)
{
	Vector3 hsv = *(Vector3*)JS_GetOpaque2(ctx, argv[0], js_rl_vector3_class_id);

	Color* p = js_mallocz(ctx, sizeof(Color));
	JSValue obj = JS_NewObjectClass(ctx, js_rl_color_class_id);

	if (!p) {
		JS_FreeValue(ctx, obj);
		return JS_EXCEPTION;
	}

	Color color = ColorFromHSV(hsv);
	memcpy(p, &color, sizeof(Color));

	JS_SetOpaque(obj, p);

	return obj;
}

static JSValue rl_get_color(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv)
{
	int colorInt;

	if (JS_ToInt32(ctx, &colorInt, argv[0]))
		return JS_UNDEFINED;

	Color* p = js_mallocz(ctx, sizeof(Color));
	JSValue obj = JS_NewObjectClass(ctx, js_rl_color_class_id);

	if (!p) {
		JS_FreeValue(ctx, obj);
		return JS_EXCEPTION;
	}

	Color color = GetColor(colorInt);
	memcpy(p, &color, sizeof(Color));

	JS_SetOpaque(obj, p);

	return obj;
}

static JSValue rl_fade(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv)
{
	Color color = *(Color*)JS_GetOpaque2(ctx, argv[0], js_rl_color_class_id);

	Color* p = js_mallocz(ctx, sizeof(Color));
	JSValue obj = JS_NewObjectClass(ctx, js_rl_color_class_id);

	if (!p) {
		JS_FreeValue(ctx, obj);
		return JS_EXCEPTION;
	}

	double fade;

	if (JS_ToFloat64(ctx, &fade, argv[1]))
		return JS_EXCEPTION;

	Color newColor = Fade(color, fade);
	memcpy(p, &newColor, sizeof(Color));
	JS_SetOpaque(obj, p);

	return obj;
}

#pragma endregion
#pragma region Misc. functions

static JSValue rl_set_config_flags(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv)
{
	int flags;

	if (JS_ToInt32(ctx, &flags, argv[0]))
		return JS_EXCEPTION;

	SetConfigFlags((unsigned char)flags);

	return JS_UNDEFINED;
}

static JSValue rl_set_trace_log_level(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv)
{
	int logType;

	if (JS_ToInt32(ctx, &logType, argv[0]))
		return JS_EXCEPTION;

	SetTraceLogLevel(logType);

	return JS_UNDEFINED;
}

static JSValue rl_set_trace_log_exit(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv)
{
	int logType;

	if (JS_ToInt32(ctx, &logType, argv[0]))
		return JS_EXCEPTION;

	SetTraceLogExit(logType);

	return JS_UNDEFINED;
}

static JSValue rl_take_screenshot(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv)
{
	const char* fileName = JS_ToCString(ctx, argv[0]);
	if (fileName == NULL)
		return JS_EXCEPTION;

	TakeScreenshot(fileName);

	return JS_UNDEFINED;
}

static JSValue rl_get_random_value(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv)
{
	int min, max;

	if (JS_ToInt32(ctx, &min, argv[0]))
		return JS_EXCEPTION;

	if (JS_ToInt32(ctx, &max, argv[1]))
		return JS_EXCEPTION;

	return JS_NewInt32(ctx, GetRandomValue(min, max));
}

static JSValue rl_open_url(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv)
{
	const char* url = JS_ToCString(ctx, argv[0]);
	if (url == NULL)
		return JS_EXCEPTION;

	OpenURL(url);

	return JS_UNDEFINED;
}

#pragma endregion
#pragma region Files management functions

static JSValue rl_file_exists(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv)
{
	const char* fileName = JS_ToCString(ctx, argv[0]);
	if (fileName == NULL)
		return JS_EXCEPTION;

	return JS_NewBool(ctx, FileExists(fileName));
}

static JSValue rl_is_file_extension(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv)
{
	const char* fileName = JS_ToCString(ctx, argv[0]);
	if (fileName == NULL)
		return JS_EXCEPTION;

	const char* extension = JS_ToCString(ctx, argv[2]);
	if (extension == NULL)
		return JS_EXCEPTION;

	return JS_NewBool(ctx, IsFileExtension(fileName, extension));
}

static JSValue rl_get_extension(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv)
{
	const char* fileName = JS_ToCString(ctx, argv[0]);
	if (fileName == NULL)
		return JS_EXCEPTION;

	return JS_NewString(ctx, GetExtension(fileName));
}

static JSValue rl_get_file_name(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv)
{
	const char* filePath = JS_ToCString(ctx, argv[0]);
	if (filePath == NULL)
		return JS_EXCEPTION;

	return JS_NewString(ctx, GetFileName(filePath));
}

static JSValue rl_get_file_name_without_extension(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv)
{
	const char* filePath = JS_ToCString(ctx, argv[0]);
	if (filePath == NULL)
		return JS_EXCEPTION;

	return JS_NewString(ctx, GetFileNameWithoutExt(filePath));
}

static JSValue rl_get_directory_path(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv)
{
	const char* fileName = JS_ToCString(ctx, argv[0]);
	if (fileName == NULL)
		return JS_EXCEPTION;

	return JS_NewString(ctx, GetDirectoryPath(fileName));
}

static JSValue rl_get_working_directory(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv)
{
	return JS_NewString(ctx, GetWorkingDirectory());
}

static JSValue rl_get_directory_files(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv)
{
	const char* dirPath = JS_ToCString(ctx, argv[0]);
	if (dirPath == NULL)
		return JS_EXCEPTION;

	int count;
	char** files = GetDirectoryFiles(dirPath, &count);

	JSValue arr = JS_NewArray(ctx);

	for (int i = 0; i < count; i++)
		JS_SetPropertyInt64(ctx, arr, i, JS_NewString(ctx, files[i]));

	ClearDirectoryFiles();

	return arr;
}

static JSValue rl_change_directory(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv)
{
	const char* dir = JS_ToCString(ctx, argv[0]);
	if (dir == NULL)
		return JS_EXCEPTION;

	return JS_NewBool(ctx, ChangeDirectory(dir));
}

static JSValue rl_is_file_dropped(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv)
{
	return JS_NewBool(ctx, IsFileDropped());
}

static JSValue rl_get_dropped_files(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv)
{
	int count;
	char** files = GetDroppedFiles(&count);

	JSValue arr = JS_NewArray(ctx);

	for (int i = 0; i < count; i++)
		JS_SetPropertyInt64(ctx, arr, i, JS_NewString(ctx, files[i]));

	ClearDroppedFiles();

	return arr;
}

static JSValue rl_get_file_mod_time(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv)
{
	const char* fileName = JS_ToCString(ctx, argv[0]);
	if (fileName == NULL)
		return JS_EXCEPTION;

	return JS_NewInt64(ctx, GetFileModTime(fileName));
}

#pragma endregion
#pragma region Persistent storage management

static JSValue rl_storage_save_value(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv)
{
	int position, value;

	if (JS_ToInt32(ctx, &position, argv[0]))
		return JS_EXCEPTION;

	if (JS_ToInt32(ctx, &value, argv[1]))
		return JS_EXCEPTION;

	StorageSaveValue(position, value);

	return JS_UNDEFINED;
}

static JSValue rl_storage_load_value(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv)
{
	int position;

	if (JS_ToInt32(ctx, &position, argv[0]))
		return JS_EXCEPTION;

	int value = StorageLoadValue(position);

	return JS_UNDEFINED;
}

#pragma endregion
// module: shapes
// module: textures
#pragma region Image/Texture2D data loading/unloading/saving functions

static JSValue rl_load_image(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv)
{
	JSValue obj = JS_NewObjectClass(ctx, js_rl_image_class_id);

	if (JS_IsException(obj))
		return obj;

	const char* fileName = NULL;

	fileName = JS_ToCString(ctx, argv[0]);
	if (fileName == NULL)
		return JS_EXCEPTION;

	Image* p = js_mallocz(ctx, sizeof(Image));
	Image image = LoadImage(fileName);

	if (!p) {
		JS_FreeValue(ctx, obj);
		return JS_EXCEPTION;
	}

	memcpy(p, &image, sizeof(Image));
	JS_SetOpaque(obj, p);

	return obj;
}

static JSValue rl_load_render_texture(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv)
{
	return js_rl_render_texture_constructor(ctx, JS_UNDEFINED, argc, argv);
}

#pragma endregion
// module: text
#pragma region Text drawing functions

static JSValue rl_draw_fps(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv)
{
	int x, y;

	if (JS_ToInt32(ctx, &x, argv[0]))
		return JS_EXCEPTION;

	if (JS_ToInt32(ctx, &y, argv[1]))
		return JS_EXCEPTION;

	DrawFPS(x, y);

	return JS_UNDEFINED;
}

static JSValue rl_draw_text(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv)
{
	const char* text = NULL;
	int x, y, size, colorInt;
	Color color = WHITE;
	
	text = JS_ToCString(ctx, argv[0]);
	if (text == NULL)
		return JS_EXCEPTION;

	if (JS_ToInt32(ctx, &x, argv[1]))
		return JS_EXCEPTION;

	if (JS_ToInt32(ctx, &y, argv[2]))
		return JS_EXCEPTION;

	if (JS_ToInt32(ctx, &size, argv[3]))
		return JS_EXCEPTION;

	if (JS_IsNumber(argv[4]))
	{
		if (JS_ToInt32(ctx, &colorInt, argv[4]))
			return JS_EXCEPTION;
		else
			color = GetColor(colorInt);
	}
	else if (JS_IsObject(argv[4]))
		color = *(Color*)JS_GetOpaque2(ctx, argv[4], js_rl_color_class_id);

	DrawText(text, x, y, size, color);

	return JS_UNDEFINED;
}

#pragma endregion


// function entries
static const JSCFunctionListEntry js_rl_funcs[] = {
	// module: core
	#pragma region Window-related functions

	JS_CFUNC_DEF("initWindow", 3, rl_init_window),
	JS_CFUNC_DEF("windowShouldClose", 1, rl_window_should_close),
	JS_CFUNC_DEF("closeWindow", 0, rl_close_window),
	JS_CFUNC_DEF("isWindowReady", 0, rl_is_window_ready),
	JS_CFUNC_DEF("isWindowMinimized", 0, rl_is_window_minimized),
	JS_CFUNC_DEF("isWindowResized", 0, rl_is_window_resized),
	JS_CFUNC_DEF("isWindowHidden", 0, rl_is_window_hidden),
	JS_CFUNC_DEF("toggleFullscreen", 0, rl_toggle_fullscreen),
	JS_CFUNC_DEF("unhideWindow", 0, rl_unhide_window),
	JS_CFUNC_DEF("hideWindow", 0, rl_hide_window),
	JS_CFUNC_DEF("setWindowIcon", 1, rl_set_window_icon),
	JS_CFUNC_DEF("setWindowTitle", 1, rl_set_window_title),
	JS_CFUNC_DEF("setWindowPosition", 2, rl_set_window_position),
	JS_CFUNC_DEF("setWindowMonitor", 1, rl_set_window_monitor),
	JS_CFUNC_DEF("setWindowMinSize", 2, rl_set_window_min_size),
	JS_CFUNC_DEF("setWindowSize", 2, rl_set_window_size),
	JS_CFUNC_DEF("getScreenWidth", 0, rl_get_screen_width),
	JS_CFUNC_DEF("getScreenHeight", 0, rl_get_screen_height),
	JS_CFUNC_DEF("getMonitorCount", 0, rl_get_monitor_count),
	JS_CFUNC_DEF("getMonitorWidth", 1, rl_get_monitor_width),
	JS_CFUNC_DEF("getMonitorHeight", 1, rl_get_monitor_height),
	JS_CFUNC_DEF("getMonitorPhysicalWidth", 1, rl_get_monitor_physical_width),
	JS_CFUNC_DEF("getMonitorPhysicalHeight", 1, rl_get_monitor_physical_height),
	JS_CFUNC_DEF("getMonitorName", 1, rl_get_monitor_name),
	JS_CFUNC_DEF("getClipboardText", 0, rl_get_clipboard_text),
	JS_CFUNC_DEF("setClipboardText", 1, rl_set_clipboard_text),

	#pragma endregion
	#pragma region Cursor-related functions

	JS_CFUNC_DEF("showCursor", 0, rl_show_cursor),
	JS_CFUNC_DEF("hideCursor", 0, rl_hide_cursor),
	JS_CFUNC_DEF("isCursorHidden", 0, rl_is_cursor_hidden),
	JS_CFUNC_DEF("enableHidden", 0, rl_enable_cursor),
	JS_CFUNC_DEF("disableHidden", 0, rl_disable_cursor),

	#pragma endregion
	#pragma region Drawing-related functions

	JS_CFUNC_DEF("clearBackground", 1, rl_clear_background),
	JS_CFUNC_DEF("beginDrawing", 0, rl_begin_drawing),
	JS_CFUNC_DEF("endDrawing", 0, rl_end_drawing),
	JS_CFUNC_DEF("beginMode2D", 1, rl_begin_mode_2d),
	JS_CFUNC_DEF("endMode2D", 0, rl_end_mode_2d),
	JS_CFUNC_DEF("beginMode3D", 1, rl_begin_mode_3d),
	JS_CFUNC_DEF("endMode3D", 0, rl_end_mode_3d),
	JS_CFUNC_DEF("beginTextureMode", 1, rl_begin_texture_mode),
	JS_CFUNC_DEF("endTextureMode", 0, rl_end_texture_mode),

	#pragma endregion
	#pragma region Screen-space-related functions

	JS_CFUNC_DEF("getMouseRay", 2, rl_get_mouse_ray),
	JS_CFUNC_DEF("getWorldToScreen", 2, rl_get_world_to_screen),
	JS_CFUNC_DEF("getCameraMatrix", 1, rl_get_camera_matrix),

	#pragma endregion
	#pragma region Timing-related functions

	JS_CFUNC_DEF("setTargetFps", 1, rl_set_target_fps),
	JS_CFUNC_DEF("getFps", 0, rl_get_fps),
	JS_CFUNC_DEF("getFrameTime", 0, rl_get_frame_time),
	JS_CFUNC_DEF("getTime", 0, rl_get_time),

	#pragma endregion
	#pragma region Color-related functions

	JS_CFUNC_DEF("colorToInt", 1, rl_color_to_int),
	JS_CFUNC_DEF("colorNormalize", 1, rl_color_normalize),
	JS_CFUNC_DEF("colorToHSV", 1, rl_color_to_hsv),
	JS_CFUNC_DEF("colorFromHSV", 1, rl_color_from_hsv),
	JS_CFUNC_DEF("getColor", 1, rl_get_color),
	JS_CFUNC_DEF("fade", 2, rl_fade),

	#pragma endregion
	#pragma region Misc. functions

	JS_CFUNC_DEF("setConfigFlags", 1, rl_set_config_flags),
	JS_CFUNC_DEF("setTraceLogLevel", 1, rl_set_trace_log_level),
	JS_CFUNC_DEF("setTraceLogExit", 1, rl_set_trace_log_exit),
	JS_CFUNC_DEF("takeScreenshot", 1, rl_take_screenshot),
	JS_CFUNC_DEF("getRandomValue", 2, rl_get_random_value),
	JS_CFUNC_DEF("openURL", 1, rl_open_url),

	#pragma endregion
	#pragma region Files management functions

	JS_CFUNC_DEF("fileExists", 1, rl_file_exists),
	JS_CFUNC_DEF("isFileExtension", 2, rl_is_file_extension),
	JS_CFUNC_DEF("getExtension", 1, rl_get_extension),
	JS_CFUNC_DEF("getFileName", 1, rl_get_file_name),
	JS_CFUNC_DEF("getFileNameWithoutExt", 1, rl_get_file_name_without_extension),
	JS_CFUNC_DEF("getDirectoryPath", 1, rl_get_directory_path),
	JS_CFUNC_DEF("getWorkingDirectory", 0, rl_get_working_directory),
	JS_CFUNC_DEF("getDirectoryFiles", 1, rl_get_directory_files),
	JS_CFUNC_DEF("changeDirectory", 1, rl_change_directory),
	JS_CFUNC_DEF("isFileDropped", 0, rl_is_file_dropped),
	JS_CFUNC_DEF("getDroppedFiles", 0, rl_get_dropped_files),
	JS_CFUNC_DEF("getFileModTime", 1, rl_get_file_mod_time),

	#pragma endregion
	#pragma region Persistent storage management

	JS_CFUNC_DEF("storageSaveValue", 2, rl_storage_save_value),
	JS_CFUNC_DEF("storageLoadValue", 1, rl_storage_load_value),

	#pragma endregion

	// module: shapes

	// module: textures
	#pragma region Image/Texture2D data loading/unloading/saving functions
	JS_CFUNC_DEF("loadImage", 1, rl_load_image),
	JS_CFUNC_DEF("loadRenderTexture", 2, rl_load_render_texture),
	#pragma endregion
	
	// module: text
	#pragma region Text drawing functions
	JS_CFUNC_DEF("drawFps", 2, rl_draw_fps),
	JS_CFUNC_DEF("drawText", 5, rl_draw_text),
	#pragma endregion
};

// initialize as a QuickJS module

static int js_rl_init(JSContext *ctx, JSModuleDef *m)
{
	js_rl_init_classes(ctx, m);

	return JS_SetModuleExportList(ctx, m, js_rl_funcs, countof(js_rl_funcs));
}

JSModuleDef *js_init_module(JSContext *ctx, const char *module_name)
{
	JSModuleDef *m;
	m = JS_NewCModule(ctx, module_name, js_rl_init);
	
	if (!m)
		return NULL;
	
	JS_AddModuleExportList(ctx, m, js_rl_funcs, countof(js_rl_funcs));
	js_rl_init_module_classes(ctx, m);

	return m;
}
