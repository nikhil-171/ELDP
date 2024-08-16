//Nikhil Mhatre
#include<cstdlib>
#include <vector>
#include <string>
#include <iostream>
#include <ios>
#include <iomanip>
#include <algorithm> 


using namespace std;
vector <string> dict {"armor", "radar", "aerospace","contract", "missile", "design", "engineer", "sensor", "defence", "global", "secure", "signal", "robotics", "systems", "circuit", "drone", "naval", "control", "electric", "platform"};
int guess = 12;                                         //variable declerations
string guessCharIn;
int charMatchCount = 0;
string reset;
vector <string> prevGuess;

void Check(string wordIn, string guessCharIn);          //function declerations
bool VaildGuess(string guessChar){
    return(isalpha(guessChar[0]) && count(prevGuess.begin(), prevGuess.end(), guessChar) < 1);
}

int main()
{
    //dict.push_back("armor");

	srand(time(0));                                     
	int randNum = rand() % 20;                          //set random number to get a random word from the dictonary
	string wordIn = dict[randNum];                     
	int wordLen = wordIn.length();                      

	//cout << wordIn << endl;                                         
	cout << "HANGMAN" << endl;                                                                  //Game intro setup
	cout << "The current word has "+ std::to_string(wordLen) +" letters."<< endl;
	cout << "You have "+ std::to_string(guess) + " guesses left."<< endl;
	cout << "Guess letter : " << endl;

	while (guess>0)                                                                             //Not giving more than 12 guesses per word
	{
		cin >> guessCharIn;
		if (!VaildGuess(guessCharIn)){                                                          //Making sure each guess is an alphabetic character that hasn't been previously entered and waiting until a valid response is entered.
		    cout << "Invalid guess. Please enter new single alphabetic character" << endl;
		    continue;
		}
        prevGuess.push_back(guessCharIn);

		if (guessCharIn == "quit") {                                                            //Check if "quit" is entered during the game to end program
			exit(0);
		}
		Check(wordIn, guessCharIn);                                                             //Function call
		guess--;                                                                                //Tracking number of guesses and updated player
		cout << " You have "+ std::to_string(guess) + " guesses left."<< endl;                  
		if(charMatchCount == wordLen) {                                                         //Once the number of characters that match the word is equal to the length of the word the player wins.
			for (int i=0; i<wordLen; i++) {
			    cout << wordIn[i] << setw(5);                                                   //priting final word
			}
			cout << " All letters guessed. Congrats! Play another round? (yes/no)" << endl;
			
			cin >> reset;                                                                       //Checking user input to play another round
		}
		if (reset == "no") {
			exit(0);
		}
		if(reset == "yes") {                                                                    //Randomizing the next word and reseting the charMatchCount, guess attempts, previosly guessed charcters for new word
			srand(time(0));
			randNum = rand() % 20;
			wordIn = dict[randNum];
			wordLen = wordIn.length();
			prevGuess.clear();
			charMatchCount = 0;
			guess = 12; 
			reset = "   ";
			//cout << wordIn << endl;
			cout << "The current word has "+ std::to_string(wordLen) +" letters."<< endl;
		}
		
	}
    cout << "Ran out of guesses. Game Over!" << endl;
	return(0);
}

void Check(string word, string guessChar)                                                       // Check function that outputs the letter the player guessed at the corresponding index in the word if it matches.
{                                                                                               // If it does not match a "_" is outputed to help the player visualize the word. 
	int wordLen = word.length();
	for (int i=0; i<wordLen; i++) {
		if(guessChar[0] == word[i]) {
			cout << guessChar[0] << setw(5);
			charMatchCount++;
		}
		else {
			cout << "_" << setw(5);
		}
	}
}
