project(
  'simpleFramework',
  ['cpp'],
version : '0.0.1',
default_options : ['warning_level=3', 'cpp_std=c++17', 'buildtype=debug', 'b_colorout=always'],
license : ''
)
    
sdl2_dep = dependency('sdl2', method : 'pkg-config')
sdli_dep = dependency('SDL2_image', method : 'pkg-config')
sdlm_dep = dependency('SDL2_mixer', method : 'pkg-config')
sdlf_dep = dependency('SDL2_ttf', method : 'pkg-config')
sdl_dep = [ sdl2_dep, sdli_dep, sdlm_dep, sdlf_dep ]




sources = files(
  	'src/log.cpp',
  	'src/point.cpp',
  	'src/rect.cpp',
  	'src/event.cpp',
  	'src/video.cpp',
 	'src/renderer.cpp',
  	'src/window.cpp'
#  	'src/texture.cpp',
#  	'src/basicrendertext.cpp'
#	'src/pushbutton.cpp',
#	'src/vbox.cpp',
#	'src/hbox.cpp',
  )

incfiles = files( 
	'include/log.h',
	'include/point.h',
	'include/rect.h',
	'include/event.h',
	'include/video.h',
	'include/renderer.h',
	'include/widget.h',
	'include/window.h'
#	'include/basicrendertext.h',
#	'include/hbox.h',
#	'include/texture.h',
#	'include/vbox.h',
#	'include/pushbutton.h',
#	'include/topbar.h',
)

inc = include_directories('include')

simpleFramework = shared_library(
  'simpleFramework',
#  meson.project_name(),
  sources,
  version : '0.0.1',
  cpp_args : '-g',
  dependencies: [sdl_dep],
  install : true
)
subdir ('test')
pkg_mod = import('pkgconfig')
pkg_mod.generate(libraries : simpleFramework,
                 version : '0.0.1', name : 'simpleFramework', filebase : 'simpleFramework', subdirs : 'simpleFramework' ,description : 
                 'A SDL2 based GUI-library')
install_headers(incfiles, subdir : 'simpleFramework')

