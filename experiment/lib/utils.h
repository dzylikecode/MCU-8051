#ifndef DZ_UTILS_H
#define DZ_UTILS_H

typedef unsigned char u8;
typedef unsigned int u16;

#ifndef VSCODE_C_PP_PROPERTIES_JSON
#define set(var, res) ((var) = (res))
#define setChar(var, res) set(var, (u8)(res))
#define getMask1(bit) (1 << (bit))
#define getMask0(bit) (~getMask1(bit))
#define clsBit(var, bit) set(var, (var)&getMask0(bit))
#define setBit(var, bit) set(var, (var) | getMask1(bit))
#define setBitEx(var, bit, res) setChar(var, clsBit(var, bit) | ((res) << (bit)))
#define get(var) (var)

#else // for vscode

#define set(var, res) 0
#define setChar(var, res) 0
#define setBitEx(var, bit, res) 0
#define get(var) 0

#define P2_0 0
#define __code
#endif // end of VSCODE_C_PP_PROPERTIES_JSON

#endif