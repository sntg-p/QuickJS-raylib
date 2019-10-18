#include "stdio.h"
#include "string.h"

#include "quickjs/quickjs.h"
#include "quickjs/cutils.h"
#include "raylib/raylib.h"

#pragma region Image class

static JSClassID js_rl_image_class_id;

static void js_rl_image_finalizer(JSRuntime *rt, JSValue val)
{
		Image* p = (Image*)JS_GetOpaque(val, js_rl_image_class_id);
		UnloadImage(*p);
}

static JSClassDef js_rl_image_class = {
		"Image",
		.finalizer = js_rl_image_finalizer,
};

static JSValue js_rl_image_get_width(JSContext *ctx, JSValueConst this_val)
{
	Image* p = (Image*)JS_GetOpaque2(ctx, this_val, js_rl_image_class_id);

	if (p)
		return JS_NewInt32(ctx, p->width);
	else
		return JS_EXCEPTION;
}

static JSValue js_rl_image_get_height(JSContext *ctx, JSValueConst this_val)
{
	Image* p = (Image*)JS_GetOpaque2(ctx, this_val, js_rl_image_class_id);

	if (p)
		return JS_NewInt32(ctx, p->height);
	else
		return JS_EXCEPTION;
}

static JSValue js_rl_image_get_format(JSContext *ctx, JSValueConst this_val)
{
	Image* p = (Image*)JS_GetOpaque2(ctx, this_val, js_rl_image_class_id);

	if (p)
		return JS_NewInt32(ctx, p->format);
	else
		return JS_EXCEPTION;
}

static JSValue js_rl_image_get_mipmaps(JSContext *ctx, JSValueConst this_val)
{
	Image* p = (Image*)JS_GetOpaque2(ctx, this_val, js_rl_image_class_id);

	if (p)
		return JS_NewInt32(ctx, p->mipmaps);
	else
		return JS_EXCEPTION;
}

static const JSCFunctionListEntry js_rl_image_proto_funcs[] = {
	JS_CGETSET_DEF("width", js_rl_image_get_width, NULL ),
	JS_CGETSET_DEF("height", js_rl_image_get_height, NULL ),
	JS_CGETSET_DEF("format", js_rl_image_get_format, NULL ),
	JS_CGETSET_DEF("mipmaps", js_rl_image_get_mipmaps, NULL ),
};

static void js_rl_init_image_class(JSContext *ctx, JSModuleDef *m)
{
	JSValue proto;
	JS_NewClassID(&js_rl_image_class_id);
	JS_NewClass(JS_GetRuntime(ctx), js_rl_image_class_id, &js_rl_image_class);
	proto = JS_NewObject(ctx);
	JS_SetPropertyFunctionList(ctx, proto, js_rl_image_proto_funcs, countof(js_rl_image_proto_funcs));
	JS_SetClassProto(ctx, js_rl_image_class_id, proto);
	// JS_NewCFunction2(ctx, js_rl_image_constructor, "Image", 1, JS_CFUNC_constructor, 0);
}

#pragma endregion

#pragma region Vector2

static JSClassID js_rl_vector2_class_id;

static JSClassDef js_rl_vector2_class = { "Vector2" };

static JSValue js_rl_vector2_get_x(JSContext *ctx, JSValueConst this_val)
{
		Vector2* p = (Vector2*)JS_GetOpaque2(ctx, this_val, js_rl_vector2_class_id);

		if (p)
			return JS_NewInt32(ctx, p->x);
		else
			return JS_EXCEPTION;
}

static JSValue js_rl_vector2_set_x(JSContext *ctx, JSValueConst this_val, JSValueConst v)
{
		Vector2* p = (Vector2*)JS_GetOpaque2(ctx, this_val, js_rl_vector2_class_id);

		if (!p)
			return JS_EXCEPTION;

		if (JS_IsUndefined(this_val) || JS_IsNull(this_val))
				return JS_UNDEFINED;
		if (JS_IsNull(v))
				return JS_UNDEFINED;
		
		int value;

		if (JS_ToInt32(ctx, &value, v))
			return JS_EXCEPTION;

		p->x = value;

		return JS_UNDEFINED;
}

static JSValue js_rl_vector2_get_y(JSContext *ctx, JSValueConst this_val)
{
		Vector2* p = (Vector2*)JS_GetOpaque2(ctx, this_val, js_rl_vector2_class_id);

		if (p)
			return JS_NewInt32(ctx, p->y);
		else
			return JS_EXCEPTION;
}

static JSValue js_rl_vector2_set_y(JSContext *ctx, JSValueConst this_val, JSValueConst v)
{
		Vector2* p = (Vector2*)JS_GetOpaque2(ctx, this_val, js_rl_vector2_class_id);

		if (!p)
			return JS_EXCEPTION;

		if (JS_IsUndefined(this_val) || JS_IsNull(this_val))
				return JS_UNDEFINED;
		if (JS_IsNull(v))
				return JS_UNDEFINED;
		
		int value;

		if (JS_ToInt32(ctx, &value, v))
			return JS_EXCEPTION;

		p->y = value;

		return JS_UNDEFINED;
}

static const JSCFunctionListEntry js_rl_vector2_proto_funcs[] = {
		JS_CGETSET_DEF("x", js_rl_vector2_get_x, js_rl_vector2_set_x ),
		JS_CGETSET_DEF("y", js_rl_vector2_get_y, js_rl_vector2_set_y ),
};

static JSValue js_rl_new_vector2(JSContext *ctx, int x, int y)
{
		JSValue obj = JS_NewObjectClass(ctx, js_rl_vector2_class_id);
		
		if (JS_IsException(obj))
			return obj;

		Vector2* p = js_mallocz(ctx, sizeof(Vector2));

		p->x = x;
		p->y = y;

		JS_SetOpaque(obj, p);

		return obj;
}

