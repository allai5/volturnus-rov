#include <XBOXRECV.h>

USB Usb ;  
XBOXRECV Xbox(&Usb) ;
int x1;
int y1;
int a1=2;
int a2=3;
int b1=4;
int b2=5;
int c1=6;
int c2=7;
int d1=8;
int d2=9;
int a=10;
int b=11;
int c=12;
int d=13;
void setup() {
  // put your setup code here, to run once:
  Usb.Init() ; 
  Serial.begin(9600);
  pinMode(a1,OUTPUT);
  pinMode(a2,OUTPUT);
  pinMode(a,OUTPUT);
  pinMode(b1,OUTPUT);
  pinMode(b2,OUTPUT);
  pinMode(b,OUTPUT);
  pinMode(c1,OUTPUT);
  pinMode(c2,OUTPUT);
  pinMode(c,OUTPUT);
  pinMode(d1,OUTPUT);
  pinMode(d2,OUTPUT);
  pinMode(d,OUTPUT);
  
}

void loop() 
{
  Usb.Task() ; 
  if (Xbox.XboxReceiverConnected) 
  {
    x1=Xbox.getAnalogHat(LeftHatX , 0);
    y1=Xbox.getAnalogHat(LeftHatY , 0);
    //speed = Xbox.getAnalogHat(LeftHatY , 0) / 128 ;

    //speed = -Xbox.getAnalogHat(LeftHatY , 0) / 128 ;
    if (x1>9000){
      digitalWrite(a,HIGH);
      digitalWrite(b,HIGH);
      analogWrite(a1,x1/128);
      analogWrite(a2,0);
      analogWrite(b1,0);
      analogWrite(b2,x1/128);
      Serial.println("1");
      Serial.println(x1/128) ;
    }
    else if (x1<-9000){
      analogWrite(a,x1/128);
      analogWrite(b,x1/128);
      analogWrite(a1,0);
      analogWrite(a2,255);
      analogWrite(b1,255);
      analogWrite(b2,0);
      Serial.println(x1/128) ;
    }
    else{
      digitalWrite(a,LOW);
      digitalWrite(b,LOW);
      analogWrite(a1,0);
      analogWrite(a2,0);
      analogWrite(b1,0);
      analogWrite(b2,0);
    }
   }
}
