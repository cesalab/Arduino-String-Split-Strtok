# Arduino-String-Split-Strtok
String Split with strtok, it's okay!

Se uso para este caso una tarjeta Teensy++ 2.0,
la cual lleva consigo un uC AT90USB1286 a 16MHz.

En la version initial:
Recibe cadena String de puerto serial,
y parte la cadena por medio de delimitadores
por lo que se guardan en un array para uso
posterior por separado...

	por ejemplo, si enviamos la cadena: 
	
	READ MEMORY1
	READ MEMORY2

el resultado es, respectivamente:

	  stringSplit[0]: READ
	  stringSplit[1]: MEMORY1
	Ultimo valor de array util = 1

	  stringSplit[0]: WRITE
	  stringSplit[1]: MEMORY0
	Ultimo valor de array util = 1
