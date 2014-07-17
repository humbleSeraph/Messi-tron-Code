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
# 37 "U:\_218c Teams\BringItOn\218C Project - World Cup\COACH CODE WE ARE USING\MasterCoach\MasterCoach\CoachMasterCode.c"
	psect config,class=CONFIG,delta=2 ;#
# 37 "U:\_218c Teams\BringItOn\218C Project - World Cup\COACH CODE WE ARE USING\MasterCoach\MasterCoach\CoachMasterCode.c"
	dw 0xFFFF & 0xFFF7 & 0xFFEF & 0xFFFA & 0xFFFF ;#
	FNCALL	_main,_InitTimers
	FNCALL	_main,_InitPorts
	FNCALL	_main,_InitComm
	FNCALL	_main,_InitInterrupts
	FNCALL	_main,_Encode_Message
	FNCALL	_main,_CalculateChecksum
	FNCALL	_main,_XBee_State
	FNCALL	_main,_Process_Status
	FNROOT	_main
	FNCALL	_ISR,_Process_SPI
	FNCALL	_ISR,i1_XBee_State
	FNCALL	intlevel1,_ISR
	global	intlevel1
	FNROOT	intlevel1
	global	_AUX
	global	_CurrentType
	global	_DIR
	global	_NextByteOut
	global	_PAIRDATA
	global	_RESPDATA
	global	_SDATA
	global	_SPD
	global	_TAGINFO
	global	_X_API
	global	_X_AddrLSB
	global	_X_AddrMSB
	global	_X_CMD
	global	_X_FID
	global	_X_RF1
	global	_X_RF2
	global	_X_RF3
	global	_X_RF4
	global	_X_RF5
	global	_X_Transition
	global	_SwitchMask
psect	idataBANK0,class=CODE,space=0,delta=2
global __pidataBANK0
__pidataBANK0:
	file	"U:\_218c Teams\BringItOn\218C Project - World Cup\COACH CODE WE ARE USING\MasterCoach\MasterCoach\CoachMasterCode.c"
	line	132

;initializer for _AUX
	retlw	0FFh
	line	122

;initializer for _CurrentType
	retlw	06h
	line	131

;initializer for _DIR
	retlw	032h
	line	86

;initializer for _NextByteOut
	retlw	07Eh
	line	128

;initializer for _PAIRDATA
	retlw	06h
	line	129

;initializer for _RESPDATA
	retlw	07h
	line	127

;initializer for _SDATA
	retlw	09Fh
	line	130

;initializer for _SPD
	retlw	07Fh
	line	126

;initializer for _TAGINFO
	retlw	07h
	line	93

;initializer for _X_API
	retlw	01h
	line	96

;initializer for _X_AddrLSB
	retlw	-120
	line	95

;initializer for _X_AddrMSB
	retlw	020h
	line	98

;initializer for _X_CMD
	retlw	01h
	line	94

;initializer for _X_FID
	retlw	01h
	line	99

;initializer for _X_RF1
	retlw	0Ah
	line	100

;initializer for _X_RF2
	retlw	0Bh
	line	101

;initializer for _X_RF3
	retlw	0Ch
	line	102

;initializer for _X_RF4
	retlw	0Dh
	line	103

;initializer for _X_RF5
	retlw	0Eh
	line	80

;initializer for _X_Transition
	retlw	01h
psect	idataCOMMON,class=CODE,space=0,delta=2
global __pidataCOMMON
__pidataCOMMON:
	line	139

;initializer for _SwitchMask
	retlw	07h
	global	_BytesIn
	global	_BytesOut
	global	_TXData
	global	_ByteIn
	global	_CommActive
	global	_CurrentR_State
	global	_CurrentX_State
	global	_LostCommCounter
	global	_MessageCounter
	global	_NextR_State
	global	_NextX_State
	global	_PORTC_Copy
	global	_Paired
	global	_R_API
	global	_R_AddrLSB
	global	_R_AddrMSB
	global	_R_CMD
	global	_R_FID
	global	_R_LengthLSB
	global	_R_Options
	global	_R_RF1
	global	_R_STATUS
	global	_R_SigStr
	global	_R_Transition
	global	_SEND
	global	_SendKick
	global	_SendWhimsy
	global	_TRANS
	global	_WHIM
	global	_X_LengthLSB
	global	_X_LengthMSB
	global	_X_Options
	global	_i
	global	_TOCounter
	global	_PlayerAddress
	global	_R_LengthMSB
	global	_SPI_Var
	global	_SwitchState
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
	global	_RCREG
_RCREG	set	26
	global	_RCSTA
_RCSTA	set	24
	global	_SSPBUF
_SSPBUF	set	19
	global	_T2CON
_T2CON	set	18
	global	_TXREG
_TXREG	set	25
	global	_CARRY
_CARRY	set	24
	global	_CKP
_CKP	set	164
	global	_GIE
_GIE	set	95
	global	_RABIF
_RABIF	set	88
	global	_RCIF
_RCIF	set	101
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
	global	_TXIF
_TXIF	set	100
	global	_WCOL
_WCOL	set	167
	global	_IOCA
_IOCA	set	150
	global	_PR2
_PR2	set	146
	global	_SPBRG
_SPBRG	set	153
	global	_SPBRGH
_SPBRGH	set	154
	global	_SSPSTAT
_SSPSTAT	set	148
	global	_TRISA
_TRISA	set	133
	global	_TRISB
_TRISB	set	134
	global	_TRISC
_TRISC	set	135
	global	_TXSTA
_TXSTA	set	152
	global	_RCIE
_RCIE	set	1125
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
	file	"CoachCodeV2.as"
	line	#
psect cinit,class=CODE,delta=2
global start_initialization
start_initialization:

psect	bssCOMMON,class=COMMON,space=1
global __pbssCOMMON
__pbssCOMMON:
_TOCounter:
       ds      2

_PlayerAddress:
       ds      1

_R_LengthMSB:
       ds      1

_SPI_Var:
       ds      1

_SwitchState:
       ds      1

psect	dataCOMMON,class=COMMON,space=1
global __pdataCOMMON
__pdataCOMMON:
	file	"U:\_218c Teams\BringItOn\218C Project - World Cup\COACH CODE WE ARE USING\MasterCoach\MasterCoach\CoachMasterCode.c"
_SwitchMask:
       ds      1

psect	bssBANK0,class=BANK0,space=1
global __pbssBANK0
__pbssBANK0:
_BytesIn:
       ds      8

_BytesOut:
       ds      8

_TXData:
       ds      6

_ByteIn:
       ds      1

_CommActive:
       ds      1

_CurrentR_State:
       ds      1

_CurrentX_State:
       ds      1

_LostCommCounter:
       ds      1

_MessageCounter:
       ds      1

_NextR_State:
       ds      1

_NextX_State:
       ds      1

_PORTC_Copy:
       ds      1

_Paired:
       ds      1

_R_API:
       ds      1

_R_AddrLSB:
       ds      1

_R_AddrMSB:
       ds      1

_R_CMD:
       ds      1

_R_FID:
       ds      1

_R_LengthLSB:
       ds      1

_R_Options:
       ds      1

_R_RF1:
       ds      1

_R_STATUS:
       ds      1

_R_SigStr:
       ds      1

_R_Transition:
       ds      1

_SEND:
       ds      1

_SendKick:
       ds      1

_SendWhimsy:
       ds      1

_TRANS:
       ds      1

_WHIM:
       ds      1

_X_LengthLSB:
       ds      1

_X_LengthMSB:
       ds      1

_X_Options:
       ds      1

_i:
       ds      1

psect	dataBANK0,class=BANK0,space=1
global __pdataBANK0
__pdataBANK0:
	file	"U:\_218c Teams\BringItOn\218C Project - World Cup\COACH CODE WE ARE USING\MasterCoach\MasterCoach\CoachMasterCode.c"
	line	132
_AUX:
       ds      1

psect	dataBANK0
	file	"U:\_218c Teams\BringItOn\218C Project - World Cup\COACH CODE WE ARE USING\MasterCoach\MasterCoach\CoachMasterCode.c"
	line	122
_CurrentType:
       ds      1

psect	dataBANK0
	file	"U:\_218c Teams\BringItOn\218C Project - World Cup\COACH CODE WE ARE USING\MasterCoach\MasterCoach\CoachMasterCode.c"
	line	131
_DIR:
       ds      1

psect	dataBANK0
	file	"U:\_218c Teams\BringItOn\218C Project - World Cup\COACH CODE WE ARE USING\MasterCoach\MasterCoach\CoachMasterCode.c"
	line	86
_NextByteOut:
       ds      1

psect	dataBANK0
	file	"U:\_218c Teams\BringItOn\218C Project - World Cup\COACH CODE WE ARE USING\MasterCoach\MasterCoach\CoachMasterCode.c"
	line	128
_PAIRDATA:
       ds      1

psect	dataBANK0
	file	"U:\_218c Teams\BringItOn\218C Project - World Cup\COACH CODE WE ARE USING\MasterCoach\MasterCoach\CoachMasterCode.c"
	line	129
_RESPDATA:
       ds      1

psect	dataBANK0
	file	"U:\_218c Teams\BringItOn\218C Project - World Cup\COACH CODE WE ARE USING\MasterCoach\MasterCoach\CoachMasterCode.c"
	line	127
_SDATA:
       ds      1

psect	dataBANK0
	file	"U:\_218c Teams\BringItOn\218C Project - World Cup\COACH CODE WE ARE USING\MasterCoach\MasterCoach\CoachMasterCode.c"
	line	130
_SPD:
       ds      1

psect	dataBANK0
	file	"U:\_218c Teams\BringItOn\218C Project - World Cup\COACH CODE WE ARE USING\MasterCoach\MasterCoach\CoachMasterCode.c"
	line	126
_TAGINFO:
       ds      1

psect	dataBANK0
	file	"U:\_218c Teams\BringItOn\218C Project - World Cup\COACH CODE WE ARE USING\MasterCoach\MasterCoach\CoachMasterCode.c"
	line	93
_X_API:
       ds      1

psect	dataBANK0
	file	"U:\_218c Teams\BringItOn\218C Project - World Cup\COACH CODE WE ARE USING\MasterCoach\MasterCoach\CoachMasterCode.c"
	line	96
_X_AddrLSB:
       ds      1

psect	dataBANK0
	file	"U:\_218c Teams\BringItOn\218C Project - World Cup\COACH CODE WE ARE USING\MasterCoach\MasterCoach\CoachMasterCode.c"
	line	95
_X_AddrMSB:
       ds      1

psect	dataBANK0
	file	"U:\_218c Teams\BringItOn\218C Project - World Cup\COACH CODE WE ARE USING\MasterCoach\MasterCoach\CoachMasterCode.c"
	line	98
_X_CMD:
       ds      1

psect	dataBANK0
	file	"U:\_218c Teams\BringItOn\218C Project - World Cup\COACH CODE WE ARE USING\MasterCoach\MasterCoach\CoachMasterCode.c"
	line	94
_X_FID:
       ds      1

psect	dataBANK0
	file	"U:\_218c Teams\BringItOn\218C Project - World Cup\COACH CODE WE ARE USING\MasterCoach\MasterCoach\CoachMasterCode.c"
	line	99
_X_RF1:
       ds      1

psect	dataBANK0
	file	"U:\_218c Teams\BringItOn\218C Project - World Cup\COACH CODE WE ARE USING\MasterCoach\MasterCoach\CoachMasterCode.c"
	line	100
_X_RF2:
       ds      1

psect	dataBANK0
	file	"U:\_218c Teams\BringItOn\218C Project - World Cup\COACH CODE WE ARE USING\MasterCoach\MasterCoach\CoachMasterCode.c"
	line	101
_X_RF3:
       ds      1

psect	dataBANK0
	file	"U:\_218c Teams\BringItOn\218C Project - World Cup\COACH CODE WE ARE USING\MasterCoach\MasterCoach\CoachMasterCode.c"
	line	102
_X_RF4:
       ds      1

psect	dataBANK0
	file	"U:\_218c Teams\BringItOn\218C Project - World Cup\COACH CODE WE ARE USING\MasterCoach\MasterCoach\CoachMasterCode.c"
	line	103
_X_RF5:
       ds      1

psect	dataBANK0
	file	"U:\_218c Teams\BringItOn\218C Project - World Cup\COACH CODE WE ARE USING\MasterCoach\MasterCoach\CoachMasterCode.c"
	line	80
_X_Transition:
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
	movlw	low((__pbssBANK0)+034h)
	fcall	clear_ram
global btemp
psect inittext,class=CODE,delta=2
global init_fetch,btemp
;	Called with low address in FSR and high address in W
init_fetch:
	movf btemp,w
	movwf pclath
	movf btemp+1,w
	movwf pc
global init_ram
;Called with:
;	high address of idata address in btemp 
;	low address of idata address in btemp+1 
;	low address of data in FSR
;	high address + 1 of data in btemp-1
init_ram:
	fcall init_fetch
	movwf indf,f
	incf fsr,f
	movf fsr,w
	xorwf btemp-1,w
	btfsc status,2
	retlw 0
	incf btemp+1,f
	btfsc status,2
	incf btemp,f
	goto init_ram
; Initialize objects allocated to BANK0
psect cinit,class=CODE,delta=2
global init_ram, __pidataBANK0
	movlw low(__pdataBANK0+20)
	movwf btemp-1,f
	movlw high(__pidataBANK0)
	movwf btemp,f
	movlw low(__pidataBANK0)
	movwf btemp+1,f
	movlw low(__pdataBANK0)
	movwf fsr,f
	fcall init_ram
; Initialize objects allocated to COMMON
	global __pidataCOMMON
psect cinit,class=CODE,delta=2
	fcall	__pidataCOMMON+0		;fetch initializer
	movwf	__pdataCOMMON+0&07fh		
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
	global	?_XBee_State
?_XBee_State:	; 0 bytes @ 0x0
	global	?_Process_Status
?_Process_Status:	; 0 bytes @ 0x0
	global	?_Process_SPI
?_Process_SPI:	; 0 bytes @ 0x0
	global	??_Process_SPI
??_Process_SPI:	; 0 bytes @ 0x0
	global	?_main
?_main:	; 0 bytes @ 0x0
	global	?_ISR
?_ISR:	; 0 bytes @ 0x0
	global	?i1_XBee_State
?i1_XBee_State:	; 0 bytes @ 0x0
	global	??i1_XBee_State
??i1_XBee_State:	; 0 bytes @ 0x0
	global	?_Encode_Message
?_Encode_Message:	; 1 bytes @ 0x0
	global	?_CalculateChecksum
?_CalculateChecksum:	; 1 bytes @ 0x0
	ds	1
	global	i1XBee_State@x
i1XBee_State@x:	; 1 bytes @ 0x1
	ds	1
	global	??_ISR
??_ISR:	; 0 bytes @ 0x2
	ds	5
psect	cstackBANK0,class=BANK0,space=1
global __pcstackBANK0
__pcstackBANK0:
	global	??_InitTimers
??_InitTimers:	; 0 bytes @ 0x0
	global	??_InitPorts
??_InitPorts:	; 0 bytes @ 0x0
	global	??_InitComm
??_InitComm:	; 0 bytes @ 0x0
	global	??_InitInterrupts
??_InitInterrupts:	; 0 bytes @ 0x0
	global	??_Encode_Message
??_Encode_Message:	; 0 bytes @ 0x0
	global	??_CalculateChecksum
