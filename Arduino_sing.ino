#define BUZZER_PIN 11 // Digital pin connected to the buzzer

int melody[] = {
  392, 392, 440, 392, 523, 494,
  392, 392, 440, 392, 587, 523,
  392, 392, 784, 659, 523, 494, 440,
  698, 698, 659, 523, 587, 523
};

int noteDuration = 250;

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  // Iterate through the melody array
  for (int i = 0; i < sizeof(melody) / sizeof(melody[0]); i++) {
    // Play the current note
    tone(BUZZER_PIN, melody[i], noteDuration);

    // Pause between notes
    delay(noteDuration);

    // Stop playing the note
    noTone(BUZZER_PIN);
  }

  // Pause between the song repetitions
  delay(2000);
}
