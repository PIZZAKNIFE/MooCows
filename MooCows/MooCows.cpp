// MooCows.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <locale>

using namespace std;

constexpr int WORD_LENGTH = 6;

void promptForRecurse() {
	string doRecurse = "";
	cout << "Want to make another guess?(yes/no)\n";
	getline(cin, doRecurse);
	string recurseChoice;
	locale loc;
	for (string::size_type i = 0; i < doRecurse.length(); ++i) {
		recurseChoice += tolower(doRecurse[i], loc);
	}
	if (recurseChoice == "yes") {
		promptUser();
	}
	else {
		cout << "Thanks for Playing\n";
	}
}

void promptUser() {
	string Guess = "";
	cout << "Make a guess: ";
	getline(cin, Guess);
	cout << "\nYour guess was: ";
	cout << Guess + "\n";
	promptForRecurse();
	return;
}

int main()
{
	cout << "Can you guess the " << WORD_LENGTH << " letter word?" << endl;
	promptUser();
	return 0;
}


