
const int led = 13;
int tries = 0;
bool locked = false;

void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  Serial.println("Enter password:");
}

void loop() {
  if (locked) return;

  if (Serial.available()) {
    String pass = Serial.readStringUntil('\n');
    pass.trim();

    if (pass == "2468") {
      digitalWrite(led, HIGH);
      Serial.println("Correct! LED ON");
      tries = 0;
    } else {
      digitalWrite(led, LOW);
      tries++;
      Serial.println("Wrong password!");

      if (tries >= 3) {
        locked = true;
        Serial.println("System locked! Reset Arduino.");
      } else {
        Serial.println("Try again.");
      }
    }
  }
}
