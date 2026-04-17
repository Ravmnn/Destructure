project('Destructure', 'cpp',
  default_options: ['warning_level=3', 'cpp_std=c++20']
)


cc = meson.get_compiler('cpp')




inc = include_directories('include')

project_dep = declare_dependency(
  include_directories: inc
)


raylib_dep = dependency('raylib',
  required: false,
  fallback: ['raylib', 'raylib_dep']
)

if not raylib_dep.found()
  error('couldn\'t find raylib dependency in the system, nor in the subprojects')
endif


math_dep = cc.find_library('m', required: true)




all_deps = [project_dep, raylib_dep, math_dep]




subdir('src')