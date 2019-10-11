#include "node.h"

void Node :: Set_Name(string Node_Name)
{
    Name = Node_Name;
}
void  Node :: Set_Value(int Node_Value)
{
    Value = Node_Value;
}
string  Node :: Get_Name()
{
    return Name;
}
int  Node :: Get_Value()
{
    return Value;
}
