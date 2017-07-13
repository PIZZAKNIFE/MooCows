// MooCows.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <string>
#include <locale>
#include <algorithm>

using namespace std;

constexpr int WORD_LENGTH = 6;
constexpr int WORD_COUNT = 3;

vector <string> words;

string normalizeInput(string input) {
	string lowered = input;
	transform(lowered.begin(), lowered.end(), lowered.begin(), ::tolower);
	return lowered;
}

void buildWords(string strArry[])
{
	//guard
	if (strArry->length() > WORD_COUNT) {
		return;
	}
	//hydrate word list
	for (string::size_type i = 0; i < strArry->length(); ++i) {
		words.push_back(normalizeInput(strArry[i]));
	}
	//confirm
	return ;
}

string fetchMagicWord(vector <string> strArry) {
	//select a word at random for the instance of a game
	
	// juggle the seed!
	srand(time(NULL));
	int randomIndex = rand() % WORD_COUNT;
	return strArry[randomIndex];
}

bool checkWordMatch(string guessed, string magicWord) {
	//moment of truth for the user!
	cout << "Checking against our records....";
	return guessed == normalizeInput(magicWord);
}

bool yesOrNo(string answer) {
	return normalizeInput(answer) == "yes";
}

string promptAndFetchUserGuess() {
	string Guess = "";
	cout << "Make a guess: " << endl;
	getline(cin, Guess);
	Guess = normalizeInput(Guess);
	cout << "Your guess was: ";
	cout << Guess << endl;
	return Guess;
}

int main()
{
	string guessed = "";
	bool isCorrect = false;
	bool doPlayAgain = true;
	words = { "GasGas", "Harley", "Horsey" };
	string magicWord = fetchMagicWord(words);
	while (!isCorrect && doPlayAgain) {
		guessed = promptAndFetchUserGuess();
		isCorrect = checkWordMatch(guessed, magicWord);
		if (isCorrect) {
			cout << "You Win! Your winning guess: " << guessed << endl;
			doPlayAgain = false;
		}
		else {
			// play again ?
			string userResponse = "No";
			cout << "Nope! " << "You incorrectly guessed: " << guessed << endl;
			cout << "Do you want to try again(yes/no)? " << endl;
			getline(cin, userResponse);
			doPlayAgain = yesOrNo(userResponse);
		}
	}

	cout << "The Magic Word was: " << magicWord << endl;
	return 0;
}


