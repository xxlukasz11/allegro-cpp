#ifndef SRC_TEXTWRITER_H_
#define SRC_TEXTWRITER_H_

#include <allegro5/allegro_color.h>
#include <string>
#include "vec.h"

namespace allegrocpp {

class Display;
class Font;
class Color;

class TextWriter {
public:
	TextWriter(const Display& display, const Font& font, const Color& textColor);

	void writeCenter(const std::string& text);

	template<typename T>
	void writeCenterAt(const Vec<T>& center, const std::string& text);

	void writeCenterAtLine(int lineIndex, const std::string& text);

private:
	void write(int x, int y, const std::string& text);

	const Display& display;
	const Font& font;
	ALLEGRO_COLOR textColor;
};

template<typename T>
void TextWriter::writeCenterAt(const Vec<T>& center, const std::string& text) {
	write(center.x, center.y, text);
}

} // namespace allegrocpp

#endif /* SRC_TEXTWRITER_H_ */
