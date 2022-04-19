#include <Servo.h>
Servo myservo;
#define aa 8    
#define AD 5
#define AS 2  
#define BD 6 
#define BS 3 
#define CD 7
#define CS 4 

#include <LiquidCrystal_I2C.h>
#define I2C_ADDR 0x27
#define BACKLIGHT_PIN 3
#define En_pin 2
#define Rw_pin  1
#define Rs_pin  0
#define D4_pin  4
#define D5_pin  5
#define D6_pin  6
#define D7_pin  7
LiquidCrystal_I2C  lcd(I2C_ADDR,En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin);

unsigned int e;
unsigned int motorspeed;
int k = 650;
int degree = 60;
int j = 300;

void setup() {
    pinMode(aa,OUTPUT); //enable of stepper
    pinMode(AD,OUTPUT); // direction pin of motor A
    pinMode(AS,OUTPUT); // step pin of motor B
    pinMode(BD,OUTPUT); // direction pin of motor B
    pinMode(BS,OUTPUT); // step pin of motor B
    pinMode(CD,OUTPUT); // direction pin of motor C
    pinMode(CS,OUTPUT); // step pin of motor C
    digitalWrite(aa,LOW); 
    pinMode(31,OUTPUT); // LED green 1
    pinMode(32,OUTPUT); // LED green 2
    pinMode(33,OUTPUT); // LED red 
    pinMode(18,OUTPUT); // Water pump's relay
    myservo.attach(26); // Servo
    lcd.begin (20,4);   // LCD
    lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
    lcd.setBacklight(HIGH);
}

