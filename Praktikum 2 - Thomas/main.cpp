#include <travelagency.h>

int main()
{
    char choice, type;
    double price;
    int createbooking;
    long travelID;
    string start, end, buffer;
    TravelAgency travelAgency;
    vector<string> bookingDetails;

    travelAgency.readFile();

    do
    {
        cout << endl << "Moechten Sie eine zusaetzliche Buchung einfuegen? (j/n)" << endl;
        cin >> choice;
        if(choice == 'j')
        {
            //do{
            cout << "Bitte geben Sie den Typ der Buchung an (f=Flug , h=Hotel, r=Mietwagenbuchung):" << endl;
            cin >> type;
            //}while(type != 'r' && type != 'h' && type != 'h');
            cout << "Bitte geben Sie den Preis der Buchung an:";
            cin >> price;
            cout << "Bitte geben Sie das Startdatum ein: ";
            cin >> start;
            cout << "Bitte geben Sie das Enddatum ein: ";
            cin >> end;
            cout << "Bitte geben Sie das ReiseID ein: ";
            cin >> travelID;
            if(type == 'f')
            {
                cout << "Bitte geben Sie den Abflughafen ein: ";
                cin >> buffer;
                bookingDetails.push_back(buffer);
                cout << "Bitte geben Sie den Zielflughafen ein: ";
                cin >> buffer;
                bookingDetails.push_back(buffer);
                cout << "Bitte geben Sie die Airline ein: ";
                cin >> buffer;
                bookingDetails.push_back(buffer);
            }
            else if(type == 'r')
            {
                cout << "Bitte geben Sie die AbholstravelAgencytion ein: ";
                cin >> buffer;
                bookingDetails.push_back(buffer);
                cout << "Bitte geben Sie die Rueckgabestation ein: ";
                cin >> buffer;
                bookingDetails.push_back(buffer);
                cout << "Bitte geben Sie die Firma ein: ";
                cin >> buffer;
                bookingDetails.push_back(buffer);
            }
            else if(type == 'h')
            {
                cout << "Bitte geben Sie das Hotel an: ";
                cin >> buffer;
                bookingDetails.push_back(buffer);
                cout << "Bitte geben Sie die Stadt ein: ";
                cin >> buffer;
                bookingDetails.push_back(buffer);
            }
            travelAgency.createBooking( type,  price,  start,  end,  travelID, bookingDetails);
            createbooking = travelAgency.createBooking( type,  price,  start,  end,  travelID, bookingDetails);

            if(createbooking == -1)
            {
                cout << "Die Reise mit der Nummer " << travelID << " besteht nicht und daher konnte keine Buchung angelegt werden" << endl;
            }
            else
            {
                cout << "Die Buchung mit der ID " << createbooking << " wurde angelegt" << endl;
                cout << "Es bestehen nun " << travelAgency.getNumberOfFlights() << " Flugbuchungen, " << travelAgency.getNumberOfRentalCarReservation() << " Mietwagenbuchungen, " << travelAgency.getNumberOfHotelBookings() << " Hotelbuchungen, im Gesamtwert von " << int(travelAgency.getTotalPrice()) << " Euro" <<  endl;
            }

        }
        else { return 0; }
    }
    while(true);
}
