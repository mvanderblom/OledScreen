#ifndef OledScreen_h
#define OledScreen_h

#include "SSD1306AsciiWire.h"

class OledScreen
{
	public:
		OledScreen(int i2cAddress);
		void debug();
		void init();
		void title(String title);
		void value(String value);
		void status(String status);
	private:
		boolean _debug = false;
		int _clockPin, _dataPin, _i2cAddress;
		SSD1306AsciiWire _oled;
		const String _fill = "               ";
};
#endif
