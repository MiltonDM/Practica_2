// Incluímos la libreria externa para poder utilizarla
#include <LiquidCrystal.h>
// Se instancia el LCD con los pines indicados
LiquidCrystal lcd(7, 8, 9, 10, 11, 12); //    ( RS, EN, d4, d5, d6, d7)

int ledOpen = 13;//salida del led en el pin 13
int ledClose = 6;//salida del led en el pin 6
int switchReed = 5;//salida del Reed SW en el pin 5
int buzzer = 4;//salida del Buzzer en el pin 4
//Esta función nos sirve para hacer una configuración
//inicial en nuestros programas
void setup() {
  // Se configuran los pines de los LEDs como salidas y se ponen a 0.
  pinMode(ledOpen, OUTPUT); //Establecer LED como salida
  pinMode(ledClose, OUTPUT); //Establecer LED como salida
  pinMode(switchReed, INPUT);//Establecer el sensor como entrada
  pinMode(buzzer, OUTPUT);//Establecer Buzzer como salida
  Serial.begin(9600);// Configuración monitor serie
  lcd.begin(16, 2);//Pantalla de 20 caracteres y  lineas
  lcd.print("Alarma Seguridadad");// Se imprime la pantalla de inicio:
}

void loop() {
  if (digitalRead(switchReed) == HIGH) {//verificar si la entrada esta ALTA
    digitalWrite(ledOpen, LOW);// apaga el LED
    digitalWrite(ledClose, HIGH);// enciende el LED
    digitalWrite(buzzer, HIGH);// enciende el buzzer
    lcd.setCursor(0, 0);// Situamos el cursor en la columna 0 fila 0 del LCD
    lcd.print("Alerta activada!");// Escribimos Alerta!!!!!!
  }
  else {
    digitalWrite(ledOpen, HIGH);// enciende el LED
    digitalWrite(ledClose, LOW);// apaga el LED
    digitalWrite(buzzer, LOW);// apaga el buzzer
    lcd.setCursor(0, 0);// Situamos el cursor en la columna 0 fila 0 del LCD
    lcd.print("Desactivada!");// Escribimos Desactivada!!!!!!
  }
  delay(1);
}


