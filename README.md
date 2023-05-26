# HC-06BT
HC-06 BT Module how to using

1. İlk olarak, HC-06 modülünü Arduino Uno'ya fiziksel olarak bağlamak için şu adımları izleyin:
   - HC-06 modülünün VCC pini, Arduino Uno'nun 5V pinine bağlanmalıdır.
   - HC-06 modülünün GND pini, Arduino Uno'nun GND pinine bağlanmalıdır.
   - HC-06 modülünün TX (transmit) pini, Arduino Uno'nun RX (receive) pinine bağlanmalıdır. (Örnekte 2 numaralı pine bağlanmıştır)
   - HC-06 modülünün RX (receive) pini, Arduino Uno'nun TX (transmit) pinine bağlanmalıdır. (Örnekte 3 numaralı pine bağlanmıştır)
   - Bu bağlantılar, Arduino Uno'nun dijital pinlerini kullanarak yapılmıştır.

2. Arduino Uno'yu bilgisayarınıza bağlayın ve Arduino IDE'yi açın.

3. Arduino IDE'de yeni bir boş proje açın.

4. HC-06 modülünün bağlantılarını sağladıktan sonra, HC-06 modülüne bağlanmak için SoftwareSerial kütüphanesini kullanacağız. Bu kütüphaneyi projeye dahil etmek için şu kod satırını projenin en üstüne ekleyin:
   ```
   #include <SoftwareSerial.h>
   ```

5. Ardından, HC-06 modülü için bir SoftwareSerial nesnesi oluşturun ve RX ve TX pinlerini belirtin:
   ```
   SoftwareSerial bluetooth(2, 3); // RX pini 2, TX pini 3 olarak belirtilmiştir
   ```

6. `setup()` fonksiyonunda, seri iletişim hızını belirleyin ve Bluetooth modülünü başlatın:
   ```
   void setup() {
     Serial.begin(9600); // Seri iletişim hızını 9600 baud olarak ayarlıyoruz
     bluetooth.begin(9600); // Bluetooth modülünü 9600 baud ile başlatıyoruz
   }
   ```

7. `loop()` fonksiyonunda, Bluetooth modülünden veri almak ve göndermek için gerekli kodları yazın:
   ```
   void loop() {
     if (bluetooth.available()) {
       char receivedData = bluetooth.read();
       Serial.print("Alınan veri: ");
       Serial.println(receivedData);
     }
     
     if (Serial.available()) {
       char sendData = Serial.read();
       bluetooth.print(sendData);
     }
   }
   ```

8. Tüm kodu yazdıktan sonra, Arduino Uno'ya yükleyin ve HC-06 modülü ile haberleşmek için başka bir Bluetooth cihazı kullanabilirsiniz. Arduino Uno'yu Bluetooth cihazınızla eşleştirin ve ardından veri alışverişi yapabilirsiniz.
