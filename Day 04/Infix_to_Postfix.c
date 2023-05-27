#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct OPS
{
    char soal[100], operand[100], stackkk[100];
    int indeks_stack, indeks_operand;
    int flag_stack;
} Operatorrr;

Operatorrr var;

void OPS_init()
{
    var.indeks_stack = -1;
    var.indeks_operand = -1;
    var.flag_stack = 0;
}

void pop_stack()
{
    var.indeks_stack--;
}

void push_operand(char huruf)
{
    var.operand[++var.indeks_operand] = huruf;
}

void push_stack(char huruf)
{

    var.stackkk[++var.indeks_stack] = huruf;
}

int main()
{

    OPS_init();
    scanf("%s", &var.soal);
    int x = strlen(var.soal);

    for (int i = 0; i < x; i++)
    {
        if (var.soal[i] >= '0' && var.soal[i] <= '9')
        {
            push_operand(var.soal[i]);
        }
        else if (var.soal[i] == '*' || var.soal[i] == '/' || var.soal[i] == '+' || var.soal[i] == '-')
        {
            while (var.indeks_stack > -1)
            {
                if (var.soal[i] == '+' || var.soal[i] == '-')
                {
                    if (var.flag_stack == 1)
                    {
                        push_operand(var.stackkk[var.indeks_stack]);
                        pop_stack();
                    }
                }
                else if (var.soal[i] == '*' || var.soal[i] == '/')
                {
                    if (var.stackkk[var.indeks_stack] == '*' || var.stackkk[var.indeks_stack] == '/')
                    {
                        if (var.flag_stack == 1)
                        {
                            push_operand(var.stackkk[var.indeks_stack]);
                            pop_stack();
                        }
                    }
                    else
                        break;
                }
            }
            push_stack(var.soal[i]);
            var.flag_stack = 1;
        }
    }
    for (int i = var.indeks_stack; i >= 0; i--)
    {
        push_operand(var.stackkk[i]);
    }

    for (int i = 0; i <= var.indeks_operand; i++)
    {
        printf("%c", var.operand[i]);
    }
    printf("\n");
}