#include <Adafruit_Sensor.h>
#include <Servo.h> 

#include<DHT.h>
#define DHTPIN 2
#define DHTTYPE DHT11
#define led 13
int servoPin = 3; 
int maxhum=10;
int maxtemp=18;
DHT dht(DHTPIN,DHTTYPE);
Servo Servo1;
void setup(){
pinMode(led,OUTPUT);
Serial.begin(9600);
dht.begin();
Servo1.attach(servoPin); 
}
void loop(){
delay(2000);
float h=dht.readHumidity();
float t=dht.readTemperature();
if(isnan(h)||isnan(t))
{
  Serial.println("Failed to read from sensor");
  return;
}
if(h>maxhum||t>maxtemp)
{
  Servo1.write(0); 

   delay(1000); 
   // Make servo go to 90 degrees 
   Servo1.write(90); 
   delay(1000); 
   // Make servo go to 180 degrees 
   Servo1.write(180); 
   delay(1000); 
}
else
{
digitalWrite(led,LOW);
}
Serial.println("Humidity:");
Serial.println(h);
Serial.print("%\t");
Serial.print("Temperature:");
Serial.print(t);
Serial.print("*C\n");
}

