
PROJ_NAME := 4_STAGE_COMPILING
CFLAGS = -I./inc/
SRC_DIR := src/
MAC_DIR := macro/
ASS_DIR := ass/
OBJ_DIR :=obj/
OBJ_FILE := obj/main.o
OBJ_FILE += obj/helloa.o
OBJ_FILE += obj/hellob.o
CC := gcc


#stage1 compiling

macro/main.i: main.c
	$(CC) -E $(CFLAGS) $< -o $@
macro/helloa.i: $(SRC_DIR)helloa.c
	$(CC) -E $(CFLAGS) $< -o $@
macro/hellob.i: $(SRC_DIR)hellob.c
	$(CC) -E $(CFLAGS) $< -o $@

#stage2 compiling

ass/main.s: $(MAC_DIR)main.i
	$(CC) -S $< -o  $@
ass/helloa.s: $(MAC_DIR)helloa.i
	$(CC) -S $< -o $@
ass/hellob.s: $(MAC_DIR)hellob.i
	$(CC) -S $< -o $@

#stage3 compiling

obj/main.o: $(ASS_DIR)main.s
	$(CC) -c $< -o $@
obj/helloa.o: $(ASS_DIR)helloa.s
	$(CC) -c $< -o $@
obj/hellob.o: $(ASS_DIR)hellob.s
	$(CC) -c $< -o $@

.PHONY: build
build: $(OBJ_FILE)
	$(CC)  $^ -o bin/main
.PHONY: clean
clean:
	rm -rf bin/* ass/* macro/* obj/*


