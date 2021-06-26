#include<iostream>
#include <cctype>
#include <cstring>
#include <cstdio>
using namespace std;

class Player{

std::string Name;
int Score;

public:
    Player(string name, int score){
        Name=name;
        Score=score;
        // Hint=hint;
        // Word=word;

    }
    
    void check_input(std::string input0, std::string hint,int n){
        system("CLS");
        
        int guess_count=5,j=0;
        std::string input;                                      
    
        char Word[n],word[n];

        for(int i=0; i<n;i++){
            Word[i]='_';
            word[i]=toupper(input0[i]);
    
        }


        while(guess_count!=0){
            system("CLS");
            cout<<endl<<Name<<"'s turn "<<endl;
            cout<<" Guesses left: "<<guess_count<<endl<<endl;
            cout<<" Hint for the given word: "<<hint<<endl<<endl;
            cout<<"Number of characters: "<<n<<endl<<endl<<" You've guessed: "<<endl;
            cout<<"\t";
            for(int i=0; i<n;i++){
        
                cout<<Word[i];
                cout<<"  ";

            }
            cout<<endl<<"Enter a character:  ";
            cin>>input;
            Word[j]=toupper(input[0]);
    
    
            if(Word[j]!=word[j]){
                guess_count--;
                Word[j]='_';
            }
            else if(Word[j]==word[j]){
                j++;
        
            }
            if(Word[n-1]==word[n-1]){
                break;
            }
    

        }
        system("CLS");
        if(guess_count==0){
            cout<<endl<<"\t\t GAME OVER \t\t";
            cout<<endl<<Name<<" you lost the round "<<endl<<"Your Score: "<<Score;
            cout<<endl<<"\t Word assigned to you: "<<input0;
        }
        else{
            cout<<endl<<"\t\t CONGRATULATIONS !"<<endl;
            
            Score=Score+guess_count;
            cout<<Name<<" You won the round "<<endl<<" Your score: "<<Score<<endl;
            
        }

    }

    void Result(){
        cout<<Name<<endl<<"FINAL SCORE: "<<Score<<endl<<endl;

    }




};



int main(){
    std::string player1,player2,hint1,hint2,word1,word2;
    int n,r;
  
    cout<<endl<<endl<<"Enter player1's Name: ";
    getline(cin,player1);

    cout<<"Enter player2's Name: ";
    getline(cin,player2);
    
    Player Player2=Player(player2,0);
     Player Player1=Player(player1,0);

    cout<<"Enter the number of Rounds you want to play: ";
    cin>>r;
    system("CLS");
    for(int i=0;i<r;i++){
        
        cout<<endl<<player1 <<endl;
        cout<<"Enter a word: ";
        cin>>word2;
        n=word2.length();
        cin.ignore();
        cout<<"Enter hint for given word: ";
        getline(cin,hint2);

        

        
        Player2.check_input(word2,hint2,n);
        cout<<endl<<endl;

        cout<<endl<<player2 <<endl;
        cout<<"Enter a word: "<<endl;
        cin>>word1;
        n=word1.length();
        cin.ignore();
        cout<<"Enter hint for given word "<<endl;
        getline(cin,hint1);

        
        Player1.check_input(word1,hint1,n);
    

    }

    cout<<endl<<endl<<endl<<"\t\t FINAL RESULT"<<endl;
    Player1.Result();
    Player2.Result();
    
return 0;
}