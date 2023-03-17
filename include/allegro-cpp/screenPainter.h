#ifndef SRC_SCREENPAINTER_H_
#define SRC_SCREENPAINTER_H_

namespace allegrocpp {

class Color;

class ScreenPainter {
public:
	void drawFilledRectangle(double topLeftX, double topLeftY, double bottomRightX, double bottomRightY,
			const Color& fillColor) const;
	void drawFilledCircle(double centerX, double centerY, double radius, const Color& fillColor) const;
	void drawFilledCircle(double centerX, double centerY, double radius, double initialTheta, double deltaTheta,
			const Color& fillColor) const;
	void drawArc(double centerX, double centerY, double radius, double initialTheta, double deltaTheta,
			double thickness, const Color& fillColor) const;
	void clearScreen(const Color& screenColor) const;
	void flushBuffer() const;
};

} // namespace allegrocpp

#endif /* SRC_SCREENPAINTER_H_ */
