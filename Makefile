VPATH = src/qjs-raylib/native

LINK_TARGET = qjs-raylib.so

DIST = dist/qjs-raylib

DIST_NATIVE = $(DIST)/native

OBJS = \
	qjs-raylib.o \
	structs.o

CFLAGS = \
	-Wall \
	-Wno-unknown-pragmas \
	-fpic

LIB_PATHS = -L/usr/local/lib/raylib/

LIBS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

REBUILDABLES = $(OBJS) dist build

%.o: %.c
	cd build && \
	gcc -c -fPIC -o $@ ../$<

all: $(LINK_TARGET) build_module
	@echo "\nAll done"

clean:
	rm -rf $(REBUILDABLES)
	@echo "\nClean done"

mkdirs:
	mkdir build && \
	mkdir dist && \
	mkdir $(DIST) && \
	mkdir $(DIST_NATIVE)

build_module:
	cd src/qjs-raylib/module && tsc
	cp -r src/qjs-raylib/module/native $(DIST)

$(LINK_TARGET): mkdirs $(OBJS)
	cd build && \
	gcc --shared -DJS_SHARED_LIBRARY -o ../$(DIST_NATIVE)/$@ $(OBJS) $(LIB_PATHS) $(LIBS)

