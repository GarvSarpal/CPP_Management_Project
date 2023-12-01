#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

class managesystem
{
public:
    void details();
    void additem();
    void readitem();
    void updateitem();
    void deleteitem();
};

void managesystem::details()
{
    system("cls");
    cout << "Press the following keys to go through the details" << endl << endl;
    cout << "1. Add rented car details" << endl;
    cout << "2. Read rented car details" << endl;
    cout << "3. Update rented car details" << endl;
    cout << "4. Delete rented car details" << endl;
    cout << "5. Exit the car rental management system" << endl;
}

void managesystem::additem()
{
    system("cls");

    int sno;
    string pn, pd, cn, cpn, d, csd;
    fstream file;

    cout << "Enter the following details" << endl << endl;

    cout << "Enter the Serial No = ";
    cin >> sno;
    cout << "Enter the Person Name = ";
    cin >> pn;
    cout << "Enter the Person Details = ";
    cin >> pd;
    cout << "Enter the Date = ";
    cin >> d;
    cout << "Enter the Car Name = ";
    cin >> cn;
    cout << "Enter the Car Plate Number = ";
    cin >> cpn;
    cout << "Enter the Car Submission Date = ";
    cin >> csd;

    file.open("managesystem.txt", ios::out | ios::app);
    file << sno << " " << pn << " " << pd << " " << d << " " << cn << " " << cpn << " " << csd << endl;
    file.close();
}

void managesystem::readitem()
{
    system("cls");

    int sno;
    string pn, pd, cn, cpn, d, csd;
    fstream file;

    file.open("managesystem.txt", ios::in);

    if (!file)
    {
        cout << "File Opening Error....";
    } else {
        cout << "Review the following details" << endl << endl;

        while (file >> sno >> pn >> pd >> d >> cn >> cpn >> csd)
        {
            cout << "Serial No = " << sno << endl;
            cout << "Person Name = " << pn << endl;
            cout << "Person Details = " << pd << endl;
            cout << "Date = " << d << endl;
            cout << "Car Name = " << cn << endl;
            cout << "Car Plate Number = " << cpn << endl;
            cout << "Car Submission Date = " << csd << endl << endl;
        }
    }

    file.close();
}

void managesystem::updateitem()
{
    system("cls");

    int sno, usno, count = 0;
    string upn, upd, ucn, ucpn, ud, ucsd;
    fstream file, file1;

    file1.open("managesystemupdate.txt", ios::app | ios::out);
    file.open("managesystem.txt", ios::in);

    if (!file)
    {
        cout << "File Opening Error";
    }
    else
    {
        cout << "Update the following details" << endl << endl;
        cout << "Update the Serial No = ";
        cin >> usno;

        while (file >> sno >> upn >> upd >> ud >> ucn >> ucpn >> ucsd)
        {
            if (sno == usno)
            {
                cout << "Now Update the rest of the details" << endl;
                cout << "Update the Person Name = ";
                cin >> upn;
                cout << "Update the Person Details = ";
                cin >> upd;
                cout << "Update the Date = ";
                cin >> ud;
                cout << "Update the Car Name = ";
                cin >> ucn;
                cout << "Update the Car Plate Number = ";
                cin >> ucpn;
                cout << "Update the Car Submission Date = ";
                cin >> ucsd;
                count++;
            }

            file1 << sno << " " << upn << " " << upd << " " << ud << " " << ucn << " " << ucpn << " " << ucsd << endl;
        }

        if (count == 0)
            cout << "Serial no not Found";
    }

    file.close();
    file1.close();

    remove("managesystem.txt");
    rename("managesystemupdate.txt", "managesystem.txt");
}

void managesystem::deleteitem()
{
    system("cls");

    int sno, dsno, count = 0;
    string dpn, dpd, dcn, dcpn, dd, dcsd;
    fstream file, file1;

    cout << "Delete the following details" << endl << endl;

    file1.open("managesystemdelete.txt", ios::app | ios::out);
    file.open("managesystem.txt", ios::in);

    if (!file)
        cout << "File Opening Error";
    else
        {
        cout << "Delete the Serial No = ";
        cin >> dsno;

        while (file >> sno >> dpn >> dpd >> dd >> dcn >> dcpn >> dcsd)
            {
            if (sno == dsno)
            {
                cout << "Delete the rest of the details" << endl;
                cout << "One Item is Deleted Successfully" << endl;
                count++;
            } else
            {
                file1 << sno << " " << dpn << " " << dpd << " " << dd << " " << dcn << " " << dcpn << " " << dcsd << endl;
            }
        }

        if (count == 0)
            cout << "The serial no not Found";
    }

    file.close();
    file1.close();
    remove("managesystem.txt");
    rename("managesystemdelete.txt", "managesystem.txt");
}

int main()
{
    managesystem ms;
    p:
    ms.details();
    int choices;
    char x;
    cout << "Enter your Choice : ";
    cin >> choices;

    switch (choices)
    {
        case 1:
            do {
                ms.additem();
                cout << "Do You Want To Add Another Item (y/n) : ";
                cin >> x;
            } while (x == 'y');
            break;
        case 2:
            ms.readitem();
            break;
        case 3:
            ms.updateitem();
            break;
        case 4:
            ms.deleteitem();
            break;
        case 5:
            exit(0);
            break;
        default:
            cout << "\n\n Invalid Value....Please Try again";
    }

    cout << "\n";
    system("pause");
    goto p;
}
