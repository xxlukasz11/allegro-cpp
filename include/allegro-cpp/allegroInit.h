#ifndef SRC_allegrocpp_ALLEGRO_INIT_H_
#define SRC_allegrocpp_ALLEGRO_INIT_H_

#include <string>

namespace allegrocpp {

enum class AllegroInitStatus {
	SUCCESS, FAILURE
};

struct AllegroInitResult {
	AllegroInitStatus status;
	std::string errorMesage;
};

AllegroInitResult initializeAllegroModules();

}
// namespace allegrocpp

#endif /* SRC_allegrocpp_ALLEGRO_INIT_H_ */
