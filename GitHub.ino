//defining the trigger and echo pins of Ultrasonic Sensor
#define trig 2
#define echo 4

//the buzzer attached to pin 8
int buzzer=8;
void setup() {
  //setting the pinmodes
  pinMode(trig,OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(echo,INPUT);
  //start serial monitor
  Serial.begin(9600);
}

void loop() {
  //getting distance from ultrasonic sensor
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);

  long t=pulseIn(echo,HIGH);

  long cm=t/29/2;

  //printing distances
  Serial.print(cm);
  Serial.println(" cm");

if(cm<55){
  //ring buzzer from 1KHz tone if the distance<55 cm
  tone(buzzer,1000);
  
}
else{
  //stop ringing the buzzer
  noTone(buzzer);
 
}



}
