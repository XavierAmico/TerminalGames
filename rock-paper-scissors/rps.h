#include <string>

class rps
{
	public:
	rps();
	std::string choose();
	std::string ask();
	int checkifWin(std::string player, std::string bot);

	private:
	std::string choices[3] = {"ROCK","PAPER","SCISSORS"};

};
