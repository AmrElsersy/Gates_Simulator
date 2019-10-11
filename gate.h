#ifndef GATE_H
#define GATE_H
#include "node.h"

class Gate
{
protected:

    Node* input1;
    Node* input2;
    Node* output;

public:

    // constructor
    Gate();
    void Set_input1(Node* Node_input1);
    void Set_input2(Node* Node_input2);
    void Set_output(Node* Node_output);
    Node* Get_input1();
    Node* Get_input2();
    Node* Get_output();
    // Abstract Class : Which must have inher inheritance
    // = 0 mean that this function dosn't have implmentation
    // and which class will inherite should have implmentation of Logic_Calc Function
    virtual void Logic_Calc() = 0;

};
#endif // GATE_H
