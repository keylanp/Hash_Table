//Keylan Petty, CS163, Assignment3
//
//This is my header file for my classes and structs

#include <fstream>
#include <cstring>
#include <cctype>
#include <iostream>

using namespace std;

class terminology
{
    public:
        terminology();
        ~terminology();
        int set(char names[], char topics[], char def[]);
        int retrieve_term(char * key, terminology & found) const;
        int retrieve_topic(char * key, terminology & found) const;
        int compare_term(char * key);
        int compare_topic(char * key);
        int display() const;
    private:
        char * name;
        char * topic;
        char * definition;
};

struct node
{
    terminology * info;
    node * next;
};

//table size
const int MAX = 13;

class termtable 
{
    public:
        termtable();
        ~termtable();
        int hash_function(char * key);
        int insert(char * key, char names[], char topics[], char def[]);
        int retrieve(char * tofind, terminology & found);
        int remove(char * toremove);
        int displayterm(char * tofind);
        int display_all();
    private:
        int destroy(node *& head);
        int display(node *);
        int remove(node *&, char *);
        node ** hash_table;    //a dynamically allocated array of head pointers
        int hash_table_size;
};

class topictable
{
    public:
        topictable();
        ~topictable();
        int hash_function(char * key)const;
        int insert(char * key, char names[], char topics[], char def[]);
        int retrieve(char * key, terminology & found) const;
        int displaytopic(char * tofind); 
        int display_all();
    private:
        int destroy(node *& head);
        int display(node *);
        node ** hash_table;
        int hash_table_size;

};

void caseA(char term[], char topic[], char definition[], termtable & trm, topictable & tpc);
void caseB(char term[], char topic[], char definition[], termtable & trm, topictable & tpc);
void caseC(char term[], termtable & trm);
void caseD(char term[], termtable & trm);
void caseE(char topic[], topictable & tpc);
void caseF(termtable & trm, topictable & tpc);
