void getdistance ()
{
digitalWrite(8, LOW);
delayMicroseconds(8);
digitalWrite(8, HIGH);
delayMicroseconds(8);
digitalWrite(8, LOW);
delayMicroseconds(8);
duration= pulseIn(9, HIGH);
distance= (duration/2) / 29.1;
Serial.println(distance);
}
