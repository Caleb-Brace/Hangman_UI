/*
* Amanuel Fufa, Caleb Brace, Caleb McGraw
* CIS 227
* Week 7
*
* 1/27/21 - 3/8/21
*/

#pragma once
#include <map>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>


#define READFILE_H_

using namespace std;

class GameHandler {
private:

    //array that we grab from
    string wordArray[12];
    string wordArrayEasy[12] = {"fox", "cat", "dog", "ant", "rat", "bat", "frog", "toad", "bird", "lion", "hawk", "mice"};
    string wordArrayMedium[12] = { "lizard", "mouse", "moose", "goose", "dragon", "rhino", "hippo", "zebra", "jaguar", "cougar", "coyote", "tiger"};
    string wordArrayHard[12] = { "ceribillum", " antidisestablishmentarianism", "hypothalamus", "salmonella", "unimaginative", "uncopyrightable", "pneumonoultramicroscopicsilicovolcanoconiosis", "Llanfair­pwllgwyn­gyllgo­gery­chwyrn­drobwll­llanty­silio­gogo­goch", "stereotype", "puzzlingly", "handkerchief", "the"};

    //vector, populated from file later
    vector<string> wordsVector;

    //map of highscores
    map<int, string> highScores;

    //Score Values
    int correctGuessPoints = 100;
    int hintMinusPoints = -50;
    int incorrectGuessPoints = -10;
    int finishWordScore = 500;
    int currentScore;

    //Files
    string wordsFile = "Words.txt";
    string scoreFile = "Scores.txt";
    string outcome = "";
    string initials;

public:

    //initializers
    string display(bool, int&);
    void hide(bool, int&);
    bool ValidateMenuScope(int&);
    bool ValidateArrayScope(int&);
    void CreateVector();
    void clearBank();
    void clearScore();
    bool gameState();
    bool checkGuess(string&);
    void setWordArrayEasy();
    void setWordArrayMedium();
    void setWordArrayHard();
    void bankStore(bool, int&);
    char displayHint();
    void addToScore(int&);
    void setCurrentScore(int);
    int getCurrentScore();
    int getIncorrectGuesses();

    void setInitials(string&);
    string getInitials();

    void writeScoreToFile(string&, int&);
    void readScoreFile();
    string getOutcome();

    //Constructer used to make file into vector
    GameHandler();
    ~GameHandler();
};
