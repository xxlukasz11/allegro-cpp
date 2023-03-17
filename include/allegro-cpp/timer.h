#ifndef SRC_allegrocpp_TIMER_H_
#define SRC_allegrocpp_TIMER_H_

#include "allegro5/allegro.h"
#include <memory>

namespace allegrocpp {

class EventQueue;

class Timer {
	friend class EventQueue;
	friend class Event;
public:
	void start();
	void stop();
	static std::unique_ptr<Timer> create(double timeoutSeconds);

private:
	using AllegroTimerDeleter = void(*)(ALLEGRO_TIMER*);
	using AllegroTimerPtr = std::unique_ptr<ALLEGRO_TIMER, AllegroTimerDeleter>;

	static void deleteTimer(ALLEGRO_TIMER* timer);
	Timer(AllegroTimerPtr timerPtr);

	AllegroTimerPtr allegroTimer;
};

} // namespace allegrocpp

#endif /* SRC_allegrocpp_TIMER_H_ */
