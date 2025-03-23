# Práctica 3: Módulo de Retardos No Bloqueantes

## Objetivo
Implementar un módulo de software para trabajar con retardos no bloqueantes a partir de las funciones creadas en la Práctica 2.


## Punto 1: Estructura del Proyecto
- **Nuevo proyecto:** Se crea una copia del proyecto de la Práctica 2.
- **Carpeta API:** Dentro de la carpeta `Drivers`, se crea la carpeta `API` que contiene dos subcarpetas:
  - **/Inc:** Para los archivos de encabezado.
  - **/Src:** Para los archivos fuente.

> **Nota para Eclipse:** Al agregar nuevas carpetas, se deben incluir en el *include path* para que sus archivos de encabezado se compilen correctamente.

## Módulo API_delay
Este módulo encapsula las funciones necesarias para gestionar retardos no bloqueantes.

## Punto 2: Programa de Titilado del LED

Implementar un programa para la placa NUCLEO-F4xx que utilice retardos no bloqueantes y haga titilar (parpadear) un LED siguiendo la secuencia predeterminada:

```c
const uint32_t TIEMPOS[] = {500, 100, 100, 1000};
```

> **NOTA**: los tiempos indicados son de encendido y el led debe trabajar con duty = 50%

## Punto 3: Implementar función auxiliar pública en API_delay.c

```c
bool_t delayIsRunning(delay_t * delay);
```

Esta función debe devolver una copia del valor del campo running de la estructura delay_t

Utilizar esta función en el código implementado para el punto dos para verificar que el delay no esté corriendo antes de cambiar su valor con delayWrite.


## Autor
- Fernando Folmer