 #include <TM1637Display.h>

// TM1637 display pins
#define CLK 2
#define DIO 3

// Button pin
#define BUTTON_PIN 4

TM1637Display display(CLK, DIO);
int counter = 0;
bool lastButtonState = HIGH;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP); // Internal pull-up
  display.setBrightness(0x0f);       // Max brightness
  display.showNumberDec(counter);    // Initial value
}

void loop() {
  bool buttonState = digitalRead(BUTTON_PIN);

  // Detect button press (LOW due to pull-up)
  if (lastButtonState == HIGH && buttonState == LOW) {
    counter++;
    if (counter > 9999) counter = 0; // Limit to 4 digits
    display.showNumberDec(counter);
    delay(200); // Debounce
  }

  lastButtonState = buttonState;
}

