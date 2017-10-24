//C++ Implementation of Finite State Machine using  Deterministic Finite Automata (DFA)
//The state diagram for the DFA is implemented as boolean function containing goto statements to determine the states
//Author: Shreyak Chakraborty (C) 2017


#include <iostream>

using namespace std;


bool fsm1(string a)     //accepts any string starting with 'ab'
{
    int i=0,state;
    cout<<"\nStates: ";

    INITIAL: state=0; cout<<state;
             if(a[i]=='a') {goto Q1;}
             if(a[i]=='b') {return false;}  //reject string
             return false;

    Q1: i+=1; state=1; cout<<state;
        if(a[i]=='a') {return false;}
        if(a[i]=='b') {goto Q2;}

    Q2:i+=1; state=2; cout<<state;
       if(a[i]=='a') {goto Q2;}
       if(a[i]=='b') {goto Q2;}

       if(state==2) return true;   //accept string
       else return false;

}


bool fsm2(string a)      //accepts any string of form a^n.b^m where n,m >= 1
{
    int i=0,state;
    cout<<"\nStates: ";

    INITIAL: state=0; cout<<state;
             if(a[i]=='a') {goto Q1;}
             if(a[i]=='b') {return false;}  //reject string
             return false;

    Q1:i+=1; state=1; cout<<state;
       if(a[i]=='a') {goto Q1;}
       if(a[i]=='b') {goto Q2;}
       return false;

    Q2:i+=1; state=2; cout<<state;
       if(a[i]=='a') {return false;}
       if(a[i]=='b') {goto Q2;}

       if(state==2) return true;   //accept string
       else return false;

}



//--------------------------------------MAIN FUNCTION---------------------------------------------------------
int main()
{
    string s; //the input string for the Machine

    cout<<"Alphabets for the FSM: {a,b}";
START:
    cout<<"\n\nEnter new input string for the FSM:";
    cin>>s;

    if(fsm1(s))
        cout<<"\nString is accepted!";
    else
        cout<<"\nString is rejected!";

    goto START;

}
