#ifndef MDWI_INCLUDE_MDW_LINALG_H
#define MDWI_INCLUDE_MDW_LINALG_H

#define MDWI_VERSION 1

#include <stdlib.h>

typedef float Vector2_F32[2];
typedef float Vector3_F32[3];
typedef float Vector4_F32[4];

typedef float Matrix2_F32[2][2];
typedef float Matrix3_F32[3][3];
typedef float Matrix4_F32[4][4];

extern void mdwi_vector2_f32_scale               (Vector2_F32 v, float scalar);
extern void mdwi_vector3_f32_scale               (Vector3_F32 v, float scalar);
extern void mdwi_vector4_f32_scale               (Vector4_F32 v, float scalar);

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

#endif // MDW_LINALG_IMPLEMENTATION
