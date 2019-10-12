
void deletedata()
{
  for (id = 1; id <= maxid; id++)
  {
    deleteFingerprint(id);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("DATA ID = ");
    lcd.print(id);
    lcd.print(" DELETED");
    delay(100);
  }
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("ALL DATA DELETED");
}
uint8_t deleteFingerprint(uint8_t id) {
  uint8_t p = -1;
  p = finger.deleteModel(id);
  if (p == FINGERPRINT_OK) {
    Serial.println("Deleted!");
  } 
}
