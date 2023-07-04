#include <iostream>
#include <cstring>
#include <cctype>
#include <stdio.h>
#include <Windows.h>
#include <iostream>
#include <conio.h>
#include <cstdio>
#include <ctime>
#include <Windows.h>
#include<fstream>
#include<iomanip>


using namespace std;
int myarr=0;
string mydata[50][5];
int point=0;	
void gotoXY(int x, int y); 
void timer();
void write_student();	//write the record in binary file
void firstscreen();
void quiz();
void info();
void display_all();	//read all records from binary file
void class_result();	//display all records in tabular format from binary file
void result();		//display result menu
double duration;
double maxtime=60;
	string comm;
enum color{ //enumeration is a user-defined data type
	NONE,
	DARK_BLUE,
	GREEN,
	DARK_CYAN,
	DARK_RED,
	PURPLE,
	DARK_YELLOW,
	NORMAL,
	GRAY,
	BLUE,
	LIME,
	CYAN,
	RED,
	PINK,
	YELLOW,
	WHITE
};
void setcolor   (color newColor);

struct question
{
  	string ques;
  	string ans1;
	string ans2;
	string ans3;
	string ans4;
	char ans;
};

int main(){
	char name;
		cout.setf(ios::fixed|ios::showpoint);
		cout<<setprecision(2); // program outputs decimal number to two decimal places
		firstscreen();
		
		_getch();
		system("cls");
	
	

return 0;
}

class student
{
	int rollno;
	char name[50];
	
	int obt;
	double per;
	char grade;
	
	void calculate();	//function to calculate grade
		void Result();
public:
	void getdata();		//function to accept data from user
	void showdata() const;	//function to show data on screen
	void show_tabular() const;
}; //class ends here
void student::calculate()
{
	per=point/5*10;
	
	if(per>=80)
	{
		grade='A';
		comm="Excellent";
		}	
	else if(per>=60)
		{
			grade='B';
			comm="Good";
		}
		
	else if(per>=40)
		{
			grade='C';
			comm="Fair";
		}
	else
		{
			grade='F';
			comm="Fail Do hard work..";
		}
}

void student::getdata()
{	
	point=0;
	cout<<"\nEnter The roll number of student ";
	cin>>rollno;
	cout<<"\n\nEnter The Name of student ";
	cin.ignore();
	cin.getline(name,50);
	system("cls");
	quiz();	
	obt=point;
	
	calculate();
	system("cls");
	Result();
}

void student::showdata() const
{
	cout<<"\nRoll number of student : "<<rollno;
	cout<<"\nName of student : "<<name;
}

void student::show_tabular() const
{
	cout<<rollno<<setw(15)<<name<<setw(10)<<obt<<setw(10)<<per<<setw(6)<<grade<<endl;
	myarr++;
}

