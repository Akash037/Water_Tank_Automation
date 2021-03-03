#include <Arduino.h>
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Send notification 3 times when tank is full with 8 second gap

BlynkTimer timer;
char auth[] = "6ced08cd273148a4a81162544bcc3b26"; //Auth code sent via Email
char ssid[] = "Hacked";                           //Wifi name
char pass[] = "0123456789";                       //Wifi Password
bool Level_100, Level_75, Level_50, Level_25, Level_0;
char flag

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
  if ((Level_100 == HIGH) && (notification < 3))
  {

    Blynk.notify("Tank is full\n Switch off motor IMMEDIATELY");
    notification++;
    break;
  }
  else if (Level_25 == HIGH)
  {
    Blynk.notify("Water Level is LOW\n Switch on motor");
    break;
  }
  else if (Level_0 == HIGH)
  {
    Blynk.notify("Tank is empty\n Switch on motor IMMEDIATELY");
  }
}

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  pinMode(D1, INPUT);
  pinMode(D2, INPUT);
  pinMode(D5, INPUT);
  pinMode(D6, INPUT);
  pinMode(D7, INPUT);
}

void loop()
{
  Blynk.run();
  level_check();
  notify();
}