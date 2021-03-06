/*******************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only
* intended for use with Renesas products. No other uses are authorized. This
* software is owned by Renesas Electronics Corporation and is protected under
* all applicable laws, including copyright laws.
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING
* THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT
* LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
* AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.
* TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS
* ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE
* FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR
* ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE
* BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software
* and to discontinue the availability of this software. By using this software,
* you agree to the additional terms and conditions found by accessing the
* following link:
* http://www.renesas.com/disclaimer
* Copyright (C) 2018 Renesas Electronics Corporation. All rights reserved.
*******************************************************************************/
/*******************************************************************************
* File Name : driver.h
* $Rev: 639 $
* $Date:: 2018-09-11 13:29:59 +0900#$
* Description :
******************************************************************************/

#ifndef DRIVER_H_
#define DRIVER_H_

#include "r_typedefs.h"

/** Unique ID. */
    #define STDIO_DRIVER_RZ_LLD_UID                (9999)

/* This is so the low level open function can tell the difference between a
   file and a device:
   Device name \\.\myDevice
   file name a:\myFile.txt
*/
#define DEVICE_INDENTIFIER          "\\\\.\\"

/* Common id descriptors for specifying channel support in low layer drivers */
typedef enum
{
    R_CH0  = (0x01 <<  0),  /*!< Reference channel 0 of associated driver */
    R_CH1  = (0x01 <<  1),  /*!< Reference channel 1 of associated driver */
    R_CH2  = (0x01 <<  2),  /*!< Reference channel 2 of associated driver */
    R_CH3  = (0x01 <<  3),  /*!< Reference channel 3 of associated driver */
    R_CH4  = (0x01 <<  4),  /*!< Reference channel 4 of associated driver */
    R_CH5  = (0x01 <<  5),  /*!< Reference channel 5 of associated driver */
    R_CH6  = (0x01 <<  6),  /*!< Reference channel 6 of associated driver */
    R_CH7  = (0x01 <<  7),  /*!< Reference channel 7 of associated driver */
    R_CH8  = (0x01 <<  8),  /*!< Reference channel 8 of associated driver */
    R_CH9  = (0x01 <<  9),  /*!< Reference channel 9 of associated driver */
    R_CH10 = (0x01 << 10),  /*!< Reference channel 10 of associated driver */
    R_CH11 = (0x01 << 11),  /*!< Reference channel 11 of associated driver */
    R_CH12 = (0x01 << 12),  /*!< Reference channel 12 of associated driver */
    R_CH13 = (0x01 << 13),  /*!< Reference channel 13 of associated driver */
    R_CH14 = (0x01 << 14),  /*!< Reference channel 14 of associated driver */
    R_CH15 = (0x01 << 15),  /*!< Reference channel 15 of associated driver */
    R_CH_ANY = (0xFFFF)     /*!< Reference ANY available channel of associated driver */
} e_channel_id_t;

/******************************************************************************
Typedef definitions
******************************************************************************/
/* Common id descriptors for specifying smart configuration index 32 possible configurations supported  */
typedef enum
{
    R_SC0  = (0x00),  /*!< Reference smart configuration index  0 of associated driver */
    R_SC1,            /*!< Reference smart configuration index  1 of associated driver */
    R_SC2,            /*!< Reference smart configuration index  2 of associated driver */
    R_SC3,            /*!< Reference smart configuration index  3 of associated driver */
    R_SC4,            /*!< Reference smart configuration index  4 of associated driver */
    R_SC5,            /*!< Reference smart configuration index  5 of associated driver */
    R_SC6,            /*!< Reference smart configuration index  6 of associated driver */
    R_SC7,            /*!< Reference smart configuration index  7 of associated driver */
    R_SC8,            /*!< Reference smart configuration index  8 of associated driver */
    R_SC9,            /*!< Reference smart configuration index  9 of associated driver */
    R_SC10,           /*!< Reference smart configuration index 10 of associated driver */
    R_SC11,           /*!< Reference smart configuration index 11 of associated driver */
    R_SC12,           /*!< Reference smart configuration index 12 of associated driver */
    R_SC13,           /*!< Reference smart configuration index 13 of associated driver */
    R_SC14,           /*!< Reference smart configuration index 14 of associated driver */
    R_SC15,           /*!< Reference smart configuration index 15 of associated driver */
    R_SC16,           /*!< Reference smart configuration index 16 of associated driver */
    R_SC17,           /*!< Reference smart configuration index 17 of associated driver */
    R_SC18,           /*!< Reference smart configuration index 18 of associated driver */
    R_SC19,           /*!< Reference smart configuration index 19 of associated driver */
    R_SC20,           /*!< Reference smart configuration index 20 of associated driver */
    R_SC21,           /*!< Reference smart configuration index 21 of associated driver */
    R_SC22,           /*!< Reference smart configuration index 22 of associated driver */
    R_SC23,           /*!< Reference smart configuration index 23 of associated driver */
    R_SC24,           /*!< Reference smart configuration index 24 of associated driver */
    R_SC25,           /*!< Reference smart configuration index 25 of associated driver */
    R_SC26,           /*!< Reference smart configuration index 26 of associated driver */
    R_SC27,           /*!< Reference smart configuration index 27 of associated driver */
    R_SC28,           /*!< Reference smart configuration index 28 of associated driver */
    R_SC29,           /*!< Reference smart configuration index 29 of associated driver */
    R_SC30,           /*!< Reference smart configuration index 30 of associated driver */
    R_SC31,           /*!< Reference smart configuration index 31 of associated driver */
} e_sc_id_t;

