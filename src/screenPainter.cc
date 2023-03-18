#include "screenPainter.h"

namespace allegrocpp {

void ScreenPainter::clearScreen(const Color& screenColor) const {
	rawPainter.clearScreen(screenColor);
}

void ScreenPainter::flushBuffer() const {
	rawPainter.flushBuffer();
}

} // namespace allegrocpp
