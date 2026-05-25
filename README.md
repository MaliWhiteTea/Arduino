# Arduino Projeleri

Bu depo, Arduino ve uyumlu kartlar için geliştirilmiş küçük deney ve test sketch'lerini içerir. Her proje kendi klasöründe bağımsız bir `.ino` dosyası olarak durur; birbirine bağlı değildir.

## Gereksinimler

- [Arduino IDE](https://www.arduino.cc/en/software) veya PlatformIO
- Uygun Arduino / Deneyap kartı ve ilgili sensör veya modül
- Seri Monitör için **9600 baud** (tüm sketch'lerde ortak)

### Harici kütüphaneler

| Proje | Kütüphane |
|-------|-----------|
| `RFID_BULUCU` | [MFRC522](https://github.com/miguelbalboa/rfid) (`#include <MFRC522.h>`) |
| Diğerleri | Yalnızca yerleşik `Wire` (`AS5600-test`) veya standart Arduino API |

Kütüphane yöneticisinden **MFRC522** arayıp yükleyebilirsiniz.

## Projeler

### RFID_BULUCU

MFRC522 RFID okuyucu modülü ile kart UID'sini seri porta yazar.

| Bağlantı | Pin |
|----------|-----|
| RST | 9 |
| SS (SDA) | 10 |
| SPI | Varsayılan SPI pinleri |

**Çıktı örneği:** `Kart UID:  04 A1 B2 C3`

Kart okunduktan sonra tekrarlı okumayı azaltmak için `PICC_HaltA()` kullanılır.

---

### JOYSTICK

Analog joystick ve buton okuması; yön ve buton durumu Türkçe metin olarak seri porta gönderilir.

| Sinyal | Pin |
|--------|-----|
| Buton | A0 |
| Y ekseni | A1 |
| X ekseni | A2 |

Eşik değerleri: X/Y > 1000 → sağ/ileri, < 100 → sol/geri; arada **Merkez**. Buton `HIGH` iken **Aktif**.

**Çıktı örneği:** `Direksiyon: Sağ | Yön: İleri | Düğme: Deaktif`

---

### A0PINOkuyucu

Potansiyometre (veya analog sensör) değerini okur ve 0–1023 aralığında seri porta basar.

| Bağlantı | Pin |
|----------|-----|
| Orta bacak (sinyal) | **A2** |

Okuma aralığı `delay(100)` ile sınırlandırılmıştır.

---

### DCMOTORSURUCU

**Deneyap Kart 1A** üzerinde çift yönlü DC motor sürücü testi. PWM kullanılmaz; yalnızca dijital HIGH/LOW ile yön değiştirilir.

| Motor çıkışı | Pin |
|--------------|-----|
| Motor 1 | D0 |
| Motor 2 | D1 |

**Davranış:** 3 sn ileri → 2 sn dur → 3 sn geri → 2 sn dur (döngü).

---

### AS5600-test

AS5600 manyetik açı sensöründen I2C ile ham ve derece cinsinden açı okur.

| Parametre | Değer |
|-----------|--------|
| I2C adresi | `0x36` |
| Açı yazmacı | `0x0E` (üst byte) |

**Çıktı örneği:** `Ham Deger: 2048 | Aci: 180.00 derece`

Okuma hatasında bağlantı kontrolü için uyarı mesajı verilir.

## Kurulum ve yükleme

1. Depoyu klonlayın veya indirin.
2. Arduino IDE'de **Dosya → Aç** ile ilgili klasördeki `.ino` dosyasını açın (ör. `RFID_BULUCU/RFID_BULUCU.ino`).
3. **Araçlar → Kart** ve **Araçlar → Port** ile doğru kartı ve COM portunu seçin.
4. Gerekli kütüphaneyi yükleyin (`RFID_BULUCU` için MFRC522).
5. **Yükle** ile sketch'i karta aktarın.
6. **Araçlar → Seri Monitör**'ü **9600** baud ile açın (seri çıktı veren projeler için).

## Klasör yapısı

```
Arduino/
├── RFID_BULUCU/
│   └── RFID_BULUCU.ino
├── JOYSTICK/
│   └── JOYSTICK.ino
├── A0PINOkuyucu/
│   └── A0PINOkuyucu.ino
├── DCMOTORSURUCU/
│   └── DCMOTORSURUCU.ino
├── AS5600-test/
│   └── AS5600-test.ino
└── README.md
```

## Notlar

- `DCMOTORSURUCU` Deneyap Kart 1A pin tanımları (`D0`, `D1`) içindir; standart Uno'da pin numaralarını donanımınıza göre güncellemeniz gerekir.
- `A0PINOkuyucu` klasör adı analog pin okuyucuyu çağrıştırsa da sketch'te okuma pini **A2** olarak tanımlıdır.
- Motor ve RFID testlerinde güç kaynağı ve kablolama polaritesine dikkat edin.
