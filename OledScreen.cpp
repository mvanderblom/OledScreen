#include "Arduino.h"
#include "OledScreen.h"
#include "Wire.h"
#include "SSD1306Ascii.h"
#include "SSD1306AsciiWire.h"

OledScreen::OledScreen(int i2cAddress) {
	this->_i2cAddress = i2cAddress;
}

void OledScreen::debug() {
	this->_debug = true;
}

void OledScreen::init() {
	pinMode(_clockPin, OUTPUT);
	pinMode(_dataPin, OUTPUT);

	Wire.begin();
	_oled.begin(&Adafruit128x64, _i2cAddress);
	_oled.set400kHz();
	_oled.setFont(Arial14);
	_oled.clear();

	if (_debug) {
		Serial.print("Initialized OledScreen on dataPin: ");
		Serial.print(_dataPin);
		Serial.print(", clockPin: ");
		Serial.println(_clockPin);
	}
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
