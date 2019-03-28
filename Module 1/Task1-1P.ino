//Setting up Constanants to describe pins
const int sensor_output = 13;
const int sensor_input = 2;
int val = 0;
void setup() {
  // put your setup code here, to run once:
    // initialize the serial communications:
    Serial.begin(9600);
  //initialize digital pin sensor_output as an output
  pinMode(sensor_output, OUTPUT);
  //initialize digital pin sensor_input as an input
  pinMode(sensor_input, INPUT);

}

void loop() {
  val = digitalRead(sensor_input);
  Serial.println(val);

  if(val == HIGH)
  {
    digitalWrite(sensor_output, HIGH);
  }
  else
  {
    digitalWrite(sensor_output, LOW);
  }
  delay(1000);
 
  // put your main code here, to run repeatedly:

}
