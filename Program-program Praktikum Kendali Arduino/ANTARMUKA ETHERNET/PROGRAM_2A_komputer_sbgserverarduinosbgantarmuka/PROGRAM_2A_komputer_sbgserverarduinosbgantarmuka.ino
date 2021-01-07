#include <SPI.h>
#include <Ethernet.h>

byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
IPAddress ip(192, 168, 1,1);

//IP address server yang dituju:
IPAddress server(192,168,1,10);

EthernetClient client; //arduino sebagai client

void setup() {
  Ethernet.begin(mac,ip);
  Serial.begin(9600);
  while (!Serial) {
    ;
  }
// delay untuk inisialisasi:
delay(1000);
Serial.println("connecting...");

if (client.connect(server, 10002)) {
  Serial.println("connected");
} else  { 
  Serial.println("connecting failed");
 }
}

void loop() {
  if(client.available()) {
    char c = client.read();
    Serial.print(c);
  }
  //Selama komunikasi serial terbentuk dan ada data,
  //maka data dibaca dan dikirimkan ke socket:
  while (Serial.available() > 0) {
    char inChar = Serial.read();
    if (client.connected()) {
      client.print(inChar) ;
    }
  }
  //jika server disconnected, maka stop client :
  if (!client.connected()) {
    Serial.println();
    Serial.println("disconnecting.");
    client.stop();
    while (true) ;
  }
}