??_CalculateChecksum:	; 0 bytes @ 0x0
	global	??_XBee_State
??_XBee_State:	; 0 bytes @ 0x0
	global	??_Process_Status
??_Process_Status:	; 0 bytes @ 0x0
	ds	1
	global	Process_Status@status
Process_Status@status:	; 1 bytes @ 0x1
	global	XBee_State@x
XBee_State@x:	; 1 bytes @ 0x1
	global	Encode_Message@Type
Encode_Message@Type:	; 1 bytes @ 0x1
	ds	1
	global	Encode_Message@Length
Encode_Message@Length:	; 1 bytes @ 0x2
	ds	3
	global	CalculateChecksum@checksum
CalculateChecksum@checksum:	; 1 bytes @ 0x5
	ds	1
	global	??_main
??_main:	; 0 bytes @ 0x6
	ds	1
;;Data sizes: Strings 0, constant 0, data 21, bss 58, persistent 0 stack 0
;;Auto spaces:   Size  Autos    Used
;; COMMON          14      7      14
;; BANK0           80      7      79
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
;;   _ISR->i1_XBee_State
;;
;; Critical Paths under _main in BANK0
;;
;;   _main->_CalculateChecksum
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
;;Main: autosize = 0, tempsize = 1, incstack = 0, save=0
;;

;;
;;Call Graph Tables:
;;
;; ---------------------------------------------------------------------------------
;; (Depth) Function   	        Calls       Base Space   Used Autos Params    Refs
;; ---------------------------------------------------------------------------------
;; (0) _main                                                 1     1      0     126
;;                                              6 BANK0      1     1      0
;;                         _InitTimers
;;                          _InitPorts
;;                           _InitComm
;;                     _InitInterrupts
;;                     _Encode_Message
;;                  _CalculateChecksum
;;                         _XBee_State
;;                     _Process_Status
;; ---------------------------------------------------------------------------------
;; (1) _Process_Status                                       2     2      0      22
;;                                              0 BANK0      2     2      0
;; ---------------------------------------------------------------------------------
;; (1) _XBee_State                                           2     2      0      22
;;                                              0 BANK0      2     2      0
;; ---------------------------------------------------------------------------------
;; (1) _CalculateChecksum                                    6     6      0      29
;;                                              0 BANK0      6     6      0
;; ---------------------------------------------------------------------------------
;; (1) _Encode_Message                                       3     3      0      53
;;                                              0 BANK0      3     3      0
;; ---------------------------------------------------------------------------------
;; (1) _InitInterrupts                                       0     0      0       0
;; ---------------------------------------------------------------------------------
;; (1) _InitComm                                             1     1      0       0
;;                                              0 BANK0      1     1      0
;; ---------------------------------------------------------------------------------
;; (1) _InitPorts                                            0     0      0       0
;; ---------------------------------------------------------------------------------
;; (1) _InitTimers                                           0     0      0       0
;; ---------------------------------------------------------------------------------
;; Estimated maximum stack depth 1
;; ---------------------------------------------------------------------------------
;; (Depth) Function   	        Calls       Base Space   Used Autos Params    Refs
;; ---------------------------------------------------------------------------------
;; (2) _ISR                                                  5     5      0      73
;;                                              2 COMMON     5     5      0
;;                        _Process_SPI
;;                       i1_XBee_State
;; ---------------------------------------------------------------------------------
;; (3) i1_XBee_State                                         2     2      0      73
;;                                              0 COMMON     2     2      0
;; ---------------------------------------------------------------------------------
;; (3) _Process_SPI                                          1     1      0       0
;;                                              0 COMMON     1     1      0
;; ---------------------------------------------------------------------------------
;; Estimated maximum stack depth 3
;; ---------------------------------------------------------------------------------

;; Call Graph Graphs:

;; _main (ROOT)
;;   _InitTimers
;;   _InitPorts
;;   _InitComm
;;   _InitInterrupts
;;   _Encode_Message
;;   _CalculateChecksum
;;   _XBee_State
;;   _Process_Status
;;
;; _ISR (ROOT)
;;   _Process_SPI
;;   i1_XBee_State
;;

;; Address spaces:

;;Name               Size   Autos  Total    Cost      Usage
;;SFR3                 0      0       0       4        0.0%
;;BITSFR3              0      0       0       4        0.0%
;;BANK2               50      0       0       7        0.0%
;;BITBANK2            50      0       0       6        0.0%
;;SFR2                 0      0       0       5        0.0%
;;BITSFR2              0      0       0       5        0.0%
;;SFR1                 0      0       0       2        0.0%
;;BITSFR1              0      0       0       2        0.0%
;;BANK1               50      0       0       5        0.0%
;;BITBANK1            50      0       0       4        0.0%
;;CODE                 0      0       0       0        0.0%
;;DATA                 0      0      62      10        0.0%
;;ABS                  0      0      5D       8        0.0%
;;NULL                 0      0       0       0        0.0%
;;STACK                0      0       5       2        0.0%
;;BANK0               50      7      4F       3       98.8%
;;BITBANK0            50      0       0       9        0.0%
;;SFR0                 0      0       0       1        0.0%
;;BITSFR0              0      0       0       1        0.0%
;;COMMON               E      7       E       1      100.0%
;;BITCOMMON            E      0       0       0        0.0%
;;EEDATA             100      0       0       0        0.0%

	global	_main
psect	maintext,global,class=CODE,delta=2
global __pmaintext
__pmaintext:

;; *************** function _main *****************
;; Defined at:
;;		line 167 in file "U:\_218c Teams\BringItOn\218C Project - World Cup\COACH CODE WE ARE USING\MasterCoach\MasterCoach\CoachMasterCode.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg, fsr0l, fsr0h, status,2, status,0, pclath, cstack
;; Tracked objects:
;;		On entry : 17F/0
;;		On exit  : 0/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2
;;      Params:         0       0       0       0
;;      Locals:         0       0       0       0
;;      Temps:          0       1       0       0
;;      Totals:         0       1       0       0
;;Total ram usage:        1 bytes
;; Hardware stack levels required when called:    3
;; This function calls:
;;		_InitTimers
;;		_InitPorts
;;		_InitComm
;;		_InitInterrupts
;;		_Encode_Message
;;		_CalculateChecksum
;;		_XBee_State
;;		_Process_Status
;; This function is called by:
;;		Startup code after reset
;; This function uses a non-reentrant model
;;
psect	maintext
	file	"U:\_218c Teams\BringItOn\218C Project - World Cup\COACH CODE WE ARE USING\MasterCoach\MasterCoach\CoachMasterCode.c"
	line	167
	global	__size_of_main
	__size_of_main	equ	__end_of_main-_main
	
_main:	
	opt	stack 5
; Regs used in _main: [wreg-fsr0h+status,2+status,0+pclath+cstack]
	line	169
	
l4474:	
;CoachMasterCode.c: 169: InitTimers();
	fcall	_InitTimers
	line	170
;CoachMasterCode.c: 170: InitPorts();
	fcall	_InitPorts
	line	171
;CoachMasterCode.c: 171: InitComm();
	fcall	_InitComm
	line	172
;CoachMasterCode.c: 172: InitInterrupts();
	fcall	_InitInterrupts
	line	173
	
l4476:	
;CoachMasterCode.c: 173: SSPBUF = BytesOut[i];
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	movf	(_i),w
	addlw	_BytesOut&0ffh
	movwf	fsr0
	bcf	status, 7	;select IRP bank0
	movf	indf,w
	movwf	(19)
	goto	l4478
	line	175
;CoachMasterCode.c: 175: while(1)
	
l1023:	
	line	182
	
