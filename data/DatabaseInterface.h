#include <string>
#include "./interface/Animal.h"

static const std::string DATABASE_DIR = "data/";
static const std::string DATABASE_FILENAME = "data.db";

class DatabaseInterface //final
{
public:
	DatabaseInterface();
	~DatabaseInterface();
	static int getDB();
    static int pushDBAnimal(Animal &animal);
};
