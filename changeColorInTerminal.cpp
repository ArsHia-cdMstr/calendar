#include <stdio.h>
#include <iostream>

using namespace std ;

// changing the color
int main()
{
    printf("\033[1;31m 2\033[m");// [1;31m -> bold red 
 // cout << "\033[31m jkl \033[m" ; // [31m -> red

 // cout << "\033[1;31m  bold red text  \033[0m"; //
    return 0;
}