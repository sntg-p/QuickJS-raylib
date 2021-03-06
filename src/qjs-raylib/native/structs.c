#include "structs.h"

#pragma region Image

void js_rl_image_finalizer(JSRuntime* rt, JSValue val)
{
	Image* p = (Image*)JS_GetOpaque(val, js_rl_image_class_id);
	UnloadImage(*p);
}

JSClassDef js_rl_image_class =
{
	"Image",
	.finalizer = js_rl_image_finalizer,
};

JSValue js_rl_image_get_width(JSContext* ctx, JSValueConst this_val)
{
	Image* p = (Image*)JS_GetOpaque2(ctx, this_val, js_rl_image_class_id);

	if (p)
		return JS_NewInt32(ctx, p->width);
	else
		return JS_EXCEPTION;
}

JSValue js_rl_image_get_height(JSContext* ctx, JSValueConst this_val)
{
	Image* p = (Image*)JS_GetOpaque2(ctx, this_val, js_rl_image_class_id);

	if (p)
		return JS_NewInt32(ctx, p->height);
	else
		return JS_EXCEPTION;
}

JSValue js_rl_image_get_format(JSContext* ctx, JSValueConst this_val)
{
	Image* p = (Image*)JS_GetOpaque2(ctx, this_val, js_rl_image_class_id);

	if (p)
		return JS_NewInt32(ctx, p->format);
	else
		return JS_EXCEPTION;
}

JSValue js_rl_image_get_mipmaps(JSContext* ctx, JSValueConst this_val)
{
	Image* p = (Image*)JS_GetOpaque2(ctx, this_val, js_rl_image_class_id);

	if (p)
		return JS_NewInt32(ctx, p->mipmaps);
	else
		return JS_EXCEPTION;
}

const JSCFunctionListEntry js_rl_image_proto_funcs[] =
{
	JS_CGETSET_DEF("width", js_rl_image_get_width, NULL),
	JS_CGETSET_DEF("height", js_rl_image_get_height, NULL),
	JS_CGETSET_DEF("format", js_rl_image_get_format, NULL),
	JS_CGETSET_DEF("mipmaps", js_rl_image_get_mipmaps, NULL),
};

void js_rl_init_image_class(JSContext* ctx, JSModuleDef* m)
{
	JSValue proto;
	JS_NewClassID(&js_rl_image_class_id);
	JS_NewClass(JS_GetRuntime(ctx), js_rl_image_class_id, &js_rl_image_class);
	proto = JS_NewObject(ctx);
	JS_SetPropertyFunctionList(ctx, proto, js_rl_image_proto_funcs, countof(js_rl_image_proto_funcs));
	JS_SetClassProto(ctx, js_rl_image_class_id, proto);
	// JS_NewCFunction2(ctx, js_rl_image_constructor, "Image", 1, JS_CFUNC_constructor_or_func, 0);
}

#pragma endregion
#pragma region Vector2

JSClassDef js_rl_vector2_class = { "Vector2" };

JSValue js_rl_vector2_get_x(JSContext* ctx, JSValueConst this_val)
{
	Vector2* p = (Vector2*)JS_GetOpaque2(ctx, this_val, js_rl_vector2_class_id);

	if (p)
		return JS_NewFloat64(ctx, p->x);
	else
		return JS_EXCEPTION;
}

JSValue js_rl_vector2_set_x(JSContext* ctx, JSValueConst this_val, JSValueConst v)
{
	Vector2* p = (Vector2*)JS_GetOpaque2(ctx, this_val, js_rl_vector2_class_id);

	if (!p)
		return JS_EXCEPTION;

	if (JS_IsUndefined(this_val) || JS_IsNull(this_val))
		return JS_UNDEFINED;
	if (JS_IsNull(v))
		return JS_UNDEFINED;

	double value;

	if (JS_ToFloat64(ctx, &value, v))
		return JS_EXCEPTION;

	p->x = value;

	return JS_UNDEFINED;
}

JSValue js_rl_vector2_get_y(JSContext* ctx, JSValueConst this_val)
{
	Vector2* p = (Vector2*)JS_GetOpaque2(ctx, this_val, js_rl_vector2_class_id);

	if (p)
		return JS_NewFloat64(ctx, p->y);
	else
		return JS_EXCEPTION;
}

JSValue js_rl_vector2_set_y(JSContext* ctx, JSValueConst this_val, JSValueConst v)
{
	Vector2* p = (Vector2*)JS_GetOpaque2(ctx, this_val, js_rl_vector2_class_id);

	if (!p)
		return JS_EXCEPTION;

	if (JS_IsUndefined(this_val) || JS_IsNull(this_val))
		return JS_UNDEFINED;
	if (JS_IsNull(v))
		return JS_UNDEFINED;

	double value;

	if (JS_ToFloat64(ctx, &value, v))
		return JS_EXCEPTION;

	p->y = value;

	return JS_UNDEFINED;
}

JSValue js_rl_new_vector2(JSContext* ctx, double x, double y)
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

JSValue js_rl_vector2_constructor(JSContext* ctx, JSValueConst new_target, int argc, JSValueConst *argv)
{
	double x, y;

	if (JS_ToFloat64(ctx, &x, argv[0]))
		return JS_EXCEPTION;

	if (JS_ToFloat64(ctx, &y, argv[1]))
		return JS_EXCEPTION;

	return js_rl_new_vector2(ctx, x, y);
}

const JSCFunctionListEntry js_rl_vector2_proto_funcs[] =
{
	JS_CGETSET_DEF("x", js_rl_vector2_get_x, js_rl_vector2_set_x),
	JS_CGETSET_DEF("y", js_rl_vector2_get_y, js_rl_vector2_set_y),
};

void js_rl_init_vector2_class(JSContext* ctx, JSModuleDef* m)
{
	JSValue proto, obj;
	JS_NewClassID(&js_rl_vector2_class_id);
	JS_NewClass(JS_GetRuntime(ctx), js_rl_vector2_class_id, &js_rl_vector2_class);
	proto = JS_NewObject(ctx);
	JS_SetPropertyFunctionList(ctx, proto, js_rl_vector2_proto_funcs, countof(js_rl_vector2_proto_funcs));
	JS_SetClassProto(ctx, js_rl_vector2_class_id, proto);

	obj = JS_NewCFunction2(ctx, js_rl_vector2_constructor, "Vector2", 2, JS_CFUNC_constructor_or_func, 0);
	JS_SetModuleExport(ctx, m, "Vector2", obj);
}

#pragma endregion
#pragma region Vector3

JSClassDef js_rl_vector3_class = { "Vector3" };

JSValue js_rl_vector3_get_x(JSContext* ctx, JSValueConst this_val)
{
	Vector3* p = (Vector3*)JS_GetOpaque2(ctx, this_val, js_rl_vector3_class_id);

	if (p)
		return JS_NewFloat64(ctx, p->x);
	else
		return JS_EXCEPTION;
}

JSValue js_rl_vector3_set_x(JSContext* ctx, JSValueConst this_val, JSValueConst v)
{
	Vector3* p = (Vector3*)JS_GetOpaque2(ctx, this_val, js_rl_vector3_class_id);

	if (!p)
		return JS_EXCEPTION;

	if (JS_IsUndefined(this_val) || JS_IsNull(this_val))
		return JS_UNDEFINED;
	if (JS_IsNull(v))
		return JS_UNDEFINED;

	double value;

	if (JS_ToFloat64(ctx, &value, v))
		return JS_EXCEPTION;

	p->x = value;

	return JS_UNDEFINED;
}

JSValue js_rl_vector3_get_y(JSContext* ctx, JSValueConst this_val)
{
	Vector3* p = (Vector3*)JS_GetOpaque2(ctx, this_val, js_rl_vector3_class_id);

	if (p)
		return JS_NewFloat64(ctx, p->y);
	else
		return JS_EXCEPTION;
}

JSValue js_rl_vector3_set_y(JSContext* ctx, JSValueConst this_val, JSValueConst v)
{
	Vector3* p = (Vector3*)JS_GetOpaque2(ctx, this_val, js_rl_vector3_class_id);

	if (!p)
		return JS_EXCEPTION;

	if (JS_IsUndefined(this_val) || JS_IsNull(this_val))
		return JS_UNDEFINED;
	if (JS_IsNull(v))
		return JS_UNDEFINED;

	double value;

	if (JS_ToFloat64(ctx, &value, v))
		return JS_EXCEPTION;

	p->y = value;

	return JS_UNDEFINED;
}

JSValue js_rl_vector3_get_z(JSContext* ctx, JSValueConst this_val)
{
	Vector3* p = (Vector3*)JS_GetOpaque2(ctx, this_val, js_rl_vector3_class_id);

	if (p)
		return JS_NewFloat64(ctx, p->z);
	else
		return JS_EXCEPTION;
}

JSValue js_rl_vector3_set_z(JSContext* ctx, JSValueConst this_val, JSValueConst v)
{
	Vector3* p = (Vector3*)JS_GetOpaque2(ctx, this_val, js_rl_vector3_class_id);

	if (!p)
		return JS_EXCEPTION;

	if (JS_IsUndefined(this_val) || JS_IsNull(this_val))
		return JS_UNDEFINED;
	if (JS_IsNull(v))
		return JS_UNDEFINED;

	double value;

	if (JS_ToFloat64(ctx, &value, v))
		return JS_EXCEPTION;

	p->z = value;

	return JS_UNDEFINED;
}

JSValue js_rl_new_vector3(JSContext* ctx, int x, int y, int z)
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

JSValue js_rl_vector3_constructor(JSContext* ctx, JSValueConst new_target, int argc, JSValueConst *argv)
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

