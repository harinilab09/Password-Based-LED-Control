
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
      delay(5000);
      digitalWrite(led, LOW);
      Serial.println("LED OFF - Timer ended");
      Serial.println("Enter password:");
    } else {
      digitalWrite(led, LOW);
      Serial.println("Wrong Password - Access Denied");
    }
  }
}
