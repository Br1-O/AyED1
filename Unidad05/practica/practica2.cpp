#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■(2)■■■■■■■■■■■■■■■■■■■■■■■■■■■■//

//create vector of words from phrase
vector<string> splitWordsIntoArray(string phrase);

//count letter of a word
int countLetters(string word);

//display letters of words with
void countLettersAndDisplayIt(string phrase);


//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■(MAIN)■■■■■■■■■■■■■■■■■■■■■■■■■■■■//

int main(int argc, char const *argv[])
{
    cout << "Ingrese una frase para contabilizar las letras de cada una de sus palabras: " << endl << endl;

    string userInput;

    getline(cin, userInput);

    countLettersAndDisplayIt(userInput);
    
    return 0;
}

//create vector of words from phrase
vector<string> splitWordsIntoArray(string phrase){

    vector<string> arrayOfWordsFromPhrase;

    string currentWord;

    for (size_t i = 0; i < phrase.size(); i++)
    {
        if (phrase[i] != '.' && phrase[i] != ',' && phrase[i] != '(' && phrase[i] != ')' && phrase[i] != '"' && phrase[i] != '!' && phrase[i] != '?')
        {
            if (( phrase[i] == ' '))
            {
                arrayOfWordsFromPhrase.push_back(currentWord);
                currentWord = "";
            }else
            {
                currentWord+= phrase[i];
            }
        }
    }

    //for the last word
    if (!currentWord.empty()){
        arrayOfWordsFromPhrase.push_back(currentWord);
        currentWord = "";
    }

    return arrayOfWordsFromPhrase;   
};

//count letter of a word
int countLetters(string word){

    int counterLetters = 0;

    for (size_t i = 0; i < word.size(); i++)
    {
        counterLetters++;
    }

    return counterLetters;
};

//display letters of words with
void countLettersAndDisplayIt(string phrase){

    vector<string> words = splitWordsIntoArray(phrase);

    for (size_t i = 0; i < words.size(); i++)
    {
        cout << "> Palabra: " << words[i] << " | > Numero de palabras: " << countLetters(words[i]) << endl;
    }
};