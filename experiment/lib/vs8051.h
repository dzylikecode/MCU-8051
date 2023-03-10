

#ifndef VS8051_H
#define VS8051_H

/*  BYTE Register  */
#define P0
#define SP
#define DPL
#define DPH
#define PCON
#define TCON
#define TMOD
#define TL0
#define TL1
#define TH0
#define TH1
#define P1
#define SCON
#define SBUF
#define P2
#define IE
#define P3
#define IP
#define PSW
#define ACC
#define B

/*  BIT Register  */
/* P0 */
#define P0_0
#define P0_1
#define P0_2
#define P0_3
#define P0_4
#define P0_5
#define P0_6
#define P0_7

/*  TCON  */
#define IT0
#define IE0
#define IT1
#define IE1
#define TR0
#define TF0
#define TR1
#define TF1

/* P1 */
#define P1_0
#define P1_1
#define P1_2
#define P1_3
#define P1_4
#define P1_5
#define P1_6
#define P1_7

/*  SCON  */
#define RI
#define TI
#define RB8
#define TB8
#define REN
#define SM2
#define SM1
#define SM0

/* P2 */
#define P2_0
#define P2_1
#define P2_2
#define P2_3
#define P2_4
#define P2_5
#define P2_6
#define P2_7

/*  IE   */
#define EX0
#define ET0
#define EX1
#define ET1
#define ES
#define EA

/*  P3  */
#define P3_0
#define P3_1
#define P3_2
#define P3_3
#define P3_4
#define P3_5
#define P3_6
#define P3_7

#define RXD
#define TXD
#define INT0
#define INT1
#define T0
#define T1
#define WR
#define RD

/*  IP   */
#define PX0
#define PT0
#define PX1
#define PT1
#define PS

/*  PSW   */
#define P
#define F1
#define OV
#define RS0
#define RS1
#define F0
#define AC
#define CY

/* BIT definitions for bits that are not directly accessible */
/* PCON bits */
#define IDL
#define PD
#define GF0
#define GF1
#define SMOD

/* TMOD bits */
#define T0_M0
#define T0_M1
#define T0_CT
#define T0_GATE
#define T1_M0
#define T1_M1
#define T1_CT
#define T1_GATE

#define T0_MASK
#define T1_MASK

/* Interrupt numbers: address = (number * 8) + 3 */
#define IE0_VECTOR /* 0x03 external interrupt 0 */
#define TF0_VECTOR /* 0x0b timer 0 */
#define IE1_VECTOR /* 0x13 external interrupt 1 */
#define TF1_VECTOR /* 0x1b timer 1 */
#define SI0_VECTOR /* 0x23 serial port 0 */

#endif
