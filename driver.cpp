#include "patron.h"
#include <fstream>

void displayMenuOption();
int getMenuOption();
void addPatron(Patron[], Patron, int*);
int readExistingPatrons(Patron[], string);
void printFileNotFound();
void displayPatrons(Patron[], int);
int getPatronOption(Patron[], int numPatrons);
void removePatron(Patron[], int, int*);
Patron createNewPatron();
void modifyPatron(Patron*);
void displayModOptions();
void displayRideMenu();
int getModOption();
void addTickets(Patron*);
void addRide(Patron*);
void editName(Patron*);
void overwriteFile(Patron[], string, int);

template <class T, class U>
T GetPatronInfo(T objectName, U numOfObjects){
    cout << objectName[numOfObjects].getFirstName()
         << " " << objectName[numOfObjects].getLastName()
         << " " << objectName[numOfObjects].getPatronNumber()
         << " " << objectName[numOfObjects].getNumTickets();

    return objectName;
} 

template <class T, class U, class V>
T NameSetters(T objectName, U first, V last){
    objectName -> setFirstName(first);
    objectName -> setLastName(last);

    return objectName;
}

template <class T, class U, class V, class W, class X, class Y>
T ExistingPatrons(T objectName, U patronTotal, V first, W last, X numID, Y ticketAmount){
    objectName[patronTotal].setFirstName(first);
    objectName[patronTotal].setLastName(last);
    objectName[patronTotal].setPatronNumber(numID);
    objectName[patronTotal].setNumTickets(ticketAmount);

    return objectName;
}


int main(int argc, char* argv[]){
    int userChoice, patronOpt;
    Patron* patrons = new Patron[300]; //dyn?
    int numPatron = 0;
    Patron patron ;
    if (argc > 1)
    {
        numPatron = readExistingPatrons(patrons, argv[1]);
    }
    else{
        printFileNotFound();
        return 1;
    }
    
    
    do{
        userChoice = getMenuOption();
        switch(userChoice){
            case 1:
                patron = createNewPatron();
                addPatron(patrons, patron, &numPatron);
                overwriteFile(patrons, argv[1], numPatron);
                break;
            case 2:
                patronOpt = getPatronOption(patrons, numPatron);
                removePatron(patrons, patronOpt-1, &numPatron);
                overwriteFile(patrons, argv[1], numPatron);
                break;
            case 3:
                cout << "Enter the number of the patron you'd like to modify." << endl;
                patronOpt = getPatronOption(patrons, numPatron);
                modifyPatron(&patrons[patronOpt-1]);
                break;
            case 4: 
                cout << "Enter the number of the patron you'd like to view." << endl;
                patronOpt = getPatronOption(patrons, numPatron);
                if(patronOpt <= numPatron){
                    cout << "First  Last ID Tickets" << endl;
                    patrons[patronOpt-1].displayPatronData();
                }
                else{
                    cout << "Invalid Input" << endl;
                }
                break;
            case 0:
                break;
            default:
                cout << "Invalid Input." << endl;
        }
    }while(userChoice != 0);

    return 0;
}

void overwriteFile(Patron patrons[], string fname, int numPatron){
    ofstream outputFile;
    string fName, lName;
    int patronNum, ticketNum;
    int totalPatron = 0;
    outputFile.open(fname);
    if(outputFile.is_open()){
       for(int i = 0; i < numPatron; i++){
            outputFile << GetPatronInfo(patrons, i);
            if(i != numPatron-1){
                outputFile << "\n";
            }
        }
    }
    else{
        printFileNotFound();
    }
}

void displayModOptions(){
    cout << "1. Add tickets" << endl;
    cout << "2. Purchase admittance to ride" << endl;
    cout << "3. Edit name" << endl;
    cout << "0. Exit to main menu" << endl;
}

void displayMenuOption(){
    cout << "1. Add Patron" << endl;
    cout << "2. Remove Patron" << endl;
    cout << "3. Modify Patron" << endl;
    cout << "4. View Patron" << endl;
    cout << "0. Exit" << endl;
}

void displayRideMenu(){
    cout << "Ride (TicketCost)" << endl;
    cout << "1. Teacups (3 tickets)" << endl; //alter to call ride object and get num tickets
    cout << "2. Magic Carpet (2 tickets)" << endl;
    cout << "3. World Tour (1 tickets)" << endl;
}
int getModOption(){
    int userChoice;
    displayModOptions();
    cin >> userChoice;
    return userChoice;
}

int getMenuOption(){
    int userChoice;
    displayMenuOption();
    cin >> userChoice;
    return userChoice;
}
int getPatronOption(Patron patrons[], int numPatrons){
    int userChoice;
    displayPatrons(patrons, numPatrons);
    cin >> userChoice;
    return userChoice;
}

