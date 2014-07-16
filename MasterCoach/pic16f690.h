
#ifndef	_HTC_H_
#warning Header file pic16f690.h included directly. Use #include <htc.h> instead.
#endif

/* header file for the MICROCHIP PIC microcontroller
 *  16F690
 */


#ifndef __PIC16F690_H
#define __PIC16F690_H

//
// Configuration mask definitions
//


// Config Register: CONFIG
#define CONFIG               0x2007
// Oscillator Selection bits
// RC oscillator: CLKOUT function on RA4/OSC2/CLKOUT pin, RC on RA5/OSC1/CLKIN
#define FOSC_EXTRCCLK        0xFFFF
// RCIO oscillator: I/O function on RA4/OSC2/CLKOUT pin, RC on RA5/OSC1/CLKIN
#define FOSC_EXTRCIO         0xFFFE
// INTOSC oscillator: CLKOUT function on RA4/OSC2/CLKOUT pin, I/O function on RA5/OSC1/CLKIN
#define FOSC_INTRCCLK        0xFFFD
// INTOSCIO oscillator: I/O function on RA4/OSC2/CLKOUT pin, I/O function on RA5/OSC1/CLKIN
#define FOSC_INTRCIO         0xFFFC
// EC: I/O function on RA4/OSC2/CLKOUT pin, CLKIN on RA5/OSC1/CLKIN
#define FOSC_EC              0xFFFB
// HS oscillator: High-speed crystal/resonator on RA4/OSC2/CLKOUT and RA5/OSC1/CLKIN
#define FOSC_HS              0xFFFA
// XT oscillator: Crystal/resonator on RA4/OSC2/CLKOUT and RA5/OSC1/CLKIN
#define FOSC_XT              0xFFF9
// LP oscillator: Low-power crystal on RA4/OSC2/CLKOUT and RA5/OSC1/CLKIN
#define FOSC_LP              0xFFF8
// Watchdog Timer Enable bit
// WDT enabled
#define WDTE_ON              0xFFFF
// WDT disabled and can be enabled by SWDTEN bit of the WDTCON register
#define WDTE_OFF             0xFFF7
// Power-up Timer Enable bit
// PWRT disabled
#define PWRTE_OFF            0xFFFF
// PWRT enabled
#define PWRTE_ON             0xFFEF
// MCLR Pin Function Select bit
// MCLR pin function is MCLR
#define MCLRE_ON             0xFFFF
// MCLR pin function is digital input, MCLR internally tied to VDD
#define MCLRE_OFF            0xFFDF
// Code Protection bit
// Program memory code protection is disabled
#define CP_OFF               0xFFFF
// Program memory code protection is enabled
#define CP_ON                0xFFBF
// Data Code Protection bit
// Data memory code protection is disabled
#define CPD_OFF              0xFFFF
// Data memory code protection is enabled
#define CPD_ON               0xFF7F
// Brown-out Reset Selection bits
// BOR enabled
#define BOREN_ON             0xFFFF
// BOR enabled during operation and disabled in Sleep
#define BOREN_NSLEEP         0xFEFF
// BOR controlled by SBOREN bit of the PCON register
#define BOREN_SBODEN         0xFDFF
// BOR disabled
#define BOREN_OFF            0xFCFF
// Internal External Switchover bit
// Internal External Switchover mode is enabled
#define IESO_ON              0xFFFF
// Internal External Switchover mode is disabled
#define IESO_OFF             0xFBFF
// Fail-Safe Clock Monitor Enabled bit
// Fail-Safe Clock Monitor is enabled
#define FCMEN_ON             0xFFFF
// Fail-Safe Clock Monitor is disabled
#define FCMEN_OFF            0xF7FF


//
// Special function register definitions
//


// Register: INDF
volatile unsigned char           INDF                @ 0x000;
// bit and bitfield definitions

// Register: TMR0
volatile unsigned char           TMR0                @ 0x001;
// bit and bitfield definitions

// Register: PCL
volatile unsigned char           PCL                 @ 0x002;
// bit and bitfield definitions

// Register: STATUS
volatile unsigned char           STATUS              @ 0x003;
// bit and bitfield definitions
volatile bit CARRY               @ ((unsigned)&STATUS*8)+0;
volatile bit DC                  @ ((unsigned)&STATUS*8)+1;
volatile bit ZERO                @ ((unsigned)&STATUS*8)+2;
volatile bit nPD                 @ ((unsigned)&STATUS*8)+3;
volatile bit nTO                 @ ((unsigned)&STATUS*8)+4;
volatile bit IRP                 @ ((unsigned)&STATUS*8)+7;
volatile bit RP0                 @ ((unsigned)&STATUS*8)+5;
volatile bit RP1                 @ ((unsigned)&STATUS*8)+6;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	C                   : 1;
        unsigned	DC                  : 1;
        unsigned	Z                   : 1;
        unsigned	nPD                 : 1;
        unsigned	nTO                 : 1;
        unsigned	RP                  : 2;
        unsigned	IRP                 : 1;
    };
    struct {
        unsigned	                    : 5;
        unsigned	RP0                 : 1;
        unsigned	RP1                 : 1;
    };
} STATUSbits @ 0x003;
#endif

// Register: FSR
volatile unsigned char           FSR                 @ 0x004;
// bit and bitfield definitions

// Register: PORTA
volatile unsigned char           PORTA               @ 0x005;
// bit and bitfield definitions
volatile bit RA0                 @ ((unsigned)&PORTA*8)+0;
volatile bit RA1                 @ ((unsigned)&PORTA*8)+1;
volatile bit RA2                 @ ((unsigned)&PORTA*8)+2;
volatile bit RA3                 @ ((unsigned)&PORTA*8)+3;
volatile bit RA4                 @ ((unsigned)&PORTA*8)+4;
volatile bit RA5                 @ ((unsigned)&PORTA*8)+5;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	RA0                 : 1;
        unsigned	RA1                 : 1;
        unsigned	RA2                 : 1;
        unsigned	RA3                 : 1;
        unsigned	RA4                 : 1;
        unsigned	RA5                 : 1;
    };
} PORTAbits @ 0x005;
#endif

// Register: PORTB
volatile unsigned char           PORTB               @ 0x006;
// bit and bitfield definitions
volatile bit RB4                 @ ((unsigned)&PORTB*8)+4;
volatile bit RB5                 @ ((unsigned)&PORTB*8)+5;
volatile bit RB6                 @ ((unsigned)&PORTB*8)+6;
volatile bit RB7                 @ ((unsigned)&PORTB*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	                    : 4;
        unsigned	RB4                 : 1;
        unsigned	RB5                 : 1;
        unsigned	RB6                 : 1;
        unsigned	RB7                 : 1;
    };
} PORTBbits @ 0x006;
#endif

