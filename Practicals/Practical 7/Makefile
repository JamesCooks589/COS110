ofiles = main.o Calendar.o Event.o
gpp_o = g++ -c -std=c++98

main: $(ofiles)
	g++ -std=c++98 $(ofiles) -o main

main.o: main.cpp Calendar.h Utils.h Event.h
	$(gpp_o) main.cpp

Calendar.o: Calendar.cpp Calendar.h
	$(gpp_o) Calendar.cpp

Event.o: Event.cpp Event.h
	$(gpp_o) Event.cpp

run: main
	./main

clean:
	rm *.o main