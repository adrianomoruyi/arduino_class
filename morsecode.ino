const int ledPin = 2;     // LED connected to digital pin 2

// 🔤 Set your hidden message here
String message = "SECRET MESSAGE";  // Students must decode this

// Morse code lookup
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
    case ' ': return " ";  // Word space
    default: return "";    // Ignore unsupported characters
  }
}

void dot() {
  digitalWrite(ledPin, HIGH);
  delay(400);              // 1 unit
  digitalWrite(ledPin, LOW);
  delay(400);              // Space between dots/dashes
}

void dash() {
  digitalWrite(ledPin, HIGH);
  delay(1200);             // 3 units
  digitalWrite(ledPin, LOW);
  delay(400);              // Space between dots/dashes
}

void flashMorse(String code) {
  for (char c : code) {
    if (c == '.') {
      dot();
    } else if (c == '-') {
      dash();
    }
  }
  delay(1200);  // Space between letters (3 units)
}

void setup() {
  pinMode(ledPin, OUTPUT);

  // Flash the hardcoded message once
  for (char c : message) {
    String morse = morseCode(c);
    if (morse == " ") {
      delay(2800);  // Space between words (7 units)
    } else {
      flashMorse(morse);
    }
  }
}

void loop() {
  // Nothing here – message only plays once when powered on
}



