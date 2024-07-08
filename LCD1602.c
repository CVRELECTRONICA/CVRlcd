/*
 * File:   LCD1602.c
 * Author: titia
 *
 * Created on 3 de julio de 2024, 10:47 AM
 */
#pragma config FOSC = HS        // Oscillator Selection (HS Oscillator, High-speed crystal/resonator connected between OSC1 and OSC2 pins)
#pragma config WDTE = OFF        // Watchdog Timer Enable (WDT enabled)
#pragma config PWRTE = ON       // Power-up Timer Enable (PWRT enabled)
#pragma config MCLRE = ON       // MCLR Pin Function Select (MCLR/VPP pin function is MCLR)
#pragma config CP = OFF         // Flash Program Memory Code Protection (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Memory Code Protection (Data memory code protection is disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable (Brown-out Reset enabled)
#pragma config CLKOUTEN = OFF   // Clock Out Enable (CLKOUT function is disabled. I/O or oscillator function on the CLKOUT pin)
#pragma config IESO = ON        // Internal/External Switchover (Internal/External Switchover mode is enabled)
#pragma config FCMEN = ON      // Fail-Safe Clock Monitor Enable (Fail-Safe Clock Monitor is enabled)

// CONFIG2
#pragma config WRT = OFF        // Flash Memory Self-Write Protection (Write protection off)
#pragma config VCAPEN = OFF     // Voltage Regulator Capacitor Enable (All VCAP pin functionality is disabled)
#pragma config PLLEN = OFF      // PLL Enable (4x PLL disabled)
#pragma config STVREN = OFF     // Stack Overflow/Underflow Reset Enable (Stack Overflow or Underflow will not cause a Reset)
#pragma config BORV = LO        // Brown-out Reset Voltage Selection (Brown-out Reset Voltage (Vbor), low trip point selected.)
#pragma config LVP = OFF        // Low-Voltage Programming Enable (High-voltage on MCLR/VPP must be used for programming)

#define _XTAL_FREQ 20000000
#include <xc.h>
#include <stdio.h>
#include "CVRlcd.h"

char b[50];

unsigned char bluetoothChar[8] = {
  0b00110,
  0b00101,
  0b10101,
  0b01110,
  0b00110,
  0b01101,
  0b10101,
  0b00110
};

void main(void) {
    
    TRISB = 0;
    LCDInit();
    LCDCreateChar(0, bluetoothChar);
    
   
    while(1){
        
       // Escribir en el LCD
        LCDSetCursor(1, 3);
        LCDWriteString("Hola, Mundo!");
        __delay_ms(2000);
        
        LCDClear();
        
        LCDSetCursor(1, 1);
        LCDWriteString("TEST LIBRERIA");
        LCDSetCursor(2, 1);
        LCDWriteString("CVR ELECTRONICA");
        __delay_ms(2000);

        LCDClear();

        LCDSetCursor(1, 1);
        LCDWriteString("A contar!");
        for(int i=0; i< 200; i++){
            LCDSetCursor(2, 1);
            sprintf(b,"Counteo: %d",i);
            LCDWriteString(b);
            __delay_ms(10);
        }
        
        LCDClear();
        __delay_ms(200);
        LCDSetCursor(1, 1);
        LCDWriteString("Puedes mostrar un texto largo y hacer scroll");
        for(int i=0; i< 40; i++){
        LCDScrollLeft();
        __delay_ms(300);
        }
        
        LCDClear();
        __delay_ms(200);
        
        LCDSetCursor(1, 1);
        LCDWriteString("Mas productos en WWW.CVRELECTRONICA.COM");
        for(int i=0; i< 30; i++){
        LCDScrollRight();
        __delay_ms(300);
        }
        
        LCDClear();
        __delay_ms(200);
        
        LCDSetCursor(1, 1);
        LCDWriteString("Caracter");
        LCDSetCursor(2, 1);
        LCDWriteString("personalizado: ");
        LCDWriteChar(0);
        
        __delay_ms(3000);
        LCDClear();
        LCDClear();
        LCDClear();
    }
    return;
}
