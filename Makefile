COMPILER = clang
SOURCE_LIBS = -I./deps/macos_arm
OSX_OPT = -Ldeps/macos_arm/ -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL deps/macos_arm/libraylib.a
OSX_OUT = -o build/three-body
CFILES = src/three-body.c

build_osx:
	$(COMPILER) $(CFILES) $(SOURCE_LIBS) $(OSX_OUT) $(OSX_OPT)