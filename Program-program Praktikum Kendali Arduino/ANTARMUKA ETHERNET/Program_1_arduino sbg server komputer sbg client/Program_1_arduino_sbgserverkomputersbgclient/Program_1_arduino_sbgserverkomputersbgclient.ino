#include <SPI.h>
#include <Ethernet.h>

int A=1;
byte mac[] = {0x8C, 0xEC, 0x4B, 0x7D, 0xA0, 0x08};
IPAddress ip(192, 168, 1,1);
EthernetServer server(80);

void setup() {
  Serial.begin(9600);
  while (!Serial){
    ;
  }
  Ethernet.begin(mac,ip);
  server.begin();
}

void loop() {
  if(A>100) {
    A=1;
  }
  EthernetClient client = server.available() ;
  if (client) {
    Serial.println("New client");
    boolean currentLineIsBlank = true;
    while (client.connected()) {
      if (client.available()){
        char c = client.read();
        if (c == '\n' && currentLineIsBlank) {
          client.println("HTTP/1.1 200 OK") ;
          client.println("Content-Type: text/html");
          client.println("Connection: close");
          client.println("Refresh: 1");

          //kode html
          client.println();
          client.println("<!DOCTYPE HTML>");
          client.println("<html>");
          client.println("<H2>");
          client.println("Sistem Antarmuka dan Akuisisi Data berbasis Ethernet <p />");
          client.print("Data di server: ");
          client.print(A);
          client.println("</H2>");
          client.println("</html>");
          break;
          }
          if (c=='\n'){
            currentLineIsBlank = true;
          }
          else if(c != '\r') {
            currentLineIsBlank = false;
          }
        }
      }
      delay(1);
      client.stop();
      Serial.println("client disconnected");
    }
    A++;
    delay(2000);
  }
