#include <Servo.h>
Servo myservo;
int pos = 0;
int cm = 0;
// Fungsi untuk Membaca Jarak Menggunakan Sensor Ultrasonik
long readUltrasonicDistance(int triggerPin, int echoPin)
{
pinMode(triggerPin, OUTPUT);
digitalWrite(triggerPin, LOW);
delayMicroseconds(2);
digitalWrite(triggerPin, HIGH);
delayMicroseconds(10);
digitalWrite(triggerPin, LOW);
pinMode(echoPin, INPUT);
return pulseIn(echoPin, HIGH);
}

// Menyiapkan Servo
void setup() {
digitalWrite(12,LOW);
myservo.attach(9);
Serial.begin(9600);
}
void loop() {
cm = 0.01723 * readUltrasonicDistance(6, 7);
if(cm<30){
Serial.print(cm);
Serial.println("cm");
for (pos = 0; pos <= 120; pos += 1) { // Ketika gate naik
myservo.write(pos);
delay(15);
}
delay(500);
for (pos = 120; pos >= 0; pos -= 1) { // ketika gate turun
myservo.write(pos);
delay(100);
}
delay(5000); //add delay how much you want
}
}