const JSCFunctionListEntry js_rl_vector3_proto_funcs[] =
{
	JS_CGETSET_DEF("x", js_rl_vector3_get_x, js_rl_vector3_set_x),
	JS_CGETSET_DEF("y", js_rl_vector3_get_y, js_rl_vector3_set_y),
	JS_CGETSET_DEF("z", js_rl_vector3_get_z, js_rl_vector3_set_z),
};

void js_rl_init_vector3_class(JSContext* ctx, JSModuleDef* m)
{
	JSValue proto, obj;
	JS_NewClassID(&js_rl_vector3_class_id);
	JS_NewClass(JS_GetRuntime(ctx), js_rl_vector3_class_id, &js_rl_vector3_class);
	proto = JS_NewObject(ctx);
	JS_SetPropertyFunctionList(ctx, proto, js_rl_vector3_proto_funcs, countof(js_rl_vector3_proto_funcs));
	JS_SetClassProto(ctx, js_rl_vector3_class_id, proto);

	obj = JS_NewCFunction2(ctx, js_rl_vector3_constructor, "Vector3", 3, JS_CFUNC_constructor_or_func, 0);
	JS_SetModuleExport(ctx, m, "Vector3", obj);
}

#pragma endregion
#pragma region Vector4

JSClassDef js_rl_vector4_class = { "Vector4" };

JSValue js_rl_vector4_get_x(JSContext* ctx, JSValueConst this_val)
{
	Vector4* p = (Vector4*)JS_GetOpaque2(ctx, this_val, js_rl_vector4_class_id);

	if (p)
		return JS_NewFloat64(ctx, p->x);
	else
		return JS_EXCEPTION;
}

JSValue js_rl_vector4_set_x(JSContext* ctx, JSValueConst this_val, JSValueConst v)
{
	Vector4* p = (Vector4*)JS_GetOpaque2(ctx, this_val, js_rl_vector4_class_id);

	if (!p)
		return JS_EXCEPTION;

	if (JS_IsUndefined(this_val) || JS_IsNull(this_val))
		return JS_UNDEFINED;
	if (JS_IsNull(v))
		return JS_UNDEFINED;

	double value;

	if (JS_ToFloat64(ctx, &value, v))
		return JS_EXCEPTION;

	p->x = value;

	return JS_UNDEFINED;
}

JSValue js_rl_vector4_get_y(JSContext* ctx, JSValueConst this_val)
{
	Vector4* p = (Vector4*)JS_GetOpaque2(ctx, this_val, js_rl_vector4_class_id);

	if (p)
		return JS_NewFloat64(ctx, p->y);
	else
		return JS_EXCEPTION;
}

JSValue js_rl_vector4_set_y(JSContext* ctx, JSValueConst this_val, JSValueConst v)
{
	Vector4* p = (Vector4*)JS_GetOpaque2(ctx, this_val, js_rl_vector4_class_id);

	if (!p)
		return JS_EXCEPTION;

	if (JS_IsUndefined(this_val) || JS_IsNull(this_val))
		return JS_UNDEFINED;
	if (JS_IsNull(v))
		return JS_UNDEFINED;

	double value;

	if (JS_ToFloat64(ctx, &value, v))
		return JS_EXCEPTION;

	p->y = value;

	return JS_UNDEFINED;
}

JSValue js_rl_vector4_get_z(JSContext* ctx, JSValueConst this_val)
{
	Vector4* p = (Vector4*)JS_GetOpaque2(ctx, this_val, js_rl_vector4_class_id);

	if (p)
		return JS_NewFloat64(ctx, p->z);
	else
		return JS_EXCEPTION;
}

JSValue js_rl_vector4_set_z(JSContext* ctx, JSValueConst this_val, JSValueConst v)
{
	Vector4* p = (Vector4*)JS_GetOpaque2(ctx, this_val, js_rl_vector4_class_id);

	if (!p)
		return JS_EXCEPTION;

	if (JS_IsUndefined(this_val) || JS_IsNull(this_val))
		return JS_UNDEFINED;
	if (JS_IsNull(v))
		return JS_UNDEFINED;

	double value;

	if (JS_ToFloat64(ctx, &value, v))
		return JS_EXCEPTION;

	p->z = value;

	return JS_UNDEFINED;
}

JSValue js_rl_vector4_get_w(JSContext* ctx, JSValueConst this_val)
{
	Vector4* p = (Vector4*)JS_GetOpaque2(ctx, this_val, js_rl_vector4_class_id);

	if (p)
		return JS_NewFloat64(ctx, p->w);
	else
		return JS_EXCEPTION;
}

JSValue js_rl_vector4_set_w(JSContext* ctx, JSValueConst this_val, JSValueConst v)
{
	Vector4* p = (Vector4*)JS_GetOpaque2(ctx, this_val, js_rl_vector4_class_id);

	if (!p)
		return JS_EXCEPTION;

	if (JS_IsUndefined(this_val) || JS_IsNull(this_val))
		return JS_UNDEFINED;
	if (JS_IsNull(v))
		return JS_UNDEFINED;

	double value;

	if (JS_ToFloat64(ctx, &value, v))
		return JS_EXCEPTION;

	p->w = value;

	return JS_UNDEFINED;
}

JSValue js_rl_new_vector4(JSContext* ctx, double x, double y, double z, double w)
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

JSValue js_rl_vector4_constructor(JSContext* ctx, JSValueConst new_target, int argc, JSValueConst *argv)
{
	double x, y, z, w;

	if (JS_ToFloat64(ctx, &x, argv[0]))
		return JS_EXCEPTION;

	if (JS_ToFloat64(ctx, &y, argv[1]))
		return JS_EXCEPTION;

	if (JS_ToFloat64(ctx, &z, argv[2]))
		return JS_EXCEPTION;

	if (JS_ToFloat64(ctx, &w, argv[3]))
		return JS_EXCEPTION;

	return js_rl_new_vector4(ctx, x, y, z, w);
}

const JSCFunctionListEntry js_rl_vector4_proto_funcs[] =
{
	JS_CGETSET_DEF("x", js_rl_vector4_get_x, js_rl_vector4_set_x),
	JS_CGETSET_DEF("y", js_rl_vector4_get_y, js_rl_vector4_set_y),
	JS_CGETSET_DEF("z", js_rl_vector4_get_z, js_rl_vector4_set_z),
	JS_CGETSET_DEF("w", js_rl_vector4_get_w, js_rl_vector4_set_w),
};

void js_rl_init_vector4_class(JSContext* ctx, JSModuleDef* m)
{
	JSValue proto, obj;
	JS_NewClassID(&js_rl_vector4_class_id);
	JS_NewClass(JS_GetRuntime(ctx), js_rl_vector4_class_id, &js_rl_vector4_class);
	proto = JS_NewObject(ctx);
	JS_SetPropertyFunctionList(ctx, proto, js_rl_vector4_proto_funcs, countof(js_rl_vector4_proto_funcs));
	JS_SetClassProto(ctx, js_rl_vector4_class_id, proto);

	obj = JS_NewCFunction2(ctx, js_rl_vector4_constructor, "Vector4", 4, JS_CFUNC_constructor_or_func, 0);
	JS_SetModuleExport(ctx, m, "Vector4", obj);
}

#pragma endregion
#pragma region Camera2D

JSClassDef js_rl_camera2d_class = { "Camera2D" };

JSValue js_rl_camera2d_get_offset(JSContext* ctx, JSValueConst this_val)
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

JSValue js_rl_camera2d_set_offset(JSContext* ctx, JSValueConst this_val, JSValueConst v)
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

JSValue js_rl_camera2d_get_target(JSContext* ctx, JSValueConst this_val)
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

JSValue js_rl_camera2d_set_target(JSContext* ctx, JSValueConst this_val, JSValueConst v)
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

JSValue js_rl_camera2d_get_rotation(JSContext* ctx, JSValueConst this_val)
{
	Camera2D* p = (Camera2D*)JS_GetOpaque2(ctx, this_val, js_rl_camera2d_class_id);

	if (p)
		return JS_NewFloat64(ctx, p->rotation);
	else
		return JS_EXCEPTION;
}

JSValue js_rl_camera2d_set_rotation(JSContext* ctx, JSValueConst this_val, JSValueConst v)
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

JSValue js_rl_camera2d_get_zoom(JSContext* ctx, JSValueConst this_val)
{
	Camera2D* p = (Camera2D*)JS_GetOpaque2(ctx, this_val, js_rl_camera2d_class_id);

	if (p)
		return JS_NewFloat64(ctx, p->zoom);
	else
		return JS_EXCEPTION;
}

JSValue js_rl_camera2d_set_zoom(JSContext* ctx, JSValueConst this_val, JSValueConst v)
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

JSValue js_rl_new_camera2d(JSContext* ctx, Vector2 offset, Vector2 target, double rotation, double zoom)
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

JSValue js_rl_camera2d_constructor(JSContext* ctx, JSValueConst new_target, int argc, JSValueConst *argv)
{
	Vector2* offset = (Vector2*)JS_GetOpaque2(ctx, argv[0], js_rl_vector2_class_id);
	Vector2* target = (Vector2*)JS_GetOpaque2(ctx, argv[1], js_rl_vector2_class_id);
	double rotation, zoom;

	if (JS_ToFloat64(ctx, &rotation, argv[2]))
		return JS_EXCEPTION;

	if (JS_ToFloat64(ctx, &zoom, argv[3]))
		return JS_EXCEPTION;

	return js_rl_new_camera2d(ctx, *offset, *target, rotation, zoom);
}

