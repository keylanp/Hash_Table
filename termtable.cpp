//Keylan Petty, CS163, Assignment3
//
//This is my implementation file for my termtable class. It includes
//all the public member functions for my class.

#include "hash.h"


//Class constructor
termtable::termtable()
{
    hash_table_size = MAX; 
    hash_table = new node * [hash_table_size];
    
    for(int i = 0; i < hash_table_size; ++i)
    {
        hash_table[i] = nullptr;
    }
}

//Class destructor
termtable::~termtable()
{
    for(int i = 0; i < hash_table_size; ++i)
    {
        if(hash_table[i])
        {
            destroy(hash_table[i]);
            hash_table[i] = nullptr; 
        }
    }
    delete [] hash_table;
}

//This is the recursive function for my destructor, iterated through existing
//nodes and deletes memory
int termtable::destroy(node *& head)
{
    if(!head)
        return 1;
    node * temp = head;
    head = head->next;
    if(temp->info)
        delete temp->info;
    delete temp;

    return destroy(head);
}

//This is my hash function. It takes in a character array pointer and converts
//each character within it to an ASCII value. It then mods this number to fit in my
//array. Will return the moded value if successful, and a negative number if not.
int termtable::hash_function(char * key)
{
    int temporary = strlen(key);
    int temp = 0;

    for(int i = 0; i < temporary; ++i)
    {
        temp += key[i];
    }
    
    temp = temp % hash_table_size;

    return temp;
}

//This is my insert function. I intake a character array pointer, pass it through my FIXME::
int termtable::insert(char * key, char names[], char topics[], char def[])
{
    int data = hash_function(key);

    if(!hash_table[data])
    {
        hash_table[data] = new node;
        hash_table[data]->info = new terminology;
        hash_table[data]->info->set(names, topics, def);
        hash_table[data]->next = nullptr;
        return 1;
    }
    node * temp = hash_table[data];

    hash_table[data] = new node;
    hash_table[data]->info = new terminology;
    hash_table[data]->info->set(names, topics, def);
    hash_table[data]->next = temp;

    return 1;
}

//This is my retrieve function. It should return 1 if the term is found and 0
//if it is not.
int termtable::retrieve(char * key, terminology & found) 
{
   int temp = hash_function(key);

   if(!hash_table[temp])
       return 0;

   node * current = hash_table[temp];

   while(current)
   {
        if(current->info->retrieve_term(key, found))
            return 1;
        current = current->next;
   }
    return 0;
}

//Uses the hash function to find the array index, then goes through nodes 
int termtable::remove(char * key)
{
    int temp = hash_function(key);
    
    if(remove(hash_table[temp],key))
        return 1;
    return 0;

}

int termtable::remove(node *& head, char * key)
{
    if(!head) return 0;
    if(head->info && head->info->compare_term(key))
    {
        node * temp = head; 
        head = head->next; 
        delete temp->info; 
        delete temp; 
        return remove(head,key)+1;
    }

    return remove(head->next,key);
}

//This is my function for finding and displaying by term. Should return 1 if the term is found
//and displayed. Will return 0 if not found.
int termtable::displayterm(char * tofind)
{
    int temp = hash_function(tofind);

    if(!hash_table[temp])
        return 0;
    
    node * current = hash_table[temp];

    while(current)
    {
        if(current->info->compare_term(tofind))
        {
            current->info->display();
            return 1;
        }
        current = current->next;
    }
    return 0;
}

//This is my display function. Returns 1 when finished/successful
int termtable::display_all() 
{
    for(int i = 0; i<MAX; ++i)
    {
        display(hash_table[i]);
    }
    return 1;
}

int termtable::display(node * head)
{
    if(!head) return 1;

    if(head->info)
        head->info->display(); 
    return display(head->next);
}
