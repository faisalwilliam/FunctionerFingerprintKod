
/*#include <Adafruit_Fingerprint.h> //Include the Fingerprint Library
#include <Servo.h> // Include the Servo Library
#include <SoftwareSerial.h>
Servo myServo; // Create servo object
#define ledPin_G 4 // Define the led pin for green
#define  ledPin_R 5 // Define the led pin for red
#define BuzzerPin  7 // Define the buzzer pin
#define servoPin  6 // Define the servo pin
SoftwareSerial mySerial(2, 3);
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial); // Create the fingerprint object
uint8_t id; // Define the id
void setup()
{
  initialize();
}
void initialize() {
  pinMode(ledPin_G, OUTPUT); // Set the led pin for green as output
  pinMode(ledPin_R, OUTPUT);
  pinMode(BuzzerPin, OUTPUT);
  myServo.attach(servoPin); // Attach the servo pin to the servo object
  Serial.begin(9600); // Start the serial port
  while (!Serial);  // Wait for serial port to connect. Needed for native USB port only
  delay(100); // Wait for a little bit
  Serial.println("\n\nAdafruit Fingerprint sensor enrollment"); // Print a message to the serial port
  finger.begin(57600); // Set the data rate for the sensor serial port
  if (finger.verifyPassword()) {
    Serial.println("Found fingerprint sensor!"); 
  } else {
    Serial.println("Did not find fingerprint sensor :("); 
    while (1) { delay(1); }
  }
  Serial.println(F("Reading sensor parameters"));
  finger.getParameters();
  Serial.print(F("Status: 0x")); Serial.println(finger.status_reg, HEX);
  Serial.print(F("Sys ID: 0x")); Serial.println(finger.system_id, HEX);
  Serial.print(F("Capacity: ")); Serial.println(finger.capacity);
  Serial.print(F("Security level: ")); Serial.println(finger.security_level);
  Serial.print(F("Device address: ")); Serial.println(finger.device_addr, HEX);
  Serial.print(F("Packet len: ")); Serial.println(finger.packet_len);
  Serial.print(F("Baud rate: ")); Serial.println(finger.baud_rate);
}
uint8_t readNumber() {
  uint8_t num = 0;
  while (num == 0) {
    while (!Serial.available());
    num = Serial.parseInt();
  }
  return num;
}
void loop() {
  blinkLed();
  playTone();
  moveServo();
  enrollFingerprint();
}
void blinkLed() {
  digitalWrite(ledPin_G, HIGH);
  delay(1000);
  digitalWrite(ledPin_G, LOW);
  delay(1000);
  digitalWrite(ledPin_R, LOW); 
  delay(1000);
  digitalWrite(ledPin_R, HIGH); 
  delay(1000);
}
void playTone() {
  tone(BuzzerPin, 1000); 
  delay(1000); 
  noTone(BuzzerPin); 
}
void moveServo() {
  myServo.write(90); 
  delay(10000);
  myServo.write(0); 
  delay(10000);
}
void enrollFingerprint() {
  Serial.println("Ready to enroll a fingerprint!");
  Serial.println("Please type in the ID # (from 1 to 127) you want to save this finger as..."); 
  id = readNumber();
  if (id == 0) {
    return;
  }
  Serial.print("Enrolling ID #");
  Serial.println(id);
  while (!getFingerprintEnroll());
}
uint8_t getFingerprintEnroll() {
  int p = -1;
  Serial.print("Waiting for valid finger to enroll as #");
  Serial.println(id);
  while (p != FINGERPRINT_OK) {
    p = finger.getImage();
    switch (p) {
      case FINGERPRINT_OK:
        Serial.println("Image taken");
        break;
      case FINGERPRINT_NOFINGER:
        Serial.print(".");
        break;
      case FINGERPRINT_PACKETRECIEVEERR:
        Serial.println("Communication error");
        break;
      case FINGERPRINT_IMAGEFAIL:
        Serial.println("Imaging error");
        break;
      default:
        Serial.println("Unknown error");
        break;
    }
  }
  return true;
}
*/
#include <Adafruit_Fingerprint.h> //Include the Fingerprint Library
#include <Servo.h> // Include the Servo Library
#include <SoftwareSerial.h>
Servo myServo; // Create servo object
#define ledPin_G 4 // Define the led pin for green
#define  ledPin_R 5 // Define the led pin for red
#define BuzzerPin  7 // Define the buzzer pin
#define servoPin  6 // Define the servo pin
SoftwareSerial mySerial(2, 3);
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial); // Create the fingerprint object
uint8_t id; // Define the id
void setup()
{
  initialize(); // Initialize the fingerprint sensor
 
}
void initialize() {  
  pinMode(ledPin_G, OUTPUT); // Set the led pin for green as output
  pinMode(ledPin_R, OUTPUT);
  pinMode(BuzzerPin, OUTPUT);
  myServo.attach(servoPin); // Attach the servo pin to the servo object
  Serial.begin(9600); // Start the serial port
  while (!Serial);  // Wait for serial port to connect. Needed for native USB port only
  delay(100); // Wait for a little bit
  Serial.println("\n\nAdafruit Fingerprint sensor enrollment"); // Print a message to the serial port
  finger.begin(57600); // Set the data rate for the sensor serial port
  if (finger.verifyPassword()) {
    Serial.println("Found fingerprint sensor!"); 
  } else {
    Serial.println("Did not find fingerprint sensor :("); 
    while (1) { delay(1); }
  }
  Serial.println(F("Reading sensor parameters")); //  Print a message to the serial port
  finger.getParameters(); // Read the sensores parameters
  Serial.print(F("Status: 0x")); Serial.println(finger.status_reg, HEX);
  Serial.print(F("Sys ID: 0x")); Serial.println(finger.system_id, HEX);
  Serial.print(F("Capacity: ")); Serial.println(finger.capacity);
  Serial.print(F("Security level: ")); Serial.println(finger.security_level);
  Serial.print(F("Device address: ")); Serial.println(finger.device_addr, HEX);
  Serial.print(F("Packet len: ")); Serial.println(finger.packet_len);
  Serial.print(F("Baud rate: ")); Serial.println(finger.baud_rate);
}
uint8_t readNumber() { // Read a number from the serial port
  uint8_t num = 0; // Initailize the number 0
  while (num == 0) { // 
    while (!Serial.available()); // Waite for a bye to be available
    num = Serial.parseInt(); // Read the nyumber from the serial prot
  }
  return num;
}
void loop() { // Main loop
  blinkLed(); // Blink the led
  playTone(); // Play a tone
  moveServo(); // Move the servo
 
  
  enrollFingerprint(); // Enroll afingerprint
}
void blinkLed() { // Blink the led
  digitalWrite(ledPin_G, HIGH);
  delay(1000);
  digitalWrite(ledPin_G, LOW);
  delay(1000);
  digitalWrite(ledPin_R, LOW); 
  delay(1000);
  digitalWrite(ledPin_R, HIGH); 
  delay(1000);
}
void playTone() { // Play a tone
  tone(BuzzerPin, 1000); 
  delay(1000); 
  noTone(BuzzerPin); 
}
void moveServo() { // Move the servo
  myServo.write(90); 
  delay(10000);
  myServo.write(0); 
  delay(10000);
}
void enrollFingerprint() { // Enroll a fingerprint
  Serial.println("Ready to enroll a fingerprint!");
  Serial.println("Please type in the ID # (from 1 to 127) you want to save this finger as..."); 
  id = readNumber(); // Read the id from the serial port
  
  if (id == 0) { // if the id is 0
    return;
  }
  Serial.print("Enrolling ID #"); 
  Serial.println(id); 
}
uint8_t getFingerprintEnroll() { // Get the fingerprint enroll
  int p = -1; // Initailize the p to -1
  Serial.print("Waiting for valid finger to enroll as #");
  Serial.println(id);
  while (p != FINGERPRINT_OK) { // whilst the finger is not enrolled
    p = finger.getImage(); // Get the finger imaget

    switch (p) { // swith the p
      case FINGERPRINT_OK:
        Serial.println("Image taken");
        break;
      case FINGERPRINT_NOFINGER:
        Serial.print("."); // Print a dot
        break;
      case FINGERPRINT_PACKETRECIEVEERR:
        Serial.println("Communication error");
        break;
      case FINGERPRINT_IMAGEFAIL:
        Serial.println("Imaging error");
        break;
      default:
        Serial.println("Unknown error");
        break;
    }
  }
  return true; // Return trur
}
