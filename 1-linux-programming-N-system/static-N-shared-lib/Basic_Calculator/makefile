	
PROJ_NAME := calculator
INC_DIR :=inc/
SRC_DIR := ./src/
CC := gcc
OBJ_FILE := obj/main.o
OBJ_FILE += obj/libra.o
CFLAGS := -I./inc/
STATIC_DIR := lib/static/
SHARED_DIR := lib/shared/

.PHONY:build clean main_run static static_link shared shared_link static_run shared_run

obj/main.o: main.c 
	@$(CC) -c $(CFLAGS) $^ -o $@ -fPIC
	
obj/libra.o: $(SRC_DIR)libra.c 
	@$(CC) -c $(CFLAGS) $^ -o $@ -fPIC
clean:
	@rm -rf bin/* obj/* lib/shared/* lib/static/*
	@echo "Delete all file"
main_run:
	@./bin/main

build: $(OBJ_FILE)	
	@$(CC) -o bin/main $^
	@echo "Finished build process"

#create static library
static:
	@ar rcs $(STATIC_DIR)libcalc.a $(OBJ_FILE)
	@echo "Create static library"
#use static lib to create main.exe
static_link:
	@$(CC) obj/main.o -Llib/static -lcalc -o bin/static_main
	@echo "Finished build process"

shared:
	@$(CC) -shared -o $(SHARED_DIR)libcalc.so $(OBJ_FILE)

shared_link:
	@$(CC) obj/main.o -Llib/shared -lcalc -o bin/shared_main
static_run:
	@./bin/static_main
shared_run:
	@./bin/shared_main
#khi tao shared file
#sudo cp libcalc.so /usr/lib
#de them shared lib vao linux

#neu muon xoa shared lib
#sudo rm /usr/lib/libcalc.so

