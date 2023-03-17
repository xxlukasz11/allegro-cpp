#include "textWriter.h"

#include <allegro5/allegro_font.h>
#include <allegro5/allegro_color.h>

#include "display.h"
#include "font.h"

constexpr int LINE_HEIGHT = 30;
static const ALLEGRO_COLOR COLOR_BLACK = al_map_rgb(0, 0, 0);

namespace allegrocpp {

TextWriter::TextWriter(const Display& display, const Font& font) :
		display(display),
		font(font) {
}

void TextWriter::writeCenter(const std::string& text) {
	write(display.getWidthPixels() / 2, display.getHeightPixels() / 2, text);
}

void TextWriter::writeCenterAtLine(int lineIndex, const std::string& text) {
	auto offset = LINE_HEIGHT * lineIndex;
	write(display.getWidthPixels() / 2, display.getHeightPixels() / 2 + offset, text);
}

void TextWriter::write(int x, int y, const std::string& text) {
	al_draw_text(font.getAllegroFontPtr(), COLOR_BLACK, x, y, ALLEGRO_ALIGN_CENTRE, text.c_str());
}

} // namespace allegrocpp
