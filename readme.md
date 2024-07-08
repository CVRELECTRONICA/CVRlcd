## LIBRERÍA PARA EL MANEJO DE PANTALLAS LCD 1602 (CVRLcd)

Esta librería permite el control completo de la pantalla lcd 1602 basadas en el controlador HD44780 usando cuatro pines de datos y dos pines de contro.

[![Display LCD 2x16](https://cvrelectronica.com/productos/imagenes/display2x16.jpg)](https://cvrelectronica.com)

- Mostrar carcteres
- Desplazar el contenido de la pantalla
- Crear tus propios carcteres

### Funciones de la librería
* void LCDInit(void);
* void LCDCommand(unsigned char cmd);
* void LCDWriteChar(char data);
* void LCDWriteString(char *str);
* void LCDSetCursor(unsigned char row, unsigned char column);
* void LCDScrollLeft(void);
* void LCDScrollRight(void);
* void LCDCreateChar(unsigned char location, unsigned char charmap[]);
* void LCDClear(void);

# IMPORTANTE!
Para cambiar los pines que controloarán la pantalla deberás editarlos en los archivos **CVRLcd.c y CVRLcd.h** <br>
por defecto las conexiones están definidas así:

| Pin Lcd | Pin Microcontrolador |
|---------|----------------------|
| RS      | RB4                  |
| EN      | RB5                  |
| D7      | RB3                  |
| D6      | RB2                  |
| D5      | RB1                  |
| D4      | RB0                  |

#### Use el main.c como referencia para resover sus dudas sobre el uso de las funciones de la libería.

Esta librería ha sido probada en placas MayaBoard basadas en el PIC16F886 y el PIC16F1936. Si quieres [conocer más sobre MayaBoard ingresa aquí](https://cvrelectronica.com/mayaboard)
[![MayaBoard By CVR](https://cvrelectronica.com/productos/imagenes/Mayaboard.png)](https://cvrelectronica.com)

# 🚨 Solución a posibles inconvenientes
* Verifica que tu microcontroladores esté trabajando correctamente (Carga un blink)
* Verifica la alimentacion del lcd
* Verifica el contraste de la pantalla (Recuerda el el lcd usa una resitencia o potenciómetro conectado al pin VEE)
* Verifica que los pines conectados coincidan con los declarados en los archivos **CVRLcd.c** y **CVRLcd.h**

## Soporte:
_*✉️ develop@cvrelectronica.com*_ <br>
_*💬 (+57) 301 546 8124 whatsApp*_ <br>
*ww.cvrelectronica.com*