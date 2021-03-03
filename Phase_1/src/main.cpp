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
int state = 0;
int flag = 0;
int notification = 0;

void tank_full()
{
  if ((state == 100) && (flag == 1))
  {
    for (int i = 0; i < 3; i++)
    {
      Blynk.notify("Tank is full\n Switch off motor IMMEDIATELY");
      delay(8000);
    }
    flag = 0;
  }
}

void level_check()
{
  if (digitalRead(D1) == HIGH)
  {
    state = 100;
    tank_full();
  }

  else
  {
    if (digitalRead(D2) == HIGH)
    {
      state = 75;
      flag = 1;
    }

    else
    {
      if (digitalRead(D5) == HIGH)
      {
        state = 50;
      }

      else
      {
        if (digitalRead(D6) == HIGH)
        {
          state = 25;
        }

        else
        {
          state = 0;
        }
      }
    }
  }
}

void notify()

{
  if ((state == 100) && (flag == 1))
  {

    Blynk.notify("Tank is full\n Switch off motor IMMEDIATELY");
    notification++;
  }

  flag = 0;

  if (Level_25 == HIGH)
  {
    Blynk.notify("Water Level is LOW\n Switch on motor");
  }

  if (Level_0 == HIGH)
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