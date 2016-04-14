#include "system.h"


System::System(void)
{
	this->ptr=new string("maoh");
}


System::~System(void)
{
	delete[] this->ptr;
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
	cout<<"A: Lägga till en motionär.\n"
<<"B: Lägga till en professionell deltagare.\n"
<<"C: Erhåll Samtliga tävlingsdeltagare.\n"
<<"D: Inlagda tävlingsdeltagare.\n"
<<"E: Endast professionella deltagare.\n"
<<"F: Erhåll antalet inlagda professionella deltagare.\n"
<<"G: Endast motionärer.\n"
<<"H: Erhålla antalet inlagda motionärer.\n"
<<"I: Ta bort en tävlingsdeltagare givet namnet.\n"
<<"J: Ändra antal säsonger som professionell för en given professionell deltagare.\n"
<<"K: Sortera alla tävlingsdeltagare baserat på namnet.\n"
<<"L: Exit.\n "<<endl;
}
void System::menu(void){
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
			this->getNrOfPlayers();
			break;
		case 'E':
			this->toString_proPlayers();
			break;
		case 'F':
			this->getNrOfProPlayers();
			break;
		case 'G':
			this->toString_motionarPlayers();
			break;
		case 'H':
			this->getNrOfMotionarer();
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

void System::addMotionar(void)const
{
	string namn, gender;
	int age=0;
	cout <<"Namn?: ";
	getline(cin, namn);
	cout <<"Kön?: ";
	getline(cin, gender);
	cout <<"ålder?: ";
	cin >> age;
	this->instance.nyMotionarDeltagare(namn, gender ,age);
}
void System::addProffs(void)const
{
    string namn, gender, klubb;
    int yearInService=0;
    cout <<"Namn?: ";
    getline(cin, namn);
    cout <<"Kön?: ";
    getline(cin, gender);
    cout <<"Klubb?: ";
    getline(cin, klubb);
    cout <<"År som proffs?: ";
    cin >> yearInService;
    this->instance.nyProfessionellDeltagare(namn, gender, klubb, yearInService);
}
void System::toString_registerData(void)
{
    string *ptr= nullptr;
    if(this->getNrOfPlayers() == 0)
    {
        ptr = new string[1];
        ptr[0]="empty";
    }
    else
    {
        ptr = new string[this->getNrOfPlayers()];
        this->instance.AllaDeltagare(ptr);
    }
    cout<<"--------------------------------";
    for (int i = 0; i < this->getNrOfPlayers() ; ++i)
    {
        ptr[i];
    }
    delete[] ptr;
}
int System::getNrOfPlayers(void)const
{
    return this->instance.antaletDeltagare();
}
void System::toString_proPlayers(void)const
{

}
int System::getNrOfProPlayers(void)const
{
    return this->instance.antalProffs();
}
void System::toString_motionarPlayers(void)const{}
int System::getNrOfMotionarer(void)const
{
    return this->instance.antalMotionarer();
}
void System::rmPlayer(void)const
{
    string namn;
    cout <<"Namn?: ";
    getline(cin, namn);
    this->instance.rmDeltagare(namn);
}
void System::changeProPlayerYearInService(void)const{}
void System::sortPlayersByNames(void)const{}

