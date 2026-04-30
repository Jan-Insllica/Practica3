#include <WiFi.h>
const char* ssid = "ProjectesSMX";
const char* password = "Hola1234";
Serial.begin(115200);
WiFi.begin(ssid, password);
Serial.print("Connectant...");
while (WiFi.status() != WL_CONNECTED) {
  delay(500);
  Serial.print(".");
}
Serial.println("\n Connectat!");
Serial.print("IP: ");
Serial.println(WiFi.localIP());
