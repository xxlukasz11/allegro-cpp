project('allegrocpp', 'cpp')

allegro_dep = declare_dependency(
    dependencies: [
        dependency('allegro-5'),
        dependency('allegro_ttf-5'),
        dependency('allegro_font-5'),
        dependency('allegro_primitives-5'),
        dependency('allegro_audio-5'),
        dependency('allegro_acodec-5'),
    ]
)

allegrocpp_public_includes = include_directories('include')
allegrocpp_private_includes = include_directories('include/allegro-cpp')

subdir('src')

allegrocpp_dep = declare_dependency(
    link_with: allegrocpp_lib,
    include_directories: allegrocpp_public_includes,
    dependencies: allegro_dep,
)