l4478:	
;CoachMasterCode.c: 176: {
;CoachMasterCode.c: 182: if(CommActive)
	movf	(_CommActive),w
	skipz
	goto	u3030
	goto	l4478
u3030:
	line	185
	
l4480:	
;CoachMasterCode.c: 183: {
;CoachMasterCode.c: 185: if( X_Transition!=0 )
	movf	(_X_Transition),w
	skipz
	goto	u3040
	goto	l4580
u3040:
	line	187
	
l4482:	
;CoachMasterCode.c: 186: {
;CoachMasterCode.c: 187: X_Transition = 0;
	clrf	(_X_Transition)
	line	189
;CoachMasterCode.c: 189: switch( CurrentX_State )
	goto	l4578
	line	191
;CoachMasterCode.c: 190: {
;CoachMasterCode.c: 191: case X_Idle_State :
	
l1027:	
	line	193
	
l4484:	
;CoachMasterCode.c: 192: {
;CoachMasterCode.c: 193: SEND = 1;
	clrf	(_SEND)
	bsf	status,0
	rlf	(_SEND),f
	line	194
;CoachMasterCode.c: 194: NextX_State = X_StartDelim_State;
	clrf	(_NextX_State)
	bsf	status,0
	rlf	(_NextX_State),f
	line	195
	
l4486:	
;CoachMasterCode.c: 195: NextByteOut = 0x7E;
	movlw	(07Eh)
	movwf	(??_main+0)+0
	movf	(??_main+0)+0,w
	movwf	(_NextByteOut)
	line	197
	
l4488:	
;CoachMasterCode.c: 197: MessageCounter = Encode_Message(CurrentType);
	movf	(_CurrentType),w
	fcall	_Encode_Message
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	movwf	(??_main+0)+0
	movf	(??_main+0)+0,w
	movwf	(_MessageCounter)
	line	198
	
l4490:	
;CoachMasterCode.c: 198: X_LengthLSB = MessageCounter + 5;
	movf	(_MessageCounter),w
	addlw	05h
	movwf	(??_main+0)+0
	movf	(??_main+0)+0,w
	movwf	(_X_LengthLSB)
	line	200
	
l4492:	
;CoachMasterCode.c: 200: X_CMD = TXData[0];
	movf	(_TXData),w
	movwf	(??_main+0)+0
	movf	(??_main+0)+0,w
	movwf	(_X_CMD)
	line	201
	
l4494:	
;CoachMasterCode.c: 201: X_RF1 = TXData[1];
	movf	0+(_TXData)+01h,w
	movwf	(??_main+0)+0
	movf	(??_main+0)+0,w
	movwf	(_X_RF1)
	line	202
	
l4496:	
;CoachMasterCode.c: 202: X_RF2 = TXData[2];
	movf	0+(_TXData)+02h,w
	movwf	(??_main+0)+0
	movf	(??_main+0)+0,w
	movwf	(_X_RF2)
	line	203
	
l4498:	
;CoachMasterCode.c: 203: X_RF3 = TXData[3];
	movf	0+(_TXData)+03h,w
	movwf	(??_main+0)+0
	movf	(??_main+0)+0,w
	movwf	(_X_RF3)
	line	204
	
l4500:	
;CoachMasterCode.c: 204: X_RF4 = TXData[4];
	movf	0+(_TXData)+04h,w
	movwf	(??_main+0)+0
	movf	(??_main+0)+0,w
	movwf	(_X_RF4)
	line	205
	
l4502:	
;CoachMasterCode.c: 205: X_RF5 = TXData[5];
	movf	0+(_TXData)+05h,w
	movwf	(??_main+0)+0
	movf	(??_main+0)+0,w
	movwf	(_X_RF5)
	line	208
;CoachMasterCode.c: 207: }
;CoachMasterCode.c: 208: break;
	goto	l4580
	line	210
;CoachMasterCode.c: 210: case X_StartDelim_State :
	
l1029:	
	line	213
	
l4504:	
;CoachMasterCode.c: 211: {
;CoachMasterCode.c: 213: NextX_State = X_LengthMSB_State;
	movlw	(02h)
	movwf	(??_main+0)+0
	movf	(??_main+0)+0,w
	movwf	(_NextX_State)
	line	214
;CoachMasterCode.c: 214: NextByteOut = X_LengthMSB ;
	movf	(_X_LengthMSB),w
	movwf	(??_main+0)+0
	movf	(??_main+0)+0,w
	movwf	(_NextByteOut)
	line	216
;CoachMasterCode.c: 215: }
;CoachMasterCode.c: 216: break;
	goto	l4580
	line	218
;CoachMasterCode.c: 218: case X_LengthMSB_State :
	
l1030:	
	line	220
	
l4506:	
;CoachMasterCode.c: 219: {
;CoachMasterCode.c: 220: NextX_State = X_LengthLSB_State;
	movlw	(03h)
	movwf	(??_main+0)+0
	movf	(??_main+0)+0,w
	movwf	(_NextX_State)
	line	221
;CoachMasterCode.c: 221: NextByteOut = X_LengthLSB;
	movf	(_X_LengthLSB),w
	movwf	(??_main+0)+0
	movf	(??_main+0)+0,w
	movwf	(_NextByteOut)
	line	223
;CoachMasterCode.c: 222: }
;CoachMasterCode.c: 223: break;
	goto	l4580
	line	225
;CoachMasterCode.c: 225: case X_LengthLSB_State :
	
l1031:	
	line	227
	
l4508:	
;CoachMasterCode.c: 226: {
;CoachMasterCode.c: 227: NextX_State = X_API_State;
	movlw	(04h)
	movwf	(??_main+0)+0
	movf	(??_main+0)+0,w
	movwf	(_NextX_State)
	line	228
;CoachMasterCode.c: 228: NextByteOut = X_API;
	movf	(_X_API),w
	movwf	(??_main+0)+0
	movf	(??_main+0)+0,w
	movwf	(_NextByteOut)
	line	230
;CoachMasterCode.c: 229: }
;CoachMasterCode.c: 230: break;
	goto	l4580
	line	232
;CoachMasterCode.c: 232: case X_API_State :
	
l1032:	
	line	234
	
l4510:	
;CoachMasterCode.c: 233: {
;CoachMasterCode.c: 234: NextX_State = X_FID_State;
	movlw	(05h)
	movwf	(??_main+0)+0
	movf	(??_main+0)+0,w
	movwf	(_NextX_State)
	line	235
;CoachMasterCode.c: 235: NextByteOut = X_FID;
	movf	(_X_FID),w
	movwf	(??_main+0)+0
	movf	(??_main+0)+0,w
	movwf	(_NextByteOut)
	line	237
;CoachMasterCode.c: 236: }
;CoachMasterCode.c: 237: break;
	goto	l4580
	line	239
;CoachMasterCode.c: 239: case X_FID_State :
	
l1033:	
	line	241
	
l4512:	
;CoachMasterCode.c: 240: {
;CoachMasterCode.c: 241: NextX_State = X_AddrMSB_State;
	movlw	(06h)
	movwf	(??_main+0)+0
	movf	(??_main+0)+0,w
	movwf	(_NextX_State)
	line	242
;CoachMasterCode.c: 242: NextByteOut = X_AddrMSB;
	movf	(_X_AddrMSB),w
	movwf	(??_main+0)+0
	movf	(??_main+0)+0,w
	movwf	(_NextByteOut)
	line	244
;CoachMasterCode.c: 243: }
;CoachMasterCode.c: 244: break;
	goto	l4580
	line	246
;CoachMasterCode.c: 246: case X_AddrMSB_State :
	
l1034:	
	line	248
	
l4514:	
;CoachMasterCode.c: 247: {
;CoachMasterCode.c: 248: NextX_State = X_AddrLSB_State;
	movlw	(07h)
	movwf	(??_main+0)+0
	movf	(??_main+0)+0,w
	movwf	(_NextX_State)
	line	249
;CoachMasterCode.c: 249: NextByteOut = X_AddrLSB;
	movf	(_X_AddrLSB),w
	movwf	(??_main+0)+0
	movf	(??_main+0)+0,w
	movwf	(_NextByteOut)
	line	251
;CoachMasterCode.c: 250: }
;CoachMasterCode.c: 251: break;
	goto	l4580
	line	253
;CoachMasterCode.c: 253: case X_AddrLSB_State :
	
l1035:	
	line	255
	
l4516:	
;CoachMasterCode.c: 254: {
;CoachMasterCode.c: 255: NextX_State = X_Options_State;
	movlw	(08h)
	movwf	(??_main+0)+0
	movf	(??_main+0)+0,w
	movwf	(_NextX_State)
	line	256
;CoachMasterCode.c: 256: NextByteOut = X_Options;
	movf	(_X_Options),w
	movwf	(??_main+0)+0
	movf	(??_main+0)+0,w
	movwf	(_NextByteOut)
	line	258
;CoachMasterCode.c: 257: }
;CoachMasterCode.c: 258: break;
	goto	l4580
	line	260
;CoachMasterCode.c: 260: case X_Options_State :
	
l1036:	
	line	262
	
l4518:	
;CoachMasterCode.c: 261: {
;CoachMasterCode.c: 262: NextX_State = X_CMD_State;
	movlw	(09h)
	movwf	(??_main+0)+0
	movf	(??_main+0)+0,w
	movwf	(_NextX_State)
	line	263
;CoachMasterCode.c: 263: NextByteOut = X_CMD;
	movf	(_X_CMD),w
	movwf	(??_main+0)+0
	movf	(??_main+0)+0,w
	movwf	(_NextByteOut)
	line	265
;CoachMasterCode.c: 264: }
;CoachMasterCode.c: 265: break;
	goto	l4580
	line	267
;CoachMasterCode.c: 267: case X_CMD_State :
	
l1037:	
	line	269
	
l4520:	
;CoachMasterCode.c: 268: {
;CoachMasterCode.c: 269: MessageCounter--;
	movlw	low(01h)
	subwf	(_MessageCounter),f
	line	270
	
l4522:	
;CoachMasterCode.c: 270: if(MessageCounter)
	movf	(_MessageCounter),w
	skipz
	goto	u3050
	goto	l4526
u3050:
	line	272
	
l4524:	
;CoachMasterCode.c: 271: {
;CoachMasterCode.c: 272: NextX_State = X_RF1_State;
	movlw	(0Ah)
	movwf	(??_main+0)+0
	movf	(??_main+0)+0,w
	movwf	(_NextX_State)
	line	273
;CoachMasterCode.c: 273: NextByteOut = X_RF1;
	movf	(_X_RF1),w
	movwf	(??_main+0)+0
	movf	(??_main+0)+0,w
	movwf	(_NextByteOut)
	line	274
;CoachMasterCode.c: 274: }
	goto	l4580
	line	275
	
l1038:	
	line	277
	
l4526:	
;CoachMasterCode.c: 275: else
;CoachMasterCode.c: 276: {
;CoachMasterCode.c: 277: NextX_State = X_Checksum_State;
	movlw	(0Fh)
	movwf	(??_main+0)+0
	movf	(??_main+0)+0,w
	movwf	(_NextX_State)
	line	278
	
l4528:	
;CoachMasterCode.c: 278: NextByteOut = CalculateChecksum();
	fcall	_CalculateChecksum
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	movwf	(??_main+0)+0
	movf	(??_main+0)+0,w
	movwf	(_NextByteOut)
	goto	l4580
	line	279
	
l1039:	
	line	281
;CoachMasterCode.c: 279: }
;CoachMasterCode.c: 280: }
;CoachMasterCode.c: 281: break;
	goto	l4580
	line	283
;CoachMasterCode.c: 283: case X_RF1_State :
	
l1040:	
	line	285
	
l4530:	
;CoachMasterCode.c: 284: {
;CoachMasterCode.c: 285: MessageCounter--;
	movlw	low(01h)
	subwf	(_MessageCounter),f
	line	286
	
l4532:	
;CoachMasterCode.c: 286: if(MessageCounter)
	movf	(_MessageCounter),w
	skipz
	goto	u3060
	goto	l4536
u3060:
	line	288
	
l4534:	
;CoachMasterCode.c: 287: {
;CoachMasterCode.c: 288: NextX_State = X_RF2_State;
	movlw	(0Bh)
	movwf	(??_main+0)+0
	movf	(??_main+0)+0,w
	movwf	(_NextX_State)
	line	289
;CoachMasterCode.c: 289: NextByteOut = X_RF2;
	movf	(_X_RF2),w
	movwf	(??_main+0)+0
	movf	(??_main+0)+0,w
	movwf	(_NextByteOut)
	line	290
;CoachMasterCode.c: 290: }
	goto	l4580
	line	291
	
l1041:	
	line	293
	
l4536:	
;CoachMasterCode.c: 291: else
;CoachMasterCode.c: 292: {
;CoachMasterCode.c: 293: NextX_State = X_Checksum_State;
	movlw	(0Fh)
	movwf	(??_main+0)+0
	movf	(??_main+0)+0,w
	movwf	(_NextX_State)
	line	294
	
l4538:	
;CoachMasterCode.c: 294: NextByteOut = CalculateChecksum();
	fcall	_CalculateChecksum
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	movwf	(??_main+0)+0
	movf	(??_main+0)+0,w
	movwf	(_NextByteOut)
	goto	l4580
	line	295
	
l1042:	
	line	297
;CoachMasterCode.c: 295: }
;CoachMasterCode.c: 296: }
;CoachMasterCode.c: 297: break;
	goto	l4580
	line	299
;CoachMasterCode.c: 299: case X_RF2_State :
	
l1043:	
	line	301
	
l4540:	
;CoachMasterCode.c: 300: {
;CoachMasterCode.c: 301: MessageCounter--;
	movlw	low(01h)
	subwf	(_MessageCounter),f
	line	302
	
l4542:	
;CoachMasterCode.c: 302: if(MessageCounter)
	movf	(_MessageCounter),w
	skipz
	goto	u3070
	goto	l4546
u3070:
	line	304
	
l4544:	
;CoachMasterCode.c: 303: {
;CoachMasterCode.c: 304: NextX_State = X_RF3_State;
	movlw	(0Ch)
	movwf	(??_main+0)+0
	movf	(??_main+0)+0,w
	movwf	(_NextX_State)
	line	305
;CoachMasterCode.c: 305: NextByteOut = X_RF3;
	movf	(_X_RF3),w
	movwf	(??_main+0)+0
	movf	(??_main+0)+0,w
	movwf	(_NextByteOut)
	line	306
;CoachMasterCode.c: 306: }
	goto	l4580
	line	307
	
l1044:	
	line	309
	
l4546:	
;CoachMasterCode.c: 307: else
;CoachMasterCode.c: 308: {
;CoachMasterCode.c: 309: NextX_State = X_Checksum_State;
	movlw	(0Fh)
	movwf	(??_main+0)+0
	movf	(??_main+0)+0,w
	movwf	(_NextX_State)
	line	310
	
l4548:	
;CoachMasterCode.c: 310: NextByteOut = CalculateChecksum();
	fcall	_CalculateChecksum
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	movwf	(??_main+0)+0
	movf	(??_main+0)+0,w
	movwf	(_NextByteOut)
	goto	l4580
	line	311
	
l1045:	
	line	313
;CoachMasterCode.c: 311: }
;CoachMasterCode.c: 312: }
;CoachMasterCode.c: 313: break;
	goto	l4580
	line	315
;CoachMasterCode.c: 315: case X_RF3_State :
	
l1046:	
	line	317
	
l4550:	
;CoachMasterCode.c: 316: {
;CoachMasterCode.c: 317: MessageCounter--;
	movlw	low(01h)
	subwf	(_MessageCounter),f
	line	318
	
l4552:	
;CoachMasterCode.c: 318: if(MessageCounter)
	movf	(_MessageCounter),w
	skipz
	goto	u3080
	goto	l4556
u3080:
	line	320
	
l4554:	
;CoachMasterCode.c: 319: {
;CoachMasterCode.c: 320: NextX_State = X_RF4_State;
	movlw	(0Dh)
	movwf	(??_main+0)+0
	movf	(??_main+0)+0,w
	movwf	(_NextX_State)
	line	321
;CoachMasterCode.c: 321: NextByteOut = X_RF4;
	movf	(_X_RF4),w
	movwf	(??_main+0)+0
	movf	(??_main+0)+0,w
	movwf	(_NextByteOut)
	line	322
;CoachMasterCode.c: 322: }
	goto	l4580
	line	323
	
l1047:	
	line	325
	
l4556:	
;CoachMasterCode.c: 323: else
;CoachMasterCode.c: 324: {
;CoachMasterCode.c: 325: NextX_State = X_Checksum_State;
	movlw	(0Fh)
	movwf	(??_main+0)+0
	movf	(??_main+0)+0,w
	movwf	(_NextX_State)
	line	326
	
l4558:	
;CoachMasterCode.c: 326: NextByteOut = CalculateChecksum();
	fcall	_CalculateChecksum
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	movwf	(??_main+0)+0
	movf	(??_main+0)+0,w
	movwf	(_NextByteOut)
	goto	l4580
	line	327
	
l1048:	
	line	329
;CoachMasterCode.c: 327: }
;CoachMasterCode.c: 328: }
;CoachMasterCode.c: 329: break;
	goto	l4580
	line	331
;CoachMasterCode.c: 331: case X_RF4_State :
	
l1049:	
	line	333
	
l4560:	
;CoachMasterCode.c: 332: {
;CoachMasterCode.c: 333: MessageCounter--;
	movlw	low(01h)
	subwf	(_MessageCounter),f
	line	334
	
l4562:	
;CoachMasterCode.c: 334: if(MessageCounter)
	movf	(_MessageCounter),w
	skipz
	goto	u3090
	goto	l4566
u3090:
	line	336
	
l4564:	
;CoachMasterCode.c: 335: {
;CoachMasterCode.c: 336: NextX_State = X_RF5_State;
	movlw	(0Eh)
	movwf	(??_main+0)+0
	movf	(??_main+0)+0,w
	movwf	(_NextX_State)
	line	337
;CoachMasterCode.c: 337: NextByteOut = X_RF5;
	movf	(_X_RF5),w
	movwf	(??_main+0)+0
	movf	(??_main+0)+0,w
	movwf	(_NextByteOut)
	line	338
;CoachMasterCode.c: 338: }
	goto	l4580
	line	339
	
l1050:	
	line	341
	
l4566:	
;CoachMasterCode.c: 339: else
;CoachMasterCode.c: 340: {
;CoachMasterCode.c: 341: NextX_State = X_Checksum_State;
	movlw	(0Fh)
	movwf	(??_main+0)+0
	movf	(??_main+0)+0,w
	movwf	(_NextX_State)
	line	342
	
l4568:	
;CoachMasterCode.c: 342: NextByteOut = CalculateChecksum();
	fcall	_CalculateChecksum
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	movwf	(??_main+0)+0
	movf	(??_main+0)+0,w
	movwf	(_NextByteOut)
	goto	l4580
	line	343
	
l1051:	
	line	345
;CoachMasterCode.c: 343: }
;CoachMasterCode.c: 344: }
;CoachMasterCode.c: 345: break;
	goto	l4580
	line	347
;CoachMasterCode.c: 347: case X_RF5_State :
	
l1052:	
	line	349
	
l4570:	
;CoachMasterCode.c: 348: {
;CoachMasterCode.c: 349: NextX_State = X_Checksum_State;
	movlw	(0Fh)
	movwf	(??_main+0)+0
	movf	(??_main+0)+0,w
	movwf	(_NextX_State)
	line	350
	
l4572:	
;CoachMasterCode.c: 350: NextByteOut = CalculateChecksum();
	fcall	_CalculateChecksum
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	movwf	(??_main+0)+0
	movf	(??_main+0)+0,w
	movwf	(_NextByteOut)
	line	352
;CoachMasterCode.c: 351: }
;CoachMasterCode.c: 352: break;
	goto	l4580
	line	354
;CoachMasterCode.c: 354: case X_Checksum_State :
	
l1053:	
	line	356
;CoachMasterCode.c: 355: {
;CoachMasterCode.c: 356: SEND = 0;
	clrf	(_SEND)
	line	357
;CoachMasterCode.c: 357: NextX_State = X_Idle_State;
	clrf	(_NextX_State)
	line	358
	
l4574:	
;CoachMasterCode.c: 358: NextByteOut = 0x7E;
	movlw	(07Eh)
	movwf	(??_main+0)+0
	movf	(??_main+0)+0,w
	movwf	(_NextByteOut)
	line	360
;CoachMasterCode.c: 359: }
;CoachMasterCode.c: 360: break;
	goto	l4580
	line	361
	
l4576:	
;CoachMasterCode.c: 361: }
	goto	l4580
	line	189
	
l1026:	
	
l4578:	
	movf	(_CurrentX_State),w
	; Switch size 1, requested type "space"
; Number of cases is 16, Range of values is 0 to 15
; switch strategies available:
; Name         Instructions Cycles
; direct_byte           39     7 (fixed)
; simple_byte           49    25 (average)
; jumptable            260     6 (fixed)
; rangetable            20     6 (fixed)
; spacedrange           38     9 (fixed)
; locatedrange          16     3 (fixed)
;	Chosen strategy is direct_byte

	movwf fsr
	movlw	16
	subwf	fsr,w
skipnc
goto l4580
movlw high(S4722)
movwf pclath
	clrc
	rlf fsr,w
	addlw low(S4722)
	movwf pc
psect	swtext1,local,class=CONST,delta=2
global __pswtext1
__pswtext1:
S4722:
	ljmp	l4484
	ljmp	l4504
	ljmp	l4506
	ljmp	l4508
	ljmp	l4510
	ljmp	l4512
	ljmp	l4514
	ljmp	l4516
	ljmp	l4518
	ljmp	l4520
	ljmp	l4530
	ljmp	l4540
	ljmp	l4550
	ljmp	l4560
	ljmp	l4570
	ljmp	l1053
psect	maintext

	line	361
	
l1028:	
	goto	l4580
	line	362
	
l1025:	
	line	364
	
l4580:	
;CoachMasterCode.c: 362: }
;CoachMasterCode.c: 364: if( R_Transition!=0 )
	movf	(_R_Transition),w
	skipz
	goto	u3100
	goto	l4652
u3100:
	line	366
	
l4582:	
;CoachMasterCode.c: 365: {
;CoachMasterCode.c: 366: R_Transition = 0;
	clrf	(_R_Transition)
	line	368
;CoachMasterCode.c: 368: switch( CurrentR_State )
	goto	l4650
	line	370
;CoachMasterCode.c: 369: {
;CoachMasterCode.c: 370: case R_Idle_State :
	
l1056:	
	line	372
	
l4584:	
;CoachMasterCode.c: 371: {
;CoachMasterCode.c: 372: if (ByteIn == 0x7E)
	movf	(_ByteIn),w
	xorlw	07Eh
	skipz
	goto	u3111
	goto	u3110
u3111:
	goto	l4652
u3110:
	line	373
	
l4586:	
;CoachMasterCode.c: 373: { NextR_State = R_LengthMSB_State; }
	clrf	(_NextR_State)
	bsf	status,0
	rlf	(_NextR_State),f
	goto	l4652
	
l1057:	
	line	375
;CoachMasterCode.c: 374: }
;CoachMasterCode.c: 375: break;
	goto	l4652
	line	377
;CoachMasterCode.c: 377: case R_LengthMSB_State :
	
l1059:	
	line	379
	
l4588:	
;CoachMasterCode.c: 378: {
;CoachMasterCode.c: 379: if ( ByteIn == 0x00 )
	movf	(_ByteIn),f
	skipz
	goto	u3121
	goto	u3120
u3121:
	goto	l4652
u3120:
	line	380
	
l4590:	
;CoachMasterCode.c: 380: { NextR_State = R_LengthLSB_State; }
	movlw	(02h)
	movwf	(??_main+0)+0
	movf	(??_main+0)+0,w
	movwf	(_NextR_State)
	goto	l4652
	
l1060:	
	line	382
;CoachMasterCode.c: 381: }
;CoachMasterCode.c: 382: break;
	goto	l4652
	line	384
;CoachMasterCode.c: 384: case R_LengthLSB_State :
	
l1061:	
	line	386
	
l4592:	
;CoachMasterCode.c: 385: {
;CoachMasterCode.c: 386: NextR_State = R_API_State;
	movlw	(03h)
	movwf	(??_main+0)+0
	movf	(??_main+0)+0,w
	movwf	(_NextR_State)
	line	387
;CoachMasterCode.c: 387: R_LengthLSB = ByteIn;
	movf	(_ByteIn),w
	movwf	(??_main+0)+0
	movf	(??_main+0)+0,w
	movwf	(_R_LengthLSB)
	line	389
;CoachMasterCode.c: 388: }
;CoachMasterCode.c: 389: break;
	goto	l4652
	line	391
;CoachMasterCode.c: 391: case R_API_State :
	
l1062:	
	line	394
	
l4594:	
;CoachMasterCode.c: 392: {
;CoachMasterCode.c: 394: R_API = ByteIn;
	movf	(_ByteIn),w
	movwf	(??_main+0)+0
	movf	(??_main+0)+0,w
	movwf	(_R_API)
	line	395
;CoachMasterCode.c: 395: if (R_API == 0x89)
	movf	(_R_API),w
	xorlw	089h
	skipz
	goto	u3131
	goto	u3130
u3131:
	goto	l4598
u3130:
	line	396
	
l4596:	
;CoachMasterCode.c: 396: NextR_State = R_FID_State;
	movlw	(0Ah)
	movwf	(??_main+0)+0
	movf	(??_main+0)+0,w
	movwf	(_NextR_State)
	goto	l4652
	line	397
	
l1063:	
	
l4598:	
;CoachMasterCode.c: 397: else if (R_API == 0x81)
	movf	(_R_API),w
	xorlw	081h
	skipz
	goto	u3141
	goto	u3140
u3141:
	goto	l1065
u3140:
	line	399
	
l4600:	
;CoachMasterCode.c: 398: {
;CoachMasterCode.c: 399: NextR_State = R_AddrMSB_State;
	movlw	(04h)
	movwf	(??_main+0)+0
	movf	(??_main+0)+0,w
	movwf	(_NextR_State)
	line	400
	
l4602:	
;CoachMasterCode.c: 400: LostCommCounter = 0;
	clrf	(_LostCommCounter)
	line	401
;CoachMasterCode.c: 401: }
	goto	l4652
	line	402
	
l1065:	
	line	403
;CoachMasterCode.c: 402: else
;CoachMasterCode.c: 403: NextR_State = R_Idle_State;
	clrf	(_NextR_State)
	goto	l4652
	
l1066:	
	goto	l4652
	
l1064:	
	line	405
;CoachMasterCode.c: 404: }
;CoachMasterCode.c: 405: break;
	goto	l4652
	line	407
;CoachMasterCode.c: 407: case R_AddrMSB_State :
	
l1067:	
	line	409
	
l4604:	
;CoachMasterCode.c: 408: {
;CoachMasterCode.c: 409: NextR_State = R_AddrLSB_State;
	movlw	(05h)
	movwf	(??_main+0)+0
	movf	(??_main+0)+0,w
	movwf	(_NextR_State)
	line	410
;CoachMasterCode.c: 410: R_AddrMSB = ByteIn;
	movf	(_ByteIn),w
	movwf	(??_main+0)+0
	movf	(??_main+0)+0,w
	movwf	(_R_AddrMSB)
	line	412
;CoachMasterCode.c: 411: }
;CoachMasterCode.c: 412: break;
	goto	l4652
	line	414
;CoachMasterCode.c: 414: case R_AddrLSB_State :
	
l1068:	
	line	416
	
l4606:	
;CoachMasterCode.c: 415: {
;CoachMasterCode.c: 416: NextR_State =R_SigStr_State;
	movlw	(06h)
	movwf	(??_main+0)+0
	movf	(??_main+0)+0,w
	movwf	(_NextR_State)
	line	417
;CoachMasterCode.c: 417: R_AddrLSB = ByteIn;
	movf	(_ByteIn),w
	movwf	(??_main+0)+0
	movf	(??_main+0)+0,w
	movwf	(_R_AddrLSB)
	line	419
;CoachMasterCode.c: 418: }
;CoachMasterCode.c: 419: break;
	goto	l4652
	line	421
;CoachMasterCode.c: 421: case R_SigStr_State :
	
l1069:	
	line	423
	
l4608:	
;CoachMasterCode.c: 422: {
;CoachMasterCode.c: 423: NextR_State = R_Options_State;
	movlw	(07h)
	movwf	(??_main+0)+0
	movf	(??_main+0)+0,w
	movwf	(_NextR_State)
	line	424
;CoachMasterCode.c: 424: R_SigStr = ByteIn;
	movf	(_ByteIn),w
	movwf	(??_main+0)+0
	movf	(??_main+0)+0,w
	movwf	(_R_SigStr)
	line	426
;CoachMasterCode.c: 425: }
;CoachMasterCode.c: 426: break;
	goto	l4652
	line	428
;CoachMasterCode.c: 428: case R_Options_State :
	
l1070:	
	line	430
	
l4610:	
;CoachMasterCode.c: 429: {
;CoachMasterCode.c: 430: NextR_State = R_CMD_State;
	movlw	(08h)
	movwf	(??_main+0)+0
	movf	(??_main+0)+0,w
	movwf	(_NextR_State)
	line	431
;CoachMasterCode.c: 431: R_Options = ByteIn;
	movf	(_ByteIn),w
	movwf	(??_main+0)+0
	movf	(??_main+0)+0,w
	movwf	(_R_Options)
	line	433
;CoachMasterCode.c: 432: }
;CoachMasterCode.c: 433: break;
	goto	l4652
	line	436
;CoachMasterCode.c: 436: case R_CMD_State:
	
l1071:	
	line	438
	
l4612:	
;CoachMasterCode.c: 437: {
;CoachMasterCode.c: 438: NextR_State = R_RF1_State;
	movlw	(09h)
	movwf	(??_main+0)+0
	movf	(??_main+0)+0,w
	movwf	(_NextR_State)
	line	439
;CoachMasterCode.c: 439: R_CMD = ByteIn;
	movf	(_ByteIn),w
	movwf	(??_main+0)+0
	movf	(??_main+0)+0,w
	movwf	(_R_CMD)
	line	442
;CoachMasterCode.c: 441: }
;CoachMasterCode.c: 442: break;
	goto	l4652
	line	444
;CoachMasterCode.c: 444: case R_RF1_State :
	
l1072:	
	line	446
;CoachMasterCode.c: 445: {
;CoachMasterCode.c: 446: NextR_State = R_Idle_State;
	clrf	(_NextR_State)
	line	447
	
l4614:	
;CoachMasterCode.c: 447: R_RF1 = ByteIn;
	movf	(_ByteIn),w
	movwf	(??_main+0)+0
	movf	(??_main+0)+0,w
	movwf	(_R_RF1)
	line	448
;CoachMasterCode.c: 448: if (R_CMD == 0x05)
	movf	(_R_CMD),w
	xorlw	05h
	skipz
	goto	u3151
	goto	u3150
u3151:
	goto	l4634
u3150:
	line	451
	
l4616:	
;CoachMasterCode.c: 449: {
;CoachMasterCode.c: 451: if(R_RF1&0x00000001)
	btfss	(_R_RF1),(0)&7
	goto	u3161
	goto	u3160
u3161:
	goto	l4632
u3160:
	line	453
	
l4618:	
;CoachMasterCode.c: 452: {
;CoachMasterCode.c: 453: Paired = 1;
	clrf	(_Paired)
	bsf	status,0
	rlf	(_Paired),f
	line	455
	
l4620:	
;CoachMasterCode.c: 455: X_AddrMSB = R_AddrMSB;
	movf	(_R_AddrMSB),w
	movwf	(??_main+0)+0
	movf	(??_main+0)+0,w
	movwf	(_X_AddrMSB)
	line	456
	
l4622:	
;CoachMasterCode.c: 456: X_AddrLSB = R_AddrLSB;
	movf	(_R_AddrLSB),w
	movwf	(??_main+0)+0
	movf	(??_main+0)+0,w
	movwf	(_X_AddrLSB)
	line	457
	
l4624:	
;CoachMasterCode.c: 457: CurrentType = 6;
	movlw	(06h)
	movwf	(??_main+0)+0
	movf	(??_main+0)+0,w
	movwf	(_CurrentType)
	line	458
	
l4626:	
;CoachMasterCode.c: 458: PORTC_Copy|=0x00000004;
	bsf	(_PORTC_Copy)+(2/8),(2)&7
	line	459
	
l4628:	
;CoachMasterCode.c: 459: PORTC = PORTC_Copy;
	movf	(_PORTC_Copy),w
	movwf	(7)	;volatile
	line	460
	
l4630:	
;CoachMasterCode.c: 460: LostCommCounter = 0;
	clrf	(_LostCommCounter)
	line	462
;CoachMasterCode.c: 462: }
	goto	l4634
	line	463
	
l1074:	
	line	465
	
l4632:	
;CoachMasterCode.c: 463: else
;CoachMasterCode.c: 464: {
;CoachMasterCode.c: 465: XBee_State(0);
	movlw	(0)
	fcall	_XBee_State
	goto	l4634
	line	466
	
l1075:	
	goto	l4634
	line	468
	
l1073:	
	line	469
	
l4634:	
;CoachMasterCode.c: 466: }
;CoachMasterCode.c: 468: }
;CoachMasterCode.c: 469: if (R_CMD == 0x06)
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	movf	(_R_CMD),w
	xorlw	06h
	skipz
	goto	u3171
	goto	u3170
u3171:
	goto	l4652
u3170:
	line	471
	
l4636:	
;CoachMasterCode.c: 470: {
;CoachMasterCode.c: 471: Process_Status(R_RF1);
	movf	(_R_RF1),w
	fcall	_Process_Status
	goto	l4652
	line	472
	
l1076:	
	line	476
;CoachMasterCode.c: 472: }
;CoachMasterCode.c: 475: }
;CoachMasterCode.c: 476: break;
	goto	l4652
	line	479
;CoachMasterCode.c: 479: case R_FID_State :
	
l1077:	
	line	481
	
l4638:	
;CoachMasterCode.c: 480: {
;CoachMasterCode.c: 481: NextR_State = R_STATUS_State;
	movlw	(0Bh)
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	movwf	(??_main+0)+0
	movf	(??_main+0)+0,w
	movwf	(_NextR_State)
	line	482
;CoachMasterCode.c: 482: R_FID = ByteIn;
	movf	(_ByteIn),w
	movwf	(??_main+0)+0
	movf	(??_main+0)+0,w
	movwf	(_R_FID)
	line	484
;CoachMasterCode.c: 483: }
;CoachMasterCode.c: 484: break;
	goto	l4652
	line	486
;CoachMasterCode.c: 486: case R_STATUS_State :
	
l1078:	
	line	488
;CoachMasterCode.c: 487: {
;CoachMasterCode.c: 488: NextR_State = R_Idle_State;
	clrf	(_NextR_State)
	line	489
	
l4640:	
;CoachMasterCode.c: 489: R_STATUS = ByteIn;
	movf	(_ByteIn),w
	movwf	(??_main+0)+0
	movf	(??_main+0)+0,w
	movwf	(_R_STATUS)
	line	491
;CoachMasterCode.c: 491: if (R_STATUS)
	movf	(_R_STATUS),w
	skipz
	goto	u3180
	goto	l4652
u3180:
	line	493
	
l4642:	
;CoachMasterCode.c: 492: {
;CoachMasterCode.c: 493: X_Transition = 1;
	clrf	(_X_Transition)
	bsf	status,0
	rlf	(_X_Transition),f
	line	494
	
l4644:	
;CoachMasterCode.c: 494: CurrentX_State = X_Idle_State;
	clrf	(_CurrentX_State)
	line	495
	
l4646:	
;CoachMasterCode.c: 495: NextX_State = CurrentX_State;
	movf	(_CurrentX_State),w
	movwf	(??_main+0)+0
	movf	(??_main+0)+0,w
	movwf	(_NextX_State)
	goto	l4652
	line	496
	
l1079:	
	line	498
;CoachMasterCode.c: 496: }
;CoachMasterCode.c: 497: }
;CoachMasterCode.c: 498: break;
	goto	l4652
	line	502
	
l4648:	
;CoachMasterCode.c: 502: }
	goto	l4652
	line	368
	
l1055:	
	
l4650:	
	movf	(_CurrentR_State),w
	; Switch size 1, requested type "space"
; Number of cases is 12, Range of values is 0 to 11
; switch strategies available:
; Name         Instructions Cycles
; direct_byte           31     7 (fixed)
; simple_byte           37    19 (average)
; jumptable            260     6 (fixed)
; rangetable            16     6 (fixed)
; spacedrange           30     9 (fixed)
; locatedrange          12     3 (fixed)
;	Chosen strategy is direct_byte

	movwf fsr
	movlw	12
	subwf	fsr,w
skipnc
goto l4652
movlw high(S4724)
movwf pclath
	clrc
	rlf fsr,w
	addlw low(S4724)
	movwf pc
psect	swtext2,local,class=CONST,delta=2
global __pswtext2
__pswtext2:
S4724:
	ljmp	l4584
	ljmp	l4588
	ljmp	l4592
	ljmp	l4594
	ljmp	l4604
	ljmp	l4606
	ljmp	l4608
	ljmp	l4610
	ljmp	l4612
	ljmp	l1072
	ljmp	l4638
	ljmp	l1078
psect	maintext

	line	502
	
l1058:	
	goto	l4652
	line	503
	
l1054:	
	line	506
	
l4652:	
;CoachMasterCode.c: 503: }
;CoachMasterCode.c: 506: if (SEND && TXIF)
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	movf	(_SEND),w
	skipz
	goto	u3190
	goto	l4660
u3190:
	
l4654:	
	btfss	(100/8),(100)&7
	goto	u3201
	goto	u3200
u3201:
	goto	l4660
u3200:
	line	508
	
l4656:	
;CoachMasterCode.c: 507: {
;CoachMasterCode.c: 508: X_Transition = 1;
	clrf	(_X_Transition)
	bsf	status,0
	rlf	(_X_Transition),f
	line	509
	
l4658:	
;CoachMasterCode.c: 509: TXREG = NextByteOut;
	movf	(_NextByteOut),w
	movwf	(25)
	goto	l4660
	line	510
	
l1080:	
	line	512
	
l4660:	
;CoachMasterCode.c: 510: }
;CoachMasterCode.c: 512: CurrentX_State = NextX_State;
	movf	(_NextX_State),w
	movwf	(??_main+0)+0
	movf	(??_main+0)+0,w
	movwf	(_CurrentX_State)
	line	513
	
l4662:	
;CoachMasterCode.c: 513: CurrentR_State = NextR_State;
	movf	(_NextR_State),w
	movwf	(??_main+0)+0
	movf	(??_main+0)+0,w
	movwf	(_CurrentR_State)
	goto	l4478
	line	515
	
l1024:	
	goto	l4478
	line	516
	
l1081:	
	line	175
	goto	l4478
	
l1082:	
	line	518
	
l1083:	
	global	start
	ljmp	start
	opt stack 0
GLOBAL	__end_of_main
	__end_of_main:
;; =============== function _main ends ============

	signat	_main,88
	global	_Process_Status
psect	text427,local,class=CODE,delta=2
global __ptext427
__ptext427:

;; *************** function _Process_Status *****************
;; Defined at:
;;		line 721 in file "U:\_218c Teams\BringItOn\218C Project - World Cup\COACH CODE WE ARE USING\MasterCoach\MasterCoach\CoachMasterCode.c"
;; Parameters:    Size  Location     Type
;;  status          1    wreg     unsigned char 
;; Auto vars:     Size  Location     Type
;;  status          1    1[BANK0 ] unsigned char 
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
;;      Locals:         0       1       0       0
;;      Temps:          0       1       0       0
;;      Totals:         0       2       0       0
;;Total ram usage:        2 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    2
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_main
;; This function uses a non-reentrant model
;;
psect	text427
	file	"U:\_218c Teams\BringItOn\218C Project - World Cup\COACH CODE WE ARE USING\MasterCoach\MasterCoach\CoachMasterCode.c"
	line	721
	global	__size_of_Process_Status
	__size_of_Process_Status	equ	__end_of_Process_Status-_Process_Status
	
_Process_Status:	
	opt	stack 5
; Regs used in _Process_Status: [wreg]
;Process_Status@status stored from wreg
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	movwf	(Process_Status@status)
	line	722
	
l4086:	
;CoachMasterCode.c: 722: SDATA = status;
	movf	(Process_Status@status),w
	movwf	(??_Process_Status+0)+0
	movf	(??_Process_Status+0)+0,w
	movwf	(_SDATA)
	line	723
	
l1120:	
	return
	opt stack 0
GLOBAL	__end_of_Process_Status
	__end_of_Process_Status:
;; =============== function _Process_Status ends ============

	signat	_Process_Status,4216
	global	_XBee_State
psect	text428,local,class=CODE,delta=2
global __ptext428
__ptext428:

;; *************** function _XBee_State *****************
;; Defined at:
;;		line 735 in file "U:\_218c Teams\BringItOn\218C Project - World Cup\COACH CODE WE ARE USING\MasterCoach\MasterCoach\CoachMasterCode.c"
;; Parameters:    Size  Location     Type
;;  x               1    wreg     unsigned char 
;; Auto vars:     Size  Location     Type
;;  x               1    1[BANK0 ] unsigned char 
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
;;      Locals:         0       1       0       0
;;      Temps:          0       1       0       0
;;      Totals:         0       2       0       0
;;Total ram usage:        2 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    2
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_main
;; This function uses a non-reentrant model
;;
psect	text428
	file	"U:\_218c Teams\BringItOn\218C Project - World Cup\COACH CODE WE ARE USING\MasterCoach\MasterCoach\CoachMasterCode.c"
	line	735
	global	__size_of_XBee_State
	__size_of_XBee_State	equ	__end_of_XBee_State-_XBee_State
	
_XBee_State:	
	opt	stack 5
; Regs used in _XBee_State: [wreg+status,2+status,0]
;XBee_State@x stored from wreg
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	movwf	(XBee_State@x)
	line	736
	
l4066:	
;CoachMasterCode.c: 736: if(x)
	movf	(XBee_State@x),w
	skipz
	goto	u2680
	goto	l1126
u2680:
	line	738
	
l4068:	
;CoachMasterCode.c: 737: {
;CoachMasterCode.c: 738: CommActive = 1;
	clrf	(_CommActive)
	bsf	status,0
	rlf	(_CommActive),f
	line	739
	
l4070:	
;CoachMasterCode.c: 739: CurrentR_State = R_Idle_State;
	clrf	(_CurrentR_State)
	line	740
	
l4072:	
;CoachMasterCode.c: 740: CurrentX_State = X_Idle_State;
	clrf	(_CurrentX_State)
	line	741
	
l4074:	
;CoachMasterCode.c: 741: PORTC_Copy&=~0x00000001;
	movlw	(0FEh)
	movwf	(??_XBee_State+0)+0
	movf	(??_XBee_State+0)+0,w
	andwf	(_PORTC_Copy),f
	line	742
	
l4076:	
;CoachMasterCode.c: 742: PORTC_Copy|=0x00000002;
	bsf	(_PORTC_Copy)+(1/8),(1)&7
	line	743
	
l4078:	
;CoachMasterCode.c: 743: LostCommCounter = 0;
	clrf	(_LostCommCounter)
	line	744
;CoachMasterCode.c: 744: PORTC = PORTC_Copy;
	movf	(_PORTC_Copy),w
	movwf	(7)	;volatile
	line	745
;CoachMasterCode.c: 745: }
	goto	l1128
	line	746
	
l1126:	
	line	748
;CoachMasterCode.c: 746: else
;CoachMasterCode.c: 747: {
;CoachMasterCode.c: 748: LostCommCounter = 0;
	clrf	(_LostCommCounter)
	line	749
;CoachMasterCode.c: 749: CommActive = 0;
	clrf	(_CommActive)
	line	750
	
l4080:	
;CoachMasterCode.c: 750: PORTC_Copy&=~0x00000002;
	movlw	(0FDh)
	movwf	(??_XBee_State+0)+0
	movf	(??_XBee_State+0)+0,w
	andwf	(_PORTC_Copy),f
	line	751
;CoachMasterCode.c: 751: PORTC_Copy&=~0x00000004;
	movlw	(0FBh)
	movwf	(??_XBee_State+0)+0
	movf	(??_XBee_State+0)+0,w
	andwf	(_PORTC_Copy),f
	line	752
	
l4082:	
;CoachMasterCode.c: 752: PORTC_Copy|=0x00000001;
	bsf	(_PORTC_Copy)+(0/8),(0)&7
	line	753
	
l4084:	
;CoachMasterCode.c: 753: PORTC = PORTC_Copy;
	movf	(_PORTC_Copy),w
	movwf	(7)	;volatile
	goto	l1128
	line	755
	
l1127:	
	line	756
	
l1128:	
	return
	opt stack 0
GLOBAL	__end_of_XBee_State
	__end_of_XBee_State:
;; =============== function _XBee_State ends ============

	signat	_XBee_State,4216
	global	_CalculateChecksum
psect	text429,local,class=CODE,delta=2
global __ptext429
__ptext429:

;; *************** function _CalculateChecksum *****************
;; Defined at:
;;		line 700 in file "U:\_218c Teams\BringItOn\218C Project - World Cup\COACH CODE WE ARE USING\MasterCoach\MasterCoach\CoachMasterCode.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;  checksum        1    5[BANK0 ] char 
;; Return value:  Size  Location     Type
;;                  1    wreg      char 
;; Registers used:
;;		wreg, status,2, status,0
;; Tracked objects:
;;		On entry : 0/0
;;		On exit  : 0/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2
;;      Params:         0       0       0       0
;;      Locals:         0       1       0       0
;;      Temps:          0       5       0       0
;;      Totals:         0       6       0       0
;;Total ram usage:        6 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    2
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_main
;; This function uses a non-reentrant model
;;
psect	text429
	file	"U:\_218c Teams\BringItOn\218C Project - World Cup\COACH CODE WE ARE USING\MasterCoach\MasterCoach\CoachMasterCode.c"
	line	700
	global	__size_of_CalculateChecksum
	__size_of_CalculateChecksum	equ	__end_of_CalculateChecksum-_CalculateChecksum
	
_CalculateChecksum:	
	opt	stack 5
; Regs used in _CalculateChecksum: [wreg+status,2+status,0]
	line	701
	
l4038:	
;CoachMasterCode.c: 701: signed char checksum = 0xFF;
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	clrf	(CalculateChecksum@checksum)
	decf	(CalculateChecksum@checksum),f
	line	703
	
l4040:	
;CoachMasterCode.c: 703: checksum -= ( X_API + X_FID + X_AddrMSB + X_AddrLSB + X_Options + X_CMD );
	movf	(_X_FID),w
	addwf	(_X_API),w
	movwf	(??_CalculateChecksum+0)+0
	movf	(_X_AddrMSB),w
	addwf	0+(??_CalculateChecksum+0)+0,w
	movwf	(??_CalculateChecksum+1)+0
	movf	(_X_AddrLSB),w
	addwf	0+(??_CalculateChecksum+1)+0,w
	movwf	(??_CalculateChecksum+2)+0
	movf	(_X_Options),w
	addwf	0+(??_CalculateChecksum+2)+0,w
	movwf	(??_CalculateChecksum+3)+0
	movf	(_X_CMD),w
	addwf	0+(??_CalculateChecksum+3)+0,w
	movwf	(??_CalculateChecksum+4)+0
	movf	0+(??_CalculateChecksum+4)+0,w
	subwf	(CalculateChecksum@checksum),f
	line	705
	
l4042:	
;CoachMasterCode.c: 705: if (X_LengthLSB > 6)
	movf	(_X_LengthLSB),w
	xorlw	80h
	addlw	-((07h)^80h)
	skipc
	goto	u2631
	goto	u2630
u2631:
	goto	l4046
u2630:
	line	706
	
l4044:	
;CoachMasterCode.c: 706: { checksum -= X_RF1; }
	movf	(_X_RF1),w
	subwf	(CalculateChecksum@checksum),f
	goto	l4046
	
l1112:	
	line	707
	
l4046:	
;CoachMasterCode.c: 707: if (X_LengthLSB > 7)
	movf	(_X_LengthLSB),w
	xorlw	80h
	addlw	-((08h)^80h)
	skipc
	goto	u2641
	goto	u2640
u2641:
	goto	l4050
u2640:
	line	708
	
l4048:	
;CoachMasterCode.c: 708: { checksum -= X_RF2; }
	movf	(_X_RF2),w
	subwf	(CalculateChecksum@checksum),f
	goto	l4050
	
l1113:	
	line	709
	
l4050:	
;CoachMasterCode.c: 709: if (X_LengthLSB > 8)
	movf	(_X_LengthLSB),w
	xorlw	80h
	addlw	-((09h)^80h)
	skipc
	goto	u2651
	goto	u2650
u2651:
	goto	l4054
u2650:
	line	710
	
l4052:	
;CoachMasterCode.c: 710: { checksum -= X_RF3; }
	movf	(_X_RF3),w
	subwf	(CalculateChecksum@checksum),f
	goto	l4054
	
l1114:	
	line	711
	
l4054:	
;CoachMasterCode.c: 711: if (X_LengthLSB > 9)
	movf	(_X_LengthLSB),w
	xorlw	80h
	addlw	-((0Ah)^80h)
	skipc
	goto	u2661
	goto	u2660
u2661:
	goto	l4058
u2660:
	line	712
	
l4056:	
;CoachMasterCode.c: 712: { checksum -= X_RF4; }
	movf	(_X_RF4),w
	subwf	(CalculateChecksum@checksum),f
	goto	l4058
	
l1115:	
	line	713
	
l4058:	
;CoachMasterCode.c: 713: if (X_LengthLSB > 10)
	movf	(_X_LengthLSB),w
	xorlw	80h
	addlw	-((0Bh)^80h)
	skipc
	goto	u2671
	goto	u2670
u2671:
	goto	l4062
u2670:
	line	714
	
l4060:	
;CoachMasterCode.c: 714: { checksum -= X_RF5; }
	movf	(_X_RF5),w
	subwf	(CalculateChecksum@checksum),f
	goto	l4062
	
l1116:	
	line	716
	
l4062:	
;CoachMasterCode.c: 716: return checksum;
	movf	(CalculateChecksum@checksum),w
	goto	l1117
	
l4064:	
	line	717
	
l1117:	
	return
	opt stack 0
GLOBAL	__end_of_CalculateChecksum
	__end_of_CalculateChecksum:
;; =============== function _CalculateChecksum ends ============

	signat	_CalculateChecksum,89
	global	_Encode_Message
psect	text430,local,class=CODE,delta=2
global __ptext430
__ptext430:

;; *************** function _Encode_Message *****************
;; Defined at:
;;		line 762 in file "U:\_218c Teams\BringItOn\218C Project - World Cup\COACH CODE WE ARE USING\MasterCoach\MasterCoach\CoachMasterCode.c"
;; Parameters:    Size  Location     Type
;;  Type            1    wreg     unsigned char 
;; Auto vars:     Size  Location     Type
;;  Type            1    1[BANK0 ] unsigned char 
;;  Length          1    2[BANK0 ] unsigned char 
;; Return value:  Size  Location     Type
;;                  1    wreg      unsigned char 
;; Registers used:
;;		wreg, fsr0l, fsr0h, status,2, status,0
;; Tracked objects:
;;		On entry : 0/0
;;		On exit  : 0/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK2
;;      Params:         0       0       0       0
;;      Locals:         0       2       0       0
;;      Temps:          0       1       0       0
;;      Totals:         0       3       0       0
;;Total ram usage:        3 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    2
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_main
;; This function uses a non-reentrant model
;;
psect	text430
	file	"U:\_218c Teams\BringItOn\218C Project - World Cup\COACH CODE WE ARE USING\MasterCoach\MasterCoach\CoachMasterCode.c"
	line	762
	global	__size_of_Encode_Message
	__size_of_Encode_Message	equ	__end_of_Encode_Message-_Encode_Message
	
_Encode_Message:	
	opt	stack 5
; Regs used in _Encode_Message: [wreg-fsr0h+status,2+status,0]
;Encode_Message@Type stored from wreg
	line	772
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	movwf	(Encode_Message@Type)
	
l3940:	
;CoachMasterCode.c: 772: unsigned char Length = 0;
	clrf	(Encode_Message@Length)
	line	774
;CoachMasterCode.c: 774: switch (Type)
	goto	l4030
	line	776
;CoachMasterCode.c: 775: {
;CoachMasterCode.c: 776: case 0:
	
l1132:	
	line	779
	
l3942:	
;CoachMasterCode.c: 777: {
;CoachMasterCode.c: 779: TXData[0] = 0x04;
	movlw	(04h)
	movwf	(??_Encode_Message+0)+0
	movf	(??_Encode_Message+0)+0,w
	movwf	(_TXData)
	line	780
	
l3944:	
;CoachMasterCode.c: 780: TXData[1] = 0;
	clrf	0+(_TXData)+01h
	line	781
	
l3946:	
;CoachMasterCode.c: 781: TXData[2] = 0;
	clrf	0+(_TXData)+02h
	line	782
	
l3948:	
;CoachMasterCode.c: 782: TXData[3] = 0;
	clrf	0+(_TXData)+03h
	line	783
	
l3950:	
;CoachMasterCode.c: 783: TXData[4] = 0;
	clrf	0+(_TXData)+04h
	line	784
	
l3952:	
;CoachMasterCode.c: 784: TXData[5] = 0;
	clrf	0+(_TXData)+05h
	line	785
	
l3954:	
;CoachMasterCode.c: 785: Length = 1;
	clrf	(Encode_Message@Length)
	bsf	status,0
	rlf	(Encode_Message@Length),f
	line	789
;CoachMasterCode.c: 788: }
;CoachMasterCode.c: 789: break;
	goto	l4032
	line	791
;CoachMasterCode.c: 791: case 1:
	
l1134:	
	line	794
	
l3956:	
;CoachMasterCode.c: 792: {
;CoachMasterCode.c: 794: TXData[0] = 0x02;
	movlw	(02h)
	movwf	(??_Encode_Message+0)+0
	movf	(??_Encode_Message+0)+0,w
	movwf	(_TXData)
	line	795
;CoachMasterCode.c: 795: TXData[1] = TAGINFO;
	movf	(_TAGINFO),w
	movwf	(??_Encode_Message+0)+0
	movf	(??_Encode_Message+0)+0,w
	movwf	0+(_TXData)+01h
	line	796
	
l3958:	
;CoachMasterCode.c: 796: TXData[2] = 0;
	clrf	0+(_TXData)+02h
	line	797
	
l3960:	
;CoachMasterCode.c: 797: TXData[3] = 0;
	clrf	0+(_TXData)+03h
	line	798
	
l3962:	
;CoachMasterCode.c: 798: TXData[4] = 0;
	clrf	0+(_TXData)+04h
	line	799
	
l3964:	
;CoachMasterCode.c: 799: TXData[5] = 0;
	clrf	0+(_TXData)+05h
	line	800
;CoachMasterCode.c: 800: Length = 2;
	movlw	(02h)
	movwf	(??_Encode_Message+0)+0
	movf	(??_Encode_Message+0)+0,w
	movwf	(Encode_Message@Length)
	line	803
;CoachMasterCode.c: 802: }
;CoachMasterCode.c: 803: break;
	goto	l4032
	line	806
;CoachMasterCode.c: 806: case 2:
	
l1135:	
	line	809
	
l3966:	
;CoachMasterCode.c: 807: {
;CoachMasterCode.c: 809: TXData[0] = 0x07;
	movlw	(07h)
	movwf	(??_Encode_Message+0)+0
	movf	(??_Encode_Message+0)+0,w
	movwf	(_TXData)
	line	810
;CoachMasterCode.c: 810: TXData[1] = TAGINFO;
	movf	(_TAGINFO),w
	movwf	(??_Encode_Message+0)+0
	movf	(??_Encode_Message+0)+0,w
	movwf	0+(_TXData)+01h
	line	811
	
l3968:	
;CoachMasterCode.c: 811: TXData[2] = 0;
	clrf	0+(_TXData)+02h
	line	812
	
l3970:	
;CoachMasterCode.c: 812: TXData[3] = 0;
	clrf	0+(_TXData)+03h
	line	813
	
l3972:	
;CoachMasterCode.c: 813: TXData[4] = 0;
	clrf	0+(_TXData)+04h
	line	814
	
l3974:	
;CoachMasterCode.c: 814: TXData[5] = 0;
	clrf	0+(_TXData)+05h
	line	815
;CoachMasterCode.c: 815: Length = 2;
	movlw	(02h)
	movwf	(??_Encode_Message+0)+0
	movf	(??_Encode_Message+0)+0,w
	movwf	(Encode_Message@Length)
	line	819
;CoachMasterCode.c: 818: }
;CoachMasterCode.c: 819: break;
	goto	l4032
	line	821
;CoachMasterCode.c: 821: case 3:
	
l1136:	
	line	824
	
l3976:	
;CoachMasterCode.c: 822: {
;CoachMasterCode.c: 824: TXData[0] = 0x06;
	movlw	(06h)
	movwf	(??_Encode_Message+0)+0
	movf	(??_Encode_Message+0)+0,w
	movwf	(_TXData)
	line	825
;CoachMasterCode.c: 825: TXData[1] = SDATA;
	movf	(_SDATA),w
	movwf	(??_Encode_Message+0)+0
	movf	(??_Encode_Message+0)+0,w
	movwf	0+(_TXData)+01h
	line	826
	
l3978:	
;CoachMasterCode.c: 826: TXData[2] = 0;
	clrf	0+(_TXData)+02h
	line	827
	
l3980:	
;CoachMasterCode.c: 827: TXData[3] = 0;
	clrf	0+(_TXData)+03h
	line	828
	
l3982:	
;CoachMasterCode.c: 828: TXData[4] = 0;
	clrf	0+(_TXData)+04h
	line	829
	
l3984:	
;CoachMasterCode.c: 829: TXData[5] = 0;
	clrf	0+(_TXData)+05h
	line	830
;CoachMasterCode.c: 830: Length = 2;
	movlw	(02h)
	movwf	(??_Encode_Message+0)+0
	movf	(??_Encode_Message+0)+0,w
	movwf	(Encode_Message@Length)
	line	833
;CoachMasterCode.c: 832: }
;CoachMasterCode.c: 833: break;
	goto	l4032
	line	835
;CoachMasterCode.c: 835: case 4:
	
l1137:	
	line	838
	
l3986:	
;CoachMasterCode.c: 836: {
;CoachMasterCode.c: 838: TXData[0] = 0x03;
	movlw	(03h)
	movwf	(??_Encode_Message+0)+0
	movf	(??_Encode_Message+0)+0,w
	movwf	(_TXData)
	line	839
;CoachMasterCode.c: 839: TXData[1] = PAIRDATA;
	movf	(_PAIRDATA),w
	movwf	(??_Encode_Message+0)+0
	movf	(??_Encode_Message+0)+0,w
	movwf	0+(_TXData)+01h
	line	840
	
l3988:	
;CoachMasterCode.c: 840: TXData[2] = 0;
	clrf	0+(_TXData)+02h
	line	841
	
l3990:	
;CoachMasterCode.c: 841: TXData[3] = 0;
	clrf	0+(_TXData)+03h
	line	842
	
l3992:	
;CoachMasterCode.c: 842: TXData[4] = 0;
	clrf	0+(_TXData)+04h
	line	843
	
l3994:	
;CoachMasterCode.c: 843: TXData[5] = 0;
	clrf	0+(_TXData)+05h
	line	844
;CoachMasterCode.c: 844: Length = 2;
	movlw	(02h)
	movwf	(??_Encode_Message+0)+0
	movf	(??_Encode_Message+0)+0,w
	movwf	(Encode_Message@Length)
	line	846
	
l3996:	
;CoachMasterCode.c: 846: X_AddrMSB = 0xff;
	clrf	(_X_AddrMSB)
	decf	(_X_AddrMSB),f
	line	847
	
l3998:	
;CoachMasterCode.c: 847: X_AddrLSB = 0xff;
	clrf	(_X_AddrLSB)
	decf	(_X_AddrLSB),f
	line	849
;CoachMasterCode.c: 848: }
;CoachMasterCode.c: 849: break;
	goto	l4032
	line	852
;CoachMasterCode.c: 852: case 5:
	
l1138:	
	line	855
	
l4000:	
;CoachMasterCode.c: 853: {
;CoachMasterCode.c: 855: TXData[0] = 0x05;
	movlw	(05h)
	movwf	(??_Encode_Message+0)+0
	movf	(??_Encode_Message+0)+0,w
	movwf	(_TXData)
	line	856
;CoachMasterCode.c: 856: TXData[1] = RESPDATA;
	movf	(_RESPDATA),w
	movwf	(??_Encode_Message+0)+0
	movf	(??_Encode_Message+0)+0,w
	movwf	0+(_TXData)+01h
	line	857
	
l4002:	
;CoachMasterCode.c: 857: TXData[2] = 0;
	clrf	0+(_TXData)+02h
	line	858
	
l4004:	
;CoachMasterCode.c: 858: TXData[3] = 0;
	clrf	0+(_TXData)+03h
	line	859
	
l4006:	
;CoachMasterCode.c: 859: TXData[4] = 0;
	clrf	0+(_TXData)+04h
	line	860
	
l4008:	
;CoachMasterCode.c: 860: TXData[5] = 0;
	clrf	0+(_TXData)+05h
	line	861
;CoachMasterCode.c: 861: Length = 2;
	movlw	(02h)
	movwf	(??_Encode_Message+0)+0
	movf	(??_Encode_Message+0)+0,w
	movwf	(Encode_Message@Length)
	line	864
;CoachMasterCode.c: 863: }
;CoachMasterCode.c: 864: break;
	goto	l4032
	line	866
;CoachMasterCode.c: 866: case 6:
	
l1139:	
	line	869
	
l4010:	
;CoachMasterCode.c: 867: {
;CoachMasterCode.c: 869: TXData[0] = 0x01;
	clrf	(_TXData)
	bsf	status,0
	rlf	(_TXData),f
	line	870
	
l4012:	
;CoachMasterCode.c: 870: TXData[1] = SPD;
	movf	(_SPD),w
	movwf	(??_Encode_Message+0)+0
	movf	(??_Encode_Message+0)+0,w
	movwf	0+(_TXData)+01h
	line	871
	
l4014:	
;CoachMasterCode.c: 871: TXData[2] = DIR;
	movf	(_DIR),w
	movwf	(??_Encode_Message+0)+0
	movf	(??_Encode_Message+0)+0,w
	movwf	0+(_TXData)+02h
	line	872
	
l4016:	
;CoachMasterCode.c: 872: TXData[3] = AUX;
	movf	(_AUX),w
	movwf	(??_Encode_Message+0)+0
	movf	(??_Encode_Message+0)+0,w
	movwf	0+(_TXData)+03h
	line	873
	
l4018:	
;CoachMasterCode.c: 873: TXData[4] = WHIM;
	movf	(_WHIM),w
	movwf	(??_Encode_Message+0)+0
	movf	(??_Encode_Message+0)+0,w
	movwf	0+(_TXData)+04h
	line	874
	
l4020:	
;CoachMasterCode.c: 874: TXData[5] = TRANS;
	movf	(_TRANS),w
	movwf	(??_Encode_Message+0)+0
	movf	(??_Encode_Message+0)+0,w
	movwf	0+(_TXData)+05h
	line	875
	
l4022:	
;CoachMasterCode.c: 875: Length = 6;
	movlw	(06h)
	movwf	(??_Encode_Message+0)+0
	movf	(??_Encode_Message+0)+0,w
	movwf	(Encode_Message@Length)
	line	876
	
l4024:	
;CoachMasterCode.c: 876: SendKick = 0;
	clrf	(_SendKick)
	line	877
	
l4026:	
;CoachMasterCode.c: 877: SendWhimsy = 0;
	clrf	(_SendWhimsy)
	line	878
	
l4028:	
;CoachMasterCode.c: 878: PORTC &= ~0x00000008;
	movlw	(0F7h)
	movwf	(??_Encode_Message+0)+0
	movf	(??_Encode_Message+0)+0,w
	andwf	(7),f	;volatile
	line	880
;CoachMasterCode.c: 879: }
;CoachMasterCode.c: 880: break;
	goto	l4032
	line	882
;CoachMasterCode.c: 882: default:
	
l1140:	
	line	883
;CoachMasterCode.c: 883: Length = 0;
	clrf	(Encode_Message@Length)
	line	885
;CoachMasterCode.c: 885: }
	goto	l4032
	line	774
	
l1131:	
	
l4030:	
	movf	(Encode_Message@Type),w
	; Switch size 1, requested type "space"
; Number of cases is 7, Range of values is 0 to 6
; switch strategies available:
; Name         Instructions Cycles
; direct_byte           21     7 (fixed)
; simple_byte           22    12 (average)
; jumptable            260     6 (fixed)
; rangetable            11     6 (fixed)
; spacedrange           20     9 (fixed)
; locatedrange           7     3 (fixed)
;	Chosen strategy is direct_byte

	movwf fsr
	movlw	7
	subwf	fsr,w
skipnc
goto l1140
movlw high(S4726)
movwf pclath
	clrc
	rlf fsr,w
	addlw low(S4726)
	movwf pc
psect	swtext3,local,class=CONST,delta=2
global __pswtext3
__pswtext3:
S4726:
	ljmp	l3942
	ljmp	l3956
	ljmp	l3966
	ljmp	l3976
	ljmp	l3986
	ljmp	l4000
	ljmp	l4010
psect	text430

	line	885
	
l1133:	
	line	886
	
l4032:	
;CoachMasterCode.c: 886: return Length;
	movf	(Encode_Message@Length),w
	goto	l1141
	
l4034:	
	line	888
	
l1141:	
	return
	opt stack 0
GLOBAL	__end_of_Encode_Message
	__end_of_Encode_Message:
;; =============== function _Encode_Message ends ============

	signat	_Encode_Message,4217
	global	_InitInterrupts
psect	text431,local,class=CODE,delta=2
global __ptext431
__ptext431:

;; *************** function _InitInterrupts *****************
;; Defined at:
;;		line 643 in file "U:\_218c Teams\BringItOn\218C Project - World Cup\COACH CODE WE ARE USING\MasterCoach\MasterCoach\CoachMasterCode.c"
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
psect	text431
	file	"U:\_218c Teams\BringItOn\218C Project - World Cup\COACH CODE WE ARE USING\MasterCoach\MasterCoach\CoachMasterCode.c"
	line	643
	global	__size_of_InitInterrupts
	__size_of_InitInterrupts	equ	__end_of_InitInterrupts-_InitInterrupts
	
_InitInterrupts:	
	opt	stack 5
; Regs used in _InitInterrupts: [wreg+status,2]
	line	646
	
l4462:	
;CoachMasterCode.c: 646: INTCON = 0b11001000;
	movlw	(0C8h)
	movwf	(11)	;volatile
	line	647
	
l4464:	
;CoachMasterCode.c: 647: RCIE = 1;
	bsf	status, 5	;RP0=1, select bank1
	bcf	status, 6	;RP1=0, select bank1
	bsf	(1125/8)^080h,(1125)&7
	line	648
	
l4466:	
;CoachMasterCode.c: 648: TMR2IE = 1;
	bsf	(1121/8)^080h,(1121)&7
	line	649
	
l4468:	
;CoachMasterCode.c: 649: SSPIE = 1;
	bsf	(1123/8)^080h,(1123)&7
	line	650
	
l4470:	
;CoachMasterCode.c: 650: PIR1 = 0;
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	clrf	(12)	;volatile
	line	652
	
l4472:	
;CoachMasterCode.c: 652: IOCA = (0x00000001|0x00000002|0x00000004);
	movlw	(07h)
	bsf	status, 5	;RP0=1, select bank1
	bcf	status, 6	;RP1=0, select bank1
	movwf	(150)^080h	;volatile
	line	653
	
l1106:	
	return
	opt stack 0
GLOBAL	__end_of_InitInterrupts
	__end_of_InitInterrupts:
;; =============== function _InitInterrupts ends ============

	signat	_InitInterrupts,88
	global	_InitComm
psect	text432,local,class=CODE,delta=2
global __ptext432
__ptext432:

;; *************** function _InitComm *****************
;; Defined at:
;;		line 657 in file "U:\_218c Teams\BringItOn\218C Project - World Cup\COACH CODE WE ARE USING\MasterCoach\MasterCoach\CoachMasterCode.c"
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
psect	text432
	file	"U:\_218c Teams\BringItOn\218C Project - World Cup\COACH CODE WE ARE USING\MasterCoach\MasterCoach\CoachMasterCode.c"
	line	657
	global	__size_of_InitComm
	__size_of_InitComm	equ	__end_of_InitComm-_InitComm
	
_InitComm:	
	opt	stack 5
; Regs used in _InitComm: [wreg+status,2+status,0]
	line	659
	
l3866:	
;CoachMasterCode.c: 659: SPBRG = 129;
	movlw	(081h)
	bsf	status, 5	;RP0=1, select bank1
	bcf	status, 6	;RP1=0, select bank1
	movwf	(153)^080h	;volatile
	line	660
	
l3868:	
;CoachMasterCode.c: 660: SPBRGH = 0;
	clrf	(154)^080h	;volatile
	line	661
	
l3870:	
;CoachMasterCode.c: 661: TXSTA = 0b00100100;
	movlw	(024h)
	movwf	(152)^080h	;volatile
	line	662
	
l3872:	
;CoachMasterCode.c: 662: RCSTA = 0b10010000;
	movlw	(090h)
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	movwf	(24)	;volatile
	line	666
	
l3874:	
;CoachMasterCode.c: 666: SSPSTAT = 0;
	bsf	status, 5	;RP0=1, select bank1
	bcf	status, 6	;RP1=0, select bank1
	clrf	(148)^080h	;volatile
	line	667
	
l3876:	
;CoachMasterCode.c: 667: WCOL = 0;
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	bcf	(167/8),(167)&7
	line	668
	
l3878:	
;CoachMasterCode.c: 668: SSPOV = 0;
	bcf	(166/8),(166)&7
	line	669
	
l3880:	
;CoachMasterCode.c: 669: SSPEN = 1;
	bsf	(165/8),(165)&7
	line	670
	
l3882:	
;CoachMasterCode.c: 670: CKP = 1;
	bsf	(164/8),(164)&7
	line	671
	
l3884:	
;CoachMasterCode.c: 671: SSPM3 = 0;
	bcf	(163/8),(163)&7
	line	672
	
l3886:	
;CoachMasterCode.c: 672: SSPM2 = 0;
	bcf	(162/8),(162)&7
	line	673
	
l3888:	
;CoachMasterCode.c: 673: SSPM1 = 1;
	bsf	(161/8),(161)&7
	line	674
	
l3890:	
;CoachMasterCode.c: 674: SSPM0 = 1;
	bsf	(160/8),(160)&7
	line	676
	
l3892:	
;CoachMasterCode.c: 676: PORTC_Copy&=(~0x00000040);
	movlw	(0BFh)
	movwf	(??_InitComm+0)+0
	movf	(??_InitComm+0)+0,w
	andwf	(_PORTC_Copy),f
	line	677
	
l3894:	
;CoachMasterCode.c: 677: PORTC = PORTC_Copy;
	movf	(_PORTC_Copy),w
	movwf	(7)	;volatile
	line	679
	
l3896:	
;CoachMasterCode.c: 679: BytesOut[0] = 0x37;
	movlw	(037h)
	movwf	(??_InitComm+0)+0
	movf	(??_InitComm+0)+0,w
	movwf	(_BytesOut)
	line	680
	
l3898:	
;CoachMasterCode.c: 680: BytesOut[1] = SDATA;
	movf	(_SDATA),w
	movwf	(??_InitComm+0)+0
	movf	(??_InitComm+0)+0,w
	movwf	0+(_BytesOut)+01h
	line	681
	
l3900:	
;CoachMasterCode.c: 681: BytesOut[2] = 0x00;
	clrf	0+(_BytesOut)+02h
	line	682
	
l3902:	
;CoachMasterCode.c: 682: BytesOut[3] = 0x00;
	clrf	0+(_BytesOut)+03h
	line	683
	
l3904:	
;CoachMasterCode.c: 683: BytesOut[4] = 0x00;
	clrf	0+(_BytesOut)+04h
	line	684
	
l3906:	
;CoachMasterCode.c: 684: BytesOut[5] = 0x00;
	clrf	0+(_BytesOut)+05h
	line	685
	
l3908:	
;CoachMasterCode.c: 685: BytesOut[6] = 0x00;
	clrf	0+(_BytesOut)+06h
	line	686
	
l3910:	
;CoachMasterCode.c: 686: BytesOut[7] = 0x00;
	clrf	0+(_BytesOut)+07h
	line	688
	
l3912:	
;CoachMasterCode.c: 688: BytesIn[0] = 0;
	clrf	(_BytesIn)
	line	689
	
l3914:	
;CoachMasterCode.c: 689: BytesIn[1] = 0;
	clrf	0+(_BytesIn)+01h
	line	690
	
l3916:	
;CoachMasterCode.c: 690: BytesIn[2] = 0;
	clrf	0+(_BytesIn)+02h
	line	691
	
l3918:	
;CoachMasterCode.c: 691: BytesIn[3] = 0;
	clrf	0+(_BytesIn)+03h
	line	692
	
l3920:	
;CoachMasterCode.c: 692: BytesIn[4] = 0;
	clrf	0+(_BytesIn)+04h
	line	693
	
l3922:	
;CoachMasterCode.c: 693: BytesIn[5] = 0;
	clrf	0+(_BytesIn)+05h
	line	694
	
l3924:	
;CoachMasterCode.c: 694: BytesIn[6] = 0;
	clrf	0+(_BytesIn)+06h
	line	695
	
l3926:	
;CoachMasterCode.c: 695: BytesIn[7] = 0;
	clrf	0+(_BytesIn)+07h
	line	696
	
l1109:	
	return
	opt stack 0
GLOBAL	__end_of_InitComm
	__end_of_InitComm:
;; =============== function _InitComm ends ============

	signat	_InitComm,88
	global	_InitPorts
psect	text433,local,class=CODE,delta=2
global __ptext433
__ptext433:

;; *************** function _InitPorts *****************
;; Defined at:
;;		line 628 in file "U:\_218c Teams\BringItOn\218C Project - World Cup\COACH CODE WE ARE USING\MasterCoach\MasterCoach\CoachMasterCode.c"
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
psect	text433
	file	"U:\_218c Teams\BringItOn\218C Project - World Cup\COACH CODE WE ARE USING\MasterCoach\MasterCoach\CoachMasterCode.c"
	line	628
	global	__size_of_InitPorts
	__size_of_InitPorts	equ	__end_of_InitPorts-_InitPorts
	
_InitPorts:	
	opt	stack 5
; Regs used in _InitPorts: [wreg+status,2]
	line	630
	
l4454:	
;CoachMasterCode.c: 630: ANSEL = 0;
	bcf	status, 5	;RP0=0, select bank2
	bsf	status, 6	;RP1=1, select bank2
	clrf	(286)^0100h	;volatile
	line	631
;CoachMasterCode.c: 631: ANSELH = 0;
	clrf	(287)^0100h	;volatile
	line	632
	
l4456:	
;CoachMasterCode.c: 632: TRISA = 0b00111111;
	movlw	(03Fh)
	bsf	status, 5	;RP0=1, select bank1
	bcf	status, 6	;RP1=0, select bank1
	movwf	(133)^080h	;volatile
	line	633
	
l4458:	
;CoachMasterCode.c: 633: TRISB = 0b00110000;
	movlw	(030h)
	movwf	(134)^080h	;volatile
	line	634
;CoachMasterCode.c: 634: TRISC = 0b00000000;
	clrf	(135)^080h	;volatile
	line	636
;CoachMasterCode.c: 636: PORTA = 0;
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	clrf	(5)	;volatile
	line	637
;CoachMasterCode.c: 637: PORTB = 0;
	clrf	(6)	;volatile
	line	638
	
l4460:	
;CoachMasterCode.c: 638: PORTC = 0x00000010;
	movlw	(010h)
	movwf	(7)	;volatile
	line	639
	
l1103:	
	return
	opt stack 0
GLOBAL	__end_of_InitPorts
	__end_of_InitPorts:
;; =============== function _InitPorts ends ============

	signat	_InitPorts,88
	global	_InitTimers
psect	text434,local,class=CODE,delta=2
global __ptext434
__ptext434:

;; *************** function _InitTimers *****************
;; Defined at:
;;		line 621 in file "U:\_218c Teams\BringItOn\218C Project - World Cup\COACH CODE WE ARE USING\MasterCoach\MasterCoach\CoachMasterCode.c"
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
psect	text434
	file	"U:\_218c Teams\BringItOn\218C Project - World Cup\COACH CODE WE ARE USING\MasterCoach\MasterCoach\CoachMasterCode.c"
	line	621
	global	__size_of_InitTimers
	__size_of_InitTimers	equ	__end_of_InitTimers-_InitTimers
	
_InitTimers:	
	opt	stack 5
; Regs used in _InitTimers: [wreg]
	line	622
	
l4452:	
;CoachMasterCode.c: 622: T2CON = 0b01111110;
	movlw	(07Eh)
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	movwf	(18)	;volatile
	line	623
;CoachMasterCode.c: 623: PR2 = 50;
	movlw	(032h)
	bsf	status, 5	;RP0=1, select bank1
	bcf	status, 6	;RP1=0, select bank1
	movwf	(146)^080h	;volatile
	line	624
	
l1100:	
	return
	opt stack 0
GLOBAL	__end_of_InitTimers
	__end_of_InitTimers:
;; =============== function _InitTimers ends ============

	signat	_InitTimers,88
	global	_ISR
psect	text435,local,class=CODE,delta=2
global __ptext435
__ptext435:

;; *************** function _ISR *****************
;; Defined at:
;;		line 524 in file "U:\_218c Teams\BringItOn\218C Project - World Cup\COACH CODE WE ARE USING\MasterCoach\MasterCoach\CoachMasterCode.c"
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
;;		_Process_SPI
;;		i1_XBee_State
;; This function is called by:
;;		Interrupt level 1
;; This function uses a non-reentrant model
;;
psect	text435
	file	"U:\_218c Teams\BringItOn\218C Project - World Cup\COACH CODE WE ARE USING\MasterCoach\MasterCoach\CoachMasterCode.c"
	line	524
	global	__size_of_ISR
	__size_of_ISR	equ	__end_of_ISR-_ISR
	
_ISR:	
	opt	stack 5
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
psect	text435
	line	527
	
i1l4088:	
;CoachMasterCode.c: 527: INTCON &= 0b00110111;
	movlw	(037h)
	movwf	(??_ISR+0)+0
	movf	(??_ISR+0)+0,w
	andwf	(11),f	;volatile
	line	529
	
i1l4090:	
;CoachMasterCode.c: 529: if (RCIF)
	btfss	(101/8),(101)&7
	goto	u269_21
	goto	u269_20
u269_21:
	goto	i1l4096
u269_20:
	line	531
	
i1l4092:	
;CoachMasterCode.c: 530: {
;CoachMasterCode.c: 531: R_Transition = 1;
	clrf	(_R_Transition)
	bsf	status,0
	rlf	(_R_Transition),f
	line	532
	
i1l4094:	
;CoachMasterCode.c: 532: ByteIn = RCREG;
	movf	(26),w	;volatile
	movwf	(??_ISR+0)+0
	movf	(??_ISR+0)+0,w
	movwf	(_ByteIn)	;volatile
	goto	i1l4096
	line	534
	
i1l1086:	
	line	536
	
i1l4096:	
;CoachMasterCode.c: 534: }
;CoachMasterCode.c: 536: if (SSPIF)
	btfss	(99/8),(99)&7
	goto	u270_21
	goto	u270_20
u270_21:
	goto	i1l4122
u270_20:
	line	539
	
i1l4098:	
;CoachMasterCode.c: 537: {
;CoachMasterCode.c: 539: PORTC_Copy|=0x00000040;
	bsf	(_PORTC_Copy)+(6/8),(6)&7
	line	540
	
i1l4100:	
;CoachMasterCode.c: 540: PORTC = PORTC_Copy;
	movf	(_PORTC_Copy),w
	movwf	(7)	;volatile
	line	541
;CoachMasterCode.c: 541: SPI_Var = SSPBUF;
	movf	(19),w	;volatile
	movwf	(??_ISR+0)+0
	movf	(??_ISR+0)+0,w
	movwf	(_SPI_Var)	;volatile
	line	542
;CoachMasterCode.c: 542: if (SPI_Var==0x37)
	movf	(_SPI_Var),w
	xorlw	037h
	skipz
	goto	u271_21
	goto	u271_20
u271_21:
	goto	i1l4104
u271_20:
	line	543
	
i1l4102:	
;CoachMasterCode.c: 543: i=0;
	clrf	(_i)
	goto	i1l4104
	
i1l1088:	
	line	545
	
i1l4104:	
;CoachMasterCode.c: 545: BytesIn[i] = SPI_Var;
	movf	(_SPI_Var),w
	movwf	(??_ISR+0)+0
	movf	(_i),w
	addlw	_BytesIn&0ffh
	movwf	fsr0
	movf	(??_ISR+0)+0,w
	bcf	status, 7	;select IRP bank0
	movwf	indf
	line	547
	
i1l4106:	
;CoachMasterCode.c: 547: i++;
	movlw	(01h)
	movwf	(??_ISR+0)+0
	movf	(??_ISR+0)+0,w
	addwf	(_i),f
	line	549
	
i1l4108:	
;CoachMasterCode.c: 549: if(i>=8)
	movlw	(08h)
	subwf	(_i),w
	skipc
	goto	u272_21
	goto	u272_20
u272_21:
	goto	i1l4114
u272_20:
	line	551
	
i1l4110:	
;CoachMasterCode.c: 550: {
;CoachMasterCode.c: 551: i=0;
	clrf	(_i)
	line	552
	
i1l4112:	
;CoachMasterCode.c: 552: Process_SPI();
	fcall	_Process_SPI
	goto	i1l4114
	line	553
	
i1l1089:	
	line	556
	
i1l4114:	
;CoachMasterCode.c: 553: }
;CoachMasterCode.c: 556: PORTC_Copy&=(~0x00000040);
	movlw	(0BFh)
	movwf	(??_ISR+0)+0
	movf	(??_ISR+0)+0,w
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	andwf	(_PORTC_Copy),f
	line	557
	
i1l4116:	
;CoachMasterCode.c: 557: PORTC = PORTC_Copy;
	movf	(_PORTC_Copy),w
	movwf	(7)	;volatile
	line	559
	
i1l4118:	
;CoachMasterCode.c: 559: SSPBUF = BytesOut[i];
	movf	(_i),w
	addlw	_BytesOut&0ffh
	movwf	fsr0
	bcf	status, 7	;select IRP bank0
	movf	indf,w
	movwf	(19)
	line	560
	
i1l4120:	
;CoachMasterCode.c: 560: SSPIF = 0;
	bcf	(99/8),(99)&7
	goto	i1l4122
	line	561
	
i1l1087:	
	line	563
	
i1l4122:	
;CoachMasterCode.c: 561: }
;CoachMasterCode.c: 563: if (TMR2IF)
	btfss	(97/8),(97)&7
	goto	u273_21
	goto	u273_20
u273_21:
	goto	i1l4144
u273_20:
	line	566
	
i1l4124:	
;CoachMasterCode.c: 564: {
;CoachMasterCode.c: 566: TOCounter++;
	movlw	low(01h)
	addwf	(_TOCounter),f
	skipnc
	incf	(_TOCounter+1),f
	movlw	high(01h)
	addwf	(_TOCounter+1),f
	line	568
;CoachMasterCode.c: 568: if (TOCounter>=78)
	movlw	high(04Eh)
	subwf	(_TOCounter+1),w
	movlw	low(04Eh)
	skipnz
	subwf	(_TOCounter),w
	skipc
	goto	u274_21
	goto	u274_20
u274_21:
	goto	i1l4142
u274_20:
	line	571
	
i1l4126:	
;CoachMasterCode.c: 569: {
;CoachMasterCode.c: 571: TOCounter = 0;
	clrf	(_TOCounter)
	clrf	(_TOCounter+1)
	line	572
	
i1l4128:	
;CoachMasterCode.c: 572: X_Transition = 1;
	clrf	(_X_Transition)
	bsf	status,0
	rlf	(_X_Transition),f
	line	573
	
i1l4130:	
;CoachMasterCode.c: 573: CurrentX_State = X_Idle_State;
	clrf	(_CurrentX_State)
	line	574
	
i1l4132:	
;CoachMasterCode.c: 574: NextX_State = CurrentX_State;
	movf	(_CurrentX_State),w
	movwf	(??_ISR+0)+0
	movf	(??_ISR+0)+0,w
	movwf	(_NextX_State)
	line	576
	
i1l4134:	
;CoachMasterCode.c: 576: LostCommCounter++;
	movlw	(01h)
	movwf	(??_ISR+0)+0
	movf	(??_ISR+0)+0,w
	addwf	(_LostCommCounter),f
	line	577
	
i1l4136:	
;CoachMasterCode.c: 577: if (LostCommCounter>=25)
	movlw	(019h)
	subwf	(_LostCommCounter),w
	skipc
	goto	u275_21
	goto	u275_20
u275_21:
	goto	i1l4142
u275_20:
	line	579
	
i1l4138:	
;CoachMasterCode.c: 578: {
;CoachMasterCode.c: 579: LostCommCounter = 0;
	clrf	(_LostCommCounter)
	line	581
	
i1l4140:	
;CoachMasterCode.c: 581: XBee_State(0);
	movlw	(0)
	fcall	i1_XBee_State
	goto	i1l4142
	line	583
	
i1l1092:	
	goto	i1l4142
	line	584
	
i1l1091:	
	line	585
	
i1l4142:	
;CoachMasterCode.c: 583: }
;CoachMasterCode.c: 584: }
;CoachMasterCode.c: 585: TMR2IF = 0;
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	bcf	(97/8),(97)&7
	goto	i1l4144
	line	586
	
i1l1090:	
	line	588
	
i1l4144:	
;CoachMasterCode.c: 586: }
;CoachMasterCode.c: 588: if (RABIF)
	btfss	(88/8),(88)&7
	goto	u276_21
	goto	u276_20
u276_21:
	goto	i1l4166
u276_20:
	line	590
	
i1l4146:	
;CoachMasterCode.c: 589: {
;CoachMasterCode.c: 590: SwitchState = PORTA;
	movf	(5),w	;volatile
	movwf	(??_ISR+0)+0
	movf	(??_ISR+0)+0,w
	movwf	(_SwitchState)
	line	591
	
i1l4148:	
;CoachMasterCode.c: 591: SwitchState &= SwitchMask;
	movf	(_SwitchMask),w
	movwf	(??_ISR+0)+0
	movf	(??_ISR+0)+0,w
	andwf	(_SwitchState),f
	line	592
	
i1l4150:	
;CoachMasterCode.c: 592: if(SwitchState == 0b00000001)
	movf	(_SwitchState),w
	xorlw	01h
	skipz
	goto	u277_21
	goto	u277_20
u277_21:
	goto	i1l4154
u277_20:
	line	594
	
i1l4152:	
;CoachMasterCode.c: 593: {
;CoachMasterCode.c: 594: CurrentType = 0;
	clrf	(_CurrentType)
	goto	i1l4154
	line	596
	
i1l1094:	
	line	597
	
i1l4154:	
;CoachMasterCode.c: 596: }
;CoachMasterCode.c: 597: if(SwitchState == 0b00000010)
	movf	(_SwitchState),w
	xorlw	02h
	skipz
	goto	u278_21
	goto	u278_20
u278_21:
	goto	i1l4158
u278_20:
	line	599
	
i1l4156:	
;CoachMasterCode.c: 598: {
;CoachMasterCode.c: 599: CurrentType = 1;
	clrf	(_CurrentType)
	bsf	status,0
	rlf	(_CurrentType),f
	goto	i1l4158
	line	600
	
i1l1095:	
	line	601
	
i1l4158:	
;CoachMasterCode.c: 600: }
;CoachMasterCode.c: 601: if(SwitchState == 0b00000100)
	movf	(_SwitchState),w
	xorlw	04h
	skipz
	goto	u279_21
	goto	u279_20
u279_21:
	goto	i1l4164
u279_20:
	line	604
	
i1l4160:	
;CoachMasterCode.c: 602: {
;CoachMasterCode.c: 604: CurrentType = 4;
	movlw	(04h)
	movwf	(??_ISR+0)+0
	movf	(??_ISR+0)+0,w
	movwf	(_CurrentType)
	line	606
	
i1l4162:	
;CoachMasterCode.c: 606: XBee_State(1);
	movlw	(01h)
	fcall	i1_XBee_State
	goto	i1l4164
	line	609
	
i1l1096:	
	line	610
	
i1l4164:	
;CoachMasterCode.c: 609: }
;CoachMasterCode.c: 610: RABIF = 0;
	bcf	(88/8),(88)&7
	goto	i1l4166
	line	611
	
i1l1093:	
	line	614
	
i1l4166:	
;CoachMasterCode.c: 611: }
;CoachMasterCode.c: 614: INTCON |= 0b11001000;
	movlw	(0C8h)
	movwf	(??_ISR+0)+0
	movf	(??_ISR+0)+0,w
	iorwf	(11),f	;volatile
	goto	i1l1097
	line	615
	
i1l4168:	
	line	616
;CoachMasterCode.c: 615: return;
	
i1l1097:	
	movf	(??_ISR+4),w
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
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
	global	i1_XBee_State
psect	text436,local,class=CODE,delta=2
global __ptext436
__ptext436:

;; *************** function i1_XBee_State *****************
;; Defined at:
;;		line 735 in file "U:\_218c Teams\BringItOn\218C Project - World Cup\COACH CODE WE ARE USING\MasterCoach\MasterCoach\CoachMasterCode.c"
;; Parameters:    Size  Location     Type
;;  XBee_State      1    wreg     unsigned char 
;; Auto vars:     Size  Location     Type
;;  XBee_State      1    1[COMMON] unsigned char 
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
psect	text436
	file	"U:\_218c Teams\BringItOn\218C Project - World Cup\COACH CODE WE ARE USING\MasterCoach\MasterCoach\CoachMasterCode.c"
	line	735
	global	__size_ofi1_XBee_State
	__size_ofi1_XBee_State	equ	__end_ofi1_XBee_State-i1_XBee_State
	
i1_XBee_State:	
	opt	stack 5
; Regs used in i1_XBee_State: [wreg+status,2+status,0]
;i1XBee_State@x stored from wreg
	movwf	(i1XBee_State@x)
	line	736
	
i1l4184:	
;CoachMasterCode.c: 736: if(x)
	movf	(i1XBee_State@x),w
	skipz
	goto	u284_20
	goto	i1l1126
u284_20:
	line	738
	
i1l4186:	
;CoachMasterCode.c: 737: {
;CoachMasterCode.c: 738: CommActive = 1;
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	clrf	(_CommActive)
	bsf	status,0
	rlf	(_CommActive),f
	line	739
	
i1l4188:	
;CoachMasterCode.c: 739: CurrentR_State = R_Idle_State;
	clrf	(_CurrentR_State)
	line	740
	
i1l4190:	
;CoachMasterCode.c: 740: CurrentX_State = X_Idle_State;
	clrf	(_CurrentX_State)
	line	741
	
i1l4192:	
;CoachMasterCode.c: 741: PORTC_Copy&=~0x00000001;
	movlw	(0FEh)
	movwf	(??i1_XBee_State+0)+0
	movf	(??i1_XBee_State+0)+0,w
	andwf	(_PORTC_Copy),f
	line	742
	
i1l4194:	
;CoachMasterCode.c: 742: PORTC_Copy|=0x00000002;
	bsf	(_PORTC_Copy)+(1/8),(1)&7
	line	743
	
i1l4196:	
;CoachMasterCode.c: 743: LostCommCounter = 0;
	clrf	(_LostCommCounter)
	line	744
;CoachMasterCode.c: 744: PORTC = PORTC_Copy;
	movf	(_PORTC_Copy),w
	movwf	(7)	;volatile
	line	745
;CoachMasterCode.c: 745: }
	goto	i1l1128
	line	746
	
i1l1126:	
	line	748
;CoachMasterCode.c: 746: else
;CoachMasterCode.c: 747: {
;CoachMasterCode.c: 748: LostCommCounter = 0;
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	clrf	(_LostCommCounter)
	line	749
;CoachMasterCode.c: 749: CommActive = 0;
	clrf	(_CommActive)
	line	750
	
i1l4198:	
;CoachMasterCode.c: 750: PORTC_Copy&=~0x00000002;
	movlw	(0FDh)
	movwf	(??i1_XBee_State+0)+0
	movf	(??i1_XBee_State+0)+0,w
	andwf	(_PORTC_Copy),f
	line	751
;CoachMasterCode.c: 751: PORTC_Copy&=~0x00000004;
	movlw	(0FBh)
	movwf	(??i1_XBee_State+0)+0
	movf	(??i1_XBee_State+0)+0,w
	andwf	(_PORTC_Copy),f
	line	752
	
i1l4200:	
;CoachMasterCode.c: 752: PORTC_Copy|=0x00000001;
	bsf	(_PORTC_Copy)+(0/8),(0)&7
	line	753
	
i1l4202:	
;CoachMasterCode.c: 753: PORTC = PORTC_Copy;
	movf	(_PORTC_Copy),w
	movwf	(7)	;volatile
	goto	i1l1128
	line	755
	
i1l1127:	
	line	756
	
i1l1128:	
	return
	opt stack 0
GLOBAL	__end_ofi1_XBee_State
	__end_ofi1_XBee_State:
;; =============== function i1_XBee_State ends ============

	signat	i1_XBee_State,88
	global	_Process_SPI
psect	text437,local,class=CODE,delta=2
global __ptext437
__ptext437:

;; *************** function _Process_SPI *****************
;; Defined at:
;;		line 891 in file "U:\_218c Teams\BringItOn\218C Project - World Cup\COACH CODE WE ARE USING\MasterCoach\MasterCoach\CoachMasterCode.c"
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
psect	text437
	file	"U:\_218c Teams\BringItOn\218C Project - World Cup\COACH CODE WE ARE USING\MasterCoach\MasterCoach\CoachMasterCode.c"
	line	891
	global	__size_of_Process_SPI
	__size_of_Process_SPI	equ	__end_of_Process_SPI-_Process_SPI
	
_Process_SPI:	
	opt	stack 5
; Regs used in _Process_SPI: [wreg+status,2+status,0]
	line	892
	
i1l4170:	
;CoachMasterCode.c: 892: if ( BytesIn[5] != 0)
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	movf	0+(_BytesIn)+05h,w
	skipz
	goto	u280_20
	goto	i1l1144
u280_20:
	line	894
	
i1l4172:	
;CoachMasterCode.c: 893: {
;CoachMasterCode.c: 894: PORTC |= 0x00000008;
	bsf	(7)+(3/8),(3)&7	;volatile
	line	895
	
i1l4174:	
;CoachMasterCode.c: 895: SendKick = 0x0F;
	movlw	(0Fh)
	movwf	(??_Process_SPI+0)+0
	movf	(??_Process_SPI+0)+0,w
	movwf	(_SendKick)
	line	896
	
i1l1144:	
	line	897
;CoachMasterCode.c: 896: }
;CoachMasterCode.c: 897: if ( BytesIn[6] != 0)
	movf	0+(_BytesIn)+06h,w
	skipz
	goto	u281_20
	goto	i1l1145
u281_20:
	line	900
	
i1l4176:	
;CoachMasterCode.c: 898: {
;CoachMasterCode.c: 900: SendWhimsy = 0xFF;
	movlw	(0FFh)
	movwf	(??_Process_SPI+0)+0
	movf	(??_Process_SPI+0)+0,w
	movwf	(_SendWhimsy)
	line	901
	
i1l1145:	
	line	903
;CoachMasterCode.c: 901: }
;CoachMasterCode.c: 903: if ((BytesIn[0]==0x37)&&(BytesIn[7]==0x00))
	movf	(_BytesIn),w
	xorlw	037h
	skipz
	goto	u282_21
	goto	u282_20
u282_21:
	goto	i1l1146
u282_20:
	
i1l4178:	
	movf	0+(_BytesIn)+07h,f
	skipz
	goto	u283_21
	goto	u283_20
u283_21:
	goto	i1l1146
u283_20:
	line	905
	
i1l4180:	
;CoachMasterCode.c: 904: {
;CoachMasterCode.c: 905: PAIRDATA = BytesIn[1];
	movf	0+(_BytesIn)+01h,w
	movwf	(??_Process_SPI+0)+0
	movf	(??_Process_SPI+0)+0,w
	movwf	(_PAIRDATA)
	line	906
;CoachMasterCode.c: 906: SPD = BytesIn[2];
	movf	0+(_BytesIn)+02h,w
	movwf	(??_Process_SPI+0)+0
	movf	(??_Process_SPI+0)+0,w
	movwf	(_SPD)
	line	907
;CoachMasterCode.c: 907: DIR = BytesIn[3];
	movf	0+(_BytesIn)+03h,w
	movwf	(??_Process_SPI+0)+0
	movf	(??_Process_SPI+0)+0,w
	movwf	(_DIR)
	line	908
;CoachMasterCode.c: 908: AUX = SendKick;
	movf	(_SendKick),w
	movwf	(??_Process_SPI+0)+0
	movf	(??_Process_SPI+0)+0,w
	movwf	(_AUX)
	line	909
;CoachMasterCode.c: 909: WHIM = SendWhimsy;
	movf	(_SendWhimsy),w
	movwf	(??_Process_SPI+0)+0
	movf	(??_Process_SPI+0)+0,w
	movwf	(_WHIM)
	line	910
	
i1l4182:	
;CoachMasterCode.c: 910: TRANS = 0;
	clrf	(_TRANS)
	line	911
	
i1l1146:	
	line	913
;CoachMasterCode.c: 911: }
;CoachMasterCode.c: 913: BytesOut[1] = SDATA;
	movf	(_SDATA),w
	movwf	(??_Process_SPI+0)+0
	movf	(??_Process_SPI+0)+0,w
	movwf	0+(_BytesOut)+01h
	line	914
	
i1l1147:	
	return
	opt stack 0
GLOBAL	__end_of_Process_SPI
	__end_of_Process_SPI:
;; =============== function _Process_SPI ends ============

	signat	_Process_SPI,88
psect	text438,local,class=CODE,delta=2
global __ptext438
__ptext438:
	global	btemp
	btemp set 07Eh

	DABS	1,126,2	;btemp
	global	wtemp0
	wtemp0 set btemp
	end
