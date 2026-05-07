#include <SPI.h>
#include <MFRC522.h>

// Pin tanımlamaları
#define RST_PIN   9    
#define SS_PIN    10   

// MFRC522 nesnesini oluştur
MFRC522 mfrc522(SS_PIN, RST_PIN);  

void setup() {
  Serial.begin(9600);   // Seri haberleşmeyi başlat
  while (!Serial);      // Seri portun açılmasını bekle
  
  SPI.begin();          // SPI veri yolunu başlat
  mfrc522.PCD_Init();   // MFRC522 modülünü başlat
  
  Serial.println("Lutfen RFID kartinizi okutun...");
}

void loop() {
  // Yeni bir kart okunmadıysa döngünün başına dön
  if ( ! mfrc522.PICC_IsNewCardPresent()) {
    return;
  }

  // Kartın seri numarası (UID) okunamadıysa döngünün başına dön
  if ( ! mfrc522.PICC_ReadCardSerial()) {
    return;
  }

  // Kartın UID'sini ekrana yazdır
  Serial.print("Kart UID: ");
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    // Okunan baytları HEX formatında yazdır
    // Eğer bayt 0x10'dan küçükse başa '0' ekleyerek formatı koru
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
  }
  
  Serial.println(); // Alt satıra geç

  // Aynı kartın sürekli peş peşe okunmasını engellemek için modülü uykuya al
  mfrc522.PICC_HaltA();
}