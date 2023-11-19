
String input;

int Light = 13;
int Fan = 12;

void setup() {
  pinMode(Light, OUTPUT);
  pinMode(Fan, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  while (Serial.available()) {
    delay(50);
    char C = Serial.read();
    input += C;
    Serial.println("Input: " + input);
  }

  if (input == "Light") {
    digitalWrite(Light, HIGH);
    Serial.println("Input: " + input);
  }

  if (input == "NoLight") {
    digitalWrite(Light, LOW);
    Serial.println("Input: " + input);
  }


  if (input == "Fan") {
    digitalWrite(Fan, HIGH);
    Serial.println("Input: " + input);
  }

  if (input == "NoFan") {
    digitalWrite(Fan, LOW);
    Serial.println("Input: " + input);
  }

  input = "";

}