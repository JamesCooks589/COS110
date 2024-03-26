ofiles = main.o Passenger.o Cargo.o SecretCargo.o
gpp_o = g++ -c -std=c++98

main: $(ofiles)
	g++ -std=c++98 $(ofiles) -o main
main.o: main.cpp Controller.h
	$(gpp_o) main.cpp
Exceptions.o: Exceptions.cpp Exceptions.h
	$(gpp_o) Exceptions.cpp
Plane.o: Plane.cpp Plane.h
	$(gpp_o) Plane.cpp
Controller.o: Controller.cpp Controller.h
	$(gpp_o) Controller.cpp
Passenger.o: Passenger.cpp Passenger.h
	$(gpp_o) Passenger.cpp
Cargo.o: Cargo.cpp Cargo.h
	$(gpp_o) Cargo.cpp
SecretCargo.o: SecretCargo.cpp SecretCargo.h
	$(gpp_o) SecretCargo.cpp
run: main
	./main
clean:
	rm -f *.o main