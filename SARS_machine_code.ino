1//Final Version of SARS code
#include <Servo.h>
Servo serv;
int trig = 5;
int echo = 6;

long duration;
int distance;

void setup() {
  // put your setup code here, to run once:
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  serv.attach(10);
  Serial.begin(9600);

  serv.write(90);
}

void giveSanitiser(){
  serv.write(130);
  delay(10);
  serv.write(0);
  delay(1000);
  serv.write(130);
}

int findDistance(){
  digitalWrite(trig,LOW);
  delayMicroseconds(10);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);

  duration = pulseIn(echo, HIGH);
  distance = duration*0.034/2;
  //Serial.write(distance);
  return int(distance);
}

void checkDistance(){

  if((distance < 100) && (distance > 20)){    //For testing only, final version will use speaker

    Serial.println(distance);
    noTone(8);
    // play a note on pin 6 for 200 ms:
    tone(8, 440, 100);
    delay(250);
  }
  
  if((distance < 4) && (distance!=0)){
    giveSanitiser();
  }
  
  else{
    
    Serial.println(distance); 
  }
  
}

void loop() {
   // put your main code here, to run repeatedly:
 
  findDistance();
  checkDistance(); 
}
