#include <Wire.h>
#include <LiquidCrystal_I2C_Menu.h>
LiquidCrystal_I2C_Menu lcd(0x27, 20, 4);

// Пины, к которым подключен энкодер
#define pinCLK 2
#define pinDT  3
#define pinSW  4

void setup() {
  lcd.begin();
  lcd.attachEncoder(pinDT, pinCLK, pinSW);
}

void loop() {
  // Опрашиваем энкодер
  eEncoderState EncoderState = lcd.getEncoderState();
  switch (EncoderState) {
    case eLeft:
      lcd.printAt(0, 0, "Left      ");
      break;
    case eRight:
      lcd.printAt(0, 0, "Right     ");
      break;
    case eButton:
      lcd.printAt(0, 0, "Button    ");
      break;
    case eLongButton:
      lcd.printAt(0, 0, "LongButton");
      break;
    case eNone:
      return;
  }
}
