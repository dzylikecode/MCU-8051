#ifndef DZ_UTILS_H
#define DZ_UTILS_H

typedef unsigned char u8;
typedef unsigned int u16;

#ifndef VSCODE_C_PP_PROPERTIES_JSON
#define set(var, res)           ((var) = (res))
#define setChar(var, res)       set(var, (u8)(res))
#define clsBit(var, bit)        set(var, (var) & (~(1 << (bit))))
#define setBit(var, bit)        set(var, (var) | (1 << (bit)))
#define setBitEx(var, bit, res) setChar(var, clsBit(var, bit) | ((res) << (bit))) // similar to var[bit] = res
#define get(var)                (var)

// copy from RRC: https://sdcc.sourceforge.net/doc/sdccman.pdf
// ! 原来的代码是移动一位, 而且左右搞反了
#define RLC(src, num)          (((src) << num) | ((src) >> (sizeof(src)*8 - num)))
#define RRC(src, num)          (((src) << (sizeof(src)*8-num) ) | ((src) >> num))


#else // cheat vscode

#define set(var, res)           0
#define setChar(var, res)       0
#define setBitEx(var, bit, res) 0 // similar to var[bit] = res
#define get(var)                0

#define P2_0                    0
#define P0                      0
#define __code

#define __asm                   {
#define __endasm                }
#define nop                     ;

#define RRC(res, left)         
#define RLC(res, left)       

#endif // end of VSCODE_C_PP_PROPERTIES_JSON

#endif