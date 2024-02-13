// pin number, where relay is connected
#define RELAY_PIN1     13
#define RELAY_PIN2     14
#define RELAY_PIN3     15
#define RELAY_PIN4     16

// variable to store current relay state
byte lastSetValue1 = 0;
byte lastSetValue2 = 0;
byte lastSetValue3 = 0;
byte lastSetValue4 = 0;

ZUNO_SETUP_SLEEPING_MODE(ZUNO_SLEEPING_MODE_ALWAYS_AWAKE);

ZUNO_SETUP_CHANNELS(
  ZUNO_SWITCH_BINARY(getter1, setter1),
  ZUNO_SWITCH_BINARY(getter2, setter2),
  ZUNO_SWITCH_BINARY(getter3, setter3),
  ZUNO_SWITCH_BINARY(getter4, setter4)
);

void setup() {
  pinMode(RELAY_PIN1, OUTPUT); // set up relay pin as output
  pinMode(RELAY_PIN2, OUTPUT); // set up relay pin as output
  pinMode(RELAY_PIN3, OUTPUT); // set up relay pin as output
  pinMode(RELAY_PIN4, OUTPUT); // set up relay pin as output
}

void loop() {
  // loop is empty, because all the control comes over the Z-Wave
}

byte getter1() {
  return lastSetValue1;
}

void setter1(byte newValue) {
  digitalWrite(RELAY_PIN1, newValue > 0); //turn relay on
  lastSetValue1 = newValue;
}

byte getter2() {
  return lastSetValue2;
}

void setter2(byte newValue) {
  digitalWrite(RELAY_PIN2, newValue > 0); //turn relay on
  lastSetValue2 = newValue;
}

byte getter3() {
  return lastSetValue3;
}

void setter3(byte newValue) {
  digitalWrite(RELAY_PIN3, newValue > 0); //turn relay on
  lastSetValue3 = newValue;
}

byte getter4() {
  return lastSetValue4;
}

void setter4(byte newValue) {
  digitalWrite(RELAY_PIN4, newValue > 0); //turn relay on
  lastSetValue4 = newValue;
}