// Register: PORTC
volatile unsigned char           PORTC               @ 0x007;
// bit and bitfield definitions
volatile bit RC0                 @ ((unsigned)&PORTC*8)+0;
volatile bit RC1                 @ ((unsigned)&PORTC*8)+1;
volatile bit RC2                 @ ((unsigned)&PORTC*8)+2;
volatile bit RC3                 @ ((unsigned)&PORTC*8)+3;
volatile bit RC4                 @ ((unsigned)&PORTC*8)+4;
volatile bit RC5                 @ ((unsigned)&PORTC*8)+5;
volatile bit RC6                 @ ((unsigned)&PORTC*8)+6;
volatile bit RC7                 @ ((unsigned)&PORTC*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	RC0                 : 1;
        unsigned	RC1                 : 1;
        unsigned	RC2                 : 1;
        unsigned	RC3                 : 1;
        unsigned	RC4                 : 1;
        unsigned	RC5                 : 1;
        unsigned	RC6                 : 1;
        unsigned	RC7                 : 1;
    };
} PORTCbits @ 0x007;
#endif

// Register: PCLATH
volatile unsigned char           PCLATH              @ 0x00A;
// bit and bitfield definitions
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	                    : 5;
    };
} PCLATHbits @ 0x00A;
#endif

// Register: INTCON
volatile unsigned char           INTCON              @ 0x00B;
// bit and bitfield definitions
volatile bit RABIF               @ ((unsigned)&INTCON*8)+0;
volatile bit INTF                @ ((unsigned)&INTCON*8)+1;
volatile bit T0IF                @ ((unsigned)&INTCON*8)+2;
volatile bit RABIE               @ ((unsigned)&INTCON*8)+3;
volatile bit INTE                @ ((unsigned)&INTCON*8)+4;
volatile bit T0IE                @ ((unsigned)&INTCON*8)+5;
volatile bit PEIE                @ ((unsigned)&INTCON*8)+6;
volatile bit GIE                 @ ((unsigned)&INTCON*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	RABIF               : 1;
        unsigned	INTF                : 1;
        unsigned	T0IF                : 1;
        unsigned	RABIE               : 1;
        unsigned	INTE                : 1;
        unsigned	T0IE                : 1;
        unsigned	PEIE                : 1;
        unsigned	GIE                 : 1;
    };
} INTCONbits @ 0x00B;
#endif

// Register: PIR1
volatile unsigned char           PIR1                @ 0x00C;
// bit and bitfield definitions
volatile bit TMR1IF              @ ((unsigned)&PIR1*8)+0;
volatile bit TMR2IF              @ ((unsigned)&PIR1*8)+1;
volatile bit CCP1IF              @ ((unsigned)&PIR1*8)+2;
volatile bit SSPIF               @ ((unsigned)&PIR1*8)+3;
volatile bit TXIF                @ ((unsigned)&PIR1*8)+4;
volatile bit RCIF                @ ((unsigned)&PIR1*8)+5;
volatile bit ADIF                @ ((unsigned)&PIR1*8)+6;
volatile bit T1IF                @ ((unsigned)&PIR1*8)+0;
volatile bit T2IF                @ ((unsigned)&PIR1*8)+1;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	TMR1IF              : 1;
        unsigned	TMR2IF              : 1;
        unsigned	CCP1IF              : 1;
        unsigned	SSPIF               : 1;
        unsigned	TXIF                : 1;
        unsigned	RCIF                : 1;
        unsigned	ADIF                : 1;
    };
    struct {
        unsigned	: 1;
        unsigned	: 1;
        unsigned	: 1;
        unsigned	: 1;
        unsigned	                    : 2;
        unsigned	: 1;
    };
    struct {
        unsigned	T1IF                : 1;
        unsigned	T2IF                : 1;
    };
} PIR1bits @ 0x00C;
#endif

// Register: PIR2
volatile unsigned char           PIR2                @ 0x00D;
// bit and bitfield definitions
volatile bit EEIF                @ ((unsigned)&PIR2*8)+4;
volatile bit C1IF                @ ((unsigned)&PIR2*8)+5;
volatile bit C2IF                @ ((unsigned)&PIR2*8)+6;
volatile bit OSFIF               @ ((unsigned)&PIR2*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	                    : 4;
        unsigned	EEIF                : 1;
        unsigned	C1IF                : 1;
        unsigned	C2IF                : 1;
        unsigned	OSFIF               : 1;
    };
} PIR2bits @ 0x00D;
#endif
// bit and bitfield definitions

// Register: TMR1L
volatile unsigned char           TMR1L               @ 0x00E;
// bit and bitfield definitions

// Register: TMR1H
volatile unsigned char           TMR1H               @ 0x00F;
// bit and bitfield definitions

// Register: TMR1
volatile unsigned int            TMR1                @ 0x00E;

// Register: T1CON
volatile unsigned char           T1CON               @ 0x010;
// bit and bitfield definitions
volatile bit TMR1ON              @ ((unsigned)&T1CON*8)+0;
volatile bit TMR1CS              @ ((unsigned)&T1CON*8)+1;
volatile bit nT1SYNC             @ ((unsigned)&T1CON*8)+2;
volatile bit T1OSCEN             @ ((unsigned)&T1CON*8)+3;
volatile bit TMR1GE              @ ((unsigned)&T1CON*8)+6;
volatile bit T1GINV              @ ((unsigned)&T1CON*8)+7;
volatile bit T1CKPS0             @ ((unsigned)&T1CON*8)+4;
volatile bit T1CKPS1             @ ((unsigned)&T1CON*8)+5;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	TMR1ON              : 1;
        unsigned	TMR1CS              : 1;
        unsigned	nT1SYNC             : 1;
        unsigned	T1OSCEN             : 1;
        unsigned	T1CKPS              : 2;
        unsigned	TMR1GE              : 1;
        unsigned	T1GINV              : 1;
    };
    struct {
        unsigned	                    : 4;
        unsigned	T1CKPS0             : 1;
        unsigned	T1CKPS1             : 1;
    };
} T1CONbits @ 0x010;
#endif

// Register: TMR2
volatile unsigned char           TMR2                @ 0x011;
// bit and bitfield definitions

// Register: T2CON
volatile unsigned char           T2CON               @ 0x012;
// bit and bitfield definitions
volatile bit TMR2ON              @ ((unsigned)&T2CON*8)+2;
volatile bit T2CKPS0             @ ((unsigned)&T2CON*8)+0;
volatile bit T2CKPS1             @ ((unsigned)&T2CON*8)+1;
volatile bit TOUTPS0             @ ((unsigned)&T2CON*8)+3;
volatile bit TOUTPS1             @ ((unsigned)&T2CON*8)+4;
volatile bit TOUTPS2             @ ((unsigned)&T2CON*8)+5;
volatile bit TOUTPS3             @ ((unsigned)&T2CON*8)+6;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	T2CKPS              : 2;
        unsigned	TMR2ON              : 1;
        unsigned	TOUTPS              : 4;
    };
    struct {
        unsigned	T2CKPS0             : 1;
        unsigned	T2CKPS1             : 1;
        unsigned	                    : 1;
        unsigned	TOUTPS0             : 1;
        unsigned	TOUTPS1             : 1;
        unsigned	TOUTPS2             : 1;
        unsigned	TOUTPS3             : 1;
    };
} T2CONbits @ 0x012;
#endif

