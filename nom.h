#ifndef NOM_H

#ifdef NOM_ASSERTIONS_ENABLED
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

#define NOM_H
#endif