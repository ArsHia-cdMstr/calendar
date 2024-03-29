#include <iostream>

// work with strings
#include <string>

// give the currunt time
#include <ctime>

#include <stdlib.h>
#include <stdio.h>

// work with files
#include <fstream>

// just to creat a directory
#include <conio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

using namespace std;


void choosTheCalendar();

class GeoCalendar
{
    // define the fields
    int year;
    int month;
    int monthDay;
    int weekDay;

public:
    GeoCalendar(int y, int m, int md, int wd)
        : year(y), month(m), monthDay(md), weekDay(wd)
    {
    }

    // getter methods of years , month , month day fields
    int getYear() { return year; }
    int getMonth() { return month; }
    int getMonthDay() { return monthDay; }

    // we need the start() to be public
    // and it is just maded to declare the
    // time that we want to print the calendar
    void start()
    {
        startTheCalendar(year, month, monthDay, weekDay);
    }

    // main func doesn't need to access these functions to run print a calendar
private:
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
            cout << "\n\n  note day : " << monthDay;

            string commond;
            cout << "\n (N) for next day " << endl;
            cout << " (P) for the past day " << endl;
            cout << " (Q) to quit the program  " << endl;
            cout << " (s) to see the note or edit it :" << endl;
            cout << " (b) to back to choosing the calenare type (perasian/georgian) :";

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
                    // monthDay = 1;
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

                startTheCalendar(year, month, monthDay, weekDay);
            }

            // past day
            else if (commond == "P" || commond == "p")
            {
                // if we are in the saturday
                // past day will be sunday
                // which is the end of the week
                if (weekDay == 0)
                    weekDay = 6;
                else
                    weekDay--;

                // if we are in 1st jan 2021
                // the past day will be 31th Dec 2020
                if (month == 1 && monthDay == 1)
                {
                    monthDay == 31;
                    year--;
                    month = 11;
                }

                // if we are in the april's 1st
                // past day will be 31th March
                if (monthDay == 1)
                {
                    month--;
                    monthDay = numberOfDays(year, (month - 1));
                }
                else
                {
                    monthDay--;
                }

                startTheCalendar(year, month, monthDay, weekDay);
            }

            // quitting the program
            else if (commond == "Q" || commond == "q")
            {
                cout << " you quited the program :) " << endl;
                exit(0);
            }

            else if ( commond == "b" || commond == "B")
            {
                // to clear the output befor the calendar
                if (system("CLS")) system("clear");
                choosTheCalendar();
            }

            // start writing and reading the notes
            else if (commond == "S" || commond == "s")
                showTheNote(year, month, monthDay, weekDay);

            // if the input isn't a correct word
            else
                cout << "commond word is wrong pleas try again :) " << endl;
        }
    }

    void showTheNote(int year, int month, int monthDay, int weekDay)
    {
        while (true)
        {
            string fileName = "notes\\" + to_string(year) + "-" + to_string(month + 1) + "-" + to_string(monthDay) + ".txt";
            ifstream inF(fileName);
            string readNote;

            // check if the day has a note
            // and then print it but if it don't
            // just say that it doesn't have
            if (inF)
            {
                cout << "note :" << endl;
                while (inF)
                {
                    getline(inF, readNote);
                    cout << readNote << endl;
                }
            }
            else
            {
                cout << "this day doesn't have a note !" << endl;
            }
            inF.close();

            // now you can delete all of note or to write
            // a new one or to edit the last one

            cout << " (D) for deleting the note file " << endl;
            cout << " (W) for writing a note " << endl;
            cout << " for ending the writing print (END) in the beginning of a line" << endl;
            cout << " (Q) to quit the notepad  " << endl;

            string commond;
            cin >> commond;

            // writing a note
            if (commond == "w" || commond == "W")
            {
                ofstream outF(fileName);
                cout << "write the note : " << endl;
                string WriteNote;

                // Execute a loop If file successfully Opened
                while (outF)
                {
                    getline(cin, WriteNote);

                    // press END to exit
                    if (WriteNote == "END")
                        break;

                    outF << WriteNote << endl;
                }

                outF.close();
            }

            // deleting the file
            if (commond == "d" || commond == "D")
            {
                int status = remove(fileName.c_str());
                if (status == 0)
                    cout << "file removed successfully !" << endl;
                else
                    cout << "file didn't exits !" << endl;
            }

            if (commond == "Q" || commond == "q")
                break;
        }

        // when we're done writing and reading we go to the calendar again
        startTheCalendar(year, month, monthDay, weekDay);
    }

    void printDaysOfAMonth(int year, int month, int M1W)
    {
        for (int i = 0; i < M1W; i++)
            cout << "    ";
        int days = numberOfDays(year, month); // EX: March -> 31 days
        int k = M1W;                          // to know when to jump to the next line in printing calendar

        int *redDays = notedDays(year, month);
        int redInd = 0;

        // printing part
        for (int i = 1; i <= days; i++)
        {
            // if the day has a note print it with red color
            if (i == redDays[redInd])
            {
                printf("\033[1;31m%4d\033[m", i);
                redInd++;

                if (k == 6)
                {
                    cout << "\n";
                    k = 0;
                }
                else
                    k++;
            }
            else
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
        delete[] redDays;
    }

    // finds that what day has a note
    int *notedDays(int year, int month)
    {
        int endOfMonth = numberOfDays(year, month);
        int *days = new int[31];
        string fileName;
        int k = 0;

        for (int i = 1; i < endOfMonth; i++)
        {
            fileName = "notes\\" + to_string(year) + "-" + to_string(month + 1) + "-" + to_string(i) + ".txt";
            // to find that is a note file exists for this date or not
            ifstream inF(fileName);
            bool exists = inF.good();
            if (exists)
            {
                days[k] = i;
                k++;
            }
        }
        return days;
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
        // to clear the output befor the calendar
         if (system("CLS")) system("clear");

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
        // 0 <= weekDay <= 6
        int m = ((weekDay - ((monthDay - 1) % 7)) % 7);
        if (m < 0)
            return (m + 7);
        else
            return m;
    }
};

