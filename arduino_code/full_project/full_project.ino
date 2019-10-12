#include <Adafruit_Fingerprint.h> 
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);
#include <SoftwareSerial.h>
SoftwareSerial mySerial(2, 3);
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);
long duration,distance;
uint8_t id;
int scan;
int maxid = 5;
void setup()  
{
  lcd.begin();
//  lcd.backlight();
  pinMode(4,INPUT_PULLUP);
  pinMode(5,INPUT_PULLUP);
  pinMode(6,INPUT_PULLUP);
  pinMode(7,INPUT_PULLUP);
  pinMode(8,OUTPUT);
  pinMode(9,INPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);;
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  Serial.begin(9600);
  while (!Serial); 
  delay(100);
  finger.begin(57600);
  if (finger.verifyPassword()) {
    lcd.print("  SISTEM  READYY!!");
  } 
  lcd.clear();
  for (id = 1; id <= maxid; id++)
  {
    deleteFingerprint(id);
  }
  id = 1;
}
void loop() 
{
  getdistance(); 
  if (distance < 10)
  {
      lcd.clear ();
      lcd.setCursor(0,0);
      lcd.print("VERIFY YOUR ID!!!!");
    for (scan=0; scan<20; scan++)
    {
      lcd.setCursor(0,1);
      lcd.print("WAITING.....");
  getFingerprintID();
  delay(50);
  getdistance();
  }
if (distance > 10)
{
  for ( int go =0 ; go <10; go ++)
  {
      lcd.clear ();
      lcd.setCursor(0,0);
      lcd.print("SEE YOU");
      delay(100);
  }
  lcd.clear();
}
  }
  else if (digitalRead(4)==LOW)
  {
    deletedata();
    id = 1;
  delay(2000);
  }
  else if (digitalRead(5)==LOW)
  {
    getdata();
    delay(2000);
  }
  else
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("    DOOR LOCK   ");
    lcd.setCursor(0,1);
    lcd.print("   FINGERPRINT  ");
    delay(100);
  }
}
