#ifndef _FUNCONFIG_H
#define _FUNCONFIG_H

// board definition file will already take care of this
//#define CH32V003           1

// #define FUNCONF_USE_PLL 1               // Use built-in 2x PLL 
// #define FUNCONF_USE_HSI 1               // Use HSI Internal Oscillator
// #define FUNCONF_USE_HSE 0               // Use External Oscillator
// #define FUNCONF_HSITRIM 0x10            // Use factory calibration on HSI Trim.
// #define FUNCONF_SYSTEM_CORE_CLOCK 48000000  // Computed Clock in Hz (Default only for 003, other chips have other defaults)
// #define FUNCONF_HSE_BYPASS 0            // Use HSE Bypass feature (for oscillator input)
// #define FUNCONF_USE_CLK_SEC	1			// Use clock security system, enabled by default
// #define FUNCONF_USE_DEBUGPRINTF 1
// #define FUNCONF_USE_UARTPRINTF  0
// #define FUNCONF_NULL_PRINTF 0           // Have printf but direct it "nowhere"
// #define FUNCONF_SYSTICK_USE_HCLK 0      // Should systick be at 48 MHz (1) or 6MHz (0) on an '003.  Typically set to 0 to divide HCLK by 8.
// #define FUNCONF_TINYVECTOR 0            // If enabled, Does not allow normal interrupts.
// #define FUNCONF_UART_PRINTF_BAUD 115200 // Only used if FUNCONF_USE_UARTPRINTF is set.
// #define FUNCONF_DEBUGPRINTF_TIMEOUT 0x80000 // Arbitrary time units, this is around 120ms.
// #define FUNCONF_ENABLE_HPE 1            // Enable hardware interrupt stack.  Very good on QingKeV4, i.e. x035, v10x, v20x, v30x, but questionable on 003. 
//                                         // If you are using that, consider using INTERRUPT_DECORATOR as an attribute to your interrupt handlers.
// #define FUNCONF_USE_5V_VDD 0            // Enable this if you plan to use your part at 5V - affects USB and PD configration on the x035.
// #define FUNCONF_DEBUG_HARDFAULT    1    // Log fatal errors with "printf"

// 1. 启用CH32V103芯片（必选）
#define CH32V10x           1

// 2. 时钟配置（保证波特率计算正确，默认即可）
#define FUNCONF_USE_HSI 1               // 使用内部振荡器（稳定，无需外部晶振）
#define FUNCONF_SYSTEM_CORE_CLOCK 80000000  // 核心时钟48MHz（CH32V003默认）

// 3. 开启串口打印（核心宏）
#define FUNCONF_USE_UARTPRINTF  1       // 开启串口printf重定向
#define FUNCONF_UART_PRINTF_BAUD 115200 // 串口波特率（根据你的串口工具调整，如9600/115200）

// 4. 可选：关闭无关配置（避免冲突）
#define FUNCONF_NULL_PRINTF 0           // 禁止"空打印"（确保输出到串口）
#define FUNCONF_USE_DEBUGPRINTF 0       // 若只用UART打印，可关闭debugprintf


#define FUNCONF_SYSTICK_USE_HCLK 1      // Should systick be at 48 MHz (1) or 6MHz (0) on an '003.  Typically set to 0 to divide HCLK by 8.


#if defined(CH32H41x)
#define MODE_OUTPUT GPIO_CNF_OUT_PP, GPIO_Speed_180MHz
#else
#define MODE_OUTPUT GPIO_Speed_10MHz | GPIO_CNF_OUT_PP
#endif


#endif