class PerCalendar
{
    int year;
    int month;
    int monthDay;
    int weekDay;

    // i want to make the note files only with georgian dates like : (2022-01-14.txt)
    // that we can see geogian notes frome jalili calendar
    int GY;  // georgian year
    int GM;  // georgian month
    int GMD; // georgian month day

public:
    PerCalendar(int gy, int gm, int gmd, int gwd)
        : GY(gy), GM(gm), GMD(gmd)
    {
        // an array to give the jalili date
        long a[3];

        // convert georgian date to jalili date
        gregorian_to_jalali(GY, GM + 1, GMD, a);

        // give jalili date to class fields
        year = a[0];

        // 1 <= a[1] <= 12
        // 0 <= month <= 11 our func have been written for this kind of input
        month = (a[1] - 1);
        monthDay = a[2];

        // georgian date's weeks start with sunday and
        // jalili date's week start with saturday so we need to
        // change the week day for jalili calendar
        weekDay = ((gwd + 1) % 7);
    }

    void start()
    {
        startTheCalendar(year, month, monthDay, weekDay);
    }

private:
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
            cout << "\n\n  note day : " << monthDay;

            string commond;
            cout << "\n (N) for next day " << endl;
            cout << " (P) for the past day " << endl;
            cout << " (Q) to quit the program  " << endl;
            cout << " (s) to see the note or edit it :" << endl;
            cout << " (b) to back to choosing the calenare type (perasian/georgian) :";


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

                // if we are in 29th esfand 1400
                // next day will be 1st farvardin 1401
                if (month == 11 && monthDay == numberOfDays(year ,month))
                {
                    monthDay = 1;
                    month = 0;
                    year++;
                }

                // if we are in 31th of march the next
                // day will be 1st of april
                else if (monthDay == numberOfDays(year, month))
                {
                    monthDay = 1;
                    month++;
                }
                else
                    monthDay++;

