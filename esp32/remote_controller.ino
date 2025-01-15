#include <WiFi.h>
#include <WebServer.h>

// WiFi Access Point Configuration
const char *SSID = "Quadruped_Robot";
const char *PASSWORD = "12345678";

// Commands (13 total actions)
enum RobotCommands
{
    CMD_STOP = 0,
    CMD_FORWARD = 1,
    CMD_BACKWARD = 2,
    CMD_LEFT = 3,
    CMD_RIGHT = 4,
    CMD_BOW = 5,
    CMD_WAVE = 6,
    CMD_SPEED_INCREASE = 7,
    CMD_SPEED_DECREASE = 8,
    CMD_DANCE = 9,
    CMD_CENTER_SERVOS = 0,
    CMD_TRIM_LEFT = 11,
    CMD_TRIM_RIGHT = 12
};

// Create WebServer object on default http port
WebServer server(80);

void setup()
{
    // Initialize Serial communication for debugging
    Serial.begin(9600);

    // Initialize Serial2 for communication with Arduino Nano
    Serial2.begin(9600, SERIAL_8N1, 16, 17); // RX2=16, TX2=17

    // Setup WiFi Access Point
    WiFi.softAP(SSID, PASSWORD);
    IPAddress IP = WiFi.softAPIP();

    Serial.print("Access Point IP: ");
    Serial.println(IP);

    // Define server routes for all commands
    server.on("/", handleRoot);
    server.on("/stop", HTTP_GET, []()
              { sendCommand(CMD_STOP); });
    server.on("/forward", HTTP_GET, []()
              { sendCommand(CMD_FORWARD); });
    server.on("/backward", HTTP_GET, []()
              { sendCommand(CMD_BACKWARD); });
    server.on("/left", HTTP_GET, []()
              { sendCommand(CMD_LEFT); });
    server.on("/right", HTTP_GET, []()
              { sendCommand(CMD_RIGHT); });
    server.on("/bow", HTTP_GET, []()
              { sendCommand(CMD_BOW); });
    server.on("/wave", HTTP_GET, []()
              { sendCommand(CMD_WAVE); });
    server.on("/speedincrease", HTTP_GET, []()
              { sendCommand(CMD_SPEED_INCREASE); });
    server.on("/speeddecrease", HTTP_GET, []()
              { sendCommand(CMD_SPEED_DECREASE); });
    server.on("/dance", HTTP_GET, []()
              { sendCommand(CMD_DANCE); });
    server.on("/centerservos", HTTP_GET, []()
              { sendCommand(CMD_CENTER_SERVOS); });
    server.on("/trimleft", HTTP_GET, []()
              { sendCommand(CMD_TRIM_LEFT); });
    server.on("/trimright", HTTP_GET, []()
              { sendCommand(CMD_TRIM_RIGHT); });

    // Start server
    server.begin();
    Serial.println("HTTP server started");
}

void loop()
{
    server.handleClient();
}

// Send Integer Command Function with Error Handling
void sendCommand(int command)
{
    // Send command via Serial2
    Serial2.write(command); // Send as a single byte

    // Send HTTP response
    server.send(200, "text/plain", "Command sent: " + String(command));

    // Debug print
    Serial.print("Sent Command: ");
    Serial.println(command);
}

// HTML Page Handler with Press-and-Hold Functionality
void handleRoot()
{
    String html = R"(
    //    HTML code with CSS and JS files embedded
)";

    server.send(200, "text/html", html);
}