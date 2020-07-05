VPATH = src/qjs-raylib/native /usr/local/include

TARGET = a.out

QJS-RAYLIB = ../../dist/qjs-raylib
LIBS = $(QJS-RAYLIB)

REBUILDABLES = $(TARGET) qjs-raylib

all: $(TARGET)
	@echo "\nAll done"

$(TARGET): qjs-raylib
	qjsc test.js

qjs-raylib:
	cp -r $(QJS-RAYLIB) ./

clean:
	rm -rf $(REBUILDABLES)
	@echo "\nClean done"