              startTheCalendar(year, month, monthDay, weekDay);
            }

            // past day
            else if (commond == "P" || commond == "p")
            {
                // if we are in the saturday
                // past day will be sunday
                // which is the end of the week
                if (weekDay == 0)
                    weekDay = 6;
                else
                    weekDay--;

                // if we are in 1st jan 2021
                // the past day will be 31th Dec 2020
                if (month == 1 && monthDay == 1)
                {
                    monthDay == numberOfDays(year ,month);
                    year--;
                    month = 11;
                }

                // if we are in the april's 1st
                // past day will be 31th March
                if (monthDay == 1)
                {
                    month--;
                    monthDay = numberOfDays(year, (month - 1));
                }
                else
                {
                    monthDay--;
                }

                startTheCalendar(year, month, monthDay, weekDay);
            }

             else if ( commond == "b" || commond == "B")
            {
                // to clear the output befor the calendar
                if (system("CLS")) system("clear");
                choosTheCalendar();
            }

            // quitting the program
            else if (commond == "Q" || commond == "q")
            {
                cout << " you quited the program :) " << endl;
                exit(0);
            }

            // start writing and reading the notes
            else if (commond == "S" || commond == "s")
                showTheNote(year, month, monthDay, weekDay);

            // if the input isn't a correct word
            else
                cout << "commond word is wrong pleas try again :) " << endl;
        }
    }

    void showTheNote(int year, int month, int monthDay, int weekDay)
    {
        while (true)
        {
            string fileName = "notes\\" + to_string(year) + "-" + to_string(month + 1) + "-" + to_string(monthDay) + ".txt";
            ifstream inF(fileName);
            string readNote;

            // check if the day has a note
            // and then print it but if it don't
            // just say that it doesn't have
            if (inF)
            {
                cout << "note :" << endl;
                while (inF)
                {
                    getline(inF, readNote);
                    cout << readNote << endl;
                }
            }
            else
            {
                cout << "this day doesn't have a note !" << endl;
            }
            inF.close();

            // now you can delete all of note or to write
            // a new one or to edit the last one

            cout << " (D) for deleting the note file " << endl;
            cout << " (W) for writing a note " << endl;
            cout << " for ending the writing print (END) in the beginning of a line" << endl;
            cout << " (Q) to quit the notepad  " << endl;

            string commond;
            cin >> commond;

            // writing a note
            if (commond == "w" || commond == "W")
            {
                ofstream outF(fileName);
                cout << "write the note : " << endl;
                string WriteNote;

                // Execute a loop If file successfully Opened
                while (outF)
                {
                    getline(cin, WriteNote);

                    // press END to exit
                    if (WriteNote == "END")
                        break;

                    outF << WriteNote << endl;
                }

                outF.close();
            }

            // deleting the file
            if (commond == "d" || commond == "D")
            {
                int status = remove(fileName.c_str());
                if (status == 0)
                    cout << "file removed successfully !" << endl;
                else
                    cout << "file didn't exits !" << endl;
            }

            if (commond == "Q" || commond == "q")
                break;
        }

        // when we're done writing and reading we go to the calendar again
        startTheCalendar(year, month, monthDay, weekDay);
    }

    void printDaysOfAMonth(int year, int month, int M1W)
    {
        for (int i = 0; i < M1W; i++)
            cout << "    ";
        int days = numberOfDays(year, month); // EX: March -> 31 days
        int k = M1W;                          // to know when to jump to the next line in printing calendar

        // we give the noteDays function the georgian date
        //  so we can find the name of the files in georgian date type
        int *redDays = notedDays(year, month);
        int redInd = 0;

        // printing part
        for (int i = 1; i <= days; i++)
        {
            // if the day has a note print it with red color
            if (i == redDays[redInd])
            {
                printf("\033[1;31m%4d\033[m", i);
                redInd++;
            }
            else
                printf("%4d", i);
            
                if (k == 6)
                {
                    cout << "\n";
                    k = 0;
                }
                else
                    k++;
        }
        delete[] redDays;
    }

    // finds that what day has a note
    int *notedDays(int year, int month)
    {
        int endOfMonth = numberOfDays(year, month);
        int *days = new int[31];
        string fileName;
        int k = 0;

        for (int i = 1; i <= endOfMonth; i++)
        {
            fileName = "notes\\" + to_string(year) + "-" + to_string(month + 1) + "-" + to_string(i) + ".txt";
            // to find that is a note file exists for this date or not
            ifstream inF(fileName);
            bool exists = inF.good();
            if (exists)
            {
                days[k] = i;
                k++;
            }
        }
        return days;
    }

    // jalili date has changes with gergian date in this func
    // EX : dey -> 30 days
    int numberOfDays(int year, int month)
    {
        switch (month)
        {
        case 0:
            return 31; // farvardin
        case 1:
            return 31; // ordibehesht
        case 2:
            return 31; // khordad
        case 3:
            return 31; // tir
        case 4:
            return 31; // mordad
        case 5:
            return 31; // shahrivar
        case 6:
            return 30; // mehr
        case 7:
            return 30; // aban
        case 8:
            return 30; // azar
        case 9:
            return 30; // dey
        case 10:
            return 30; // bahman
        case 11:       // esfand
            if ((year % 4) == 3)
                return 30;
            else
                return 29;
        }
    }

    // jalili date has changes with gergian date in this func
    void printTheMonthTitle(int year, int month)
    {
        // to clear the output befor the calendar
         if (system("CLS")) system("clear");

        cout << "  --------------------------" << endl;
        cout << "       " << monthDayName(month) << "  ,  " << year << endl;
        cout << "  --------------------------" << endl;
        cout << "  sh  1s  2s  3s  4s  5s  jo" << endl;
    }

    // jalili date has changes with gergian date in this func
    // the 0th month -> farvardin , ...
    string monthDayName(int month)
    {
        switch (month)
        {
        case 0:
            return "farvardin";
        case 1:
            return "ordibehesht";
        case 2:
            return "khordad";
        case 3:
            return "tir";
        case 4:
            return "mordad";
        case 5:
            return "shahrivar";
        case 6:
            return "mehr";
        case 7:
            return "aban";
        case 8:
            return "azar";
        case 9:
            return "dey";
        case 10:
            return "bahman";
        case 11:
            return "esfand";
        }
    }

    // today is 10th and saturday what day is 1st ?
    int findTheFirstDayOfMonth(int monthDay, int weekDay)
    {
        // 0 <= weekDay <= 6
        int m = ((weekDay - ((monthDay - 1) % 7)) % 7);
        if (m < 0)
            return (m + 7);
        else
            return m;
    }

    // input is georgian date and output is an array of persian output
    void gregorian_to_jalali(long gy, long gm, long gd, long out[])
    {
        long days;
        {
            long gy2 = (gm > 2) ? (gy + 1) : gy;
            long g_d_m[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
            days = 355666 + (365 * gy) + ((int)((gy2 + 3) / 4)) - ((int)((gy2 + 99) / 100)) + ((int)((gy2 + 399) / 400)) + gd + g_d_m[gm - 1];
        }
        long jy = -1595 + (33 * ((int)(days / 12053)));
        days %= 12053;
        jy += 4 * ((int)(days / 1461));
        days %= 1461;
        if (days > 365)
        {
            jy += (int)((days - 1) / 365);
            days = (days - 1) % 365;
        }
        out[0] = jy;
        if (days < 186)
        {
            out[1] /*jm*/ = 1 + (int)(days / 31);
            out[2] /*jd*/ = 1 + (days % 31);
        }
        else
        {
            out[1] /*jm*/ = 7 + (int)((days - 186) / 30);
            out[2] /*jd*/ = 1 + ((days - 186) % 30);
        }
        return;
    }
};

