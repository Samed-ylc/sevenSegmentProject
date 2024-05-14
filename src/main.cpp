#include <Arduino.h>

// 7 Segment Display pinleri
int segA = 2;
int segB = 3;
int segC = 4;
int segD = 5;
int segE = 6;
int segF = 7;
int segG = 8;

// Ortak Katot pinleri
int katot1 = 9;
int katot2 = 10;
int katot3 = 11;

// Buton pini
int butonPin = 12;

// Sayı dizisi
int sayilar[] = {123, 456, 789, 159, 753, 246, 380, 612};
int sayiIndex = 0;

void setup() {
  // Segment pinlerini çıkış olarak ayarla
  pinMode(segA, OUTPUT);
  pinMode(segB, OUTPUT);
  pinMode(segC, OUTPUT);
  pinMode(segD, OUTPUT);
  pinMode(segE, OUTPUT);
  pinMode(segF, OUTPUT);
  pinMode(segG, OUTPUT);

  // Katot pinlerini çıkış olarak ayarla
  pinMode(katot1, OUTPUT);
  pinMode(katot2, OUTPUT);
  pinMode(katot3, OUTPUT);

  // Buton pinini giriş olarak ayarla
  pinMode(butonPin, INPUT_PULLUP);
}

void showNumber(int sayi) {
  // Sayının basamaklarını ayır
  void showDigit(int digit, int katot); // Declare the function 'showDigit' before calling it

  int birler = sayi % 10;
  int onlar = (sayi / 10) % 10;
  int yuzler = sayi / 100;

  // Birler basamağını göster
  showDigit(birler, katot1);
  delay(5); // Görüntü kararlılığı için

  // Onlar basamağını göster
  showDigit(onlar, katot2);
  delay(5);

  // Yüzler basamağını göster
  showDigit(yuzler, katot3);
  delay(5);
}

void showDigit(int digit, int katot) {
  // Tüm segmentleri kapat
  digitalWrite(segA, LOW);
  digitalWrite(segB, LOW);
  digitalWrite(segC, LOW);
  digitalWrite(segD, LOW);
  digitalWrite(segE, LOW);
  digitalWrite(segF, LOW);
  digitalWrite(segG, LOW);

  // Digit değerine göre segmentleri aç
  switch (digit) {
    case 0:
      digitalWrite(segA, HIGH);
      digitalWrite(segB, HIGH);
      digitalWrite(segC, HIGH);
      digitalWrite(segD, HIGH);
      digitalWrite(segE, HIGH);
      digitalWrite(segF, HIGH);
      break;
    case 1:
      digitalWrite(segB, HIGH);
      digitalWrite(segC, HIGH);
      break;
    case 2:
      digitalWrite(segA, HIGH);
      digitalWrite(segB, HIGH);
      digitalWrite(segD, HIGH);
      digitalWrite(segE, HIGH);
      digitalWrite(segG, HIGH);
      break;
    case 3:
      digitalWrite(segA, HIGH);
      digitalWrite(segB, HIGH);
      digitalWrite(segC, HIGH);
      digitalWrite(segD, HIGH);
      digitalWrite(segG, HIGH);
      break;
    case 4:
      digitalWrite(segB, HIGH);
      digitalWrite(segC, HIGH);
      digitalWrite(segF, HIGH);
      digitalWrite(segG, HIGH);
      break;
    case 5:
      digitalWrite(segA, HIGH);
      digitalWrite(segC, HIGH);
      digitalWrite(segD, HIGH);
      digitalWrite(segF, HIGH);
      digitalWrite(segG, HIGH);
      break;
    case 6:
      digitalWrite(segA, HIGH);
      digitalWrite(segC, HIGH);
      digitalWrite(segD, HIGH);
      digitalWrite(segE, HIGH);
      digitalWrite(segF, HIGH);
      digitalWrite(segG, HIGH);
      break;
    case 7:
      digitalWrite(segA, HIGH);
      digitalWrite(segB, HIGH);
      digitalWrite(segC, HIGH);
      break;
    case 8:
      digitalWrite(segA, HIGH);
      digitalWrite(segB, HIGH);
      digitalWrite(segC, HIGH);
      digitalWrite(segD, HIGH);
      digitalWrite(segE, HIGH);
      digitalWrite(segF, HIGH);
      digitalWrite(segG, HIGH);
      break;
    case 9:
      digitalWrite(segA, HIGH);
      digitalWrite(segB, HIGH);
      digitalWrite(segC, HIGH);
      digitalWrite(segD, HIGH);
      digitalWrite(segF, HIGH);
      digitalWrite(segG, HIGH);
      break;
  }

  digitalWrite(katot, LOW); // Ortak katodu aktif et
  delay(1); // Görüntü kararlılığı için
  digitalWrite(katot, HIGH); // Ortak katodu deaktif et
}

void loop() {
  // Buton kontrolü
  if (digitalRead(butonPin) == LOW) {
    sayiIndex = (sayiIndex + 1) % 8; // Bir sonraki sayıya geç
    delay(200); // Debounce
  }

  // 3 basamaklı sayıyı göster
  showNumber(sayilar[sayiIndex]);
}
