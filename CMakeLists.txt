cmake_minimum_required(VERSION 3.9)

file(GLOB allegrocpp_SRC "src/*.cc")
add_library(allegrocpp STATIC ${allegrocpp_SRC})

set_property(TARGET allegrocpp PROPERTY CXX_STANDARD 17)
target_compile_options(allegrocpp PRIVATE -Wall -pedantic -O2)

target_include_directories(allegrocpp
	PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include
	PRIVATE ${CMAKE_CURRENT_LIST_DIR}/include/allegro-cpp
)

target_link_libraries(allegrocpp allegro_ttf allegro_font allegro_primitives allegro_audio allegro_acodec allegro)