static JSValue js_rl_vector2_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv)
{
		int x, y;

		if (JS_ToInt32(ctx, &x, argv[0]))
				return JS_EXCEPTION;

		if (JS_ToInt32(ctx, &y, argv[1]))
			return JS_EXCEPTION;

		return js_rl_new_vector2(ctx, x, y);
}

static void js_rl_init_vector2_class(JSContext *ctx, JSModuleDef *m)
{
	JSValue proto, obj;
	JS_NewClassID(&js_rl_vector2_class_id);
	JS_NewClass(JS_GetRuntime(ctx), js_rl_vector2_class_id, &js_rl_vector2_class);
	proto = JS_NewObject(ctx);
	JS_SetPropertyFunctionList(ctx, proto, js_rl_vector2_proto_funcs, countof(js_rl_vector2_proto_funcs));
	JS_SetClassProto(ctx, js_rl_vector2_class_id, proto);

	obj = JS_NewCFunction2(ctx, js_rl_vector2_constructor, "Vector2", 2, JS_CFUNC_constructor, 0);
	JS_SetModuleExport(ctx, m, "Vector2", obj);
}

#pragma endregion

#pragma region Vector3

static JSClassID js_rl_vector3_class_id;

static JSClassDef js_rl_vector3_class = { "Vector3" };

static JSValue js_rl_vector3_get_x(JSContext *ctx, JSValueConst this_val)
{
		Vector3* p = (Vector3*)JS_GetOpaque2(ctx, this_val, js_rl_vector3_class_id);

		if (p)
			return JS_NewInt32(ctx, p->x);
		else
			return JS_EXCEPTION;
}

static JSValue js_rl_vector3_set_x(JSContext *ctx, JSValueConst this_val, JSValueConst v)
{
		Vector3* p = (Vector3*)JS_GetOpaque2(ctx, this_val, js_rl_vector3_class_id);

		if (!p)
			return JS_EXCEPTION;

		if (JS_IsUndefined(this_val) || JS_IsNull(this_val))
				return JS_UNDEFINED;
		if (JS_IsNull(v))
				return JS_UNDEFINED;
		
		int value;

		if (JS_ToInt32(ctx, &value, v))
			return JS_EXCEPTION;

		p->x = value;

		return JS_UNDEFINED;
}

static JSValue js_rl_vector3_get_y(JSContext *ctx, JSValueConst this_val)
{
		Vector3* p = (Vector3*)JS_GetOpaque2(ctx, this_val, js_rl_vector3_class_id);

		if (p)
			return JS_NewInt32(ctx, p->y);
		else
			return JS_EXCEPTION;
}

static JSValue js_rl_vector3_set_y(JSContext *ctx, JSValueConst this_val, JSValueConst v)
{
		Vector3* p = (Vector3*)JS_GetOpaque2(ctx, this_val, js_rl_vector3_class_id);

		if (!p)
			return JS_EXCEPTION;

		if (JS_IsUndefined(this_val) || JS_IsNull(this_val))
				return JS_UNDEFINED;
		if (JS_IsNull(v))
				return JS_UNDEFINED;
		
		int value;

		if (JS_ToInt32(ctx, &value, v))
			return JS_EXCEPTION;

		p->y = value;

		return JS_UNDEFINED;
}

static JSValue js_rl_vector3_get_z(JSContext *ctx, JSValueConst this_val)
{
		Vector3* p = (Vector3*)JS_GetOpaque2(ctx, this_val, js_rl_vector3_class_id);

		if (p)
			return JS_NewInt32(ctx, p->z);
		else
			return JS_EXCEPTION;
}

static JSValue js_rl_vector3_set_z(JSContext *ctx, JSValueConst this_val, JSValueConst v)
{
		Vector3* p = (Vector3*)JS_GetOpaque2(ctx, this_val, js_rl_vector3_class_id);

		if (!p)
			return JS_EXCEPTION;

		if (JS_IsUndefined(this_val) || JS_IsNull(this_val))
				return JS_UNDEFINED;
		if (JS_IsNull(v))
				return JS_UNDEFINED;
		
		int value;

		if (JS_ToInt32(ctx, &value, v))
			return JS_EXCEPTION;

		p->z = value;

		return JS_UNDEFINED;
}

static const JSCFunctionListEntry js_rl_vector3_proto_funcs[] = {
		JS_CGETSET_DEF("x", js_rl_vector3_get_x, js_rl_vector3_set_x),
		JS_CGETSET_DEF("y", js_rl_vector3_get_y, js_rl_vector3_set_y),
		JS_CGETSET_DEF("z", js_rl_vector3_get_z, js_rl_vector3_set_z),
};

static JSValue js_rl_new_vector3(JSContext *ctx, int x, int y, int z)
{
		JSValue obj = JS_NewObjectClass(ctx, js_rl_vector3_class_id);
		
		if (JS_IsException(obj))
			return obj;

		Vector3* p = js_mallocz(ctx, sizeof(Vector3));

		p->x = x;
		p->y = y;
		p->z = z;

		JS_SetOpaque(obj, p);
		
		return obj;
}

static JSValue js_rl_vector3_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv)
{
		int x, y, z;

		if (JS_ToInt32(ctx, &x, argv[0]))
				return JS_EXCEPTION;

		if (JS_ToInt32(ctx, &y, argv[1]))
			return JS_EXCEPTION;

		if (JS_ToInt32(ctx, &z, argv[2]))
			return JS_EXCEPTION;

		return js_rl_new_vector3(ctx, x, y, z);
}

