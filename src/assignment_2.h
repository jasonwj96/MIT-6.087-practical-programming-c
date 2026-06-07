#pragma once

/*

Problem 2.1
Determine the size,minimum and maximum value following data types. Please specify if your
machine is 32 bit or 64 bits in the answer.

char
unsigned char
short
int
unsigned int
unsigned long
float

Hint: Use sizeof() operator,limits.h and float.h header files

Problem 2.2

Write logical expressions that tests whether a given character variable c is
lower case letter

• upper case letter
• digit
• white space (includes space,tab,new line)

Problem 2.3

Consider int val=0xCAFE; Write expressions using bitwise operators that do the following:

• test if atleast three of last four bits (LSB) are on
• reverse the byte order (i.e., produce val=0xFECA)
• rotate fourbits (i.e., produce val=0xECAF)

Problem 2.4

Using precedence rules, evaluate the following expressions and determine the value of the vari
ables(without running the code). Also rewrite them using parenthesis to make the order explicit.

Assume (x=0xFF33,MASK=0xFF00).Expression: c=x & MASK ==0;
Assume (x=10,y=2,z=2;).Expression: z=y=x++ + ++y∗2;
Assume (x=10,y=4,z=1;).Expression: y>>= x&0x2 && z;

Problem 2.5

Determine if the following statements have any errors. If so, highlight them
and explain why.
int 2nd value=10;
Assume (x=0,y=0,alliszero=1). alliszero =(x=1) && (y=0);•
Assume (x=10,y=3,z=0;). y=++x+y;z=z−−>x;•
Assume that we want to test if last four bits of x are on. (int MASK=0xF;ison=x&MASK==MASK)

*/

void problem_2_1();
void problem_2_2(char c);
void problem_2_3();