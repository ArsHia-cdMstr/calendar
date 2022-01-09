#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <stdlib.h>

using namespace std;

// class PerCalendar
// {
// public:
//     PerCalendar()
//     {
//         startAPerCalendar();
//     }
// };

class GeoCalendar
{
    // find the currunt time
    time_t now = time(0);
    tm *ltm = localtime(&now); // currunt time
    int year = (ltm->tm_year + 1900);
    int month = ltm->tm_mon;
    int weekDay = ltm->tm_wday;
    int monthDay = ltm->tm_mday;

public:
    GeoCalendar()
    {
        startTheCalendar(year, month, monthDay, weekDay);
    }

    void startTheCalendar(int year, int month, int monthDay, int weekDay)
    {
        // print the calendar :
        int month_1st_weekday = findTheFirstDayOfMonth(monthDay, weekDay);
        printTheMonthTitle(year, month);
        printDaysOfAMonth(year, month, month_1st_weekday);

        Actions();
    }

    void Actions()
    {

        while (true)
        {

            // choose the day that we want to put a note
            cout << "note day : " << monthDay;

            string commond;
            cout << "\n (N) for next day " << endl;
            cout << " (P) for the past day " << endl;
            cout << " (Q) to quit the program  " << endl;
            cout << " (s) to see the note or edit it :" << endl ; 

            cin >> commond;

            // next day
            if (commond == "N" || commond == "n")
            {
                // if we are in the sunday
                // next day will be saturday
                // the 1st day of the week
                if (weekDay == 6)
                    weekDay = 0;
                else
                    weekDay++;

                // if we are in 31th December 2021
                // next day will be 1st jan 2022
                if (month == 11 && monthDay == 31)
                {
                    month = 0;
                    year++;
                }

                // if we are in 31th of march the next
                // day will be 1st of april
                if (monthDay == numberOfDays(year, month))
                {
                    monthDay = 1;
                    month++;
                }
                else
                    monthDay++;

                startTheCalendar(year, month, monthDay, weekDay)
            }

            // past day
            else if (commond == "P" || commond == "p")
            {
                // if we are in the saturday
                // past day will be sunday  
                // which is the end of the week
                if (weekday == 0)
                    weekDay == 6 ;
                else
                    weekDay-- ;

                // if we are in 1st jan 2021
                // the past day will be 31th Dec 2020
                if (month == 1 && monthDay == 1)
                {
                    monthDay == 31 ;
                    year-- ;
                    month = 11 ;
                }


                // if we are in the april's 1st      
                // past day will be 31th March
                if (monthDay == 1)
                {
                    month--;
                    monthday = numberOfDays(year , (month - 1) );
                }else{
                    monthDay-- ;
                }

                startTheCalendar(year ,month ,monthDay ,weekDay);             
            }

            //quitting the program
            else if (commond == "Q" || commond == "q")
            {
                cout << " you quited the program :) " << endl;
                exit(0);
            }

            else if (commond == "S" || commond == "s")
            {
            
            }
        }

    }

    void showTheNote(int year ,int month ,int monthDay ,int weekDay)
    {
        
    }

    void printDaysOfAMonth(int year, int month, int M1W)
    {
        for (int i = 0; i < M1W; i++)
            cout << "    ";
        int days = numberOfDays(year, month); // EX: March -> 31 days
        int k = M1W;                          // to know when to jump to the next line in printing calendar

        for (int i = 1; i <= days; i++)
        {
            printf("%4d", i);
            if (k == 6)
            {
                cout << "\n";
                k = 0;
            }
            else
                k++;
        }
    }

    // EX : march -> 31 days
    int numberOfDays(int year, int month)
    {
        switch (month)
        {
        case 0:
            return 31; // jan
        case 1:
            if (year % 400 == 0 || // feb
                (year % 4 == 0 && year % 100 != 0))
                return (29);
            else
                return (28);
        case 2:
            return 31; // march
        case 3:
            return 30; // april
        case 4:
            return 31; // may
        case 5:
            return 30; // june
        case 6:
            return 31; // july
        case 7:
            return 31; // Aug
        case 8:
            return 30; // Sep
        case 9:
            return 31; // Oct
        case 10:
            return 30; // Nov
        case 11:
            return 31; // Dec
        }
    }

    void printTheMonthTitle(int year, int month)
    {
        cout << "  --------------------------" << endl;
        cout << "       " << monthDayName(month) << "  ,  " << year << endl;
        cout << "  --------------------------" << endl;
        cout << "  Su  Mo  Tu  We  Th  Fr  Sa" << endl;
    }

    // the 0th month -> january , ...
    string monthDayName(int month)
    {
        switch (month)
        {
        case 0:
            return "January";
        case 1:
            return "February";
        case 2:
            return "March";
        case 3:
            return "April";
        case 4:
            return "May";
        case 5:
            return "june";
        case 6:
            return "july";
        case 7:
            return "August";
        case 8:
            return "September";
        case 9:
            return "October";
        case 10:
            return "November";
        case 11:
            return "December";
        }
    }

    // today is 10th and saturday what day is 1st ?
    int findTheFirstDayOfMonth(int monthDay, int weekDay)
    {
        return ((weekDay - ((monthDay - 1) % 7)) % 7);
    }
};

int main()
{
}
