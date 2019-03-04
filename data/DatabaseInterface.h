#include <string>
#include "interface/Animal.h"
#include "interface/Client.h"

static const std::string DATABASE_DIR = "data/";
static const std::string DATABASE_FILENAME = "data.db";

class DatabaseInterface //final
{
public:
	DatabaseInterface();
	~DatabaseInterface();
    static int getAnimalCount();
    static int getClientCount();
    static Animal** getAnimalArray();
    static Client** getClientArray();
    static void pushDBAnimal(Animal &animal);
    static void pushDBClient(Client &client);
};