static void js_rl_init_vector3_class(JSContext *ctx, JSModuleDef *m)
{
	JSValue proto, obj;
	JS_NewClassID(&js_rl_vector3_class_id);
	JS_NewClass(JS_GetRuntime(ctx), js_rl_vector3_class_id, &js_rl_vector3_class);
	proto = JS_NewObject(ctx);
	JS_SetPropertyFunctionList(ctx, proto, js_rl_vector3_proto_funcs, countof(js_rl_vector3_proto_funcs));
	JS_SetClassProto(ctx, js_rl_vector3_class_id, proto);

	obj = JS_NewCFunction2(ctx, js_rl_vector3_constructor, "Vector3", 3, JS_CFUNC_constructor, 0);
	JS_SetModuleExport(ctx, m, "Vector3", obj);
}

#pragma endregion

#pragma region Vector4

static JSClassID js_rl_vector4_class_id;

static JSClassDef js_rl_vector4_class = { "Vector4" };

static JSValue js_rl_vector4_get_x(JSContext *ctx, JSValueConst this_val)
{
		Vector4* p = (Vector4*)JS_GetOpaque2(ctx, this_val, js_rl_vector4_class_id);

		if (p)
			return JS_NewInt32(ctx, p->x);
		else
			return JS_EXCEPTION;
}

static JSValue js_rl_vector4_set_x(JSContext *ctx, JSValueConst this_val, JSValueConst v)
{
		Vector4* p = (Vector4*)JS_GetOpaque2(ctx, this_val, js_rl_vector4_class_id);

		if (!p)
			return JS_EXCEPTION;

		if (JS_IsUndefined(this_val) || JS_IsNull(this_val))
				return JS_UNDEFINED;
		if (JS_IsNull(v))
				return JS_UNDEFINED;
		
		int value;

		if (JS_ToInt32(ctx, &value, v))
			return JS_EXCEPTION;

		p->x = value;

		return JS_UNDEFINED;
}

static JSValue js_rl_vector4_get_y(JSContext *ctx, JSValueConst this_val)
{
		Vector4* p = (Vector4*)JS_GetOpaque2(ctx, this_val, js_rl_vector4_class_id);

		if (p)
			return JS_NewInt32(ctx, p->y);
		else
			return JS_EXCEPTION;
}

static JSValue js_rl_vector4_set_y(JSContext *ctx, JSValueConst this_val, JSValueConst v)
{
		Vector4* p = (Vector4*)JS_GetOpaque2(ctx, this_val, js_rl_vector4_class_id);

		if (!p)
			return JS_EXCEPTION;

		if (JS_IsUndefined(this_val) || JS_IsNull(this_val))
				return JS_UNDEFINED;
		if (JS_IsNull(v))
				return JS_UNDEFINED;
		
		int value;

		if (JS_ToInt32(ctx, &value, v))
			return JS_EXCEPTION;

		p->y = value;

		return JS_UNDEFINED;
}

static JSValue js_rl_vector4_get_z(JSContext *ctx, JSValueConst this_val)
{
		Vector4* p = (Vector4*)JS_GetOpaque2(ctx, this_val, js_rl_vector4_class_id);

		if (p)
			return JS_NewInt32(ctx, p->z);
		else
			return JS_EXCEPTION;
}

static JSValue js_rl_vector4_set_z(JSContext *ctx, JSValueConst this_val, JSValueConst v)
{
		Vector4* p = (Vector4*)JS_GetOpaque2(ctx, this_val, js_rl_vector4_class_id);

		if (!p)
			return JS_EXCEPTION;

		if (JS_IsUndefined(this_val) || JS_IsNull(this_val))
				return JS_UNDEFINED;
		if (JS_IsNull(v))
				return JS_UNDEFINED;
		
		int value;

		if (JS_ToInt32(ctx, &value, v))
			return JS_EXCEPTION;

		p->z = value;

		return JS_UNDEFINED;
}

static JSValue js_rl_vector4_get_w(JSContext *ctx, JSValueConst this_val)
{
		Vector4* p = (Vector4*)JS_GetOpaque2(ctx, this_val, js_rl_vector4_class_id);

		if (p)
			return JS_NewInt32(ctx, p->w);
		else
			return JS_EXCEPTION;
}

static JSValue js_rl_vector4_set_w(JSContext *ctx, JSValueConst this_val, JSValueConst v)
{
		Vector4* p = (Vector4*)JS_GetOpaque2(ctx, this_val, js_rl_vector4_class_id);

		if (!p)
			return JS_EXCEPTION;

		if (JS_IsUndefined(this_val) || JS_IsNull(this_val))
				return JS_UNDEFINED;
		if (JS_IsNull(v))
				return JS_UNDEFINED;
		
		int value;

		if (JS_ToInt32(ctx, &value, v))
			return JS_EXCEPTION;

		p->w = value;

		return JS_UNDEFINED;
}

static const JSCFunctionListEntry js_rl_vector4_proto_funcs[] = {
		JS_CGETSET_DEF("x", js_rl_vector4_get_x, js_rl_vector4_set_x),
		JS_CGETSET_DEF("y", js_rl_vector4_get_y, js_rl_vector4_set_y),
		JS_CGETSET_DEF("z", js_rl_vector4_get_z, js_rl_vector4_set_z),
		JS_CGETSET_DEF("w", js_rl_vector4_get_w, js_rl_vector4_set_w),
};

static JSValue js_rl_new_vector4(JSContext *ctx, int x, int y, int z, int w)
{
		JSValue obj = JS_NewObjectClass(ctx, js_rl_vector4_class_id);
		
		if (JS_IsException(obj))
			return obj;

		Vector4* p = js_mallocz(ctx, sizeof(Vector4));

		p->x = x;
		p->y = y;
		p->z = z;
		p->w = w;

		JS_SetOpaque(obj, p);
		
		return obj;
}

