
#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 4

#define CLK_PIN   13
#define DATA_PIN  11
#define CS_PIN    10

// Hardware SPI connection
MD_Parola P = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);

int trigPin = 9;  // TRIG Pin
int echoPin = 8;  // ECHO Pin

float duration_us, distance_cm,distance_In;


void setup() {

  P.begin();

  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

}

void loop() {

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration_us = pulseIn(echoPin, HIGH);

  distance_cm = duration_us * 0.034/2;
  distance_In = duration_us * 0.0133/2 ;

  Serial.print("Distance(CM) : ");
  Serial.print(distance_cm);
  Serial.print(" cm ,,");

  Serial.println();


  Serial.print("distance(IN) : ");
  Serial.print(distance_In);
  Serial.println(" In");

  if (P.displayAnimate()){ 
    // P.displayClear();
    char result[8];
    dtostrf(distance_In , 6, 2, result);
    P.displayText(result, PA_CENTER, P.getSpeed(), 10000, PA_SCROLL_LEFT, PA_SCROLL_LEFT);
  }

  delay(500);

}
