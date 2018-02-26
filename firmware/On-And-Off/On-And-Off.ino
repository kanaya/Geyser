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

const long Second = 1000;
const long Minute = 60;

long off_intervals[16] = {
  1 * Minute,    // 0
  2 * Minute,    // 1
  3 * Minute,    // 2
  4 * Minute,    // 3
  5 * Minute,    // 4
  6 * Minute,    // 5
  7 * Minute,    // 6
  8 * Minute,    // 7
  9 * Minute,    // 8
  10 * Minute,   // 9
  15 * Minute,   // 10
  30 * Minute,   // 11
  60 * Minute,   // 12
  90 * Minute,   // 13
  120 * Minute,  // 14
  240 * Minute,  // 15
}; 

long on_intervals[16] = {
  1 * Second,    // 0
  1.5 * Second,  // 1
  2 * Second,    // 2
  2.5 * Second,  // 3
  3 * Second,    // 4
  3.5 * Second,  // 5
  4 * Second,    // 6
  4.5 * Second,  // 7
  5 * Second,    // 8
  5.5 * Second,  // 9
  6 * Second,    // 10
  6.5 * Second,  // 11
  7 * Second,    // 12
  7.5 * Second,  // 13
  8 * Second,    // 14
  10 * Second,   // 15
}; 

long off_interval;
long on_interval;

long ticktack = 0;

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

void readRotarySw() {
  int u0 = digitalRead(U0);
  int u1 = digitalRead(U1);
  int u2 = digitalRead(U2);
  int u3 = digitalRead(U3);
  int v0 = digitalRead(V0);
  int v1 = digitalRead(V1);
  int v2 = digitalRead(V2);
  int v3 = digitalRead(V3);
  off_interval = (u3 << 3) | (u2 << 2) | (u1 << 1) | u0;
  on_interval = (v3 << 3) | (v2 << 2) | (v1 << 1) | v0;  
}

void printPinStatus() {
  Serial.print("off_interval = ");
  Serial.println(off_interval);
  Serial.print("on_interval = ");
  Serial.println(on_interval);
  Serial.print("ticktack = ");
  Serial.println(ticktack);
  Serial.println("---"); 
}

// the loop function runs over and over again forever
void loop() {
  readRotarySw();
  printPinStatus();

  ++ticktack;
  if (ticktack >= off_intervals[off_interval]) {
    ticktack = 0;
    digitalWrite(RELAY, HIGH); // Turn on
    delay(on_intervals[on_interval]);
    digitalWrite(RELAY, LOW);
  }
  else {
    delay(1000);
  }
}