const JSCFunctionListEntry js_rl_camera2d_proto_funcs[] =
{
	JS_CGETSET_DEF("offset", js_rl_camera2d_get_offset, js_rl_camera2d_set_offset),
	JS_CGETSET_DEF("target", js_rl_camera2d_get_target, js_rl_camera2d_set_target),
	JS_CGETSET_DEF("rotation", js_rl_camera2d_get_rotation, js_rl_camera2d_set_rotation),
	JS_CGETSET_DEF("zoom", js_rl_camera2d_get_zoom, js_rl_camera2d_set_zoom),
};

void js_rl_init_camera2d_class(JSContext* ctx, JSModuleDef* m)
{
	JSValue proto, obj;
	JS_NewClassID(&js_rl_camera2d_class_id);
	JS_NewClass(JS_GetRuntime(ctx), js_rl_camera2d_class_id, &js_rl_camera2d_class);
	proto = JS_NewObject(ctx);
	JS_SetPropertyFunctionList(ctx, proto, js_rl_camera2d_proto_funcs, countof(js_rl_camera2d_proto_funcs));
	JS_SetClassProto(ctx, js_rl_camera2d_class_id, proto);

	obj = JS_NewCFunction2(ctx, js_rl_camera2d_constructor, "Camera2D", 4, JS_CFUNC_constructor_or_func, 0);
	JS_SetModuleExport(ctx, m, "Camera2D", obj);
}

#pragma endregion
#pragma region Camera3D

JSClassDef js_rl_camera3d_class = { "Camera3D" };

JSValue js_rl_camera3d_get_position(JSContext* ctx, JSValueConst this_val)
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

JSValue js_rl_camera3d_set_position(JSContext* ctx, JSValueConst this_val, JSValueConst v)
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

JSValue js_rl_camera3d_get_target(JSContext* ctx, JSValueConst this_val)
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

JSValue js_rl_camera3d_set_target(JSContext* ctx, JSValueConst this_val, JSValueConst v)
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

JSValue js_rl_camera3d_get_up(JSContext* ctx, JSValueConst this_val)
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

JSValue js_rl_camera3d_set_up(JSContext* ctx, JSValueConst this_val, JSValueConst v)
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

JSValue js_rl_camera3d_get_fov_y(JSContext* ctx, JSValueConst this_val)
{
	Camera3D* p = (Camera3D*)JS_GetOpaque2(ctx, this_val, js_rl_camera3d_class_id);

	if (p)
		return JS_NewFloat64(ctx, p->fovy);
	else
		return JS_EXCEPTION;
}

JSValue js_rl_camera3d_set_fov_y(JSContext* ctx, JSValueConst this_val, JSValueConst v)
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

JSValue js_rl_camera3d_get_type(JSContext* ctx, JSValueConst this_val)
{
	Camera3D* p = (Camera3D*)JS_GetOpaque2(ctx, this_val, js_rl_camera3d_class_id);

	if (p)
		return JS_NewInt32(ctx, p->type);
	else
		return JS_EXCEPTION;
}

JSValue js_rl_camera3d_set_type(JSContext* ctx, JSValueConst this_val, JSValueConst v)
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

JSValue js_rl_new_camera3d(JSContext* ctx, Vector3 position, Vector3 target, Vector3 up, double fovy, int type)
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

JSValue js_rl_camera3d_constructor(JSContext* ctx, JSValueConst new_target, int argc, JSValueConst *argv)
{
	Vector3* position = (Vector3*)JS_GetOpaque2(ctx, argv[0], js_rl_vector3_class_id);
	Vector3* target = (Vector3*)JS_GetOpaque2(ctx, argv[1], js_rl_vector3_class_id);
	Vector3* up = (Vector3*)JS_GetOpaque2(ctx, argv[3], js_rl_vector3_class_id);
	double fovy;
	int type;

	JS_ToFloat64(ctx, &fovy, argv[4]);
	JS_ToInt32(ctx, &type, argv[5]);

	return js_rl_new_camera3d(ctx, *position, *target, *up, fovy, type);
}

const JSCFunctionListEntry js_rl_camera3d_proto_funcs[] =
{
	JS_CGETSET_DEF("position", js_rl_camera3d_get_position, js_rl_camera3d_set_position),
	JS_CGETSET_DEF("target", js_rl_camera3d_get_target, js_rl_camera3d_set_target),
	JS_CGETSET_DEF("up", js_rl_camera3d_get_up, js_rl_camera3d_set_up),
	JS_CGETSET_DEF("fovY", js_rl_camera3d_get_fov_y, js_rl_camera3d_set_fov_y),
	JS_CGETSET_DEF("type", js_rl_camera3d_get_type, js_rl_camera3d_set_type),
};

void js_rl_init_camera3d_class(JSContext* ctx, JSModuleDef* m)
{
	JSValue proto, obj;
	JS_NewClassID(&js_rl_camera3d_class_id);
	JS_NewClass(JS_GetRuntime(ctx), js_rl_camera3d_class_id, &js_rl_camera3d_class);
	proto = JS_NewObject(ctx);
	JS_SetPropertyFunctionList(ctx, proto, js_rl_camera3d_proto_funcs, countof(js_rl_camera3d_proto_funcs));
	JS_SetClassProto(ctx, js_rl_camera3d_class_id, proto);

	obj = JS_NewCFunction2(ctx, js_rl_camera3d_constructor, "Camera3D", 4, JS_CFUNC_constructor_or_func, 0);
	JS_SetModuleExport(ctx, m, "Camera3D", obj);
}

#pragma endregion
#pragma region Texture2D

void js_rl_texture2d_finalizer(JSRuntime* rt, JSValue val)
{
	Texture2D* p = (Texture2D*)JS_GetOpaque(val, js_rl_texture2d_class_id);
	UnloadTexture(*p);
}

JSClassDef js_rl_texture2d_class =
{
	"Texture2D",
	.finalizer = js_rl_texture2d_finalizer,
};

JSValue js_rl_texture2d_get_id(JSContext* ctx, JSValueConst this_val)
{
	Texture2D* p = (Texture2D*)JS_GetOpaque2(ctx, this_val, js_rl_texture2d_class_id);

	if (p)
		return JS_NewInt32(ctx, p->id);
	else
		return JS_EXCEPTION;
}

JSValue js_rl_texture2d_get_width(JSContext* ctx, JSValueConst this_val)
{
	Texture2D* p = (Texture2D*)JS_GetOpaque2(ctx, this_val, js_rl_texture2d_class_id);

	if (p)
		return JS_NewInt32(ctx, p->width);
	else
		return JS_EXCEPTION;
}

JSValue js_rl_texture2d_get_height(JSContext* ctx, JSValueConst this_val)
{
	Texture2D* p = (Texture2D*)JS_GetOpaque2(ctx, this_val, js_rl_texture2d_class_id);

	if (p)
		return JS_NewInt32(ctx, p->height);
	else
		return JS_EXCEPTION;
}

JSValue js_rl_texture2d_get_format(JSContext* ctx, JSValueConst this_val)
{
	Texture2D* p = (Texture2D*)JS_GetOpaque2(ctx, this_val, js_rl_texture2d_class_id);

	if (p)
		return JS_NewInt32(ctx, p->format);
	else
		return JS_EXCEPTION;
}

JSValue js_rl_texture2d_get_mipmaps(JSContext* ctx, JSValueConst this_val)
{
	Texture2D* p = (Texture2D*)JS_GetOpaque2(ctx, this_val, js_rl_texture2d_class_id);

	if (p)
		return JS_NewInt32(ctx, p->mipmaps);
	else
		return JS_EXCEPTION;
}

const JSCFunctionListEntry js_rl_texture2d_proto_funcs[] =
{
	JS_CGETSET_DEF("id", js_rl_texture2d_get_id, NULL),
	JS_CGETSET_DEF("width", js_rl_texture2d_get_width, NULL),
	JS_CGETSET_DEF("height", js_rl_texture2d_get_height, NULL),
	JS_CGETSET_DEF("format", js_rl_texture2d_get_format, NULL),
	JS_CGETSET_DEF("mipmaps", js_rl_texture2d_get_mipmaps, NULL),
};

void js_rl_init_texture2d_class(JSContext* ctx, JSModuleDef* m)
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

void js_rl_render_texture_finalizer(JSRuntime* rt, JSValue val)
{
	RenderTexture* p = (RenderTexture*)JS_GetOpaque(val, js_rl_render_texture_class_id);
	UnloadRenderTexture(*p);
}

JSClassDef js_rl_render_texture_class =
{
	"RenderTexture2D",
	.finalizer = js_rl_render_texture_finalizer,
};

JSValue js_rl_render_texture_get_id(JSContext* ctx, JSValueConst this_val)
{
	RenderTexture2D* p = (RenderTexture2D*)JS_GetOpaque2(ctx, this_val, js_rl_render_texture_class_id);

	if (p)
		return JS_NewInt32(ctx, p->id);
	else
		return JS_EXCEPTION;
}

JSValue js_rl_render_texture_set_id(JSContext* ctx, JSValueConst this_val, JSValueConst v)
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

JSValue js_rl_render_texture_get_texture(JSContext* ctx, JSValueConst this_val)
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

JSValue js_rl_render_texture_set_texture(JSContext* ctx, JSValueConst this_val, JSValueConst v)
{
	RenderTexture2D* p = (RenderTexture2D*)JS_GetOpaque2(ctx, this_val, js_rl_render_texture_class_id);

	if (!p)
		return JS_EXCEPTION;

	if (JS_IsUndefined(this_val) || JS_IsNull(this_val))
		return JS_UNDEFINED;
	if (JS_IsNull(v))
		return JS_UNDEFINED;

	Texture value = *(Texture *)JS_GetOpaque2(ctx, v, js_rl_texture2d_class_id);
	p->texture = value;

	return JS_UNDEFINED;
}

JSValue js_rl_render_texture_get_depth(JSContext* ctx, JSValueConst this_val)
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

