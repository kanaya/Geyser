/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO 
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino model, check
  the Technical Specs of your board  at https://www.arduino.cc/en/Main/Products
  
  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
  
  modified 2 Sep 2016
  by Arturo Guadalupi
  
  modified 8 Sep 2016
  by Colby Newman
*/

const int U0 = 5;
const int U1 = 6;
const int U2 = 7;
const int U3 = 8;

const int V0 = 9;
const int V1 = 10;
const int V2 = 11;
const int V3 = 12;

const int RELAY = LED_BUILTIN;

void setup() {
  pinMode(U0, INPUT_PULLUP);
  pinMode(U1, INPUT_PULLUP);
  pinMode(U2, INPUT_PULLUP);
  pinMode(U3, INPUT_PULLUP);
  
  pinMode(V0, INPUT_PULLUP);
  pinMode(V1, INPUT_PULLUP);
  pinMode(V2, INPUT_PULLUP);
  pinMode(V3, INPUT_PULLUP);
  
  pinMode(RELAY, OUTPUT);

  Serial.begin(9600);
  Serial.println("Hello.");
}

void printPinStatus() {
  int u0 = digitalRead(U0);
  int u1 = digitalRead(U1);
  int u2 = digitalRead(U2);
  int u3 = digitalRead(U3);
  int v0 = digitalRead(V0);
  int v1 = digitalRead(V1);
  int v2 = digitalRead(V2);
  int v3 = digitalRead(V3);
  int u = (u3 << 3) | (u2 << 2) | (u1 << 1) | u0;
  int v = (v3 << 3) | (v2 << 2) | (v1 << 1) | v0;
  Serial.println(u);
  Serial.println(v);
  Serial.println("---"); 
}

// the loop function runs over and over again forever
void loop() {
  printPinStatus();
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}