// Register: SSPBUF
volatile unsigned char           SSPBUF              @ 0x013;
// bit and bitfield definitions

// Register: SSPCON
volatile unsigned char           SSPCON              @ 0x014;
// bit and bitfield definitions
volatile bit CKP                 @ ((unsigned)&SSPCON*8)+4;
volatile bit SSPEN               @ ((unsigned)&SSPCON*8)+5;
volatile bit SSPOV               @ ((unsigned)&SSPCON*8)+6;
volatile bit WCOL                @ ((unsigned)&SSPCON*8)+7;
volatile bit SSPM0               @ ((unsigned)&SSPCON*8)+0;
volatile bit SSPM1               @ ((unsigned)&SSPCON*8)+1;
volatile bit SSPM2               @ ((unsigned)&SSPCON*8)+2;
volatile bit SSPM3               @ ((unsigned)&SSPCON*8)+3;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	SSPM                : 4;
        unsigned	CKP                 : 1;
        unsigned	SSPEN               : 1;
        unsigned	SSPOV               : 1;
        unsigned	WCOL                : 1;
    };
    struct {
        unsigned	SSPM0               : 1;
        unsigned	SSPM1               : 1;
        unsigned	SSPM2               : 1;
        unsigned	SSPM3               : 1;
    };
} SSPCONbits @ 0x014;
#endif
// bit and bitfield definitions

// Register: CCPR1L
volatile unsigned char           CCPR1L              @ 0x015;
// bit and bitfield definitions

// Register: CCPR1H
volatile unsigned char           CCPR1H              @ 0x016;
// bit and bitfield definitions

// Register: CCPR
volatile unsigned int            CCPR                @ 0x015;

// Register: CCP1CON
volatile unsigned char           CCP1CON             @ 0x017;
// bit and bitfield definitions
volatile bit CCP1M0              @ ((unsigned)&CCP1CON*8)+0;
volatile bit CCP1M1              @ ((unsigned)&CCP1CON*8)+1;
volatile bit CCP1M2              @ ((unsigned)&CCP1CON*8)+2;
volatile bit CCP1M3              @ ((unsigned)&CCP1CON*8)+3;
volatile bit DC1B0               @ ((unsigned)&CCP1CON*8)+4;
volatile bit DC1B1               @ ((unsigned)&CCP1CON*8)+5;
volatile bit P1M0                @ ((unsigned)&CCP1CON*8)+6;
volatile bit P1M1                @ ((unsigned)&CCP1CON*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	CCP1M               : 4;
        unsigned	DC1B                : 2;
        unsigned	P1M                 : 2;
    };
    struct {
        unsigned	CCP1M0              : 1;
        unsigned	CCP1M1              : 1;
        unsigned	CCP1M2              : 1;
        unsigned	CCP1M3              : 1;
        unsigned	DC1B0               : 1;
        unsigned	DC1B1               : 1;
        unsigned	P1M0                : 1;
        unsigned	P1M1                : 1;
    };
} CCP1CONbits @ 0x017;
#endif

// Register: RCSTA
volatile unsigned char           RCSTA               @ 0x018;
// bit and bitfield definitions
volatile bit RX9D                @ ((unsigned)&RCSTA*8)+0;
volatile bit OERR                @ ((unsigned)&RCSTA*8)+1;
volatile bit FERR                @ ((unsigned)&RCSTA*8)+2;
volatile bit ADDEN               @ ((unsigned)&RCSTA*8)+3;
volatile bit CREN                @ ((unsigned)&RCSTA*8)+4;
volatile bit SREN                @ ((unsigned)&RCSTA*8)+5;
volatile bit RX9                 @ ((unsigned)&RCSTA*8)+6;
volatile bit SPEN                @ ((unsigned)&RCSTA*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	RX9D                : 1;
        unsigned	OERR                : 1;
        unsigned	FERR                : 1;
        unsigned	ADDEN               : 1;
        unsigned	CREN                : 1;
        unsigned	SREN                : 1;
        unsigned	RX9                 : 1;
        unsigned	SPEN                : 1;
    };
} RCSTAbits @ 0x018;
#endif

// Register: TXREG
volatile unsigned char           TXREG               @ 0x019;
// bit and bitfield definitions

// Register: RCREG
volatile unsigned char           RCREG               @ 0x01A;
// bit and bitfield definitions

// Register: PWM1CON
volatile unsigned char           PWM1CON             @ 0x01C;
// bit and bitfield definitions
volatile bit PRSEN               @ ((unsigned)&PWM1CON*8)+7;
volatile bit PDC0                @ ((unsigned)&PWM1CON*8)+0;
volatile bit PDC1                @ ((unsigned)&PWM1CON*8)+1;
volatile bit PDC2                @ ((unsigned)&PWM1CON*8)+2;
volatile bit PDC3                @ ((unsigned)&PWM1CON*8)+3;
volatile bit PDC4                @ ((unsigned)&PWM1CON*8)+4;
volatile bit PDC5                @ ((unsigned)&PWM1CON*8)+5;
volatile bit PDC6                @ ((unsigned)&PWM1CON*8)+6;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	PDC                 : 7;
        unsigned	PRSEN               : 1;
    };
    struct {
        unsigned	PDC0                : 1;
        unsigned	PDC1                : 1;
        unsigned	PDC2                : 1;
        unsigned	PDC3                : 1;
        unsigned	PDC4                : 1;
        unsigned	PDC5                : 1;
        unsigned	PDC6                : 1;
    };
} PWM1CONbits @ 0x01C;
#endif

// Register: ECCPAS
volatile unsigned char           ECCPAS              @ 0x01D;
// bit and bitfield definitions
volatile bit ECCPASE             @ ((unsigned)&ECCPAS*8)+7;
volatile bit PSSBD0              @ ((unsigned)&ECCPAS*8)+0;
volatile bit PSSBD1              @ ((unsigned)&ECCPAS*8)+1;
volatile bit PSSAC0              @ ((unsigned)&ECCPAS*8)+2;
volatile bit PSSAC1              @ ((unsigned)&ECCPAS*8)+3;
volatile bit ECCPAS0             @ ((unsigned)&ECCPAS*8)+4;
volatile bit ECCPAS1             @ ((unsigned)&ECCPAS*8)+5;
volatile bit ECCPAS2             @ ((unsigned)&ECCPAS*8)+6;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	PSSBD               : 2;
        unsigned	PSSAC               : 2;
        unsigned	ECCPAS              : 3;
        unsigned	ECCPASE             : 1;
    };
    struct {
        unsigned	PSSBD0              : 1;
        unsigned	PSSBD1              : 1;
        unsigned	PSSAC0              : 1;
        unsigned	PSSAC1              : 1;
        unsigned	ECCPAS0             : 1;
        unsigned	ECCPAS1             : 1;
        unsigned	ECCPAS2             : 1;
    };
} ECCPASbits @ 0x01D;
#endif

// Register: ADRESH
volatile unsigned char           ADRESH              @ 0x01E;
// bit and bitfield definitions

