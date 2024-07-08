/************************************************************************
 *                        CVR ELECTRONICA                               *
 *                     WWW.CVRELECTRONICA.COM                           *
 * Libreria para el manejo de pantallas con el controlador HD44780      *
 * Referencias probadas: 0802,1602. En general debería funcionar        *
 * con cualquier pantalla que esté basada en el controlador con         *
 * pocas modificaciones.                                                *
 * Encuentra la documentacion de esta y más librerías en el repositorio *
 * o en cvrelectronica.com                                              *
 *                                                                      *
 * Escrita por Cristian Valdez R.                                       *
 * V1 - 3/julio de 2024                                                 *
 ************************************************************************/

#ifndef CVRLCD1602_H
#define CVRLCD1602_H

#include <xc.h>

#define _XTAL_FREQ 20000000

/**
 * Estos pines hacen referencia a los pines a los que
 * estará conectada la placa
 * Por default se usaron los pines del PUERTOB
 * RS -> B4
 * E  -> B5
 * D4 -> B0
 * D5 -> B1
 * D6 -> B2
 * D7 -> B3
 * 
 * Estos pines tambien deben ser modificados en el archivo CVRlcd.c
 * en caso de que sean modiicados en este archivo
 */
#define RS LATBbits.LATB4
#define E  LATBbits.LATB5
#define D4 LATBbits.LATB0
#define D5 LATBbits.LATB1
#define D6 LATBbits.LATB2
#define D7 LATBbits.LATB3

void LCDInit(void);
void LCDCommand(unsigned char cmd);
void LCDWriteChar(char data);
void LCDWriteString(char *str);
void LCDSetCursor(unsigned char row, unsigned char column);
void LCDScrollLeft(void);
void LCDScrollRight(void);
void LCDCreateChar(unsigned char location, unsigned char charmap[]);
void LCDClear(void);
#endif 
