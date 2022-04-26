
int PhotoPin1 = A5;
int PhotoPin2 = A0;

int button  = 13;
int prevButtonState;
int buttonState;

int lightCal;
int lightVal;
boolean HaveMercyOnMeChris = false;

unsigned long startTime = millis();
unsigned long endTime = 0;
int interval = 0;


void setup()
{
  Serial.begin(9600);

  lightCal = analogRead(PhotoPin1);
  lightCal = analogRead(PhotoPin2);

  pinMode(button, INPUT);
}


void loop() {
//  prevButtonState = buttonState;
//  buttonState = debounce(button, prevButtonState);
////  Serial.println(buttonState);
//
//
//  if (buttonState == HIGH && prevButtonState == LOW) {
//    HaveMercyOnMeChris = false;
//    Serial.println("buttonPressed");
//  }



  if (analogRead(PhotoPin2) < 800) {
//    Serial.println("2trigger");
    startTime = millis();

  }
  else if (analogRead(PhotoPin1) < 800 && !HaveMercyOnMeChris) {
    //    Serial.println("1trigger");

    endTime = millis();
    interval  = endTime - startTime;
    HaveMercyOnMeChris = true;
    Serial.println(interval);
  }


  int value = analogRead(PhotoPin1);
  int val = analogRead(PhotoPin2);

  //  Serial.println("Analog value : ");
  //  Serial.println(value);
  //  Serial.println(val);

  //if (endTime - startTime > interval) {
  //      Serial.println("timer triggered");
  //      startTime = millis();
  //    }

}

// this function returns the debounce reading of a button
boolean debounce(int aButtonPin, boolean aPrevButtonState) {
  //read the bouncy reading of the button
  boolean bouncyButtonState = digitalRead(aButtonPin);

  // toggle if statement that detects if button is pushed
  if (bouncyButtonState == HIGH && aPrevButtonState == LOW) {

    // wait until bounciness has stopped
    delay(15);
  }
  boolean debounceButtonState = bouncyButtonState;

  return debounceButtonState;


}
