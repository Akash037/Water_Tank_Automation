#include <Arduino.h>
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Input: water level, battery voltage
// Output: water level, battery voltage, notification, call

// Flag when water level changes

BlynkTimer timer;
char auth[] = "6ced08cd273148a4a81162544bcc3b26"; //Auth code sent via Email
char ssid[] = "Hacked";                           //Wifi name
char pass[] = "0123456789";                       //Wifi Password
bool Level_100, Level_75, Level_50, Level_25, Level_0;
char flag;

void water_level_check()
{

    Level_100 = digitalRead(D1);
    Level_75 = digitalRead(D2);
    Level_50 = digitalRead(D5);
    Level_25 = digitalRead(D6);
    Level_0 = digitalRead(D7);

    if (Level_100)
    {
        flag = L_100;
        break;
    }
    else
    {
        flag = L_75;
    }

    else if (Level_100)
    {
        flag = f;
        break;
    }
    else if (Level_100)
    {
        flag = f;
        break;
    }
    if (Level_100)
    {
        flag = f;
        break;
    }
    if (Level_100)
    {
        flag = f;
        break;
    }
}

void notify()
{
}

void battery_level_check()
{
    // Check battery voltage every 5 minute
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
    water_level_check();
    notify();
    battery_level_check();
}