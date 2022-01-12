#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    cout<< "start" << endl ;
    string filename ;
    getline(cin, filename);
    ofstream outfile(filename + ".dat");
    outfile << "hello";
    outfile.close();
    cout << "end" << endl ;
    return 0;
}