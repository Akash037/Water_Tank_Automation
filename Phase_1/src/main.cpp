#include <Arduino.h>
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

BlynkTimer timer;
char auth[] = "6ced08cd273148a4a81162544bcc3b26"; //Auth code sent via Email
char ssid[] = "Hacked"; //Wifi name
char pass[] = "0123456789";  //Wifi Password
int flag=0;
bool full;
bool high;
bool half;
bool low;
bool empty;


void level_check()
{
  full = digitalRead(D1);
  high = digitalRead(D2);
  half = digitalRead(D5);
  low = digitalRead(D6);
  empty = digitalRead(D7);
}

void notify()
{
  if (full == HIGH)
  {
    Blynk.notify("Tank is full\n Switch off motor IMMEDIATELY");
  }
  else if (high == HIGH)
  {
    Blynk.notify("Tank is about to be full\n Switch off motor");
  }
  else if (half == HIGH)
  {
    Blynk.notify("Tank is half filled");
  }
  else if (low == HIGH)
  {
    Blynk.notify("Water Level is LOW\n Switch on motor");
  }
  else //if (empty == HIGH)                                           ye dekhna kuch add karni ho toh condition
  {
    Blynk.notify("Tank is empty\n Switch on motor IMMEDIATELY");
  }
}


void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  pinMode(D1,INPUT);
  pinMode(D2,INPUT);
  pinMode(D5,INPUT);
  pinMode(D6,INPUT);
  pinMode(D7,INPUT);
  
}


void loop() {
  Blynk.run();
  level_check();
  notify();
}