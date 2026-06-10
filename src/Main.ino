#include <WiFi.h>
#include <WebServer.h>

// ===== WIFI =====
const char* ssid = "Jan";
const char* password = "Jan12345678";

// ===== SERVIDOR WEB =====
WebServer server(80);

// ===== SENSORES =====
const int pinLDR = 35;
const int pinLM35 = 34;

// ===== LED ALERTA =====
const int LED = 27;

// ==============================
// Página principal
// ==============================
void enviarPaginaPrincipal() {

  // Lectura sensores
  int valorLDR = analogRead(pinLDR);

  // Cálculo temperatura LM35
  float tempC = (analogRead(pinLM35) * 5.0 / 4095.0) * 100.0;

  // Lógica de alertas
  String colorTemp = "#28a745"; // Verde
  String estado = "NORMAL";

  digitalWrite(LED, LOW);

  if (tempC > 24.0) {
    colorTemp = "#dc3545"; // Rojo
    estado = "ALERTA";
    digitalWrite(LED, HIGH);
  }

  // HTML
  String html = "<!DOCTYPE html>";
  html += "<html>";
  html += "<head>";
  html += "<meta charset='UTF-8'>";
  html += "<meta http-equiv='refresh' content='5'>";
  html += "<title>Monitor CPD</title>";

  html += "<style>";
  html += "body{font-family:Arial,sans-serif;";
  html += "background:#f4f4f4;";
  html += "text-align:center;";
  html += "margin-top:30px;}";

  html += ".card{";
  html += "padding:20px;";
  html += "color:white;";
  html += "display:inline-block;";
  html += "margin:10px;";
  html += "border-radius:10px;";
  html += "width:220px;";
  html += "box-shadow:0 0 10px rgba(0,0,0,0.2);}";
  
  html += "a{display:block;margin-top:20px;font-size:18px;}";
  html += "</style>";

  html += "</head>";
  html += "<body>";

  html += "<h1>Dashboard de Monitorització CPD</h1>";

  html += "<div class='card' style='background:";
  html += colorTemp;
  html += ";'>";
  html += "<h2>Temperatura</h2>";
  html += "<p>";
  html += String(tempC, 1);
  html += " °C</p>";
  html += "<p>";
  html += estado;
  html += "</p>";
  html += "</div>";

  html += "<div class='card' style='background:#007bff;'>";
  html += "<h2>Llum (LDR)</h2>";
  html += "<p>";
  html += String(valorLDR);
  html += "</p>";
  html += "</div>";

  html += "<br>";
  html += "<a href='/credits'>Crèdits</a>";

  html += "</body>";
  html += "</html>";

  server.send(200, "text/html", html);
}

// ==============================
// Página créditos
// ==============================
void credits() {
  String html = "<html><head><meta charset='UTF-8'></head><body>";
  html += "<h1>Crèdits</h1>";
  html += "<p>Pràctica 3 - Dashboard de monitorització CPD</p>";
  html += "<p>Fet per Jan</p>";
  html += "<a href='/'>Tornar</a>";
  html += "</body></html>";

  server.send(200, "text/html", html);
}

// ==============================
// SETUP
// ==============================
void setup() {

  Serial.begin(115200);

  pinMode(LED, OUTPUT);

  Serial.println();
  Serial.println("Iniciant ESP32...");

  WiFi.begin(ssid, password);

  Serial.print("Connectant");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("Connectat!");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());

  // Rutas web
  server.on("/", enviarPaginaPrincipal);
  server.on("/credits", credits);

  server.begin();

  Serial.println("Servidor web iniciat");
}

// ==============================
// LOOP
// ==============================
void loop() {
  server.handleClient();
}
