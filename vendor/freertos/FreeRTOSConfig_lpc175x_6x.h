/*
    FreeRTOS V7.3.0 - Copyright (C) 2012 Real Time Engineers Ltd.


    ***************************************************************************
     *                                                                       *
     *    FreeRTOS tutorial books are available in pdf and paperback.        *
     *    Complete, revised, and edited pdf reference manuals are also       *
     *    available.                                                         *
     *                                                                       *
     *    Purchasing FreeRTOS documentation will not only help you, by       *
     *    ensuring you get running as quickly as possible and with an        *
     *    in-depth knowledge of how to use FreeRTOS, it will also help       *
     *    the FreeRTOS project to continue with its mission of providing     *
     *    professional grade, cross platform, de facto standard solutions    *
     *    for microcontrollers - completely free of charge!                  *
     *                                                                       *
     *    >>> See http://www.FreeRTOS.org/Documentation for details. <<<     *
     *                                                                       *
     *    Thank you for using FreeRTOS, and thank you for your support!      *
     *                                                                       *
    ***************************************************************************


    This file is part of the FreeRTOS distribution.

    FreeRTOS is free software; you can redistribute it and/or modify it under
    the terms of the GNU General Public License (version 2) as published by the
    Free Software Foundation AND MODIFIED BY the FreeRTOS exception.
    >>>NOTE<<< The modification to the GPL is included to allow you to
    distribute a combined work that includes FreeRTOS without being obliged to
    provide the source code for proprietary components outside of the FreeRTOS
    kernel.  FreeRTOS is distributed in the hope that it will be useful, but
    WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
    or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
    more details. You should have received a copy of the GNU General Public
    License and the FreeRTOS license exception along with FreeRTOS; if not it
    can be viewed here: http://www.freertos.org/a00114.html and also obtained
    by writing to Richard Barry, contact details for whom are available on the
    FreeRTOS WEB site.

    1 tab == 4 spaces!

    http://www.FreeRTOS.org - Documentation, latest information, license and
    contact details.

    http://www.SafeRTOS.com - A version that is certified for use in safety
    critical systems.

    http://www.OpenRTOS.com - Commercial support, development, porting,
    licensing and training services.
*/

#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

#include <stdint.h>
#include "hal/hal.h"
extern uint32_t SystemCoreClock;

/*-----------------------------------------------------------
 * Application specific definitions.
 *
 * These definitions should be adjusted for your particular hardware and
 * application requirements.
 *
 * THESE PARAMETERS ARE DESCRIBED WITHIN THE 'CONFIGURATION' SECTION OF THE
 * FreeRTOS API DOCUMENTATION AVAILABLE ON THE FreeRTOS.org WEB SITE.
 * http://www.freertos.org/a00110.html
 *----------------------------------------------------------*/

#define configUSE_PREEMPTION			1
#define configMAX_PRIORITIES			( ( unsigned portBASE_TYPE ) 7 )
#define configCPU_CLOCK_HZ				( SystemCoreClock )
#define configTICK_RATE_HZ				( ( portTickType ) 1000 )
#define configMINIMAL_STACK_SIZE		( ( unsigned short ) 90 )
#define configTOTAL_HEAP_SIZE			( ( size_t ) ( 16 * 1024 ) )
#define configMAX_TASK_NAME_LEN			( 32 )
#define configIDLE_SHOULD_YIELD			0
#define configQUEUE_REGISTRY_SIZE		10
#define configUSE_TRACE_FACILITY		1
#define configUSE_16_BIT_TICKS			0
#define configUSE_MUTEXES				1
#define configUSE_CO_ROUTINES 			0
#define configMAX_CO_ROUTINE_PRIORITIES ( 2 )
#define configUSE_COUNTING_SEMAPHORES 	1
#define configUSE_ALTERNATIVE_API 		0
#define configUSE_RECURSIVE_MUTEXES		1

/* Hook function related definitions. */
#define configUSE_TICK_HOOK				0
#define configUSE_IDLE_HOOK				0
#define configUSE_MALLOC_FAILED_HOOK	1
#define configCHECK_FOR_STACK_OVERFLOW	2


/* Software timer related definitions. */
#define configUSE_TIMERS				0
#define configTIMER_TASK_PRIORITY		( configMAX_PRIORITIES - 3 )
#define configTIMER_QUEUE_LENGTH		10
#define configTIMER_TASK_STACK_DEPTH	configMINIMAL_STACK_SIZE

/* Run time stats gathering definitions. */
//void vMainConfigureTimerForRunTimeStats( void );
//uint32_t ulMainGetRunTimeCounterValue( void );
//#define configGENERATE_RUN_TIME_STATS	1
//#define portCONFIGURE_TIMER_FOR_RUN_TIME_STATS() vMainConfigureTimerForRunTimeStats()
//#define portGET_RUN_TIME_COUNTER_VALUE() ulMainGetRunTimeCounterValue()


/* Set the following definitions to 1 to include the API function, or zero
to exclude the API function. */
#define INCLUDE_vTaskPrioritySet			1
#define INCLUDE_uxTaskPriorityGet			1
#define INCLUDE_vTaskDelete					1
#define INCLUDE_vTaskCleanUpResources		0
#define INCLUDE_vTaskSuspend				1
#define INCLUDE_vTaskDelayUntil				1
#define INCLUDE_vTaskDelay					1
#define INCLUDE_uxTaskGetStackHighWaterMark	1
#define INCLUDE_xTimerGetTimerTaskHandle	0
#define INCLUDE_xTaskGetIdleTaskHandle		0
#define INCLUDE_xQueueGetMutexHolder		1

#ifdef DEBUG
	#define configASSERT( x ) if( ( x ) == 0 ) { taskDISABLE_INTERRUPTS(); for( ;; ); }
#endif


/* Use the system definition, if there is one */
#ifdef __NVIC_PRIO_BITS
	#define configPRIO_BITS       __NVIC_PRIO_BITS
#else
	#define configPRIO_BITS       5        /* 32 priority levels */
#endif

/* The maximum priority an interrupt that uses an interrupt safe FreeRTOS API
function can have.  Note that lower priority have numerically higher values.  */
#define configMAX_LIBRARY_INTERRUPT_PRIORITY	( 5 )

/* The minimum possible interrupt priority. */
#define configMIN_LIBRARY_INTERRUPT_PRIORITY	( 31 )

/* The lowest priority. */
#define configKERNEL_INTERRUPT_PRIORITY 		( configMIN_LIBRARY_INTERRUPT_PRIORITY << (8 - configPRIO_BITS) )

/* Priority 5, or 248 as only the top five bits are implemented. */
#define configMAX_SYSCALL_INTERRUPT_PRIORITY 	( configMAX_LIBRARY_INTERRUPT_PRIORITY << (8 - configPRIO_BITS) )

/* Definitions that map the FreeRTOS port interrupt handlers to their CMSIS
standard names. */
#define vPortSVCHandler SVCall_Handler
#define xPortPendSVHandler PendSV_Handler
#define xPortSysTickHandler SysTick_Handler



#endif /* FREERTOS_CONFIG_H */
