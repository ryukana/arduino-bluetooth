
int BTReset = 3;
int LED = 13;

char inByte = 0;
int nowAction = 0;
void setup() {
  // make the Bluetooth Module reset:
  digitalWrite(BTReset, LOW);
  delay(100);
  digitalWrite(BTReset, HIGH);
  delay(500);
   
  // initialize serial communication at 115200 bits per second:
  Serial.begin(115200);
 
  pinMode(LED, OUTPUT);  // make a LED pin output
}

void loop() {
  // if we get a valid byte, read analog ins:
  if (Serial.available() > 0) {
    // get incoming byte:
    inByte = Serial.read();
    if (inByte == '0') {
      nowAction = 0;
    } else if (inByte == '5') {
      nowAction = 5;
    } else {
      nowAction = 9;
    }
    Serial.println(inByte); 
    delay(100);
  }
  delay(1);        // delay in between reads for stability
  
  if (nowAction == 0) {
      digitalWrite(LED, LOW);    
  } else if (nowAction == 5) {
      digitalWrite(LED, HIGH);
      delay(25);
      digitalWrite(LED, LOW);
      delay(25);    
  } else {
      digitalWrite(LED, HIGH);
  }
}