JSValue js_rl_render_texture_set_depth(JSContext* ctx, JSValueConst this_val, JSValueConst v)
{
	RenderTexture2D* p = (RenderTexture2D*)JS_GetOpaque2(ctx, this_val, js_rl_render_texture_class_id);

	if (!p)
		return JS_EXCEPTION;

	if (JS_IsUndefined(this_val) || JS_IsNull(this_val))
		return JS_UNDEFINED;
	if (JS_IsNull(v))
		return JS_UNDEFINED;

	Texture value = *(Texture *)JS_GetOpaque2(ctx, v, js_rl_texture2d_class_id);
	p->depth = value;

	return JS_UNDEFINED;
}

JSValue js_rl_render_texture_get_depth_texture(JSContext* ctx, JSValueConst this_val)
{
	RenderTexture2D* p = (RenderTexture2D*)JS_GetOpaque2(ctx, this_val, js_rl_render_texture_class_id);

	if (p)
		return JS_NewBool(ctx, p->depthTexture);
	else
		return JS_EXCEPTION;
}

JSValue js_rl_render_texture_set_depth_texture(JSContext* ctx, JSValueConst this_val, JSValueConst v)
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

JSValue js_rl_render_texture_constructor(JSContext* ctx, JSValueConst new_target, int argc, JSValueConst *argv)
{
	JSValue obj = JS_NewObjectClass(ctx, js_rl_render_texture_class_id);

	int w, h;

	if (JS_ToInt32(ctx, &w, argv[0]))
		return JS_EXCEPTION;

	if (JS_ToInt32(ctx, &h, argv[1]))
		return JS_EXCEPTION;

	RenderTexture2D* p = js_mallocz(ctx, sizeof(RenderTexture2D));
	RenderTexture2D rt = LoadRenderTexture(w, h);

	if (!p)
	{
		JS_FreeValue(ctx, obj);
		return JS_EXCEPTION;
	}

	memcpy(p, &rt, sizeof(rt));

	JS_SetOpaque(obj, p);

	return obj;
}

const JSCFunctionListEntry js_rl_render_texture_proto_funcs[] =
{
	JS_CGETSET_DEF("x", js_rl_render_texture_get_id, js_rl_render_texture_set_id),
	JS_CGETSET_DEF("y", js_rl_render_texture_get_texture, js_rl_render_texture_set_texture),
	JS_CGETSET_DEF("z", js_rl_render_texture_get_depth, js_rl_render_texture_set_depth),
	JS_CGETSET_DEF("w", js_rl_render_texture_get_depth_texture, js_rl_render_texture_set_depth_texture),
};

void js_rl_init_render_texture_class(JSContext* ctx, JSModuleDef* m)
{
	JSValue proto, obj;
	JS_NewClassID(&js_rl_render_texture_class_id);
	JS_NewClass(JS_GetRuntime(ctx), js_rl_render_texture_class_id, &js_rl_render_texture_class);
	proto = JS_NewObject(ctx);
	JS_SetPropertyFunctionList(ctx, proto, js_rl_render_texture_proto_funcs, countof(js_rl_render_texture_proto_funcs));
	JS_SetClassProto(ctx, js_rl_render_texture_class_id, proto);

	obj = JS_NewCFunction2(ctx, js_rl_render_texture_constructor, "RenderTexture2D", 2, JS_CFUNC_constructor_or_func, 0);
	JS_SetModuleExport(ctx, m, "RenderTexture2D", obj);
}

#pragma endregion
#pragma region Ray

JSClassDef js_rl_ray_class = { "Ray" };

JSValue js_rl_ray_get_position(JSContext* ctx, JSValueConst this_val)
{
	Ray* p = (Ray*)JS_GetOpaque2(ctx, this_val, js_rl_ray_class_id);

	if (p)
	{
		JSValue obj = JS_NewObject(ctx);
		JS_SetOpaque(obj, &p->position);
		return obj;
	}
	else
		return JS_EXCEPTION;
}

JSValue js_rl_ray_set_position(JSContext* ctx, JSValueConst this_val, JSValueConst v)
{
	Ray* p = (Ray*)JS_GetOpaque2(ctx, this_val, js_rl_ray_class_id);

	if (!p)
		return JS_EXCEPTION;

	if (JS_IsUndefined(this_val) || JS_IsNull(this_val))
		return JS_UNDEFINED;
	if (JS_IsNull(v))
		return JS_UNDEFINED;

	p->position = *(Vector3*)JS_GetOpaque2(ctx, v, js_rl_vector3_class_id);

	return JS_UNDEFINED;
}

JSValue js_rl_ray_get_direction(JSContext* ctx, JSValueConst this_val)
{
	Ray* p = (Ray*)JS_GetOpaque2(ctx, this_val, js_rl_ray_class_id);

	if (p)
	{
		JSValue obj = JS_NewObject(ctx);
		JS_SetOpaque(obj, &p->direction);
		return obj;
	}
	else
		return JS_EXCEPTION;
}

JSValue js_rl_ray_set_direction(JSContext* ctx, JSValueConst this_val, JSValueConst v)
{
	Ray* p = (Ray*)JS_GetOpaque2(ctx, this_val, js_rl_ray_class_id);

	if (!p)
		return JS_EXCEPTION;

	if (JS_IsUndefined(this_val) || JS_IsNull(this_val))
		return JS_UNDEFINED;
	if (JS_IsNull(v))
		return JS_UNDEFINED;

	p->direction = *(Vector3*)JS_GetOpaque2(ctx, v, js_rl_vector3_class_id);

	return JS_UNDEFINED;
}

JSValue js_rl_new_ray(JSContext* ctx, Vector3 position, Vector3 direction)
{
	JSValue obj = JS_NewObjectClass(ctx, js_rl_ray_class_id);

	if (JS_IsException(obj))
		return obj;

	Ray* p = js_mallocz(ctx, sizeof(Ray));

	p->position = position;
	p->direction = direction;

	JS_SetOpaque(obj, p);

	return obj;
}

JSValue js_rl_ray_constructor(JSContext* ctx, JSValueConst new_target, int argc, JSValueConst *argv)
{
	Vector3* position = (Vector3*)JS_GetOpaque2(ctx, argv[0], js_rl_vector3_class_id);
	Vector3* direction = (Vector3*)JS_GetOpaque2(ctx, argv[1], js_rl_vector3_class_id);

	return js_rl_new_ray(ctx, *position, *direction);
}

const JSCFunctionListEntry js_rl_ray_proto_funcs[] =
{
	JS_CGETSET_DEF("position", js_rl_ray_get_position, js_rl_ray_set_position),
	JS_CGETSET_DEF("target", js_rl_ray_get_direction, js_rl_ray_set_direction),
};

void js_rl_init_ray_class(JSContext* ctx, JSModuleDef* m)
{
	JSValue proto, obj;
	JS_NewClassID(&js_rl_ray_class_id);
	JS_NewClass(JS_GetRuntime(ctx), js_rl_ray_class_id, &js_rl_ray_class);
	proto = JS_NewObject(ctx);
	JS_SetPropertyFunctionList(ctx, proto, js_rl_ray_proto_funcs, countof(js_rl_ray_proto_funcs));
	JS_SetClassProto(ctx, js_rl_ray_class_id, proto);

	obj = JS_NewCFunction2(ctx, js_rl_ray_constructor, "Ray", 4, JS_CFUNC_constructor_or_func, 0);
	JS_SetModuleExport(ctx, m, "Ray", obj);
}

#pragma endregion
#pragma region Matrix

JSClassDef js_rl_matrix_class = { "Matrix" };

