CC= g++ 
CFLAGS= -Wall -Wextra -Werror
STANDART= -std=c++17
TESTFLAGS=-lgtest
TESTFILES= tests/*.cc

all: gcov_report install dvi dist

tests: clean
	$(CC) $(CFLAGS) --coverage $(STANDART) $(TESTFILES) controller/*.cc model/*.cc -o test $(TESTFLAGS)
	./test

gcov_report: tests clean
	./test
	lcov -t "test" -o test.info -c -d . --no-external
	genhtml -o report test.info
	open report/index.html

install: uninstall
	@mkdir build
	@cd build && qmake ../interface/Calculator.pro && make && rm -rf *o *.cpp Makefile *.h .qmake.stash

uninstall:
	rm -rf build

dist:
	@rm -rf dist.tar.gz
	@tar -cvzf dist.tar.gz build/Calculator.app

dvi:
	@doxygen conf && mv html documentation
	@open documentation/index.html

clean: uninstall
	rm -rf *.out *.o s21_matrix_oop.a *.gcda *.gcno *.info test main
	rm -rf report
	rm -rf documentation
	rm -rf dist.tar.gz
	rm -rf Main
