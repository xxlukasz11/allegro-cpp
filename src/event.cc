#include "event.h"
#include "timer.h"
#include <unordered_map>

namespace allegrocpp {

// @formatter:off
static const std::unordered_map<ALLEGRO_EVENT_TYPE, EventType> eventTypeMapping {
	{ ALLEGRO_EVENT_DISPLAY_CLOSE, EventType::DISPLAY_CLOSE },
	{ ALLEGRO_EVENT_TIMER, EventType::TIMER_EXPIRED },
	{ ALLEGRO_EVENT_KEY_DOWN, EventType::KEY_PRESSED },
	{ ALLEGRO_EVENT_KEY_UP, EventType::KEY_RELEASED }
};

static const std::unordered_map<int, KeyboardKey> keyboardMapping{
		{ ALLEGRO_KEY_DOWN, KeyboardKey::KEY_DOWN },
		{ ALLEGRO_KEY_UP, KeyboardKey::KEY_UP },
		{ ALLEGRO_KEY_LEFT, KeyboardKey::KEY_LEFT },
		{ ALLEGRO_KEY_RIGHT, KeyboardKey::KEY_RIGHT },
		{ ALLEGRO_KEY_ESCAPE, KeyboardKey::KEY_ESCAPE },
		{ ALLEGRO_KEY_Y, KeyboardKey::KEY_Y },
		{ ALLEGRO_KEY_N, KeyboardKey::KEY_N }
};
// @formatter:on

namespace {
EventType readEventType(const ALLEGRO_EVENT& event) {
	auto found = eventTypeMapping.find(event.type);
	if (found == eventTypeMapping.end()) {
		return EventType::UNKNOWN;
	}
	return found->second;
}
} // namespace

Event::Event(const ALLEGRO_EVENT& event) :
		event(event),
		eventType(readEventType(event)),
		key(KeyboardKey::UNKNOWN) {
	readKeyIfPossible();
}

EventType Event::getEventType() const {
	return eventType;
}

KeyboardKey Event::getKey() const {
	return key;
}

bool Event::isEventSource(const Timer& timer) const {
	return event.timer.source == timer.allegroTimer.get();
}

bool Event::isKeyReleased(KeyboardKey key) const {
	return isKeyReleased() && key == this->key;
}

bool Event::isKeyPressed(KeyboardKey key) const {
	return isKeyPressed() && key == this->key;
}

bool Event::isKeyboardEvent() const {
	return isKeyReleased() || isKeyPressed();
}

bool Event::isKeyReleased() const {
	return EventType::KEY_RELEASED == eventType;
}

bool Event::isKeyPressed() const {
	return EventType::KEY_PRESSED == eventType;
}

void Event::readKeyIfPossible() {
	if (!isKeyboardEvent()) {
		return;
	}
	auto found = keyboardMapping.find(event.keyboard.keycode);
	if (found != keyboardMapping.end()) {
		key = found->second;
	}
}

} // namespace allegrocpp
