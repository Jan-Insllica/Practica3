#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "ProjectesSMX";
const char* password = "Hola1234";

WebServer server(80);

const int pinLDR = 35;
const int pinLM35 = 34;

void enviarPaginaPrincipal() {

  int valorLDR = analogRead(pinLDR);
  float tempC = (analogRead(pinLM35) * 5.0 / 4095.0) * 100.0;

  String html = "<html><head>";
  html += "<meta charset='UTF-8'>";
  html += "<meta http-equiv='refresh' content='5'>";
  html += "<style>";
  html += "body{font-family:sans-serif;text-align:center;}";
  html += ".card{padding:20px;color:white;display:inline-block;margin:10px;border-radius:10px;background:gray;}";
  html += "</style>";
  html += "</head><body>";

  html += "<h1>Monitor CPD</h1>";

  html += "<div class='card'>";
  html += "<h3>Temperatura</h3>";
  html += "<p>" + String(tempC, 1) + " °C</p>";
  html += "</div>";

  html += "<div class='card'>";
  html += "<h3>LDR</h3>";
  html += "<p>" + String(valorLDR) + "</p>";
  html += "</div>";

  html += "</body></html>";

  server.send(200, "text/html", html);
}

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }

  server.on("/", enviarPaginaPrincipal);
  server.begin();
}

void loop() {
  server.handleClient();
}