// Register: ADCON0
volatile unsigned char           ADCON0              @ 0x01F;
// bit and bitfield definitions
volatile bit ADON                @ ((unsigned)&ADCON0*8)+0;
volatile bit GO_nDONE            @ ((unsigned)&ADCON0*8)+1;
volatile bit VCFG                @ ((unsigned)&ADCON0*8)+6;
volatile bit ADFM                @ ((unsigned)&ADCON0*8)+7;
volatile bit GO                  @ ((unsigned)&ADCON0*8)+1;
volatile bit CHS0                @ ((unsigned)&ADCON0*8)+2;
volatile bit CHS1                @ ((unsigned)&ADCON0*8)+3;
volatile bit CHS2                @ ((unsigned)&ADCON0*8)+4;
volatile bit CHS3                @ ((unsigned)&ADCON0*8)+5;
volatile bit nDONE               @ ((unsigned)&ADCON0*8)+1;
volatile bit GO_DONE             @ ((unsigned)&ADCON0*8)+1;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	ADON                : 1;
        unsigned	GO_nDONE            : 1;
        unsigned	CHS                 : 4;
        unsigned	VCFG                : 1;
        unsigned	ADFM                : 1;
    };
    struct {
        unsigned	: 1;
        unsigned	: 1;
        unsigned	: 4;
        unsigned	: 1;
        unsigned	: 1;
    };
    struct {
        unsigned	                    : 1;
        unsigned	GO                  : 1;
        unsigned	CHS0                : 1;
        unsigned	CHS1                : 1;
        unsigned	CHS2                : 1;
        unsigned	CHS3                : 1;
    };
    struct {
        unsigned	: 1;
        unsigned	nDONE               : 1;
    };
    struct {
        unsigned	: 1;
        unsigned	GO_DONE             : 1;
    };
} ADCON0bits @ 0x01F;
#endif

//
// Special function register definitions: Bank 1
//


// Register: OPTION_REG
volatile unsigned char           OPTION_REG          @ 0x081;
// bit and bitfield definitions
volatile bit PSA                 @ ((unsigned)&OPTION_REG*8)+3;
volatile bit T0SE                @ ((unsigned)&OPTION_REG*8)+4;
volatile bit T0CS                @ ((unsigned)&OPTION_REG*8)+5;
volatile bit INTEDG              @ ((unsigned)&OPTION_REG*8)+6;
volatile bit nRABPU              @ ((unsigned)&OPTION_REG*8)+7;
volatile bit PS0                 @ ((unsigned)&OPTION_REG*8)+0;
volatile bit PS1                 @ ((unsigned)&OPTION_REG*8)+1;
volatile bit PS2                 @ ((unsigned)&OPTION_REG*8)+2;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	PS                  : 3;
        unsigned	PSA                 : 1;
        unsigned	T0SE                : 1;
        unsigned	T0CS                : 1;
        unsigned	INTEDG              : 1;
        unsigned	nRABPU              : 1;
    };
    struct {
        unsigned	PS0                 : 1;
        unsigned	PS1                 : 1;
        unsigned	PS2                 : 1;
    };
} OPTION_REGbits @ 0x081;
#endif

// Register: TRISA
volatile unsigned char           TRISA               @ 0x085;
// bit and bitfield definitions
volatile bit TRISA0              @ ((unsigned)&TRISA*8)+0;
volatile bit TRISA1              @ ((unsigned)&TRISA*8)+1;
volatile bit TRISA2              @ ((unsigned)&TRISA*8)+2;
volatile bit TRISA3              @ ((unsigned)&TRISA*8)+3;
volatile bit TRISA4              @ ((unsigned)&TRISA*8)+4;
volatile bit TRISA5              @ ((unsigned)&TRISA*8)+5;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	TRISA0              : 1;
        unsigned	TRISA1              : 1;
        unsigned	TRISA2              : 1;
        unsigned	TRISA3              : 1;
        unsigned	TRISA4              : 1;
        unsigned	TRISA5              : 1;
    };
} TRISAbits @ 0x085;
#endif

// Register: TRISB
volatile unsigned char           TRISB               @ 0x086;
// bit and bitfield definitions
volatile bit TRISB4              @ ((unsigned)&TRISB*8)+4;
volatile bit TRISB5              @ ((unsigned)&TRISB*8)+5;
volatile bit TRISB6              @ ((unsigned)&TRISB*8)+6;
volatile bit TRISB7              @ ((unsigned)&TRISB*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	                    : 4;
        unsigned	TRISB4              : 1;
        unsigned	TRISB5              : 1;
        unsigned	TRISB6              : 1;
        unsigned	TRISB7              : 1;
    };
} TRISBbits @ 0x086;
#endif

// Register: TRISC
volatile unsigned char           TRISC               @ 0x087;
// bit and bitfield definitions
volatile bit TRISC0              @ ((unsigned)&TRISC*8)+0;
volatile bit TRISC1              @ ((unsigned)&TRISC*8)+1;
volatile bit TRISC2              @ ((unsigned)&TRISC*8)+2;
volatile bit TRISC3              @ ((unsigned)&TRISC*8)+3;
volatile bit TRISC4              @ ((unsigned)&TRISC*8)+4;
volatile bit TRISC5              @ ((unsigned)&TRISC*8)+5;
volatile bit TRISC6              @ ((unsigned)&TRISC*8)+6;
volatile bit TRISC7              @ ((unsigned)&TRISC*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	TRISC0              : 1;
        unsigned	TRISC1              : 1;
        unsigned	TRISC2              : 1;
        unsigned	TRISC3              : 1;
        unsigned	TRISC4              : 1;
        unsigned	TRISC5              : 1;
        unsigned	TRISC6              : 1;
        unsigned	TRISC7              : 1;
    };
} TRISCbits @ 0x087;
#endif

// Register: PIE1
volatile unsigned char           PIE1                @ 0x08C;
// bit and bitfield definitions
volatile bit TMR1IE              @ ((unsigned)&PIE1*8)+0;
volatile bit TMR2IE              @ ((unsigned)&PIE1*8)+1;
volatile bit CCP1IE              @ ((unsigned)&PIE1*8)+2;
volatile bit SSPIE               @ ((unsigned)&PIE1*8)+3;
volatile bit TXIE                @ ((unsigned)&PIE1*8)+4;
volatile bit RCIE                @ ((unsigned)&PIE1*8)+5;
volatile bit ADIE                @ ((unsigned)&PIE1*8)+6;
volatile bit T1IE                @ ((unsigned)&PIE1*8)+0;
volatile bit T2IE                @ ((unsigned)&PIE1*8)+1;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	TMR1IE              : 1;
        unsigned	TMR2IE              : 1;
        unsigned	CCP1IE              : 1;
        unsigned	SSPIE               : 1;
        unsigned	TXIE                : 1;
        unsigned	RCIE                : 1;
        unsigned	ADIE                : 1;
    };
    struct {
        unsigned	T1IE                : 1;
        unsigned	T2IE                : 1;
    };
} PIE1bits @ 0x08C;
#endif

