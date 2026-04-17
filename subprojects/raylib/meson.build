project('raylib', 'c')


cc = meson.get_compiler('c')

raylib_lib = cc.find_library('raylib',
  dirs: [meson.current_source_dir() / 'lib'],
  required: true
)

raylib_dep = declare_dependency(
  dependencies: raylib_lib,
  include_directories: include_directories('include')
)