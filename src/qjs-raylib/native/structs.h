#include "stdio.h"
#include "string.h"

#include "quickjs/quickjs.h"
#include "quickjs/cutils.h"
#include "raylib/raylib.h"

#pragma region Image

JSClassID js_rl_image_class_id;

void js_rl_init_image_class(JSContext* ctx, JSModuleDef* m);
void js_rl_image_finalizer(JSRuntime* rt, JSValue val);

JSValue js_rl_image_get_width(JSContext* ctx, JSValueConst this_val);
JSValue js_rl_image_get_height(JSContext* ctx, JSValueConst this_val);
JSValue js_rl_image_get_format(JSContext* ctx, JSValueConst this_val);
JSValue js_rl_image_get_mipmaps(JSContext* ctx, JSValueConst this_val);

#pragma endregion
#pragma region Vector2

JSClassID js_rl_vector2_class_id;

JSValue js_rl_new_vector2(JSContext* ctx, double x, double y);
JSValue js_rl_vector2_constructor(JSContext* ctx, JSValueConst new_target, int argc, JSValueConst *argv);

void js_rl_init_vector2_class(JSContext* ctx, JSModuleDef* m);

JSValue js_rl_vector2_get_x(JSContext* ctx, JSValueConst this_val);
JSValue js_rl_vector2_set_x(JSContext* ctx, JSValueConst this_val, JSValueConst v);
JSValue js_rl_vector2_get_y(JSContext* ctx, JSValueConst this_val);
JSValue js_rl_vector2_set_y(JSContext* ctx, JSValueConst this_val, JSValueConst v);

#pragma endregion
#pragma region Vector3

JSClassID js_rl_vector3_class_id;

JSValue js_rl_new_vector3(JSContext* ctx, int x, int y, int z);
JSValue js_rl_vector3_constructor(JSContext* ctx, JSValueConst new_target, int argc, JSValueConst *argv);

void js_rl_init_vector3_class(JSContext* ctx, JSModuleDef* m);

JSValue js_rl_vector3_get_x(JSContext* ctx, JSValueConst this_val);
JSValue js_rl_vector3_set_x(JSContext* ctx, JSValueConst this_val, JSValueConst v);
JSValue js_rl_vector3_get_y(JSContext* ctx, JSValueConst this_val);
JSValue js_rl_vector3_set_y(JSContext* ctx, JSValueConst this_val, JSValueConst v);
JSValue js_rl_vector3_get_z(JSContext* ctx, JSValueConst this_val);
JSValue js_rl_vector3_set_z(JSContext* ctx, JSValueConst this_val, JSValueConst v);

#pragma endregion
#pragma region Vector4

JSClassID js_rl_vector4_class_id;

JSValue js_rl_new_vector4(JSContext* ctx, double x, double y, double z, double w);
JSValue js_rl_vector4_constructor(JSContext* ctx, JSValueConst new_target, int argc, JSValueConst *argv);

void js_rl_init_vector4_class(JSContext* ctx, JSModuleDef* m);

JSValue js_rl_vector4_get_x(JSContext* ctx, JSValueConst this_val);
JSValue js_rl_vector4_set_x(JSContext* ctx, JSValueConst this_val, JSValueConst v);
JSValue js_rl_vector4_get_y(JSContext* ctx, JSValueConst this_val);
JSValue js_rl_vector4_set_y(JSContext* ctx, JSValueConst this_val, JSValueConst v);
JSValue js_rl_vector4_get_z(JSContext* ctx, JSValueConst this_val);
JSValue js_rl_vector4_set_z(JSContext* ctx, JSValueConst this_val, JSValueConst v);
JSValue js_rl_vector4_get_w(JSContext* ctx, JSValueConst this_val);
JSValue js_rl_vector4_set_w(JSContext* ctx, JSValueConst this_val, JSValueConst v);

#pragma endregion
#pragma region Camera2D

JSClassID js_rl_camera2d_class_id;

JSValue js_rl_new_camera2d(JSContext* ctx, Vector2 offset, Vector2 target, double rotation, double zoom);
JSValue js_rl_camera2d_constructor(JSContext* ctx, JSValueConst new_target, int argc, JSValueConst *argv);

void js_rl_init_camera2d_class(JSContext* ctx, JSModuleDef* m);

