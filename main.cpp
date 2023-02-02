//Keylan Petty, CS163, Assingment3
//
//This is my main implentation file. It has a switch function for all user options
//and takes in all the data from my .o file

#include "hash.h"

int main() 
{ 
    char userchoice = 'A';
    char term[100];
    char topic[100];
    char definition[200];
   
    termtable trm;
    topictable tpc;

    cout << "Welcome to my hash table program!" << endl;

    while(userchoice != 'Q')
    {
        cout << "Please select and option below!\n" << endl;

        cout << "A: Read from input file" << endl;
        cout << "B: Manually insert term, topic, and definition" << endl;
        cout << "C: Display by term name" << endl;
        cout << "D: Remove by term name" << endl;
        cout << "E: Display all of a certain topic" << endl;
        cout << "F: Display all of everything!" << endl;
        cout << "Q: Quit program" << endl; 
        cout << "What would you like to do?" << endl;

        cin >> userchoice;
        cin.ignore(100,'\n');
        cin.clear();
        userchoice = toupper(userchoice);

        switch(userchoice)
        {
            case 'A': caseA(term, topic, definition, trm, tpc);
                      break;
            case 'B': caseB(term, topic, definition, trm, tpc);
                      break;
            case 'C': caseC(term, trm);
                      break;
            case 'D': caseD(term, trm);
                      break;
            case 'E': caseE(topic, tpc);
                      break;
            case 'F': caseF(trm, tpc);
                      break;
            case 'Q': break;
            default: break;
        }
    }


    return 0;
}

