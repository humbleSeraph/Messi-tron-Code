opt subtitle "HI-TECH Software Omniscient Code Generator (Lite mode) build 9453"

opt pagewidth 120

	opt lm

	processor	16F690
clrc	macro
	bcf	3,0
	endm
clrz	macro
	bcf	3,2
	endm
setc	macro
	bsf	3,0
	endm
setz	macro
	bsf	3,2
	endm
skipc	macro
	btfss	3,0
	endm
skipz	macro
	btfss	3,2
	endm
skipnc	macro
	btfsc	3,0
	endm
skipnz	macro
	btfsc	3,2
	endm
indf	equ	0
indf0	equ	0
pc	equ	2
pcl	equ	2
status	equ	3
fsr	equ	4
fsr0	equ	4
c	equ	1
z	equ	0
pclath	equ	10
# 26 "U:\_218c Teams\BringItOn\218C Project - World Cup\COACH CODE WE ARE USING\SlaveCoach\SlaveCoach\CoachSlaveCode.c"
	psect config,class=CONFIG,delta=2 ;#
# 26 "U:\_218c Teams\BringItOn\218C Project - World Cup\COACH CODE WE ARE USING\SlaveCoach\SlaveCoach\CoachSlaveCode.c"
	dw 0xFFFF & 0xFFF7 & 0xFFEF & 0xFFFC & 0xFFDF ;#
	FNCALL	_main,_InitTimers
	FNCALL	_main,_InitPorts
	FNCALL	_main,_InitComm
	FNCALL	_main,_InitInterrupts
	FNCALL	_main,_Initialize_Sensors
	FNCALL	_main,_ReadKick
	FNCALL	_main,_ReadWhimsy
	FNCALL	_InitComm,_ReadPlayer
	FNROOT	_main
	FNCALL	_ISR,_Read_Thrust
	FNCALL	_ISR,i1_ReadKick
	FNCALL	_ISR,i1_ReadWhimsy
	FNCALL	_ISR,_UpdateEnergy
	FNCALL	_ISR,i1_ReadPlayer
	FNCALL	intlevel1,_ISR
	global	intlevel1
	FNROOT	intlevel1
	global	_BytesIn
	global	_BytesOut
	global	_ActiveCommuncation
	global	_LeftCrossingFlag
	global	_LeftZCR
	global	_NominalAccelerationLeft
	global	_NominalAccelerationRight
	global	_RightCrossingFlag
	global	_RightThrust
	global	_RightZCR
	global	_TOCounter
	global	_LeftTemp
	global	_LeftThrust
	global	_MagnetL
	global	_Microphone
	global	_RightTemp
	global	_i
	global	_ADCON0
psect	text406,local,class=CODE,delta=2
global __ptext406
__ptext406:
_ADCON0	set	31
	global	_ADRESH
_ADRESH	set	30
	global	_INTCON
_INTCON	set	11
	global	_PIR1
_PIR1	set	12
	global	_PORTA
_PORTA	set	5
	global	_PORTB
_PORTB	set	6
	global	_PORTC
_PORTC	set	7
	global	_SSPBUF
_SSPBUF	set	19
	global	_T2CON
_T2CON	set	18
	global	_CARRY
_CARRY	set	24
	global	_CKP
_CKP	set	164
	global	_GIE
_GIE	set	95
	global	_SSPEN
_SSPEN	set	165
	global	_SSPIF
_SSPIF	set	99
	global	_SSPM0
_SSPM0	set	160
	global	_SSPM1
_SSPM1	set	161
	global	_SSPM2
_SSPM2	set	162
	global	_SSPM3
_SSPM3	set	163
	global	_SSPOV
_SSPOV	set	166
	global	_TMR2IF
_TMR2IF	set	97
	global	_WCOL
_WCOL	set	167
	global	_ADCON1
_ADCON1	set	159
	global	_OSCCON
_OSCCON	set	143
	global	_PR2
_PR2	set	146
	global	_SSPSTAT
_SSPSTAT	set	148
	global	_TRISA
_TRISA	set	133
	global	_TRISB
_TRISB	set	134
	global	_TRISC
_TRISC	set	135
	global	_SSPIE
_SSPIE	set	1123
	global	_TMR2IE
_TMR2IE	set	1121
	global	_ANSEL
_ANSEL	set	286
	global	_ANSELH
_ANSELH	set	287
	global	_EEADR
_EEADR	set	269
	global	_EEDATA
_EEDATA	set	268
	global	_EECON1
_EECON1	set	396
	global	_EECON2
_EECON2	set	397
	global	_RD
_RD	set	3168
	global	_WR
_WR	set	3169
	global	_WREN
_WREN	set	3170
	file	"SlaveCoach.as"
	line	#
psect cinit,class=CODE,delta=2
global start_initialization
start_initialization:

psect	bssCOMMON,class=COMMON,space=1
global __pbssCOMMON
__pbssCOMMON:
_LeftTemp:
       ds      1

_LeftThrust:
       ds      1

_MagnetL:
       ds      1

_Microphone:
       ds      1

_RightTemp:
       ds      1

_i:
       ds      1

psect	bssBANK0,class=BANK0,space=1
global __pbssBANK0
__pbssBANK0:
_BytesIn:
       ds      8

_BytesOut:
       ds      8

_ActiveCommuncation:
       ds      1

_LeftCrossingFlag:
       ds      1

_LeftZCR:
       ds      1

_NominalAccelerationLeft:
       ds      1

_NominalAccelerationRight:
       ds      1

_RightCrossingFlag:
       ds      1

_RightThrust:
       ds      1

_RightZCR:
       ds      1

_TOCounter:
       ds      1

psect clrtext,class=CODE,delta=2
global clear_ram
;	Called with FSR containing the base address, and
;	W with the last address+1
clear_ram:
	clrwdt			;clear the watchdog before getting into this loop
clrloop:
	clrf	indf		;clear RAM location pointed to by FSR
	incf	fsr,f		;increment pointer
	xorwf	fsr,w		;XOR with final address
	btfsc	status,2	;have we reached the end yet?
	retlw	0		;all done for this memory range, return
	xorwf	fsr,w		;XOR again to restore value
	goto	clrloop		;do the next byte

; Clear objects allocated to COMMON
psect cinit,class=CODE,delta=2
	movlw	low(__pbssCOMMON)
	movwf	fsr
	movlw	low((__pbssCOMMON)+06h)
	fcall	clear_ram
; Clear objects allocated to BANK0
psect cinit,class=CODE,delta=2
	bcf	status, 7	;select IRP bank0
	movlw	low(__pbssBANK0)
	movwf	fsr
	movlw	low((__pbssBANK0)+019h)
	fcall	clear_ram
psect cinit,class=CODE,delta=2
global end_of_initialization

;End of C runtime variable initialization code

end_of_initialization:
clrf status
ljmp _main	;jump to C main() function
psect	cstackCOMMON,class=COMMON,space=1
global __pcstackCOMMON
__pcstackCOMMON:
	global	?_InitTimers
?_InitTimers:	; 0 bytes @ 0x0
	global	?_InitPorts
?_InitPorts:	; 0 bytes @ 0x0
	global	?_InitComm
?_InitComm:	; 0 bytes @ 0x0
	global	?_InitInterrupts
?_InitInterrupts:	; 0 bytes @ 0x0
	global	?_Initialize_Sensors
?_Initialize_Sensors:	; 0 bytes @ 0x0
	global	?_ReadKick
?_ReadKick:	; 0 bytes @ 0x0
	global	?_ReadWhimsy
?_ReadWhimsy:	; 0 bytes @ 0x0
	global	?_Read_Thrust
?_Read_Thrust:	; 0 bytes @ 0x0
	global	??_Read_Thrust
??_Read_Thrust:	; 0 bytes @ 0x0
	global	?_UpdateEnergy
?_UpdateEnergy:	; 0 bytes @ 0x0
	global	??_UpdateEnergy
??_UpdateEnergy:	; 0 bytes @ 0x0
	global	?_main
?_main:	; 0 bytes @ 0x0
	global	?_ISR
?_ISR:	; 0 bytes @ 0x0
	global	??i1_ReadPlayer
??i1_ReadPlayer:	; 0 bytes @ 0x0
	global	?i1_ReadKick
?i1_ReadKick:	; 0 bytes @ 0x0
	global	??i1_ReadKick
