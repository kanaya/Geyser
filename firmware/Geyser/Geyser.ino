/*
  Geyser 1.0.0
  Copyright (C) 2018 by Pineapple Design.

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

// OFF-INTERVAL
const int U0 = 5;
const int U1 = 6;
const int U2 = 7;
const int U3 = 8;

// ON-INTERVAL
const int V0 = 9;
const int V1 = 10;
const int V2 = 11;
const int V3 = 12;

const int RELAY = LED_BUILTIN;
const int INDICATOR = 2;

const long Second = 1000;
const long Minute = 60;

long off_intervals[16] = {  // [s]
  0.1 * Minute,  // 0 -- Test mode
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

long on_intervals[16] = {  // [ms]
  1 * Second,    // 0 -- Test mode
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

void greeting() {
  Serial.println("Hello.");
}

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
  digitalWrite(RELAY, LOW);
  
  pinMode(INDICATOR, OUTPUT);
  digitalWrite(INDICATOR, HIGH);

  // Serial.begin(9600);
  sayImOn();
  sayImOn();
  sayImOn();
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

void sayImOn() {
  // Spends 50[ms]
  digitalWrite(INDICATOR, LOW);
  delay(10);
  digitalWrite(INDICATOR, HIGH);
  delay(40);
}

void loop() {
  sayImOn();  // 50[ms]
  readRotarySw();
  // printPinStatus();

  ++ticktack;
  if (ticktack >= off_intervals[off_interval]) {
    ticktack = 0;
    digitalWrite(RELAY, HIGH); // Turn on
    delay(on_intervals[on_interval]);
    digitalWrite(RELAY, LOW);
  }
  else {
    delay(950);
  }
}
