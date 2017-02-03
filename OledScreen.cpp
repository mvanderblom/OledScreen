#include <Arduino.h>
#include <OledScreen.h>
#include <Wire.h>
#include <SSD1306Ascii.h>
#include <SSD1306AsciiWire.h>

OledScreen::OledScreen(int i2cAddress) {
	this->_i2cAddress = i2cAddress;
}

void OledScreen::init() {
	Wire.begin();
	_oled.begin(&Adafruit128x64, _i2cAddress);
	_oled.set400kHz();
	_oled.setFont(Arial14);
	_oled.clear();

//	Serial.print("Initialized OledScreen on i2cAddress: ");
//	Serial.println(_i2cAddress);
}

void OledScreen::title(String title) {
	_oled.setCursor(0, 0);
	_oled.set1X();
	_oled.print(title);
	_oled.print(_fill);
}

void OledScreen::value(String value) {
	_oled.setCursor(0, 2);
	_oled.set2X();
	_oled.print(value);
	_oled.print(_fill);
}

void OledScreen::status(String status) {
	_oled.setCursor(0, 6);
	_oled.set1X();
	_oled.print(status);
	_oled.print(_fill);
}
