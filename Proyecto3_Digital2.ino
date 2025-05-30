#include <WiFi.h>
#include <WebServer.h>
#include <Wire.h>

#define N1_14 0x64
#define N2_58 0x10

#define I2C_SDA 16
#define I2C_SCL 17
uint8_t P_Disponibles = 0xFF;
const char* ssid = "Prueba";
const char* password = "Cla123123";
WebServer server(80);



void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Wire.begin(I2C_SDA, I2C_SCL);
  Serial.println("Conectando a red Wi-Fi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }

  Serial.println("\nConectado a WiFi.");
  Serial.print("IP del ESP32: ");
  Serial.println(WiFi.localIP());

  server.on("/", HTTP_GET, Pagina);
  server.on("/estado", HTTP_GET, Estado);
  server.begin();
  Serial.println("Servidor HTTP iniciado");
  server.on("/test", [](){
  server.send(200, "text/plain", "ESP OK");
});
}

void loop() {
    server.handleClient();

  uint8_t Parqueos_14 = 0xF0;
  uint8_t Parqueos_58 = 0x0F;

  Wire.requestFrom(N1_14, 1);
  if (Wire.available()) {
    Parqueos_14 = Wire.read();
  }
  
  P_Disponibles = Parqueos_14 | Parqueos_58;


  delay(500);

}

