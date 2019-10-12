#include <Adafruit_Fingerprint.h> 
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);
#include <SoftwareSerial.h>
SoftwareSerial mySerial(2, 3);
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);
long durasi, jarak;
uint8_t id;
void setup()  
{
  lcd.begin();
  lcd.backlight();
  pinMode(4,INPUT_PULLUP);
  pinMode(5,INPUT_PULLUP);
  pinMode(6,INPUT_PULLUP);
  pinMode(7,INPUT_PULLUP);
  pinMode(8,OUTPUT);
  pinMode(9,INPUT);
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  Serial.begin(9600);
  while (!Serial); 
  delay(100);
  pinMode(13,OUTPUT);
  finger.begin(57600);
  if (finger.verifyPassword()) {
    lcd.print("  SISTEM  READYY!!");
  } else {
    lcd.print("Did not find fingerprint sensor :(");
    while (1) { delay(1); }
  }
  Serial.println("Waiting for valid finger...");
}
void loop() 
{
  lcd.clear();
digitalWrite(8, LOW);
delayMicroseconds(8);
digitalWrite(8, HIGH);
delayMicroseconds(8);
digitalWrite(8, LOW);
delayMicroseconds(8);
durasi= pulseIn(9, HIGH);  // menerima suara ultrasonic
jarak= (durasi/2) / 29.1;     // mengubah durasi menjadi jarak (cm)
Serial.println(jarak); 
  if (jarak < 10)
  {
  getFingerprintID();
  delay(50);            //don't ned to run this at full speed.
  }
  else if (digitalRead(4)==LOW)
  {
    deletedata();
    id = 1;
  delay(3000);
  }
  else if (digitalRead(5)==LOW)
  {
    getdata();
    delay(5000);
  }
}
