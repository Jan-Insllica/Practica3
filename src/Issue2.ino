#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "ProjectesSMX";
const char* password = "Hola1234";

WebServer server(80);

void enviarPaginaPrincipal() {
  server.send(200, "text/plain", "Hola, soc el teu ESP32");
}

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);

  Serial.print("Connectant...");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConnectat!");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());

  server.on("/", enviarPaginaPrincipal);
  server.begin();
}

void loop() {
  server.handleClient();
}