// Register: PIE2
volatile unsigned char           PIE2                @ 0x08D;
// bit and bitfield definitions
volatile bit EEIE                @ ((unsigned)&PIE2*8)+4;
volatile bit C1IE                @ ((unsigned)&PIE2*8)+5;
volatile bit C2IE                @ ((unsigned)&PIE2*8)+6;
volatile bit OSFIE               @ ((unsigned)&PIE2*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	                    : 4;
        unsigned	EEIE                : 1;
        unsigned	C1IE                : 1;
        unsigned	C2IE                : 1;
        unsigned	OSFIE               : 1;
    };
} PIE2bits @ 0x08D;
#endif

// Register: PCON
volatile unsigned char           PCON                @ 0x08E;
// bit and bitfield definitions
volatile bit nBOR                @ ((unsigned)&PCON*8)+0;
volatile bit nPOR                @ ((unsigned)&PCON*8)+1;
volatile bit SBOREN              @ ((unsigned)&PCON*8)+4;
volatile bit ULPWUE              @ ((unsigned)&PCON*8)+5;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	nBOR                : 1;
        unsigned	nPOR                : 1;
        unsigned	                    : 2;
        unsigned	SBOREN              : 1;
        unsigned	ULPWUE              : 1;
    };
} PCONbits @ 0x08E;
#endif

// Register: OSCCON
volatile unsigned char           OSCCON              @ 0x08F;
// bit and bitfield definitions
volatile bit SCS                 @ ((unsigned)&OSCCON*8)+0;
volatile bit LTS                 @ ((unsigned)&OSCCON*8)+1;
volatile bit HTS                 @ ((unsigned)&OSCCON*8)+2;
volatile bit OSTS                @ ((unsigned)&OSCCON*8)+3;
volatile bit IRCF0               @ ((unsigned)&OSCCON*8)+4;
volatile bit IRCF1               @ ((unsigned)&OSCCON*8)+5;
volatile bit IRCF2               @ ((unsigned)&OSCCON*8)+6;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	SCS                 : 1;
        unsigned	LTS                 : 1;
        unsigned	HTS                 : 1;
        unsigned	OSTS                : 1;
        unsigned	IRCF                : 3;
    };
    struct {
        unsigned	                    : 4;
        unsigned	IRCF0               : 1;
        unsigned	IRCF1               : 1;
        unsigned	IRCF2               : 1;
    };
} OSCCONbits @ 0x08F;
#endif

// Register: OSCTUNE
volatile unsigned char           OSCTUNE             @ 0x090;
// bit and bitfield definitions
volatile bit TUN0                @ ((unsigned)&OSCTUNE*8)+0;
volatile bit TUN1                @ ((unsigned)&OSCTUNE*8)+1;
volatile bit TUN2                @ ((unsigned)&OSCTUNE*8)+2;
volatile bit TUN3                @ ((unsigned)&OSCTUNE*8)+3;
volatile bit TUN4                @ ((unsigned)&OSCTUNE*8)+4;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	TUN                 : 5;
    };
    struct {
        unsigned	TUN0                : 1;
        unsigned	TUN1                : 1;
        unsigned	TUN2                : 1;
        unsigned	TUN3                : 1;
        unsigned	TUN4                : 1;
    };
} OSCTUNEbits @ 0x090;
#endif

// Register: PR2
volatile unsigned char           PR2                 @ 0x092;
// bit and bitfield definitions

// Register: SSPADD
volatile unsigned char           SSPADD              @ 0x093;
// bit and bitfield definitions

// Register: SSPMSK
volatile unsigned char           SSPMSK              @ 0x093;	// shared address with SSPADD
volatile unsigned char           MSK                 @ 0x093;	// shared address with SSPADD
// bit and bitfield definitions
volatile bit MSK0                @ ((unsigned)&SSPMSK*8)+0;
volatile bit MSK1                @ ((unsigned)&SSPMSK*8)+1;
volatile bit MSK2                @ ((unsigned)&SSPMSK*8)+2;
volatile bit MSK3                @ ((unsigned)&SSPMSK*8)+3;
volatile bit MSK4                @ ((unsigned)&SSPMSK*8)+4;
volatile bit MSK5                @ ((unsigned)&SSPMSK*8)+5;
volatile bit MSK6                @ ((unsigned)&SSPMSK*8)+6;
volatile bit MSK7                @ ((unsigned)&SSPMSK*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	MSK0                : 1;
        unsigned	MSK1                : 1;
        unsigned	MSK2                : 1;
        unsigned	MSK3                : 1;
        unsigned	MSK4                : 1;
        unsigned	MSK5                : 1;
        unsigned	MSK6                : 1;
        unsigned	MSK7                : 1;
    };
} SSPMSKbits @ 0x093;
#endif

// Register: SSPSTAT
volatile unsigned char           SSPSTAT             @ 0x094;
// bit and bitfield definitions
volatile bit BF                  @ ((unsigned)&SSPSTAT*8)+0;
volatile bit UA                  @ ((unsigned)&SSPSTAT*8)+1;
volatile bit R_nW                @ ((unsigned)&SSPSTAT*8)+2;
volatile bit S                   @ ((unsigned)&SSPSTAT*8)+3;
volatile bit P                   @ ((unsigned)&SSPSTAT*8)+4;
volatile bit D_nA                @ ((unsigned)&SSPSTAT*8)+5;
volatile bit CKE                 @ ((unsigned)&SSPSTAT*8)+6;
volatile bit SMP                 @ ((unsigned)&SSPSTAT*8)+7;
volatile bit R                   @ ((unsigned)&SSPSTAT*8)+2;
volatile bit D                   @ ((unsigned)&SSPSTAT*8)+5;
volatile bit I2C_READ            @ ((unsigned)&SSPSTAT*8)+2;
volatile bit I2C_START           @ ((unsigned)&SSPSTAT*8)+3;
volatile bit I2C_STOP            @ ((unsigned)&SSPSTAT*8)+4;
volatile bit I2C_DATA            @ ((unsigned)&SSPSTAT*8)+5;
volatile bit nW                  @ ((unsigned)&SSPSTAT*8)+2;
volatile bit nA                  @ ((unsigned)&SSPSTAT*8)+5;
volatile bit nWRITE              @ ((unsigned)&SSPSTAT*8)+2;
volatile bit nADDRESS            @ ((unsigned)&SSPSTAT*8)+5;
volatile bit R_W                 @ ((unsigned)&SSPSTAT*8)+2;
volatile bit D_A                 @ ((unsigned)&SSPSTAT*8)+5;
volatile bit READ_WRITE          @ ((unsigned)&SSPSTAT*8)+2;
volatile bit DATA_ADDRESS        @ ((unsigned)&SSPSTAT*8)+5;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	BF                  : 1;
        unsigned	UA                  : 1;
        unsigned	R_nW                : 1;
        unsigned	S                   : 1;
        unsigned	P                   : 1;
        unsigned	D_nA                : 1;
        unsigned	CKE                 : 1;
        unsigned	SMP                 : 1;
    };
    struct {
        unsigned	: 1;
        unsigned	: 1;
        unsigned	: 1;
        unsigned	: 1;
        unsigned	: 1;
        unsigned	: 1;
        unsigned	: 1;
        unsigned	: 1;
    };
    struct {
        unsigned	                    : 2;
        unsigned	R                   : 1;
        unsigned	: 2;
        unsigned	D                   : 1;
    };
    struct {
        unsigned	: 2;
        unsigned	I2C_READ            : 1;
        unsigned	I2C_START           : 1;
        unsigned	I2C_STOP            : 1;
        unsigned	I2C_DATA            : 1;
    };
    struct {
        unsigned	: 2;
        unsigned	nW                  : 1;
        unsigned	: 2;
        unsigned	nA                  : 1;
    };
    struct {
        unsigned	: 2;
        unsigned	nWRITE              : 1;
        unsigned	: 2;
        unsigned	nADDRESS            : 1;
    };
    struct {
        unsigned	: 2;
        unsigned	R_W                 : 1;
        unsigned	: 2;
        unsigned	D_A                 : 1;
    };
    struct {
        unsigned	: 2;
        unsigned	READ_WRITE          : 1;
        unsigned	: 2;
        unsigned	DATA_ADDRESS        : 1;
    };
} SSPSTATbits @ 0x094;
#endif

