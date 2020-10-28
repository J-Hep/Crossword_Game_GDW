#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <string.h> 
using namespace std;


int main()
{
	const int SIZE = 10;
	ifstream wordList;
	wordList.open("Wordlist.txt");

	//array creation
	string words[SIZE];

	//vector data structure to store arrays and of words
	vector <vector<string>> crossword;

	//set size of vector to constant size
	crossword.resize(SIZE);

	//go through vectors
	for (int i = 0; i < SIZE; i++)
	{
		crossword[i].resize(SIZE);
	}

	//declare a string for each line in txt file
	string line; 
	int count = 0;
	while (getline(wordList, line))
	{
		//assigns each line to an area in the array
		words[count] = line;
		//count to read next line
		count++;
	}

	//close ifstream
	wordList.close();

		// S E L E C T I O N  S O R T \\

	//Sorting from largest to smallest strings
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = i + 1; j < SIZE; j++)
		{
			//compare words at both indexes and determines which is longer
			if (words[i].length() < words[j].length())
			{
				//cout << words[i].length(1)
				//swap elements, per selectionsort
				string wordLarge = words[j];

				//swap indexes of i and j (comparison)
				words[j] = words[i];
				words[i] = wordLarge;

			}
		}
	}

	// M A I N    O  U  T  P  U  T  \\

	//outputs all words in array
	for (int i = 0; i < SIZE; i++)
	{
		cout << words[i] << endl;
	}

	// H A N G  M A N   T E S T \\
	
		
			// TEST CODE \\
	
	/* This block of code outputs the word at words[i]
	* then basically asks the user to spell it out, and it'll 
	* go through all interations of it.
	* 
	* words[SIZE] IS THE ARRAY, hence words[0-10] right now are valid
	*/

	// userInput car
	char userInput;
	//nested for loop, this one runs through words
	for (int i = 0; i < SIZE; i++)
	{
		//assigns the word from the array into a variable
		std::string wordCheck = words[i];

		cout << words[i] << endl;
		//second for loop, runs through letters
		for (int j = 0; j < wordCheck.length(); j++)
		{
			//assigns first letter of word 
			char letter = wordCheck[j];
			cin >> userInput;
			//check statement
			if (userInput == wordCheck[j])
			{
				cout << "Correct!\n";
			}
			else
			{
				cout << "Incorrect!\n";
			}
			
		}
		cout << "\n";
	}

	return 0;
}

