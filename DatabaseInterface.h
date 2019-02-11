#include <string>

static const std::string DATABASE_DIR = "data/";
static const std::string DATABASE_FILENAME = "data.db";

class DatabaseInterface //final
{
public:
	DatabaseInterface();
	~DatabaseInterface();
	static int getDB();
};
