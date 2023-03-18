#ifndef INCLUDE_ALLEGRO_CPP_SCREENPAINTER_H_
#define INCLUDE_ALLEGRO_CPP_SCREENPAINTER_H_

#include "rawScreenPainter.h"
#include "vec.h"
#include "slice.h"

namespace allegrocpp {

class Color;

class ScreenPainter {
public:
	template<typename T, typename V>
	void drawFilledRectangle(const Vec<T>& topLeft, const Vec<T>& bottomRight, const Color& fillColor) const;

	template<typename T, typename V>
	void drawFilledRoundedRectangle(const Vec<T>& topLeft, const Vec<T>& bottomRight, const Vec<T>& cornerRadius,
			const Color& fillColor) const;

	template<typename T>
	void drawFilledCircle(const Vec<T>& center, float radius, const Color& fillColor) const;

	template<typename T>
	void drawFilledSlice(const Vec<T>& center, float radius, const Slice& slice, const Color& fillColor) const;

	template<typename T>
	void drawArc(const Vec<T>& center, float radius, const Slice& slice, float thickness, const Color& fillColor) const;

	void clearScreen(const Color& screenColor) const;

	void flushBuffer() const;

private:
	RawScreenPainter rawPainter;
};

template<typename T, typename V>
void ScreenPainter::drawFilledRectangle(const Vec<T>& topLeft, const Vec<T>& bottomRight,
		const Color& fillColor) const {
	rawPainter.drawFilledRectangle(topLeft.x, topLeft.y, bottomRight.x, bottomRight.y, fillColor);
}

template<typename T, typename V>
void ScreenPainter::drawFilledRoundedRectangle(const Vec<T>& topLeft, const Vec<T>& bottomRight,
		const Vec<T>& cornerRadius, const Color& fillColor) const {
	rawPainter.drawFilledRoundedRectangle(topLeft.x, topLeft.y, bottomRight.x, bottomRight.y, cornerRadius.x,
			cornerRadius.y, fillColor);
}

template<typename T>
void ScreenPainter::drawFilledCircle(const Vec<T>& center, float radius, const Color& fillColor) const {
	rawPainter.drawFilledCircle(center.x, center.y, radius, fillColor);
}

template<typename T>
void ScreenPainter::drawFilledSlice(const Vec<T>& center, float radius, const Slice& slice,
		const Color& fillColor) const {
	rawPainter.drawFilledCircle(center.x, center.y, radius, slice.initialTheta, slice.deltaTheta, fillColor);
}

template<typename T>
void ScreenPainter::drawArc(const Vec<T>& center, float radius, const Slice& slice, float thickness,
		const Color& fillColor) const {
	rawPainter.drawArc(center.x, center.y, radius, slice.initialTheta, slice.deltaTheta, thickness, fillColor);
}

} // namespace allegrocpp

#endif /* INCLUDE_ALLEGRO_CPP_SCREENPAINTER_H_ */
