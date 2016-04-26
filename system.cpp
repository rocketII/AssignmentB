//Roderik Bauhn
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
    //on windows
	//system("cls");
    //on *nix systems
	system("clear");
	cout<<"//////////////////////////////////////////////////////////////////////////////////////";
	//windows hex escape characters for åäö.
    //\x84 = ä \x94 = ö, \x86 = å.
	cout<<"\nMusik Instrument hanterare 2016";
	cout<<"\n Tips: efter varje inmatning tryck p\x86 retur-,linefeed- eller radbrytningstangenten.\n";
	cout<<"A: Lägga till instrument.\n"
    <<"B: Presentera alla instrument.\n"
    <<"C: Presentera alla stränginstrument med all tillhörande information.\n"
    <<"D: Presentera alla blåsinstrument med all tillhörande information.\n"
    <<"E: Presentera alla stränginstrument vars strängantal ligger i ett givet intervall.\n"
    <<"F: Ändra antal strängar givet stränginstrumentets namn.\n"
    <<"G: Ta bort ett instrument.\n"
    <<"H: Exit.\n"
    <<endl;
}
//menu logic
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
			this->addInstrument();
			break;
		case 'B':
			this->toString_InstrumentData();
			break;
		case 'C':
			this->toString_StringInstruments();
			break;
		case 'D':
			this->toString_luftInstrument();
			break;
		case 'E':
			this->getStringInstrumentWithinIntervall();
			break;
		case 'F':
            this->findInstrumentChangeNrOfStrings();
			break;
		case 'G':
			this->rmPlayer();
			break;
		case 'H':
            flag = false;
			break;
		};
		fflush(stdin);
	} while (flag);
}
//A.
void System::addInstrument(void)
{
    char choice = ' ';
    cout <<"Press one key y för Sträng Instrument n för blås: "<<endl;
    choice = getchar();
    if(tolower(choice) == 'y')
    {
        this->addStringInstrument();
    }
    else if(tolower(choice) == 'n')
    {
        this->addAirInstrument();
    }
    else
    {
        cout <<"Fel indata"<<endl;
    }
}
//A.
void System::addStringInstrument(void)
{
	string namn;
	int nrOfStrings=0;
    bool knapp, bowStroke;
    char choice=' ';
    cin.ignore();
	cout <<"Namn?: ";
	getline(cin, namn);
	cout <<"Antal strängar?: ";
    cin >> nrOfStrings;
    cin.ignore();
	cout <<"str\x86ke?(y/n): ";
    cin >> choice;
    if(tolower(choice) == 'y')
    {
        bowStroke = true;
        knapp = !bowStroke;
        this->instance.nyttStrangInstrument(namn, nrOfStrings, knapp, bowStroke);
    }
    else if(tolower(choice)=='n')
    {
        bowStroke = false;
        knapp = !bowStroke;
        this->instance.nyttStrangInstrument(namn, nrOfStrings, knapp, bowStroke);
    }
    else
        cout << "fel indata!"<<endl;


}
//A.
void System::addAirInstrument(void)
{
    string namn;
    bool blackblas, trablas;
    char choice=' ';
    cout <<"Namn?: ";
    cin.ignore();
    getline(cin, namn);
    cout <<"träbl\x86s?(y/n): ";
    cin >> choice;
    cin.ignore();
    if(tolower(choice) == 'y')
    {
        trablas = true;
        blackblas = !trablas;
        this->instance.nyttLuftInstrument(namn, blackblas, trablas);
    }
    else if(tolower(choice)=='n')
    {
        trablas = false;
        blackblas = !trablas;
        this->instance.nyttLuftInstrument(namn, blackblas, trablas);
    }
    else
        cout << "fel indata!"<<endl;
}
//B.
void System::toString_InstrumentData(void)
{
    delete this->ptr;
    this->ptr= nullptr;
    if(this->getNrOfInstruments() == 0)
    {
        this->ptr = new string[1];
        this->ptr[0]="empty";
    }
    else
    {
        this->ptr = new string[this->getNrOfInstruments()];
        this->instance.AllaInstrument(ptr);
    }
    cout<<"--------------------------------";
    for (int i = 0; i < this->getNrOfInstruments() ; ++i)
    {
        cout << this->ptr[i];
    }
    delete[] this->ptr;
    this->ptr= nullptr;
}
//B.
int System::getNrOfInstruments(void)const
{
    return this->instance.antaletInstrument();
}
//C.
void System::toString_StringInstruments(void)
{
    delete this->ptr;
    this->ptr= nullptr;
    if(this->getNrOfInstruments() == 0)
    {
        this->ptr = new string[1];
        this->ptr[0]="empty";
    }
    else
    {
        this->ptr = new string[this->getNrOfStringInstruments()];
        this->instance.AllaStrangInstrument(ptr);
    }
    cout<<"--------------------------------";
    for (int i = 0; i < this->getNrOfStringInstruments(); ++i)
    {
        cout <<  this->ptr[i];
    }
    delete[] this->ptr;
    this->ptr = nullptr;
}
//C.
int System::getNrOfStringInstruments(void)const
{
    return this->instance.antalStrangInstrument();
}
//D.
void System::toString_luftInstrument(void)
{
    delete this->ptr;
    this->ptr= nullptr;
    if(this->getNrOfInstruments() == 0)
    {
        this->ptr = new string[1];
        this->ptr[0]="empty";
    }
    else
    {
        this->ptr = new string[this->getNrOfLuftInstrument()];
        this->instance.AllaLuftInstrument(ptr);
    }
    cout<<"--------------------------------";
    for (int i = 0; i < this->getNrOfLuftInstrument() ; ++i)
    {
        cout << this->ptr[i];
    }
    delete[] this->ptr;
    this->ptr= nullptr;
}
//D.
int System::getNrOfLuftInstrument(void)const
{
    return this->instance.antalLuftInstrument();
}
//E.
void System::getStringInstrumentWithinIntervall(void)
{
    int min, max;
    cout<<"\nAnge minsta stråke följt av retur:";
    cin >> min >> max;
    cout << this->instance.AllstrangInstrumentInIntervall(min, max);
}
//F.
void System::findInstrumentChangeNrOfStrings(void)
{
    string namnA;
    int strings;
    cout<<"\n Instrument namn: ";
    getline(cin, namnA);
    cout<<"\n Instruments nya antal strängar: ";
    cin >> strings;
    this->instance.changeNrOfStrings(strings, namnA);
}
//G.
void System::rmPlayer(void)
{
    string namn;
    cout <<"Namn?: ";
    getline(cin, namn);
    this->instance.rmInstrument(namn);
}



