
           //book 11 ,12,7,2,4,9,10,3,5 0,1
                     //  ,8,13     ,A0,A1,A2,A3,A4,A5



int trig = 13;    // sonar sensor
int echo = 12;
float distance=25;
float duration;


int MotorA_in1 =2;   //motor driver pin     motor A right side
int MotorA_in2 =3;
int MotorB_in3 =4;     // motor B left side         
int MotorB_in4 =5;
int MotorA_PWM =A1;
int MotorB_PWM =A2;

char sms;
int spd= 150;

void setup() {
  Serial.begin(9600);
       pinMode(trig, OUTPUT);  //ultrasonic sensor
       pinMode(echo, INPUT);
   
  pinMode(MotorA_in1, OUTPUT);
  pinMode(MotorA_in2, OUTPUT);
  pinMode(MotorB_in3, OUTPUT);
  pinMode(MotorB_in4, OUTPUT);
  pinMode(MotorA_PWM, OUTPUT);
  pinMode(MotorB_PWM, OUTPUT);  
}

void loop() {
             // default things
        analogWrite(MotorA_PWM, spd);   //used PWM
        analogWrite(MotorB_PWM, spd);
      
        //ultrasonic sensor
         sonar();
         
  
                        // iF you use Andriod Phone
   
   if(Serial.available()) {
   sms = Serial.read();
            if(distance <25 && distance!=0) {
           
            self();
            delay(200);
         }
   

      if(sms == 'B') {
    RobotBackward();
   }
   if(sms == 'F' && distance>25) {
    RobotForward();
   }
   if(sms == 'R' && distance>25) {
    RobotRight();
   }
   if(sms == 'L' && distance>25) {
    RobotLeft();
   }
      if(sms == 'S' && distance>25) {
    RobotStop();
   }

                      // Speed control
   if(sms == '0') {
    spd = 0;
   }
      if(sms == '1') {
    spd = 28;
   }
      if(sms == '2') {
    spd = 56;
   }
      if(sms == '3') {
    spd = 84;
   }
      if(sms == '4') {
    spd = 112;
   }
      if(sms == '5') {
    spd = 140;
   }
      if(sms == '6') {
    spd = 168;
   }
      if(sms == '7') {
    spd = 196;
   }
      if(sms == '8') {
    spd = 224;
   }
      if(sms == '9') {
    spd = 255;
   }

   } 

} 
           
// robot movement function   
void RobotForward() {

  digitalWrite(MotorA_in1, LOW);  //clockwiwse
  digitalWrite(MotorA_in2, HIGH);
  digitalWrite(MotorB_in3, HIGH);
  digitalWrite(MotorB_in4, LOW);

}

void RobotStop() {

  digitalWrite(MotorA_in1, LOW);
  digitalWrite(MotorA_in2, LOW);
  digitalWrite(MotorB_in3, LOW);
  digitalWrite(MotorB_in4, LOW);

}

void RobotBackward() {

  digitalWrite(MotorA_in1, HIGH);
  digitalWrite(MotorA_in2, LOW);
  digitalWrite(MotorB_in3, LOW);
  digitalWrite(MotorB_in4, HIGH);
  
}


void RobotRight() {
  
    digitalWrite(MotorA_in1, HIGH);
  digitalWrite(MotorA_in2, LOW);
  digitalWrite(MotorB_in3, HIGH);
  digitalWrite(MotorB_in4, LOW);

}

void RobotLeft() {

    digitalWrite(MotorA_in1, LOW);
  digitalWrite(MotorA_in2, HIGH);
  digitalWrite(MotorB_in3, LOW);
  digitalWrite(MotorB_in4, HIGH);   
}

void sonar() {
            digitalWrite(trig, LOW);
        delay(2);
        digitalWrite(trig, HIGH);
        delayMicroseconds(10);
        digitalWrite(trig,LOW);
        duration =pulseIn(echo, HIGH); 
        distance=(duration*0.0332)/2;  // calculated in cm
        Serial.print("distance is=");
        Serial.print(distance);
        Serial.print("cm\n");
}


void self() {
  RobotBackward();
}
        
    
