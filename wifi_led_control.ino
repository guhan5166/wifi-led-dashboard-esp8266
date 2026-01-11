#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "Enter Your ssid";
const char* password = "Enter Your Password";

ESP8266WebServer server(80);

#define LED1 D1
#define LED2 D2
#define LED3 D3

bool led1State = false;
bool led2State = false;
bool led3State = false;

String buildPage() {
  String page = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
<meta name="viewport" content="width=device-width, initial-scale=1">
<title>Smart LED Control</title>
<style>
body {
  background: #020617;
  font-family: 'Segoe UI', Arial;
  text-align: center;
  color: white;
}
h2 {
  margin-top: 20px;
  letter-spacing: 1px;
}
.btn {
  width: 85%;
  padding: 18px;
  margin: 12px;
  font-size: 20px;
  border-radius: 14px;
  border: none;
  color: black;
  font-weight: bold;
}
.cyan { background: #22d3ee; }
.purple { background: #c084fc; }
.yellow { background: #fde047; }
.green { background: #4ade80; }
</style>
</head>
<body>

<h2>WiFi LED Dashboard</h2>

<button class="btn cyan" onclick="location.href='/toggle1'">LED 1</button>
<button class="btn purple" onclick="location.href='/toggle2'">LED 2</button>
<button class="btn yellow" onclick="location.href='/toggle3'">LED 3</button>
<button class="btn green" onclick="location.href='/toggleall'">ALL LEDs</button>

</body>
</html>
)rawliteral";
  return page;
}

void setup() {
  Serial.begin(9600);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);

  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }

  Serial.print("IP: ");
  Serial.println(WiFi.localIP());

  server.on("/", []() {
    server.send(200, "text/html", buildPage());
  });

  server.on("/toggle1", []() {
    led1State = !led1State;
    digitalWrite(LED1, led1State);
    server.send(200, "text/html", buildPage());
  });

  server.on("/toggle2", []() {
    led2State = !led2State;
    digitalWrite(LED2, led2State);
    server.send(200, "text/html", buildPage());
  });

  server.on("/toggle3", []() {
    led3State = !led3State;
    digitalWrite(LED3, led3State);
    server.send(200, "text/html", buildPage());
  });

  server.on("/toggleall", []() {
    bool newState = !(led1State && led2State && led3State);
    led1State = led2State = led3State = newState;

    digitalWrite(LED1, newState);
    digitalWrite(LED2, newState);
    digitalWrite(LED3, newState);

    server.send(200, "text/html", buildPage());
  });

  server.begin();
}

void loop() {
  server.handleClient();
}
