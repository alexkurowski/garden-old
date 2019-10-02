default: build_osx run

INPUT_OSX = \
	lib/osx/libraylib.a \
	src/main.cpp

OUTPUT = bin/out

LIBS = \
	-lstdc++

LIBS_OSX = \
	-framework CoreVideo \
	-framework IOKit     \
	-framework Cocoa     \
	-framework GLUT      \
	-framework OpenGL

OPTS = \
	-Iinclude  \
	-std=c++17 \
	-g         \
	-o $(OUTPUT)

build_osx: clean prepare copy_assets
	clang++ $(LIBS) $(LIBS_OSX) $(OPTS) $(INPUT_OSX)

clean:
	rm -rf ./bin

prepare:
	mkdir ./bin

copy_assets:
	cp -r ./assets ./bin/

run:
	$(OUTPUT)
