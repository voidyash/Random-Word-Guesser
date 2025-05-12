#include<iostream>
#include<vector>
#include<ctime>
#include<cstdlib>
#include<algorithm>
#include<set>

void giveHint(const std::string& word, int hintType)
{
	if (hintType == 1)
	{
		std::cout << "Hint: The word has " << word.length() << " letters" << std::endl;
	}
	else if (hintType == 2)
	{
		std::cout << "Hint: The first letter of the word is " << word[0] << std::endl;
	}
	else if (hintType == 3)
	{
		std::cout << "Hint: The word contains the letter " << word[rand() % word.length()] << std::endl;
	}
	else if (hintType == 4)
	{
		std::cout << "Hint: The word contains the letter " << word[rand() % word.length()] << std::endl;
	}
	else if (hintType == 5)
	{
		std::cout << "Hint: The word contains the letter " << word[rand() % word.length()] << std::endl;
	}
}

int main()
{
	srand(time(0));

	while (true)
	{
		std::vector<std::string> wordList = { "life", "exit", "ryzen", "router", "google", "class", "pilot" };


		std::string chosenWord = wordList[rand() % wordList.size()];

		std::string guessedWord(chosenWord.length(), '_');

		int attempts = 15;
		std::set<char> guessedLetters;

		std::cout << "WELCOME TO THE RANDOM WORD GUESSER! 😁🎉" << std::endl;
		std::cout << "GIESS THE WORD BY ENTERING ONE WORD AT A TIME! " << std::endl;

		while (attempts > 0 && guessedWord != chosenWord)
		{
			std::cout << "\n Your current guess: " << guessedWord << std::endl;
			std::cout << "You have " << attempts << " attempts left!" << std::endl;

			char guess;
			std::cout << "Enter your guess (or type '?' for a hint): ";
			std::cin >> guess;

			if (guess == '?')
			{
				giveHint(chosenWord, rand() % 3 + 1);
				continue;
			}

			bool correct = false;
			for (size_t i = 0; i < chosenWord.length(); i++)
			{
				if (tolower(chosenWord[i]) == tolower(guess))
				{
					guessedWord[i] = chosenWord[i];
					correct = true;
				}
			}

			if (correct)
			{
				std::cout << "Correct Guess! 🎯" << std::endl;
			}
			else
			{
				std::cout << "Wrong Guess! ❌" << std::endl;
				attempts--;
			}
		}
		if (guessedWord == chosenWord)
		{
			std::cout << "\n CONGRATULATIONS! YOU GUESSED THE WORD: " << chosenWord << std::endl;
		}
		else
		{
			std::cout << "\n GAME OVER! THE WORD WAS: " << chosenWord << std::endl;
		}
		
		// Ask the user wants to play again
		std::string playAgain;
		std::cout << "\n Do you want to play again? (yes/no)" << std::endl;
		std::cin >> playAgain;

		std::transform(playAgain.begin(), playAgain.end(), playAgain.begin(), ::tolower);
		
		if (playAgain == "no")
		{
			std::cout << "Thanks for playing! GoodBye! " << std::endl;
			break;
		}
		else if (playAgain != "yes")
		{
			std::cout << "Invalid Response!. Exiting Program." << std::endl;
			break;
		}
	}

	return 0;
}