void addTickets(Patron* patron){
    int numTickToAdd;
    double numTicketsForCalc;
    cout << "How many tickets would you like to add?" << endl;
    cin >> numTickToAdd;
    patron->setNumTickets(patron->getNumTickets() + numTickToAdd);
    numTicketsForCalc = patron->getNumTickets();
    

    char currencyInput;
    cout << "What currency would you like to pay with?\n";
    cout << "(D/d = dollars; A/a = Ariarys)\n";
    cin >> currencyInput;

    double currency;

    if(currencyInput == 'D' || currencyInput == 'd'){
        Dollars* costDollars;
        currency = costDollars->dollarAmount();
    }
    if(currencyInput == 'A' || currencyInput == 'a'){
        Ariarys* costAriarys;
        currency = costAriarys->ariaryAmount();
    }
    else{
        cout << "Invalid input\n";
    }

    Calculator<double> costCalculations;
    costCalculations.calculation(&currency, &numTicketsForCalc);

    cout << "How much would you like to pay?" << endl;
    cout << "cost: ";
    cout << costCalculations.calculation(&currency, &numTicketsForCalc);

    double payment;
    cin >> payment;
    costCalculations.setMoneyGiven(payment);
    
    costCalculations.calculation(costCalculations.getMoneyGiven());
    
    if(costCalculations.calculation(costCalculations.getMoneyGiven()) <= 0){
        cout << "No change returned.\n";
    }
    if(costCalculations.calculation(costCalculations.getMoneyGiven()) > 0){
        cout << "Change returned: "
             << costCalculations.calculation(costCalculations.getMoneyGiven());
        cout << endl;
    }

    

}

void addRide(Patron* patron){
    int userOpt, numTickets;
    cout << "Select the ride you'd like to add." << endl;
    displayRideMenu();
    cin >> userOpt;
    Ride* newRide;
    Teacups newTeacupsRide;
    MagicCarpet newMagicCarpetRide;
    WorldTour newWorldTourRide;
    switch(userOpt){
        case 1:
            *newRide = Teacups();
            numTickets = newTeacupsRide.numTicketsNecessary();
            break;
        case 2:
            *newRide = MagicCarpet();
            numTickets = newMagicCarpetRide.numTicketsNecessary();
            break;
        case 3:
            *newRide = WorldTour();
            numTickets = newWorldTourRide.numTicketsNecessary();
            break;
        default:
            cout << "Invalid Input." << endl;
    }
    numTickets = newRide->numTicketsNecessary();
    if(patron->getNumTickets() >= numTickets){
        patron->setNumTickets(patron->getNumTickets() - numTickets);
        patron->addPatronRide(newRide);
    }
    else{
        cout << "Patron does not have enough tickets. Do they want to purchase more tickets?" << endl;
        cout << "1. Yes" << endl;
        cout << "2. No" << endl;
        cin >> userOpt;
        if(userOpt == 1){
            addTickets(patron);
        }

    }
}
void editName(Patron* patron){
    int userChoice;
    string firstName, lastName;
    cout << "Would you like to edit the:\n1. first \n2. last  \n3. whole name" << endl;
    cin >> userChoice;
    switch(userChoice){
        case 1:
            cout << "Enter edited first name." << endl;
            cin >> firstName;
            patron->setFirstName(firstName);
            break;
        case 2:
            cout << "Enter edited last name." << endl;
            cin >> lastName;
            patron->setLastName(lastName);
            break;
        case 3:
            cout << "Enter edited first and last name." << endl;
            cin >> firstName >> lastName;
            NameSetters(patron, firstName, lastName);
        default:
            cout << "Invalid Entry" << endl;

    }
}


void displayPatrons(Patron patrons[], int numPatrons){
    for(int i = 0; i < numPatrons; i++){
        cout << i + 1 << ". ";
        patrons[i].displayName();
    }
}
Patron createNewPatron(){
    string first, last;
    char response;
    int numT, numP;
    int numRides = 0;
    cout << "Let's add a patron to the system!" << endl;
    cout << "Patron first and last name (Sara Davis): " << endl;
    cin >> first >> last;
    cout << "Patron idNumber (last 4 digits of phone number): " << endl;
    cin >> numP;
    cout << "How many tickets would they like to purchase? " << endl;
    cin >> numT;
    Ride* rides[numT];
    Patron newPatron(first, last, numP, numRides, numT, *rides);
    do{
        cout << "Would they like to purchase ride admittance now? (Y or N)" << endl; 
        cin >> response;
        addRide(&newPatron);
    }while(response != 'N' && response != 'n');

    return newPatron;
}
void addPatron(Patron patrons[], Patron newPatron, int* numPatrons){
    patrons[*numPatrons] = newPatron;
    (*numPatrons)++;
}
void removePatron(Patron patrons[], int optPatron, int* numPatrons){
    for(int i = 0; i <= *numPatrons; i++){
        if (i < optPatron){
            patrons[i] = patrons[i];
        }
        else if (i > optPatron){
            patrons[i-1] = patrons[i];
        }
    }
    (*numPatrons)--;
    
}
void modifyPatron(Patron* patron){
    int modOpt;
    do{
        modOpt = getModOption();
        switch(modOpt){
            case 1:
                addTickets(patron);
                break;
            case 2:
                addRide(patron);
                break;
            case 3:
                editName(patron);
                break;
            case 0:
                break;
            default:
                cout << "Invalid Input" << endl;
                break;
        }
    }while(modOpt != 0);

}

void printFileNotFound(){
    cout << "Patron File not found. Run the program again with the file name on the command line." <<endl;
}
int readExistingPatrons(Patron patrons[], string fname){
    ifstream inputFile;
    string fName, lName;
    int patronNum, ticketNum;
    int totalPatron = 0;
    inputFile.open(fname);
    if(inputFile.is_open()){
        while(inputFile.good()){
            inputFile >> fName >> lName >> patronNum >> ticketNum;
            ExistingPatrons(patrons, totalPatron, fName, lName, patronNum, ticketNum);
            totalPatron++;
        }
    }
    else{
        printFileNotFound();
        return -1;
    }
    return totalPatron;
}