JSValue js_rl_matrix_get_m0(JSContext* ctx, JSValueConst this_val)
{
	Matrix* p = (Matrix*)JS_GetOpaque2(ctx, this_val, js_rl_matrix_class_id);

	if (p)
		return JS_NewFloat64(ctx, p->m0);
	else
		return JS_EXCEPTION;
}
JSValue js_rl_matrix_get_m1(JSContext* ctx, JSValueConst this_val)
{
	Matrix* p = (Matrix*)JS_GetOpaque2(ctx, this_val, js_rl_matrix_class_id);

	if (p)
		return JS_NewFloat64(ctx, p->m1);
	else
		return JS_EXCEPTION;
}
JSValue js_rl_matrix_get_m2(JSContext* ctx, JSValueConst this_val)
{
	Matrix* p = (Matrix*)JS_GetOpaque2(ctx, this_val, js_rl_matrix_class_id);

	if (p)
		return JS_NewFloat64(ctx, p->m2);
	else
		return JS_EXCEPTION;
}
JSValue js_rl_matrix_get_m3(JSContext* ctx, JSValueConst this_val)
{
	Matrix* p = (Matrix*)JS_GetOpaque2(ctx, this_val, js_rl_matrix_class_id);

	if (p)
		return JS_NewFloat64(ctx, p->m3);
	else
		return JS_EXCEPTION;
}
JSValue js_rl_matrix_get_m4(JSContext* ctx, JSValueConst this_val)
{
	Matrix* p = (Matrix*)JS_GetOpaque2(ctx, this_val, js_rl_matrix_class_id);

	if (p)
		return JS_NewFloat64(ctx, p->m4);
	else
		return JS_EXCEPTION;
}
JSValue js_rl_matrix_get_m5(JSContext* ctx, JSValueConst this_val)
{
	Matrix* p = (Matrix*)JS_GetOpaque2(ctx, this_val, js_rl_matrix_class_id);

	if (p)
		return JS_NewFloat64(ctx, p->m5);
	else
		return JS_EXCEPTION;
}
JSValue js_rl_matrix_get_m6(JSContext* ctx, JSValueConst this_val)
{
	Matrix* p = (Matrix*)JS_GetOpaque2(ctx, this_val, js_rl_matrix_class_id);

	if (p)
		return JS_NewFloat64(ctx, p->m6);
	else
		return JS_EXCEPTION;
}
JSValue js_rl_matrix_get_m7(JSContext* ctx, JSValueConst this_val)
{
	Matrix* p = (Matrix*)JS_GetOpaque2(ctx, this_val, js_rl_matrix_class_id);

	if (p)
		return JS_NewFloat64(ctx, p->m7);
	else
		return JS_EXCEPTION;
}
JSValue js_rl_matrix_get_m8(JSContext* ctx, JSValueConst this_val)
{
	Matrix* p = (Matrix*)JS_GetOpaque2(ctx, this_val, js_rl_matrix_class_id);

	if (p)
		return JS_NewFloat64(ctx, p->m8);
	else
		return JS_EXCEPTION;
}
JSValue js_rl_matrix_get_m9(JSContext* ctx, JSValueConst this_val)
{
	Matrix* p = (Matrix*)JS_GetOpaque2(ctx, this_val, js_rl_matrix_class_id);

	if (p)
		return JS_NewFloat64(ctx, p->m9);
	else
		return JS_EXCEPTION;
}
JSValue js_rl_matrix_get_m10(JSContext* ctx, JSValueConst this_val)
{
	Matrix* p = (Matrix*)JS_GetOpaque2(ctx, this_val, js_rl_matrix_class_id);

	if (p)
		return JS_NewFloat64(ctx, p->m10);
	else
		return JS_EXCEPTION;
}
JSValue js_rl_matrix_get_m11(JSContext* ctx, JSValueConst this_val)
{
	Matrix* p = (Matrix*)JS_GetOpaque2(ctx, this_val, js_rl_matrix_class_id);

	if (p)
		return JS_NewFloat64(ctx, p->m11);
	else
		return JS_EXCEPTION;
}
JSValue js_rl_matrix_get_m12(JSContext* ctx, JSValueConst this_val)
{
	Matrix* p = (Matrix*)JS_GetOpaque2(ctx, this_val, js_rl_matrix_class_id);

	if (p)
		return JS_NewFloat64(ctx, p->m12);
	else
		return JS_EXCEPTION;
}
JSValue js_rl_matrix_get_m13(JSContext* ctx, JSValueConst this_val)
{
	Matrix* p = (Matrix*)JS_GetOpaque2(ctx, this_val, js_rl_matrix_class_id);

	if (p)
		return JS_NewFloat64(ctx, p->m13);
	else
		return JS_EXCEPTION;
}
JSValue js_rl_matrix_get_m14(JSContext* ctx, JSValueConst this_val)
{
	Matrix* p = (Matrix*)JS_GetOpaque2(ctx, this_val, js_rl_matrix_class_id);

	if (p)
		return JS_NewFloat64(ctx, p->m14);
	else
		return JS_EXCEPTION;
}
JSValue js_rl_matrix_get_m15(JSContext* ctx, JSValueConst this_val)
{
	Matrix* p = (Matrix*)JS_GetOpaque2(ctx, this_val, js_rl_matrix_class_id);

	if (p)
		return JS_NewFloat64(ctx, p->m15);
	else
		return JS_EXCEPTION;
}

JSValue js_rl_matrix_set_m0(JSContext* ctx, JSValueConst this_val, JSValueConst v)
{
	Matrix* p = (Matrix*)JS_GetOpaque2(ctx, this_val, js_rl_matrix_class_id);

	if (!p)
		return JS_EXCEPTION;

	if (JS_IsUndefined(this_val) || JS_IsNull(this_val))
		return JS_UNDEFINED;
	if (JS_IsNull(v))
		return JS_UNDEFINED;

	double value;

	if (JS_ToFloat64(ctx, &value, v))
		return JS_EXCEPTION;

	p->m0 = value;

	return JS_UNDEFINED;
}

JSValue js_rl_matrix_set_m1(JSContext* ctx, JSValueConst this_val, JSValueConst v)
{
	Matrix* p = (Matrix*)JS_GetOpaque2(ctx, this_val, js_rl_matrix_class_id);

	if (!p)
		return JS_EXCEPTION;

	if (JS_IsUndefined(this_val) || JS_IsNull(this_val))
		return JS_UNDEFINED;
	if (JS_IsNull(v))
		return JS_UNDEFINED;

	double value;

	if (JS_ToFloat64(ctx, &value, v))
		return JS_EXCEPTION;

	p->m1 = value;

	return JS_UNDEFINED;
}

JSValue js_rl_matrix_set_m2(JSContext* ctx, JSValueConst this_val, JSValueConst v)
{
	Matrix* p = (Matrix*)JS_GetOpaque2(ctx, this_val, js_rl_matrix_class_id);

	if (!p)
		return JS_EXCEPTION;

	if (JS_IsUndefined(this_val) || JS_IsNull(this_val))
		return JS_UNDEFINED;
	if (JS_IsNull(v))
		return JS_UNDEFINED;

	double value;

	if (JS_ToFloat64(ctx, &value, v))
		return JS_EXCEPTION;

	p->m2 = value;

	return JS_UNDEFINED;
}

JSValue js_rl_matrix_set_m3(JSContext* ctx, JSValueConst this_val, JSValueConst v)
{
	Matrix* p = (Matrix*)JS_GetOpaque2(ctx, this_val, js_rl_matrix_class_id);

	if (!p)
		return JS_EXCEPTION;

	if (JS_IsUndefined(this_val) || JS_IsNull(this_val))
		return JS_UNDEFINED;
	if (JS_IsNull(v))
		return JS_UNDEFINED;

	double value;

	if (JS_ToFloat64(ctx, &value, v))
		return JS_EXCEPTION;

	p->m3 = value;

	return JS_UNDEFINED;
}

JSValue js_rl_matrix_set_m4(JSContext* ctx, JSValueConst this_val, JSValueConst v)
{
	Matrix* p = (Matrix*)JS_GetOpaque2(ctx, this_val, js_rl_matrix_class_id);

	if (!p)
		return JS_EXCEPTION;

	if (JS_IsUndefined(this_val) || JS_IsNull(this_val))
		return JS_UNDEFINED;
	if (JS_IsNull(v))
		return JS_UNDEFINED;

	double value;

	if (JS_ToFloat64(ctx, &value, v))
		return JS_EXCEPTION;

	p->m4 = value;

	return JS_UNDEFINED;
}

JSValue js_rl_matrix_set_m5(JSContext* ctx, JSValueConst this_val, JSValueConst v)
{
	Matrix* p = (Matrix*)JS_GetOpaque2(ctx, this_val, js_rl_matrix_class_id);

	if (!p)
		return JS_EXCEPTION;

	if (JS_IsUndefined(this_val) || JS_IsNull(this_val))
		return JS_UNDEFINED;
	if (JS_IsNull(v))
		return JS_UNDEFINED;

	double value;

	if (JS_ToFloat64(ctx, &value, v))
		return JS_EXCEPTION;

	p->m5 = value;

	return JS_UNDEFINED;
}

JSValue js_rl_matrix_set_m6(JSContext* ctx, JSValueConst this_val, JSValueConst v)
{
	Matrix* p = (Matrix*)JS_GetOpaque2(ctx, this_val, js_rl_matrix_class_id);

	if (!p)
		return JS_EXCEPTION;

	if (JS_IsUndefined(this_val) || JS_IsNull(this_val))
		return JS_UNDEFINED;
	if (JS_IsNull(v))
		return JS_UNDEFINED;

	double value;

	if (JS_ToFloat64(ctx, &value, v))
		return JS_EXCEPTION;

	p->m6 = value;

	return JS_UNDEFINED;
}

JSValue js_rl_matrix_set_m7(JSContext* ctx, JSValueConst this_val, JSValueConst v)
{
	Matrix* p = (Matrix*)JS_GetOpaque2(ctx, this_val, js_rl_matrix_class_id);

	if (!p)
		return JS_EXCEPTION;

	if (JS_IsUndefined(this_val) || JS_IsNull(this_val))
		return JS_UNDEFINED;
	if (JS_IsNull(v))
		return JS_UNDEFINED;

	double value;

	if (JS_ToFloat64(ctx, &value, v))
		return JS_EXCEPTION;

	p->m7 = value;

	return JS_UNDEFINED;
}

JSValue js_rl_matrix_set_m8(JSContext* ctx, JSValueConst this_val, JSValueConst v)
{
	Matrix* p = (Matrix*)JS_GetOpaque2(ctx, this_val, js_rl_matrix_class_id);

	if (!p)
		return JS_EXCEPTION;

	if (JS_IsUndefined(this_val) || JS_IsNull(this_val))
		return JS_UNDEFINED;
	if (JS_IsNull(v))
		return JS_UNDEFINED;

	double value;

	if (JS_ToFloat64(ctx, &value, v))
		return JS_EXCEPTION;

	p->m8 = value;

	return JS_UNDEFINED;
}

JSValue js_rl_matrix_set_m9(JSContext* ctx, JSValueConst this_val, JSValueConst v)
{
	Matrix* p = (Matrix*)JS_GetOpaque2(ctx, this_val, js_rl_matrix_class_id);

	if (!p)
		return JS_EXCEPTION;

	if (JS_IsUndefined(this_val) || JS_IsNull(this_val))
		return JS_UNDEFINED;
	if (JS_IsNull(v))
		return JS_UNDEFINED;

	double value;

	if (JS_ToFloat64(ctx, &value, v))
		return JS_EXCEPTION;

	p->m9 = value;

	return JS_UNDEFINED;
}

