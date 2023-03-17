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
		{ ALLEGRO_KEY_DOWN, KeyboardKey::DOWN },
		{ ALLEGRO_KEY_UP, KeyboardKey::UP },
		{ ALLEGRO_KEY_LEFT, KeyboardKey::LEFT },
		{ ALLEGRO_KEY_RIGHT, KeyboardKey::RIGHT },
		{ ALLEGRO_KEY_ESCAPE, KeyboardKey::ESCAPE },
		{ ALLEGRO_KEY_A, KeyboardKey::A },
		{ ALLEGRO_KEY_B, KeyboardKey::B },
		{ ALLEGRO_KEY_C, KeyboardKey::C },
		{ ALLEGRO_KEY_D, KeyboardKey::D },
		{ ALLEGRO_KEY_E, KeyboardKey::E },
		{ ALLEGRO_KEY_F, KeyboardKey::F },
		{ ALLEGRO_KEY_G, KeyboardKey::G },
		{ ALLEGRO_KEY_H, KeyboardKey::H },
		{ ALLEGRO_KEY_I, KeyboardKey::I },
		{ ALLEGRO_KEY_J, KeyboardKey::J },
		{ ALLEGRO_KEY_K, KeyboardKey::K },
		{ ALLEGRO_KEY_L, KeyboardKey::L },
		{ ALLEGRO_KEY_M, KeyboardKey::M },
		{ ALLEGRO_KEY_N, KeyboardKey::N },
		{ ALLEGRO_KEY_O, KeyboardKey::O },
		{ ALLEGRO_KEY_P, KeyboardKey::P },
		{ ALLEGRO_KEY_R, KeyboardKey::R },
		{ ALLEGRO_KEY_S, KeyboardKey::S },
		{ ALLEGRO_KEY_T, KeyboardKey::T },
		{ ALLEGRO_KEY_U, KeyboardKey::U },
		{ ALLEGRO_KEY_V, KeyboardKey::V },
		{ ALLEGRO_KEY_W, KeyboardKey::W },
		{ ALLEGRO_KEY_X, KeyboardKey::X },
		{ ALLEGRO_KEY_Y, KeyboardKey::Y },
		{ ALLEGRO_KEY_Z, KeyboardKey::Z },
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