void ebod()
{
 			
			for(int x = 20; x < 103; x++){
			setcolor(CYAN);
			gotoXY(x,4);	
			cout<<char(205);
			}
			for(int x = 20; x < 103; x++){
			setcolor(PURPLE);
			gotoXY(x,12);	
			cout<<char(205);
			}

			for(int x = 5; x < 12; x++){
			setcolor(CYAN);
			gotoXY(20,x);	
			cout<<char(186);
			}
			for(int x = 5; x < 12; x++){
			setcolor(CYAN);
			gotoXY(103,x);	
			cout<<char(186);
			}
			setcolor(CYAN);

			gotoXY(20,4);	
			cout<<char(201);
			gotoXY(103,4);	
			cout<<char(187);
			gotoXY(103,12);	
			cout<<char(188);
			gotoXY(20,12);	
			cout<<char(200);

}
void gotoXY(int x, int y) 	//function to decide location of the screem
{
	//A "handle" is a generic identifier (typically a pointer) used to represent something
	//Retrieves a handle to the specified standard device (standard input, standard output).
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); 		 
	COORD CursorPosition; 
	CursorPosition.X = x; // Locates column
	CursorPosition.Y = y; // Locates Row
	//Sets the cursor position in the specified console screen buffer.
	//A COORD structure that specifies the new cursor position, in characters. The coordinates are 
	//the column and row of a screen buffer character cell. The coordinates must be within the 
	//boundaries of the console screen buffer.
	SetConsoleCursorPosition(console,CursorPosition); // Sets position for next thing to be printed 
}
void info()
{
	setcolor(RED);
	gotoXY(56,4);	
		cout<<"Instruction"<<endl;
	setcolor(GREEN);
	gotoXY(50,5);	
		cout<<"Press Enter to Home Menu"<<endl;
	
		setcolor(LIME);
		gotoXY(38,6);	
		cout<<"   ________________________________________"<<endl;
		gotoXY(38,7);
		cout<<" / \\                             	         \\."<<endl;
		gotoXY(38,8);
		cout<<"|   |                                      |."<<endl;
		gotoXY(38,9);
		cout<<" \\_ | Select==>                            |."<<endl;
		gotoXY(38,10);
		cout<<"    | Press only Valid Opton--> (a,b,c,d)  |."<<endl;
		gotoXY(38,11);
		cout<<"    | if u Press Other key consider wrong  |."<<endl;
		gotoXY(38,12);
		cout<<"    | answer.                              |."<<endl;
		gotoXY(38,13);
		cout<<"    |                            	   	 |."<<endl;
		gotoXY(38,14);
		cout<<"    | Skip==>                              |."<<endl;
		gotoXY(38,15);
		cout<<"    | Press Enter to Skip the Question     |."<<endl;
		gotoXY(38,16);
		cout<<"    |                            	         |."<<endl;
		gotoXY(38,17);
		cout<<"    | Points==>                            |."<<endl;
		gotoXY(38,18);
		cout<<"    | 10 Point will be awarded for each    |."<<endl;
		gotoXY(38,19);
		cout<<"    | correct answer.                      |."<<endl;
		gotoXY(38,20);
		cout<<"    |                                      |."<<endl;
		gotoXY(38,21);
		cout<<"    | Time==>                              |."<<endl;
		gotoXY(38,22);
		cout<<"    | Team will be given 60 seconds for    |."<<endl;
		gotoXY(38,23);
		cout<<"    | each question.                       |."<<endl;
		gotoXY(38,24);
		cout<<"    |                            	         |."<<endl;
		gotoXY(38,25);
		cout<<"    | Identification==>                    |."<<endl;
		gotoXY(38,26);
		cout<<"    | Enter Roll Number and Name for Recod |."<<endl;
		gotoXY(38,27);
		cout<<"    | save                          	 |."<<endl;
		gotoXY(38,28);
		cout<<"    |   ___________________________________|___"<<endl;
		gotoXY(38,29);
		cout<<"    |  /                                      /."<<endl;
		gotoXY(38,30);
		cout<<"    \\_/______________________________________/."<<endl;
	
}


void student::Result()
{
	int f=30;
	setcolor(RED);
	gotoXY(0,3);
	cout<<"  _____                 _ _   "<<endl;
	gotoXY(0,4);
	cout<<" |  __ \\               | | |  "<<endl;
	gotoXY(0,5);
	cout<<" | |__) |___  ___ _   _| | |_ "<<endl;
	gotoXY(0,6);
	cout<<" |  _  // _ \\/ __| | | | | __|"<<endl;
	gotoXY(0,7);
	cout<<" | | \\ \\  __/\\__ \\ |_| | | |_ "<<endl;
	gotoXY(0,8);
	cout<<" |_|  \\_\\___||___/\\__,_|_|\\__|"<<endl;
	
	setcolor(YELLOW);
gotoXY(f,1);
cout<<"                     ,---.           ,---.   "<<endl;
gotoXY(f,2);
cout<<"                    / /^`.\\.--''''-./,'^\\ \\	"<<endl;
gotoXY(f,3);
cout<<"                    \\ \\    _       _    / /	"<<endl;
gotoXY(f,4);
cout<<"                     `./  / __   __ \\  \\,'	"<<endl;
gotoXY(f,5);
cout<<"                      /    /_O)_(_O\\    \\	"<<endl;
gotoXY(f,6);
cout<<"                      |  .-'  ___  `-.  |	"<<endl;
gotoXY(f,7);
cout<<"                   .--|       \\_/       |--.	"<<endl;
gotoXY(f,8);
cout<<"                 ,'    \\   \\   |   /   /    `."<<endl;
gotoXY(f,9);
cout<<"                /       `.  `--^--'  ,'       \\"<<endl;
gotoXY(f,10);
cout<<"             .-^^^^^-.    `--.___.--'     .-^^^^^-."<<endl;
gotoXY(f,11);
cout<<".-----------/         \\------------------/         \\--------------."<<endl;
gotoXY(f,12);
cout<<"| .---------\\         /----------------- \\         /------------. |"<<endl;
gotoXY(f,13);
cout<<"| |          `-`--`--'                    `--'--'-'             | |"<<endl;
gotoXY(f,14);
cout<<"| |                                                             | |"<<endl;
gotoXY(f,15);
cout<<"| |                                                             | |"<<endl;
gotoXY(f,16);
cout<<"| |                                                             | |"<<endl;
gotoXY(f,17);
cout<<"| |                                                             | |"<<endl;
gotoXY(f,18);
cout<<"| |_____________________________________________________________| |"<<endl;
gotoXY(f,19);
cout<<"|_________________________________________________________________|"<<endl;
gotoXY(f,20);
cout<<"                   )__________|__|__________("<<endl;
gotoXY(f,21);
cout<<"                  |            ||            |"<<endl;
gotoXY(f,22);
cout<<"                  |____________||____________|"<<endl;
gotoXY(f,23);
cout<<"                    ),-----.(      ),-----.("<<endl;
gotoXY(f,24);
cout<<"                  ,'   ==.   \\    /  .==    `."<<endl;
gotoXY(f,25);
cout<<"                 /            )  (            \\"<<endl;
gotoXY(f,26);
cout<<"                 `==========='    `==========='  "<<endl;
	setcolor(CYAN);
	gotoXY(35,14);
	cout<<"Name ==>"<<name;
	setcolor(CYAN);
	gotoXY(70,14);
	cout<<"Roll No ==> "<<rollno;
	setcolor(CYAN);
	gotoXY(35,15);
	cout<<"Total Score ==> 50";
	gotoXY(70,15);
	cout<<"Your Score ==> "<<point;
	setcolor(CYAN);
	gotoXY(35,16);
	cout<<"Percentage ==> "<<per;
	gotoXY(70,16);
	cout<<"Grade ==> "<<grade;
	setcolor(CYAN);
	gotoXY(35,17);
	cout<<"Comments==> "<<comm;
_getch();
	
}

