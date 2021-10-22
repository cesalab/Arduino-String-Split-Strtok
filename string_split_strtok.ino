#include <String.h>
#define MAX_CHAR 50
#define MAX_ARRAY 10

String incomingString;  // for incoming serial data
String stringSplit[MAX_ARRAY] = {""};   // arrary to save values
char delimitadores[] = " ,;!()";
char *resultado = nullptr;
char *strtok( char *str1, const char *str2 ); 

void setup() 
{
      Serial.begin(115200);
}

void loop () {
      if (Serial.available() > 0) {
          // read the incoming byte:
          incomingString = Serial.readString() ;
          //Serial.print("I received: ");
          //Serial.println(incomingString);
          char colle[MAX_CHAR];
          uint8_t i = 0;
          
          incomingString.toCharArray(colle, MAX_CHAR);
          resultado = strtok( colle, delimitadores );
          stringSplit [i] = resultado;
          
          while( resultado != NULL ) 
          {
              i++;
              resultado = strtok( NULL, delimitadores );
              stringSplit[i] = resultado;
          }
          //imprimir array de palabras
          for (i = 0; i < MAX_ARRAY; i++){
              if (stringSplit[i] == "")     break;
              Serial.print("  stringSplit["); Serial.print(i); Serial.print("]: "); Serial.println(stringSplit[i]);
          }
          //revisamos cual es el ultimo lugar del array
          Serial.print("Ultimo valor de array util = ");   Serial.print (--i);    
          Serial.println("\n");
          
          for(i = 0; i < MAX_ARRAY; i++)   stringSplit[i] = "";             
      }
}
