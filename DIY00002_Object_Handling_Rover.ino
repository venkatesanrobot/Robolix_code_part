#include <ESPAsyncWebSrv.h>

const char* ssid = "ESP8266";    // Change this to your WiFi network's SSID
const char* password = "asdfghjkl"; // Change this to your WiFi network's password

const int IP1 = 25; // Change to your motor control pins
const int IP2 = 26; // Change to your motor control pins
const int IP3 = 32; // Change to your motor control pins
const int IP4 = 33; // Change to your mot0or control pins

AsyncWebServer server(80);


const char INDEX_HTML[] PROGMEM = R"(
<html>
   <head>
    <title>botlix</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <style>
      body { font-family: Arial; text-align: center; margin:0px auto; padding-top: 30px;}
      table { margin-left: auto; margin-right: auto; }
      td { padding: 8 px; }
      .button 
      {
        background-color: #2f4468;
        border: none;
        color: white;
        padding: 18px 28px;
        text-align: center;
        text-decoration: none;
        display: inline-block;
        font-size: 24px;
        margin: 6px 3px;
        cursor: pointer;
        -webkit-touch-callout: none;
        -webkit-user-select: none;
        -khtml-user-select: none;
        -moz-user-select: none;
        -ms-user-select: none;
        user-select: none;
        -webkit-tap-highlight-color: rgba(0,0,0,0);
      }
    </style>
  </head>
  <body>
    <h1>web controlling bot</h1>
    <table>
      <tr>
 
 <td colspan="3" align="center"><button class="button" onmousedown="toggleCheckbox('forward');" ontouchstart="toggleCheckbox('forward');" onmouseup="toggleCheckbox('stop');"
  ontouchend="toggleCheckbox('stop');">Forward</button></td></tr>
      <tr><td align="center"><button class="button" onmousedown="toggleCheckbox('left');" 
      ontouchstart="toggleCheckbox('left');" onmouseup="toggleCheckbox('stop');" ontouchend="toggleCheckbox('stop');">Left</button></td><td align="center"><button class="button" onmousedown="toggleCheckbox('stop');" ontouchstart="toggleCheckbox('stop');">Stop</button></td><td align="center"><button class="button" onmousedown="toggleCheckbox('right');" ontouchstart="toggleCheckbox('right');" onmouseup="toggleCheckbox('stop');" ontouchend="toggleCheckbox('stop');">Right</button></td></tr>
      <tr>
        <td colspan="3" align="center">
          <button class="button" onmousedown="toggleCheckbox('backward');" ontouchstart="toggleCheckbox('backward');" onmouseup="toggleCheckbox('stop');" ontouchend="toggleCheckbox('stop');">Backward</button>
        </td>
      </tr>                   
    </table>
    <script>
    function toggleCheckbox(x)
    {
      var xhr = new XMLHttpRequest();
      xhr.open("GET", "/action?action=" + x, true);
      xhr.send();
    }
  </script>
  </body>
</html>
)";


void setup() {
  Serial.begin(115200);

  pinMode(IP1, OUTPUT);
  pinMode(IP2, OUTPUT);
  pinMode(IP3, OUTPUT);
  pinMode(IP4, OUTPUT);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", INDEX_HTML);
  });

  server.on("/action", HTTP_GET, [](AsyncWebServerRequest *request){
    String action = request->arg("action");
    handleAction(action);
    request->send(200, "text/html", "Action: " + action);
  });

  server.begin();
}

void loop() {
}

void handleAction(String action) {
  if (action == "forward") {
    digitalWrite(IP1, HIGH);
    digitalWrite(IP2, LOW);
    digitalWrite(IP3, HIGH);
    digitalWrite(IP4, LOW);
    Serial.println("Device FORWARD");
  } else if (action == "backward") {
    digitalWrite(IP1, LOW);
    digitalWrite(IP2, HIGH);
    digitalWrite(IP3, LOW);
    digitalWrite(IP4, HIGH);
    Serial.println("Device BACKWARD");
  } else if (action == "left") {
    digitalWrite(IP1, HIGH);
    digitalWrite(IP2, LOW);
    digitalWrite(IP3, LOW);
    digitalWrite(IP4, HIGH);
    Serial.println("Device LEFT");
  } else if (action == "right") {
    digitalWrite(IP1, LOW);
    digitalWrite(IP2, HIGH);
    digitalWrite(IP3, HIGH);
    digitalWrite(IP4, LOW);
    Serial.println("Device RIGHT");
  } else if (action == "stop") {
    digitalWrite(IP1, LOW);
    digitalWrite(IP2, LOW);
    digitalWrite(IP3, LOW);
    digitalWrite(IP4, LOW);
    Serial.println("Device OFF");
  }
}
