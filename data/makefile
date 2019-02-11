OBJ = main.o DatabaseInterface.o

cuACS: $(OBJ)
	g++ -o cuACS $(OBJ) -l sqlite3

main.o: main.cpp
	g++ -c main.cpp

DatabaseInterface.o: DatabaseInterface.cpp DatabaseInterface.h
	g++ -c DatabaseInterface.cpp

clean:
	rm -f $(OBJ) cuACS
