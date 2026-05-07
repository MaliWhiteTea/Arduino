const int buttonPin = A0;
const int yAxisPin = A1; 
const int xAxisPin = A2; 

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
}

void loop() {
  int yValue = analogRead(yAxisPin);
  int xValue = analogRead(xAxisPin);
  bool isPressed = (digitalRead(buttonPin) == HIGH);

  // Direksiyon (X Ekseni) Kontrolü
  String direksiyon = "Merkez";
  if (xValue > 1000) {
    direksiyon = "Sağ";
  } else if (xValue < 100) {
    direksiyon = "Sol";
  }

  // Yön (Y Ekseni) Kontrolü
  String yon = "Merkez";
  if (yValue > 1000) {
    yon = "İleri";
  } else if (yValue < 100) {
    yon = "Geri";
  }

  // Düğme Durumu
  String dugme = isPressed ? "Aktif" : "Deaktif";

  // İstenen formatta Serial ekrana yazdırma
  Serial.print("Direksiyon: ");
  Serial.print(direksiyon);
  Serial.print(" | Yön: ");
  Serial.print(yon);
  Serial.print(" | Düğme: ");
  Serial.println(dugme);

  delay(100); // Ekranın çok hızlı akmasını engellemek için
}