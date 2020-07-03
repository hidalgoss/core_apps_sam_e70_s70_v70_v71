/*******************************************************************************
  MPLAB Harmony Application Header File

  Company:
    Microchip Technology Inc.

  File Name:
    app_sst26.h

  Summary:
    This header file provides prototypes and definitions for the application.

  Description:
    This header file provides function prototypes and data type definitions for
    the application.  Some of these are required by the system (such as the
    "APP_SST26_Initialize" and "APP_SST26_Tasks" prototypes) and some of them are only used
    internally by the application (such as the "APP_SST26_STATES" definition).  Both
    are defined here for convenience.
*******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/
//DOM-IGNORE-END

#ifndef APP_SST26_H
#define APP_SST26_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "configuration.h"
#include "system/fs/sys_fs.h"
#include "osal/osal.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

extern "C" {

#endif
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Type Definitions
// *****************************************************************************
// *****************************************************************************
#define BUFFER_SIZE                (4096U)

// *****************************************************************************
/* Application states

  Summary:
    Application states enumeration

  Description:
    This enumeration defines the valid application states.  These states
    determine the behavior of the application at various times.
*/

typedef enum
{
    /* The app mounts the disk */
    APP_SST26_MOUNT_DISK = 0,

    /* The app formats the disk. */
    APP_SST26_FORMAT_DISK,

    /* The app opens the file */
    APP_SST26_OPEN_FILE,

    /* The app writes data to the file */
    APP_SST26_WRITE_TO_FILE,

    /* The app performs a file sync operation. */
    APP_SST26_FLUSH_FILE,

    /* The app checks the file status */
    APP_SST26_READ_FILE_STAT,

    /* The app checks the file size */
    APP_SST26_READ_FILE_SIZE,

    /* The app does a file seek to the end of the file. */
    APP_SST26_DO_FILE_SEEK,

    /* The app checks for EOF */
    APP_SST26_CHECK_EOF,

    /* The app does another file seek, to move file pointer to the beginning of
     * the file. */
    APP_SST26_DO_ANOTHER_FILE_SEEK,

    /* The app reads and verifies the written data. */
    APP_SST26_READ_FILE_CONTENT,

    /* The app closes the file. */
    APP_SST26_CLOSE_FILE,

    /* The app unmounts the disk. */
    APP_SST26_UNMOUNT_DISK,

    /* The app idles */
    APP_SST26_IDLE,

    /* An app error has occurred */
    APP_SST26_ERROR

} APP_SST26_STATES;

// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    Application strings and buffers are be defined outside this structure.
 */

typedef struct
{
    /* SYS_FS File handle */
    SYS_FS_HANDLE fileHandle;

    /* Application's current state */
    APP_SST26_STATES state;

    SYS_FS_FSTAT fileStatus;

    long fileSize;

    /* Read Buffer */
    uint8_t readBuffer[BUFFER_SIZE];

    /* Write Buffer*/
    uint8_t writeBuffer[BUFFER_SIZE];

} APP_SST26_DATA;

extern APP_SST26_DATA appSST26Data;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Routines
// *****************************************************************************
// *****************************************************************************
/* These routines are called by drivers when certain events occur.
*/

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_SST26_Initialize ( void )

  Summary:
     MPLAB Harmony application initialization routine.

  Description:
    This function initializes the Harmony application.  It places the
    application in its initial state and prepares it to run so that its
    APP_SST26_Tasks function can be called.

  Precondition:
    All other system initialization routines should be called before calling
    this routine (in "SYS_Initialize").

  Parameters:
    None.

  Returns:
    None.

  Example:
    <code>
    APP_SST26_Initialize();
    </code>

  Remarks:
    This routine must be called from the SYS_Initialize function.
*/

void APP_SST26_Initialize ( void );


/*******************************************************************************
  Function:
    void APP_SST26_Tasks ( void )

  Summary:
    MPLAB Harmony Demo application tasks function

  Description:
    This routine is the Harmony Demo application's tasks function.  It
    defines the application's state machine and core logic.

  Precondition:
    The system and application initialization ("SYS_Initialize") should be
    called before calling this.

  Parameters:
    None.

  Returns:
    None.

  Example:
    <code>
    APP_SST26_Tasks();
    </code>

  Remarks:
    This routine must be called from SYS_Tasks() routine.
 */

void APP_SST26_Tasks( void );


#endif /* APP_SST26_H */

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END
