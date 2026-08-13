#define motor1 5
#define motor2 18
#define pwm 19
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
  pinMode(pwm, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  int velocidade = 0;
  int modo= -1;

  while(Serial.available()==0){
    //esperar
  }
  modo = Serial.parseInt();
  velocidade = Serial.parseInt();
  if(modo==0){
    digitalWrite(motor1, LOW);
    digitalWrite(motor2, LOW);
    analogWrite(pwm, velocidade);
    }

  if(modo==1){
    digitalWrite(motor1, HIGH);
    digitalWrite(motor2, LOW);
    analogWrite(pwm, velocidade);
    }
  if(modo==2){
    digitalWrite(motor1, LOW);
    digitalWrite(motor2, HIGH);
    analogWrite(pwm, velocidade);
  }

  Serial.println(modo);
  Serial.println(velocidade);
  delay(5000);
}
