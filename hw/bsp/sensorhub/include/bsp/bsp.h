/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 * 
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */
#ifndef H_BSP_H
#define H_BSP_H

#include <inttypes.h>
#include <mcu/mcu.h>
#include <syscfg/syscfg.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Define special stackos sections */
#define sec_data_core   __attribute__((section(".data.core")))
#define sec_bss_core    __attribute__((section(".bss.core")))
#define sec_bss_nz_core __attribute__((section(".bss.core.nz")))

/* More convenient section placement macros. */
#define bssnz_t         sec_bss_nz_core

/* System SRAM */
extern uint8_t _ram_start;
#define RAM_SIZE        (192 * 1024)
/* System CCM (core coupled memory) data RAM. */
extern uint8_t _ccram_start;
#define CCRAM_SIZE      (64 * 1024)

/* 4KB of backup SRAM, accessible only from the CPU. 
 * Protected and retained in Standby or VBAT mode. 
 */ 
#define BACKUPRAM_SIZE  (4 * 1024)

/* LED pins */
#define LED_BLINK_PIN   MCU_GPIO_PORTD(12)

/* UART pins */
#define UART_CNT 1
#define CONSOLE_UART 	"uart0"

#if MYNEWT_VAL(BOOT_SERIAL)
#define BOOT_SERIAL_DETECT_PIN          16 /* on Sensor Hub board BOOT0 is dedicated! */
#define BOOT_SERIAL_DETECT_PIN_CFG      HAL_GPIO_PULL_UP
#define BOOT_SERIAL_DETECT_PIN_VAL      0

#define BOOT_SERIAL_REPORT_PIN          LED_BLINK_PIN
#define BOOT_SERIAL_REPORT_FREQ         (MYNEWT_VAL(OS_CPUTIME_FREQ) / 4)
#endif

#define NFFS_AREA_MAX    (8)

#ifdef __cplusplus
}
#endif

#endif  /* H_BSP_H */