// Register: WPUA
volatile unsigned char           WPUA                @ 0x095;
volatile unsigned char           WPU                 @ 0x095;
// bit and bitfield definitions
volatile bit WPUA0               @ ((unsigned)&WPUA*8)+0;
volatile bit WPUA1               @ ((unsigned)&WPUA*8)+1;
volatile bit WPUA2               @ ((unsigned)&WPUA*8)+2;
volatile bit WPUA4               @ ((unsigned)&WPUA*8)+4;
volatile bit WPUA5               @ ((unsigned)&WPUA*8)+5;
volatile bit WPU0                @ ((unsigned)&WPUA*8)+0;
volatile bit WPU1                @ ((unsigned)&WPUA*8)+1;
volatile bit WPU2                @ ((unsigned)&WPUA*8)+2;
volatile bit WPU4                @ ((unsigned)&WPUA*8)+4;
volatile bit WPU5                @ ((unsigned)&WPUA*8)+5;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	WPUA0               : 1;
        unsigned	WPUA1               : 1;
        unsigned	WPUA2               : 1;
        unsigned	                    : 1;
        unsigned	WPUA4               : 1;
        unsigned	WPUA5               : 1;
    };
    struct {
        unsigned	WPU0                : 1;
        unsigned	WPU1                : 1;
        unsigned	WPU2                : 1;
        unsigned	: 1;
        unsigned	WPU4                : 1;
        unsigned	WPU5                : 1;
    };
} WPUAbits @ 0x095;
#endif

// Register: IOCA
volatile unsigned char           IOCA                @ 0x096;
volatile unsigned char           IOC                 @ 0x096;
// bit and bitfield definitions
volatile bit IOCA0               @ ((unsigned)&IOCA*8)+0;
volatile bit IOCA1               @ ((unsigned)&IOCA*8)+1;
volatile bit IOCA2               @ ((unsigned)&IOCA*8)+2;
volatile bit IOCA3               @ ((unsigned)&IOCA*8)+3;
volatile bit IOCA4               @ ((unsigned)&IOCA*8)+4;
volatile bit IOCA5               @ ((unsigned)&IOCA*8)+5;
volatile bit IOC0                @ ((unsigned)&IOCA*8)+0;
volatile bit IOC1                @ ((unsigned)&IOCA*8)+1;
volatile bit IOC2                @ ((unsigned)&IOCA*8)+2;
volatile bit IOC3                @ ((unsigned)&IOCA*8)+3;
volatile bit IOC4                @ ((unsigned)&IOCA*8)+4;
volatile bit IOC5                @ ((unsigned)&IOCA*8)+5;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	IOCA0               : 1;
        unsigned	IOCA1               : 1;
        unsigned	IOCA2               : 1;
        unsigned	IOCA3               : 1;
        unsigned	IOCA4               : 1;
        unsigned	IOCA5               : 1;
    };
    struct {
        unsigned	IOC0                : 1;
        unsigned	IOC1                : 1;
        unsigned	IOC2                : 1;
        unsigned	IOC3                : 1;
        unsigned	IOC4                : 1;
        unsigned	IOC5                : 1;
    };
} IOCAbits @ 0x096;
#endif

// Register: WDTCON
volatile unsigned char           WDTCON              @ 0x097;
// bit and bitfield definitions
volatile bit SWDTEN              @ ((unsigned)&WDTCON*8)+0;
volatile bit WDTPS0              @ ((unsigned)&WDTCON*8)+1;
volatile bit WDTPS1              @ ((unsigned)&WDTCON*8)+2;
volatile bit WDTPS2              @ ((unsigned)&WDTCON*8)+3;
volatile bit WDTPS3              @ ((unsigned)&WDTCON*8)+4;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	SWDTEN              : 1;
        unsigned	WDTPS               : 4;
    };
    struct {
        unsigned	                    : 1;
        unsigned	WDTPS0              : 1;
        unsigned	WDTPS1              : 1;
        unsigned	WDTPS2              : 1;
        unsigned	WDTPS3              : 1;
    };
} WDTCONbits @ 0x097;
#endif

// Register: TXSTA
volatile unsigned char           TXSTA               @ 0x098;
// bit and bitfield definitions
volatile bit TX9D                @ ((unsigned)&TXSTA*8)+0;
volatile bit TRMT                @ ((unsigned)&TXSTA*8)+1;
volatile bit BRGH                @ ((unsigned)&TXSTA*8)+2;
volatile bit SENDB               @ ((unsigned)&TXSTA*8)+3;
volatile bit SYNC                @ ((unsigned)&TXSTA*8)+4;
volatile bit TXEN                @ ((unsigned)&TXSTA*8)+5;
volatile bit TX9                 @ ((unsigned)&TXSTA*8)+6;
volatile bit CSRC                @ ((unsigned)&TXSTA*8)+7;
volatile bit SENB                @ ((unsigned)&TXSTA*8)+3;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	TX9D                : 1;
        unsigned	TRMT                : 1;
        unsigned	BRGH                : 1;
        unsigned	SENDB               : 1;
        unsigned	SYNC                : 1;
        unsigned	TXEN                : 1;
        unsigned	TX9                 : 1;
        unsigned	CSRC                : 1;
    };
    struct {
        unsigned	                    : 3;
        unsigned	SENB                : 1;
    };
} TXSTAbits @ 0x098;
#endif

// Register: SPBRG
volatile unsigned char           SPBRG               @ 0x099;
// bit and bitfield definitions
volatile bit BRG0                @ ((unsigned)&SPBRG*8)+0;
volatile bit BRG1                @ ((unsigned)&SPBRG*8)+1;
volatile bit BRG2                @ ((unsigned)&SPBRG*8)+2;
volatile bit BRG3                @ ((unsigned)&SPBRG*8)+3;
volatile bit BRG4                @ ((unsigned)&SPBRG*8)+4;
volatile bit BRG5                @ ((unsigned)&SPBRG*8)+5;
volatile bit BRG6                @ ((unsigned)&SPBRG*8)+6;
volatile bit BRG7                @ ((unsigned)&SPBRG*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	BRG0                : 1;
        unsigned	BRG1                : 1;
        unsigned	BRG2                : 1;
        unsigned	BRG3                : 1;
        unsigned	BRG4                : 1;
        unsigned	BRG5                : 1;
        unsigned	BRG6                : 1;
        unsigned	BRG7                : 1;
    };
} SPBRGbits @ 0x099;
#endif

