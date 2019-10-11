#include "simulator.h"

Simulator:: Simulator(QString path_gates)
{
    this->path = path_gates;

    int Gates_Num = 0;
    int Nodes_Num = 0;
    DynamicArray<string> names;

    Calc_Gates_Nodes(Gates_Num, Nodes_Num, names);
    // create the Dynamic array of Gates of the Num we calculate in main function
    DynamicArray<Gate*> added_Gates(Gates_Num);
    // make an added array then add it to the original array
    Gates += added_Gates;

    // create the Dynamic array of Nodes of the Num we calculate in main function
    DynamicArray<Node> added_Nodes(Nodes_Num);
    // make an added array then add it to the original array
    Nodes += added_Nodes;
    // Set the Name of Nodes
    for (int i = 0; i < Nodes_Num; i++)
    {
//        cout << names[i] << endl;
        Nodes[i].Set_Name(names[i]);
    }

}
// functions related to constructor
// calculate the Num of Gates and Nodes and a string of Names of Nodes

// add name to array of string(names) if not found in it && if it found will do nothing
void Simulator::  Add_if_not_found(string name, DynamicArray<string>& names)
{
    int found = 0;
    for (int i = 0, n = names.size(); i < n; i++)
    {
        if (names[i] == name)
        {
            found = 1;
            break;
        }
    }
    if (found == 0)
    {
        names.Add_Last(name);
    }
}
void Simulator::  Calc_Gates_Nodes(int& GateNum, int& NodeNum, DynamicArray<string>& nodes_names)
{
    // storing each line in string and split it
    string first_word;
    ifstream file(this->path.toStdString());
    // check if the file can't open
    if (!file.is_open())
    {
        cout << "file can't open";
        exit(1);
    }

    while (file >> first_word)
    {
        if (first_word == "SET")
        {
            break;
        }

        GateNum++;
        if (first_word == "NOT")
        {
            string in1;
            string out;

            file >> in1 >> out;

            Add_if_not_found(in1, nodes_names);
            Add_if_not_found(out, nodes_names);

            continue;
        }
        // .......................................................................

        string in1;
        string in2;
        string out;

        file >> in1 >> in2 >> out;


        Add_if_not_found(in1, nodes_names);
        Add_if_not_found(in2, nodes_names);
        Add_if_not_found(out, nodes_names);


    }
    NodeNum = nodes_names.size();
    file.close();
}

// calculate the output Nodes from the calc_Logic functions of gates
void Simulator::  Simulate()
{
    // time consuming is n2 (it is a little bad)
    // but we do that to Let the user Write the Gates with out sorting
    // As we repeat that prosses to make sure that all thing is calculated
    for (int i = 0, n = Gates.size(); i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            Gates[j]->Logic_Calc();
        }
    }
}
// search the Nodes array by name of node and return a pointer to it
Node*  Simulator:: Find_Node(string name)
{
    Node* pointer = NULL;
    for (int i = 0, n = Nodes.size(); i < n; i++)
    {
        if (name == Nodes[i].Get_Name())
        {
            pointer = &Nodes[i];
            return pointer;
        }
    }

    return pointer;
}
void  Simulator:: Print_ALL()
{
    for (int i = 0, n = Nodes.size(); i < n; i++)
    {
        cout << Nodes[i].Get_Name() << " = " << Nodes[i].Get_Value() << "\n";
    }
}
void  Simulator:: Print_Node(string name)
{
    Node* pointer = Find_Node(name);
    cout << pointer->Get_Name() << " = " << pointer->Get_Value() << "\n";
}

// Load Data from the file and pass it to all other functions
void Simulator::  Conect_Gates_Nodes()
{

    // conect the nodes to gates
    ifstream file(this->path.toStdString());

    // check if the file can't open
    if (!file.is_open())
    {
        cout << "file can'ttttttt open";
        exit(1);
    }

    string first_word;
    int pos_Gate = 0;
    while (file >> first_word)
    {
        if (first_word == "SET")
        {
            string name;
            int value;
            file >> name >> value;
            Node* ptr_node = Find_Node(name);
            ptr_node->Set_Value(value);
            continue;
        }
        else if (first_word == "SIM")
        {
            Simulate();
            continue;
        }
        else if (first_word == "OUT")
        {
            string printed_node;
            file >> printed_node;
            if (printed_node == "ALL")
            {
                Print_ALL();
            }
            else
            {
                Print_Node(printed_node);
            }
            continue;
        }
        else if (first_word == "AND")
        {
            Gates[pos_Gate] = new AND();
        }
        else if (first_word == "OR")
        {
            Gates[pos_Gate] = new OR();
        }
        else if (first_word == "NOT")
        {
            Gates[pos_Gate] = new NOT();
        }
        else if (first_word == "XOR")
        {
            Gates[pos_Gate] = new XOR();
        }
        else if (first_word == "XNOR")
        {
            Gates[pos_Gate] = new XNOR();
        }
        else if (first_word == "NAND")
        {
            Gates[pos_Gate] = new NAND();
        }
        else if (first_word == "NOR")
        {
            Gates[pos_Gate] = new NOR();
        }


        // .........................................................


        //Block For Nodes
        // Get the Nodes Names for each Gate in one string

        // NOT Gate have only one input So it is special (you can skip this )
        if (first_word == "NOT")
        {
            string in1;
            string out;

            file >> in1 >> out;

            Node* Node_ptr_in1 = Find_Node(in1);
            Node* Node_ptr_out = Find_Node(out);

            Gates[pos_Gate]->Set_input1(Node_ptr_in1);
            Gates[pos_Gate]->Set_output(Node_ptr_out);

            pos_Gate++;
            continue;
        }

        // substract the string and get each node in string
        string in1;
        string in2;
        string out;

        file >> in1 >> in2 >> out;

        // Get a pointer to this node to store it in the Node pointer in Gate class
        Node* Node_ptr_in1 = Find_Node(in1);
        Node* Node_ptr_in2 = Find_Node(in2);
        Node* Node_ptr_out = Find_Node(out);

        // Make the Node pointer in Gate points to each node of (input1 , input2 , output)
        Gates[pos_Gate]->Set_input1(Node_ptr_in1);
        Gates[pos_Gate]->Set_input2(Node_ptr_in2);
        Gates[pos_Gate]->Set_output(Node_ptr_out);

        pos_Gate++;

        // .........................................................
    }
}

