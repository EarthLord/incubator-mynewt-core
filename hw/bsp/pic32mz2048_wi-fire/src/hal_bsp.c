/**
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
#include <assert.h>

#include <syscfg/syscfg.h>

#include <hal/hal_bsp.h>
#include <mcu/mips_hal.h>

#if MYNEWT_VAL(UART_0) || MYNEWT_VAL(UART_1) || MYNEWT_VAL(UART_2) || \
    MYNEWT_VAL(UART_3) || MYNEWT_VAL(UART_4) || MYNEWT_VAL(UART_5)
#include <uart/uart.h>
#include <uart_hal/uart_hal.h>
#endif

#include <bsp/bsp.h>

#include <xc.h>

/* JTAG on, WDT off */
#pragma config JTAGEN=1, FWDTEN=0
/* DMT off, primary oscilator EC mode, PLL */
#pragma config FDMTEN=0, POSCMOD=0, FNOSC=1, DMTCNT=1
/* 24MHz posc input to pll, div by 3, multiply by 50, div by 2 -> 200mhz*/
#pragma config FPLLODIV=1, FPLLMULT=49, FPLLICLK=0, FPLLRNG=1, FPLLIDIV=2
/* USB off */
#pragma config FUSBIDIO=0


#if MYNEWT_VAL(UART_0)
static struct uart_dev os_bsp_uart0;
#endif

#if MYNEWT_VAL(UART_1)
static struct uart_dev os_bsp_uart1;
#endif

#if MYNEWT_VAL(UART_2)
static struct uart_dev os_bsp_uart2;
#endif

#if MYNEWT_VAL(UART_3)
static struct uart_dev os_bsp_uart3;
#endif

#if MYNEWT_VAL(UART_4)
static struct uart_dev os_bsp_uart4;
static const struct mips_uart_cfg uart4_cfg = {
    .tx = MCU_GPIO_PORTF(8),
    .rx = MCU_GPIO_PORTF(2)
};
#endif

#if MYNEWT_VAL(UART_5)
static struct uart_dev os_bsp_uart5;
#endif

const struct hal_flash *
hal_bsp_flash_dev(uint8_t id)
{
    return 0;
}

void
hal_bsp_init(void)
{
    int rc;

    #if MYNEWT_VAL(UART_0)
        rc = os_dev_create((struct os_dev *) &os_bsp_uart0, "uart0",
            OS_DEV_INIT_PRIMARY, 0, uart_hal_init, 0);
        assert(rc == 0);
    #endif

    #if MYNEWT_VAL(UART_1)
        rc = os_dev_create((struct os_dev *) &os_bsp_uart1, "uart1",
            OS_DEV_INIT_PRIMARY, 0, uart_hal_init, 0);
        assert(rc == 0);
    #endif

    #if MYNEWT_VAL(UART_2)
        rc = os_dev_create((struct os_dev *) &os_bsp_uart2, "uart2",
            OS_DEV_INIT_PRIMARY, 0, uart_hal_init, 0);
        assert(rc == 0);
    #endif

    #if MYNEWT_VAL(UART_3)
        rc = os_dev_create((struct os_dev *) &os_bsp_uart3, "uart3",
            OS_DEV_INIT_PRIMARY, 0, uart_hal_init, &uart4_cfg);
        assert(rc == 0);
    #endif

    #if MYNEWT_VAL(UART_4)
        rc = os_dev_create((struct os_dev *) &os_bsp_uart4, "uart4",
            OS_DEV_INIT_PRIMARY, 0, uart_hal_init, 0);
        assert(rc == 0);
    #endif

    #if MYNEWT_VAL(UART_5)
        rc = os_dev_create((struct os_dev *) &os_bsp_uart5, "uart5",
            OS_DEV_INIT_PRIMARY, 0, uart_hal_init, 0);
        assert(rc == 0);
    #endif

    (void)rc;
}

int
hal_bsp_hw_id(uint8_t *id, int max_len)
{
    if (max_len > sizeof(DEVID)) {
        max_len = sizeof(DEVID);
    }

    memcpy(id, &DEVID, max_len);
    return max_len;
}