JSValue js_rl_camera2d_get_offset(JSContext* ctx, JSValueConst this_val);
JSValue js_rl_camera2d_set_offset(JSContext* ctx, JSValueConst this_val, JSValueConst v);
JSValue js_rl_camera2d_get_target(JSContext* ctx, JSValueConst this_val);
JSValue js_rl_camera2d_set_target(JSContext* ctx, JSValueConst this_val, JSValueConst v);
JSValue js_rl_camera2d_get_rotation(JSContext* ctx, JSValueConst this_val);
JSValue js_rl_camera2d_set_rotation(JSContext* ctx, JSValueConst this_val, JSValueConst v);
JSValue js_rl_camera2d_get_zoom(JSContext* ctx, JSValueConst this_val);
JSValue js_rl_camera2d_set_zoom(JSContext* ctx, JSValueConst this_val, JSValueConst v);

#pragma endregion
#pragma region Camera3D

JSClassID js_rl_camera3d_class_id;

JSValue js_rl_new_camera3d(JSContext* ctx, Vector3 position, Vector3 target, Vector3 up, double fovy, int type);
JSValue js_rl_camera3d_constructor(JSContext* ctx, JSValueConst new_target, int argc, JSValueConst *argv);

void js_rl_init_camera3d_class(JSContext* ctx, JSModuleDef* m);

JSValue js_rl_camera3d_get_position(JSContext* ctx, JSValueConst this_val);
JSValue js_rl_camera3d_set_position(JSContext* ctx, JSValueConst this_val, JSValueConst v);
JSValue js_rl_camera3d_get_target(JSContext* ctx, JSValueConst this_val);
JSValue js_rl_camera3d_set_target(JSContext* ctx, JSValueConst this_val, JSValueConst v);
JSValue js_rl_camera3d_get_up(JSContext* ctx, JSValueConst this_val);
JSValue js_rl_camera3d_set_up(JSContext* ctx, JSValueConst this_val, JSValueConst v);
JSValue js_rl_camera3d_get_fov_y(JSContext* ctx, JSValueConst this_val);
JSValue js_rl_camera3d_set_fov_y(JSContext* ctx, JSValueConst this_val, JSValueConst v);
JSValue js_rl_camera3d_get_type(JSContext* ctx, JSValueConst this_val);
JSValue js_rl_camera3d_set_type(JSContext* ctx, JSValueConst this_val, JSValueConst v);

#pragma endregion
#pragma region Texture2D

JSClassID js_rl_texture2d_class_id;

void js_rl_init_texture2d_class(JSContext* ctx, JSModuleDef* m);
void js_rl_texture2d_finalizer(JSRuntime* rt, JSValue val);

JSValue js_rl_texture2d_get_id(JSContext* ctx, JSValueConst this_val);
JSValue js_rl_texture2d_get_width(JSContext* ctx, JSValueConst this_val);
JSValue js_rl_texture2d_get_height(JSContext* ctx, JSValueConst this_val);
JSValue js_rl_texture2d_get_format(JSContext* ctx, JSValueConst this_val);
JSValue js_rl_texture2d_get_mipmaps(JSContext* ctx, JSValueConst this_val);

#pragma endregion
#pragma region RenderTexture

JSClassID js_rl_render_texture_class_id;

JSValue js_rl_render_texture_constructor(JSContext* ctx, JSValueConst new_target, int argc, JSValueConst *argv);

void js_rl_init_render_texture_class(JSContext* ctx, JSModuleDef* m);
void js_rl_render_texture_finalizer(JSRuntime* rt, JSValue val);

JSValue js_rl_render_texture_get_id(JSContext* ctx, JSValueConst this_val);
JSValue js_rl_render_texture_set_id(JSContext* ctx, JSValueConst this_val, JSValueConst v);
JSValue js_rl_render_texture_get_texture(JSContext* ctx, JSValueConst this_val);
JSValue js_rl_render_texture_set_texture(JSContext* ctx, JSValueConst this_val, JSValueConst v);
JSValue js_rl_render_texture_get_depth(JSContext* ctx, JSValueConst this_val);
JSValue js_rl_render_texture_set_depth(JSContext* ctx, JSValueConst this_val, JSValueConst v);
JSValue js_rl_render_texture_get_depth_texture(JSContext* ctx, JSValueConst this_val);
JSValue js_rl_render_texture_set_depth_texture(JSContext* ctx, JSValueConst this_val, JSValueConst v);

