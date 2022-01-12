#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    cout<< "start" << endl ;
    string filename ;
    getline(cin, filename);

    // fstream  afile;
    // afile.open("file.dat", ios::out | ios::in );
    
    ofstream outfile(filename + ".txt");
    outfile << "hello";
    outfile.close();
    cout << "end" << endl ;
    return 0;
}


//file deleting 

#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int status;
    char fileName[20];
    cout<<"Enter the Name of File: ";
    cin>>fileName;
    status = remove(fileName);
    if(status==0)
        cout<<"\nFile Deleted Successfully!";
    else
        cout<<"\nError Occurred!";
    cout<<endl;
    return 0;
}























/* File Handling with C++ using ifstream & ofstream class object*/
/* To write the Content in File*/
/* Then to read the content of file*/
#include <iostream>

/* fstream header file for ifstream, ofstream,
fstream classes */
#include <fstream>

using namespace std;

// Driver Code
int main()
{
	// Creation of ofstream class object
	ofstream fout;

	string line;

	// by default ios::out mode, automatically deletes
	// the content of file. To append the content, open in ios:app
	// fout.open("sample.txt", ios::app)
	fout.open("sample.txt");

	// Execute a loop If file successfully opened
	while (fout) {

		// Read a Line from standard input
		getline(cin, line);

		// Press -1 to exit
		if (line == "-1")
			break;

		// Write line in file
		fout << line << endl;
	}

	// Close the File
	fout.close();

	// Creation of ifstream class object to read the file
	ifstream fin;

	// by default open mode = ios::in mode
	fin.open("sample.txt");

	// Execute a loop until EOF (End of File)
	while (fin) {

		// Read a Line from File
		getline(fin, line);

		// Print line in Console
		cout << line << endl;
	}

	// Close the file
	fin.close();

	return 0;
}
