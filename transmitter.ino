#include <stdlib.h>
#define REQ 10
#define ACK 11
int b0, b1, b2, b3, b4, b5, b6, b7;
char incomingByte = 0;

void setup() {
  Serial.begin(9600); // open the serial port at 9600 bits per second
  pinMode(REQ,OUTPUT);
  pinMode(ACK,INPUT);
}

void clear_bits() {
  //optional function
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
}


void print_bit() {
  incomingByte = Serial.read();
  if (incomingByte) {

    Serial.print((char)incomingByte);

    // MSB: B7, LSB: B0
    b0 = incomingByte & 0b1;
    b1 = (incomingByte & 0b10) >> 1;
    b2 = (incomingByte & 0b100) >> 2;
    b3 = (incomingByte & 0b1000) >> 3;
    b4 = (incomingByte & 0b10000) >> 4;
    b5 = (incomingByte & 0b100000) >> 5;
    b6 = (incomingByte & 0b1000000) >> 6;
    b7 = (incomingByte & 0b10000000) >> 7;
  
   if (b0 == 1) {
    digitalWrite(2,HIGH);
   } else {
    digitalWrite(2,LOW);
   }
   if (b1 == 1) {
    digitalWrite(3,HIGH);
   } else {
    digitalWrite(3,LOW);
   }
   if (b2 == 1) {
    digitalWrite(4,HIGH);
   } else {
   digitalWrite(4,LOW);
   }
   if (b3 == 1) {
    digitalWrite(5,HIGH);
   } else {
    digitalWrite(5,LOW);
   }
   if (b4 == 1) {
    digitalWrite(6,HIGH);
   } else {
    digitalWrite(6,LOW);
   }
   if (b5 == 1) {
    digitalWrite(7,HIGH);
   } else {
    digitalWrite(7,LOW);
   }   
   if (b6 == 1) {
    digitalWrite(8,HIGH);
   } else {
    digitalWrite(8,LOW);
   }
   if (b7 == 1) {
    digitalWrite(9,HIGH);
   } else {
    digitalWrite(9,LOW);
   }

  digitalWrite(REQ, HIGH);
  while(digitalRead(ACK) == LOW) {;} // spinlock (waiting to write)
  digitalWrite(REQ, LOW);

  }
}

void print_each() {
  incomingByte = Serial.read();   
}

void loop() {
  if (Serial.available() > 0) {
    delay(10);
    print_bit();
  }
}
