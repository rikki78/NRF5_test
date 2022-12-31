#include <Arduino.h>

#define LED 17

#define MY_RADIO_RF24
#define MY_RADIO_NRF5_ESB
#define MY_NODE_ID 182
#define ARDUINO_GENERIC
#define SKETCH_NAME "NRF52 Test"
#define SKETCH_VERSION "0.1"

#include <MySensors.h>

#define CHILD_ID 1
MyMessage msg(CHILD_ID, V_VAR1);

void presentation()
{
  sendSketchInfo(SKETCH_NAME, SKETCH_VERSION);
  present(CHILD_ID, S_CUSTOM);
}

void setup()
{
  pinMode(LED, OUTPUT);
  Serial.begin(115200);
  //Serial.setPins();
}

void loop()
{
  static uint8_t num;
  Serial.print("Send ");
  Serial.print(num);
  if (send(msg.set(num)))
  {
    Serial.println(" ok ");
  } 
  else
  {
    Serial.println(" fail ");
  } 

  num++;
  digitalWrite(LED, HIGH);
  wait(5000);
  digitalWrite(LED, LOW);
  wait(5000);
}