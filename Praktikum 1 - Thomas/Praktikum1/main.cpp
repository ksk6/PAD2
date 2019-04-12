#include <iostream>
#include <travelagency.h>
using namespace std;

int main()
{
    TravelAgency agency;
    int in = -1;

    cout << "Bitte nennen Sie den gewünschten Modus:" << endl;
    cout << "0 - Text" << endl;
    cout << "1 - Binary" << endl;
    cout << "Alles andere - Programm beenden" << endl;

    cin >> in;

    if(in == 0){
        // Text
        agency.readFile();
    }else if(in == 1){
        // Binary
        agency.readBinaryFile();
    }else{
        return 0;
    }

    return 0;
}
