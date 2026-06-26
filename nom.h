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

#define Kilobyes(value) ((value) * 1024LL)
#define Megabytes(value) (Kilobyes(value) * 1024LL)
#define Gigabytes(value) (Megabytes(value) * 1024LL)
#define Terabytes(value) (Gigabytes(value) * 1024LL)

#define PI32 3.14159265359f
#define EPSILON32 1e-5f
#define EPSILON64 1e-9

#define DEG2RAD(degrees) ((degrees) * PI32 / 180.0f)
#define RAD2DEG(radians) ((radians) * 180.0f / PI32)
#define MIN(A, B) (((A) < (B)) ? (A) : (B))
#define MAX(A, B) (((A) > (B)) ? (A) : (B))
#define ARRAY_COUNT(arr) sizeof(arr) / sizeof(arr[0])

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

#define NOM_H
#endif