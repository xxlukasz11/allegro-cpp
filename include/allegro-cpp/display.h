#ifndef SRC_DISPLAY_H_
#define SRC_DISPLAY_H_

#include <allegro5/allegro.h>
#include <string>
#include <memory>

namespace allegrocpp {

class EventQueue;

struct DisplayInitParams {
	int rasterSizePixels;
	int numHorizontalRasters;
	int numVerticalRasters;
	std::string windowName{ "Unnamed display" };
};

class Display {
	friend class EventQueue;
public:
	void placeAtScreenCenter();
	int getRasterSize() const;
	int getWidthPixels() const;
	int getHeightPixels() const;
	int getWidthRasters() const;
	int getHeightRasters() const;

	static std::unique_ptr<Display> create(const DisplayInitParams& displayInitParams);

private:
	using AllegroDisplayDeleter = void(*)(ALLEGRO_DISPLAY*);
	using AllegroDisplayPtr = std::unique_ptr<ALLEGRO_DISPLAY, AllegroDisplayDeleter>;

	Display(AllegroDisplayPtr allegrodisplay, const DisplayInitParams& displayInitParams);
	static void destroyDisplay(ALLEGRO_DISPLAY* display);

	AllegroDisplayPtr allegroDisplay;
	int rasterSize;
	int widthRasters;
	int heightRasters;
	int widthPixels;
	int heightPixels;
};

} // namespace allegrocpp

#endif /* SRC_DISPLAY_H_ */
