#include "eventQueue.h"
#include "display.h"
#include "timer.h"

namespace allegrocpp {

EventQueue::EventQueue() :
		allegroEventQueue(al_create_event_queue(), destroyEventQueue) {
}

void EventQueue::flushEvents() {
	al_flush_event_queue(allegroEventQueue.get());
}

Event EventQueue::waitForEvent() {
	ALLEGRO_EVENT event;
	al_wait_for_event(allegroEventQueue.get(), &event);
	return Event{ event };
}

void EventQueue::destroyEventQueue(ALLEGRO_EVENT_QUEUE* queue) {
	al_destroy_event_queue(queue);
}

void EventQueue::registerKeyboard() {
	al_register_event_source(allegroEventQueue.get(), al_get_keyboard_event_source());
}
void EventQueue::registerMouse() {
	al_register_event_source(allegroEventQueue.get(), al_get_mouse_event_source());
}

void EventQueue::registerTimer(const Timer& timer) {
	al_register_event_source(allegroEventQueue.get(), al_get_timer_event_source(timer.allegroTimer.get()));
}

void EventQueue::registerDisplay(const Display& display) {
	al_register_event_source(allegroEventQueue.get(), al_get_display_event_source(display.allegroDisplay.get()));
}

} // namespace allegrocpp
