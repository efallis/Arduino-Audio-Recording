#define AVERAGE 10
#define BAUD 115200

int i;
double transmitted = 0;
double sum;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(BAUD);

  setRes(3, 11);
}

void loop() {
  // put your main code here, to run repeatedly:

  sum = 0;
  for(i=0;i<AVERAGE;i++)
  {
    sum += analogRead(0);
  }
  sum /= AVERAGE;
  
  Serial.println(String("") + sum);
}

void setRes(int m, int sel){
  digitalWrite(sel, 0);
  //Delay, giving time for pin to pull down
  delay(10);
  //Write CS low, indicating start of resistance change
  digitalWrite(13, 0);
  //Convert potentiometer to known state
  for (int i = 0; i < 64; i++){
    delay(5);
    digitalWrite(sel, !digitalRead(sel));
    delay(5);
    digitalWrite(sel, !digitalRead(sel));
  }
  digitalWrite(13,1);

  //Write to up/down pin (up)
  digitalWrite(sel, 1);
  delay(10);
  //Write CS low, indicating start of resistance change
  digitalWrite(13, 0);
  //Convert potentiometer to known state3
  for (int i = 0; i < m; i++){
    delay(5);
    digitalWrite(sel, !digitalRead(sel));
    delay(5);
    digitalWrite(sel, !digitalRead(sel));
  } 
}