static JSValue js_rl_vector4_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv)
{
		int x, y, z, w;

		if (JS_ToInt32(ctx, &x, argv[0]))
				return JS_EXCEPTION;

		if (JS_ToInt32(ctx, &y, argv[1]))
			return JS_EXCEPTION;

		if (JS_ToInt32(ctx, &z, argv[2]))
			return JS_EXCEPTION;

		if (JS_ToInt32(ctx, &w, argv[3]))
			return JS_EXCEPTION;

		return js_rl_new_vector4(ctx, x, y, z, w);
}

static void js_rl_init_vector4_class(JSContext *ctx, JSModuleDef *m)
{
	JSValue proto, obj;
	JS_NewClassID(&js_rl_vector4_class_id);
	JS_NewClass(JS_GetRuntime(ctx), js_rl_vector4_class_id, &js_rl_vector4_class);
	proto = JS_NewObject(ctx);
	JS_SetPropertyFunctionList(ctx, proto, js_rl_vector4_proto_funcs, countof(js_rl_vector4_proto_funcs));
	JS_SetClassProto(ctx, js_rl_vector4_class_id, proto);

	obj = JS_NewCFunction2(ctx, js_rl_vector4_constructor, "Vector4", 4, JS_CFUNC_constructor, 0);
	JS_SetModuleExport(ctx, m, "Vector4", obj);
}

#pragma endregion

#pragma region Camera2D

static JSClassID js_rl_camera2d_class_id;

static JSClassDef js_rl_camera2d_class = { "Camera2D" };

static JSValue js_rl_camera2d_get_offset(JSContext *ctx, JSValueConst this_val)
{
		Camera2D* p = (Camera2D*)JS_GetOpaque2(ctx, this_val, js_rl_camera2d_class_id);

		if (p)
		{
			JSValue obj = JS_NewObject(ctx);
			JS_SetOpaque(obj, &p->offset);
			return obj;
		}
		else
			return JS_EXCEPTION;
}

static JSValue js_rl_camera2d_set_offset(JSContext *ctx, JSValueConst this_val, JSValueConst v)
{
		Camera2D* p = (Camera2D*)JS_GetOpaque2(ctx, this_val, js_rl_camera2d_class_id);

		if (!p)
			return JS_EXCEPTION;

		if (JS_IsUndefined(this_val) || JS_IsNull(this_val))
			return JS_UNDEFINED;
		if (JS_IsNull(v))
			return JS_UNDEFINED;

		p->offset = *(Vector2*)JS_GetOpaque2(ctx, v, js_rl_vector2_class_id);

		return JS_UNDEFINED;
}

static JSValue js_rl_camera2d_get_target(JSContext *ctx, JSValueConst this_val)
{
		Camera2D* p = (Camera2D*)JS_GetOpaque2(ctx, this_val, js_rl_camera2d_class_id);

		if (p)
		{
			JSValue obj = JS_NewObject(ctx);
			JS_SetOpaque(obj, &p->target);
			return obj;
		}
		else
			return JS_EXCEPTION;
}

static JSValue js_rl_camera2d_set_target(JSContext *ctx, JSValueConst this_val, JSValueConst v)
{
		Camera2D* p = (Camera2D*)JS_GetOpaque2(ctx, this_val, js_rl_camera2d_class_id);

		if (!p)
			return JS_EXCEPTION;

		if (JS_IsUndefined(this_val) || JS_IsNull(this_val))
			return JS_UNDEFINED;
		if (JS_IsNull(v))
			return JS_UNDEFINED;

		p->target = *(Vector2*)JS_GetOpaque2(ctx, v, js_rl_vector2_class_id);

		return JS_UNDEFINED;
}

static JSValue js_rl_camera2d_get_rotation(JSContext *ctx, JSValueConst this_val)
{
		Camera2D* p = (Camera2D*)JS_GetOpaque2(ctx, this_val, js_rl_camera2d_class_id);

		if (p)
			return JS_NewFloat64(ctx, p->rotation);
		else
			return JS_EXCEPTION;
}

static JSValue js_rl_camera2d_set_rotation(JSContext *ctx, JSValueConst this_val, JSValueConst v)
{
		Camera2D* p = (Camera2D*)JS_GetOpaque2(ctx, this_val, js_rl_camera2d_class_id);

		if (!p)
			return JS_EXCEPTION;

		if (JS_IsUndefined(this_val) || JS_IsNull(this_val))
				return JS_UNDEFINED;
		if (JS_IsNull(v))
				return JS_UNDEFINED;
		
		double value;

		if (JS_ToFloat64(ctx, &value, v))
			return JS_EXCEPTION;

		p->rotation = value;

		return JS_UNDEFINED;
}

static JSValue js_rl_camera2d_get_zoom(JSContext *ctx, JSValueConst this_val)
{
		Camera2D* p = (Camera2D*)JS_GetOpaque2(ctx, this_val, js_rl_camera2d_class_id);

		if (p)
			return JS_NewFloat64(ctx, p->zoom);
		else
			return JS_EXCEPTION;
}

static JSValue js_rl_camera2d_set_zoom(JSContext *ctx, JSValueConst this_val, JSValueConst v)
{
		Camera2D* p = (Camera2D*)JS_GetOpaque2(ctx, this_val, js_rl_camera2d_class_id);

		if (!p)
			return JS_EXCEPTION;

		if (JS_IsUndefined(this_val) || JS_IsNull(this_val))
				return JS_UNDEFINED;
		if (JS_IsNull(v))
				return JS_UNDEFINED;
		
		double value;

		if (JS_ToFloat64(ctx, &value, v))
			return JS_EXCEPTION;

		p->zoom = value;

		return JS_UNDEFINED;
}

