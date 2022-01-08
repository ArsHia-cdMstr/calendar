#include<iostream>
#include<string>
#include <ctime>
#include <iomanip>


using namespace std ;

void startAGeoCalendar(bool isPersian )
{
    //find the currunt time
    time_t now = time(0);
    tm *ltm = localtime(&now); // currunt time 

    int month_1st_weekday = findTheFirstDayOfMonth( ltm ) ;
    printTheMonthTitle( ltm ) ;
    printDaysOfAMonth( ltm , month_1st_weekday );

}

void printDaysOfAMonth(tm* time , int M1W)//uncomplete
{
    cout << setw((M1W*4)) ;

    for (int i=0 ; i<)
}

int numberOfDays(int year, int month)
{
    switch (month)
    {
    case 0: return 31 ;//jan
    case 1: if (year % 400 == 0 ||      // feb
                (year % 4 == 0 && year % 100 != 0))
            return (29);
        else
            return (28);
    case 2: return 31;//march
    case 3: return 30;//april
    case 4: return 31;//may
    case 5: return 30;//june
    case 6: return 31;//july 
    case 7: return 31;//Aug
    case 8: return 30;//Sep
    case 9: return 31;//Oct
    case 10: return 30;//Nov
    case 11: return 31;//Dec
    }
}

void printTheMonthTitle(tm* time)
{
    cout << "--------------------------\n" ;
    cout << setw(5) << monthDayName(time->tm_mon) << "  ,  " << 1900 + time->tm_year << endl;
    cout << "--------------------------\n" ;
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
    return ((time->tm_wday - ((time->tm_mday - 1) % 7) ) % 7);
} 

class PerCalendar 
{
public:
    PerCalendar()
    {
        startAPerCalendar();               
    }
};

class GeoCalendar 
{
public:
    GeoCalendar()
    {
        startAGeoCalendar();               
    }
};


int main()
{

}
