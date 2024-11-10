#define LED1 2
#define LED2 4

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
}

void loop() {
  digitalWrite(LED1, HIGH);
  delay(300);
  digitalWrite(LED1, LOW);

  digitalWrite(LED2, HIGH);
  delay(700);
  digitalWrite(LED2, LOW);

  delay(200);
}
