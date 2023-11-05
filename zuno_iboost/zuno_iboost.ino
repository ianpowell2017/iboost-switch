// pin number, where relay is connected
#define RELAY_PIN     13

// variable to store current relay state
byte lastSetValue;

ZUNO_SETUP_CHANNELS(ZUNO_SWITCH_BINARY(getter, setter));

void setup() {
  pinMode(RELAY_PIN, OUTPUT); // set up relay pin as output
}

void loop() {
  // loop is empty, because all the control comes over the Z-Wave
}

byte getter() {
  return lastSetValue;
}

void setter(byte newValue) {
  // newValue is a variable, holding a "value"
  // which came from the controller or other Z-Wave device
  if (newValue > 0) { // if greater then zero
    digitalWrite(RELAY_PIN, HIGH); //turn relay on
  } else {            // if equals zero
    digitalWrite(RELAY_PIN, LOW);  //turn relay off
  }

  // save the new value in a variable
  lastSetValue = newValue;
}