//A simple multiplayer guessing game based on customizable objects

#include <iostream>
#include <string>
#include <stack>
#include <cstdlib>
#include <math.h>

using namespace std;

class obj   //custom object that is to be guessed by the players
{
public:
    int val;
};

class Player
{
    public:
    int score;
    string name;
    
    Player(string s)
    {
        score=0;
        name=s;
    }
    void disp_details();
};

void Player::disp_details()
{
    cout<<"\nPlayer Details:";
    cout<<"\nName=\t"<<name;
    cout<<"\nScore=\t"<<score<<endl;
}


int main()
{
    int seed,i,g1,g2,num,turns;

    cout<<"Enter seed value:";
    cin>>seed;
    srand(seed);
    
    string name1,name2;
    cout<<"\nEnter name of players:";
    cin>>name1>>name2;

    Player p1(name1),p2(name2);
    cout<<"\nEnter number of turns:";
    cin>>turns;

    obj K[turns],object;
    stack<obj> A;
    for(i=0;i<turns;i++)  //initialize the stack with custom objects
    {
        K[i].val=rand()%10+1; 
        A.push(K[i]);
    }

    cout<<"\n\nGame starting...";
    while(!A.empty()) //the main game loop
    {
        object=A.top();
        A.pop();
        cout<<"\n"<<p1.name<<" enter guess:";
        cin>>g1;  //input guess of Player 1
        cout<<"\n"<<p2.name<<" enter guess:";
        cin>>g2;  //input guess of Player 2

        if(abs(g1-object.val)<abs(g2-object.val))
            {cout<<"\n\t"<<p1.name<<" wins!"<<" value was "<<object.val; ++p1.score;}
        else if(abs(g1-object.val)>abs(g2-object.val))
            {cout<<"\n\t"<<p2.name<<" wins!"<<" value was "<<object.val; ++p2.score;}
        else
            cout<<"\n\tIt's a draw"<<" value was "<<object.val;;
    }

    cout<<"\n\n-----------------GAME OVER---------------";
    if(p1.score>p2.score) cout<<"\n"<<p1.name<<" wins!"<<endl;
    else if(p1.score>p2.score) cout<<"\n"<<p1.name<<" wins!"<<endl;
    else cout<<"\nMatch DRAW!!"<<endl;
    
    return 0;
}