void Borders() 
{
	{

		for(int x = 2; x < 70; x++){
		setcolor(DARK_CYAN);

		//setcolor(WHITE);
		gotoXY(x,1);	
		cout<<char(205);
		}

		Beep(200, 25);
		gotoXY(135,1);	
		cout<<char(187);		
		for(int y = 2; y < 50; y++){
		gotoXY(135,y);	
		cout<<char(186);
		}

		Beep(300, 25);
		gotoXY(135,50);	
		cout<<char(188);		
		for(int x = 134; x > 1; x--){
		gotoXY(x,50);	
		cout<<char(205);			
		}

		Beep(400, 25);

		gotoXY(1,50);	
		cout<<char(200);		
		for(int y = 49; y > 1; y--){
		gotoXY(1,y);	
		cout<<char(186);		
		}
		gotoXY(1,1);	
		cout<<char(201);		
		Beep(500, 25);
	}
}
void setcolor   (color newColor) 
{
	//A "handle" is a generic identifier (typically a pointer) used to represent something.
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), (newColor ) );
}


void quiz()
{
	
	std::clock_t start;
    start = std::clock();	

	char a,b,e;
    int t=0;
	int i=0;
	int right=0;
	int wrong=0;
	char answer;
	struct question abc[6];
	int srno=0;
	

	abc[0] = {"Which of the following is not the characteristic of a class?","Generic","Friend","Inline","Inline",'c'};
	abc[1] = {"Which of the following statements is most suitable for the C++ language?","Statically typed language.","Dynamically typed language.","All","Type-less language.",'a'};
	abc[2] = {"Which of the following operators doesn�t allow overloading?","Comparison operator.","Assignment operator.","Scope resolution operator.","Dereference operator.",'c'};
	abc[3] = {"Which of the following isn�t supported in C++ language?","Namespaces.","Inheritance","Reflection.","Polymorphism.",'c'};
	abc[4] = {"Which of the following keywords can�t appear inside a class definition?","template","static","virtual","friend",'a'};

	do {
		duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
			setcolor(RED);			
			gotoXY(69,3);
			cout << maxtime-duration << endl;
		if (duration>=maxtime) {
			t=0;
			break;
		}

		if (srno==i) {
			system("cls");

			srno++;
			b=' ';
			e=' ';
			answer=abc[i].ans;

			ebod();
			for(int x = 12; x < 16; x++){
			setcolor(CYAN);
			gotoXY(20,x);	
			cout<<char(186);
			}
			for(int x = 20; x < 103; x++){
			setcolor(CYAN);
			gotoXY(x,16);	
			cout<<char(205);
			}
			for(int x = 12; x < 16; x++){
			setcolor(CYAN);
			gotoXY(103,x);	
			cout<<char(186);
			}


			setcolor(CYAN);
			gotoXY(103,16);	
			cout<<char(188);
			gotoXY(20,16);	
			cout<<char(200);

			int col=23;
			setcolor(BLUE);
			gotoXY(23,5);
			
			cout << "Question "<<srno<<") " <<endl;
			gotoXY(23,6);cout<< abc[i].ques<< endl;
	  		gotoXY(col,8);
			setcolor(DARK_YELLOW);
			cout <<" a - " << abc[i].ans1<< endl;
	  		gotoXY(col,9);
			cout <<" b - " << abc[i].ans2<< endl;
	  		gotoXY(col,10);
			cout << " c - " << abc[i].ans3<< endl;
	  		gotoXY(col,11);
			cout << " d - " << abc[i].ans4<< endl;
			gotoXY(45,13);		
			cout << " Press Enter to skip ";
			gotoXY(45,14);		
			cout << " Select your Option ==> ";
			setcolor(YELLOW);
			gotoXY(45,3);		
			cout << " Your Remaning Time ==> ";

		}

		if(_kbhit()){
			setcolor(YELLOW);
			gotoXY(70,14);
			a=_getch();
			//cin>>a;
			cout<<a;

			if(int(a)==13){

					gotoXY(30,18);
					setcolor(RED);
				cout << "You skipped this Question";
			} else {
				if(a==answer){
					gotoXY(62,18);
					setcolor(LIME);
					point=point+10;
					cout << "Congratulation You selected right option";
				} else {
					gotoXY(70,18);
					setcolor(GREEN);
					cout << "Correct Option is  ==> "<<answer;
					gotoXY(30,18);
					setcolor(RED);
					cout << "You selected wrong option.";

				}
			}
			_getch();
			i++;
		} 
	} while (i<5);
	
	if (i<4) {
		cout<<"\nTime is up. You failed to attempt all questions"<<endl;
	} 
		        
	_getch();
}
void write_student()
{
	student st;
	ofstream outFile;
	outFile.open("nauzer.dat",ios::binary|ios::app);
	st.getdata();
	outFile.write(reinterpret_cast<char *> (&st), sizeof(student));
	outFile.close();
    //	cout<<"\n\nStudent record Has Been Created ";
	//cin.ignore();
	cin.get();
}

