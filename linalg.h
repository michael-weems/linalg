#ifndef MDWI_INCLUDE_MDW_LINALG_H
#define MDWI_INCLUDE_MDW_LINALG_H

#define MDWI_VERSION 1

#include <stdlib.h>
#include <string.h>

typedef float Vector2_F32[2];
typedef float Vector3_F32[3];
typedef float Vector4_F32[4];

typedef float Matrix2_F32[2][2];
typedef float Matrix3_F32[3][3];
typedef float Matrix4_F32[4][4];

extern void mdwi_matrix2_f32_identity(Matrix2_F32 m); 
extern void mdwi_matrix3_f32_identity(Matrix3_F32 m); 
extern void mdwi_matrix4_f32_identity(Matrix4_F32 m); 

extern void mdwi_matrix3_f32_translate(Matrix3_F32 m, Vector2_F32 v); 
extern void mdwi_matrix4_f32_translate(Matrix4_F32 m, Vector3_F32 v); 

extern void mdwi_vector2_f32_scale  (Vector2_F32 v, float scalar);
extern void mdwi_vector3_f32_scale  (Vector3_F32 v, float scalar);
extern void mdwi_vector4_f32_scale  (Vector4_F32 v, float scalar);

extern void mdwi_vector2_f32_transform_matrix2_f32          (Vector2_F32 v, Matrix2_F32 m);
extern void mdwi_vector3_f32_transform_matrix3_f32          (Vector3_F32 v, Matrix3_F32 m);
extern void mdwi_vector4_f32_transform_matrix4_f32          (Vector4_F32 v, Matrix4_F32 m);

//
//
////   end header file   /////////////////////////////////////////////////////
#endif // MDWI_INCLUDE_MDW_IMAGE_H

#ifdef MDW_LINALG_IMPLEMENTATION

//#include <stdarg.h>
#include <stddef.h>
//#include <stdint.h>
//#include <stdlib.h>
//#include <math.h>  
//#include <assert.h>

const Matrix2_F32 M2_IDENTITY = {
	{1.0, 0.0},
	{0.0, 1.0}
};
const Matrix3_F32 M3_IDENTITY = {
	{1.0, 0.0, 0.0},
	{0.0, 1.0, 0.0},
	{0.0, 0.0, 1.0}
};
const Matrix4_F32 M4_IDENTITY = {
	{1.0, 0.0, 0.0, 0.0},
	{0.0, 1.0, 0.0, 0.0},
	{0.0, 0.0, 1.0, 0.0},
	{0.0, 0.0, 0.0, 1.0}
};

inline void mdwi_matrix2_f32_identity(Matrix2_F32 m) {
	memcpy(m, M2_IDENTITY, sizeof(Matrix2_F32));
}
inline void mdwi_matrix3_f32_identity(Matrix3_F32 m) {
	memcpy(m, M3_IDENTITY, sizeof(Matrix3_F32));
}
inline void mdwi_matrix4_f32_identity(Matrix4_F32 m) {
	memcpy(m, M4_IDENTITY, sizeof(Matrix4_F32));
}

inline void mdwi_matrix3_f32_translate(Matrix3_F32 m, Vector2_F32 v) {
	mdwi_matrix3_f32_identity(m);
	m[2][0] = v[0];
	m[2][1] = v[1];
}
inline void mdwi_matrix4_f32_translate(Matrix4_F32 m, Vector3_F32 v) {
	mdwi_matrix4_f32_identity(m);
	m[3][0] = v[0];
	m[3][1] = v[1];
	m[3][2] = v[2];
}

inline void mdwi_vector2_f32_scale(Vector2_F32 v, float scalar) {
	v[0] *= scalar;
	v[1] *= scalar;
}

inline void mdwi_vector3_f32_scale(Vector3_F32 v, float scalar) {
	v[0] *= scalar;
	v[1] *= scalar;
	v[2] *= scalar;
}

inline void mdwi_vector4_f32_scale(Vector4_F32 v, float scalar) {
	v[0] *= scalar;
	v[1] *= scalar;
	v[2] *= scalar;
	v[3] *= scalar;
}

inline void mdwi_vector2_f32_transform_matrix2_f32(Vector2_F32 v, Matrix2_F32 m) {
	Vector2_F32 o = {0.0,0.0};
	o[0] = v[0];
	o[1] = v[1];

	o[0] = v[0] * m[0][0] + v[1] * m[1][0];
	o[1] = v[0] * m[0][1] + v[1] * m[1][1];

	v[0] = o[0];
	v[1] = o[1];
}
inline void mdwi_vector3_f32_transform_matrix3_f32(Vector3_F32 v, Matrix3_F32 m) {
	Vector3_F32 o = {0.0,0.0,0.0};
	o[0] = v[0];
	o[1] = v[1];
	o[2] = v[2];

	o[0] = v[0] * m[0][0] + v[1] * m[1][0] + v[2] * m[2][0];
	o[1] = v[0] * m[0][1] + v[1] * m[1][1] + v[2] * m[2][1];
	o[2] = v[0] * m[0][2] + v[1] * m[1][2] + v[2] * m[2][2];

	v[0] = o[0];
	v[1] = o[1];
	v[2] = o[2];
}
inline void mdwi_vector4_f32_transform_matrix4_f32(Vector4_F32 v, Matrix4_F32 m) {
	Vector4_F32 o = {0.0,0.0,0.0,0.0};
	o[0] = v[0];
	o[1] = v[1];
	o[2] = v[2];
	o[3] = v[3];

	o[0] = v[0] * m[0][0] + v[1] * m[1][0] + v[2] * m[2][0] + v[3] * m[3][0];
	o[1] = v[0] * m[0][1] + v[1] * m[1][1] + v[2] * m[2][1] + v[3] * m[3][1];
	o[2] = v[0] * m[0][2] + v[1] * m[1][2] + v[2] * m[2][2] + v[3] * m[3][2];
	o[3] = v[0] * m[0][3] + v[1] * m[1][3] + v[2] * m[2][3] + v[3] * m[3][3];

	v[0] = o[0];
	v[1] = o[1];
	v[2] = o[2];
	v[3] = o[3];
}

#endif // MDW_LINALG_IMPLEMENTATION
