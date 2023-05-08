
// These constants won't change. They're used to give names to the pins used:
const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
const int analogInPin2 = A1; // Analog output pin that the LED is attached to

int sensorValue = 0; // value read from the pot
int outputValue = 0; // value output to the PWM (analog out)

void setup()
{
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
}

void loop()
{
  // read the analog in value:
  sensorValue = analogRead(analogInPin);
  int sensorValue2 = analogRead(analogInPin2);

  // print the results to the Serial Monitor:
  Serial.print("sensor 1= ");
  Serial.println(sensorValue);
  delay(2000);
  Serial.print("sensor 2= ");
  Serial.println(sensorValue2);

  // wait 2 milliseconds before the next loop for the analog-to-digital
  // converter to settle after the last reading:
  delay(2000);
}
