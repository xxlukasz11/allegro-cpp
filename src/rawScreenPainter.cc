#include "color.h"
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_color.h>
#include "rawScreenPainter.h"

namespace allegrocpp {

namespace {

ALLEGRO_COLOR allegroColor(const Color& color) {
	return al_map_rgb(color.r(), color.g(), color.b());
}

} // namespace

void RawScreenPainter::drawFilledRectangle(float topLeftX, float topLeftY, float bottomRightX, float bottomRightY,
		const Color& fillColor) const {
	al_draw_filled_rectangle(topLeftX, topLeftY, bottomRightX, bottomRightY, allegroColor(fillColor));
}

void RawScreenPainter::drawFilledRoundedRectangle(float topLeftX, float topLeftY, float bottomRightX,
		float bottomRightY, float radiusX, float radiusY, const Color& fillColor) const {
	al_draw_filled_rounded_rectangle(topLeftX, topLeftY, bottomRightX, bottomRightY, radiusX, radiusY,
			allegroColor(fillColor));
}

void RawScreenPainter::drawFilledCircle(float centerX, float centerY, float radius, const Color& fillColor) const {
	al_draw_filled_circle(centerX, centerY, radius, allegroColor(fillColor));
}

void RawScreenPainter::drawFilledCircle(float centerX, float centerY, float radius, float initialTheta,
		float deltaTheta, const Color& fillColor) const {
	al_draw_filled_pieslice(centerX, centerY, radius, initialTheta, deltaTheta, allegroColor(fillColor));
}

void RawScreenPainter::drawArc(float centerX, float centerY, float radius, float initialTheta, float deltaTheta,
		float thickness, const Color& fillColor) const {
	al_draw_arc(centerX, centerY, radius, initialTheta, deltaTheta, allegroColor(fillColor), thickness);
}

void RawScreenPainter::clearScreen(const Color& screenColor) const {
	al_clear_to_color(allegroColor(screenColor));
}

void RawScreenPainter::flushBuffer() const {
	al_flip_display();
}

} // namespace allegrocpp
