#include <iostream>
#include "Node.h"
#include "LinkedList.h"
#include <sstream>
#include <vector>
using namespace std;

int main()
{
    string input = ""; int inputs[100];
    getline(cin, input);

    vector<string>result;
    istringstream iss(input);
    for (string s; iss >> s;)
    {
        result.push_back(s);
    }
    int n = 0;
    for(int i = 0; i<result.size(); i++)
    {
        if(isdigit(result.at(i)[0]))
        {
            inputs[i] = stoi(result.at(i));
            n++;
        } else break;
    }

    LinkedList * list = new LinkedList(inputs, n);
    //list->printItems();
    for(int i = 0; i<result.size(); i++)
    {
        if(result.at(i) == "AF")
        {
            list->addFront(stoi(result.at(i+1)));
        }else if(result.at(i) == "AE")
        {
            list->addEnd(stoi(result.at(i+1)));
        }
        else if(result.at(i) == "AP")
        {
            list->addAtPosition(stoi(result.at(i+1)), stoi(result.at(i+2)));
        }
        else if(result.at(i) == "S")
        {
            list->search(stoi(result.at(i+1)));
        }
        else if(result.at(i) == "DF")
        {
            list->deleteFront();
        }
        else if(result.at(i) == "DE")
        {
            list->deleteEnd();
        }
        else if(result.at(i) == "DP")
        {
            list->deletePosition(stoi(result.at(i+1)));
        }
        else if(result.at(i) == "GI")
        {
            list->getItem(stoi(result.at(i+1)));
        }
    }
    list->printItems();
    cout<<endl;
    return 0;
}