#define ERROR_WINDOW 50  // +/- this value
#define BUTTONDELAY 20
#define DEBUG_ON


int calibrationTime = 1;        
long unsigned int lowIn;         
long unsigned int pause = 5000;  
boolean lockLow = true;
boolean takeLowTime;  
int pirPin = 7;
int led_r = 11;   
int led_g = 8;
int led_y = 12;
int led_b = 10;
int piezo = 9;
int btn1 = A2;
int btn2 = A3;
int button1 = 0;
int button2 = 0;
int state = 0;
long buttonLastChecked = 0;

void setup(){
  Serial.begin(9600);
  pinMode(pirPin, INPUT);
  pinMode(led_r, OUTPUT);
  pinMode(led_g, OUTPUT);
  pinMode(led_y, OUTPUT);
  pinMode(led_b, OUTPUT);
  pinMode(piezo, OUTPUT);
  digitalWrite(pirPin, LOW);
  digitalWrite(led_g, HIGH);

  //give the sensor some time to calibrate
  digitalWrite(led_y, HIGH);
  Serial.print("calibrating sensor ");
  analogWrite(piezo, 500);
  delay(500);
  analogWrite(piezo, 0);
    for(int i = 0; i < calibrationTime; i++){
      Serial.print(".");
      delay(1000);
      }
    Serial.println(" done");
    Serial.println("SENSOR ACTIVE");
    analogWrite(piezo, 100);
    delay(500);
    analogWrite(piezo, 0);
    delay(50);
    digitalWrite(led_y, LOW);
  }

int button() {
  if( buttonLastChecked == 0 ) // see if this is the first time checking the buttons
    buttonLastChecked = millis()+BUTTONDELAY;  // force a check this cycle
  if( millis() - buttonLastChecked > BUTTONDELAY ) { // make sure a reasonable delay passed
    if( int buttNum = buttonPushed(btn1) ) return buttNum;  
    buttonLastChecked = millis(); // reset the lastChecked value
  }
  return 0;
}

int buttonPushed(int pinNum) {
  int val = 0;         // variable to store the read value
  digitalWrite((14+pinNum), HIGH); // enable the 20k internal pullup
  val = analogRead(pinNum);   // read the input pin
  if( val >= 0 and val <= (20+ERROR_WINDOW) ) return 5;
  else return 0;  // no button found to have been pushed
}

void loop(){
  state += button();
  
    if(state == 5) {
      digitalWrite(led_b, HIGH);
      if(digitalRead(pirPin) == HIGH){
        digitalWrite(led_r, HIGH);
        delay(50);
        digitalWrite(led_b, LOW);
        delay(50);
        if(lockLow){ 
          analogWrite(piezo, 500);  
          lockLow = false;            
          Serial.println("---");
          Serial.print("motion detected at ");
          Serial.print(millis()/1000);
          Serial.println(" sec"); 
          delay(100);
          analogWrite(piezo, 0);
        } takeLowTime = true;
      }
      if(digitalRead(pirPin) == LOW){ 
        digitalWrite(led_b, LOW); 
        delay(50);     
        if(takeLowTime){
          lowIn = millis();          
          takeLowTime = false;
        }
        if(!lockLow && millis() - lowIn > pause){
          digitalWrite(led_r, LOW);
          delay(50);  
          digitalWrite(led_y, HIGH); 
          delay(50); 
          analogWrite(piezo, 500);
          lockLow = true;
          delay(500);           
          Serial.print("motion ended at ");      //output
          Serial.print((millis() - pause)/1000);
          Serial.println(" sec");
          delay(50);
          analogWrite(piezo, 0);
          digitalWrite(led_y, LOW);
          delay(50); 
          digitalWrite(led_b, HIGH);
          delay(50); 
        }
       }
    }
    if(state == 10) {
      state = 0;
      digitalWrite(led_b, LOW);
      delay(50);
    }
}
