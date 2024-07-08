#include <xc.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include "CVRlcd.h"

// Function to initialize the LCD
/**
 * Inicialización del LCD
 * Actualice los valores de TRISxx en caso de que estos
 * sean modificados en CVRlcd.h
 */
void LCDInit(void) {
    
    TRISBbits.TRISB5 = 0;
    TRISBbits.TRISB4 = 0;
    TRISBbits.TRISB3 = 0;
    TRISBbits.TRISB2 = 0;
    TRISBbits.TRISB1 = 0;
    TRISBbits.TRISB0 = 0;

    // Secuencia de inicialización
    __delay_ms(20); // Esperar el encendido del lcd / Wait for LCD to power up
    LCDCommand(0x02); // Inicializa el LCD en modo 4-bits / Initialize LCD in 4-bit mode
    LCDCommand(0x28); // Se establece: / modo 4-bits, 2 lineas, 5x7 punto Function set: 4-bit mode, 2 lines, 5x7 dots
    LCDCommand(0x0C); // Display Encendido, cursor apagado / Display on, cursor off
    LCDCommand(0x06); // Modo de entrada: Incremento del cursor, sin desplazamiente /Entry mode set: increment cursor, no shift
    LCDCommand(0x01); // Limpiar displat / Clear display
    __delay_ms(2); // Espera a que el comando limpiar display esté limpio / Wait for clear display command to complete
}

//Funcion para enviar comandos al LCD / Function to send a command to the LCD 
void LCDCommand(unsigned char cmd) {
    RS = 0; // RS = 0 para modo comando

    // Envio de la parte alta del byte
    D4 = (cmd >> 4) & 0x01;
    D5 = (cmd >> 5) & 0x01;
    D6 = (cmd >> 6) & 0x01;
    D7 = (cmd >> 7) & 0x01;
    E = 1;
    __delay_us(1);
    E = 0;
    __delay_us(1);

    // Envio de la parte baja del byte
    D4 = cmd & 0x01;
    D5 = (cmd >> 1) & 0x01;
    D6 = (cmd >> 2) & 0x01;
    D7 = (cmd >> 3) & 0x01;
    E = 1;
    __delay_us(1);
    E = 0;
    __delay_us(1);
}



// Función para enviar un caracter al LCDFunction to write a character to the LCD
void LCDWriteChar(char data) {
    RS = 1; // RS = 1 para modo dato

    // Envio de la parte alta del byte
    D4 = (data >> 4) & 0x01;
    D5 = (data >> 5) & 0x01;
    D6 = (data >> 6) & 0x01;
    D7 = (data >> 7) & 0x01;
    E = 1;
    __delay_us(1);
    E = 0;
    __delay_us(1);

    // Envio de la parte baja del byte
    D4 = data & 0x01;
    D5 = (data >> 1) & 0x01;
    D6 = (data >> 2) & 0x01;
    D7 = (data >> 3) & 0x01;
    E = 1;
    __delay_us(1);
    E = 0;
    __delay_us(1);
}

// Función para escribir un String en el LCD / Function to write a string to the LCD
void LCDWriteString(char *str) {
    while (*str) {
        LCDWriteChar(*str++);
    }
}

// Función para establecer la posición del cursor / Function to set the cursor position
void LCDSetCursor(unsigned char row, unsigned char column) {
    unsigned char address;

    // Determina la dirección basado en la fila y la columna
    if (row == 1) {
        address = 0x80 + (column - 1);
    } else if (row == 2) {
        address = 0xC0 + (column - 1);
    }

    // Send the address command
    LCDCommand(address);
}

// Función para realizar scroll hacia la derecha
void LCDScrollLeft(void) {
    LCDCommand(0x18); // Comando para realizar scroll hacia la izquierda
}

// Función para realizar scroll hacia la derecha
void LCDScrollRight(void) {
    LCDCommand(0x1C); // 
}

/**
 * @brief Crea un carácter personalizado en el LCD.
 *
 * Esta función almacena un patrón de carácter personalizado en una
 * ubicación específica de la CGRAM del controlador HD44780.
 *
 * @param location La ubicación en la CGRAM (0-7) donde se almacenará el carácter.
 * @param charmap Un array de 8 bytes que representa el patrón del carácter.
 */
void LCDCreateChar(unsigned char location, unsigned char charmap[]) {
    location &= 0x07; // We only have 8 locations 0-7
    LCDCommand(0x40 | (location << 3)); // Set CGRAM address
    
    for (int i = 0; i < 8; i++) {
        LCDWriteChar(charmap[i]); // Write the character pattern to CGRAM
    }
    LCDCommand(0x80); // Return to DDRAM mode
}

void LCDClear(void){
    LCDCommand(0x01); // Limpiar displat / Clear displayLCDCommand(0x01); // Limpiar displat / Clear display
    __delay_ms(2); // Espera a que el comando limpiar display esté limpio / Wait for clear display command to complete
}