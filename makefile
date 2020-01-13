project3: main.o inputValidation.o Barbarian.o Medusa.o BlueMen.o HarryPotter.o Vampire.o
	g++ main.o inputValidation.o Barbarian.o Medusa.o BlueMen.o HarryPotter.o Vampire.o -o project3

main.o: main.cpp
	g++ -c main.cpp

inputValidation.o: inputValidation.cpp inputValidation.hpp
	g++ -c inputValidation.cpp

Barbarian.o: Barbarian.cpp Barbarian.hpp
	g++ -c Barbarian.cpp

Medusa.o: Medusa.cpp Medusa.hpp
	g++ -c Medusa.cpp

BlueMen.o: BlueMen.cpp BlueMen.hpp
	g++ -c BlueMen.cpp

HarryPotter.o: HarryPotter.cpp HarryPotter.hpp
	g++ -c HarryPotter.cpp

Vampire.o: Vampire.cpp Vampire.hpp
	g++ -c Vampire.cpp

clean:
	rm *.o project3
