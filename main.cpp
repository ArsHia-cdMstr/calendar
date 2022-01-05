#include<iostream>
#include<string>
#include <ctime>
#include <iomanip>


using namespace std ;

void startACalendar()
{
    //find the currunt time
        time_t now = time(0);
        tm *ltm = localtime(&now); // currunt time 

        int month_1st_weekday = findTheFirstDayOfMonth() ;
        
}

void printTheMontheTitle(tm* time)
{
    cout << setfill('-') << setw(26) <<     ;
    cout << setw(5) << monthDayName(time->tm_mon) << "  ,  " << 1900 + time->tm_year << endl;
    cout << setfill('-') << setw(26) << endl;
}

string monthDayName(int month)
{
    switch (month)
    {
    case 0: return "January";
    case 1: return "February";
    case 2: return "March";
    case 3: return "April";
    case 4: return "May";
    case 5: return "june";
    case 6: return "july";
    case 7: return "August";
    case 8: return "September";
    case 9: return "October";
    case 10: return "November";
    case 11: return "December";
    }
}

int findTheFirstDayOfMonth(tm *time)
{
    return (time->tm_mday * -1)+1 % 7 ;
} 

class Calendar 
{
public:
    Calendar()
    {
        startACalendar();
                       
    }
}


int main()
{

}
