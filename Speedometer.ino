#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <math.h>

float start, finished;
float elapsed, time;
float wheelRadius = 5; //inches
float circ; //circumference or distance per revolution
float speedmph;
int i = 0;

//Hall Sensor Digital In
int hallPin = 2;

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  circ = M_PI*2*wheelRadius;
  pinMode(hallPin, INPUT);

  attachInterrupt(digitalPinToInterrupt(2), speedCalc, RISING);
  
  lcd.init();// initialize the lcd 
  lcd.backlight();

  lcd.setCursor(1,0);
  lcd.print("Initializing");
  lcd.setCursor(1,1);
  lcd.print("eKart v1.9.0");
  delay(3000);
  lcd.clear();
  
  lcd.setCursor(1,0);
  lcd.print("CURRENT SPEED:");
  lcd.setCursor(7,1);
  lcd.print("mph");

}

void speedCalc(){
  if((millis()-start)>60){
    elapsed=millis()-start;

    //i=i+1;
    
    start=millis();

    speedmph = (56.8182*circ)/elapsed;
  }
}

void loop()
{
  lcd.setCursor(1,1);
  lcd.print(speedmph);
  /*if(millis()-start>5000){
    speedmph = 0;
  }*/
}