#pragma endregion
#pragma region Ray

JSClassID js_rl_ray_class_id;

JSValue js_rl_new_ray(JSContext* ctx, Vector3 position, Vector3 direction);
JSValue js_rl_ray_constructor(JSContext* ctx, JSValueConst new_target, int argc, JSValueConst *argv);

void js_rl_init_ray_class(JSContext* ctx, JSModuleDef* m);

JSValue js_rl_ray_get_position(JSContext* ctx, JSValueConst this_val);
JSValue js_rl_ray_set_position(JSContext* ctx, JSValueConst this_val, JSValueConst v);
JSValue js_rl_ray_get_direction(JSContext* ctx, JSValueConst this_val);
JSValue js_rl_ray_set_direction(JSContext* ctx, JSValueConst this_val, JSValueConst v);

#pragma endregion
#pragma region Matrix

JSClassID js_rl_matrix_class_id;

JSValue js_rl_new_matrix(JSContext* ctx, double m0, double m1, double m2, double m3, double m4, double m5, double m6, double m7, double m8, double m9, double m10, double m11, double m12, double m13, double m14, double m15);
JSValue js_rl_matrix_constructor(JSContext* ctx, JSValueConst new_target, int argc, JSValueConst *argv);

void js_rl_init_matrix_class(JSContext* ctx, JSModuleDef* m);

JSValue js_rl_matrix_get_m0(JSContext* ctx, JSValueConst this_val);
JSValue js_rl_matrix_get_m1(JSContext* ctx, JSValueConst this_val);
JSValue js_rl_matrix_get_m2(JSContext* ctx, JSValueConst this_val);
JSValue js_rl_matrix_get_m3(JSContext* ctx, JSValueConst this_val);
JSValue js_rl_matrix_get_m4(JSContext* ctx, JSValueConst this_val);
JSValue js_rl_matrix_get_m5(JSContext* ctx, JSValueConst this_val);
JSValue js_rl_matrix_get_m6(JSContext* ctx, JSValueConst this_val);
JSValue js_rl_matrix_get_m7(JSContext* ctx, JSValueConst this_val);
JSValue js_rl_matrix_get_m8(JSContext* ctx, JSValueConst this_val);
JSValue js_rl_matrix_get_m9(JSContext* ctx, JSValueConst this_val);
JSValue js_rl_matrix_get_m10(JSContext* ctx, JSValueConst this_val);
JSValue js_rl_matrix_get_m11(JSContext* ctx, JSValueConst this_val);
JSValue js_rl_matrix_get_m12(JSContext* ctx, JSValueConst this_val);
JSValue js_rl_matrix_get_m13(JSContext* ctx, JSValueConst this_val);
JSValue js_rl_matrix_get_m14(JSContext* ctx, JSValueConst this_val);
JSValue js_rl_matrix_get_m15(JSContext* ctx, JSValueConst this_val);

JSValue js_rl_matrix_set_m0(JSContext* ctx, JSValueConst this_val, JSValueConst v);
JSValue js_rl_matrix_set_m1(JSContext* ctx, JSValueConst this_val, JSValueConst v);
JSValue js_rl_matrix_set_m2(JSContext* ctx, JSValueConst this_val, JSValueConst v);
JSValue js_rl_matrix_set_m3(JSContext* ctx, JSValueConst this_val, JSValueConst v);
JSValue js_rl_matrix_set_m4(JSContext* ctx, JSValueConst this_val, JSValueConst v);
JSValue js_rl_matrix_set_m5(JSContext* ctx, JSValueConst this_val, JSValueConst v);
JSValue js_rl_matrix_set_m6(JSContext* ctx, JSValueConst this_val, JSValueConst v);
JSValue js_rl_matrix_set_m7(JSContext* ctx, JSValueConst this_val, JSValueConst v);
JSValue js_rl_matrix_set_m8(JSContext* ctx, JSValueConst this_val, JSValueConst v);
JSValue js_rl_matrix_set_m9(JSContext* ctx, JSValueConst this_val, JSValueConst v);
JSValue js_rl_matrix_set_m10(JSContext* ctx, JSValueConst this_val, JSValueConst v);
JSValue js_rl_matrix_set_m11(JSContext* ctx, JSValueConst this_val, JSValueConst v);
JSValue js_rl_matrix_set_m12(JSContext* ctx, JSValueConst this_val, JSValueConst v);
JSValue js_rl_matrix_set_m13(JSContext* ctx, JSValueConst this_val, JSValueConst v);
JSValue js_rl_matrix_set_m14(JSContext* ctx, JSValueConst this_val, JSValueConst v);
JSValue js_rl_matrix_set_m15(JSContext* ctx, JSValueConst this_val, JSValueConst v);

