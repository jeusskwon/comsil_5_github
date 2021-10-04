main : main.o array.o rangearray.o
	g++ -o main main.o array.o rangearray.o
main.o : Array.h RangeArray.h main.cpp
	g++ -c -o main.o main.cpp

array.o : Array.h array.cpp
	g++ -c -o array.o array.cpp

rangearray.o : RangeArray.h rangearray.cpp
	g++ -c -o rangearray.o rangearray.cpp
