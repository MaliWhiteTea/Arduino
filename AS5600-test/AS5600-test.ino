#include <Wire.h>

const int AS5600_ADDRESS = 0x36; // AS5600 varsayılan I2C adresi
const int ANGLE_REGISTER_HIGH = 0x0E; // Ham açı verisinin başlangıç yazmacı

void setup() {
  Serial.begin(9600);
  Wire.begin(); // I2C haberleşmesini başlat
  
  Serial.println("AS5600 Testi Basliyor...");
}

void loop() {
  // Açı yazmacından veri okumak için sensöre istek gönder
  Wire.beginTransmission(AS5600_ADDRESS);
  Wire.write(ANGLE_REGISTER_HIGH);
  Wire.endTransmission();

  // Sensörden 2 byte veri talep et
  Wire.requestFrom(AS5600_ADDRESS, 2);

  if (Wire.available() == 2) {
    int highByte = Wire.read();
    int lowByte = Wire.read();

    // 12-bit ham değeri birleştir
    int rawAngle = (highByte << 8) | lowByte;

    // Ham değeri (0-4095) dereceye (0-360) dönüştür
    float angleDegrees = (rawAngle * 360.0) / 4096.0;

    Serial.print("Ham Deger: ");
    Serial.print(rawAngle);
    Serial.print(" | Aci: ");
    Serial.print(angleDegrees, 2); // Virgülden sonra 2 hane yazdır
    Serial.println(" derece");
  } else {
    Serial.println("Sensor okuma hatasi! Baglantilari kontrol et.");
  }
  
  delay(100); // Okumalar arası bekleme süresi
}