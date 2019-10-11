#ifndef NODE_H
#define NODE_H

#include "string"
using namespace std;

class Node
{
private:
    string Name;
    int Value;
public:
    void Set_Name(string Node_Name);
    void Set_Value(int Node_Value);
    string Get_Name();
    int Get_Value();
};
#endif // NODE_H