void loop() {
int button = digitalRead(50); // Push Button
int switch1 = digitalRead(22);// Switch
int a= analogRead(A8);        // Moisture Sensor
a = map (a,0,1023,10,99);
int b= analogRead(A9);        // Limit
b = map (b,0,1023,99,10);
int c = analogRead(A11);      // Water Duration
c = map (c,0,1023,9,1);
int z = analogRead(A10);      // Motor's Speed
z = map (z,0,1023,4,9);
motorspeed = z * 100;
e = c*1000;

// Seeding
if (button == HIGH){
   digitalWrite(31,HIGH);

// Seed 1
   digitalWrite(AD,LOW); 
   digitalWrite(BD,LOW);
   digitalWrite(CD,LOW);             
    for(int i=0;i<k;i++)           
    {
        digitalWrite(AS,HIGH);
        delayMicroseconds(motorspeed);
        digitalWrite(BS,HIGH);
        delayMicroseconds(motorspeed);
        digitalWrite(CS,HIGH);
        delayMicroseconds(motorspeed);
        digitalWrite(AS,LOW);
        delayMicroseconds(motorspeed);
        digitalWrite(BS,LOW);
        delayMicroseconds(motorspeed);
        digitalWrite(CS,LOW);
        delayMicroseconds(motorspeed);
    }    
    myservo.write(degree);
    delay(j);
    myservo.write(0);
    delay(1000);

//Seed 2
   digitalWrite(CD,LOW);             
    for(int i=0;i<k;i++)           
    {       
        digitalWrite(CS,HIGH);
        delayMicroseconds(motorspeed);       
        digitalWrite(CS,LOW);
        delayMicroseconds(motorspeed);
    }    
    myservo.write(degree);
    delay(j);
    myservo.write(0);
    delay(1000);

// Seed 3
   digitalWrite(CD,LOW);             
    for(int i=0;i<k;i++)           
    {       
        digitalWrite(CS,HIGH);
        delayMicroseconds(motorspeed);       
        digitalWrite(CS,LOW);
        delayMicroseconds(motorspeed);
    }
    myservo.write(degree);
    delay(j);
    myservo.write(0);
    delay(1000);

//Seed 4
   digitalWrite(AD,LOW); 
   digitalWrite(BD,LOW);             
    for(int i=0;i<k;i++)           
    {
        digitalWrite(AS,HIGH);
        delayMicroseconds(motorspeed);
        digitalWrite(BS,HIGH);
        delayMicroseconds(motorspeed);        
        digitalWrite(AS,LOW);
        delayMicroseconds(motorspeed);
        digitalWrite(BS,LOW);
        delayMicroseconds(motorspeed);       
    }
    myservo.write(degree);
    delay(j);
    myservo.write(0);
    delay(1000);

// Seed 5
   digitalWrite(CD,HIGH);             
    for(int i=0;i<k;i++)           
    {       
        digitalWrite(CS,HIGH);
        delayMicroseconds(motorspeed);       
        digitalWrite(CS,LOW);
        delayMicroseconds(motorspeed);
    }
    myservo.write(degree);
    delay(j);
    myservo.write(0);
    delay(1000);

//Seed 6
   digitalWrite(CD,HIGH);             
    for(int i=0;i<k;i++)           
    {       
        digitalWrite(CS,HIGH);
        delayMicroseconds(motorspeed);
        digitalWrite(CS,LOW);
        delayMicroseconds(motorspeed);
    }
    myservo.write(degree);
    delay(j);
    myservo.write(0);
    delay(1000);

//Seed 7
  digitalWrite(AD,LOW); 
  digitalWrite(BD,LOW);             
    for(int i=0;i<k;i++)           
    {
        digitalWrite(AS,HIGH);
        delayMicroseconds(motorspeed);
        digitalWrite(BS,HIGH);
        delayMicroseconds(motorspeed);        
        digitalWrite(AS,LOW);
        delayMicroseconds(motorspeed);
        digitalWrite(BS,LOW);
        delayMicroseconds(motorspeed);       
    }
    myservo.write(degree);
    delay(j);
    myservo.write(0);
    delay(1000);

//Seed 8
   digitalWrite(CD,LOW);             
    for(int i=0;i<k;i++)           
    {       
        digitalWrite(CS,HIGH);
        delayMicroseconds(motorspeed);
        digitalWrite(CS,LOW);
        delayMicroseconds(motorspeed);
    }
    myservo.write(degree);
    delay(j);
    myservo.write(0);
    delay(1000);

//Seed 9
   digitalWrite(CD,LOW);             
    for(int i=0;i<k;i++)           
    {       
        digitalWrite(CS,HIGH);
        delayMicroseconds(motorspeed);
        digitalWrite(CS,LOW);
        delayMicroseconds(motorspeed);
    }
    myservo.write(degree);
    delay(j);
    myservo.write(0);
    delay(1000);

//Return Normal Place
   digitalWrite(AD,HIGH); 
   digitalWrite(BD,HIGH);
   digitalWrite(CD,HIGH);             
    for(int i=0;i<1950;i++)           
    {
        digitalWrite(AS,HIGH);
        delayMicroseconds(motorspeed);
        digitalWrite(BS,HIGH);
        delayMicroseconds(motorspeed);
        digitalWrite(CS,HIGH);
        delayMicroseconds(motorspeed);
        digitalWrite(AS,LOW);
        delayMicroseconds(motorspeed);
        digitalWrite(BS,LOW);
        delayMicroseconds(motorspeed);
        digitalWrite(CS,LOW);
        delayMicroseconds(motorspeed);
    } 
    digitalWrite(31,LOW);
} 

// Watering
    if (switch1 == HIGH && a <= b){
   digitalWrite(33,HIGH);
   digitalWrite(32,LOW);
   digitalWrite(AD,LOW); 
   digitalWrite(BD,LOW);
   digitalWrite(CD,LOW);             
    for(int i=0;i<1350;i++)           
    {
        digitalWrite(AS,HIGH);
        delayMicroseconds(motorspeed);
        digitalWrite(BS,HIGH);
        delayMicroseconds(motorspeed);
        digitalWrite(CS,HIGH);
        delayMicroseconds(motorspeed);
        digitalWrite(AS,LOW);
        delayMicroseconds(motorspeed);
        digitalWrite(BS,LOW);
        delayMicroseconds(motorspeed);
        digitalWrite(CS,LOW);
        delayMicroseconds(motorspeed);
    } 
    
   digitalWrite(18,HIGH);
   delay(e);
   digitalWrite(18,LOW);
   
   digitalWrite(AD,HIGH); 
   digitalWrite(BD,HIGH);
   digitalWrite(CD,HIGH);             
    for(int i=0;i<1350;i++)           
    {
        digitalWrite(AS,HIGH);
        delayMicroseconds(motorspeed);
        digitalWrite(BS,HIGH);
        delayMicroseconds(motorspeed);
        digitalWrite(CS,HIGH);
        delayMicroseconds(motorspeed);
        digitalWrite(AS,LOW);
        delayMicroseconds(motorspeed);
        digitalWrite(BS,LOW);
        delayMicroseconds(motorspeed);
        digitalWrite(CS,LOW);
        delayMicroseconds(motorspeed);
    } 
 digitalWrite(33,LOW);
}

 if (switch1 == HIGH && a >= b){
 digitalWrite(18,LOW);
 digitalWrite(32,HIGH);
 digitalWrite(33,LOW);
}
if (switch1 == LOW){
  digitalWrite(18,LOW);
  digitalWrite(32,LOW);
  digitalWrite(33,LOW);
}

// Displaying in LCD
 lcd.setCursor(3,0);
 lcd.print("Auto Planting");
 lcd.setCursor(0,1);  
 lcd.print("Moisture = ");
 lcd.print(a);
 lcd.print("/");
 lcd.print(b);
 lcd.setCursor(0,2);
 lcd.print("Watering Time = ");
 lcd.print(c);
 lcd.setCursor(0,3);
 lcd.print("Motorspeed = ");
 lcd.print(z);
}
