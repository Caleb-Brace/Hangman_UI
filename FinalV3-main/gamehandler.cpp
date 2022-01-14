/*
* Amanuel Fufa, Caleb Brace, Caleb McGraw
* CIS 227
* Week 7
*
* 1/27/21 - 3/8/21
*/

#include <map>
#include "gamehandler.h"
#include <string>
#include <algorithm>
#include <iostream>
#include "mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QIODevice>

using namespace std;

int winCount = 0;
int lossCount = 0;

vector<char> guessBank;

string hidden;
string bankStorage;

string GameHandler::display(bool typeCheck, int& n) {

    //this runs if reading from array
    if (typeCheck) {
        MainWindow window;

        string placeholder = "Position " + to_string(n) + ": " + wordArray[n];

        return placeholder;
    }

    //this runs if reading from vector (made from file)
    else {

        string placeholder = "Position " + to_string(n) + ": " + wordsVector[n];

        return placeholder;
    }

}

//clear guesses made
void GameHandler::clearBank() {
    guessBank.clear();
}

//reset score
void GameHandler::clearScore() {
    winCount = 0;
    lossCount = 0;
}


void GameHandler::bankStore(bool typeCheck, int& n) {

    if (typeCheck) {

        bankStorage = wordArray[n];
        for (int i = 0; i < bankStorage.length(); i++) {    //Stores word to be manipulated for letter-to-letter guessing
            guessBank.push_back(bankStorage[i]);

        }
    }

    else {

        bankStorage = wordsVector[n];
        for (int i = 0; i < bankStorage.length(); i++) {
            guessBank.push_back(bankStorage[i]);

        }
    }
}

char GameHandler::displayHint() {


    addToScore(hintMinusPoints);

    char placeholder = hidden.at(0);
    return placeholder;
    }

    //TODO
//get word, and "hide it" from displaying
void GameHandler::hide(bool typeCheck, int& n) {
    //this runs if reading from array

    if (typeCheck) {

        hidden = wordArray[n];
        int x = hidden.length();

        string hidi(x - winCount, '-');

        cout << hidi << endl;
    }

    //this runs if reading from vector (made from file)
    else {
        hidden = wordsVector[n];
        int x = hidden.length();

        string hidi(x - winCount, '-');

        cout << hidi << endl;
    }
}


//validate menu has correct input numbers
bool GameHandler::ValidateMenuScope(int& menu) {

    if (menu >= 1 && menu <= 5) {
        return true;
    }

    else {
        return false;
    }
}

    //TODO
bool GameHandler::checkGuess(string& guess) {

    // converts the guess to lower case to ensure a hit regardless of capitilization
    transform(guess.begin(), guess.end(), guess.begin(), :: tolower);


    //if guess is correct
    if (find(guessBank.begin(), guessBank.end(), guess[0])!= guessBank.end()) {

        winCount = winCount + 1;
        addToScore(correctGuessPoints);

        cout << "You have guessed " << winCount << " letters correct!" << endl;

        // finds the guessed letter within the guessBank array and erases it

        vector<char> :: iterator gFinder = find(guessBank.begin(), guessBank.end(), guess[0]);
        if (gFinder != guessBank.end()) guessBank.erase(gFinder);

        return true;
    }

    //if guess is incorrect
    else {

        lossCount = lossCount + 1;
        addToScore(incorrectGuessPoints);

        cout << "You have guessed " << lossCount << " times incorrectly! (out of 5)" << endl;

        return false;
    }
}



    //TODO
bool GameHandler::gameState() {

    //if game hasnt been lost or won yet
    if (lossCount <= 4 && winCount < hidden.length() - 1) {

        return true;
    }

    //reset when game is finished
    else {

        if (lossCount == 5) {
            outcome = "You Lose";

            cout << "\nYou Lose\n";
        }
        else {
            addToScore(finishWordScore);
            outcome = "You WIN!";

            cout << "\nYou Win!\n";
        }

        // Write score to file
        writeScoreToFile(initials, currentScore);

        setCurrentScore(0);
        guessBank.clear();

        winCount = 0;
        lossCount = 0;

        return false;
    }
}

//validate array choice is within scope
bool GameHandler::ValidateArrayScope(int& arrayPosition) {

    //ensure a word is chosen, not too low or high
    if (arrayPosition >= 1 && arrayPosition <= 12) {
        return true;
    }

    else {
        return false;
    }
}

void GameHandler::CreateVector() {
    string line;
    ifstream myFile;

    myFile.open(wordsFile);

    //Get all lines in file and add them to a vector
    if (myFile.is_open()) {
        while (getline(myFile, line)) {
            wordsVector.push_back(line);
        }

        myFile.close();
    }
}

void GameHandler::addToScore(int& score) {
    currentScore += score;
}

void GameHandler::setCurrentScore(int score) {
    currentScore = score;
}

int GameHandler::getCurrentScore() {
    return currentScore;
}

void GameHandler::writeScoreToFile(string& name, int& score) {
    ofstream file(scoreFile, ios::app);

    QFile readScore("Scores.txt");


    if (readScore.open(QIODevice::WriteOnly | QIODevice::Text)){

        QTextStream stream(&readScore);

        file << name << " " << score << endl;
    }

    file.close();
}

void GameHandler::readScoreFile() { //Called to use log score on exit
    ifstream file;
    string line;
    string name;
    int score;

    file.open(scoreFile);

    while (getline(file, line)) {

        name = line.substr(0, 3);   //Cuts off name entries that go past the 3 letter initial entry
        score = stoi(line.substr(3));

        highScores[score] = name;
    }

    //TODO
    for (map<int, string>::iterator m = highScores.begin(); m != highScores.end(); m++) {
        cout << m->second << " " << m->first << endl;
    }

    file.close();
}

void GameHandler::setInitials(string& init) {
    initials = init;
}

string GameHandler::getInitials() {
    return initials;
}

void GameHandler::setWordArrayEasy(){
    for (int x = 0; x < 12; x++) {
        wordArray[x] = wordArrayEasy[x];
    }
}

void GameHandler::setWordArrayMedium(){
    for (int x = 0; x < 12; x++) {
        wordArray[x] = wordArrayMedium[x];
    }
}

void GameHandler::setWordArrayHard(){
    for (int x = 0; x < 12; x++) {
        wordArray[x] = wordArrayHard[x];
    }
}

string GameHandler::getOutcome() {
    return outcome;
}

int GameHandler::getIncorrectGuesses() {
    return lossCount;
}

GameHandler::GameHandler() {
    CreateVector();
    setCurrentScore(0);
}

GameHandler::~GameHandler() {

}
