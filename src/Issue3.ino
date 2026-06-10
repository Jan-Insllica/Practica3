#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "ProjectesSMX";
const char* password = "Hola1234";

WebServer server(80);

void enviarPaginaPrincipal() {

  String html = "<html><head><meta charset='UTF-8'>";
  html += "<style>";
  html += "body{font-family:sans-serif;text-align:center;}";
  html += ".card{padding:20px;color:white;display:inline-block;margin:10px;border-radius:10px;}";
  html += "</style>";
  html += "</head><body>";

  html += "<h1>Monitor CPD</h1>";
  html += "<div class='card' style='background:gray;'>";
  html += "<h3>Temp</h3>";
  html += "<p>-- °C</p>";
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
