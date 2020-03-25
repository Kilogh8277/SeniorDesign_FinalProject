int switchPin = A2;

int powerPin = 9;

double voltageReading = 0;

double voltageConversion = (5 / 1023); // Voltage conversion from resolution to voltage

void setup() {
  pinMode(switchPin, INPUT);
  pinMode(powerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  analogWrite(powerPin, 255 * (3.3 / 1023));
  voltageReading = analogRead(switchPin);

  voltageReading = voltageReading * voltageConversion;
  Serial.println(voltageReading);
}
