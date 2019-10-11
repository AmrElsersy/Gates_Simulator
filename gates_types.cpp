#include "gates_types.h"


void AND:: Logic_Calc()
{
    if ((input1->Get_Value() == 1 && input2->Get_Value() == 1))
    {
        output->Set_Value(1);
    }
    else
    {
        output->Set_Value(0);
    }
}

void OR :: Logic_Calc()
{
    if ((input1->Get_Value() == 1 || input2->Get_Value() == 1))
    {
        output->Set_Value(1);
    }
    else
    {
        output->Set_Value(0);
    }
}
void  NOT ::Logic_Calc()
{
    if (input2 == NULL)
    {
        if (input1->Get_Value() == 0)
        {
            output->Set_Value(1);
        }
        else if (input1->Get_Value() == 1)
        {
            output->Set_Value(0);
        }
    }
    else if (input1 == NULL)
    {
        if (input2->Get_Value() == 0)
        {
            output->Set_Value(1);
        }
        else if (input2->Get_Value() == 1)
        {
            output->Set_Value(0);
        }
    }
}
void XOR :: Logic_Calc()
{
    if (input1->Get_Value() == input2->Get_Value())
    {
        output->Set_Value(0);
    }
    else
    {
        output->Set_Value(1);
    }
}
void XNOR:: Logic_Calc()
{
    if (input1->Get_Value() == input2->Get_Value())
    {
        output->Set_Value(1);
    }
    else
    {
        output->Set_Value(0);
    }
}
void NAND :: Logic_Calc()
{
    if ((input1->Get_Value() == 1 && input2->Get_Value() == 1))
    {
        output->Set_Value(0);
    }
    else
    {
        output->Set_Value(1);
    }
}
void NOR:: Logic_Calc()
{
    if ((input1->Get_Value() == 1 || input2->Get_Value() == 1))
    {
        output->Set_Value(0);
    }
    else
    {
        output->Set_Value(1);
    }
}
