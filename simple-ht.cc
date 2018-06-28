//simple hash table using an array of linked lists
#include <iostream>
#include <iomanip>
#include <functional>
#include <string>
#include <unordered_set>

//node structure for linked list
struct node
{
    std::string data;
    node *next;
};

//class to manipulate ll
class list
{
    public:
        list();
        //append node at end of list
        void add_node (std::string);
  
        //print ll
        void print (void);

        //print if given value is in list
        void isFound (std::string);

    private:
        node *head, *tail;
};

list::list ()
{
    head = NULL;
    tail = NULL;
}

//append node at end
void 
list::add_node (std::string data)
{
    node *tmp = new node;
    tmp->data = data;
    tmp->next = NULL;

    if (head == NULL)
    {
        head = tmp;
        tail = tmp;
    }
    else
    {
        tail->next = tmp;
        tail = tail->next;
    }
}

//print ll
void
list::print(void)
{
    if (head==NULL)
    {
        std::cout << "\n empty "<<std::endl;
    }
    else
    {
        node *tmp = head;
        while (tmp != NULL)
        {
            std::cout << "\n key = " << tmp->data << std::endl;
            tmp = tmp->next;
        }
    }
}

//print if given value is found in ll
void
list::isFound (std::string str)
{ 
    if (head==NULL)
    {
        std::cout << "\n does not exist " << std::endl;
        return;
    }
    else
    {
        node *tmp = head;
        while (tmp != NULL)
        {
            if (tmp->data == str)
            {
                std::cout << "\n found value = " << tmp->data << std::endl;
                return;
            }
            tmp = tmp->next;
        }
    }
}

//return location of key in hash table
long
GetIndex (std::string key, long arraySize)
{
    std::size_t str_hash = std::hash<std::string>{}(key);
    
    return str_hash % arraySize;
}

int main ()
{
    //size of hash table
    list *a = NULL;
    long a_size = 0;

    std::cout <<"\n enter table size " << std::endl;
    std::cin >> a_size;

    a = new list [a_size]; 

    //init table with empty nodes
    for (long i = 0; i < a_size; i++)
    {
        list htl;
        a[i] = htl;
    }

    //number of enteries to store

    long n_enteries = 0;
    std::cout << "\n enter number of enteries " << std::endl;
    std::cin >> n_enteries;

    std::cout << "\n input keys " << std::endl;

    std::cin.ignore();
    std::cin.clear();
    
    //store enteries from user
    for (long i = 0 ; i < n_enteries; i++)
    {
        std::string str;
        getline(std::cin, str);

        long index = GetIndex (str, a_size);
        std::cout << "\n index " << index << std::endl;
        a[index].add_node(str);
    }


    //print hash table
    std::cout << "\n printing " << std::endl;

    for (long i = 0; i < a_size ; i++)
    {
        std::cout << "\n index value " << i << std::endl;
        a[i].print();
    }

    //enter value to find in list
    std::cout << "\n enter value to find " << std::endl;

    for (long i = 0; i < a_size ; i++)
    {
        std::string strf = "";
        getline (std::cin, strf);
        long index = GetIndex (strf, a_size);
        std::cout << "\n this value should be at index value " << index << std::endl;
        a[index].isFound(strf);
    }
    
    return 0;
}
