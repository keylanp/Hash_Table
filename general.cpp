//Keylan Petty, CS163, Assignment3
//
//This is my general file. It has all the function prototypes listed in main.

#include "hash.h"

//This is my function for readign in from an input file
void caseA(char term[100], char topic[100], char definition[200], termtable & trm, topictable & tpc)
{
    char temp[50];
    char * temp2;
    ifstream inFile;

    cout << "Please enter the name of the input file you would like to use" << endl;

    cin.get(temp, 100, '\n');
    
    inFile.open(temp);
    if(!inFile)
    {
        cout << "File did not open, returning to main menu." << endl;
        return;
    }
    
    
    //Priming input file
    inFile.getline(term, 100, '|');
   
    while(!inFile.eof())
    {
        inFile.ignore(100, ' ');
        if(strlen(term))
                term[strlen(term)-1] = '\0';

        inFile.getline(topic, 100, '|');
        inFile.ignore(100, ' ');
        if(strlen(topic))
            topic[strlen(topic)-1] = '\0';
       
        inFile.getline(definition, 200, '\n');
        
        temp2 = new char[strlen(term)+1];
        strcpy(temp2, term);
        trm.insert(temp2, term, topic, definition);
        delete [] temp2;

        temp2 = new char[strlen(topic)+1];
        strcpy(temp2, topic);
        tpc.insert(temp2, term, topic, definition);
        delete [] temp2;

        inFile.getline(term, 100, '|');
    }

    inFile.close();
    cout << "File is now stored in both hash tables" << endl;

    return;
}

void caseB(char term[], char topic[], char definition[], termtable & trm, topictable & tpc)
{
   cout << "\nWhat is the term(name)?: ";

   cin.getline(term, 100, '\n');

   cout << "\nWhat is the topic it relates to?: ";
    
   cin.getline(topic, 100, '\n');

   cout << "\nWhat is the definition?: ";

    cin.getline(definition,200, '\n');

    char * temp = new char[strlen(term)+1];

    strcpy(temp, term);
    trm.insert(temp, term, topic, definition);
    delete [] temp;

    temp = new char[strlen(topic)+1];
    strcpy(temp, topic);
    tpc.insert(temp, term, topic, definition);
    
    delete [] temp;
    temp = nullptr;

    cout << "This term has been added to both hash tables\n" << endl;

    return;
}

void caseC(char term[], termtable & trm)
{
    cout << "\nWhat term would you like to display?: ";
    cin.getline(term, 100, '\n');
    
    char * temp = new char[strlen(term)+1];
    strcpy(temp, term);
    if(trm.displayterm(temp))
        cout << "Returning to main menu\n" << endl;
    else
        cout << "This term does not exist!" << endl;

    delete [] temp;

    return;

}

void caseD(char term[], termtable & trm)
{
    cout << "\nWhat term would you like to remove?: ";
    cin.getline(term, 100,'\n');

    char * temp = new char[strlen(term)+1];
    strcpy(temp, term);

    if(trm.remove(temp))
        cout << "\nFound and removed, returning to main" << endl;
    else
        cout << "could not find this term, returning to main" << endl;
    delete [] temp;
    return;
}

void caseE(char topic[], topictable & tpc)
{
    cout << "\nWhat topic would you like to display?: " << endl;
    cin.getline(topic, 100, '\n');

    char * temp = new char[strlen(topic)+1];
    strcpy(temp, topic);

    if(tpc.displaytopic(temp))
        cout << "\nReturning to main" << endl;
    else
        cout << "Could not find. Returning to main." << endl;
   
    if(temp)
        delete [] temp;
    return;

}

void caseF(termtable & trm, topictable & tpc)
{
    trm.display_all();
    tpc.display_all();

    return;
}
