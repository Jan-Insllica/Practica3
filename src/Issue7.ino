#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "ProjectesSMX";
const char* password = "Hola1234";

WebServer server(80);

const int pinLDR = 35;
const int pinLM35 = 34;
const int LED = 27;

void enviarPaginaPrincipal() {

  int valorLDR = analogRead(pinLDR);
  float tempC = (analogRead(pinLM35) * 5.0 / 4095.0) * 100.0;

  String colorTemp = "#28a745";

  digitalWrite(LED, LOW);

  if (tempC > 24.0) {
    colorTemp = "#dc3545";
    digitalWrite(LED, HIGH);
  }

  String html = "<html><head>";
  html += "<meta charset='UTF-8'>";
  html += "<meta http-equiv='refresh' content='5'>";
  html += "</head><body>";

  html += "<h1>Monitor CPD</h1>";

  html += "<div style='background:" + colorTemp + ";padding:20px;color:white;border-radius:10px;'>";
  html += "<h3>Temperatura</h3>";
  html += "<p>" + String(tempC, 1) + " °C</p>";
  html += "</div>";

  html += "<p>LDR: " + String(valorLDR) + "</p>";

  html += "<p><a href='/credits'>Crèdits</a></p>";

  html += "</body></html>";

  server.send(200, "text/html", html);
}

void credits() {
  server.send(
    200,
    "text/html",
    "<h1>Fet per Dani</h1><a href='/'>Tornar</a>"
  );
}

void setup() {
  Serial.begin(115200);

  pinMode(LED, OUTPUT);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }

  server.on("/", enviarPaginaPrincipal);
  server.on("/credits", credits);

  server.begin();
}

void loop() {
  server.handleClient();
}