/******************************************************************************
Typedef definitions
******************************************************************************/

typedef enum _CTLCODE
{
    CTL_FILE_SEEK = 0,
    CTL_FILE_SIZE,
    CTL_GET_VERSION,
    CTL_GET_LAST_ERROR,
    CTL_GET_ERROR_STRING,
    CTL_WDT_RESET,
    CTL_GET_TIME_STAMP,
    CTL_SET_OVERLAPPED_READ_EVENT,
    CTL_GET_OVERLAPPED_READ_RESULT,
    CTL_CANCEL_OVERLAPPED_READ,
    CTL_SET_OVERLAPPED_WRITE_EVENT,
    CTL_GET_OVERLAPPED_WRITE_RESULT,
    CTL_CANCEL_OVERLAPPED_WRITE,
    CTL_SET_TIME_OUT,
    CTL_GET_TIME_OUT,
    CTL_USB_ATTACHED,
    CTL_USB_MS_RESET,
    CTL_USB_MS_GET_MAX_LUN,
    CTL_USB_MS_CLEAR_BULK_IN_STALL,
    CTL_USB_MS_WAIT_MUTEX,
    CTL_USB_MS_RELEASE_MUTEX,
    CTL_SCI_SET_CONFIGURATION,
    CTL_SCI_GET_CONFIGURATION,
    CTL_SCI_GET_LINE_STATUS,
    CTL_SCI_PURGE_BUFFERS,
    CTL_SCI_SET_BREAK,
    CTL_SCI_CLEAR_BREAK,
    CTL_GET_RX_BUFFER_COUNT,
    CTL_GET_STDIN_EVENT,
    CTL_GET_DATE,
    CTL_SET_DATE,
    CTL_GET_MOUSE_DATA,
    CTL_GET_SPEAKER_VOLUME,
    CTL_SET_SPEAKER_VOLUME,
    CTL_INC_SPEAKER_VOLUME,
    CTL_DEC_SPEAKER_VOLUME,
    CTL_SET_SPEAKER_MUTE,
    CTL_GET_SPEAKER_SAMPLE_RATE,
    CTL_SET_MEDIA_ACCESS_CONTROL_ADDRESS,
    CTL_SET_OVERLAPPED_WRITE_EVENT_UDP_TX_COE,
    CTL_SET_OVERLAPPED_WRITE_EVENT_TCP_TX_COE,
    CTL_OVERLAPPED_PACKET_FORWARD,
    CTL_SET_START_OFFSETS,
    CTL_GET_LINK_STATE,
    CTL_GET_LINK_CHANGE_EVENT,
    CTL_MAC_AUTO_LOAD_CHECK,
    CTL_SET_PORT_NUMBER,
    CTL_SET_LWIP_SOCKET_INDEX,
    CTL_GET_LWIP_SOCKET_INDEX,
    CTL_SET_PROMISCUOUS_MODE,
    CTL_GET_PROMISCUOUS_MODE,
    CTL_SET_LINK_INDICATOR,
    CTL_SET_SYN_PORT_CFG,
    CTL_GET_FIRST_OVERLAPPED_READ_EVENT,
    CTL_GET_OVERLAPPED_READ_EVENT,
    CTL_GET_OVERLAPPED_WRITE_EVENT,
    CTL_STREAM_REQUIRES_AUTHENTICATION,
    CTL_STREAM_SET_CONNECTION_IDLE_CALL_BACK,
    CTL_STREAM_SET_INPUT_PREPARSER,
    CTL_STREAM_UDP_TCP,
    CTL_STREAM_TCP,
    CTL_STREAM_TCP_CONNECTED,
    CTL_GET_STREAM_PAIR_NAME,
    CTL_HID_KEYBOARD,
    CTL_BLANK_CHECK,
    CTL_CLEAR_LCD_SCREEN,
    CTL_SET_LCD_OUTPUT_CURSOR,
    CTL_SET_LCD_USER_CURSOR,
    CTL_SET_LCD_CURSOR_STYLE,
    CTL_SET_MM_DRV,
    CTL_SET_OS_DRV,
    CTL_USBF_IS_CONNECTED,
    CTL_USBF_SET_RW_MODE,
    CTL_USBF_SET_CONFIGURATION,
    CTL_USBF_GET_CONFIGURATION,
    CTL_USBF_SEND_HID_REPORTIN,
    CTL_USBF_START,
    CTL_USBF_STOP,
    /* TODO: add device specific control functions here */
    /* must be last control code, dynamic driver will reuse
       control code from this point forward */
    CTL_NEXT_FREE

} CTLCODE;

