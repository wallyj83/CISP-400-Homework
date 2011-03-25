    //
/*
 11. Inventory Program
 Write a program that uses a class to store 
 the following inventory data in a file:
 
 Item description
 Quantity on hand
 Wholesale cost
 Retail cost
 Date added to inventory
 The program should have a menu that allows 
 the user to perform the following tasks:
 
 • Add new records to the file.
 • Display any record in the file.
 • Change any record in the file.
 
 Input Validation: The program should not 
 accept quantities, or wholesale or retail 
 costs less than 0. The program should not 
 accept dates that the programmer 
 determines are unreasonable.
 
 
 */
#include	<iomanip>
#include 	<iostream>
#include 	<vector>
#include 	<string>
using namespace std;

class inventory
{
private:
    string itemDesc;
    int itemQuant, itemNum;
    float itemRcost, itemWcost;
    short int itemDay, itemMonth, itemYear;
    
public:
    inventory()
    {
    itemDesc='\0';
    itemDay = 0;
    itemNum = 0;
    itemMonth=0;
    itemYear = 0;
    itemQuant=0;
    itemRcost=0;
    itemWcost=0;
    }
    void addItem(string a, int b, float c, float d, short int e, short int f, short int g, int h)
    {
    itemDesc =a;
    itemQuant=b;
    itemWcost=c;
    itemRcost=d;
    itemDay = e;
    itemMonth=f;
    itemYear=g;
    itemNum=h;
    
    }
    void setItemDesc(string a){itemDesc=a;}
    void setItemQuant(int b){itemQuant=b;}
    void setItemWcost(float c){itemWcost = c;}
    void setItemRcost(float d){itemRcost = d;}
    void setItemDay(short int e){itemDay = e;}
    void setItemMonth(short int f){itemMonth=f;}
    void setItemYear(short int g){itemYear = g;}
    short int getItemMonth(){short int e=itemDay; return e;}
    short int getItemDay(){short int f=itemMonth; return f;}
    short int getItemYear(){short g=itemYear; return g;}
    void Cout()
    {
    cout<<"Item description:        "<<itemDesc <<endl;
    cout<<"Quantity on hand:        "<<itemQuant<<endl;
    cout<<"Wholesale Cost:          "<<itemWcost<<endl;
    cout<<"Retail Cost:             "<<itemRcost<<endl;
    cout<<"Date added to inventory: "<<itemMonth<<"/"<<itemDay<<"/"<<itemYear<<endl;
    cout<<"Item numer:              "<<itemNum<<endl;
    }
};

char * Strchcpy(char *, char * , int);
bool checkamount(float);
bool itemvalidDate(string, long);
void checkDate(string, long);
void displayItem();
void editItem();
void allItem();
void addRec();
void showmenu();
void showmenu1();
void flush();
void clear();

vector<inventory> items(1);

int main()
{
	items[0].addItem("The first Item",4,25.30,28.25,23,7,1981,1);
    char choice;
    flush();
    cout<<"Please select from the following options"<<endl;
    showmenu();
	cin >> choice;
	flush();
	while (choice != '5')
        {
    	clear();
      	if(choice== '1') addRec();
        else
            if(choice== '2') displayItem();
            else          
                if(choice== '3')editItem();
                else       
                    if(choice== '4')allItem();
                    else
                        cout << "That's not a choice."<<endl;
        
        showmenu();
        cin>>choice;flush();
        }
    cout << "Bye!\n";
	return 0;    
}

void flush()
{
	char ch;
	while ( ch=cin.get()!= '\n');
}

void Clear()
{
    system("clear");
  
}

void showmenu()
{
    cout << "Please enter 1, 2, 3, 4, or 5:"<<endl<<
    "1) Add record				2) Display record"<<endl<<
    "3) Update record		        4) Show All"<<endl<<
    "5) quit"<<endl;
}

void showmenu1()
{
    cout << "Please slect wich field to edit:"<<endl<<
    "1) Item Description		2) Quantity on hand"<<endl<<
    "3) Wholesale Cost			4) Retail Cost"<<endl<<
    "5) Date added to inventory	6) Return"<<endl<<endl;
    
}

void addRec()
{
    long vecsize;
    int itemNumtemp;
    string a, b;
    int c;
    float e, f;
    
    vecsize=items.size();
    itemNumtemp = (int)vecsize+1;
    items.push_back(inventory());
    cout << "Please enter the Items Description" <<endl;
    cout <<": ";
    getline(cin, a);
    cout << "Please Enter the Quantity on hand" <<endl;
    cout <<": ";
    cin	>> c;
    cout << "Please Enter the Wholesale cost" <<endl;
    cout <<": ";
    cin >>e;
    if(checkamount(e))
        {
        cout << "Please enter a positive amount" << endl;
        cout << ": ";
        cin>>e;
        }
    cout <<"Please Enter the Retail Cost" << endl;
    cin >>f;
    checkamount(f);
    if(checkamount(f))
        {
        cout << "Please enter a positive amount" << endl;
        cout << ": ";
        cin >> f;
        }
    
    cout<<"Please enter the date added to inventory(dd/MM/YY)"<<endl;
    cout<<": ";
    cin >> b;
    if(itemvalidDate(b, vecsize))
        {
        }
    
    else
        {
        cout<<"That is not a valid date, please enter a valid date (dd/MM/YY)"<<endl;
        cout<<": "<<endl;
        cin >> b;
        }
    
    
}

void checkDate(string b, long vecsize)
{
    
    char month[3],
    day[3],
    year[3];
  	char * ch_ptr;
    
    
	ch_ptr = new char [b.size()+1];
    
	strcpy (ch_ptr, b.c_str());
    
    ch_ptr = Strchcpy(month, ch_ptr, '/');
    ++ch_ptr;
    ch_ptr = Strchcpy(day, ch_ptr, '/');
    ++ch_ptr;
    Strchcpy(year, ch_ptr, '\0');
    
    items[vecsize].setItemDay(atoi(day));
    items[vecsize].setItemMonth(atoi(month));
    items[vecsize].setItemYear(atoi(year));
    
}

char * Strchcpy(char * target, char * source, int ch)
{
    while (*source != ch && *source != '\0')
        {
        *target = *source;
        ++target;
        ++source;
        }
    
    *target = '\0';
    
    return source;
    
}

bool  itemvalidDate(string b, long vecsize)
{
    checkDate(b, vecsize);
    short int tempMonth, tempDay, tempYear;
    tempMonth =items[vecsize].getItemMonth();
    tempDay = items[vecsize].getItemDay();
    tempYear =items[vecsize].getItemYear();
    
    int ny_days [13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int ly_days [13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (tempMonth > 0 && tempMonth < 13)
        if (tempDay > 0 && tempDay < 32 )
            if (tempYear < 80)
                if (tempYear % 4 == 0)
                    {
                    if (tempDay <= ly_days[tempMonth])
                        return 1;
                    }
                else 
                    {
                    if (tempDay <= ny_days[tempMonth])
                        return 1;
                    }
    
            	else
                    return 0;
                else 
                    return 0;
                else 
                    return 0;
    
}

bool checkamount(float a)
{
    if(a>= 0)
        {
        return 0;
        }
    else
        {
        return 1;
        }
}

void displayItem()
{
    int tempNum;
    cout<<"Please enter the item number that you would like to display"<<endl;
    cin >> tempNum;
    tempNum=tempNum-1;
    items[tempNum].Cout();
    
}