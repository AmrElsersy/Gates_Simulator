#ifndef SIMULATOR_H
#define SIMULATOR_H
#include <QString>
#include "string"

#include "dynamicarray.h"
#include "gates_types.h"

#include <iostream>
#include <fstream>
using namespace  std;

class Simulator
{
private:
    // we can't declare the size in definition in class
    // so we will make an added array then add it to the original array
    DynamicArray<Gate*> Gates;
    DynamicArray<Node> Nodes;
    QString path;
public:
    Simulator(QString);
    // add name to array of string(names) if not found in it && if it found will do nothing
    void Add_if_not_found(string name, DynamicArray<string>& names);
    void Calc_Gates_Nodes(int& GateNum, int& NodeNum, DynamicArray<string>& nodes_names);
    // calculate the output Nodes from the calc_Logic functions of gates
    void Simulate();

    // search the Nodes array by name of node and return a pointer to it
    Node* Find_Node(string name);
    void Print_ALL();
    void Print_Node(string name);

    // Load Data from the file and pass it to all other functions
    void Conect_Gates_Nodes();


};


#endif // SIMULATOR_H
