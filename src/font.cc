#include "font.h"

#include <iostream>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

namespace allegrocpp {

Font::Font(AllegroFontPtr fontPtr, int fontSize) :
		allegroFont(std::move(fontPtr)),
		fontSize(fontSize) {
}

void Font::destroyFont(ALLEGRO_FONT* font) {
	al_destroy_font(font);
}

std::unique_ptr<Font> Font::loadFromTtfFile(const char* filename, int fontSize) {
	AllegroFontPtr fontPtr{ al_load_ttf_font(filename, fontSize, 0), destroyFont };
	if (!fontPtr) {
		return nullptr;
	}
	return std::unique_ptr<Font>(new Font(std::move(fontPtr), fontSize));
}

int Font::getFontSize() const {
	return fontSize;
}

ALLEGRO_FONT* Font::getAllegroFontPtr() const {
	return allegroFont.get();
}

} // namespace allegrocpp
