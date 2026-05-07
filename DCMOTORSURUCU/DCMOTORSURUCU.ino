/* * Deneyap Kart 1A - Basit Motor Testi (PWM YOK)
 * Amaç: Donanım sağlamlığını test etmek.
 */

const int motorPin1 = D0; 
const int motorPin2 = D1;

void setup() {
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  
  // Başlangıçta ikisini de kapat (Motor durmalı)
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  delay(2000); // 2 saniye bekle
}

void loop() {
  // İLERİ DÖN
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  delay(3000);

  // DUR
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  delay(2000);

  // GERİ DÖN
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  delay(3000);
  
  // DUR
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  delay(2000);
}