#ifndef SRC_FONT_H_
#define SRC_FONT_H_

#include <memory>
#include <string>
#include <allegro5/allegro_font.h>

namespace allegrocpp {

class Font {
public:
	static std::unique_ptr<Font> loadFromTtfFile(const char* filename, int fontSize);
	int getFontSize() const;
	ALLEGRO_FONT* getAllegroFontPtr() const;

private:
	using AllegroFontDeleter = void(*)(ALLEGRO_FONT*);
	using AllegroFontPtr = std::unique_ptr<ALLEGRO_FONT, AllegroFontDeleter>;

	Font(AllegroFontPtr fontPtr, int fontSize);
	static void destroyFont(ALLEGRO_FONT* font);

	AllegroFontPtr allegroFont;
	int fontSize;
};

} // namespace allegrocpp

#endif // SRC_FONT_H_