??i1_ReadKick:	; 0 bytes @ 0x0
	global	?i1_ReadWhimsy
?i1_ReadWhimsy:	; 0 bytes @ 0x0
	global	??i1_ReadWhimsy
??i1_ReadWhimsy:	; 0 bytes @ 0x0
	global	?_ReadPlayer
?_ReadPlayer:	; 1 bytes @ 0x0
	global	?i1_ReadPlayer
?i1_ReadPlayer:	; 1 bytes @ 0x0
	ds	1
	global	i1ReadPlayer@x
i1ReadPlayer@x:	; 1 bytes @ 0x1
	ds	1
	global	UpdateEnergy@x
UpdateEnergy@x:	; 1 bytes @ 0x2
	ds	1
	global	??_ISR
??_ISR:	; 0 bytes @ 0x3
	ds	5
psect	cstackBANK0,class=BANK0,space=1
global __pcstackBANK0
__pcstackBANK0:
	global	??_InitTimers
??_InitTimers:	; 0 bytes @ 0x0
	global	??_InitPorts
??_InitPorts:	; 0 bytes @ 0x0
	global	??_InitInterrupts
??_InitInterrupts:	; 0 bytes @ 0x0
	global	??_Initialize_Sensors
??_Initialize_Sensors:	; 0 bytes @ 0x0
	global	??_ReadKick
??_ReadKick:	; 0 bytes @ 0x0
	global	??_ReadWhimsy
??_ReadWhimsy:	; 0 bytes @ 0x0
	global	??_ReadPlayer
??_ReadPlayer:	; 0 bytes @ 0x0
	ds	1
	global	ReadPlayer@x
ReadPlayer@x:	; 1 bytes @ 0x1
	ds	1
	global	??_InitComm
??_InitComm:	; 0 bytes @ 0x2
	ds	1
	global	??_main
??_main:	; 0 bytes @ 0x3
;;Data sizes: Strings 0, constant 0, data 0, bss 31, persistent 0 stack 0
;;Auto spaces:   Size  Autos    Used
;; COMMON          14      8      14
;; BANK0           80      3      28
;; BANK1           80      0       0
;; BANK2           80      0       0

;;
;; Pointer list with targets:



;;
;; Critical Paths under _main in COMMON
;;
;;   None.
;;
;; Critical Paths under _ISR in COMMON
;;
;;   _ISR->_UpdateEnergy
;;
;; Critical Paths under _main in BANK0
;;
;;   _main->_InitComm
;;   _InitComm->_ReadPlayer
;;
;; Critical Paths under _ISR in BANK0
;;
;;   None.
;;
;; Critical Paths under _main in BANK1
;;
;;   None.
;;
;; Critical Paths under _ISR in BANK1
;;
;;   None.
;;
;; Critical Paths under _main in BANK2
;;
;;   None.
;;
;; Critical Paths under _ISR in BANK2
;;
;;   None.

;;
;;Main: autosize = 0, tempsize = 0, incstack = 0, save=0
;;

;;
;;Call Graph Tables:
;;
;; ---------------------------------------------------------------------------------
;; (Depth) Function   	        Calls       Base Space   Used Autos Params    Refs
;; ---------------------------------------------------------------------------------
;; (0) _main                                                 0     0      0      24
;;                         _InitTimers
;;                          _InitPorts
;;                           _InitComm
;;                     _InitInterrupts
;;                 _Initialize_Sensors
;;                           _ReadKick
;;                         _ReadWhimsy
;; ---------------------------------------------------------------------------------
;; (1) _InitComm                                             1     1      0      24
;;                                              2 BANK0      1     1      0
;;                         _ReadPlayer
;; ---------------------------------------------------------------------------------
;; (2) _ReadPlayer                                           2     2      0      24
;;                                              0 BANK0      2     2      0
;; ---------------------------------------------------------------------------------
;; (1) _ReadWhimsy                                           0     0      0       0
;; ---------------------------------------------------------------------------------
;; (1) _ReadKick                                             0     0      0       0
;; ---------------------------------------------------------------------------------
;; (1) _Initialize_Sensors                                   1     1      0       0
;;                                              0 BANK0      1     1      0
;; ---------------------------------------------------------------------------------
;; (1) _InitInterrupts                                       0     0      0       0
;; ---------------------------------------------------------------------------------
;; (1) _InitPorts                                            0     0      0       0
;; ---------------------------------------------------------------------------------
;; (1) _InitTimers                                           0     0      0       0
;; ---------------------------------------------------------------------------------
;; Estimated maximum stack depth 2
;; ---------------------------------------------------------------------------------
;; (Depth) Function   	        Calls       Base Space   Used Autos Params    Refs
;; ---------------------------------------------------------------------------------
;; (3) _ISR                                                  5     5      0     143
;;                                              3 COMMON     5     5      0
;;                        _Read_Thrust
;;                         i1_ReadKick
;;                       i1_ReadWhimsy
;;                       _UpdateEnergy
;;                       i1_ReadPlayer
;; ---------------------------------------------------------------------------------
;; (4) i1_ReadWhimsy                                         0     0      0       0
;; ---------------------------------------------------------------------------------
;; (4) i1_ReadKick                                           0     0      0       0
;; ---------------------------------------------------------------------------------
;; (4) i1_ReadPlayer                                         2     2      0      77
;;                                              0 COMMON     2     2      0
;; ---------------------------------------------------------------------------------
;; (4) _UpdateEnergy                                         3     3      0      66
;;                                              0 COMMON     3     3      0
;; ---------------------------------------------------------------------------------
;; (4) _Read_Thrust                                          1     1      0       0
;;                                              0 COMMON     1     1      0
;; ---------------------------------------------------------------------------------
;; Estimated maximum stack depth 4
;; ---------------------------------------------------------------------------------

;; Call Graph Graphs:

;; _main (ROOT)
;;   _InitTimers
;;   _InitPorts
;;   _InitComm
;;     _ReadPlayer
;;   _InitInterrupts
;;   _Initialize_Sensors
;;   _ReadKick
;;   _ReadWhimsy
;;
;; _ISR (ROOT)
;;   _Read_Thrust
;;   i1_ReadKick
;;   i1_ReadWhimsy
;;   _UpdateEnergy
;;   i1_ReadPlayer
;;

;; Address spaces:

;;Name               Size   Autos  Total    Cost      Usage
;;BITCOMMON            E      0       0       0        0.0%
;;EEDATA             100      0       0       0        0.0%
;;NULL                 0      0       0       0        0.0%
;;CODE                 0      0       0       0        0.0%
;;COMMON               E      8       E       1      100.0%
;;BITSFR0              0      0       0       1        0.0%
;;SFR0                 0      0       0       1        0.0%
;;BITSFR1              0      0       0       2        0.0%
;;SFR1                 0      0       0       2        0.0%
;;STACK                0      0       6       2        0.0%
;;BANK0               50      3      1C       3       35.0%
;;BITBANK1            50      0       0       4        0.0%
;;BITSFR3              0      0       0       4        0.0%
;;SFR3                 0      0       0       4        0.0%
;;BANK1               50      0       0       5        0.0%
;;BITSFR2              0      0       0       5        0.0%
;;SFR2                 0      0       0       5        0.0%
;;BITBANK2            50      0       0       6        0.0%
;;BANK2               50      0       0       7        0.0%
;;ABS                  0      0      2A       8        0.0%
;;BITBANK0            50      0       0       9        0.0%
;;DATA                 0      0      30      10        0.0%

	global	_main
psect	maintext,global,class=CODE,delta=2
global __pmaintext
__pmaintext:

;; *************** function _main *****************
;; Defined at:
;;		line 88 in file "U:\_218c Teams\BringItOn\218C Project - World Cup\COACH CODE WE ARE USING\SlaveCoach\SlaveCoach\CoachSlaveCode.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg, status,2, status,0, pclath, cstack
;; Tracked objects:
;;		On entry : 17F/0
;;		On exit  : 0/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2
;;      Params:         0       0       0       0
;;      Locals:         0       0       0       0
;;      Temps:          0       0       0       0
;;      Totals:         0       0       0       0
;;Total ram usage:        0 bytes
;; Hardware stack levels required when called:    4
;; This function calls:
;;		_InitTimers
;;		_InitPorts
;;		_InitComm
;;		_InitInterrupts
;;		_Initialize_Sensors
;;		_ReadKick
;;		_ReadWhimsy
;; This function is called by:
;;		Startup code after reset
;; This function uses a non-reentrant model
;;
psect	maintext
	file	"U:\_218c Teams\BringItOn\218C Project - World Cup\COACH CODE WE ARE USING\SlaveCoach\SlaveCoach\CoachSlaveCode.c"
	line	88
	global	__size_of_main
	__size_of_main	equ	__end_of_main-_main
	
