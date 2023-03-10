#ifndef VS8052_H
#define VS8052_H

#include "vs8051.h" /* load definitions for the 8051 core */

#ifdef VS8051_H
#undef VS8051_H
#endif

/* define 8052 specific registers only */

/* T2CON */
#define T2CON

/* RCAP2 L & H */
#define RCAP2L
#define RCAP2H
#define TL2
#define TH2

/*  IE  */
#define ET2 /* Enable timer2 interrupt */

/*  IP  */
#define PT2 /* T2 interrupt priority bit */

/* T2CON bits */
#define T2CON_0
#define T2CON_1
#define T2CON_2
#define T2CON_3
#define T2CON_4
#define T2CON_5
#define T2CON_6
#define T2CON_7

#define CP_RL2
#define C_T2
#define TR2
#define EXEN2
#define TCLK
#define RCLK
#define EXF2
#define TF2

#endif
