// Pins for ULN2003 / LED Strip
const int RED_PIN = 9;
const int GREEN_PIN = 10;
const int BLUE_PIN = 11;

// Speed control - Increase this if the Arduino is getting too hot!
// 10 = Fast/Smooth, 30 = Slow/Chill
int fadeSpeed = 15; 

void setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
}

void loop() {
  // 1. Fade from RED to GREEN
  for (int i = 0; i <= 255; i++) {
    analogWrite(RED_PIN, 255 - i);
    analogWrite(GREEN_PIN, i);
    analogWrite(BLUE_PIN, 0);
    delay(fadeSpeed);
  }

  // 2. Fade from GREEN to BLUE
  for (int i = 0; i <= 255; i++) {
    analogWrite(RED_PIN, 0);
    analogWrite(GREEN_PIN, 255 - i);
    analogWrite(BLUE_PIN, i);
    delay(fadeSpeed);
  }

  // 3. Fade from BLUE back to RED
  for (int i = 0; i <= 255; i++) {
    analogWrite(RED_PIN, i);
    analogWrite(GREEN_PIN, 0);
    analogWrite(BLUE_PIN, 255 - i);
    delay(fadeSpeed);
  }
}