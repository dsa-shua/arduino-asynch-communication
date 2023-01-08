#define d0 12
#define d1 11
#define d2 10
#define d3 9
#define d4 8
#define d5 7
#define d6 6
#define d7 5
#define REQ 3
#define ACK 2

// byte holders
int b0, b1,b2,b3,b4,b5,b6,b7;

int in_byte = 0;

void setup() {
  Serial.begin(9600);
  pinMode(REQ, INPUT);
  pinMode(ACK, OUTPUT);
}

void loop(){
  if (digitalRead(REQ) == HIGH) {
    delay(20);
    digitalWrite(ACK,HIGH);
    if (digitalRead(d0)) {b0 = 1;} else {b0 = 0;}
    if (digitalRead(d1)) {b1 = 1;} else {b1 = 0;}
    if (digitalRead(d2)) {b2 = 1;} else {b2 = 0;}
    if (digitalRead(d3)) {b3 = 1;} else {b3 = 0;}
    if (digitalRead(d4)) {b4 = 1;} else {b4 = 0;}
    if (digitalRead(d5)) {b5 = 1;} else {b5 = 0;}
    if (digitalRead(d6)) {b6 = 1;} else {b6 = 0;}
    if (digitalRead(d7)) {b7 = 1;} else {b7 = 0;}
    in_byte = b0 + (b1 << 1) + (b2 << 2) + (b3 << 3) + (b4 << 4) + (b5 << 5) + (b6 << 6) + (b7 << 7);
    Serial.print((char)in_byte);
    digitalWrite(ACK,HIGH);
    while (digitalRead(REQ) == HIGH) {digitalWrite(ACK,HIGH);} //spin lock
    digitalWrite(ACK,LOW);
  }
}
