int i;
int sensorValue=0;

void setup(){
  pinMode(12, OUTPUT); 
  pinMode(11, OUTPUT); 
  pinMode(8,OUTPUT);
  pinMode(3,OUTPUT);
  Serial.begin(9600);
}

void loop(){
  sensorValue=analogRead(A0);
  
  Serial.println(sensorValue,DEC);
  if(sensorValue > 25 && sensorValue < 80){
    digitalWrite(8, LOW);
    for (i = 0; i < 350; i++){
      digitalWrite(3, LOW);
      digitalWrite(12, HIGH); // active sound
      digitalWrite(11, HIGH); // active led
      delay(1); 
      digitalWrite(12, LOW); // deactive sound
      delay(1); 
    }
    delay (30); 
    for (i = 0; i < 150; i++) {
      digitalWrite(12, HIGH); 
      digitalWrite(11, LOW); 
      delay(2); 
      digitalWrite(12, LOW); 
      delay(2); 
    }
  }
  else if(sensorValue>80){
     for (i = 0; i < 350; i++){
        digitalWrite(3,LOW);
    	digitalWrite(12, HIGH); 
   	 	digitalWrite(8, HIGH); 
	    delay(1); 
    	digitalWrite(12, LOW); 
	    delay(1);
     }
  }
  else {
    digitalWrite(3, HIGH);
	digitalWrite(8, LOW);
	digitalWrite(11,LOW);
  }
}
