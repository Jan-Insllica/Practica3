Pràctica 3 – Dashboard de monitorització d’un CPD

Finalitat

Desenvolupar un sistema de monitorització per a una sala de servidors (CPD) utilitzant una placa ESP32 com a servidor web, permetent consultar les dades ambientals en temps real des d’un navegador i generar alertes visuals davant situacions de risc.

Resum del projecte

L’ESP32 es connecta a la xarxa WiFi i crea un servidor web accessible des de qualsevol dispositiu de la mateixa xarxa.

La pàgina web mostra informació en temps real obtinguda a partir d’un sensor de temperatura LM35 i un sensor de lluminositat LDR connectats a les entrades analògiques de la placa.

La interfície web s’actualitza automàticament cada cinc segons i presenta les dades de manera visual mitjançant targetes informatives.

Quan la temperatura supera els 24 °C, el sistema activa una alerta canviant el color de la targeta de temperatura a vermell i encenent un LED connectat a l’ESP32.

També s’ha implementat una pàgina secundària de crèdits accessible des de l’adreça "/credits".

Funcionalitats implementades

* Connexió de l’ESP32 a una xarxa WiFi.
* Creació d’un servidor web al port 80.
* Visualització d’una pàgina web amb disseny HTML i CSS.
* Lectura en temps real dels sensors LM35 i LDR.
* Actualització automàtica de les dades mostrades.
* Sistema d’alertes visual basat en la temperatura.
* Activació automàtica d’un LED d’alerta.
* Pàgina secundària de crèdits.

Seguiment del projecte

El seguiment de les tasques s’ha realitzat mitjançant un tauler Kanban a GitHub amb les columnes:

* To do
* Doing
* Done

Cada funcionalitat del projecte s’ha gestionat mitjançant una Issue independent.

Resultat final

El sistema permet monitoritzar en temps real les condicions ambientals d’una sala de servidors a través d’una interfície web accessible des de la xarxa local.

L’usuari pot consultar les dades actuals dels sensors, detectar situacions de risc de manera immediata i rebre alertes visuals tant a la pàgina web com mitjançant un LED físic.

El funcionament és estable i ofereix una solució bàsica de supervisió d’un CPD utilitzant una ESP32, sensors analògics i tecnologies web integrades.
