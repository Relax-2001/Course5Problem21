#include <iostream>
#include <cstdlib>

using namespace std;

enum enRandomizeChoice { SmallLetter = 1, CapitalLetter = 2, SpecialCharecter = 3, RandomDigit = 4 };

int ReadPositiveNumber(string Message)
{
	int Number = 0;
	do
	{
		cout << Message << endl;
		cin >> Number;
	} while (Number <= 0);
	return Number;
}

int RandomNumber(int From, int To)
{

	int RandomNum = rand() % (To - From + 1) + From;

	return RandomNum;
}

char GenerateCharecter(enRandomizeChoice CharType)
{

	switch (CharType)
	{
	case enRandomizeChoice::SmallLetter:
		return char(RandomNumber(97, 122));
		break;

	case enRandomizeChoice::CapitalLetter:
		return char(RandomNumber(65, 90));
		break;

	case enRandomizeChoice::SpecialCharecter:
		return char(RandomNumber(33, 47));
		break;

	case enRandomizeChoice::RandomDigit:
		return char(RandomNumber(48, 57));
	}
}

string GenerateWord(enRandomizeChoice CharType, int Length)
{
	string Word = "";

	for (int i = 1 ; i <= Length ; i++)
	{
		Word += GenerateCharecter(CharType);
	}

	return Word;

}

string GenerateKey()
{

	string Key = "";

	Key = GenerateWord(enRandomizeChoice::CapitalLetter , 4) + "-";
	Key += GenerateWord(enRandomizeChoice::CapitalLetter, 4) + "-";
	Key += GenerateWord(enRandomizeChoice::CapitalLetter, 4) + "-";
	Key += GenerateWord(enRandomizeChoice::CapitalLetter, 4) ;

	return Key;
}

void GenerateKeys(int NumberOfKeys)
{

	for (int i = 1; i <= NumberOfKeys; i++)
	{
		cout << "Key [" << i << "] ";
		cout << GenerateKey() << endl;
	}

}


int main()
{
	srand((unsigned)time(NULL));

	int NumberOfKeys = ReadPositiveNumber("Enter number of keys to generate");

	 GenerateKeys(NumberOfKeys);
	

}
