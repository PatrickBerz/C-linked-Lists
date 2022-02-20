//Patrick Berzins
//Linked lists practice


#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

struct employee_data
{
	string firstname;
	string lastname;
	char initial;
	unsigned int ID;
	double hours;
	double wage;
	double pay;
	employee_data *link;   
};

void enter_data(employee_data &person);
void print_data(employee_data &person);
ifstream infile;
int main(void)
{
	
	infile.open("C:/Users/Patri/OneDrive/Documents/CS_Data_Files/Employee_data.txt");
	// You will need to change the path to the data file for your computer
	string line;
	employee_data *employee = new employee_data; // Pointer to employee_data type

	if (!infile)
	{
		cout << "Unable to open the employeed data file." << endl;
		system("pause");
		return 1; // Error code for file open error
	}

	cout << "Employee Data File opened." << endl;
	// Read and ingnore the first two lines of the file.
	// They are not data lines.

	getline(infile, line);
	getline(infile, line);


	employee_data *root, *current_node, *new_node; //declares pointers
	
	current_node = new employee_data;   
	
	enter_data(*current_node);  // gets first line of data
	
	current_node->link = NULL;  // sets current node to null

	root = current_node;
	
	while (!infile.eof())      //loops till end of file
	{
		new_node = new employee_data;   // makes a new node for employee data
		getline(infile, line);         // gets next line of data from file
		enter_data(*new_node);          // calls function
		new_node->link = NULL;            // sets new node to null
		current_node->link = new_node;    // links the last node to new node
		current_node = new_node;          // sets teh current node to the new one
		
	}

	current_node = root;                  // brings current node back to beginning of the list
	while (current_node->link != NULL)        // loops until node is Null
	{
		cout << "Employee Data" << endl << endl;
		print_data(*current_node);                // calls print data function
		current_node = current_node->link;         // moves to next linked node
		

	}


	system("pause");
	return 0;
}
void enter_data(employee_data &person)
{
	infile >> person.firstname >> person.lastname >> person.initial   // enters data
		>> person.ID >> person.hours >> person.wage
		>> person.pay;
	return;
}
void print_data(employee_data &person)  // prints data
{
	cout << endl;
	cout << fixed << setprecision(2) << left;
	cout << person.firstname << " " << person.initial
		<< " " << person.lastname << endl;
	cout << setw(15) << "ID:" << person.ID << endl;
	cout << setw(15) << "Hours Worked:" << person.hours << endl;
	cout << setw(15) << "Wage:" << person.wage << endl;
	cout << setw(15) << "Gross Pay:" << person.pay << endl << endl;
	cout << right;
	return;
}
