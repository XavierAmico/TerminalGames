#ifndef WORDLE_H
#define WORDLE_H

#include <string>
#include <vector>

class Wordle {
public:
    Wordle();           // Loads words and seeds random
    void startGame();   // Displays welcome and calls gameMgr()

private:
    void gameMgr();     // Controls the game loop
    void selectWord();
    std::string askUser();
    bool search(std::string input);
    void generateOutput(std::string guess);
    std::string colorLetter(char ltr, int index);

    std::string curWord;
    std::string yellow = "\033[33m";
    std::string green = "\033[92m";
    std::string reset = "\033[0m";
    bool gameWin = false;
    std::vector<std::string> words;
    std::vector<std::string> output;
};

#endif
