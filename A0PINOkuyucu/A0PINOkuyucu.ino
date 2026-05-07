// Potansiyometrenin orta bacağının bağlı olduğu analog pin
const int potPin = A2; 

// Okunan değeri saklayacağımız değişken
int potDeger = 0; 

void setup() {
  // Bilgisayar ile Arduino arasındaki seri iletişimi 9600 baud hızında başlatıyoruz
  Serial.begin(9600);
}

void loop() {
  // A0 pinindeki gerilimi okuyup (0-1023 arası) değişkene kaydediyoruz
  potDeger = analogRead(potPin);

  // Okunan değeri Seri Monitör'e alt satıra geçerek yazdırıyoruz
  Serial.println(potDeger);

  // Okumaların çok hızlı akıp ekranı dondurmaması için 100 milisaniye bekleme ekliyoruz
  delay(100); 
}