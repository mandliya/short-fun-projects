/*
 * A simple guessing game hangman.
 *
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <utility>

using namespace std;

void drawState( int state )
{

    switch( state ) 
    {
        case 1:
        {
            cout << endl << endl 
                 << "\033[1;31m   +----+  \033[0m"<< endl 
                 << "\033[1;31m   |    |  \033[0m"<< endl 
                 << "\033[1;31m   |       \033[0m"<< endl 
                 << "\033[1;31m   |       \033[0m"<< endl 
                 << "\033[1;31m   |       \033[0m"<< endl 
                 << "\033[1;31m   |       \033[0m"<< endl 
                 << "\033[1;31m  =============\033[0m"<< endl << endl; 
            break;
        }

        case 2:
        {
            cout << endl << endl 
                 << "\033[1;31m   +----+  \033[0m" << endl 
                 << "\033[1;31m   |    |  \033[0m" << endl 
                 << "\033[1;31m   |    O  \033[0m" << endl 
                 << "\033[1;31m   |    |  \033[0m" << endl 
                 << "\033[1;31m   |       \033[0m" << endl 
                 << "\033[1;31m   |       \033[0m" << endl 
                 << "\033[1;31m  =============\033[0m"<<endl<<endl; 
            break;
        }

        case 3:
        {
            cout << endl << endl 
                 << "\033[1;31m   +----+  \033[0m" << endl 
                 << "\033[1;31m   |    |  \033[0m" << endl 
                 << "\033[1;31m   |    O  \033[0m" << endl 
                 << "\033[1;31m   |   /|  \033[0m" << endl 
                 << "\033[1;31m   |       \033[0m" << endl 
                 << "\033[1;31m   |       \033[0m" << endl 
                 << "\033[1;31m  =============\033[0m"<<endl<<endl; 
            break;
        }

        case 4:
        {
            /* To print '\' we need an esacape char, that is why \\ */
            cout << endl << endl 
                 << "\033[1;31m   +----+   \033[0m" << endl 
                 << "\033[1;31m   |    |   \033[0m" << endl 
                 << "\033[1;31m   |    O   \033[0m" << endl 
                 << "\033[1;31m   |   /|\\ \033[0m" << endl 
                 << "\033[1;31m   |        \033[0m" << endl 
                 << "\033[1;31m   |        \033[0m" << endl 
                 << "\033[1;31m  =============\033[0m"<<endl<<endl; 
            break;
        }

        case 5:
        {
            /* To print '\' we need an esacape char, that is why \\ */
            cout << endl << endl 
                 << "\033[1;31m   +----+   \033[0m" << endl 
                 << "\033[1;31m   |    |   \033[0m" << endl 
                 << "\033[1;31m   |    O   \033[0m" << endl 
                 << "\033[1;31m   |   /|\\ \033[0m" << endl 
                 << "\033[1;31m   |   /    \033[0m" << endl 
                 << "\033[1;31m   |        \033[0m" << endl 
                 << "\033[1;31m  =============\033[0m"<<endl<<endl; 
            break;
        }

        case 6:
        {
            /* To print '\' we need an esacape char, that is why \\ */
            cout << endl << endl 
                 << "\033[1;31m   +----+   \033[0m" << endl 
                 << "\033[1;31m   |    |   \033[0m" << endl 
                 << "\033[1;31m   |    O   \033[0m" << endl 
                 << "\033[1;31m   |   /|\\ \033[0m" << endl 
                 << "\033[1;31m   |   / \\ \033[0m" << endl 
                 << "\033[1;31m   | \033[0m\033[31mYou are Dead \033[0m" << endl 
                 << "\033[1;31m  ================\033[0m"<<endl<<endl; 
            break;
        }

        default:
            std::cout << "Invalid state, something went wrong\n";
    }
}

std::vector<std::string> loadWords(const std::string & path)
{
    std::ifstream file(path);
    if (! file.is_open() ) {
        std::cerr << "Error opening words file\n";
        std::exit(-1);
    }

    std::vector<std::string> words;
    std::string word{""};
    while(std::getline(file, word))
    {
        words.push_back(word);
    }
    return words;
}

void clearScreen()
{
    std::cout << std::string(100, '\n');
}

int main(int argc, char * argv[])
{
    if (argc != 2 )
    {
        std::cerr << "Run: <executable> <word file>\n";
        std::exit(-1);
    }
    std::string path(argv[1]);
    std::vector<std::string> words = loadWords(path);
    std::srand ( unsigned ( std::time(0) ) );
    std::string secretWord, guessWord, wrongGuessed("");
    char answer,regame;
    int gameState;
    bool firstWrong = false;
    bool won = false;
    std::size_t found;
    int score = 0;
    do {
        std::random_shuffle(words.begin(), words.end() );
        secretWord = words[0];
        std::transform(secretWord.begin(), secretWord.end(), secretWord.begin(), ::tolower);
        guessWord = std::string(secretWord.length(), '_');
        gameState = 1;
        firstWrong = false;
        wrongGuessed = "";
        won = false;
        while(gameState != 6)
        {
            clearScreen();
            std::cout << "\033[1;43m Welcome to Hangman \033[0m\n\n";
            drawState(gameState);
            std::cout << "\nYour Word: " << guessWord << std::endl;;
            if (won)
            {
                std::cout << "\033[32mCurrent Score :" << score << "\033[0m" << std::endl;
                std::cout << "\033[1;42m Hurray you won!!! \033[0m\n\n";
                break;
            }

            std::cout << "\033[31mCurrent Score :" << score << "\033[0m" << std::endl;

            if (firstWrong) 
            {
                std::cout << "Wrong guessed chars :" << wrongGuessed << std::endl;
            }
            std::cout << "\nGuess a character:";
            std::cin >> answer;
            found = guessWord.find(answer, 0);
            if (found != std::string::npos)
            {
                continue;
            }
            found = secretWord.find(answer, 0);
            if (found == std::string::npos)
            {
                ++gameState;
                firstWrong = true;
                wrongGuessed += answer;
                score -= 5;
                continue;
            }
            while ( found != std::string::npos )
            {
                guessWord[found] = answer;
                found = secretWord.find(answer, found+1);
            }
            score += 10;
            if (secretWord.compare(guessWord) == 0) {
                score += 30;
                won = true;
            }
        }
        if (!won) {
            clearScreen();
            std::cout << "\033[1;43m Welcome to Hangman \033[0m\n\n";
            drawState(gameState);
            std::cout << "\033[31mCurrent Score :" << score << "\033[0m" << std::endl;
            std::cout <<"The correct word was :" << secretWord << std::endl;
            std::cout << "\033[1;41m Game Over!!! \033[0m\n\n";
        }
        std::cout << "Do you want to continue ( 'y' for yes, anything else for no ):";
        std::cin >> regame;
        regame = std::tolower(regame);
    } while(regame == 'y');
    std::cout << "Total Score:" << score << std::endl;
    std::cout << "Good bye!" <<std::endl;

    return 0;
}
