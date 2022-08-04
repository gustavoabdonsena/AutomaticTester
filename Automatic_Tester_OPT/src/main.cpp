#include <Arduino.h>

#define sense A1
#define trigger 3


void setup() {

  pinMode(sense,INPUT);
  pinMode(trigger, INPUT);

  Serial.begin(9600);
  Serial.println("Initialized");

}

void loop() {
  
  if(digitalRead(trigger) == true){
    Serial.println("Testing...");
    delay(800);
    Serial.println((String) analogRead(sense));
    //para 5v aplicados, para tensões diferentes necessitamos de um parâmetro de ref do arduino
    if(analogRead(sense) > 900){
      Serial.println("Ok!");
      delay(3000);
    }else{
      Serial.println("Error!");
      delay(1000);
    }
  }
  delay(200);

}