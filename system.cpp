#include "system.h"


System::System(void)
{
	this->ptr=new string("maoh");
}


System::~System(void)
{
	delete this->ptr;
}
void System::menutxt(void)const
{
	
	cout<<"\n!!![Tryck Retur tangent(d.v.s. radbrytning)]!!!";
	getchar();
	//system("cls");
	system("clear");
	cout<<"//////////////////////////////////////////////////////////////////////////////////////";
	//\x84 = ä \x94 = ö, \x86 = å.
	cout<<"\nDeltagar hanterare 2016";
	cout<<"\n Tips: efter varje inmatning tryck p\x86 retur-,linefeed- eller radbrytningstangenten.\n";
	cout<<"A: L\x84gga till en motion\x84r.\n"
    <<"B: L\x84gga till en professionell deltagare.\n"
    <<"C: Erh\x86ll Samtliga t\x84vlingsdeltagare.\n"
    <<"D: Inlagda t\x84vlingsdeltagare.\n"
    <<"E: Endast professionella deltagare.\n"
    <<"F: Erh\x86ll antalet inlagda professionella deltagare.\n"
    <<"G: Endast motion\x84rer.\n"
    <<"H: Erh\x86lla antalet inlagda motion\x84rer.\n"
    <<"I: Ta bort en t\x84vlingsdeltagare givet namnet.\n"
    <<"J: \x84ndra antal s\x84songer som professionell f\x94r en given professionell deltagare.\n"
    <<"K: Sortera alla t\x84vlingsdeltagare baserat p\x86 namnet.\n"
    <<"L: Exit.\n "<<endl;
}
void System::menu(void)
{
	bool flag = true;
    char choice;
	
	do
	{
		menutxt();
		cout<<"\nV\x84LJ EN BOKSTAV: "<<endl;
		cin >> choice;
		cin.ignore();
		switch(toupper(choice))
		{
		case 'A':
			this->addMotionar();
			break;
		case 'B':
			this->addProffs();
			break;
		case 'C':
			this->toString_registerData();
			break;
		case 'D':
			cout << this->getNrOfPlayers();
			break;
		case 'E':
			this->toString_proPlayers();
			break;
		case 'F':
			cout << this->getNrOfProPlayers();
			break;
		case 'G':
			this->toString_motionarPlayers();
			break;
		case 'H':
			cout << this->getNrOfMotionarer()+1;
			break;
		case 'I':
			this->rmPlayer();
			break;
		case 'j':
			this->changeProPlayerYearInService();
			break;
		case 'K':
			this->sortPlayersByNames();
			break;
		case 'L':
			flag = false;
			break;
		};
		fflush(stdin);
	} while (flag == true);
}

void System::addMotionar(void)
{
	string namn, gender;
	int age=0;
	cout <<"Namn?: ";
	getline(cin, namn);
	cout <<"K\x94n?: ";
	getline(cin, gender);
	cout <<"\x86lder?: ";
	cin >> age;
	this->instance.nyMotionarDeltagare(namn, gender ,age);
}
void System::addProffs(void)
{
    string namn, gender, klubb;
    int yearInService=0;
    cout <<"Namn?: ";
    getline(cin, namn);
    cout <<"K\x94n?: ";
    getline(cin, gender);
    cout <<"Klubb?: ";
    getline(cin, klubb);
    cout <<"\x86r som proffs?: ";
    cin >> yearInService;
    this->instance.nyProfessionellDeltagare(namn, gender, klubb, yearInService);
}
void System::toString_registerData(void)
{
    delete this->ptr;
    this->ptr= nullptr;
    if(this->getNrOfPlayers() == 0)
    {
        this->ptr = new string[1];
        this->ptr[0]="empty";
    }
    else
    {
        this->ptr = new string[this->getNrOfPlayers()];
        this->instance.AllaDeltagare(ptr);
    }
    cout<<"--------------------------------";
    for (int i = 0; i < this->getNrOfPlayers() ; ++i)
    {
        cout << this->ptr[i];
    }
    delete[] this->ptr;
    this->ptr= nullptr;
}
int System::getNrOfPlayers(void)const
{
    return this->instance.antaletDeltagare();
}
void System::toString_proPlayers(void)
{
    delete this->ptr;
    this->ptr= nullptr;
    if(this->getNrOfPlayers() == 0)
    {
        this->ptr = new string[1];
        this->ptr[0]="empty";
    }
    else
    {
        this->ptr = new string[this->getNrOfProPlayers()];
        this->instance.AllaProffs(ptr);
    }
    cout<<"--------------------------------";
    for (int i = 0; i < this->getNrOfProPlayers() ; ++i)
    {
        cout << this->ptr[i];
    }
    delete[] this->ptr;
    this->ptr= nullptr;
}
int System::getNrOfProPlayers(void)const
{
    return this->instance.antalProffs();
}
void System::toString_motionarPlayers(void)
{
    delete this->ptr;
    this->ptr= nullptr;
    if(this->getNrOfPlayers() == 0)
    {
        this->ptr = new string[1];
        this->ptr[0]="empty";
    }
    else
    {
        this->ptr = new string[this->getNrOfPlayers()];
        this->instance.AllaDeltagare(ptr);
    }
    cout<<"--------------------------------";
    for (int i = 0; i < this->getNrOfPlayers() ; ++i)
    {
       cout <<  this->ptr[i];
    }
    delete[] this->ptr;
    this->ptr = nullptr;
}
int System::getNrOfMotionarer(void)const
{
    return this->instance.antalMotionarer();
}
void System::rmPlayer(void)
{
    string namn;
    cout <<"Namn?: ";
    getline(cin, namn);
    this->instance.rmDeltagare(namn);
}
void System::changeProPlayerYearInService(void)
{
    string namnDelta;
    int yearInService=-1;
    int change=-1;
    cout <<"Namn: ";
    getline(cin, namnDelta);
    cout <<"\x84ndra med x \x86r?\nx= ";
    cin >> yearInService;
    this->instance.setProffsActiveYears(yearInService, namnDelta);
}
void System::sortPlayersByNames(void)
{
    this->instance.sortingByNames();
}

