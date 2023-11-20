/*
Filename: SWC PROJECT
Programmers: Evra, Beat, Yaya, Ain, Yana
Program Decsription: To make a student record management
Date: 17/11/23
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <set>
#include <cctype>
#include <algorithm>
#include <limits>

using namespace std;

//Declare Arrays as Global Variable
const int numOfStudents = 50;
int studentID[numOfStudents];
string studentName[numOfStudents];
double scores[numOfStudents];
int attendance[numOfStudents];

//Function for Admin Login Page
void adminLoginPage(string &userName, string &password) // Arguements
{
	cout<<"=========================================================================================="<<endl;
	cout<<"||\t\t\t\tSTUDENT RECORDS MANAGEMENT\t\t\t\t||"<<endl;
	cout<<"=========================================================================================="<<endl;
	cout<<"||  Username: ";
	getline (cin,userName); //user prompt username with spacing allows
	cout<<"                                                                                        ||"<<endl;
	cout<<"||  Password: ";                                         
	getline (cin,password); //user prompt password with spacing allows
	cout<<"=========================================================================================="<<endl;
	
}

//inputStudentData function
void inputStudentData()
{
	//Declare variable
	int id;
	string name;
	double studentScores, percentageAttendance, studentAttendance;
	set<int> uniqueID;
	
		// For loop to enter student data based on total student
		for (int i = 0; i < numOfStudents; ++i)
			{
				bool iD; //to compare the variable 
				
				//do while loop making sure there is no repeated ID value. Make it Unique
				// Student Id Code Segment
				do{
					cout<<"Enter ID for Student "<< i+1 <<" in Integer Number\t "<<": ";
					cin>>id;
					
					//The code to making sure the value is not repeated
					iD=uniqueID.insert(id).second;
					
						if(!iD) //Pop up message to inform user if ID is already exist
						{
							cout<<"=========================================================================================="<<endl;
							cout<<"||                ID already existed!\nPlease enter a different ID                      ||"<<endl;
							cout<<"=========================================================================================="<<endl;
							cout<<endl;
						}
					}
				
				while (!iD); // If ID is not existed the ID will be stored in array
					studentID[i] = id; //end of the do while loop for studentID	
				 	cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Clear the newline character from the buffer
			
					//Student Name Code segment
           			cout<<"Enter name for Student "<< i+1 <<"\t\t\t : ";
					getline(cin,name); // User prompt name with spacing allow
					studentName[i] = name; // address the data to student Name Arrays
    
    			//Student scores segment
				do{
					cout<<"Student "<< i+1 <<" scores\t\t\t\t : ";
					cin>>studentScores;
					
						//Checking the value of scores must betwen 0.00 to 100.00					
						if (studentScores >= 101.00)
							{
								cout<<"=========================================================================================="<<endl;
								cout<<"||                                  Invalid scores!!                                    ||"<<endl;
								cout<<"=========================================================================================="<<endl;
							}
					}
				
				while (studentScores >= 101.00);
				scores[i]= studentScores; //address the data to studentScores Arrays
				
				do{
					cout<<"Student "<< i+1 <<" attendance in days (max 265 days)\t : ";
					cin>>studentAttendance; // User prompt attendance based on days
					cout<<endl;
					
						if (studentAttendance > 265 || studentAttendance <= 0) //pop up message to tell the user the Attendance is Invalid
							{
								cout<<"=========================================================================================="<<endl;
								cout<<"||                     Invalid attendance. Please re-insert attendance!                 ||"<<endl;
								cout<<"=========================================================================================="<<endl;
							}
					}
				
				while (studentAttendance > 265 || studentAttendance <= 0); //if the attendance is valid
				
				//calculation to make it as percentage
				percentageAttendance = (studentAttendance/265) * 100;
				attendance[i] = percentageAttendance; //address the data to attendance Arrays
			
				cout<<"=========================================================================================="<<endl;
				cout<< endl;
			}
				
	
}

// calculateAverageScores Function
double calculateAverageScores()
{
	//declaring variables
	double totalScores = 0.0, averageScores;
	
	//for loop based on totalStudents
	for(int i = 0; i < numOfStudents; ++i )
	{
		totalScores= scores[i]+totalScores; // an equation to sum up all the scores
	}
	
	averageScores= totalScores/numOfStudents; // divide 
	
	return averageScores; // return value
}

// displayStudentRecords Function
void displayStudentRecords()
//Template for displaying the results
{
	cout<<"=========================================================================================="<<endl;
	cout<<"||                                     STUDENT RECORDS                                  ||"<<endl;
	cout<<"=========================================================================================="<<endl;
	cout<<"|| Student ID || Student Name            || Student Scores    || Student Attendance (%) ||"<<endl;
	cout<<"=========================================================================================="<<endl;
		
	for(int i = 0; i < numOfStudents; i++ ) //looping for list down all the results
	{
	cout<<"||"<<studentID[i] <<"                  " <<studentName[i] <<"                         " << scores[i] << "               "  << fixed << setprecision(2) << attendance[i] << endl;
	cout<<"||            ||                         ||                   ||                        ||"<<endl;
	cout<<"=========================================================================================="<<endl;
	}
	cout<<"=========================================================================================="<<endl;
	cout<<"|| The average score is: " << calculateAverageScores() <<" \t\t\t\t\t                        ||"<<endl;
	cout<<"=========================================================================================="<<endl;
}

//main function
int main()
{
	//variables declaration
	string username, password;

	adminLoginPage(username, password); //adminLoginPage Function CALL
	
	//multi way selection
	// this is for checking whether user prompt the exact username and password to access "STUDENT RECORD MANAGEMENT"
	if (username == "Mdm Robaya" && password == "robaya123")
	{
		cout<<"||\t\t\t\tWELCOME " << username <<"!\t\t\t\t\t||\n";
		cout<<"=========================================================================================="<<endl;
		
		inputStudentData (); //inputStudentData Function CALL
		calculateAverageScores();  //calculateAverageScores Function CALL
		displayStudentRecords();  //displayStudentRecords Function CALL
		
	}
	else if (username == "Evra" && password == "Evra2005")
	{
		cout<<"||\t\t\t\tWELCOME " << username <<"!\t\t\t\t\t\t||\n";
		cout<<"=========================================================================================="<<endl;
		
		inputStudentData (); //inputStudentData Function CALL
		calculateAverageScores();  //calculateAverageScores Function CALL
		displayStudentRecords(); //displayStudentRecords Function CALL
	}
	
	else if (username == "Yaya" && password == "Yaya123")
	{
		cout<<"||\t\t\t\tWELCOME " << username <<"!\t\t\t\t\t\t||\n";
		cout<<"=========================================================================================="<<endl;
		
		inputStudentData (); //inputStudentData Function CALL
		calculateAverageScores();  //calculateAverageScores Function CALL
		displayStudentRecords();  //displayStudentRecords Function CALL
	}
	
	else if (username == "Ain" && password == "Ain123")
	{
		cout<<"||\t\t\t\tWELCOME " << username <<"!\t\t\t\t\t\t||\n";
		cout<<"=========================================================================================="<<endl;
		
		inputStudentData (); //inputStudentData Function CALL
		calculateAverageScores();  //calculateAverageScores Function CALL
		displayStudentRecords(); //displayStudentRecords Function CALL
	}
	
	else if (username == "Yana" && password == "Yana123")
	{
	cout<<"||\t\t\t\tWELCOME " << username <<"!\t\t\t\t\t\t||\n";
		cout<<"=========================================================================================="<<endl;
		
		inputStudentData (); //inputStudentData Function CALL
		calculateAverageScores();  //calculateAverageScores Function CALL
		displayStudentRecords(); //displayStudentRecords Function CALL
	}
	
	else if (username == "Beat" && password == "Beat123")
	{
		cout<<"||\t\t\t\tWELCOME " << username <<"!\t\t\t\t\t\t||\n";
		cout<<"=========================================================================================="<<endl;
		
		inputStudentData (); //inputStudentData Function CALL
		calculateAverageScores();  //calculateAverageScores Function CALL
		displayStudentRecords(); //displayStudentRecords Function CALL
	}
	
	else //if none is correct
	{
		cout <<"=========================================================================================="<<endl;
		cout <<"||                            Invalid Username or Password!                             ||"<<endl;
		cout <<"||                                PLEASE TRY AGAIN !!!                                  ||"<<endl;
		cout <<"=========================================================================================="<<endl;
		return 1; //ERROR
	}
	
	return 0;
}