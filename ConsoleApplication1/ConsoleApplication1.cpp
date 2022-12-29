// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
class linked
{
    struct node
    {
        int item;
        node* next;
    };
    node* head;
    node* last;
    int length;
public:
    linked()
    {
        head = last = NULL;
        length = 0;
    }
    bool isEmpty()
    {
        return head == NULL;
    }
    void insertFirst(int element)
    {
        node* newnode = new node;
        newnode->item = element;
        if (isEmpty())
        {
            head = last = newnode;
            newnode->next = NULL;
        }
        else
        {
            newnode->next = head;
            head = newnode;
        }
        length++;
    }
    
    void insertLast(int element)
    {
        node* newnode = new node;
        newnode->item = element;
        if (isEmpty())
        {
            head = last = newnode;
            newnode->next = NULL;
        }
        else
        {
            last->next = newnode;
            newnode->next = NULL;
            last = newnode;
        }
        length++;
    }
   
    void insertAtPos(int pos, int element)
    {
        node* newnode = new node;
        newnode->item = element;
        if (pos<0 || pos>length)
        {
            cout << "out of range" << endl;
        }
        else if (pos == 0)
        {
            insertFirst(element);
        }
        else if (pos == length)
        {
            insertLast(element);
        }
        else
        {
            node* cur = head;
            for (int i = 1; i < pos; i++)
            {
                cur = cur->next;
            }
            newnode->next = cur->next;
            cur->next = newnode;
            length++;
        }

    }
   
    void display()
    {
        if (isEmpty())
        {
            cout << "List is Empty" << endl;
        }
        else
        {
            node* cur = head;
            while (cur != NULL)
            {
                cout << cur->item << " ";
                cur = cur->next;
            }

        }
    }
   
    int counter()
    {
        return length;
    }
   
    void deleteFirst()
    {
        node* cur = head;
        if (isEmpty())
        {
            cout << "List in Null" << endl;
        }
        else if (length == 1)
        {
            delete head;
            head = last = NULL;
            length--;
        }
        else
        {
            head = head->next;
            delete cur;
            length--;
        }
    }
   
    void deleteLasat()
    {
        if (isEmpty())
        {
            cout << "List in Null" << endl;
        }
        else if (length == 1)
        {
            delete last;
            head = last = NULL;
            length--;
        }
        else
        {
            node* curr = head->next;
            node* priv = head;
            while (curr != last)
            {
                priv = curr;
                curr = curr->next;
            }
            delete curr;
            priv->next = NULL;
            last = priv;
            length--;
        }
    }
  
    void deletePos(int pos)
    {
        if (pos<0 || pos>length)
        {
            cout << "Error" << endl;
        }
        else if (pos == 0)
        {
            deleteFirst();
        }
        else if (pos == length)
        {
            deleteLasat();
        }
        else
        {
            node* cur = head->next;
            node* prev = head;
            for (int i = 1; i < pos; i++)
            {
                prev = cur;
                cur = cur->next;
            }
            prev->next = cur->next;
            delete cur;
            length--;


        }
    }
    
    int getFirst()
    {
        return head->item;
    }
    
    int getLast()
    {
        return last->item;
    }
    
    void reArange()
    {
        int el1, el2;
        node* cur, * prevcur;
        if (isEmpty())
            cout << "Stack is Empty" << endl;
        else if (length == 1)
        {
            cout << "the list has one element please add more element ";
            display();
        }
        else
        {
            for (cur = head; cur->next != NULL; cur = cur->next)
            {
                for (prevcur = cur->next; prevcur != NULL; prevcur = prevcur->next)
                {
                    if (cur->item > prevcur->item)
                    {
                        el1 = cur->item;
                        cur->item = prevcur->item;
                        prevcur->item = el1;
                    }
                }

            }
        }
    }
};
int main()
{
    linked l;
    l.insertFirst(50);
    l.insertLast(40);
    cout << l.counter() << endl;
    l.insertAtPos(1, 30);
    l.insertFirst(0);
    l.deleteFirst();
    l.deleteLasat();
    l.deletePos(1);

    l.display();
    cout << "\n the first =" << l.getFirst() << "\n the last= " << l.getLast() << endl;
    // cout<<endl<<"the sort= ";
    l.reArange();
    l.display();
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
