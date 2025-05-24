const int ledPin = 2;  // LED connected to digital pin 2


// Morse code lookup function
String morseCode(char c) {
  switch (toupper(c)) {
    case 'A': return ".-";
    case 'B': return "-...";
    case 'C': return "-.-.";
    case 'D': return "-..";
    case 'E': return ".";
    case 'F': return "..-.";
    case 'G': return "--.";
    case 'H': return "....";
    case 'I': return "..";
    case 'J': return ".---";
    case 'K': return "-.-";
    case 'L': return ".-..";
    case 'M': return "--";
    case 'N': return "-.";
    case 'O': return "---";
    case 'P': return ".--.";
    case 'Q': return "--.-";
    case 'R': return ".-.";
    case 'S': return "...";
    case 'T': return "-";
    case 'U': return "..-";
    case 'V': return "...-";
    case 'W': return ".--";
    case 'X': return "-..-";
    case 'Y': return "-.--";
    case 'Z': return "--..";
    case '1': return ".----";
    case '2': return "..---";
    case '3': return "...--";
    case '4': return "....-";
    case '5': return ".....";
    case '6': return "-....";
    case '7': return "--...";
    case '8': return "---..";
    case '9': return "----.";
    case '0': return "-----";
    case ' ': return " ";  // space = word gap
    default: return "";    // ignore unsupported characters
  }
}


// Flash one dot
void dot() {
  digitalWrite(ledPin, HIGH);
  delay(400);              // 1 unit
  digitalWrite(ledPin, LOW);
  delay(400);              // space between dots/dashes
}


// Flash one dash
void dash() {
  digitalWrite(ledPin, HIGH);
  delay(1200);              // 3 units
  digitalWrite(ledPin, LOW);
  delay(400);              // space between dots/dashes
}


// Flash Morse code for a single letter
void flashMorse(String code) {
  for (char c : code) {
    if (c == '.') {
      dot();
    } else if (c == '-') {
      dash();
    }
  }
  delay(1200);              // space between letters (3 units)
}


void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Enter a message:");
}


void loop() {
  if (Serial.available()) {
    String message = Serial.readStringUntil('\n');
    message.trim();


    for (char c : message) {
      String morse = morseCode(c);
      if (morse == " ") {
        delay(2800);       // space between words (7 units)
      } else {
        flashMorse(morse);
      }
    }


    Serial.println("Done. Enter another message:");
  }
}
