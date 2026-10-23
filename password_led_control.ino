
const int led = 13;
String password = "1234";

void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  Serial.println("Enter password:");
}

void loop() {
  if (Serial.available()) {
    String input = Serial.readStringUntil('\n');
    input.trim();

    if (input == password) {
      digitalWrite(led, HIGH);
      Serial.println("Access Granted - LED ON");
    } else {
      digitalWrite(led, LOW);
      Serial.println("Access Denied - LED OFF");
    }
  }
}
