uint8_t getFingerprintID() {

  uint8_t p = finger.getImage();
  switch (p) {
    case FINGERPRINT_OK:
      scan = 21;
      Serial.println("Image taken");
      break;
    case FINGERPRINT_NOFINGER:
      //Serial.println(".");
      return p;
  }
  p = finger.image2Tz();
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image converted");
      break;
  }
  p = finger.fingerFastSearch();
  if (p == FINGERPRINT_OK) {
    Serial.println("Found a print match!");
  } else if (p == FINGERPRINT_NOTFOUND) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("YOUR ID FAULT");
    delay(1000);
    return p;
  } else {
    Serial.println("Unknown error");
    return p;
  }
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Found ID #"); lcd.print(finger.fingerID);
  lcd.setCursor(0, 1);
  lcd.print("DOOR IS OPENED");
  analogWrite(10, 100);
  delay(2000);
  analogWrite(10, 0);
  analogWrite(11, 100);
  lcd.setCursor(0, 1);
  lcd.print("DOOR IS CLOSED");
  delay(2000);
  analogWrite(11, 0);

  return finger.fingerID;
}
