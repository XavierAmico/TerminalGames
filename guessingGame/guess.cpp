#include <iostream>


int main()
{
    srand(time(NULL));
    
    int secretNum = 1 + rand() % 10;
    int userGuess;
    bool gameEnd;
    
    while (gameEnd == false)
    {
        std::cout << "Guess a number! (1-10): "; 
        std::cin >> userGuess;
        
        if (userGuess != secretNum)
        {
            std::cout << "Sorry, that number is " << abs(secretNum - userGuess) << " away from the secret number." << std::endl;
        }
        if (userGuess == secretNum)
        {
            std::cout << "Congratulations, that's correct! The number was " << secretNum << ", Good Job!"<< std::endl;
            gameEnd = true;
        }
    }
    return 0;
}
