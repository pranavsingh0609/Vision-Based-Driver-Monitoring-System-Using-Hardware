#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int irSensor = 2;


int motorA1 = 8;
int motorA2 = 9;
int enableA = 10;


int led1 = 3;
int led2 = 5;
int led3 = 6;
int led4 = 11;


int buzzer = 7;

void setup() {
  pinMode(irSensor, INPUT);

  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(enableA, OUTPUT);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);

  pinMode(buzzer, OUTPUT);

  lcd.init();
  lcd.backlight();

  lcd.print("System Ready");
  delay(2000);
  lcd.clear();
}

void loop() {
  int sensorValue = digitalRead(irSensor);

  if (sensorValue == HIGH) {
    

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("DROWSY ALERT!");

    // Stop motor
    digitalWrite(motorA1, LOW);
    digitalWrite(motorA2, LOW);
    digitalWrite(enableA, LOW);

    // Hazard LEDs ON
    analogWrite(led1, 60);
    analogWrite(led2, 60);
    analogWrite(led3, 60);
    analogWrite(led4, 60);

    // Buzzer ON
    digitalWrite(buzzer, HIGH);

    delay(400);

    // OFF
    analogWrite(led1, 0);
    analogWrite(led2, 0);
    analogWrite(led3, 0);
    analogWrite(led4, 0);

    digitalWrite(buzzer, LOW);

    delay(400);
  }
  else {
    

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Driver Awake....");

    // Motor ON
    digitalWrite(motorA1, HIGH);
    digitalWrite(motorA2, LOW);
    digitalWrite(enableA, HIGH);

    // LEDs OFF
    analogWrite(led1, 0);
    analogWrite(led2, 0);
    analogWrite(led3, 0);
    analogWrite(led4, 0);

    // Buzzer OFF
    digitalWrite(buzzer, LOW);
  }
}
