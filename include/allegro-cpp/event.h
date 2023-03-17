#ifndef SRC_allegrocpp_EVENT_H_
#define SRC_allegrocpp_EVENT_H_

#include <allegro5/allegro.h>

namespace allegrocpp {

enum class KeyboardKey {
	UP, LEFT, RIGHT, DOWN, ESCAPE, A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, R, S, T, U, V, W, X, Y, Z, UNKNOWN
};

enum class EventType {
	DISPLAY_CLOSE, TIMER_EXPIRED, KEY_PRESSED, KEY_RELEASED, UNKNOWN
};

class Timer;

class Event {
public:
	Event(const ALLEGRO_EVENT& event);
	EventType getEventType() const;
	KeyboardKey getKey() const;

	bool isEventSource(const Timer& timer) const;
	bool isKeyReleased(KeyboardKey key) const;
	bool isKeyPressed(KeyboardKey key) const;

private:
	bool isKeyboardEvent() const;
	bool isKeyReleased() const;
	bool isKeyPressed() const;
	void readKeyIfPossible();

	ALLEGRO_EVENT event;
	EventType eventType;
	KeyboardKey key;
};

} // namespace allegrocpp

#endif /* SRC_allegrocpp_EVENT_H_ */
