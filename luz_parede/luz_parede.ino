#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>

int jantar = 5;
int corredor = 6;
int espelho = 7;
int parede = 8;

int buttonState1;
int buttonState2;
int buttonState3;
int buttonState4;
int buttonStateAll;

SoftwareSerial Bluetooth(0, 1);
char Data;
void sendData(String transmitData){
Bluetooth.println(transmitData);}

void setup(){
    Bluetooth.begin(9600);
    pinMode(jantar,OUTPUT);
    pinMode(corredor,OUTPUT);
    pinMode(espelho,OUTPUT);
    pinMode(parede,OUTPUT);
    digitalWrite(jantar,HIGH);
    digitalWrite(corredor,HIGH);
    digitalWrite(espelho,HIGH);
    digitalWrite(parede,HIGH);
}

void loop(){
      
    if(Bluetooth.available()){
        Data=Bluetooth.read();
        buttonState1 = digitalRead(jantar);
        buttonState2 = digitalRead(corredor);
        buttonState3 = digitalRead(espelho);
        buttonState4 = digitalRead(parede);
        buttonStateAll = digitalRead(jantar);
        
        if (buttonState1 == 0 && Data==('A')){
            digitalWrite(jantar,1);
            sendData("Sala de Jantar Light OFF");
        }
        if (buttonState1 == 1 && Data==('A')){
            digitalWrite(jantar,0);
            sendData("Sala de Jantar Light ON");    
        }        
        if (buttonState2 == 0 && Data==('B')){
            digitalWrite(corredor,1);
            sendData("Corredor Light OFF");
        }
        if (buttonState2 == 1 && Data==('B')){
            digitalWrite(corredor,0);
            sendData("Corredor Light ON");    
        }
        if (buttonState3 == 0 && Data==('C')){
            digitalWrite(espelho,1);
            sendData("Espelho Light OFF");
        }
        if (buttonState3 == 1 && Data==('C')){
            digitalWrite(espelho,0);
            sendData("Espelho Light ON");    
        }
        if (buttonState4 == 0 && Data==('D')){
            digitalWrite(parede,1);
            sendData("Parede OFF");
        }
        if (buttonState4 == 1 && Data==('D')){
            digitalWrite(parede,0);
            sendData("Parede Light ON");    
        }
        if (buttonStateAll == 1 && Data==('H')){
            digitalWrite(jantar,0);
            digitalWrite(corredor,0);
            digitalWrite(espelho,0);
            digitalWrite(parede,0);
            sendData("ALL LIGHTS ON");
        }
        if (buttonStateAll == 0 && Data==('H')){
            digitalWrite(jantar,1);
            digitalWrite(corredor,1);
            digitalWrite(espelho,1);
            digitalWrite(parede,1);
            sendData("ALL LIGHTS OFF");
        }
        if (buttonStateAll == 0 && Data==('I')){
            digitalWrite(jantar,1);
            digitalWrite(corredor,1);
            digitalWrite(espelho,1);
            digitalWrite(parede,1);
            sendData("ALL LIGHTS OFF");
        }
    }
}
