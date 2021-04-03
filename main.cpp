// Revision 0.5 BATA, 04/02/2021
Maderdash




#include <Arduino.h>


//#define time 100
//#define hotairTc A0
//#define ironTc A1
//#define ironPot A2
//#define hotairPot A3
//BOOLEAN Inputs
int time = 100;
int hotairTc = A0;
int ironTc = A1;
int ironPot = A2;
int hotairPot = A3;




//DIGITAL inputs
//#define swMan 2
//#define swIron 3
//#define swAir 4
//#define hall 7
int swMan = 2;
int swIron =3;
int swAir = 4;
int hall = 7;


//DIGITAL outs PWM
//#define ironEl 5
//#define airEl 6
//#define extra 9
//#define fanOut 10
//#define led 11
int ironEl = 5;
int airEl = 6;
int fanOut = 9;
int led = 11;
int heat = false;
//OUTPUTS



void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
digitalWrite(ironEl, HIGH);
digitalWrite(airEl, HIGH);
}

void loop() {
//Read switches====================================================
int SwMan = digitalRead(swMan);//==================================
int SwIron = digitalRead(swIron);//================================
int SwAir = digitalRead(swAir);//==================================
int Hall = digitalRead(hall);//====================================
int HotairTc = analogRead(hotairTc);//=============================
int HotairPot = analogRead(hotairPot);//===========================
int IronTc = analogRead(ironTc);//=================================
int IronPot = analogRead(ironPot);//===============================
HotairTc = map(HotairTc, 0, 1023, 0, 1000);//======================
HotairPot = map(HotairPot, 0, 1023, 0, 480);//=====================
IronTc = map(IronTc, 0, 1023, 0, 1000);//==========================
IronPot = map(IronPot, 0, 1023, 0, 480);//=========================
//Read switches====================================================

if(Hall == HIGH || SwMan == HIGH){
  int heat = true;
}
else {(heat = false);}

if (SwAir == LOW && heat == true && HotairTc < HotairPot){
  digitalWrite(airEl, LOW);
}
else {digitalWrite(ironEl, HIGH);}
if (SwIron == LOW && IronTc < IronPot){
  digitalWrite(airEl, LOW);
}
else {digitalWrite(ironEl, HIGH);}



Serial.println(IronTc);
delay(time);
Serial.println(IronPot);
delay(time);
Serial.println(HotairTc);
delay(time);
Serial.println(HotairPot);
delay(time);

}