static const JSCFunctionListEntry js_rl_camera2d_proto_funcs[] = {
		JS_CGETSET_DEF("offset", js_rl_camera2d_get_offset, js_rl_camera2d_set_offset),
		JS_CGETSET_DEF("target", js_rl_camera2d_get_target, js_rl_camera2d_set_target),
		JS_CGETSET_DEF("rotation", js_rl_camera2d_get_rotation, js_rl_camera2d_set_rotation),
		JS_CGETSET_DEF("zoom", js_rl_camera2d_get_zoom, js_rl_camera2d_set_zoom),
};

static JSValue js_rl_new_camera2d(JSContext *ctx, Vector2 offset, Vector2 target, double rotation, double zoom)
{
		JSValue obj = JS_NewObjectClass(ctx, js_rl_camera2d_class_id);
		
		if (JS_IsException(obj))
			return obj;

		Camera2D* p = js_mallocz(ctx, sizeof(Camera2D));

		p->offset = offset;
		p->target = target;
		p->rotation = rotation;
		p->zoom = zoom;

		JS_SetOpaque(obj, p);
		
		return obj;
}

static JSValue js_rl_camera2d_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv)
{
		Vector2* offset = (Vector2*)JS_GetOpaque2(ctx, argv[0], js_rl_camera2d_class_id);
		Vector2* target = (Vector2*)JS_GetOpaque2(ctx, argv[1], js_rl_camera2d_class_id);
		double rotation, zoom;

		if (JS_ToFloat64(ctx, &rotation, argv[2]))
			return JS_EXCEPTION;

		if (JS_ToFloat64(ctx, &zoom, argv[3]))
			return JS_EXCEPTION;

		return js_rl_new_camera2d(ctx, *offset, *target, rotation, zoom);
}

static void js_rl_init_camera2d_class(JSContext *ctx, JSModuleDef *m)
{
	JSValue proto, obj;
	JS_NewClassID(&js_rl_camera2d_class_id);
	JS_NewClass(JS_GetRuntime(ctx), js_rl_camera2d_class_id, &js_rl_camera2d_class);
	proto = JS_NewObject(ctx);
	JS_SetPropertyFunctionList(ctx, proto, js_rl_camera2d_proto_funcs, countof(js_rl_camera2d_proto_funcs));
	JS_SetClassProto(ctx, js_rl_camera2d_class_id, proto);

	obj = JS_NewCFunction2(ctx, js_rl_camera2d_constructor, "Camera2D", 4, JS_CFUNC_constructor, 0);
	JS_SetModuleExport(ctx, m, "Camera2D", obj);
}

#pragma endregion

#pragma region Camera3D

static JSClassID js_rl_camera3d_class_id;

static JSClassDef js_rl_camera3d_class = { "Camera3D" };

static JSValue js_rl_camera3d_get_position(JSContext *ctx, JSValueConst this_val)
{
		Camera3D* p = (Camera3D*)JS_GetOpaque2(ctx, this_val, js_rl_camera3d_class_id);

		if (p)
		{
			JSValue obj = JS_NewObject(ctx);
			JS_SetOpaque(obj, &p->position);
			return obj;
		}
		else
			return JS_EXCEPTION;
}

static JSValue js_rl_camera3d_set_position(JSContext *ctx, JSValueConst this_val, JSValueConst v)
{
		Camera3D* p = (Camera3D*)JS_GetOpaque2(ctx, this_val, js_rl_camera3d_class_id);

		if (!p)
			return JS_EXCEPTION;

		if (JS_IsUndefined(this_val) || JS_IsNull(this_val))
			return JS_UNDEFINED;
		if (JS_IsNull(v))
			return JS_UNDEFINED;

		p->position = *(Vector3*)JS_GetOpaque2(ctx, v, js_rl_vector3_class_id);

		return JS_UNDEFINED;
}

static JSValue js_rl_camera3d_get_target(JSContext *ctx, JSValueConst this_val)
{
		Camera3D* p = (Camera3D*)JS_GetOpaque2(ctx, this_val, js_rl_camera3d_class_id);

		if (p)
		{
			JSValue obj = JS_NewObject(ctx);
			JS_SetOpaque(obj, &p->target);
			return obj;
		}
		else
			return JS_EXCEPTION;
}

static JSValue js_rl_camera3d_set_target(JSContext *ctx, JSValueConst this_val, JSValueConst v)
{
		Camera3D* p = (Camera3D*)JS_GetOpaque2(ctx, this_val, js_rl_camera3d_class_id);

		if (!p)
			return JS_EXCEPTION;

		if (JS_IsUndefined(this_val) || JS_IsNull(this_val))
			return JS_UNDEFINED;
		if (JS_IsNull(v))
			return JS_UNDEFINED;

		p->target = *(Vector3*)JS_GetOpaque2(ctx, v, js_rl_vector3_class_id);

		return JS_UNDEFINED;
}

static JSValue js_rl_camera3d_get_up(JSContext *ctx, JSValueConst this_val)
{
		Camera3D* p = (Camera3D*)JS_GetOpaque2(ctx, this_val, js_rl_camera3d_class_id);

		if (p)
		{
			JSValue obj = JS_NewObject(ctx);
			JS_SetOpaque(obj, &p->up);
			return obj;
		}
		else
			return JS_EXCEPTION;
}

