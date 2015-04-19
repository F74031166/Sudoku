all: solve.o give_question.o Sudoku.o Clock.o
	g++ -o solve solve.o Sudoku.o Clock.o
	g++ -o give_question give_question.o Sudoku.o
Sudoku.o: Sudoku.cpp Sudoku.h
	g++ -c Sudoku.cpp
Clock.o: Clock.cpp Clock.h
	g++ -c Clock.cpp
solve.o: solve.cpp Sudoku.h Clock.h
	g++ -c solve.cpp
give_question.o: give_question.cpp Sudoku.h
	g++ -c give_question.cpp
clean:
	rm solve*.o Sudoku*.o give_question*.o Clock*.o
