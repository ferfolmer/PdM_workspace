#ifndef API_UART_H
#define API_UART_H

#include <stdint.h>
#include <stdbool.h>
#include "API_delay.h"

/**
 * @brief inicializes the UART peripheral and prints the UART configuration to the console.
 * 
 * @return bool_t true if the UART was initialized successfully, false otherwise.
 * @note This function configures the UART peripheral with the following settings:
 * - Baud rate: 115200 bps
 * - Word length: 8 bits
 * - Stop bits: 1
 * - Parity: None
 */
bool_t uartInit();

/**
 * @brief Sends a byte of data over UART.
 * 
 * @param pstring string to be sent over UART.
 * @note This function uses the HAL_UART_Transmit function to send the data.
 */
void uartSendString(uint8_t * pstring);

/**
 * @brief Sends as many bytes of data as specified by the size parameter over UART.
 * 
 * @param pstring string to be sent over UART.
 * @param size number of bytes to be sent over UART.
 * @note This function uses the HAL_UART_Transmit function to send the data.
 */
void uartSendStringSize(uint8_t * pstring, uint16_t size);

/**
 * @brief Receives as many bytes of data as specified by the size parameter over UART.
 * 
 * @param pstring string to be received over UART.
 * @param size number of bytes to be received over UART.
 * @note This function uses the HAL_UART_Receive function to receive the data.  
 */
void uartReceiveStringSize(uint8_t * pstring, uint16_t size);



#endif // API_UART_H