static JSValue js_rl_camera3d_set_up(JSContext *ctx, JSValueConst this_val, JSValueConst v)
{
		Camera3D* p = (Camera3D*)JS_GetOpaque2(ctx, this_val, js_rl_camera3d_class_id);

		if (!p)
			return JS_EXCEPTION;

		if (JS_IsUndefined(this_val) || JS_IsNull(this_val))
			return JS_UNDEFINED;
		if (JS_IsNull(v))
			return JS_UNDEFINED;

		p->up = *(Vector3*)JS_GetOpaque2(ctx, v, js_rl_vector3_class_id);

		return JS_UNDEFINED;
}

static JSValue js_rl_camera3d_get_fov_y(JSContext *ctx, JSValueConst this_val)
{
		Camera3D* p = (Camera3D*)JS_GetOpaque2(ctx, this_val, js_rl_camera3d_class_id);

		if (p)
			return JS_NewFloat64(ctx, p->fovy);
		else
			return JS_EXCEPTION;
}

static JSValue js_rl_camera3d_set_fov_y(JSContext *ctx, JSValueConst this_val, JSValueConst v)
{
		Camera3D* p = (Camera3D*)JS_GetOpaque2(ctx, this_val, js_rl_camera3d_class_id);

		if (!p)
			return JS_EXCEPTION;

		if (JS_IsUndefined(this_val) || JS_IsNull(this_val))
				return JS_UNDEFINED;
		if (JS_IsNull(v))
				return JS_UNDEFINED;
		
		double value;

		if (JS_ToFloat64(ctx, &value, v))
			return JS_EXCEPTION;

		p->fovy = value;

		return JS_UNDEFINED;
}

static JSValue js_rl_camera3d_get_type(JSContext *ctx, JSValueConst this_val)
{
		Camera3D* p = (Camera3D*)JS_GetOpaque2(ctx, this_val, js_rl_camera3d_class_id);

		if (p)
			return JS_NewInt32(ctx, p->type);
		else
			return JS_EXCEPTION;
}

static JSValue js_rl_camera3d_set_type(JSContext *ctx, JSValueConst this_val, JSValueConst v)
{
		Camera3D* p = (Camera3D*)JS_GetOpaque2(ctx, this_val, js_rl_camera3d_class_id);

		if (!p)
			return JS_EXCEPTION;

		if (JS_IsUndefined(this_val) || JS_IsNull(this_val))
				return JS_UNDEFINED;
		if (JS_IsNull(v))
				return JS_UNDEFINED;
		
		int value;

		if (JS_ToInt32(ctx, &value, v))
			return JS_EXCEPTION;

		p->type = value;

		return JS_UNDEFINED;
}

static const JSCFunctionListEntry js_rl_camera3d_proto_funcs[] = {
		JS_CGETSET_DEF("position", js_rl_camera3d_get_position, js_rl_camera3d_set_position),
		JS_CGETSET_DEF("target", js_rl_camera3d_get_target, js_rl_camera3d_set_target),
		JS_CGETSET_DEF("up", js_rl_camera3d_get_up, js_rl_camera3d_set_up),
		JS_CGETSET_DEF("fovY", js_rl_camera3d_get_fov_y, js_rl_camera3d_set_fov_y),
		JS_CGETSET_DEF("type", js_rl_camera3d_get_type, js_rl_camera3d_set_type),
};

static JSValue js_rl_new_camera3d(JSContext *ctx, Vector3 position, Vector3 target, Vector3 up, double fovy, int type)
{
		JSValue obj = JS_NewObjectClass(ctx, js_rl_camera3d_class_id);
		
		if (JS_IsException(obj))
			return obj;

		Camera3D* p = js_mallocz(ctx, sizeof(Camera3D));

		p->position = position;
		p->target = target;
		p->up = up;
		p->fovy = fovy;
		p->type = type;

		JS_SetOpaque(obj, p);
		
		return obj;
}

static JSValue js_rl_camera3d_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv)
{
		Vector3* position = (Vector3*)JS_GetOpaque2(ctx, argv[0], js_rl_camera3d_class_id);
		Vector3* target = (Vector3*)JS_GetOpaque2(ctx, argv[1], js_rl_camera3d_class_id);
		Vector3* up = (Vector3*)JS_GetOpaque2(ctx, argv[3], js_rl_camera3d_class_id);
		double fovy;
		int type;

		JS_ToFloat64(ctx, &fovy, argv[4]);
		JS_ToInt32(ctx, &type, argv[5]);

		return js_rl_new_camera3d(ctx, *position, *target, *up, fovy, type);
}

static void js_rl_init_camera3d_class(JSContext *ctx, JSModuleDef *m)
{
	JSValue proto, obj;
	JS_NewClassID(&js_rl_camera3d_class_id);
	JS_NewClass(JS_GetRuntime(ctx), js_rl_camera3d_class_id, &js_rl_camera3d_class);
	proto = JS_NewObject(ctx);
	JS_SetPropertyFunctionList(ctx, proto, js_rl_camera3d_proto_funcs, countof(js_rl_camera3d_proto_funcs));
	JS_SetClassProto(ctx, js_rl_camera3d_class_id, proto);

	obj = JS_NewCFunction2(ctx, js_rl_camera3d_constructor, "Camera3D", 4, JS_CFUNC_constructor, 0);
	JS_SetModuleExport(ctx, m, "Camera3D", obj);
}

#pragma endregion

#pragma region Texture2D class

static JSClassID js_rl_texture2d_class_id;

static void js_rl_texture2d_finalizer(JSRuntime *rt, JSValue val)
{
		Texture2D* p = (Texture2D*)JS_GetOpaque(val, js_rl_texture2d_class_id);
		UnloadTexture(*p);
}

