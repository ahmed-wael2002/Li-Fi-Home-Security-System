#ifndef TYPES_H
#define TYPES_H

/* Boolean Data Type */
typedef unsigned char boolean;

/* Boolean Values */
#ifndef FALSE
#define FALSE       (0u)
#endif
#ifndef TRUE
#define TRUE        (1u)
#endif

#define NULL   ((void*)0)

typedef unsigned char           uint8;
typedef unsigned short          uint16;
typedef unsigned long           uint32;
typedef unsigned long long      uint64;
typedef float                   float32;
typedef double                  float64;
typedef unsigned char*          uint8_ptr;
typedef unsigned short*         uint16_ptr;
typedef unsigned long*          uint32_ptr;
typedef unsigned long long*     uint64_ptr;
typedef float*                  float32_ptr;
typedef double*                 float64_ptr;
typedef signed char             int8;
typedef signed short            int16;
typedef signed long             int32;
typedef signed long long        int64;
typedef signed char*            int8_ptr;
typedef signed short*           int16_ptr;
typedef signed long*            int32_ptr;
typedef signed long long *      int64_ptr;

#endif