#pragma endregion
#pragma region Color

JSClassID js_rl_color_class_id;

JSValue js_rl_new_color(JSContext* ctx, int r, int g, int b, int a);
JSValue js_rl_color_constructor(JSContext* ctx, JSValueConst new_target, int argc, JSValueConst *argv);

void js_rl_init_color_class(JSContext* ctx, JSModuleDef* m);

JSValue js_rl_color_get_r(JSContext* ctx, JSValueConst this_val);
JSValue js_rl_color_set_r(JSContext* ctx, JSValueConst this_val, JSValueConst v);
JSValue js_rl_color_get_g(JSContext* ctx, JSValueConst this_val);
JSValue js_rl_color_set_g(JSContext* ctx, JSValueConst this_val, JSValueConst v);
JSValue js_rl_color_get_b(JSContext* ctx, JSValueConst this_val);
JSValue js_rl_color_set_b(JSContext* ctx, JSValueConst this_val, JSValueConst v);
JSValue js_rl_color_get_a(JSContext* ctx, JSValueConst this_val);
JSValue js_rl_color_set_a(JSContext* ctx, JSValueConst this_val, JSValueConst v);

#pragma endregion
#pragma region Rectangle

JSClassID js_rl_rectangle_class_id;

JSValue js_rl_new_rectangle(JSContext* ctx, double x, double y, double w, double h);
JSValue js_rl_rectangle_constructor(JSContext* ctx, JSValueConst new_target, int argc, JSValueConst *argv);

void js_rl_init_rectangle_class(JSContext* ctx, JSModuleDef* m);

JSValue js_rl_rectangle_get_x(JSContext* ctx, JSValueConst this_val);
JSValue js_rl_rectangle_set_x(JSContext* ctx, JSValueConst this_val, JSValueConst v);
JSValue js_rl_rectangle_get_y(JSContext* ctx, JSValueConst this_val);
JSValue js_rl_rectangle_set_y(JSContext* ctx, JSValueConst this_val, JSValueConst v);
JSValue js_rl_rectangle_get_width(JSContext* ctx, JSValueConst this_val);
JSValue js_rl_rectangle_set_width(JSContext* ctx, JSValueConst this_val, JSValueConst v);
JSValue js_rl_rectangle_get_height(JSContext* ctx, JSValueConst this_val);
JSValue js_rl_rectangle_set_height(JSContext* ctx, JSValueConst this_val, JSValueConst v);

#pragma endregion
#pragma region CharInfo

JSClassID js_rl_char_info_class_id;

void js_rl_init_char_info_class(JSContext* ctx, JSModuleDef* m);

JSValue js_rl_char_info_get_value(JSContext* ctx, JSValueConst this_val);
JSValue js_rl_char_info_get_rectangle(JSContext* ctx, JSValueConst this_val);
JSValue js_rl_char_info_get_offset_x(JSContext* ctx, JSValueConst this_val);
JSValue js_rl_char_info_get_offset_y(JSContext* ctx, JSValueConst this_val);
JSValue js_rl_char_info_get_advance_x(JSContext* ctx, JSValueConst this_val);

#pragma endregion
#pragma region Font

JSClassID js_rl_font_class_id;

void js_rl_init_font_class(JSContext* ctx, JSModuleDef* m);
void js_rl_font_finalizer(JSRuntime* rt, JSValue val);

JSValue js_rl_font_get_texture(JSContext* ctx, JSValueConst this_val);
JSValue js_rl_font_get_base_size(JSContext* ctx, JSValueConst this_val);
JSValue js_rl_font_get_chars(JSContext* ctx, JSValueConst this_val);

#pragma endregion

void js_rl_init_classes(JSContext* ctx, JSModuleDef* m);
void js_rl_init_module_classes(JSContext* ctx, JSModuleDef* m);