static JSClassDef js_rl_texture2d_class = {
		"Texture2D",
		.finalizer = js_rl_texture2d_finalizer,
};

static JSValue js_rl_texture2d_get_id(JSContext *ctx, JSValueConst this_val)
{
	Texture2D* p = (Texture2D*)JS_GetOpaque2(ctx, this_val, js_rl_texture2d_class_id);

	if (p)
		return JS_NewInt32(ctx, p->id);
	else
		return JS_EXCEPTION;
}

static JSValue js_rl_texture2d_get_width(JSContext *ctx, JSValueConst this_val)
{
	Texture2D* p = (Texture2D*)JS_GetOpaque2(ctx, this_val, js_rl_texture2d_class_id);

	if (p)
		return JS_NewInt32(ctx, p->width);
	else
		return JS_EXCEPTION;
}

static JSValue js_rl_texture2d_get_height(JSContext *ctx, JSValueConst this_val)
{
	Texture2D* p = (Texture2D*)JS_GetOpaque2(ctx, this_val, js_rl_texture2d_class_id);

	if (p)
		return JS_NewInt32(ctx, p->height);
	else
		return JS_EXCEPTION;
}

static JSValue js_rl_texture2d_get_format(JSContext *ctx, JSValueConst this_val)
{
	Texture2D* p = (Texture2D*)JS_GetOpaque2(ctx, this_val, js_rl_texture2d_class_id);

	if (p)
		return JS_NewInt32(ctx, p->format);
	else
		return JS_EXCEPTION;
}

static JSValue js_rl_texture2d_get_mipmaps(JSContext *ctx, JSValueConst this_val)
{
	Texture2D* p = (Texture2D*)JS_GetOpaque2(ctx, this_val, js_rl_texture2d_class_id);

	if (p)
		return JS_NewInt32(ctx, p->mipmaps);
	else
		return JS_EXCEPTION;
}

static const JSCFunctionListEntry js_rl_texture2d_proto_funcs[] = {
	JS_CGETSET_DEF("id", js_rl_texture2d_get_id, NULL ),
	JS_CGETSET_DEF("width", js_rl_texture2d_get_width, NULL ),
	JS_CGETSET_DEF("height", js_rl_texture2d_get_height, NULL ),
	JS_CGETSET_DEF("format", js_rl_texture2d_get_format, NULL ),
	JS_CGETSET_DEF("mipmaps", js_rl_texture2d_get_mipmaps, NULL ),
};

static void js_rl_init_texture2d_class(JSContext *ctx, JSModuleDef *m)
{
	JSValue proto;
	JS_NewClassID(&js_rl_texture2d_class_id);
	JS_NewClass(JS_GetRuntime(ctx), js_rl_texture2d_class_id, &js_rl_texture2d_class);
	proto = JS_NewObject(ctx);
	JS_SetPropertyFunctionList(ctx, proto, js_rl_texture2d_proto_funcs, countof(js_rl_texture2d_proto_funcs));
	JS_SetClassProto(ctx, js_rl_texture2d_class_id, proto);
}

#pragma endregion

#pragma region RenderTexture

static JSClassID js_rl_render_texture_class_id;

static void js_rl_render_texture_finalizer(JSRuntime *rt, JSValue val)
{
		RenderTexture* p = (RenderTexture*)JS_GetOpaque(val, js_rl_render_texture_class_id);
		UnloadRenderTexture(*p);
}

static JSClassDef js_rl_render_texture_class =
{
	"RenderTexture2D",
	.finalizer = js_rl_render_texture_finalizer,
};

static JSValue js_rl_render_texture_get_id(JSContext *ctx, JSValueConst this_val)
{
		RenderTexture2D* p = (RenderTexture2D*)JS_GetOpaque2(ctx, this_val, js_rl_render_texture_class_id);

		if (p)
			return JS_NewInt32(ctx, p->id);
		else
			return JS_EXCEPTION;
}

static JSValue js_rl_render_texture_set_id(JSContext *ctx, JSValueConst this_val, JSValueConst v)
{
		RenderTexture2D* p = (RenderTexture2D*)JS_GetOpaque2(ctx, this_val, js_rl_render_texture_class_id);

		if (!p)
			return JS_EXCEPTION;

		if (JS_IsUndefined(this_val) || JS_IsNull(this_val))
				return JS_UNDEFINED;
		if (JS_IsNull(v))
				return JS_UNDEFINED;
		
		int value;

		if (JS_ToInt32(ctx, &value, v))
			return JS_EXCEPTION;

		p->id = value;

		return JS_UNDEFINED;
}

static JSValue js_rl_render_texture_get_texture(JSContext *ctx, JSValueConst this_val)
{
		RenderTexture2D* p = (RenderTexture2D*)JS_GetOpaque2(ctx, this_val, js_rl_render_texture_class_id);

		if (p)
		{
			JSValue obj = JS_NewObjectClass(ctx, js_rl_texture2d_class_id);
			if (!JS_IsException(obj))
				JS_SetOpaque(obj, &p->texture);
			return obj;
		}
		else
			return JS_EXCEPTION;
}

static JSValue js_rl_render_texture_set_texture(JSContext *ctx, JSValueConst this_val, JSValueConst v)
{
		RenderTexture2D* p = (RenderTexture2D*)JS_GetOpaque2(ctx, this_val, js_rl_render_texture_class_id);

		if (!p)
			return JS_EXCEPTION;

		if (JS_IsUndefined(this_val) || JS_IsNull(this_val))
				return JS_UNDEFINED;
		if (JS_IsNull(v))
				return JS_UNDEFINED;

		Texture value = *(Texture*)JS_GetOpaque2(ctx, v, js_rl_texture2d_class_id);
		p->texture = value;

		return JS_UNDEFINED;
}

