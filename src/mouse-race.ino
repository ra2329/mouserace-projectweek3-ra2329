// Wheel control
const int RWheel = 3;   // Right wheel pin
const int LWheel = 4;   // Left wheel pin

float baseSpeed = 50; // Starting speed

float SteeringS = 0.5; // steering sensitivity

// Signal detecting
const int RSensor = A0; // Right sensor pin
const int LSensor = A1; // Left sensor pin

float RSignal = 0; // Right sensor signal
float LSignal = 0; // Left sensor signal

void setup() {
  pinMode(RWheel, OUTPUT);
  pinMode(LWheel, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  analogRead(RSensor);
  RSignal = analogRead(RSensor);

  analogRead(LSensor);
  LSignal = analogRead(LSensor);

  if (RSignal < 140) RSignal = 0;
  if (LSignal < 140) LSignal = 0;

  float error = RSignal - LSignal; // detecting difference in two sensors
  float correction = SteeringS * error; // choosing the correction ammount

  // changing speed based on correction
  float LSpeed = baseSpeed - correction;
  float RSpeed = baseSpeed + correction;

  // constraining what the speed can be
  LSpeed = constrain(LSpeed, 0, 255);
  RSpeed = constrain(RSpeed, 0, 255);

  // Serial
  Serial.printf("RSignal=%.2f LSignal=%.2f error=%.2f correction=%.2f RSpeed=%.2f LSpeed=%.2f\n", RSignal, LSignal, error, correction, RSpeed, LSpeed);

  // outputing speed
  analogWrite(RWheel, RSpeed);
  analogWrite(LWheel, LSpeed);
}