void Pagina(){
  String html;
html += "<!DOCTYPE html>\n";
html += "<html>\n";
html += "    <head>\n";
html += "        <style>\n";
html += "            body{\n";
html += "                background-image: url(\"https://raw.githubusercontent.com/MateoCasta/Proyecto3-Digital2/refs/heads/main/ParqueoVacio.png\");\n";
html += "                background-size: cover;\n";
html += "                background-position: 0px  -350px; /* Alinea la imagen arriba */            \n";
html += "                background-repeat: no-repeat;\n";
html += "\n";
html += "\n";
html += "            }\n";
html += "            .nombres{\n";
html += "                text-align: center;\n";
html += "                font-size: 25px;\n";
html += "                font-weight: bold;\n";
html += "            }\n";
html += "            h1{\n";
html += "                text-align: center;\n";
html += "            }\n";
html += "            .Parqueos{\n";
html += "                position: absolute;\n";
html += "                top: 120px;\n";
html += "                left: 70px;\n";
html += "                width: 300px;\n";
html += "                height: 600px;\n";
html += "                color: darkblue;\n";
html += "                border: 6px solid black;\n";
html += "                background-color: darkblue; \n";
html += "                border-radius: 5%;\n";
html += "                z-index: 3;\n";
html += "                box-shadow: 10px 5px 15px rgba(0, 0, 0);\n";
html += "\n";
html += "\n";
html += "            }\n";
html += "            .circulo{\n";
html += "                position: absolute;\n";
html += "                top: 3px;\n";
html += "                left: 80px;\n";
html += "                width: 120px;\n";
html += "                height: 120px;\n";
html += "                border: 10px solid white;\n";
html += "                border-radius: 50%;\n";
html += "                z-index: 4;\n";
html += "                background-color: transparent;\n";
html += "             \n";
html += "\n";
html += "\n";
html += "\n";
html += "            }\n";
html += "            .letra {\n";
html += "                position: absolute;            /* Centra el texto horizontal y vertical */\n";
html += "                font-size: 125px;\n";
html += "                top: -8px;\n";
html += "                left: 25px;\n";
html += "\n";
html += "                font-weight: 10px;\n";
html += "                color: white;\n";
html += "                font-family: Arial;   \n";
html += "            }\n";
html += "            .Parqueo1{\n";
html += "                position: absolute;\n";
html += "                top: 335px;     /* pon la posición que desees */\n";
html += "                left: 776px;\n";
html += "                width: 70px;   /* ajusta al tamaño de tu coche */\n";
html += "                height: 144px;\n";
html += "                background-image: url('https://raw.githubusercontent.com/MateoCasta/Proyecto3-Digital2/refs/heads/main/Carro1.png');\n";
html += "                background-size: cover;     /* o “cover” si quieres cubrir todo el div */\n";
html += "                background-repeat: no-repeat;\n";
html += "                background-position: center;\n";
html += "                z-index: 5;     \n";
html += "\n";
html += "            }\n";
html += "            .Parqueo2{\n";
html += "                position: absolute;\n";
html += "                top: 335px;     /* pon la posición que desees */\n";
html += "                left: 850px;\n";
html += "                width: 70px;   /* ajusta al tamaño de tu coche */\n";
html += "                height: 144px;\n";
html += "                background-image: url('https://raw.githubusercontent.com/MateoCasta/Proyecto3-Digital2/refs/heads/main/Carro1.png');\n";
html += "                background-size: cover;     /* o “cover” si quieres cubrir todo el div */\n";
html += "                background-repeat: no-repeat;\n";
html += "                background-position: center;\n";
html += "                z-index: 5;     \n";
html += "\n";
html += "            }\n";
html += "            .Parqueo3{\n";
html += "                position: absolute;\n";
html += "                top: 335px;     /* pon la posición que desees */\n";
html += "                left: 925px;\n";
html += "                width: 70px;   /* ajusta al tamaño de tu coche */\n";
html += "                height: 144px;\n";
html += "                background-image: url('https://raw.githubusercontent.com/MateoCasta/Proyecto3-Digital2/refs/heads/main/Carro1.png');\n";
html += "                background-size: cover;     /* o “cover” si quieres cubrir todo el div */\n";
html += "                background-repeat: no-repeat;\n";
html += "                background-position: center;\n";
html += "                z-index: 5;     \n";
html += "\n";
html += "            }\n";
html += "            .Parqueo4{\n";
html += "                position: absolute;\n";
html += "                top: 335px;     /* pon la posición que desees */\n";
html += "                left: 1000px;\n";
html += "                width: 70px;   /* ajusta al tamaño de tu coche */\n";
html += "                height: 144px;\n";
html += "                background-image: url('https://raw.githubusercontent.com/MateoCasta/Proyecto3-Digital2/refs/heads/main/Carro1.png');\n";
html += "                background-size: cover;     /* o “cover” si quieres cubrir todo el div */\n";
html += "                background-repeat: no-repeat;\n";
html += "                background-position: center;\n";
html += "                z-index: 5;     \n";
html += "\n";
html += "            }\n";
html += "             .Parqueo5{\n";
html += "                position: absolute;\n";
html += "                top: 560px;     /* pon la posición que desees */\n";
html += "                left: 776px;\n";
html += "                width: 70px;   /* ajusta al tamaño de tu coche */\n";
html += "                height: 144px;\n";
html += "                background-image: url('https://raw.githubusercontent.com/MateoCasta/Proyecto3-Digital2/refs/heads/main/Carro1.png');\n";
html += "                background-size: cover;     /* o “cover” si quieres cubrir todo el div */\n";
html += "                background-repeat: no-repeat;\n";
html += "                background-position: center;\n";
html += "                z-index: 5;     \n";
html += "\n";
html += "            }\n";
html += "            .Parqueo6{\n";
html += "                position: absolute;\n";
html += "                top: 560px;     /* pon la posición que desees */\n";
html += "                left: 850px;\n";
html += "                width: 70px;   /* ajusta al tamaño de tu coche */\n";
html += "                height: 144px;\n";
html += "                background-image: url('https://raw.githubusercontent.com/MateoCasta/Proyecto3-Digital2/refs/heads/main/Carro1.png');\n";
html += "                background-size: cover;     /* o “cover” si quieres cubrir todo el div */\n";
html += "                background-repeat: no-repeat;\n";
html += "                background-position: center;\n";
html += "                z-index: 5;     \n";
html += "\n";
html += "            }\n";
html += "             .Parqueo7{\n";
html += "                position: absolute;\n";
html += "                top: 560px;     /* pon la posición que desees */\n";
html += "                left: 925px;\n";
html += "                width: 70px;   /* ajusta al tamaño de tu coche */\n";
html += "                height: 144px;\n";
html += "                background-image: url('https://raw.githubusercontent.com/MateoCasta/Proyecto3-Digital2/refs/heads/main/Carro1.png');\n";
html += "                background-size: cover;     /* o “cover” si quieres cubrir todo el div */\n";
html += "                background-repeat: no-repeat;\n";
html += "                background-position: center;\n";
html += "                z-index: 5;     \n";
html += "\n";
html += "            }\n";
html += "            .Parqueo8{\n";
html += "                position: absolute;\n";
html += "                top: 560px;     /* pon la posición que desees */\n";
html += "                left: 1000px;\n";
html += "                width: 70px;   /* ajusta al tamaño de tu coche */\n";
html += "                height: 144px;\n";
html += "                background-image: url('https://raw.githubusercontent.com/MateoCasta/Proyecto3-Digital2/refs/heads/main/Carro1.png');\n";
html += "                background-size: cover;     /* o “cover” si quieres cubrir todo el div */\n";
html += "                background-repeat: no-repeat;\n";
html += "                background-position: center;\n";
html += "                z-index: 5;     \n";
html += "\n";
html += "            }\n";
html += "            .hidden {\n";
html += "             display: none !important;\n";
html += "            }\n";
html += "            \n";
html += "\n";
html += "\n";
html += "\n";
html += "\n";
html += "\n";
html += "        </style>\n";
html += "        <h1> Proyecto #3 Digital 2 </h1>\n";
html += "        <p class = \"nombres\">Mateo Castañeda - 22432 Albert Vandercam - 22688</p>\n";
html += "\n";
html += "\n";
html += "    \n";
html += "\n";
html += "    </head>\n";
html += "\n";
html += "\n";
html += "    <body>\n";
html += "        <div class = \"Parqueos\">\n";
html += "            <div class = \"circulo\">\n";
html += "            <span class = \"letra\">P</span>\n";
html += "\n";
html += "\n";
html += "\n";
html += "            </div>\n";
html += "            <div class = \"NumeroDeParqueos\">\n";
html += "\n";
html += "\n";
html += "            </div>\n";
html += "\n";
html += "\n";
html += "\n";
html += "        </div>\n";
html += "        <div id = \"p1\" class = \"Parqueo1\"></div>\n";
html += "        <div id = \"p2\" class = \"Parqueo2\"></div>\n";
html += "        <div id = \"p3\" class = \"Parqueo3\"></div>\n";
html += "        <div id = \"p4\" class = \"Parqueo4\"></div>\n";
html += "        <div id = \"p5\" class = \"Parqueo5\"></div>\n";
html += "        <div id = \"p6\" class = \"Parqueo6\"></div>\n";
html += "        <div id = \"p7\" class = \"Parqueo7\"></div>\n";
html += "        <div id = \"p8\" class = \"Parqueo8\"></div>\n";
html += "\n";
html += "         <script>\n";
html += "  function toggleSpot(n) {\n";
html += "    const el = document.getElementById('p' + n);\n";
html += "    if (!el) return;\n";
html += "    el.classList.toggle('hidden');\n";
html += "  }\n";
html += "\n";
html += "\n";
html += "  function obtenerParqueos() {\n";
html += "    fetch('/estado')\n";
html += "      .then(response => {\n";
html += "        if (!response.ok) throw new Error('Error en /estado');\n";
html += "        return response.text();\n";
html += "      })\n";
html += "      .then(texto => {\n";
html += "        const bits = parseInt(texto, 10);\n";
html += "        actualizarPantalla(bits);\n";
html += "      })\n";
html += "      .catch(err => console.error('Fetch fallo:', err));\n";
html += "  }\n";
html += "\n";
html += "\n";
html += "  function actualizarPantalla(bits) {\n";
html += "    let libres = 0;\n";
html += "    for (let i = 1; i <= 8; i++) {\n";
html += "      const el = document.getElementById('p' + i);\n";
html += "      const bit = (bits >> (i - 1)) & 1;\n";
html += "      if (bit === 1) {\n";
html += "        el.classList.add('hidden');\n";
html += "        libres++;\n";
html += "      } else {\n";
html += "\n";
html += "        el.classList.remove('hidden');\n";
html += "      }\n";
html += "    }\n";
html += "    const caja = document.querySelector('.NumeroDeParqueos');\n";
html += "    if (caja) caja.textContent = libres + ' libres';\n";
html += "  }\n";
html += "\n";
html += "\n";
html += "  window.addEventListener('load', () => {\n";
html += "    obtenerParqueos();                  \n";
html += "    setInterval(obtenerParqueos, 500);   \n";
html += "  });\n";
html += "         </script>\n";
html += "\n";
html += "\n";
html += "\n";
html += "       \n";
html += "\n";
html += "    </body>\n";
html += "\n";
html += "</html>\n";
server.send(200, "text/html", html);


}
void Estado() {
  server.send(200, "text/plain", String(P_Disponibles));
}



