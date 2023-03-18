#ifndef SRC_RAWSCREENPAINTER_H_
#define SRC_RAWSCREENPAINTER_H_

namespace allegrocpp {

class Color;

class RawScreenPainter {
public:
	void drawFilledRectangle(float topLeftX, float topLeftz, float bottomRightX, float bottomRightY,
			const Color& fillColor) const;
	void drawFilledRoundedRectangle(float topLeftX, float topLeftY, float bottomRightX, float bottomRightY,
			float radiusX, float radiusY, const Color& fillColor) const;
	void drawFilledCircle(float centerX, float centerY, float radius, const Color& fillColor) const;
	void drawFilledCircle(float centerX, float centerY, float radius, float initialTheta, float deltaTheta,
			const Color& fillColor) const;
	void drawArc(float centerX, float centerY, float radius, float initialTheta, float deltaTheta, float thickness,
			const Color& fillColor) const;
	void clearScreen(const Color& screenColor) const;
	void flushBuffer() const;
};

} // namespace allegrocpp

#endif /* SRC_RAWSCREENPAINTER_H_ */
