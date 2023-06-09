CC=g++ -std=c++17 -Wall -Werror -Wextra
CHECKFLAGS=-lgtest
CURRENTDIR = $(shell pwd)
BUILD_DIR=build
APP_DIR=MazeAndCaves
APP=MazeAndCaves
REPORTDIR=gcov_report
GCOV=--coverage
OPEN=
FILTER=
TEST_LIB:=./tests/tests_main.cc \
    ./model/parsing_file.cc \
    ./model/cave.cc \
    ./model/cave_automaton.cc \
	./model/maze.cc \
	./model/maze_solve.cc \
	./model/maze_generator.cc
CPPCHECKFLAG = --enable=all --suppress=unusedFunction --suppress=missingInclude --suppress=noConstructor --language=c++ --std=c++17

OS = $(shell uname)

ifeq ($(OS), Linux)
	CC+=-D OS_LINUX -g -s
	CHECKFLAGS+=-lpthread
	CHECK_LEAKS=CK_FORK=no valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=log.txt
	OPEN=xdg-open
	DIR=
	QTFLAGS=-spec linux-g++
else
	CC+=-D OS_MAC
	CHECK_LEAKS=CK_FORK=no leaks --atExit --
	FILTER=--gtest_filter=-*.Exception
	OPEN=open
	DIR=/$(APP).app
	QTFLAGS=
endif

all: build

build: 
	@mkdir -p $(BUILD_DIR)
	cd $(BUILD_DIR); cmake ..; make

rebuild: clean build

install: uninstall
	@mkdir -p $(APP_DIR)
	@cp -r $(BUILD_DIR)$(DIR) $(APP_DIR)

dist: install
	tar -czvf $(APP_DIR).tgz $(APP_DIR)
	mv $(APP_DIR).tgz $(APP_DIR)

uninstall:
	@rm -rf $(APP_DIR)

dvi:
	doxygen ./docs/Doxyfile
	$(OPEN) ./docs/html/index.html

tests: mostlyclean
	@$(CC) $(TEST_LIB) $(CHECKFLAGS) -o Test
	@./Test
	@rm -rf *.o *.a Test

gcov_report: mostlyclean
	@$(CC) $(TEST_LIB) -o Test $(GCOV) $(CHECKFLAGS)
	@./Test
	@lcov --no-external -c -d . -o $(APP).info
	@genhtml -o $(REPORTDIR) $(APP).info
	@$(OPEN) ./$(REPORTDIR)/index.html

check: style cppcheck leaks

style: 
	@cp ../linters/.clang-format .
	clang-format -style=google -i */*.cc */*.h
	@rm .clang-format

cppcheck:
	@cppcheck $(CPPCHECKFLAG) */*.cc */*/*.cc *.cc  */*.h */*/*.h *.h

leaks: mostlyclean
	@$(CC) $(TEST_LIB) $(CHECKFLAGS) -o Test
	@$(CHECK_LEAKS) ./Test $(FILTER)
	@rm -rf *.o *.a Test

clean:
	@rm -rf *.o *.a *.out *.gcno *.gch *.gcda *.info *.tgz $(REPORTDIR) Test $(BUILD_DIR) ./docs/html

mostlyclean:
	@rm -rf *.o *.a *.out *.gcno *.gch *.gcda *.info *.tgz $(REPORTDIR) Test

open:
ifeq ($(OS), Linux)
	./$(APP_DIR)/$(APP)
else
	open $(APP_DIR)/$(APP).app
endif
