#include<iostream>
#include<string>

using namespace std ;

void chooseGor_Per();
void startGeorgian();
void startPersian();

int main()
{
    chooseGor_Per() ;
}

void chooseGor_Per()
{
    char a ;
    cout << "for using georgian calendar type \"G\" \nand for using persian calendar type \"P\" (G/P) : " ;
    cin >> a ;
    if (a == 'G' || a == 'g'){ 
        // start georgian calendar

    }else if (a == 'p' || a == 'P'){
        // start persian calendar
        
    }else{
        cout << "your input is wrong" ;
        chooseGor_Per();
    }
}

void startGeorgian()
{
    
}