// Register: SPBRGH
volatile unsigned char           SPBRGH              @ 0x09A;
// bit and bitfield definitions
volatile bit BRG8                @ ((unsigned)&SPBRGH*8)+0;
volatile bit BRG9                @ ((unsigned)&SPBRGH*8)+1;
volatile bit BRG10               @ ((unsigned)&SPBRGH*8)+2;
volatile bit BRG11               @ ((unsigned)&SPBRGH*8)+3;
volatile bit BRG12               @ ((unsigned)&SPBRGH*8)+4;
volatile bit BRG13               @ ((unsigned)&SPBRGH*8)+5;
volatile bit BRG14               @ ((unsigned)&SPBRGH*8)+6;
volatile bit BRG15               @ ((unsigned)&SPBRGH*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	BRG8                : 1;
        unsigned	BRG9                : 1;
        unsigned	BRG10               : 1;
        unsigned	BRG11               : 1;
        unsigned	BRG12               : 1;
        unsigned	BRG13               : 1;
        unsigned	BRG14               : 1;
        unsigned	BRG15               : 1;
    };
} SPBRGHbits @ 0x09A;
#endif

// Register: BAUDCTL
volatile unsigned char           BAUDCTL             @ 0x09B;
// bit and bitfield definitions
volatile bit ABDEN               @ ((unsigned)&BAUDCTL*8)+0;
volatile bit WUE                 @ ((unsigned)&BAUDCTL*8)+1;
volatile bit BRG16               @ ((unsigned)&BAUDCTL*8)+3;
volatile bit SCKP                @ ((unsigned)&BAUDCTL*8)+4;
volatile bit RCIDL               @ ((unsigned)&BAUDCTL*8)+6;
volatile bit ABDOVF              @ ((unsigned)&BAUDCTL*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	ABDEN               : 1;
        unsigned	WUE                 : 1;
        unsigned	                    : 1;
        unsigned	BRG16               : 1;
        unsigned	SCKP                : 1;
        unsigned	: 1;
        unsigned	RCIDL               : 1;
        unsigned	ABDOVF              : 1;
    };
} BAUDCTLbits @ 0x09B;
#endif

// Register: ADRESL
volatile unsigned char           ADRESL              @ 0x09E;
// bit and bitfield definitions

// Register: ADCON1
volatile unsigned char           ADCON1              @ 0x09F;
// bit and bitfield definitions
volatile bit ADCS0               @ ((unsigned)&ADCON1*8)+4;
volatile bit ADCS1               @ ((unsigned)&ADCON1*8)+5;
volatile bit ADCS2               @ ((unsigned)&ADCON1*8)+6;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	                    : 4;
        unsigned	ADCS                : 3;
    };
    struct {
        unsigned	: 4;
        unsigned	ADCS0               : 1;
        unsigned	ADCS1               : 1;
        unsigned	ADCS2               : 1;
    };
} ADCON1bits @ 0x09F;
#endif

//
// Special function register definitions: Bank 2
//


// Register: EEDAT
volatile unsigned char           EEDAT               @ 0x10C;
volatile unsigned char           EEDATA              @ 0x10C;
// bit and bitfield definitions

// Register: EEADR
volatile unsigned char           EEADR               @ 0x10D;
// bit and bitfield definitions

// Register: EEDATH
volatile unsigned char           EEDATH              @ 0x10E;
// bit and bitfield definitions
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	                    : 6;
    };
} EEDATHbits @ 0x10E;
#endif

// Register: EEADRH
volatile unsigned char           EEADRH              @ 0x10F;
// bit and bitfield definitions
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	                    : 4;
    };
} EEADRHbits @ 0x10F;
#endif

// Register: WPUB
volatile unsigned char           WPUB                @ 0x115;
// bit and bitfield definitions
volatile bit WPUB4               @ ((unsigned)&WPUB*8)+4;
volatile bit WPUB5               @ ((unsigned)&WPUB*8)+5;
volatile bit WPUB6               @ ((unsigned)&WPUB*8)+6;
volatile bit WPUB7               @ ((unsigned)&WPUB*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	                    : 4;
        unsigned	WPUB                : 4;
    };
    struct {
        unsigned	: 4;
        unsigned	WPUB4               : 1;
        unsigned	WPUB5               : 1;
        unsigned	WPUB6               : 1;
        unsigned	WPUB7               : 1;
    };
} WPUBbits @ 0x115;
#endif

// Register: IOCB
volatile unsigned char           IOCB                @ 0x116;
// bit and bitfield definitions
volatile bit IOCB4               @ ((unsigned)&IOCB*8)+4;
volatile bit IOCB5               @ ((unsigned)&IOCB*8)+5;
volatile bit IOCB6               @ ((unsigned)&IOCB*8)+6;
volatile bit IOCB7               @ ((unsigned)&IOCB*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	                    : 4;
        unsigned	IOCB4               : 1;
        unsigned	IOCB5               : 1;
        unsigned	IOCB6               : 1;
        unsigned	IOCB7               : 1;
    };
} IOCBbits @ 0x116;
#endif

// Register: VRCON
volatile unsigned char           VRCON               @ 0x118;
// bit and bitfield definitions
volatile bit VP6EN               @ ((unsigned)&VRCON*8)+4;
volatile bit VRR                 @ ((unsigned)&VRCON*8)+5;
volatile bit C2VREN              @ ((unsigned)&VRCON*8)+6;
volatile bit C1VREN              @ ((unsigned)&VRCON*8)+7;
volatile bit VR0                 @ ((unsigned)&VRCON*8)+0;
volatile bit VR1                 @ ((unsigned)&VRCON*8)+1;
volatile bit VR2                 @ ((unsigned)&VRCON*8)+2;
volatile bit VR3                 @ ((unsigned)&VRCON*8)+3;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	VR                  : 4;
        unsigned	VP6EN               : 1;
        unsigned	VRR                 : 1;
        unsigned	C2VREN              : 1;
        unsigned	C1VREN              : 1;
    };
    struct {
        unsigned	VR0                 : 1;
        unsigned	VR1                 : 1;
        unsigned	VR2                 : 1;
        unsigned	VR3                 : 1;
    };
} VRCONbits @ 0x118;
#endif

