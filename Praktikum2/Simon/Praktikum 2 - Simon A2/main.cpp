#include <travelagency.h>

int main()
{
    TravelAgency ta;
    char choice;
    ta.readFile();
    /*
    do{
        cout << "Moechten Sie die Binaere-Datei einlesen, druecken Sie b\n"
                "Moechten Sie die Normale-Datei einlesen, druecken Sie n\n" << endl;
        cin >> choice;
        switch (choice) {
        case 'n': ta.readFile(); break;
        default: cout << "Dies war keine gueltige Eingabe";
        }
    }while(choice == 'b' || choice == 'n');
    */
    return 0;
}