// which calendar do you want to use ??

int main()
{
    // notes will be saved in this directory
    mkdir("notes");

    // to clear the terminal
    if (system("CLS")) system("clear");

    choosTheCalendar();
}

void choosTheCalendar()
{
    
    // find the currunt time
    time_t now = time(0);
    tm *ltm = localtime(&now); // currunt time
    int year = (ltm->tm_year + 1900);
    int month = ltm->tm_mon;     //  0 <= month <= 11
    int weekDay = ltm->tm_wday;  // 0 <= week day <= 6
    int monthDay = ltm->tm_mday; // 1 <= month day <= 31 or 30 or ... based on the month


    while (true)
    {
        cout << "choos the calendar type : " << endl;
        cout << "(P) for using the persian calendar " << endl;
        cout << "(G) for using the Georian calendar " << endl;
        string commond;
        cin >> commond;

        if (commond == "p" || commond == "P")
        {
            cout << "persian calendar starts : " << endl;
            PerCalendar p(year, month, monthDay, weekDay);
            p.start();
        }
        else if(commond == "G" || commond == "g")
        {
            cout << "georgian calendar starts : " << endl;
            GeoCalendar g(year, month, monthDay, weekDay);
            g.start();
        }
        else
        {
            cout << "your input is wrong pleas try again :)" << endl;
        }
    }
}
