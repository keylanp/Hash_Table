//Keylan Petty, CS163, Assignment3
//
//This is my implementation file for my topictable class - my class for my second
//hash table - organized by topic

#include "hash.h"

//Class constructor
topictable::topictable()
{
    hash_table_size = MAX; 
    hash_table = new node * [hash_table_size];
    
    for(int i = 0; i < hash_table_size; ++i)
    {
        hash_table[i] = nullptr;
    }
}

//Class destructor
topictable::~topictable()
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
int topictable::destroy(node *& head)
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
int topictable::hash_function(char * key) const
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

//This is my insert function. I intake a character array pointers and set each
//term in the info stored in the character array
int topictable::insert(char * key, char names[], char topics[], char def[])
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

//This is my retrieve function. It should return 1 if the topic is found and 0
//if it is not.
int topictable::retrieve(char * key, terminology & found) const
{
   int temp = hash_function(key);

   if(!hash_table[temp])
       return 0;

   node * current = hash_table[temp];

   while(current)
   {
        if(current->info->retrieve_topic(key, found))
            return 1;
        current = current->next;
   }
    return 0;
}

//This is my function for finding and displaying by topic. Should return 1 if the topic is found
//and displayed. Will return 0 if not found.
int topictable::displaytopic(char * tofind)
{
    int temp = hash_function(tofind);

    if(!hash_table[temp])
        return 0;
    
    node * current = hash_table[temp];

    while(current)
    {
        if(current->info && current->info->compare_topic(tofind))
        {
            current->info->display();
        }
        current = current->next;
    }
    return 0;
}

int topictable::display_all() 
{
    for(int i = 0; i<MAX;++i)
    {
        display(hash_table[i]);
    }
    return 1;
}

int topictable::display(node * head)
{
    if(!head) return 1;

    if(head->info)
        head->info->display(); 
    return display(head->next);
}