JSValue js_rl_matrix_set_m10(JSContext* ctx, JSValueConst this_val, JSValueConst v)
{
	Matrix* p = (Matrix*)JS_GetOpaque2(ctx, this_val, js_rl_matrix_class_id);

	if (!p)
		return JS_EXCEPTION;

	if (JS_IsUndefined(this_val) || JS_IsNull(this_val))
		return JS_UNDEFINED;
	if (JS_IsNull(v))
		return JS_UNDEFINED;

	double value;

	if (JS_ToFloat64(ctx, &value, v))
		return JS_EXCEPTION;

	p->m10 = value;

	return JS_UNDEFINED;
}

JSValue js_rl_matrix_set_m11(JSContext* ctx, JSValueConst this_val, JSValueConst v)
{
	Matrix* p = (Matrix*)JS_GetOpaque2(ctx, this_val, js_rl_matrix_class_id);

	if (!p)
		return JS_EXCEPTION;

	if (JS_IsUndefined(this_val) || JS_IsNull(this_val))
		return JS_UNDEFINED;
	if (JS_IsNull(v))
		return JS_UNDEFINED;

	double value;

	if (JS_ToFloat64(ctx, &value, v))
		return JS_EXCEPTION;

	p->m11 = value;

	return JS_UNDEFINED;
}

JSValue js_rl_matrix_set_m12(JSContext* ctx, JSValueConst this_val, JSValueConst v)
{
	Matrix* p = (Matrix*)JS_GetOpaque2(ctx, this_val, js_rl_matrix_class_id);

	if (!p)
		return JS_EXCEPTION;

	if (JS_IsUndefined(this_val) || JS_IsNull(this_val))
		return JS_UNDEFINED;
	if (JS_IsNull(v))
		return JS_UNDEFINED;

	double value;

	if (JS_ToFloat64(ctx, &value, v))
		return JS_EXCEPTION;

	p->m12 = value;

	return JS_UNDEFINED;
}

JSValue js_rl_matrix_set_m13(JSContext* ctx, JSValueConst this_val, JSValueConst v)
{
	Matrix* p = (Matrix*)JS_GetOpaque2(ctx, this_val, js_rl_matrix_class_id);

	if (!p)
		return JS_EXCEPTION;

	if (JS_IsUndefined(this_val) || JS_IsNull(this_val))
		return JS_UNDEFINED;
	if (JS_IsNull(v))
		return JS_UNDEFINED;

	double value;

	if (JS_ToFloat64(ctx, &value, v))
		return JS_EXCEPTION;

	p->m13 = value;

	return JS_UNDEFINED;
}

JSValue js_rl_matrix_set_m14(JSContext* ctx, JSValueConst this_val, JSValueConst v)
{
	Matrix* p = (Matrix*)JS_GetOpaque2(ctx, this_val, js_rl_matrix_class_id);

	if (!p)
		return JS_EXCEPTION;

	if (JS_IsUndefined(this_val) || JS_IsNull(this_val))
		return JS_UNDEFINED;
	if (JS_IsNull(v))
		return JS_UNDEFINED;

	double value;

	if (JS_ToFloat64(ctx, &value, v))
		return JS_EXCEPTION;

	p->m14 = value;

	return JS_UNDEFINED;
}

JSValue js_rl_matrix_set_m15(JSContext* ctx, JSValueConst this_val, JSValueConst v)
{
	Matrix* p = (Matrix*)JS_GetOpaque2(ctx, this_val, js_rl_matrix_class_id);

	if (!p)
		return JS_EXCEPTION;

	if (JS_IsUndefined(this_val) || JS_IsNull(this_val))
		return JS_UNDEFINED;
	if (JS_IsNull(v))
		return JS_UNDEFINED;

	double value;

	if (JS_ToFloat64(ctx, &value, v))
		return JS_EXCEPTION;

	p->m15 = value;

	return JS_UNDEFINED;
}

JSValue js_rl_new_matrix(JSContext* ctx, double m0, double m1, double m2, double m3, double m4, double m5, double m6, double m7, double m8, double m9, double m10, double m11, double m12, double m13, double m14, double m15)
{
	JSValue obj = JS_NewObjectClass(ctx, js_rl_matrix_class_id);

	if (JS_IsException(obj))
		return obj;

	Matrix* p = js_mallocz(ctx, sizeof(Matrix));

	p->m0 = m0;
	p->m1 = m1;
	p->m2 = m2;
	p->m3 = m3;
	p->m4 = m4;
	p->m5 = m5;
	p->m6 = m6;
	p->m7 = m7;
	p->m8 = m8;
	p->m9 = m9;
	p->m10 = m10;
	p->m11 = m11;
	p->m12 = m12;
	p->m13 = m13;
	p->m14 = m14;
	p->m15 = m15;

	JS_SetOpaque(obj, p);

	return obj;
}

JSValue js_rl_matrix_constructor(JSContext* ctx, JSValueConst new_target, int argc, JSValueConst *argv)
{
	double m0, m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15;

	JS_ToFloat64(ctx, &m0, argv[0]);
	JS_ToFloat64(ctx, &m1, argv[1]);
	JS_ToFloat64(ctx, &m2, argv[2]);
	JS_ToFloat64(ctx, &m3, argv[3]);
	JS_ToFloat64(ctx, &m4, argv[4]);
	JS_ToFloat64(ctx, &m5, argv[5]);
	JS_ToFloat64(ctx, &m6, argv[6]);
	JS_ToFloat64(ctx, &m7, argv[7]);
	JS_ToFloat64(ctx, &m8, argv[8]);
	JS_ToFloat64(ctx, &m9, argv[9]);
	JS_ToFloat64(ctx, &m10, argv[10]);
	JS_ToFloat64(ctx, &m11, argv[11]);
	JS_ToFloat64(ctx, &m12, argv[12]);
	JS_ToFloat64(ctx, &m13, argv[13]);
	JS_ToFloat64(ctx, &m14, argv[14]);
	JS_ToFloat64(ctx, &m15, argv[15]);

	return js_rl_new_matrix(ctx, m0, m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15);
}

const JSCFunctionListEntry js_rl_matrix_proto_funcs[] =
{
	JS_CGETSET_DEF("m0", js_rl_matrix_get_m0, js_rl_matrix_set_m0),
	JS_CGETSET_DEF("m1", js_rl_matrix_get_m1, js_rl_matrix_set_m1),
	JS_CGETSET_DEF("m2", js_rl_matrix_get_m2, js_rl_matrix_set_m2),
	JS_CGETSET_DEF("m3", js_rl_matrix_get_m3, js_rl_matrix_set_m3),
	JS_CGETSET_DEF("m4", js_rl_matrix_get_m4, js_rl_matrix_set_m4),
	JS_CGETSET_DEF("m5", js_rl_matrix_get_m5, js_rl_matrix_set_m5),
	JS_CGETSET_DEF("m6", js_rl_matrix_get_m6, js_rl_matrix_set_m6),
	JS_CGETSET_DEF("m7", js_rl_matrix_get_m7, js_rl_matrix_set_m7),
	JS_CGETSET_DEF("m8", js_rl_matrix_get_m8, js_rl_matrix_set_m8),
	JS_CGETSET_DEF("m9", js_rl_matrix_get_m9, js_rl_matrix_set_m9),
	JS_CGETSET_DEF("m10", js_rl_matrix_get_m10, js_rl_matrix_set_m10),
	JS_CGETSET_DEF("m11", js_rl_matrix_get_m11, js_rl_matrix_set_m11),
	JS_CGETSET_DEF("m12", js_rl_matrix_get_m12, js_rl_matrix_set_m12),
	JS_CGETSET_DEF("m13", js_rl_matrix_get_m13, js_rl_matrix_set_m13),
	JS_CGETSET_DEF("m14", js_rl_matrix_get_m14, js_rl_matrix_set_m14),
	JS_CGETSET_DEF("m15", js_rl_matrix_get_m15, js_rl_matrix_set_m15),
};

void js_rl_init_matrix_class(JSContext* ctx, JSModuleDef* m)
{
	JSValue proto, obj;
	JS_NewClassID(&js_rl_matrix_class_id);
	JS_NewClass(JS_GetRuntime(ctx), js_rl_matrix_class_id, &js_rl_matrix_class);
	proto = JS_NewObject(ctx);
	JS_SetPropertyFunctionList(ctx, proto, js_rl_matrix_proto_funcs, countof(js_rl_matrix_proto_funcs));
	JS_SetClassProto(ctx, js_rl_matrix_class_id, proto);

	obj = JS_NewCFunction2(ctx, js_rl_matrix_constructor, "Matrix", 4, JS_CFUNC_constructor_or_func, 0);
	JS_SetModuleExport(ctx, m, "Matrix", obj);
}

#pragma endregion
#pragma region Color

JSClassDef js_rl_color_class = { "Color" };

JSValue js_rl_color_get_r(JSContext* ctx, JSValueConst this_val)
{
	Color* p = (Color*)JS_GetOpaque2(ctx, this_val, js_rl_color_class_id);

	if (p)
		return JS_NewInt32(ctx, p->r);
	else
		return JS_EXCEPTION;
}

JSValue js_rl_color_set_r(JSContext* ctx, JSValueConst this_val, JSValueConst v)
{
	Color* p = (Color*)JS_GetOpaque2(ctx, this_val, js_rl_color_class_id);

	if (!p)
		return JS_EXCEPTION;

	if (JS_IsUndefined(this_val) || JS_IsNull(this_val))
		return JS_UNDEFINED;
	if (JS_IsNull(v))
		return JS_UNDEFINED;

	int value;

	if (JS_ToInt32(ctx, &value, v))
		return JS_EXCEPTION;

	p->r = value;

	return JS_UNDEFINED;
}

JSValue js_rl_color_get_g(JSContext* ctx, JSValueConst this_val)
{
	Color* p = (Color*)JS_GetOpaque2(ctx, this_val, js_rl_color_class_id);

	if (p)
		return JS_NewInt32(ctx, p->g);
	else
		return JS_EXCEPTION;
}

