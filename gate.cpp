#include "gate.h"

Gate :: Gate()
{
    input1 = NULL;
    input2 = NULL;
    output = NULL;
}

void Gate :: Set_input1(Node* Node_input1)
{
    input1 = Node_input1;
}
void Gate ::Set_input2(Node* Node_input2)
{
    input2 = Node_input2;
}
void Gate ::Set_output(Node* Node_output)
{
    output = Node_output;
}
Node* Gate ::Get_input1()
{
    return input1;
}
Node* Gate ::Get_input2()
{
    return input2;
}
Node* Gate ::Get_output()
{
    return output;
}