// Register: CM1CON0
volatile unsigned char           CM1CON0             @ 0x119;
// bit and bitfield definitions
volatile bit C1R                 @ ((unsigned)&CM1CON0*8)+2;
volatile bit C1POL               @ ((unsigned)&CM1CON0*8)+4;
volatile bit C1OE                @ ((unsigned)&CM1CON0*8)+5;
volatile bit C1OUT               @ ((unsigned)&CM1CON0*8)+6;
volatile bit C1ON                @ ((unsigned)&CM1CON0*8)+7;
volatile bit C1CH0               @ ((unsigned)&CM1CON0*8)+0;
volatile bit C1CH1               @ ((unsigned)&CM1CON0*8)+1;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	C1CH                : 2;
        unsigned	C1R                 : 1;
        unsigned	                    : 1;
        unsigned	C1POL               : 1;
        unsigned	C1OE                : 1;
        unsigned	C1OUT               : 1;
        unsigned	C1ON                : 1;
    };
    struct {
        unsigned	C1CH0               : 1;
        unsigned	C1CH1               : 1;
    };
} CM1CON0bits @ 0x119;
#endif

// Register: CM2CON0
volatile unsigned char           CM2CON0             @ 0x11A;
// bit and bitfield definitions
volatile bit C2R                 @ ((unsigned)&CM2CON0*8)+2;
volatile bit C2POL               @ ((unsigned)&CM2CON0*8)+4;
volatile bit C2OE                @ ((unsigned)&CM2CON0*8)+5;
volatile bit C2OUT               @ ((unsigned)&CM2CON0*8)+6;
volatile bit C2ON                @ ((unsigned)&CM2CON0*8)+7;
volatile bit C2CH0               @ ((unsigned)&CM2CON0*8)+0;
volatile bit C2CH1               @ ((unsigned)&CM2CON0*8)+1;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	C2CH                : 2;
        unsigned	C2R                 : 1;
        unsigned	                    : 1;
        unsigned	C2POL               : 1;
        unsigned	C2OE                : 1;
        unsigned	C2OUT               : 1;
        unsigned	C2ON                : 1;
    };
    struct {
        unsigned	C2CH0               : 1;
        unsigned	C2CH1               : 1;
    };
} CM2CON0bits @ 0x11A;
#endif

// Register: CM2CON1
volatile unsigned char           CM2CON1             @ 0x11B;
// bit and bitfield definitions
volatile bit C2SYNC              @ ((unsigned)&CM2CON1*8)+0;
volatile bit T1GSS               @ ((unsigned)&CM2CON1*8)+1;
volatile bit MC2OUT              @ ((unsigned)&CM2CON1*8)+6;
volatile bit MC1OUT              @ ((unsigned)&CM2CON1*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	C2SYNC              : 1;
        unsigned	T1GSS               : 1;
        unsigned	                    : 4;
        unsigned	MC2OUT              : 1;
        unsigned	MC1OUT              : 1;
    };
} CM2CON1bits @ 0x11B;
#endif

// Register: ANSEL
volatile unsigned char           ANSEL               @ 0x11E;
// bit and bitfield definitions
volatile bit ANS0                @ ((unsigned)&ANSEL*8)+0;
volatile bit ANS1                @ ((unsigned)&ANSEL*8)+1;
volatile bit ANS2                @ ((unsigned)&ANSEL*8)+2;
volatile bit ANS3                @ ((unsigned)&ANSEL*8)+3;
volatile bit ANS4                @ ((unsigned)&ANSEL*8)+4;
volatile bit ANS5                @ ((unsigned)&ANSEL*8)+5;
volatile bit ANS6                @ ((unsigned)&ANSEL*8)+6;
volatile bit ANS7                @ ((unsigned)&ANSEL*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	ANS0                : 1;
        unsigned	ANS1                : 1;
        unsigned	ANS2                : 1;
        unsigned	ANS3                : 1;
        unsigned	ANS4                : 1;
        unsigned	ANS5                : 1;
        unsigned	ANS6                : 1;
        unsigned	ANS7                : 1;
    };
} ANSELbits @ 0x11E;
#endif

// Register: ANSELH
volatile unsigned char           ANSELH              @ 0x11F;
// bit and bitfield definitions
volatile bit ANS8                @ ((unsigned)&ANSELH*8)+0;
volatile bit ANS9                @ ((unsigned)&ANSELH*8)+1;
volatile bit ANS10               @ ((unsigned)&ANSELH*8)+2;
volatile bit ANS11               @ ((unsigned)&ANSELH*8)+3;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	ANS8                : 1;
        unsigned	ANS9                : 1;
        unsigned	ANS10               : 1;
        unsigned	ANS11               : 1;
    };
} ANSELHbits @ 0x11F;
#endif

//
// Special function register definitions: Bank 3
//


// Register: EECON1
volatile unsigned char           EECON1              @ 0x18C;
// bit and bitfield definitions
volatile bit RD                  @ ((unsigned)&EECON1*8)+0;
volatile bit WR                  @ ((unsigned)&EECON1*8)+1;
volatile bit WREN                @ ((unsigned)&EECON1*8)+2;
volatile bit WRERR               @ ((unsigned)&EECON1*8)+3;
volatile bit EEPGD               @ ((unsigned)&EECON1*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	RD                  : 1;
        unsigned	WR                  : 1;
        unsigned	WREN                : 1;
        unsigned	WRERR               : 1;
        unsigned	                    : 3;
        unsigned	EEPGD               : 1;
    };
} EECON1bits @ 0x18C;
#endif

// Register: EECON2
volatile unsigned char           EECON2              @ 0x18D;
// bit and bitfield definitions

// Register: PSTRCON
volatile unsigned char           PSTRCON             @ 0x19D;
// bit and bitfield definitions
volatile bit STRA                @ ((unsigned)&PSTRCON*8)+0;
volatile bit STRB                @ ((unsigned)&PSTRCON*8)+1;
volatile bit STRC                @ ((unsigned)&PSTRCON*8)+2;
volatile bit STRD                @ ((unsigned)&PSTRCON*8)+3;
volatile bit STRSYNC             @ ((unsigned)&PSTRCON*8)+4;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	STRA                : 1;
        unsigned	STRB                : 1;
        unsigned	STRC                : 1;
        unsigned	STRD                : 1;
        unsigned	STRSYNC             : 1;
    };
} PSTRCONbits @ 0x19D;
#endif

// Register: SRCON
volatile unsigned char           SRCON               @ 0x19E;
// bit and bitfield definitions
volatile bit PULSR               @ ((unsigned)&SRCON*8)+2;
volatile bit PULSS               @ ((unsigned)&SRCON*8)+3;
volatile bit C2REN               @ ((unsigned)&SRCON*8)+4;
volatile bit C1SEN               @ ((unsigned)&SRCON*8)+5;
volatile bit SR0                 @ ((unsigned)&SRCON*8)+6;
volatile bit SR1                 @ ((unsigned)&SRCON*8)+7;
#ifndef _LIB_BUILD
volatile union {
    struct {
        unsigned	                    : 2;
        unsigned	PULSR               : 1;
        unsigned	PULSS               : 1;
        unsigned	C2REN               : 1;
        unsigned	C1SEN               : 1;
        unsigned	SR                  : 2;
    };
    struct {
        unsigned	: 6;
        unsigned	SR0                 : 1;
        unsigned	SR1                 : 1;
    };
} SRCONbits @ 0x19E;
#endif

#endif
