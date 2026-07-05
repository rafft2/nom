#ifndef NOM_H

#ifdef NOM_ENABLE_ASSERT
    #define ASSERT(x)\
        do\
        {\
            if(!(x))\
            {\
                printf("assertion failed: %s.\nAt %s line %d\n", #x, __FILE__, __LINE__);\
                *(int *)0 = 0;\
            }\
        } while(0)
#else
    #define ASSERT(x)
#endif

#define Kilobytes(value) ((value) * 1024LL)
#define Megabytes(value) (Kilobytes(value) * 1024LL)
#define Gigabytes(value) (Megabytes(value) * 1024LL)
#define Terabytes(value) (Gigabytes(value) * 1024LL)

#define PI32 3.14159265359f
#define EPSILON32 1e-5f
#define EPSILON64 1e-9

#define DEG2RAD(degrees) ((degrees) * PI32 / 180.0f)
#define RAD2DEG(radians) ((radians) * 180.0f / PI32)
#define MIN(A, B) (((A) < (B)) ? (A) : (B))
#define MAX(A, B) (((A) > (B)) ? (A) : (B))
#define ARRAY_COUNT(arr) (sizeof(arr) / sizeof(arr[0]))

typedef signed long long s64;
typedef unsigned long long u64;
typedef signed int s32;
typedef unsigned int u32;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned int b32;
typedef float f32;
typedef double f64;

f32 SquareRoot(f32 a)
{
    f32 result = sqrtf(a);
    return(result);
}

struct vec2i
{
    s32 x, y;
};

struct vec2
{
    f32 x, y;
};

struct vec3
{
    f32 x, y, z;
};

vec3 Vec3()
{
    vec3 result = { 0.0f, 0.0f, 0.0f };
    return(result);
}

vec3 Vec3(f32 v)
{
    vec3 result = { v, v, v };
    return(result);
}

vec3 Vec3(f32 x, f32 y, f32 z)
{
    vec3 result = { x, y, z };
    return(result);
}

vec3 operator+(vec3 &a, vec3 &b)
{
    vec3 result;
    result.x = a.x + b.x;
    result.y = a.y + b.y;
    result.z = a.z + b.z;
    return(result);
}

vec3 &operator+=(vec3 &a, vec3 &b)
{
    a.x += b.x;
    a.y += b.y;
    a.z += b.z;
    return(a);
}

vec3 &operator/=(vec3 &a, f32 b)
{
    a.x /= b;
    a.y /= b;
    a.z /= b;
    return(a);
}

f32 DotProduct(vec3 a, vec3 b)
{
    f32 result = a.x * b.x + a.y * b.y + a.z * b.z;
    return(result);
}

f32 LengthSquared(vec3 a)
{
    f32 result = DotProduct(a, a);
    return(result);
}

f32 Length(vec3 a)
{
    f32 result = SquareRoot(LengthSquared(a));
    return(result);
}

vec3 Normalize(vec3 v)
{
    f32 length = Length(v);
    if(length > 0)
    {
        vec3 result = { v.x / length, v.y / length, v.z / length };
        return(result);
    }
    return(v);
}

vec3 CrossProduct(vec3 a, vec3 b)
{
    vec3 result;
    result.x = a.y * b.z - a.z * b.y;
    result.y = a.z * b.x - a.x * b.z;
    result.z = a.x * b.y - a.y * b.x;
    return(result);
}

struct mat4x4
{
    f32 e[4][4];
 
    f32* operator[](u8 i) { return e[i]; }
};

mat4x4 operator*(mat4x4 &A, mat4x4 &B)
{
    mat4x4 result;
    for(u32 i = 0; i < 4; i++)
    {
        for(u32 j = 0; j < 4; j++)
        {
            result.e[i][j] = A.e[i][0] * B.e[0][j] +
                             A.e[i][1] * B.e[1][j] +
                             A.e[i][2] * B.e[2][j] +
                             A.e[i][3] * B.e[3][j];
        }
    }
    return(result);
}

mat4x4 Identity()
{
    mat4x4 result = {1, 0, 0, 0,
                     0, 1, 0, 0,
                     0, 0, 1, 0,
                     0, 0, 0, 1};
    return(result);
}

mat4x4 Transpose(mat4x4 A)
{
    mat4x4 result;
    for(u32 i = 0; i < 4; i++)
    {
        for(u32 j = 0; j < 4; j++)
        {
            result.e[i][j] = A.e[j][i];
        }
    }
    return(result);
}

mat4x4 Scaling(f32 a, f32 b, f32 c)
{
    mat4x4 result = {a, 0, 0, 0,
                     0, b, 0, 0,
                     0, 0, c, 0,
                     0, 0, 0, 1};
    return(result);
}

mat4x4 Scaling(f32 s)
{
    mat4x4 result = Scaling(s, s, s);
    return(result);
}

mat4x4 RotationX(f32 theta)
{
    mat4x4 result = {1, 0, 0, 0,
                     0, cosf(theta), sinf(theta), 0,
                     0, -sinf(theta), cosf(theta), 0,
                     0, 0, 0, 1};
    return(result);
}

mat4x4 RotationY(f32 theta)
{
    mat4x4 result = {cosf(theta), 0, -sinf(theta), 0,
                     0, 1, 0, 0,
                     sinf(theta), 0, cosf(theta), 0,
                     0, 0, 0, 1};
    return(result);
}

mat4x4 RotationZ(f32 theta)
{
    mat4x4 result = {cosf(theta), sinf(theta), 0, 0,
                     -sinf(theta), cosf(theta), 0, 0,
                     0, 0, 1, 0,
                     0, 0, 0, 1};
    return(result);
}

mat4x4 Translation(f32 a, f32 b, f32 c)
{
    mat4x4 result = {1, 0, 0, 0,
                     0, 1, 0, 0,
                     0, 0, 1, 0,
                     a, b, c, 1};
    return(result);
}

#define NOM_H
#endif