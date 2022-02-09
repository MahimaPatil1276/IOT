const int BUZZER=5;
void setup()
 {
  // put your setup code here, to run once:
pinMode(BUZZER,OUTPUT);
Serial.begin(115200);
}

void loop()
 {
  // put your main code here, to run repeatedly:
digitalWrite(BUZZER,HIGH);
Serial.println("BUZZER ON\n");
delay(2000);

digitalWrite(BUZZER,LOW);
Serial.println("BUZZER OFF\n");
delay(2000); 
}
