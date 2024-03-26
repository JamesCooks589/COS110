ofiles = main.o
gpp_o = g++ -c -std=c++98

main: $(ofiles)
	g++ -std=c++98 $(ofiles) -o main
main.o: main.cpp SortList.h
	$(gpp_o) main.cpp
SortNode.o: SortNode.cpp SortNode.h
	$(gpp_o) SortNode.cpp
SortList.o: SortList.cpp SortList.h
	$(gpp_o) SortList.cpp
run: main
	./main
clean:
	rm -f *.o main