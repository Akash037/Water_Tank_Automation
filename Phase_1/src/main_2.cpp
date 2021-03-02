#include <Arduino.h>
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

BlynkTimer timer;
char auth[] = "6ced08cd273148a4a81162544bcc3b26"; //Auth code sent via Email
char ssid[] = "Hacked";                           //Wifi name
char pass[] = "0123456789";                       //Wifi Password
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