_main:	
	opt	stack 4
; Regs used in _main: [wreg+status,2+status,0+pclath+cstack]
	line	89
	
l3469:	
;CoachSlaveCode.c: 89: InitTimers();
	fcall	_InitTimers
	line	90
;CoachSlaveCode.c: 90: InitPorts();
	fcall	_InitPorts
	line	91
;CoachSlaveCode.c: 91: InitComm();
	fcall	_InitComm
	line	92
;CoachSlaveCode.c: 92: InitInterrupts();
	fcall	_InitInterrupts
	line	93
;CoachSlaveCode.c: 93: Initialize_Sensors();
	fcall	_Initialize_Sensors
	goto	l3471
	line	95
;CoachSlaveCode.c: 95: while(1)
	
l941:	
	line	98
	
l3471:	
;CoachSlaveCode.c: 96: {
;CoachSlaveCode.c: 98: ReadKick();
	fcall	_ReadKick
	line	99
	
l3473:	
;CoachSlaveCode.c: 99: ReadWhimsy();
	fcall	_ReadWhimsy
	goto	l3471
	line	100
	
l942:	
	line	95
	goto	l3471
	
l943:	
	line	102
	
l944:	
	global	start
	ljmp	start
	opt stack 0
GLOBAL	__end_of_main
	__end_of_main:
;; =============== function _main ends ============

	signat	_main,88
	global	_InitComm
psect	text407,local,class=CODE,delta=2
global __ptext407
__ptext407:

;; *************** function _InitComm *****************
;; Defined at:
;;		line 276 in file "U:\_218c Teams\BringItOn\218C Project - World Cup\COACH CODE WE ARE USING\SlaveCoach\SlaveCoach\CoachSlaveCode.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg, status,2, pclath, cstack
;; Tracked objects:
;;		On entry : 0/0
;;		On exit  : 0/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2
;;      Params:         0       0       0       0
;;      Locals:         0       0       0       0
;;      Temps:          0       1       0       0
;;      Totals:         0       1       0       0
;;Total ram usage:        1 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    3
;; This function calls:
;;		_ReadPlayer
;; This function is called by:
;;		_main
;; This function uses a non-reentrant model
;;
psect	text407
	file	"U:\_218c Teams\BringItOn\218C Project - World Cup\COACH CODE WE ARE USING\SlaveCoach\SlaveCoach\CoachSlaveCode.c"
	line	276
	global	__size_of_InitComm
	__size_of_InitComm	equ	__end_of_InitComm-_InitComm
	
_InitComm:	
	opt	stack 4
; Regs used in _InitComm: [wreg+status,2+pclath+cstack]
	line	278
	
l3435:	
;CoachSlaveCode.c: 278: SSPSTAT = 0;
	bsf	status, 5	;RP0=1, select bank1
	bcf	status, 6	;RP1=0, select bank1
	clrf	(148)^080h	;volatile
	line	279
	
l3437:	
;CoachSlaveCode.c: 279: WCOL = 0;
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	bcf	(167/8),(167)&7
	line	280
	
l3439:	
;CoachSlaveCode.c: 280: SSPOV = 0;
	bcf	(166/8),(166)&7
	line	281
	
l3441:	
;CoachSlaveCode.c: 281: SSPEN = 1;
	bsf	(165/8),(165)&7
	line	282
	
l3443:	
;CoachSlaveCode.c: 282: CKP = 1;
	bsf	(164/8),(164)&7
	line	283
	
l3445:	
;CoachSlaveCode.c: 283: SSPM3 = 0;
	bcf	(163/8),(163)&7
	line	284
	
l3447:	
;CoachSlaveCode.c: 284: SSPM2 = 1;
	bsf	(162/8),(162)&7
	line	285
	
l3449:	
;CoachSlaveCode.c: 285: SSPM1 = 0;
	bcf	(161/8),(161)&7
	line	286
	
l3451:	
;CoachSlaveCode.c: 286: SSPM0 = 0;
	bcf	(160/8),(160)&7
	line	289
	
l3453:	
;CoachSlaveCode.c: 289: BytesOut[1] = ReadPlayer();
	fcall	_ReadPlayer
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	movwf	(??_InitComm+0)+0
	movf	(??_InitComm+0)+0,w
	movwf	0+(_BytesOut)+01h
	line	290
	
l3455:	
;CoachSlaveCode.c: 290: BytesOut[2] = LeftTemp;
	movf	(_LeftTemp),w
	movwf	(??_InitComm+0)+0
	movf	(??_InitComm+0)+0,w
	movwf	0+(_BytesOut)+02h
	line	291
	
l3457:	
;CoachSlaveCode.c: 291: BytesOut[3] = RightTemp;
	movf	(_RightTemp),w
	movwf	(??_InitComm+0)+0
	movf	(??_InitComm+0)+0,w
	movwf	0+(_BytesOut)+03h
	line	292
	
l3459:	
;CoachSlaveCode.c: 292: BytesOut[4] = 0;
	clrf	0+(_BytesOut)+04h
	line	293
	
l3461:	
;CoachSlaveCode.c: 293: BytesOut[5] = Microphone;
	movf	(_Microphone),w
	movwf	(??_InitComm+0)+0
	movf	(??_InitComm+0)+0,w
	movwf	0+(_BytesOut)+05h
	line	294
	
l3463:	
;CoachSlaveCode.c: 294: BytesOut[6] = MagnetL;
	movf	(_MagnetL),w
	movwf	(??_InitComm+0)+0
	movf	(??_InitComm+0)+0,w
	movwf	0+(_BytesOut)+06h
	line	295
	
l3465:	
;CoachSlaveCode.c: 295: BytesOut[7] = 0;
	clrf	0+(_BytesOut)+07h
	line	297
	
l3467:	
;CoachSlaveCode.c: 297: BytesIn[1] = 0;
	clrf	0+(_BytesIn)+01h
	line	298
	
l997:	
	return
	opt stack 0
GLOBAL	__end_of_InitComm
	__end_of_InitComm:
;; =============== function _InitComm ends ============

	signat	_InitComm,88
	global	_ReadPlayer
psect	text408,local,class=CODE,delta=2
global __ptext408
__ptext408:

;; *************** function _ReadPlayer *****************
;; Defined at:
;;		line 162 in file "U:\_218c Teams\BringItOn\218C Project - World Cup\COACH CODE WE ARE USING\SlaveCoach\SlaveCoach\CoachSlaveCode.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;  x               1    1[BANK0 ] unsigned char 
;; Return value:  Size  Location     Type
;;                  1    wreg      char 
;; Registers used:
;;		wreg, status,2
;; Tracked objects:
;;		On entry : 0/0
;;		On exit  : 0/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2
;;      Params:         0       0       0       0
;;      Locals:         0       1       0       0
;;      Temps:          0       1       0       0
;;      Totals:         0       2       0       0
;;Total ram usage:        2 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    2
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_InitComm
;; This function uses a non-reentrant model
;;
psect	text408
	file	"U:\_218c Teams\BringItOn\218C Project - World Cup\COACH CODE WE ARE USING\SlaveCoach\SlaveCoach\CoachSlaveCode.c"
	line	162
	global	__size_of_ReadPlayer
	__size_of_ReadPlayer	equ	__end_of_ReadPlayer-_ReadPlayer
	
_ReadPlayer:	
	opt	stack 4
; Regs used in _ReadPlayer: [wreg+status,2]
	line	164
	
l3411:	
;CoachSlaveCode.c: 164: unsigned char x=0;
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	clrf	(ReadPlayer@x)
	line	165
	
l3413:	
;CoachSlaveCode.c: 165: x = PORTC & 0b00011111 ;
	movf	(7),w
	andlw	01Fh
	movwf	(??_ReadPlayer+0)+0
	movf	(??_ReadPlayer+0)+0,w
	movwf	(ReadPlayer@x)
	line	166
	
l3415:	
;CoachSlaveCode.c: 166: return x;
	movf	(ReadPlayer@x),w
	goto	l953
	
l3417:	
	line	167
	
l953:	
	return
	opt stack 0
GLOBAL	__end_of_ReadPlayer
	__end_of_ReadPlayer:
;; =============== function _ReadPlayer ends ============

	signat	_ReadPlayer,89
	global	_ReadWhimsy
psect	text409,local,class=CODE,delta=2
global __ptext409
__ptext409:

;; *************** function _ReadWhimsy *****************
;; Defined at:
;;		line 212 in file "U:\_218c Teams\BringItOn\218C Project - World Cup\COACH CODE WE ARE USING\SlaveCoach\SlaveCoach\CoachSlaveCode.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		None
;; Tracked objects:
;;		On entry : 0/0
;;		On exit  : 0/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2
;;      Params:         0       0       0       0
;;      Locals:         0       0       0       0
;;      Temps:          0       0       0       0
;;      Totals:         0       0       0       0
;;Total ram usage:        0 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    2
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_main
;; This function uses a non-reentrant model
;;
psect	text409
	file	"U:\_218c Teams\BringItOn\218C Project - World Cup\COACH CODE WE ARE USING\SlaveCoach\SlaveCoach\CoachSlaveCode.c"
	line	212
	global	__size_of_ReadWhimsy
	__size_of_ReadWhimsy	equ	__end_of_ReadWhimsy-_ReadWhimsy
	
_ReadWhimsy:	
	opt	stack 5
; Regs used in _ReadWhimsy: []
	line	214
	
l3327:	
;CoachSlaveCode.c: 214: if ( (PORTA & 0x00000008)==0 )
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	btfsc	(5),(3)&7
	goto	u2471
	goto	u2470
u2471:
	goto	l976
u2470:
	line	216
	
l3329:	
;CoachSlaveCode.c: 215: {
;CoachSlaveCode.c: 216: MagnetL = 0xFF;
	clrf	(_MagnetL)
	decf	(_MagnetL),f
	goto	l976
	line	217
	
l975:	
	line	218
	
l976:	
	return
	opt stack 0
GLOBAL	__end_of_ReadWhimsy
	__end_of_ReadWhimsy:
;; =============== function _ReadWhimsy ends ============

	signat	_ReadWhimsy,88
	global	_ReadKick
psect	text410,local,class=CODE,delta=2
global __ptext410
__ptext410:

;; *************** function _ReadKick *****************
;; Defined at:
;;		line 171 in file "U:\_218c Teams\BringItOn\218C Project - World Cup\COACH CODE WE ARE USING\SlaveCoach\SlaveCoach\CoachSlaveCode.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		None
;; Tracked objects:
;;		On entry : 0/0
;;		On exit  : 0/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2
;;      Params:         0       0       0       0
;;      Locals:         0       0       0       0
;;      Temps:          0       0       0       0
;;      Totals:         0       0       0       0
;;Total ram usage:        0 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    2
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_main
;; This function uses a non-reentrant model
;;
psect	text410
	file	"U:\_218c Teams\BringItOn\218C Project - World Cup\COACH CODE WE ARE USING\SlaveCoach\SlaveCoach\CoachSlaveCode.c"
	line	171
	global	__size_of_ReadKick
	__size_of_ReadKick	equ	__end_of_ReadKick-_ReadKick
	
_ReadKick:	
	opt	stack 5
; Regs used in _ReadKick: []
	line	173
	
l3323:	
;CoachSlaveCode.c: 173: if( ( (PORTA & 0x00000004)==0 ) ||( (PORTA & 0x00000008)==0 ) )
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	btfss	(5),(2)&7
	goto	u2451
	goto	u2450
u2451:
	goto	l958
u2450:
	
l3325:	
	btfsc	(5),(3)&7
	goto	u2461
	goto	u2460
u2461:
	goto	l959
u2460:
	
l958:	
	line	175
;CoachSlaveCode.c: 174: {
;CoachSlaveCode.c: 175: Microphone = 0xFF;
	clrf	(_Microphone)
	decf	(_Microphone),f
	goto	l959
	line	176
	
l956:	
	line	177
	
l959:	
	return
	opt stack 0
GLOBAL	__end_of_ReadKick
	__end_of_ReadKick:
;; =============== function _ReadKick ends ============

	signat	_ReadKick,88
	global	_Initialize_Sensors
psect	text411,local,class=CODE,delta=2
global __ptext411
__ptext411:

;; *************** function _Initialize_Sensors *****************
;; Defined at:
;;		line 303 in file "U:\_218c Teams\BringItOn\218C Project - World Cup\COACH CODE WE ARE USING\SlaveCoach\SlaveCoach\CoachSlaveCode.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg
;; Tracked objects:
;;		On entry : 0/0
;;		On exit  : 0/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2
;;      Params:         0       0       0       0
;;      Locals:         0       0       0       0
;;      Temps:          0       1       0       0
;;      Totals:         0       1       0       0
;;Total ram usage:        1 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    2
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_main
;; This function uses a non-reentrant model
;;
psect	text411
	file	"U:\_218c Teams\BringItOn\218C Project - World Cup\COACH CODE WE ARE USING\SlaveCoach\SlaveCoach\CoachSlaveCode.c"
	line	303
	global	__size_of_Initialize_Sensors
	__size_of_Initialize_Sensors	equ	__end_of_Initialize_Sensors-_Initialize_Sensors
	
_Initialize_Sensors:	
	opt	stack 5
; Regs used in _Initialize_Sensors: [wreg]
	line	305
	
l3313:	
;CoachSlaveCode.c: 305: ADCON1 = 0x00000020;
	movlw	(020h)
	bsf	status, 5	;RP0=1, select bank1
	bcf	status, 6	;RP1=0, select bank1
	movwf	(159)^080h	;volatile
	line	310
;CoachSlaveCode.c: 310: ADCON0 = (0x00000001);
	movlw	(01h)
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	movwf	(31)	;volatile
	line	311
	
l3315:	
;CoachSlaveCode.c: 311: ADCON0 |= 0x00000002;
	bsf	(31)+(1/8),(1)&7	;volatile
	line	312
;CoachSlaveCode.c: 312: while (ADCON0 & 0x00000002)
	goto	l1000
	
l1001:	
	line	313
;CoachSlaveCode.c: 313: ;
	
l1000:	
	line	312
	btfsc	(31),(1)&7
	goto	u2431
	goto	u2430
u2431:
	goto	l1000
u2430:
	goto	l3317
	
l1002:	
	line	314
	
l3317:	
;CoachSlaveCode.c: 314: NominalAccelerationLeft = ADRESH;
	movf	(30),w	;volatile
	movwf	(??_Initialize_Sensors+0)+0
	movf	(??_Initialize_Sensors+0)+0,w
	movwf	(_NominalAccelerationLeft)
	line	317
;CoachSlaveCode.c: 317: ADCON0 = (0x00000004|0x00000001);
	movlw	(05h)
	movwf	(31)	;volatile
	line	318
	
l3319:	
;CoachSlaveCode.c: 318: ADCON0 |= 0x00000002;
	bsf	(31)+(1/8),(1)&7	;volatile
	line	319
;CoachSlaveCode.c: 319: while (ADCON0 & 0x00000002)
	goto	l1003
	
l1004:	
	line	320
;CoachSlaveCode.c: 320: ;
	
l1003:	
	line	319
	btfsc	(31),(1)&7
	goto	u2441
	goto	u2440
u2441:
	goto	l1003
u2440:
	goto	l3321
	
l1005:	
	line	321
	
l3321:	
;CoachSlaveCode.c: 321: NominalAccelerationRight = ADRESH;
	movf	(30),w	;volatile
	movwf	(??_Initialize_Sensors+0)+0
	movf	(??_Initialize_Sensors+0)+0,w
	movwf	(_NominalAccelerationRight)
	line	322
	
l1006:	
	return
	opt stack 0
GLOBAL	__end_of_Initialize_Sensors
	__end_of_Initialize_Sensors:
;; =============== function _Initialize_Sensors ends ============

	signat	_Initialize_Sensors,88
	global	_InitInterrupts
psect	text412,local,class=CODE,delta=2
global __ptext412
__ptext412:

;; *************** function _InitInterrupts *****************
;; Defined at:
;;		line 265 in file "U:\_218c Teams\BringItOn\218C Project - World Cup\COACH CODE WE ARE USING\SlaveCoach\SlaveCoach\CoachSlaveCode.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg, status,2
;; Tracked objects:
;;		On entry : 0/0
;;		On exit  : 0/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2
;;      Params:         0       0       0       0
;;      Locals:         0       0       0       0
;;      Temps:          0       0       0       0
;;      Totals:         0       0       0       0
;;Total ram usage:        0 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    2
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_main
;; This function uses a non-reentrant model
;;
psect	text412
	file	"U:\_218c Teams\BringItOn\218C Project - World Cup\COACH CODE WE ARE USING\SlaveCoach\SlaveCoach\CoachSlaveCode.c"
	line	265
	global	__size_of_InitInterrupts
	__size_of_InitInterrupts	equ	__end_of_InitInterrupts-_InitInterrupts
	
_InitInterrupts:	
	opt	stack 5
; Regs used in _InitInterrupts: [wreg+status,2]
	line	268
	
l3305:	
;CoachSlaveCode.c: 268: INTCON = 0b11000000;
	movlw	(0C0h)
	movwf	(11)	;volatile
	line	269
	
l3307:	
;CoachSlaveCode.c: 269: TMR2IE = 1;
	bsf	status, 5	;RP0=1, select bank1
	bcf	status, 6	;RP1=0, select bank1
	bsf	(1121/8)^080h,(1121)&7
	line	270
	
l3309:	
;CoachSlaveCode.c: 270: SSPIE = 1;
	bsf	(1123/8)^080h,(1123)&7
	line	271
	
l3311:	
;CoachSlaveCode.c: 271: PIR1 = 0;
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	clrf	(12)	;volatile
	line	272
	
l994:	
	return
	opt stack 0
GLOBAL	__end_of_InitInterrupts
	__end_of_InitInterrupts:
;; =============== function _InitInterrupts ends ============

	signat	_InitInterrupts,88
	global	_InitPorts
psect	text413,local,class=CODE,delta=2
global __ptext413
__ptext413:

;; *************** function _InitPorts *****************
;; Defined at:
;;		line 251 in file "U:\_218c Teams\BringItOn\218C Project - World Cup\COACH CODE WE ARE USING\SlaveCoach\SlaveCoach\CoachSlaveCode.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg, status,2
;; Tracked objects:
;;		On entry : 0/0
;;		On exit  : 0/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2
;;      Params:         0       0       0       0
;;      Locals:         0       0       0       0
;;      Temps:          0       0       0       0
;;      Totals:         0       0       0       0
;;Total ram usage:        0 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    2
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_main
;; This function uses a non-reentrant model
;;
psect	text413
	file	"U:\_218c Teams\BringItOn\218C Project - World Cup\COACH CODE WE ARE USING\SlaveCoach\SlaveCoach\CoachSlaveCode.c"
	line	251
	global	__size_of_InitPorts
	__size_of_InitPorts	equ	__end_of_InitPorts-_InitPorts
	
_InitPorts:	
	opt	stack 5
; Regs used in _InitPorts: [wreg+status,2]
	line	253
	
l3291:	
;CoachSlaveCode.c: 253: ANSEL = 0b00000011;
	movlw	(03h)
	bcf	status, 5	;RP0=0, select bank2
	bsf	status, 6	;RP1=1, select bank2
	movwf	(286)^0100h	;volatile
	line	254
	
l3293:	
;CoachSlaveCode.c: 254: ANSELH = 0;
	clrf	(287)^0100h	;volatile
	line	255
	
l3295:	
;CoachSlaveCode.c: 255: TRISA = 0b00001111;
	movlw	(0Fh)
	bsf	status, 5	;RP0=1, select bank1
	bcf	status, 6	;RP1=0, select bank1
	movwf	(133)^080h	;volatile
	line	256
	
l3297:	
;CoachSlaveCode.c: 256: TRISB = 0b01010000;
	movlw	(050h)
	movwf	(134)^080h	;volatile
	line	257
	
l3299:	
;CoachSlaveCode.c: 257: TRISC = 0b01111111;
	movlw	(07Fh)
	movwf	(135)^080h	;volatile
	line	258
	
l3301:	
;CoachSlaveCode.c: 258: PORTA = 0b00100000;
	movlw	(020h)
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	movwf	(5)	;volatile
	line	259
	
l3303:	
;CoachSlaveCode.c: 259: PORTB = 0b10100000;
	movlw	(0A0h)
	movwf	(6)	;volatile
	line	260
;CoachSlaveCode.c: 260: PORTC = 0;
	clrf	(7)	;volatile
	line	261
	
l991:	
	return
	opt stack 0
GLOBAL	__end_of_InitPorts
	__end_of_InitPorts:
;; =============== function _InitPorts ends ============

	signat	_InitPorts,88
	global	_InitTimers
psect	text414,local,class=CODE,delta=2
global __ptext414
__ptext414:

;; *************** function _InitTimers *****************
;; Defined at:
;;		line 241 in file "U:\_218c Teams\BringItOn\218C Project - World Cup\COACH CODE WE ARE USING\SlaveCoach\SlaveCoach\CoachSlaveCode.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg
;; Tracked objects:
;;		On entry : 0/0
;;		On exit  : 0/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2
;;      Params:         0       0       0       0
;;      Locals:         0       0       0       0
;;      Temps:          0       0       0       0
;;      Totals:         0       0       0       0
;;Total ram usage:        0 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    2
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_main
;; This function uses a non-reentrant model
;;
psect	text414
	file	"U:\_218c Teams\BringItOn\218C Project - World Cup\COACH CODE WE ARE USING\SlaveCoach\SlaveCoach\CoachSlaveCode.c"
	line	241
	global	__size_of_InitTimers
	__size_of_InitTimers	equ	__end_of_InitTimers-_InitTimers
	
_InitTimers:	
	opt	stack 5
; Regs used in _InitTimers: [wreg]
	line	243
	
l3289:	
;CoachSlaveCode.c: 243: OSCCON = 0b01000001;
	movlw	(041h)
	bsf	status, 5	;RP0=1, select bank1
	bcf	status, 6	;RP1=0, select bank1
	movwf	(143)^080h	;volatile
	line	245
;CoachSlaveCode.c: 245: T2CON = 0b01111110;
	movlw	(07Eh)
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	movwf	(18)	;volatile
	line	246
;CoachSlaveCode.c: 246: PR2 = 255;
	movlw	(0FFh)
	bsf	status, 5	;RP0=1, select bank1
	bcf	status, 6	;RP1=0, select bank1
	movwf	(146)^080h	;volatile
	line	247
	
l988:	
	return
	opt stack 0
GLOBAL	__end_of_InitTimers
	__end_of_InitTimers:
;; =============== function _InitTimers ends ============

	signat	_InitTimers,88
	global	_ISR
psect	text415,local,class=CODE,delta=2
global __ptext415
__ptext415:

;; *************** function _ISR *****************
;; Defined at:
;;		line 111 in file "U:\_218c Teams\BringItOn\218C Project - World Cup\COACH CODE WE ARE USING\SlaveCoach\SlaveCoach\CoachSlaveCode.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg, fsr0l, fsr0h, status,2, status,0, pclath, cstack
;; Tracked objects:
;;		On entry : 0/0
;;		On exit  : 0/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2
;;      Params:         0       0       0       0
;;      Locals:         0       0       0       0
;;      Temps:          5       0       0       0
;;      Totals:         5       0       0       0
;;Total ram usage:        5 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    1
;; This function calls:
;;		_Read_Thrust
;;		i1_ReadKick
;;		i1_ReadWhimsy
;;		_UpdateEnergy
;;		i1_ReadPlayer
;; This function is called by:
;;		Interrupt level 1
;; This function uses a non-reentrant model
;;
psect	text415
	file	"U:\_218c Teams\BringItOn\218C Project - World Cup\COACH CODE WE ARE USING\SlaveCoach\SlaveCoach\CoachSlaveCode.c"
	line	111
	global	__size_of_ISR
	__size_of_ISR	equ	__end_of_ISR-_ISR
	
_ISR:	
	opt	stack 4
; Regs used in _ISR: [wreg-fsr0h+status,2+status,0+pclath+cstack]
psect	intentry,class=CODE,delta=2
global __pintentry
__pintentry:
global interrupt_function
interrupt_function:
	global saved_w
	saved_w	set	btemp+0
	movwf	saved_w
	swapf	status,w
	movwf	(??_ISR+1)
	movf	fsr0,w
	movwf	(??_ISR+2)
	movf	pclath,w
	movwf	(??_ISR+3)
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	movf	btemp+1,w
	movwf	(??_ISR+4)
	ljmp	_ISR
psect	text415
	line	112
	
i1l3331:	
;CoachSlaveCode.c: 112: if (SSPIF)
	btfss	(99/8),(99)&7
	goto	u248_21
	goto	u248_20
u248_21:
	goto	i1l947
u248_20:
	line	114
	
i1l3333:	
;CoachSlaveCode.c: 113: {
;CoachSlaveCode.c: 114: BytesIn[i] = SSPBUF;
	movf	(19),w	;volatile
	movwf	(??_ISR+0)+0
	movf	(_i),w
	addlw	_BytesIn&0ffh
	movwf	fsr0
	movf	(??_ISR+0)+0,w
	bcf	status, 7	;select IRP bank0
	movwf	indf
	line	115
;CoachSlaveCode.c: 115: SSPBUF = BytesOut[i];
	movf	(_i),w
	addlw	_BytesOut&0ffh
	movwf	fsr0
	movf	indf,w
	movwf	(19)
	line	116
	
i1l3335:	
;CoachSlaveCode.c: 116: i++;
	movlw	(01h)
	movwf	(??_ISR+0)+0
	movf	(??_ISR+0)+0,w
	addwf	(_i),f
	line	117
	
i1l3337:	
;CoachSlaveCode.c: 117: if(i>=7)
	movlw	(07h)
	subwf	(_i),w
	skipc
	goto	u249_21
	goto	u249_20
u249_21:
	goto	i1l948
u249_20:
	line	119
	
i1l3339:	
;CoachSlaveCode.c: 118: {
;CoachSlaveCode.c: 119: i=0;
	clrf	(_i)
	line	121
;CoachSlaveCode.c: 121: Microphone = 0;
	clrf	(_Microphone)
	line	122
;CoachSlaveCode.c: 122: MagnetL = 0;
	clrf	(_MagnetL)
	line	123
	
i1l948:	
	line	125
;CoachSlaveCode.c: 123: }
;CoachSlaveCode.c: 125: SSPIF = 0;
	bcf	(99/8),(99)&7
	line	126
	
i1l947:	
	line	129
;CoachSlaveCode.c: 126: }
;CoachSlaveCode.c: 129: if (TMR2IF)
	btfss	(97/8),(97)&7
	goto	u250_21
	goto	u250_20
u250_21:
	goto	i1l950
u250_20:
	line	131
	
i1l3341:	
;CoachSlaveCode.c: 130: {
;CoachSlaveCode.c: 131: TOCounter++;
	movlw	(01h)
	movwf	(??_ISR+0)+0
	movf	(??_ISR+0)+0,w
	addwf	(_TOCounter),f
	line	132
	
i1l3343:	
;CoachSlaveCode.c: 132: Read_Thrust();
	fcall	_Read_Thrust
	line	133
	
i1l3345:	
;CoachSlaveCode.c: 133: ReadKick();
	fcall	i1_ReadKick
	line	134
	
i1l3347:	
;CoachSlaveCode.c: 134: ReadWhimsy();
	fcall	i1_ReadWhimsy
	line	138
	
i1l3349:	
;CoachSlaveCode.c: 138: UpdateEnergy(BytesIn[1]);
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	movf	0+(_BytesIn)+01h,w
	fcall	_UpdateEnergy
	line	143
	
i1l3351:	
;CoachSlaveCode.c: 143: BytesOut[0] = 0x37;
	movlw	(037h)
	movwf	(??_ISR+0)+0
	movf	(??_ISR+0)+0,w
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	movwf	(_BytesOut)
	line	144
	
i1l3353:	
;CoachSlaveCode.c: 144: BytesOut[1] = ReadPlayer();
	fcall	i1_ReadPlayer
	movwf	(??_ISR+0)+0
	movf	(??_ISR+0)+0,w
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	movwf	0+(_BytesOut)+01h
	line	145
	
i1l3355:	
;CoachSlaveCode.c: 145: BytesOut[2] = LeftTemp;
	movf	(_LeftTemp),w
	movwf	(??_ISR+0)+0
	movf	(??_ISR+0)+0,w
	movwf	0+(_BytesOut)+02h
	line	146
	
i1l3357:	
;CoachSlaveCode.c: 146: BytesOut[3] = RightTemp;
	movf	(_RightTemp),w
	movwf	(??_ISR+0)+0
	movf	(??_ISR+0)+0,w
	movwf	0+(_BytesOut)+03h
	line	147
	
i1l3359:	
;CoachSlaveCode.c: 147: BytesOut[4] = 0;
	clrf	0+(_BytesOut)+04h
	line	148
	
i1l3361:	
;CoachSlaveCode.c: 148: BytesOut[5] = Microphone;
	movf	(_Microphone),w
	movwf	(??_ISR+0)+0
	movf	(??_ISR+0)+0,w
	movwf	0+(_BytesOut)+05h
	line	149
	
i1l3363:	
;CoachSlaveCode.c: 149: BytesOut[6] = MagnetL;
	movf	(_MagnetL),w
	movwf	(??_ISR+0)+0
	movf	(??_ISR+0)+0,w
	movwf	0+(_BytesOut)+06h
	line	150
	
i1l3365:	
;CoachSlaveCode.c: 150: BytesOut[7] = 0;
	clrf	0+(_BytesOut)+07h
	line	151
	
i1l3367:	
;CoachSlaveCode.c: 151: TOCounter = 0;
	clrf	(_TOCounter)
	line	154
	
i1l3369:	
;CoachSlaveCode.c: 154: TMR2IF = 0;
	bcf	(97/8),(97)&7
	goto	i1l950
	line	155
	
i1l949:	
	goto	i1l950
	line	157
	
i1l3371:	
	line	158
;CoachSlaveCode.c: 155: }
;CoachSlaveCode.c: 157: return;
	
i1l950:	
	movf	(??_ISR+4),w
	movwf	btemp+1
	movf	(??_ISR+3),w
	movwf	pclath
	movf	(??_ISR+2),w
	movwf	fsr0
	swapf	(??_ISR+1)^0FFFFFF80h,w
	movwf	status
	swapf	saved_w,f
	swapf	saved_w,w
	retfie
	opt stack 0
GLOBAL	__end_of_ISR
	__end_of_ISR:
;; =============== function _ISR ends ============

	signat	_ISR,88
	global	i1_ReadWhimsy
psect	text416,local,class=CODE,delta=2
global __ptext416
__ptext416:

;; *************** function i1_ReadWhimsy *****************
;; Defined at:
;;		line 212 in file "U:\_218c Teams\BringItOn\218C Project - World Cup\COACH CODE WE ARE USING\SlaveCoach\SlaveCoach\CoachSlaveCode.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		None
;; Tracked objects:
;;		On entry : 0/0
;;		On exit  : 0/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2
;;      Params:         0       0       0       0
;;      Locals:         0       0       0       0
;;      Temps:          0       0       0       0
;;      Totals:         0       0       0       0
;;Total ram usage:        0 bytes
;; Hardware stack levels used:    1
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_ISR
;; This function uses a non-reentrant model
;;
psect	text416
	file	"U:\_218c Teams\BringItOn\218C Project - World Cup\COACH CODE WE ARE USING\SlaveCoach\SlaveCoach\CoachSlaveCode.c"
	line	212
	global	__size_ofi1_ReadWhimsy
	__size_ofi1_ReadWhimsy	equ	__end_ofi1_ReadWhimsy-i1_ReadWhimsy
	
i1_ReadWhimsy:	
	opt	stack 4
; Regs used in i1_ReadWhimsy: []
	line	214
	
i1l3431:	
;CoachSlaveCode.c: 214: if ( (PORTA & 0x00000008)==0 )
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	btfsc	(5),(3)&7
	goto	u260_21
	goto	u260_20
u260_21:
	goto	i1l976
u260_20:
	line	216
	
i1l3433:	
;CoachSlaveCode.c: 215: {
;CoachSlaveCode.c: 216: MagnetL = 0xFF;
	clrf	(_MagnetL)
	decf	(_MagnetL),f
	goto	i1l976
	line	217
	
i1l975:	
	line	218
	
i1l976:	
	return
	opt stack 0
GLOBAL	__end_ofi1_ReadWhimsy
	__end_ofi1_ReadWhimsy:
;; =============== function i1_ReadWhimsy ends ============

	signat	i1_ReadWhimsy,88
	global	i1_ReadKick
psect	text417,local,class=CODE,delta=2
global __ptext417
__ptext417:

;; *************** function i1_ReadKick *****************
;; Defined at:
;;		line 171 in file "U:\_218c Teams\BringItOn\218C Project - World Cup\COACH CODE WE ARE USING\SlaveCoach\SlaveCoach\CoachSlaveCode.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		None
;; Tracked objects:
;;		On entry : 0/0
;;		On exit  : 0/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2
;;      Params:         0       0       0       0
;;      Locals:         0       0       0       0
;;      Temps:          0       0       0       0
;;      Totals:         0       0       0       0
;;Total ram usage:        0 bytes
;; Hardware stack levels used:    1
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_ISR
;; This function uses a non-reentrant model
;;
psect	text417
	file	"U:\_218c Teams\BringItOn\218C Project - World Cup\COACH CODE WE ARE USING\SlaveCoach\SlaveCoach\CoachSlaveCode.c"
	line	171
	global	__size_ofi1_ReadKick
	__size_ofi1_ReadKick	equ	__end_ofi1_ReadKick-i1_ReadKick
	
i1_ReadKick:	
	opt	stack 4
; Regs used in i1_ReadKick: []
	line	173
	
i1l3427:	
;CoachSlaveCode.c: 173: if( ( (PORTA & 0x00000004)==0 ) ||( (PORTA & 0x00000008)==0 ) )
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	btfss	(5),(2)&7
	goto	u258_21
	goto	u258_20
u258_21:
	goto	i1l958
u258_20:
	
i1l3429:	
	btfsc	(5),(3)&7
	goto	u259_21
	goto	u259_20
u259_21:
	goto	i1l959
u259_20:
	
i1l958:	
	line	175
;CoachSlaveCode.c: 174: {
;CoachSlaveCode.c: 175: Microphone = 0xFF;
	clrf	(_Microphone)
	decf	(_Microphone),f
	goto	i1l959
	line	176
	
i1l956:	
	line	177
	
i1l959:	
	return
	opt stack 0
GLOBAL	__end_ofi1_ReadKick
	__end_ofi1_ReadKick:
;; =============== function i1_ReadKick ends ============

	signat	i1_ReadKick,88
	global	i1_ReadPlayer
psect	text418,local,class=CODE,delta=2
global __ptext418
__ptext418:

;; *************** function i1_ReadPlayer *****************
;; Defined at:
;;		line 162 in file "U:\_218c Teams\BringItOn\218C Project - World Cup\COACH CODE WE ARE USING\SlaveCoach\SlaveCoach\CoachSlaveCode.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;  ReadPlayer      1    1[COMMON] unsigned char 
;; Return value:  Size  Location     Type
;;                  1    wreg      char 
;; Registers used:
;;		wreg, status,2
;; Tracked objects:
;;		On entry : 0/0
;;		On exit  : 0/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2
;;      Params:         0       0       0       0
;;      Locals:         1       0       0       0
;;      Temps:          1       0       0       0
;;      Totals:         2       0       0       0
;;Total ram usage:        2 bytes
;; Hardware stack levels used:    1
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_ISR
;; This function uses a non-reentrant model
;;
psect	text418
	file	"U:\_218c Teams\BringItOn\218C Project - World Cup\COACH CODE WE ARE USING\SlaveCoach\SlaveCoach\CoachSlaveCode.c"
	line	162
	global	__size_ofi1_ReadPlayer
	__size_ofi1_ReadPlayer	equ	__end_ofi1_ReadPlayer-i1_ReadPlayer
	
i1_ReadPlayer:	
	opt	stack 4
; Regs used in i1_ReadPlayer: [wreg+status,2]
	line	164
	
i1l3419:	
;CoachSlaveCode.c: 164: unsigned char x=0;
	clrf	(i1ReadPlayer@x)
	line	165
	
i1l3421:	
;CoachSlaveCode.c: 165: x = PORTC & 0b00011111 ;
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	movf	(7),w
	andlw	01Fh
	movwf	(??i1_ReadPlayer+0)+0
	movf	(??i1_ReadPlayer+0)+0,w
	movwf	(i1ReadPlayer@x)
	line	166
	
i1l3423:	
;CoachSlaveCode.c: 166: return x;
	movf	(i1ReadPlayer@x),w
	goto	i1l953
	
i1l3425:	
	line	167
	
i1l953:	
	return
	opt stack 0
GLOBAL	__end_ofi1_ReadPlayer
	__end_ofi1_ReadPlayer:
;; =============== function i1_ReadPlayer ends ============

	signat	i1_ReadPlayer,89
	global	_UpdateEnergy
psect	text419,local,class=CODE,delta=2
global __ptext419
__ptext419:

;; *************** function _UpdateEnergy *****************
;; Defined at:
;;		line 222 in file "U:\_218c Teams\BringItOn\218C Project - World Cup\COACH CODE WE ARE USING\SlaveCoach\SlaveCoach\CoachSlaveCode.c"
;; Parameters:    Size  Location     Type
;;  x               1    wreg     char 
;; Auto vars:     Size  Location     Type
;;  x               1    2[COMMON] char 
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg, status,2, status,0
;; Tracked objects:
;;		On entry : 0/0
;;		On exit  : 0/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2
;;      Params:         0       0       0       0
;;      Locals:         1       0       0       0
;;      Temps:          2       0       0       0
;;      Totals:         3       0       0       0
;;Total ram usage:        3 bytes
;; Hardware stack levels used:    1
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_ISR
;; This function uses a non-reentrant model
;;
psect	text419
	file	"U:\_218c Teams\BringItOn\218C Project - World Cup\COACH CODE WE ARE USING\SlaveCoach\SlaveCoach\CoachSlaveCode.c"
	line	222
	global	__size_of_UpdateEnergy
	__size_of_UpdateEnergy	equ	__end_of_UpdateEnergy-_UpdateEnergy
	
_UpdateEnergy:	
	opt	stack 4
; Regs used in _UpdateEnergy: [wreg+status,2+status,0]
;UpdateEnergy@x stored from wreg
	movwf	(UpdateEnergy@x)
	line	223
	
i1l3399:	
;CoachSlaveCode.c: 223: if( (x & 0x00000001)!=0)
	movf	(UpdateEnergy@x),w
	movwf	(??_UpdateEnergy+0)+0
	clrf	(??_UpdateEnergy+0)+0+1
	btfsc	(??_UpdateEnergy+0)+0,7
	decf	(??_UpdateEnergy+0)+0+1,f
	btfss	0+(??_UpdateEnergy+0)+0,(0)&7
	goto	u255_21
	goto	u255_20
u255_21:
	goto	i1l979
u255_20:
	line	224
	
i1l3401:	
;CoachSlaveCode.c: 224: { PORTA &= ~0x00000020; }
	movlw	(0DFh)
	movwf	(??_UpdateEnergy+0)+0
	movf	(??_UpdateEnergy+0)+0,w
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	andwf	(5),f	;volatile
	goto	i1l3403
	line	225
	
i1l979:	
	line	226
;CoachSlaveCode.c: 225: else
;CoachSlaveCode.c: 226: { PORTA |= 0x00000020; }
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	bsf	(5)+(5/8),(5)&7	;volatile
	goto	i1l3403
	
i1l980:	
	line	228
	
i1l3403:	
;CoachSlaveCode.c: 228: if( (x & 0x00000002)!=0)
	movf	(UpdateEnergy@x),w
	movwf	(??_UpdateEnergy+0)+0
	clrf	(??_UpdateEnergy+0)+0+1
	btfsc	(??_UpdateEnergy+0)+0,7
	decf	(??_UpdateEnergy+0)+0+1,f
	btfss	0+(??_UpdateEnergy+0)+0,(1)&7
	goto	u256_21
	goto	u256_20
u256_21:
	goto	i1l981
u256_20:
	line	229
	
i1l3405:	
;CoachSlaveCode.c: 229: { PORTB &= ~0x00000080; }
	movlw	(07Fh)
	movwf	(??_UpdateEnergy+0)+0
	movf	(??_UpdateEnergy+0)+0,w
	andwf	(6),f	;volatile
	goto	i1l3407
	line	230
	
i1l981:	
	line	231
;CoachSlaveCode.c: 230: else
;CoachSlaveCode.c: 231: { PORTB |= 0x00000080; }
	bsf	(6)+(7/8),(7)&7	;volatile
	goto	i1l3407
	
i1l982:	
	line	233
	
i1l3407:	
;CoachSlaveCode.c: 233: if( (x & 0x00000004)!=0)
	movf	(UpdateEnergy@x),w
	movwf	(??_UpdateEnergy+0)+0
	clrf	(??_UpdateEnergy+0)+0+1
	btfsc	(??_UpdateEnergy+0)+0,7
	decf	(??_UpdateEnergy+0)+0+1,f
	btfss	0+(??_UpdateEnergy+0)+0,(2)&7
	goto	u257_21
	goto	u257_20
u257_21:
	goto	i1l983
u257_20:
	line	234
	
i1l3409:	
;CoachSlaveCode.c: 234: { PORTB &= ~0x00000020; }
	movlw	(0DFh)
	movwf	(??_UpdateEnergy+0)+0
	movf	(??_UpdateEnergy+0)+0,w
	andwf	(6),f	;volatile
	goto	i1l985
	line	235
	
i1l983:	
	line	236
;CoachSlaveCode.c: 235: else
;CoachSlaveCode.c: 236: { PORTB |= 0x00000020; }
	bsf	(6)+(5/8),(5)&7	;volatile
	goto	i1l985
	
i1l984:	
	line	237
	
i1l985:	
	return
	opt stack 0
GLOBAL	__end_of_UpdateEnergy
	__end_of_UpdateEnergy:
;; =============== function _UpdateEnergy ends ============

	signat	_UpdateEnergy,4216
	global	_Read_Thrust
psect	text420,local,class=CODE,delta=2
global __ptext420
__ptext420:

;; *************** function _Read_Thrust *****************
;; Defined at:
;;		line 181 in file "U:\_218c Teams\BringItOn\218C Project - World Cup\COACH CODE WE ARE USING\SlaveCoach\SlaveCoach\CoachSlaveCode.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg, status,2, status,0
;; Tracked objects:
;;		On entry : 0/0
;;		On exit  : 0/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2
;;      Params:         0       0       0       0
;;      Locals:         0       0       0       0
;;      Temps:          1       0       0       0
;;      Totals:         1       0       0       0
;;Total ram usage:        1 bytes
;; Hardware stack levels used:    1
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_ISR
;; This function uses a non-reentrant model
;;
psect	text420
	file	"U:\_218c Teams\BringItOn\218C Project - World Cup\COACH CODE WE ARE USING\SlaveCoach\SlaveCoach\CoachSlaveCode.c"
	line	181
	global	__size_of_Read_Thrust
	__size_of_Read_Thrust	equ	__end_of_Read_Thrust-_Read_Thrust
	
_Read_Thrust:	
	opt	stack 4
; Regs used in _Read_Thrust: [wreg+status,2+status,0]
	line	184
	
i1l3373:	
;CoachSlaveCode.c: 184: ADCON0 = (0x00000001);
	movlw	(01h)
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	movwf	(31)	;volatile
	line	185
	
i1l3375:	
;CoachSlaveCode.c: 185: ADCON0 |= 0x00000002;
	bsf	(31)+(1/8),(1)&7	;volatile
	line	186
;CoachSlaveCode.c: 186: while (ADCON0 & 0x00000002)
	goto	i1l962
	
i1l963:	
	line	187
;CoachSlaveCode.c: 187: ;
	
i1l962:	
	line	186
	btfsc	(31),(1)&7
	goto	u251_21
	goto	u251_20
u251_21:
	goto	i1l962
u251_20:
	goto	i1l3377
	
i1l964:	
	line	188
	
i1l3377:	
;CoachSlaveCode.c: 188: LeftThrust = ADRESH;
	movf	(30),w	;volatile
	movwf	(??_Read_Thrust+0)+0
	movf	(??_Read_Thrust+0)+0,w
	movwf	(_LeftThrust)
	line	189
;CoachSlaveCode.c: 189: LeftTemp = (signed char) LeftThrust;
	movf	(_LeftThrust),w
	movwf	(??_Read_Thrust+0)+0
	movf	(??_Read_Thrust+0)+0,w
	movwf	(_LeftTemp)
	line	190
	
i1l3379:	
;CoachSlaveCode.c: 190: if (LeftTemp < 0)
	btfss	(_LeftTemp),7
	goto	u252_21
	goto	u252_20
u252_21:
	goto	i1l3383
u252_20:
	line	191
	
i1l3381:	
;CoachSlaveCode.c: 191: LeftTemp = LeftTemp + 128;
	movf	(_LeftTemp),w
	addlw	-128
	movwf	(??_Read_Thrust+0)+0
	movf	(??_Read_Thrust+0)+0,w
	movwf	(_LeftTemp)
	goto	i1l3385
	line	192
	
i1l965:	
	line	193
	
i1l3383:	
;CoachSlaveCode.c: 192: else
;CoachSlaveCode.c: 193: LeftTemp = LeftTemp - 127;
	movf	(_LeftTemp),w
	addlw	-127
	movwf	(??_Read_Thrust+0)+0
	movf	(??_Read_Thrust+0)+0,w
	movwf	(_LeftTemp)
	goto	i1l3385
	
i1l966:	
	line	194
	
i1l3385:	
;CoachSlaveCode.c: 194: LeftTemp = -LeftTemp;
	comf	(_LeftTemp),f
	incf	(_LeftTemp),f
	line	197
;CoachSlaveCode.c: 197: ADCON0 = (0x00000004|0x00000001);
	movlw	(05h)
	movwf	(31)	;volatile
	line	198
	
i1l3387:	
;CoachSlaveCode.c: 198: ADCON0 |= 0x00000002;
	bsf	(31)+(1/8),(1)&7	;volatile
	line	199
;CoachSlaveCode.c: 199: while (ADCON0 & 0x00000002)
	goto	i1l967
	
i1l968:	
	line	200
;CoachSlaveCode.c: 200: ;
	
i1l967:	
	line	199
	btfsc	(31),(1)&7
	goto	u253_21
	goto	u253_20
u253_21:
	goto	i1l967
u253_20:
	goto	i1l3389
	
i1l969:	
	line	201
	
i1l3389:	
;CoachSlaveCode.c: 201: RightThrust = ADRESH;
	movf	(30),w	;volatile
	movwf	(??_Read_Thrust+0)+0
	movf	(??_Read_Thrust+0)+0,w
	movwf	(_RightThrust)
	line	202
;CoachSlaveCode.c: 202: RightTemp = (signed char) RightThrust;
	movf	(_RightThrust),w
	movwf	(??_Read_Thrust+0)+0
	movf	(??_Read_Thrust+0)+0,w
	movwf	(_RightTemp)
	line	203
	
i1l3391:	
;CoachSlaveCode.c: 203: if (RightTemp < 0)
	btfss	(_RightTemp),7
	goto	u254_21
	goto	u254_20
u254_21:
	goto	i1l3395
u254_20:
	line	204
	
i1l3393:	
;CoachSlaveCode.c: 204: RightTemp = RightTemp + 128;
	movf	(_RightTemp),w
	addlw	-128
	movwf	(??_Read_Thrust+0)+0
	movf	(??_Read_Thrust+0)+0,w
	movwf	(_RightTemp)
	goto	i1l3397
	line	205
	
i1l970:	
	line	206
	
i1l3395:	
;CoachSlaveCode.c: 205: else
;CoachSlaveCode.c: 206: RightTemp = RightTemp - 127;
	movf	(_RightTemp),w
	addlw	-127
	movwf	(??_Read_Thrust+0)+0
	movf	(??_Read_Thrust+0)+0,w
	movwf	(_RightTemp)
	goto	i1l3397
	
i1l971:	
	line	207
	
i1l3397:	
;CoachSlaveCode.c: 207: RightTemp = -RightTemp;
	comf	(_RightTemp),f
	incf	(_RightTemp),f
	line	208
	
i1l972:	
	return
	opt stack 0
GLOBAL	__end_of_Read_Thrust
	__end_of_Read_Thrust:
;; =============== function _Read_Thrust ends ============

	signat	_Read_Thrust,88
psect	text421,local,class=CODE,delta=2
global __ptext421
__ptext421:
	global	btemp
	btemp set 07Eh

	DABS	1,126,2	;btemp
	global	wtemp0
	wtemp0 set btemp
	end