//***************************************************************
//    	function to read all records from file
//****************************************************************

void display_all()
{
	student st;
	ifstream inFile;
	inFile.open("nauzer.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}
	cout<<"\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n";
	while(inFile.read(reinterpret_cast<char *> (&st), sizeof(student)))
	{
		st.showdata();
		cout<<"\n\n====================================\n";
	}
	inFile.close();
	cin.ignore();
	cin.get();
}


//***************************************************************
//    	function to display all students grade report
//****************************************************************

void class_result()
{
	student st;
	ifstream inFile;

	inFile.open("nauzer.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();

		cin.get();
		return;
	}

	cout<<"\n\n\t\tALL STUDENTS RESULT \n";
	cout<<"\n\t\tPress Enter to Go Back Home Screen\n";
	cout<<"==========================================================\n";
	cout<<"R.No          Name      Points     %      Grade"<<endl;
	cout<<"==========================================================\n";
	while(inFile.read(reinterpret_cast<char *> (&st), sizeof(student)))
	{
		st.show_tabular();
	}
	cin.ignore();
	cin.get();
	inFile.close();
}

//***************************************************************
//    	function to display result menu
//****************************************************************



void firstscreen()		//simply desgin screen
{

	doo :
	system("CLS");		
						setcolor(NORMAL);
			cout<<"\n\n\n\t\t\t\t   __      __   ___  | |   ___    ___    _ __ ___     ___  "<<endl;
			cout<<"\t\t\t\t   \\ \\ /\\ / /  / _ \\ | |  / __|  / _ \\  | '_ ` _ \\   / _ \\ "<<endl;
			cout<<"\t\t\t\t    \\ V  V /  |  __/ | | | (__  | (_) | | | | | | | |  __/ "<<endl;
			cout<<"\t\t\t\t     \\_/\\_/    \\___| |_|  \\___|  \\___/  |_| |_| |_|  \\___| "<<endl;
	setcolor(GREEN);
	gotoXY(50,20);
	cout<<" >>";
	gotoXY(74,20);
	cout<<" >>";
	gotoXY(54,20);
	setcolor(WHITE);
	cout<<"Press Enter Continue";
	Beep(500, 100);
	gotoXY(45,10);
	cout<<"======Select Following Option ======";
	gotoXY(50,12);
	cout<<"1-->  New Game";
	gotoXY(50,13);
	cout<<"2-->  Instructions";
	gotoXY(50,14);
	cout<<"3-->  Result Record";  
	gotoXY(42,16);
	cout<<"Select : ";    
	Beep(500, 100);
	go:                                     
	int type;
	gotoXY(51,16);
	cin>>type;	
	switch(type)
	{
		case 1:
			{
						system("CLS");
			
			system("COlOR 3f");
			write_student();	
			break;
			}
	case 2:
			{
			system("CLS");
	
			info();
			_getch();
			goto doo;
			break;
			}
			case 3:
			{
			system("CLS");		
				setcolor(GREEN);
			class_result();
			
			system("CLS");
			goto doo;
			break;
			}

		 default:
			
			cout<<"/n INVALID CHOICE";
			_getch();
			goto go;
	}
	//system("CLS");
		
}
