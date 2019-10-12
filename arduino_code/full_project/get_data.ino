uint8_t getdata() {
  if (id<1)
  {
    id=1;
  }
  if (id>=1 && id<=maxid)
  {
  deleteFingerprint(id);
  int p = -1;
  lcd.clear();  
  lcd.setCursor(0,0);
  lcd.print("TAKE YOUR FINGER");
  while (p != FINGERPRINT_OK) {
    p = finger.getImage();
    switch (p) {
    case FINGERPRINT_OK:
      lcd.setCursor(0,1);
  lcd.print("IMAGE FIND");
      break;
    case FINGERPRINT_NOFINGER:  
  lcd.setCursor(0,1);
  lcd.print("WAITING......");
      break;
    }
  }
  p = finger.image2Tz(1);
  switch (p) {
    case FINGERPRINT_OK:
  lcd.clear();  
  lcd.setCursor(0,0);
  lcd.print("IMAGE CONVERTED");
      break;
  }
  lcd.setCursor(0,1);
  lcd.print("REMOVE FINGER");
  p = 0;
  while (p != FINGERPRINT_NOFINGER) {
    p = finger.getImage();
  }
  Serial.print("ID "); Serial.println(id);
  p = -1;
  lcd.clear();  
  lcd.setCursor(0,0);
  lcd.print("TAKE FINGER AGAIN");
  while (p != FINGERPRINT_OK) {
    p = finger.getImage();
    switch (p) {
    case FINGERPRINT_OK:
      lcd.setCursor(0,1);
  lcd.print("IMAGE FIND");
      break;
    case FINGERPRINT_NOFINGER:  
  lcd.setCursor(0,1);
  lcd.print("WAITING.......");
      break;
    }
  }
  p = finger.image2Tz(2);
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image converted");
      break;
  }
   lcd.clear();  
  lcd.setCursor(0,0);
  lcd.print("Creating on ID = ");  lcd.print(id);
  delay(1000);
  p = finger.createModel();
  if (p == FINGERPRINT_OK) {
    Serial.println("Prints matched!");
  }
  Serial.print("ID "); Serial.println(id);
  p = finger.storeModel(id);
  if (p == FINGERPRINT_OK) {
    lcd.setCursor(0,1);
  lcd.print("ID ");
  lcd.print(id);
  lcd.print(" Stored!");
  id = id + 1;
  } 
}
else 
{
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("SORY ID IS FULL ");
    lcd.setCursor(0,1);
    lcd.print("ERASE CURRENT ID");
    delay(100);
}
}
