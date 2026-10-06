#include <iostream>
using namespace std;
struct Node
{
    string coach;
    Node *next;
};
Node *last = NULL;
void addBeginning(string name)
{
    Node *newNode = new Node;
    newNode->coach = name;

    if (last == NULL)
    {
        last = newNode;
        newNode->next = last;
    }
    else
    {
        newNode->next = last->next;
        last->next = newNode;
    }
}
void addEnd(string name)
{
    Node *newNode = new Node;
    newNode->coach = name;

    if (last == NULL)
    {
        last = newNode;
        newNode->next = last;
    }
    else
    {
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }
}
void removeCoach(string name)
{
    if (last == NULL)
    {
        cout << "List is empty\n";
        return;
    }
    Node *temp = last->next;
    Node *prev = last;
    do
    {
        if (temp->coach == name)
        {
            if (temp == last && temp->next == last)
            {
                last = NULL;
            }
            else
            {
                prev->next = temp->next;
                if (temp == last)
                    last = prev;
            }
            delete temp;
            cout << "Coach removed\n";
            return;
        }
        prev = temp;
        temp = temp->next;
    } while (temp != last->next);
    cout << "Coach not found\n";
}
void display()
{
    if (last == NULL)
    {
        cout << "List is empty\n";
        return;
    }
    Node *temp = last->next;
    do
    {
        cout << temp->coach << " -> ";
        temp = temp->next;
    } while (temp != last->next);

    cout << "NULL\n";
}
int main()
{
    addEnd("Coach 1");
    addEnd("Coach 2");
    addEnd("Coach 3");
    addEnd("Coach 4");
    cout << "Original coaches:\n";
    display();
    addBeginning("New Coach");
    cout << "\nAfter adding at beginning:\n";
    display();
    addEnd("Coach 5");
    cout << "\nAfter adding at end:\n";
    display();
    removeCoach("Coach 2");
    cout << "\nAfter removing Coach 2:\n";
    display();
    return 0;
}
