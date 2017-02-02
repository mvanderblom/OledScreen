#ifndef OledScreen_h
#define OledScreen_h

#include "SSD1306AsciiWire.h"

// Uses pin A4 for data and A5 for clock
class OledScreen
{
	public:
		OledScreen(int i2cAddress);
		void init();
		void title(String title);
		void value(String value);
		void status(String status);
	private:
		int _i2cAddress;
		SSD1306AsciiWire _oled;
		const String _fill = "                              ";
};
#endif