JSValue js_rl_color_set_g(JSContext* ctx, JSValueConst this_val, JSValueConst v)
{
	Color* p = (Color*)JS_GetOpaque2(ctx, this_val, js_rl_color_class_id);

	if (!p)
		return JS_EXCEPTION;

	if (JS_IsUndefined(this_val) || JS_IsNull(this_val))
		return JS_UNDEFINED;
	if (JS_IsNull(v))
		return JS_UNDEFINED;

	int value;

	if (JS_ToInt32(ctx, &value, v))
		return JS_EXCEPTION;

	p->g = value;

	return JS_UNDEFINED;
}

JSValue js_rl_color_get_b(JSContext* ctx, JSValueConst this_val)
{
	Color* p = (Color*)JS_GetOpaque2(ctx, this_val, js_rl_color_class_id);

	if (p)
		return JS_NewInt32(ctx, p->b);
	else
		return JS_EXCEPTION;
}

JSValue js_rl_color_set_b(JSContext* ctx, JSValueConst this_val, JSValueConst v)
{
	Color* p = (Color*)JS_GetOpaque2(ctx, this_val, js_rl_color_class_id);

	if (!p)
		return JS_EXCEPTION;

	if (JS_IsUndefined(this_val) || JS_IsNull(this_val))
		return JS_UNDEFINED;
	if (JS_IsNull(v))
		return JS_UNDEFINED;

	int value;

	if (JS_ToInt32(ctx, &value, v))
		return JS_EXCEPTION;

	p->b = value;

	return JS_UNDEFINED;
}

JSValue js_rl_color_get_a(JSContext* ctx, JSValueConst this_val)
{
	Color* p = (Color*)JS_GetOpaque2(ctx, this_val, js_rl_color_class_id);

	if (p)
		return JS_NewInt32(ctx, p->a);
	else
		return JS_EXCEPTION;
}

JSValue js_rl_color_set_a(JSContext* ctx, JSValueConst this_val, JSValueConst v)
{
	Color* p = (Color*)JS_GetOpaque2(ctx, this_val, js_rl_color_class_id);

	if (!p)
		return JS_EXCEPTION;

	if (JS_IsUndefined(this_val) || JS_IsNull(this_val))
		return JS_UNDEFINED;
	if (JS_IsNull(v))
		return JS_UNDEFINED;

	int value;

	if (JS_ToInt32(ctx, &value, v))
		return JS_EXCEPTION;

	p->a = value;

	return JS_UNDEFINED;
}

JSValue js_rl_new_color(JSContext* ctx, int r, int g, int b, int a)
{
	JSValue obj = JS_NewObjectClass(ctx, js_rl_color_class_id);

	if (JS_IsException(obj))
		return obj;

	Color* p = js_mallocz(ctx, sizeof(Color));

	p->r = r;
	p->g = g;
	p->b = b;
	p->a = a;

	JS_SetOpaque(obj, p);

	return obj;
}

JSValue js_rl_color_constructor(JSContext* ctx, JSValueConst new_target, int argc, JSValueConst *argv)
{
	int r, g, b, a;

	if (JS_ToInt32(ctx, &r, argv[0]))
		return JS_EXCEPTION;

	if (JS_ToInt32(ctx, &g, argv[1]))
		return JS_EXCEPTION;

	if (JS_ToInt32(ctx, &b, argv[2]))
		return JS_EXCEPTION;

	if (JS_IsUndefined(argv[3]))
		a = 255;
	else if (JS_ToInt32(ctx, &a, argv[3]))
		return JS_EXCEPTION;

	return js_rl_new_color(ctx, r, g, b, a);
}

const JSCFunctionListEntry js_rl_color_proto_funcs[] =
{
	JS_CGETSET_DEF("r", js_rl_color_get_r, js_rl_color_set_r),
	JS_CGETSET_DEF("g", js_rl_color_get_g, js_rl_color_set_g),
	JS_CGETSET_DEF("b", js_rl_color_get_b, js_rl_color_set_b),
	JS_CGETSET_DEF("a", js_rl_color_get_a, js_rl_color_set_a),
};

void js_rl_init_color_class(JSContext* ctx, JSModuleDef* m)
{
	JSValue proto, obj;
	JS_NewClassID(&js_rl_color_class_id);
	JS_NewClass(JS_GetRuntime(ctx), js_rl_color_class_id, &js_rl_color_class);
	proto = JS_NewObject(ctx);
	JS_SetPropertyFunctionList(ctx, proto, js_rl_color_proto_funcs, countof(js_rl_color_proto_funcs));
	JS_SetClassProto(ctx, js_rl_color_class_id, proto);

	obj = JS_NewCFunction2(ctx, js_rl_color_constructor, "Color", 4, JS_CFUNC_constructor_or_func, 0);
	JS_SetModuleExport(ctx, m, "Color", obj);
}

#pragma endregion
#pragma region Rectangle

JSClassDef js_rl_rectangle_class = { "Rectangle" };

JSValue js_rl_rectangle_get_x(JSContext* ctx, JSValueConst this_val)
{
	Rectangle* p = (Rectangle*)JS_GetOpaque2(ctx, this_val, js_rl_rectangle_class_id);

	if (p)
		return JS_NewFloat64(ctx, p->x);
	else
		return JS_EXCEPTION;
}

JSValue js_rl_rectangle_set_x(JSContext* ctx, JSValueConst this_val, JSValueConst v)
{
	Rectangle* p = (Rectangle*)JS_GetOpaque2(ctx, this_val, js_rl_rectangle_class_id);

	if (!p)
		return JS_EXCEPTION;

	if (JS_IsUndefined(this_val) || JS_IsNull(this_val))
		return JS_UNDEFINED;
	if (JS_IsNull(v))
		return JS_UNDEFINED;

	double value;

	if (JS_ToFloat64(ctx, &value, v))
		return JS_EXCEPTION;

	p->x = value;

	return JS_UNDEFINED;
}

JSValue js_rl_rectangle_get_y(JSContext* ctx, JSValueConst this_val)
{
	Rectangle* p = (Rectangle*)JS_GetOpaque2(ctx, this_val, js_rl_rectangle_class_id);

	if (p)
		return JS_NewFloat64(ctx, p->y);
	else
		return JS_EXCEPTION;
}

JSValue js_rl_rectangle_set_y(JSContext* ctx, JSValueConst this_val, JSValueConst v)
{
	Rectangle* p = (Rectangle*)JS_GetOpaque2(ctx, this_val, js_rl_rectangle_class_id);

	if (!p)
		return JS_EXCEPTION;

	if (JS_IsUndefined(this_val) || JS_IsNull(this_val))
		return JS_UNDEFINED;
	if (JS_IsNull(v))
		return JS_UNDEFINED;

	double value;

	if (JS_ToFloat64(ctx, &value, v))
		return JS_EXCEPTION;

	p->y = value;

	return JS_UNDEFINED;
}

JSValue js_rl_rectangle_get_width(JSContext* ctx, JSValueConst this_val)
{
	Rectangle* p = (Rectangle*)JS_GetOpaque2(ctx, this_val, js_rl_rectangle_class_id);

	if (p)
		return JS_NewFloat64(ctx, p->width);
	else
		return JS_EXCEPTION;
}

JSValue js_rl_rectangle_set_width(JSContext* ctx, JSValueConst this_val, JSValueConst v)
{
	Rectangle* p = (Rectangle*)JS_GetOpaque2(ctx, this_val, js_rl_rectangle_class_id);

	if (!p)
		return JS_EXCEPTION;

	if (JS_IsUndefined(this_val) || JS_IsNull(this_val))
		return JS_UNDEFINED;
	if (JS_IsNull(v))
		return JS_UNDEFINED;

	double value;

	if (JS_ToFloat64(ctx, &value, v))
		return JS_EXCEPTION;

	p->width = value;

	return JS_UNDEFINED;
}

JSValue js_rl_rectangle_get_height(JSContext* ctx, JSValueConst this_val)
{
	Rectangle* p = (Rectangle*)JS_GetOpaque2(ctx, this_val, js_rl_rectangle_class_id);

	if (p)
		return JS_NewFloat64(ctx, p->height);
	else
		return JS_EXCEPTION;
}

JSValue js_rl_rectangle_set_height(JSContext* ctx, JSValueConst this_val, JSValueConst v)
{
	Rectangle* p = (Rectangle*)JS_GetOpaque2(ctx, this_val, js_rl_rectangle_class_id);

	if (!p)
		return JS_EXCEPTION;

	if (JS_IsUndefined(this_val) || JS_IsNull(this_val))
		return JS_UNDEFINED;
	if (JS_IsNull(v))
		return JS_UNDEFINED;

	double value;

	if (JS_ToFloat64(ctx, &value, v))
		return JS_EXCEPTION;

	p->height = value;

	return JS_UNDEFINED;
}

JSValue js_rl_new_rectangle(JSContext* ctx, double x, double y, double w, double h)
{
	JSValue obj = JS_NewObjectClass(ctx, js_rl_rectangle_class_id);

	if (JS_IsException(obj))
		return obj;

	Rectangle* p = js_mallocz(ctx, sizeof(Rectangle));

	p->x = x;
	p->y = y;
	p->width = w;
	p->height = h;

	JS_SetOpaque(obj, p);

	return obj;
}

JSValue js_rl_rectangle_constructor(JSContext* ctx, JSValueConst new_target, int argc, JSValueConst *argv)
{
	double x, y, w, h;

	if (JS_ToFloat64(ctx, &x, argv[0]))
		return JS_EXCEPTION;

	if (JS_ToFloat64(ctx, &y, argv[1]))
		return JS_EXCEPTION;

	if (JS_ToFloat64(ctx, &w, argv[2]))
		return JS_EXCEPTION;

	if (JS_ToFloat64(ctx, &h, argv[3]))
		return JS_EXCEPTION;

	return js_rl_new_rectangle(ctx, x, y, w, h);
}