static JSValue js_rl_render_texture_get_depth(JSContext *ctx, JSValueConst this_val)
{
		RenderTexture2D* p = (RenderTexture2D*)JS_GetOpaque2(ctx, this_val, js_rl_render_texture_class_id);

		if (p)
		{
			JSValue obj = JS_NewObjectClass(ctx, js_rl_texture2d_class_id);
			if (!JS_IsException(obj))
				JS_SetOpaque(obj, &p->depth);
			return obj;
		}
		else
			return JS_EXCEPTION;
}

static JSValue js_rl_render_texture_set_depth(JSContext *ctx, JSValueConst this_val, JSValueConst v)
{
		RenderTexture2D* p = (RenderTexture2D*)JS_GetOpaque2(ctx, this_val, js_rl_render_texture_class_id);

		if (!p)
			return JS_EXCEPTION;

		if (JS_IsUndefined(this_val) || JS_IsNull(this_val))
				return JS_UNDEFINED;
		if (JS_IsNull(v))
				return JS_UNDEFINED;

		Texture value = *(Texture*)JS_GetOpaque2(ctx, v, js_rl_texture2d_class_id);
		p->depth = value;

		return JS_UNDEFINED;
}

static JSValue js_rl_render_texture_get_depth_texture(JSContext *ctx, JSValueConst this_val)
{
		RenderTexture2D* p = (RenderTexture2D*)JS_GetOpaque2(ctx, this_val, js_rl_render_texture_class_id);

		if (p)
			return JS_NewBool(ctx, p->depthTexture);
		else
			return JS_EXCEPTION;
}

static JSValue js_rl_render_texture_set_depth_texture(JSContext *ctx, JSValueConst this_val, JSValueConst v)
{
		RenderTexture2D* p = (RenderTexture2D*)JS_GetOpaque2(ctx, this_val, js_rl_render_texture_class_id);

		if (!p)
			return JS_EXCEPTION;

		if (JS_IsUndefined(this_val) || JS_IsNull(this_val))
				return JS_UNDEFINED;
		if (JS_IsNull(v))
				return JS_UNDEFINED;
		
		bool value = JS_ToBool(ctx, v);

		p->depthTexture = value;

		return JS_UNDEFINED;
}

static const JSCFunctionListEntry js_rl_render_texture_proto_funcs[] = {
		JS_CGETSET_DEF("x", js_rl_render_texture_get_id, js_rl_render_texture_set_id),
		JS_CGETSET_DEF("y", js_rl_render_texture_get_texture, js_rl_render_texture_set_texture),
		JS_CGETSET_DEF("z", js_rl_render_texture_get_depth, js_rl_render_texture_set_depth),
		JS_CGETSET_DEF("w", js_rl_render_texture_get_depth_texture, js_rl_render_texture_set_depth_texture),
};

static JSValue js_rl_render_texture_constructor(JSContext *ctx, JSValueConst new_target, int argc, JSValueConst *argv)
{
	JSValue obj = JS_NewObjectClass(ctx, js_rl_render_texture_class_id);

	int w, h;

	if (JS_ToInt32(ctx, &w, argv[0]))
		return JS_EXCEPTION;

	if (JS_ToInt32(ctx, &h, argv[1]))
		return JS_EXCEPTION;

	RenderTexture2D* p = js_mallocz(ctx, sizeof(RenderTexture2D));
	RenderTexture2D rt = LoadRenderTexture(w, h);

	if (!p) {
		JS_FreeValue(ctx, obj);
		return JS_EXCEPTION;
	}

	memcpy(p, &rt, sizeof(rt));

	JS_SetOpaque(obj, p);

	return obj;
}

static void js_rl_init_render_texture_class(JSContext *ctx, JSModuleDef *m)
{
	JSValue proto, obj;
	JS_NewClassID(&js_rl_render_texture_class_id);
	JS_NewClass(JS_GetRuntime(ctx), js_rl_render_texture_class_id, &js_rl_render_texture_class);
	proto = JS_NewObject(ctx);
	JS_SetPropertyFunctionList(ctx, proto, js_rl_render_texture_proto_funcs, countof(js_rl_render_texture_proto_funcs));
	JS_SetClassProto(ctx, js_rl_render_texture_class_id, proto);

	obj = JS_NewCFunction2(ctx, js_rl_render_texture_constructor, "RenderTexture2D", 2, JS_CFUNC_constructor, 0);
	JS_SetModuleExport(ctx, m, "RenderTexture2D", obj);
}

#pragma endregion

static void js_rl_init_classes(JSContext *ctx, JSModuleDef *m)
{
	js_rl_init_image_class(ctx, m);
	js_rl_init_vector2_class(ctx, m);
	js_rl_init_vector3_class(ctx, m);
	js_rl_init_vector4_class(ctx, m);
	js_rl_init_camera2d_class(ctx, m);
	js_rl_init_camera3d_class(ctx, m);
	js_rl_init_texture2d_class(ctx, m);
	js_rl_init_render_texture_class(ctx, m);
}

static void js_rl_init_module_classes(JSContext *ctx, JSModuleDef *m)
{
	JS_AddModuleExport(ctx, m, "Vector2");
	JS_AddModuleExport(ctx, m, "Vector3");
	JS_AddModuleExport(ctx, m, "Vector4");
	JS_AddModuleExport(ctx, m, "Camera2D");
	JS_AddModuleExport(ctx, m, "Camera3D");
	JS_AddModuleExport(ctx, m, "Texture2D");
	JS_AddModuleExport(ctx, m, "RenderTexture2D");
}