typedef struct st_def_driver_t *st_driver_ptr_t;

typedef struct st_def_stream_t *st_stream_ptr_t;


/* Version Information for drivers (high or low level little endian) */
typedef struct
{
    union
    {
        uint32_t full;      /*!< Major + Minor combined as 1 uint32_t data member  */
        struct
        {
          uint16_t minor;    /*!< Version, modified by Product Owner  */
          uint16_t major;    /*!< Version, modified by developer  */
        } sub;
    } version;
    uint32_t build;          /*!< Build Number Generated during the release   */

    /* The driver name */
    const char   *p_szdriver_name;
} st_drv_info_t;

/*!< Common error codes supported by all drivers */
typedef enum
{
    DRV_SUCCESS = 0,    /*!< No Error  */
    DRV_ERROR   = (-1), /*!< General error  */
} e_err_code_t;


/******************************************************************************
 * Version Info Structure
 ******************************************************************************/
typedef struct
{
    st_drv_info_t hld;
    st_drv_info_t lld;
} st_ver_info_t, *st_ver_info_ptr_t;

/* Define the structure of the functions to access the device driver */
typedef struct st_r_driver_intern_t
{
    /* The driver name */
    const char   *const p_device_name;

    /* The driver open function */
    int_t (*const open)(st_stream_ptr_t pStream);

    /* The driver close function */
    void (*const close)(st_stream_ptr_t pStream);

    /* The driver read function */
    int_t (*const read)(st_stream_ptr_t pStream, uint8_t *pbyBuffer, uint32_t uiCount);

    /* The driver write function */
    int_t (*const write)(st_stream_ptr_t pStream, const uint8_t * pbyBuffer, uint32_t uiCount);

    /* A driver control function to handle all other driver specific
       functions */
    int_t (*const control)(st_stream_ptr_t pStream, uint32_t ctlCode, void *pCtlStruct);

    /* The driver version (updated by developer) */
    int_t (*const get_version)(st_stream_ptr_t pStream, st_ver_info_t *pVerInfo);

} st_r_driver_t;


/* Define the structure of the table to hold a pointer to the device driver
   functions, pointer to any driver specific data, pointer to the file and
   access options */
typedef struct st_def_stream_t
{
    st_r_driver_t * p_device_driver;
    st_r_driver_t * p_driver;
    char_t  *p_stream_name;
    void    *p_extension;
#if defined( __RX )
    long    iFileNumber;
    long    iFileMode;
    long    iFileFlag;
#else
    int_t   file_number;
    int_t   file_mode;
    int_t   file_flag;
#endif
    e_sc_id_t sc_config_index;
} st_stream_t;

#if 0
/**
 * @typedef DRIVER_IF_CONTROL Common Control Interface controls shared across all drivers
 */
typedef enum
{
	CTL_FILE_SEEK = (STDIO_DRIVER_RZ_LLD_UID<<16) +  0, /*!< File Seek control */
} e_ctrl_code_driver_t;
#endif

/******************************************************************************
Macro definitions
******************************************************************************/


/******************************************************************************
Function Prototypes
******************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif
extern  int_t no_dev_open(st_stream_ptr_t pStream);
extern  void no_dev_close(st_stream_ptr_t pStream);
extern  int_t no_dev_read(st_stream_ptr_t pStream, uint8_t *pbyBuffer, uint32_t uiCount);
extern  int_t no_dev_write(st_stream_ptr_t pStream, const uint8_t *pbyBuffer, uint32_t uiCount);
extern  int_t no_dev_control(st_stream_ptr_t pStream, uint32_t ctlCode, void *pCtlStruct);
extern  int_t no_dev_get_version(st_stream_ptr_t pStream, st_ver_info_ptr_t info_ptr);


#ifdef __cplusplus
}
#endif


#endif /* DRIVER_H_ */

