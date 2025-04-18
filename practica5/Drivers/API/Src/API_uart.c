#include "API_uart.h"
#include <string.h>
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_uart.h"

#define UART_INSTANCE USART2
#define UART_BAUDRATE 115200
#define UART_TIMEOUT_SEND 1000
#define UART_TIMEOUT_RECEIVE 1


static UART_HandleTypeDef huart_;
static const char *uartInitMessage = "UART Initialized with config 8N1\r\n";

uint32_t getBaudRate(){
	return UART_BAUDRATE;
}

bool_t uartInit() {
    bool_t ret = false;
    huart_.Instance = UART_INSTANCE;
    huart_.Init.BaudRate = UART_BAUDRATE;
    huart_.Init.WordLength = UART_WORDLENGTH_8B;
    huart_.Init.StopBits = UART_STOPBITS_1;
    huart_.Init.Parity = UART_PARITY_NONE;
    huart_.Init.Mode = UART_MODE_TX_RX;
    huart_.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    huart_.Init.OverSampling = UART_OVERSAMPLING_16;
    if (HAL_UART_Init(&huart_) != HAL_OK) {
        ret = false; // Initialization failed
    } else {
        uartSendString((uint8_t *)uartInitMessage);
        ret = true;
        // UART initialized successfully
    }
    return ret;
}

void uartSendString(uint8_t * pstring) {
	if (pstring == NULL) return;
    HAL_UART_Transmit(&huart_, pstring, strlen((char *)pstring), UART_TIMEOUT_SEND);
}

void uartSendStringSize(uint8_t * pstring, uint16_t size) {
	if (pstring == NULL || size == 0) return;
    HAL_UART_Transmit(&huart_, pstring, size, UART_TIMEOUT_SEND);
}

void uartReceiveStringSize(uint8_t * pstring, uint16_t size) {
	if (pstring == NULL || size <= 0) return;
    HAL_UART_Receive(&huart_, pstring, size, UART_TIMEOUT_RECEIVE);
}
