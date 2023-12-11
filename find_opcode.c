#include "monty.h"

/***/

void find_opcode(void)
{
    instruction_t instruction[] =
        {
            {"push", push},
            {"pall", pall},
            {"pint", pint},
            {"pop", pop},
            {"swap", swap},
            {"add", add},
            {"nop", nop},
        };
}