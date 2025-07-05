#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char input[100];
int pos = 0;
char currentChar;

void error()
{
    printf(" Invalid Expression\n");
        exit(1);
        }
        void advance()
        {
            currentChar = input[pos++];
            }

            void match(char expected)
            {

                if(currentChar == expected)
                        advance();
                            else
                             error();
                                    }

                                    // Grammar: E -> T E'
                                    void E();
                                    void Eprime();
                                    void T();
                                    void Tprime();
                                    void F();

                                    void E()
                                    {
                                        T();
                                            Eprime();
                                            }
                                            void Eprime()
                                            {
                                                if(currentChar == '+' || currentChar == '-')
                                                    {
                                                            char op = currentChar;
                                                                    advance();
                                                                            T();
                                                                                    Eprime();
                                                                                        }
                                                                                            //else { (do nothing)
                                                                                            }


                                                                                            void T()
                                                                                            {
                                                                                                F();
                                                                                                    Tprime();
                                                                                                    }
                                                                                                    void Tprime()
                                                                                                    {
                                                                                                        if(currentChar == '*' || currentChar == '/')
                                                                                                            {
                                                                                                                    char op = currentChar;
                                                                                                                            advance();
                                                                                                                                    F();
                                                                                                                                            Tprime();
                                                                                                                                                }
                                                                                                                                                    //else { (do nothing)
                                                                                                                                                    }


                                                                                                                                                    void F()
                                                                                                                                                    {
                                                                                                                                                        if (isalpha(currentChar))
                                                                                                                                                            {
                                                                                                                                                                    advance();
                                                                                                                                                                        }
                                                                                                                                                                            else if (currentChar == '(')
                                                                                                                                                                                {
                                                                                                                                                                                        advance();
                                                                                                                                                                                                E();
                                                                                                                                                                                                        if(currentChar == ')')
                                                                                                                                                                                                                {
                                                                                                                                                                                                                            advance();
                                                                                                                                                                                                                                    }
                                                                                                                                                                                                                                            else
                                                                                                                                                                                                                                                    {
                                                                                                                                                                                                                                                                error();
                                                                                                                                                                                                                                                                        }
                                                                                                                                                                                                                                                                            }
                                                                                                                                                                                                                                                                                else
                                                                                                                                                                                                                                                                                    {
                                                                                                                                                                                                                                                                                            error();
                                                                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                                                                }

                                                                                                                                                                                                                                                                                                int main()
                                                                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                                                    printf("Enter an expression: ");
                                                                                                                                                                                                                                                                                                        fgets(input, sizeof(input), stdin);
                                                                                                                                                                                                                                                                                                            input[strcspn(input,"\n")] = '\0';
                                                                                                                                                                                                                                                                                                                advance();

                                                                                                                                                                                                                                                                                                                    E();
                                                                                                                                                                                                                                                                                                                        if(currentChar =='\0')
                                                                                                                                                                                                                                                                                                                                printf("Expression is valid \n");
                                                                                                                                                                                                                                                                                                                                    else
                                                                                                                                                                                                                                                                                                                                             printf("Invalid Expression\n");
                                                                                                                                                                                                                                                                                                                                             }