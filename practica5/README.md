# Práctica 5: Implementación de un Módulo de Software para UART

## Objetivo
Desarrollar un módulo de software para utilizar la UART, implementando funcionalidades básicas de transmisión y recepción de datos, así como funcionalidades adicionales para interactuar con la terminal.

---

## Descripción de la Práctica

### Punto 1: Implementación del Módulo UART
Se implementó un módulo de software en los archivos `API_uart.c` y `API_uart.h`, ubicados en las carpetas `/API/src` y `/API/inc`, respectivamente.

#### Funciones Públicas
Las siguientes funciones públicas se definieron en `API_uart.h`:
- **`bool_t uartInit()`**: Inicializa la UART e imprime los parámetros de configuración en la terminal. Devuelve `true` si la inicialización es exitosa, y `false` en caso contrario.
- **`void uartSendString(uint8_t *pstring)`**: Envía un string completo por la UART utilizando `HAL_UART_Transmit(...)`.
- **`void uartSendStringSize(uint8_t *pstring, uint16_t size)`**: Envía un string de tamaño específico por la UART utilizando `HAL_UART_Transmit(...)`.
- **`void uartReceiveStringSize(uint8_t *pstring, uint16_t size)`**: Recibe un string de tamaño específico por la UART utilizando `HAL_UART_Receive(...)`.

#### Consideraciones de Implementación
- **Validación de Parámetros**: Se verifica que los punteros no sean `NULL` y que los valores de tamaño sean razonables.
- **Verificación de Retornos**: Se validan los valores de retorno de todas las funciones de la HAL utilizadas.
- **Mensaje de Inicialización**: `uartInit()` imprime un mensaje con los parámetros de configuración de la UART al inicializarse.

---

### Punto 2: Detección de Flancos
Se integró el módulo UART con el programa de la práctica 4 para informar al usuario sobre flancos ascendentes y descendentes detectados. 
- **Flanco Ascendente**: Se envía el mensaje `"Flanco ascendente detectado"`.
- **Flanco Descendente**: Se envía el mensaje `"Flanco descendente detectado"`.
- Cada mensaje se escribe en una nueva línea en la terminal.

---

### Punto 3: Funcionalidad Adicional 
Se agregó una funcionalidad para borrar el contenido de la terminal y responder con los parámetros de configuración de la UART al recibir el carácter `'c'` desde la terminal de la PC.
- **Borrar Terminal**: Se implementó una función para limpiar la terminal.
- **Respuesta con Configuración**: El microcontrolador responde con al menos cuatro parámetros de configuración de la UART en un formato legible.
- **Estrategia de Respuesta**: Se asegura que el sistema no pierda peticiones ni genere reportes no solicitados.

---

## Autor
Fernando Folmer