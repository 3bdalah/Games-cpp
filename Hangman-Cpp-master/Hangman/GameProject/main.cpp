#include <bits/stdc++.h>
#include <cstdlib>
#include<ctime>
#include <string>
using namespace std;

const int MAX_TRIES = 5;
int letterFill (char, string, string&);

int main()
{
    string name;
    char letter;
    int num_of_wrong_guesses =0;
    string word;
    string words[]={
        "india",
        "pakistan",
        "nepal",
        "malaysia",
        "philippines",
        "australia",
        "iran",
        "ethiopia",
        "oman",
        "indonesia"
    };
    // choose and copy a word from array of words randomly 
    srand(time(NULL));
    int n = rand()% 10;
    word= words[n];
    
    //  initalize the secret word with the * character.
    string unknown(word.length(),'*');
    // welcome the user 
    cout<<"\n\nwelcome to hangman... Guess a country Name";
    cout<<"\n\nEach letter is represented by a star , ";
    cout<<"\n\nYou have to type only one letter in onr try";
    cout<<"\n\nYou have"<<MAX_TRIES<<" tries to try and guess ";
    cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    // loop until the guesses are used up 
    while(num_of_wrong_guesses<MAX_TRIES){
        cout<<"\n\n"<<unknown;
        cout<<"\n\nGuess a letter : ";
        cin>>letter; 
        // Fill secret word with letter if the guess is correct ,
        // otherwise increement the number of wrong guesses.
        if(letterFill(letter,word,unknown) == 0){
            cout<<endl<<"Whoops! that letter isn`t in there! "<<endl;
            num_of_wrong_guesses++;
        }else{
            cout<<endl<<"You found a letter! Isn`t that exciting!"<<endl;
        }
        // tell user how many guesses has left.
        cout <<"You have "<<MAX_TRIES - num_of_wrong_guesses;
        cout<<"Guesses left ."<<endl;
        // check if user guessef the word.
        if(word == unknown){
            cout<<word<< endl;
            cout<<"Yeah! You Got It! ";
            break;
        }
    }
    if(num_of_wrong_guesses == MAX_TRIES){
        cout<<"\nSorry, You los... You have been haged."<<endl;
        cout<<'the word was : '<< word << endl;
    }
    cin.ignore();
    cin.get();
    return 0;
}

int letterFill(char guess,string secretword , string &guessword){
    int i;
    int matches=0;
    int len=secretword.length();
    for(i =0;i<len;i++){
        // did we already match this letter in a previous guess ? 
        if(guess == guessword[i]){
            return 0;
        }
        // is the guess in the secret word ?
        if(guess == secretword[i]){
            guessword[i] = guess;
            matches++;
        }
    }
    return matches;
}