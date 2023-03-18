#ifndef INCLUDE_ALLEGRO_CPP_VEC_H_
#define INCLUDE_ALLEGRO_CPP_VEC_H_

#include <type_traits>

namespace allegrocpp {

template<typename T, typename = std::enable_if_t<std::is_fundamental_v<T>>>
struct Vec {
public:
	T x;
	T y;
};

template<typename T>
bool operator<(const Vec<T>& left, const Vec<T>& right) {
	return left.x == right.x ? left.y < right.y : left.x < right.x;
}

template<typename T>
bool operator==(const Vec<T>& left, const Vec<T>& right) {
	return left.x == right.x && left.y == right.y;
}

using IntVec = Vec<int>;

}
// namesace allegrocpp

#endif /* INCLUDE_ALLEGRO_CPP_VEC_H_ */
