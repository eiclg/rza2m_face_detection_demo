@/*******************************************************************************
@* DISCLAIMER
@* This software is supplied by Renesas Electronics Corporation and is only
@* intended for use with Renesas products. No other uses are authorized. This
@* software is owned by Renesas Electronics Corporation and is protected under
@* all applicable laws, including copyright laws.
@* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING
@* THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT
@* LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
@* AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.
@* TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS
@* ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE
@* FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR
@* ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE
@* BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
@* Renesas reserves the right, without notice, to make changes to this software
@* and to discontinue the availability of this software. By using this software,
@* you agree to the additional terms and conditions found by accessing the
@* following link:
@* http://www.renesas.com/disclaimer
@* Copyright (C) 2018 Renesas Electronics Corporation. All rights reserved.
@*******************************************************************************/
@/*******************************************************************************
@* File Name   : vector_table.asm
@* $Rev: 328 $
@* $Date:: 2018-04-27 09:45:43 +0900#$
@* Description : Vector table
@*******************************************************************************/


@==================================================================
@ Entry point for the Reset handler
@==================================================================
    .section    VECTOR_TABLE, #execinstr, #alloc
    .arm

    .extern  reset_handler

    .global Start
    .global  vector_table

Start:

vector_table:
    LDR pc, =reset_handler          @ +0x0000_0000 : Reset exception
    B   .                           @ +0x0000_0004 : Undefined instructions exception
    B   .                           @ +0x0000_0008 : Software interrupts exceptions
    B   .                           @ +0x0000_000c : Prefetch abort exception
    B   .                           @ +0x0000_0010 : Data abort exception
    B   .                           @ +0x0000_0014 : Reserved
    B   .                           @ +0x0000_0018 : IRQ exception
    B   .                           @ +0x0000_001c : FIQ exception

Literals:
    .LTORG

    .END
