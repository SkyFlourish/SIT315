//Setting up Constanants to describe pins
const int sensor_output = 13;
const int interrupt_pin = 2;
volatile byte state = LOW;

int val = 0;
void setup() {
  // put your setup code here, to run once:
    // initialize the serial communications:
    Serial.begin(9600);
  //initialize digital pin sensor_output as an output
  pinMode(sensor_output, OUTPUT);

  //initialize digital pin sensor_input as an input
  pinMode(interrupt_pin, INPUT);
  //initialize the intterupt to work when the pin's value hanges from low to high
  attachInterrupt(digitalPinToInterrupt(interrupt_pin),blink, CHANGE);
}

void loop() {
// Serial.println(val);
 // digitalWrite(sensor_output, state);
  // put your main code here, to run repeatedly:
  }

  void blink () {
    state = digitalRead(interrupt_pin);
    //write on serial
    Serial.println(state);
    //write on pin output
    digitalWrite(sensor_output,state);
  }
