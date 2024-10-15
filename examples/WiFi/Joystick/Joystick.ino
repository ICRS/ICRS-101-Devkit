/*
  This program creates a wireless access point (called 101 Robot by default) that you can connect to with any WiFi capable device. 

  Once the program is running on an ESP32 go to 192.168.4.1 in a web browser to see the joystick.
*/

#include <WiFi.h>
#include <NetworkClient.h>
#include <WiFiAP.h>

#include "webpage.h"

#define DEBUG 0 /* Set to 1 to show WiFi debugging information */

#define MOTOR_LEFT_1 35
#define MOTOR_LEFT_2 33
#define MOTOR_RIGHT_1 39
#define MOTOR_RIGHT_2 37

/* Set a name for your robot (this will be the WiFi network name so make it unique) */
const char *ssid = "101 Robot";

NetworkServer server(80);

/* The move function called when a joystick movement is detected from the webpage.

    magnitude: an integer between 0 and 100 representing how far from the centre the joystick is.
               0 means no movement
               100 means full speed
    angle: an integer between -180 and 180 representing the angle of the joystick.
               0 means forwards
               > 0 means right
               < 0 means left
*/
void move(int magnitude, int angle) {

  Serial.print(magnitude);
  Serial.print(", ");
  Serial.println(angle);

  /* WRITE YOUR CODE HERE*/

  /* Go forwards */
  if ((angle > -45) && (angle < 45)) {
    analogWrite(MOTOR_LEFT_1, magnitude);
    analogWrite(MOTOR_LEFT_2, 0);
    analogWrite(MOTOR_RIGHT_1, magnitude);
    analogWrite(MOTOR_RIGHT_2, 0);
  }
}

/* The setup function runs once when you press reset or power the board */
void setup() {

  /* Set motor pins as outputs */
  pinMode(MOTOR_LEFT_1, OUTPUT);
  pinMode(MOTOR_LEFT_2, OUTPUT);
  pinMode(MOTOR_RIGHT_1, OUTPUT);
  pinMode(MOTOR_RIGHT_2, OUTPUT);

  /* Set motor pins to a known state */
  digitalWrite(MOTOR_LEFT_1, LOW);
  digitalWrite(MOTOR_LEFT_2, LOW);
  digitalWrite(MOTOR_RIGHT_1, LOW);
  digitalWrite(MOTOR_RIGHT_2, LOW);

  Serial.begin(115200);
  delay(1000);
  Serial.println();
  Serial.println("Configuring access point...");

  if (!WiFi.softAP(ssid)) {
    log_e("Soft AP creation failed.");
    while (1)
      ;
  }
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  server.begin();

  Serial.println("Server started");
}

/* The loop function runs repeatedly */
void loop() {
  NetworkClient client = server.accept();  // listen for incoming clients

  if (client) {  // if you get a client,

#if DEBUG == 1
    Serial.println("New Client.");  // print a message out the serial port
#endif

    String currentLine = "";      // make a String to hold incoming data from the client
    while (client.connected()) {  // loop while the client's connected
      if (client.available()) {   // if there's bytes to read from the client,
        char c = client.read();   // read a byte, then

#if DEBUG == 1
        Serial.write(c);  // print it out the serial monitor
#endif

        if (c == '\n') {  // if the byte is a newline character

          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();

            // the content of the HTTP response follows the header:
            client.print(JOYSTICK);

            // The HTTP response ends with another blank line:
            client.println();

            // break out of the while loop:
            break;

          } else {  // If you receive data, check if it's a POST request
            if (currentLine.startsWith("POST")) {
              String coordinates = currentLine.substring(currentLine.indexOf('[') + 1, currentLine.indexOf(']'));
              int magnitude = coordinates.substring(0, coordinates.indexOf(',')).toInt();
              int angle = coordinates.substring(coordinates.indexOf(',') + 1).toInt();

              move(magnitude, angle);

              client.println("HTTP/1.1 200 OK");
              client.println("Content-type:text/plain");
              client.println();
            }
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
      }
    }

    // close the connection:
    client.stop();
#if DEBUG == 1
    Serial.println("Client Disconnected.");
#endif
  }
}
