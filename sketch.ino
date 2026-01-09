
const int buttonPin = 2;
const int relayPin  = 8;
const int buzzerPin = 9;
const int timerLED  = 13;


const unsigned long totalTime = 10000; 
const unsigned long onTime = 3000;      
bool running = false;
unsigned long startTime = 0;
unsigned long lastBeep = 0;
bool finished = false;
unsigned long finishTime = 0;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(relayPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(timerLED, OUTPUT);

  digitalWrite(relayPin, LOW);
  digitalWrite(timerLED, LOW);
  digitalWrite(buzzerPin, LOW);
}

void loop() {
  unsigned long currentMillis = millis();

  if (digitalRead(buttonPin) == LOW && !running && !finished) {
    delay(200); 
    running = true;
    startTime = currentMillis;
    lastBeep = 0;
  }

  
  if (running) {
    unsigned long elapsed = currentMillis - startTime;
    unsigned long remaining = (totalTime - elapsed) / 1000;

    
    unsigned long interval = 1000;        
    if (remaining <= 3) interval = 300;  

    if (currentMillis - lastBeep >= interval) {
      tone(buzzerPin, 2000, 80);
      lastBeep = currentMillis;
    }

  
    if (elapsed >= totalTime) {
      running = false;
      finished = true;
      finishTime = currentMillis;

      digitalWrite(timerLED, HIGH);  
      digitalWrite(relayPin, HIGH);   
    }
  }

  
  if (finished && (currentMillis - finishTime < onTime)) {
  
    if (currentMillis - lastBeep >= 100) { 
      tone(buzzerPin, 2500, 50);          
      lastBeep = currentMillis;
    }
  }

  if (finished && (currentMillis - finishTime >= onTime)) {
    digitalWrite(timerLED, LOW);
    digitalWrite(relayPin, LOW);
    noTone(buzzerPin);

    finished = false; 
  }
}
