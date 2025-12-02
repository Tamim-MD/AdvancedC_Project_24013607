CC = gcc                   # compiler
CFLAGS = -Wall -g          # warning + debug flags

SRC = src/main.c src/vocab.c   # source files
OUT = hanji.exe                # output program (Windows)

all: $(OUT)                # default build target

$(OUT): $(SRC)             # build rule
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

clean:
	-del $(OUT) 2>nul      # remove exe (ignore errors)