const JSCFunctionListEntry js_rl_rectangle_proto_funcs[] =
{
	JS_CGETSET_DEF("x", js_rl_rectangle_get_x, js_rl_rectangle_set_x),
	JS_CGETSET_DEF("y", js_rl_rectangle_get_y, js_rl_rectangle_set_y),
	JS_CGETSET_DEF("width", js_rl_rectangle_get_width, js_rl_rectangle_set_width),
	JS_CGETSET_DEF("height", js_rl_rectangle_get_height, js_rl_rectangle_set_height),
};

void js_rl_init_rectangle_class(JSContext* ctx, JSModuleDef* m)
{
	JSValue proto, obj;
	JS_NewClassID(&js_rl_rectangle_class_id);
	JS_NewClass(JS_GetRuntime(ctx), js_rl_rectangle_class_id, &js_rl_rectangle_class);
	proto = JS_NewObject(ctx);
	JS_SetPropertyFunctionList(ctx, proto, js_rl_rectangle_proto_funcs, countof(js_rl_rectangle_proto_funcs));
	JS_SetClassProto(ctx, js_rl_rectangle_class_id, proto);

	obj = JS_NewCFunction2(ctx, js_rl_rectangle_constructor, "Rectangle", 4, JS_CFUNC_constructor_or_func, 0);
	JS_SetModuleExport(ctx, m, "Rectangle", obj);
}

#pragma endregion
#pragma region CharInfo

JSClassDef js_rl_char_info_class = { "CharInfo" };

JSValue js_rl_char_info_get_value(JSContext* ctx, JSValueConst this_val)
{
	CharInfo* p = (CharInfo*)JS_GetOpaque2(ctx, this_val, js_rl_char_info_class_id);

	if (p)
		return JS_NewInt32(ctx, p->value);
	else
		return JS_EXCEPTION;
}

JSValue js_rl_char_info_get_offset_x(JSContext* ctx, JSValueConst this_val)
{
	CharInfo* p = (CharInfo*)JS_GetOpaque2(ctx, this_val, js_rl_char_info_class_id);

	if (p)
		return JS_NewInt32(ctx, p->offsetX);
	else
		return JS_EXCEPTION;
}

JSValue js_rl_char_info_get_offset_y(JSContext* ctx, JSValueConst this_val)
{
	CharInfo* p = (CharInfo*)JS_GetOpaque2(ctx, this_val, js_rl_char_info_class_id);

	if (p)
		return JS_NewInt32(ctx, p->offsetY);
	else
		return JS_EXCEPTION;
}

JSValue js_rl_char_info_get_advance_x(JSContext* ctx, JSValueConst this_val)
{
	CharInfo* p = (CharInfo*)JS_GetOpaque2(ctx, this_val, js_rl_char_info_class_id);

	if (p)
		return JS_NewInt32(ctx, p->advanceX);
	else
		return JS_EXCEPTION;
}

JSValue js_rl_char_info_get_image(JSContext* ctx, JSValueConst this_val)
{
	CharInfo* p = (CharInfo*)JS_GetOpaque2(ctx, this_val, js_rl_char_info_class_id);

	if (p)
	{
		JSValue obj = JS_NewObjectClass(ctx, js_rl_image_class_id);

		if (JS_IsException(obj))
			return obj;

		JS_SetOpaque(obj, &p->image);

		return obj;
	}
	else
		return JS_EXCEPTION;
}

const JSCFunctionListEntry js_rl_char_info_proto_funcs[] =
{
	JS_CGETSET_DEF("value", js_rl_char_info_get_value, NULL),
	JS_CGETSET_DEF("offsetX", js_rl_char_info_get_offset_x, NULL),
	JS_CGETSET_DEF("offsetY", js_rl_char_info_get_offset_y, NULL),
	JS_CGETSET_DEF("advanceX", js_rl_char_info_get_advance_x, NULL),
	JS_CGETSET_DEF("image", js_rl_char_info_get_image, NULL),
};

void js_rl_init_char_info_class(JSContext* ctx, JSModuleDef* m)
{
	JSValue proto;
	JS_NewClassID(&js_rl_char_info_class_id);
	JS_NewClass(JS_GetRuntime(ctx), js_rl_char_info_class_id, &js_rl_char_info_class);
	proto = JS_NewObject(ctx);
	JS_SetPropertyFunctionList(ctx, proto, js_rl_char_info_proto_funcs, countof(js_rl_char_info_proto_funcs));
	JS_SetClassProto(ctx, js_rl_char_info_class_id, proto);
	// JS_NewCFunction2(ctx, js_rl_char_info_constructor, "CharInfo", 1, JS_CFUNC_constructor_or_func, 0);
}

#pragma endregion
#pragma region Font

void js_rl_font_finalizer(JSRuntime* rt, JSValue val)
{
	Font* p = (Font*)JS_GetOpaque(val, js_rl_font_class_id);
	UnloadFont(*p);
}

JSClassDef js_rl_font_class =
{
	"Font",
	.finalizer = js_rl_font_finalizer,
};

JSValue js_rl_font_get_texture(JSContext* ctx, JSValueConst this_val)
{
	Font* p = (Font*)JS_GetOpaque2(ctx, this_val, js_rl_font_class_id);

	if (p)
	{
		JSValue obj = JS_NewObjectClass(ctx, js_rl_image_class_id);
		Texture2D* p2 = js_mallocz(ctx, sizeof(Texture2D));

		if (!p2) {
			JS_FreeValue(ctx, obj);
			return JS_EXCEPTION;
		}

		memcpy(p2, &p->texture, sizeof(Texture2D));
		JS_SetOpaque(obj, p);

		return obj;
	}
	else
		return JS_EXCEPTION;
}

JSValue js_rl_font_get_base_size(JSContext* ctx, JSValueConst this_val)
{
	Font* p = (Font*)JS_GetOpaque2(ctx, this_val, js_rl_font_class_id);

	if (p)
		return JS_NewInt32(ctx, p->baseSize);
	else
		return JS_EXCEPTION;
}

JSValue js_rl_font_get_chars(JSContext* ctx, JSValueConst this_val)
{
	Font* p = (Font*)JS_GetOpaque2(ctx, this_val, js_rl_font_class_id);

	if (p)
	{
		JSValue arr = JS_NewArray(ctx);

		for (int i = 0; i < p->charsCount; i++)
		{
			JSValue obj = JS_NewObjectClass(ctx, js_rl_char_info_class_id);
			CharInfo* character = js_mallocz(ctx, sizeof(CharInfo));
			memcpy(character, p->chars + i, sizeof(Color));
			JS_SetOpaque(obj, character);
			JS_SetPropertyInt64(ctx, arr, i, obj);
		}

		return arr;
	}
	else
		return JS_EXCEPTION;
}

const JSCFunctionListEntry js_rl_font_proto_funcs[] =
{
	JS_CGETSET_DEF("texture", js_rl_font_get_texture, NULL),
	JS_CGETSET_DEF("baseSize", js_rl_font_get_base_size, NULL),
	JS_CGETSET_DEF("chars", js_rl_font_get_chars, NULL),
};

void js_rl_init_font_class(JSContext* ctx, JSModuleDef* m)
{
	JSValue proto;
	JS_NewClassID(&js_rl_font_class_id);
	JS_NewClass(JS_GetRuntime(ctx), js_rl_font_class_id, &js_rl_font_class);
	proto = JS_NewObject(ctx);
	JS_SetPropertyFunctionList(ctx, proto, js_rl_font_proto_funcs, countof(js_rl_font_proto_funcs));
	JS_SetClassProto(ctx, js_rl_font_class_id, proto);
	// JS_NewCFunction2(ctx, js_rl_font_constructor, "Font", 1, JS_CFUNC_constructor_or_func, 0);
}

#pragma endregion

void js_rl_init_classes(JSContext* ctx, JSModuleDef* m)
{
	js_rl_init_image_class(ctx, m);
	js_rl_init_vector2_class(ctx, m);
	js_rl_init_vector3_class(ctx, m);
	js_rl_init_vector4_class(ctx, m);
	js_rl_init_camera2d_class(ctx, m);
	js_rl_init_camera3d_class(ctx, m);
	js_rl_init_texture2d_class(ctx, m);
	js_rl_init_render_texture_class(ctx, m);
	js_rl_init_ray_class(ctx, m);
	js_rl_init_color_class(ctx, m);
	js_rl_init_matrix_class(ctx, m);
	js_rl_init_rectangle_class(ctx, m);
	js_rl_init_font_class(ctx, m);
	js_rl_init_char_info_class(ctx, m);
}

void js_rl_init_module_classes(JSContext* ctx, JSModuleDef* m)
{
	JS_AddModuleExport(ctx, m, "Vector2");
	JS_AddModuleExport(ctx, m, "Vector3");
	JS_AddModuleExport(ctx, m, "Vector4");
	JS_AddModuleExport(ctx, m, "Camera2D");
	JS_AddModuleExport(ctx, m, "Camera3D");
	JS_AddModuleExport(ctx, m, "Texture2D");
	JS_AddModuleExport(ctx, m, "RenderTexture2D");
	JS_AddModuleExport(ctx, m, "Ray");
	JS_AddModuleExport(ctx, m, "Color");
	JS_AddModuleExport(ctx, m, "Matrix");
	JS_AddModuleExport(ctx, m, "Rectangle");
	JS_AddModuleExport(ctx, m, "Font");
	JS_AddModuleExport(ctx, m, "CharInfo");
}
