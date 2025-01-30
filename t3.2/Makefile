CC      = clang
CFLAGS  = -std=c99 -Og -g -Wpedantic
LDFLAGS = -lc -lm
BINNAME = main

ifeq ($(OS),WINDOWS_NT)
	RM = del /f /q
	BIN = $(BINNAME).exe
else
	RM = rm -f
	BIN = $(BINNAME)
endif

.PHONY: all

all: clean build run

clean:
	$(RM) $(BIN)

build:
	@echo building...
	$(CC) *.c $(CFLAGS) $(LDFLAGS) -o $(BIN)

run:
	@echo running...
	@./$(BIN)
