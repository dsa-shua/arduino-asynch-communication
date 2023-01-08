#include <stdlib.h>

#define REG_COUNT 8
  unsigned int CYCLES = 0;
  unsigned int MAX_CYCLES = 1;
  int *x_reg = (int*)malloc(REG_COUNT * sizeof(int));
  char incomingByte = 0; // for incoming serial data
  String in_text;
  int b0, b1, b2, b3, b4, b5, b6, b7;

void name1(){
   for (int i = 0; i < x_reg[REG_COUNT]; i=i+1){
    x_reg[i] = i;
  }
}
  
void setup() {
  Serial.begin(9600); // open the serial port at 9600 bits per second
  name1();
}

void printlist(){
    while(CYCLES < MAX_CYCLES) {
    CYCLES++;  
    Serial.print("-------Begin--------\n");  
    for (int i = 0; i < REG_COUNT; i++){
      Serial.print("[");
      Serial.print(i);
      Serial.print("]: ");
      Serial.println(x_reg[i]);
    }
    Serial.println("--------End---------\n");  
  }
}

void print_string() {
  in_text = Serial.readStringUntil('\n');
  Serial.print(">>> ");
  Serial.println(in_text);
}

void print_bit() {
  incomingByte = Serial.read();
  if (incomingByte != 10) {
    Serial.print(">>> ");
    Serial.print("CHAR: ");
    Serial.print((char)incomingByte);
    Serial.print(" | DEC: ");
    Serial.print(incomingByte, DEC);
    Serial.print(" | ");
    Serial.println(incomingByte, BIN);
    // MSB: B7, LSB: B0
    b0 = incomingByte & 0b1;
    b1 = (incomingByte & 0b10) >> 1;
    b2 = (incomingByte & 0b100) >> 2;
    b3 = (incomingByte & 0b1000) >> 3;
    b4 = (incomingByte & 0b10000) >> 4;
    b5 = (incomingByte & 0b100000) >> 5;
    b6 = (incomingByte & 0b1000000) >> 6;
    b7 = (incomingByte & 0b10000000) >> 7;

   Serial.println(b0);
   Serial.println(b1);
   Serial.println(b2);
   Serial.println(b3);
   Serial.println(b4);
   Serial.println(b5);
   Serial.println(b6);
   Serial.println(b7);

  
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

//   Serial.println("Stored Bits:");
//   Serial.println(d0);
//   Serial.println(d1);
//   Serial.println(d2);
//   Serial.println(d3);
//   Serial.println(d4);
//   Serial.println(d5);
//   Serial.println(d6);
//   Serial.println(d7);
  }
}

void print_each() {
  incomingByte = Serial.read();   
}

void loop() {
  delay(10);
  if (Serial.available() > 0) {
  print_bit();
  }
}
