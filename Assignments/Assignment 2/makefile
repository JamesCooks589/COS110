ofiles = main.o matrix.o vector.o arithmetic.o
gpp_o = g++ -c -std=c++98

main: $(ofiles)
	g++ -std=c++98 $(ofiles) -o main

main.o: main.cpp matrix.h vector.h
	$(gpp_o) main.cpp

matrix.o: matrix.cpp matrix.h
	$(gpp_o) matrix.cpp

vector.o: vector.cpp vector.h
	$(gpp_o) vector.cpp

arithmetic.o: arithmetic.cpp arithmetic.h
	$(gpp_o) arithmetic.cpp

run: main
	./main

clean:
	rm *.o main
                                                               
