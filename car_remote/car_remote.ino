#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>


int ENA = D6;
int IN1 = D0;
int IN2 = D1;

int ENB = D7;
int IN3 = D2;
int IN4 = D3;

//connect Blynk and Wifi
char auth[] = ""; //auth of blynk
char ssid[] = ""; //nameofwifi
char pass[] = ""; //passwordwifi

//function controller a car
void moveControl(int x)
{
  if (x == 1)
  {
    analogWrite(ENA, 1024);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);

    analogWrite(ENB, 1024);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);

  }
  else
  {
    analogWrite(ENA, 1024);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);

    analogWrite(ENB, 1024);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
  }
}

void moveControlLeft(int x)
{
  if (x == 1)
  {
    analogWrite(ENA, 1024);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);

  }
  else
  {
    analogWrite(ENA, 1024);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);

    analogWrite(ENB, 1024);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
  }
}

void moveControlright(int x)
{
  if (x == 1)
  {
    analogWrite(ENB, 1024);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);

  }
  else
  {
    analogWrite(ENA, 1024);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);

    analogWrite(ENB, 1024);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
  }
}

void moveControlBack(int x)
{
  if (x == 1)
  {
    analogWrite(ENA, 1024);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);

    analogWrite(ENB, 1024);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  }
  else
  {
    analogWrite(ENA, 1024);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);

    analogWrite(ENB, 1024);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
  }
}

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop()
{
  Blynk.run();
}

BLYNK_WRITE(V2)
{
  int x = param[0].asInt();

  Serial.print("B value is: ");
  Serial.println(x);

  moveControl(x);
}

BLYNK_WRITE(V1)
{
  int x = param[0].asInt();

  Serial.print("B value is: ");
  Serial.println(x);

  moveControlLeft(x);
}

BLYNK_WRITE(V3)
{
  int x = param[0].asInt();

  Serial.print("B value is: ");
  Serial.println(x);

  moveControlright(x);
}

BLYNK_WRITE(V4)
{
  int x = param[0].asInt();

  Serial.print("B value is: ");
  Serial.println(x);

  moveControlBack(x);
}
