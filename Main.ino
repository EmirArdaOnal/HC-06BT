#include <SoftwareSerial.h> // HC-06 modülü için SoftwareSerial kütüphanesini dahil ediyoruz

SoftwareSerial bluetooth(2, 3); // RX pini 2, TX pini 3 olarak belirtilmiştir

void setup() {
  Serial.begin(9600); // Seri iletişim hızını 9600 baud olarak ayarlıyoruz
  bluetooth.begin(9600); // Bluetooth modülünü 9600 baud ile başlatıyoruz
}

void loop() {
  if (bluetooth.available()) { // Bluetooth modülünden veri varsa
    char receivedData = bluetooth.read(); // Veriyi okuyoruz
    Serial.print("Alınan veri: ");
    Serial.println(receivedData); // Alınan veriyi seri monitöre yazdırıyoruz
  }
  
  if (Serial.available()) { // Seri monitörden veri varsa
    char sendData = Serial.read(); // Veriyi okuyoruz
    bluetooth.print(sendData); // Veriyi Bluetooth modülüne gönderiyoruz
  }
}
