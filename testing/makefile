OBJ = DatabaseController.o ArrayCollection.o CUACSController.o Entity.o EntityBuilder.o interface/main.cpp

test: $(OBJ)
	g++ $(OBJ) -l sqlite3 -o test

DatabaseController.o: data/DatabaseController.h data/DatabaseController.cpp
	g++ -c data/DatabaseController.h data/DatabaseController.cpp -l sqlite3

ArrayCollection.o: interface/ArrayCollection.h interface/ArrayCollection.cpp interface/Description.h
	g++ -c interface/ArrayCollection.h interface/ArrayCollection.cpp -l sqlite3

CUACSController.o: interface/CUACSController.h interface/CUACSController.cpp ArrayCollection.o DatabaseController.o Entity.o EntityBuilder.o
	g++ -c interface/CUACSController.h interface/CUACSController.cpp -l sqlite3

Entity.o: interface/Entity.h interface/Entity.cpp ArrayCollection.o
	g++ -c interface/Entity.h interface/Entity.cpp -l sqlite3

EntityBuilder.o: interface/EntityBuilder.h interface/EntityBuilder.cpp ArrayCollection.o Entity.o
	g++ -c interface/EntityBuilder.h interface/EntityBuilder.cpp -l sqlite3

clean:
	rm *.o test
