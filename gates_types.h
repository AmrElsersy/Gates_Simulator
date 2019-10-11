#ifndef GATES_TYPES_H
#define GATES_TYPES_H
#include "gate.h"

class AND : public Gate
{
    void Logic_Calc();
};

class OR : public Gate
{
    void Logic_Calc();
};

class NOT : public Gate
{
    void Logic_Calc();
};

class XOR : public Gate
{
    void Logic_Calc();
};

class XNOR : public Gate
{
    void Logic_Calc();
};

class NAND : public Gate
{
    void Logic_Calc();
};

class NOR : public Gate
{
    void Logic_Calc();
};

#endif // GATES_TYPES_H
