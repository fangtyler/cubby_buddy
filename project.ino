#include <LiquidCrystal.h>

const int LIGHT_THRESHOLD = 500;
const int TEMP_THRESHOLD = 500;

// Light variables
int lightPin = A0;
int lightReading = 0;
bool lightChange = false;
int curLState = 0; // 0 - dark, 1 - light
int prevLState = 0; // 0 - dark, 1 - light 
int lightCounter = 0;
int savedLState = 0;

// Temprature variables
int tempPin = A1;
int tempReading = 0;
int curTState = 0; // 0 - cold, 1 - hot
int prevTState = 0; // 0 - cold, 1 - hot 
int tempCounter = 0;
int savedTState = 0;

void setup() {
  Serial.begin(9600);
  pinMode(lightPin, INPUT);
//  pinMode(tempPin, INPUT);  
}

void loop() {
  handleLight();
  // 500 ms per iteration
  delay(500); 
}

// Handle light (photocell) reading
// 1. Read current light value, determine curLState (light, dark)
// 2. If curLState changes from prevLState, reset lightCounter, raise flag lightChange
// 3. If not state change:
//    a. If lightChange is true, increment lightCounter
//    b. If lightCounter reaches 10, reset lightChange, update savedLState
// 4. If savedLState changes, queue the light reaction based on savedLState
void handleLight() {
  lightReading = analogRead(lightPin);
  Serial.println(lightReading);
  curLState = lightReading > LIGHT_THRESHOLD ? 1 : 0;
  if (curLState != prevLState) {
    lightCounter = 0;
    lightChange = true;
  } else {
    if (lightChange == true) {
      lightCounter++;
      if (lightCounter == 10) {
        lightChange = false;
        savedLState = curLState;
        // print savedLState
      }
    }
  }
  prevLState = curLState;
}

// Handle temprature reading
// 1. Read current temp value, determine curTState (hot, cold)
// 2. If curTState changes from prevTState, reset counter, raise flag tempChange
// 3. If not state change:
//    a. If lightChange is true, increment lightCounter
//    b. If lightCounter reaches 10, reset lightChange, update savedLState
// 4. If savedLState changes, queue the light reaction based on savedLState
void handleTemp() {

  
}

// TODO: research gesture detection
void handleGuesture() {

  
}

void queueReaction() {

}

void playReaction() {

}
