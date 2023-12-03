#include <iostream>
#include "Header.h"
#include <string>
#include <fstream>
#include <Windows.h>
#include<cstdio>


using namespace std;

ifstream fin;
ofstream fout;
void dis(Teacher* tchr, int x) {

	for (int i = 0; i < x; ++i)
	{


		cout << tchr[i].username << ',' << tchr[i].password << ',' << tchr[i].tID << ',' << tchr[i].name << ',' << tchr[i].dept << ',' << tchr[i].gender << ',' << tchr[i].qualification << ',' << tchr[i].address << ',' << tchr[i].lecture << ',';
		for (int j = 0; j < 5; ++j)
		{
			fout << tchr[i].lecDay[j] << ',' << tchr[i].lectTime[j] << ',';
		}
		cout << endl;



	}
}
void tremove()
{


	int result1 = remove("teacher.txt");

	if (result1 == 0) {
		printf("File removed successfully.\n");
	}
	else {
		printf("Failed to remove the file.\n");
	}


}
void sremove()
{


	int result1 = remove("student.txt");

	if (result1 == 0) {
		printf("File removed successfully.\n");
	}
	else {
		printf("Failed to remove the file.\n");
	}


}


bool searchFile(const string& filename, const string& searchData) {
	ifstream fin(filename);
	string line;

	if (fin.is_open()) {
		while (getline(fin, line)) {
			if (line.find(searchData) != string::npos) {
				fin.close();
				return true;
			}
		}
		fin.close();
	}

	return false;
}

void allStore(Teacher* tchr, int x)
{
	fout.open("teacher.txt", ios::app);

	if (fout.is_open())
	{
		for (int i = 0; i < x; ++i)
		{
			fout << tchr[i].username << ',' << tchr[i].password << ',' << tchr[i].tID << ',' << tchr[i].name << ',' << tchr[i].dept << ',' << tchr[i].gender << ',' << tchr[i].qualification << ',' << tchr[i].address << ',' << tchr[i].lecture << ',';
			for (int j = 0; j < 5; ++j)
			{
				fout << tchr[i].lecDay[j] << ',' << tchr[i].lectTime[j] << ',';
			}
			fout << endl;
		}

		fout.close();
		cout << "Data stored successfully." << endl;
	}
	else
		cout << "Teacher File Not Open" << endl;
}
void SallStore(Student* stu, int x)
{
	fout.open("student.txt", ios::app);

	if (fout.is_open())
	{
		for (int i = 0; i < x; ++i)
		{
			fout << stu[i].rollNo << ',' << stu[i].name << ',' << stu[i].password << ',' << stu[i].feeStatus << ',';
			for (int j = 0; j < 5; ++j)
			{
				fout << stu[i].courses[j] << ',';
			}
			fout << endl;

		}

		fout.close();
		cout << "Data stored successfully." << endl;
	}
	else
		cout << "Student File Not Open" << endl;
}


void Teacher::file()
{

	fout.open("teacher.txt", ios::app);

	if (fout.is_open())
	{
		fout << username << ',' << password << ',' << tID << ',' << name << ',' << dept << ',' << gender << ',' << qualification << ',' << address << ',' << lecture << ',';
		for (int i = 0; i < 5; ++i)
		{
			fout << lecDay[i] << ',' << lectTime[i] << ',';
		}
		fout << endl;
		fout.close();
	}
	else
		cout << "Teacher File Not Open" << endl;
}

//administrator's definations 

void Administrator::signIn()
{
	try {
		cout << "Enter Username : ";
		cin >> userName;
		if (userName.size() < 5) {
			throw exception();
		}
	}
	catch (exception) {
		cout << "exception caught! : username should be of atleast 5 digits" << endl;
		signIn();
	}
	if (searchFile("admin.txt", userName))
	{
		
		try {
			cout << "Enter Password : ";
			cin >> password;
			if (password.size() < 5) {
				throw exception();
			}
		}
		catch (exception) {
			cout << "exception caught! : password should be of atleast 5 digits" << endl;
			signIn();
		}
		

		if (searchFile("admin.txt", password))
		{
			cout << "Successful" << endl;
		}
		else
		{
			cout << "Wrong Password" << endl;
			signIn();
		}
	}
	else
	{
		cout << "Incorrect username" << endl;
		signIn();
	}
}

void Administrator::addStudent(int n)//n is the index at which the next student is to be added 
{
	cout << "Name : ";
	cin >> stu[n].name;
	cout << "roll No : ";
	cin >> stu[n].rollNo;
	cout << "Set password : ";
	cin >> stu[n].password;
	cout << "Fee status(paid or unpaid) : ";
	cin >> stu[n].feeStatus;
	cout << "Input 5 courses :\n";
	for (int i = 0; i < 5; ++i) {
		cout << "Course " << i + 1 << " : ";
		cin >> stu[n].courses[i];
	}
}

void Administrator::addTeacher(int n)
{
	tchr[n].sr = n;
	cout << "ID : ";
	cin >> tchr[n].tID;
	tchr[n].username = tchr[n].tID;
	cout << " User Name will be ID, Set Password" << endl;
	cin >> tchr[n].password;
	cout << "Name : ";
	cin >> tchr[n].name;
	cout << "Gender : ";
	cin >> tchr[n].gender;
	cout << "Department : ";
	cin >> tchr[n].dept;
	cout << "Address : ";
	cin >> tchr[n].address;
	cout << "Qualification : ";
	cin >> tchr[n].qualification;
	cout << "\t\t\t Assign 5 Lectures Day adn Time " << endl;
	cout << "Input Course" << endl;
	cin >> tchr[n].lecture;
	for (int i = 0; i < 5; ++i)
	{
		cout << "LEC " << i + 1 << ")" << endl;
		cout << "Input LEC Day" << endl;
		cin >> tchr[n].lecDay[i];
		cout << "Input Lecture Timmings" << endl;
		cout << "Time " << endl;
		cin >> tchr[n].lectTime[i];
		cout << endl;

	}
}


void Administrator::addHod() {
	cout << "Is the HOD teacher as well?\nPress 1 for yes 0 for no" << endl;
	cin >> (*hod).isTchr;
	cout << "ID : ";
	cin >> (*hod).tID;
	(*hod).username = (*hod).tID;
	cout << "ID will be Username\nPassword : ";
	cin >> (*hod).password;
	cout << "Name : ";
	cin >> (*hod).name;
	cout << "Gender : ";
	cin >> (*hod).gender;
	cout << "Department : ";
	cin >> (*hod).dept;
	cout << "Address : ";
	cin >> (*hod).address;
	cout << "Qualification : ";
	cin >> (*hod).qualification;
	if ((*hod).isTchr) {
		cout << "\t\t\t Assign 5 Lectures Day adn Time " << endl;
		cout << "Input Course" << endl;
		cin >> (*hod).lecture;
		for (int i = 0; i < 5; ++i)
		{
			cout << "LEC " << i + 1 << ")" << endl;
			cout << "Input LEC Day" << endl;
			cin >> (*hod).lecDay[i];
			cout << "Input Lecture Timmings" << endl;
			cout << "Time: " << endl;
			cin >> (*hod).lectTime[i];
			cout << endl;
		}
	}
}

void Administrator::editStudent(int n) //n is the serial number of the student 
//index of that student will be n-1
{
	cout << "Edit Name : ";
	cin >> stu[n - 1].name;
	cout << "Edit roll No : ";
	cin >> stu[n - 1].rollNo;
	cout << "Edit Fee status(paid or unpaid) : ";
	cin >> stu[n - 1].feeStatus;
	cout << "Edit 5 courses\n";
	for (int i = 0; i < 5; ++i) {
		cout << " Edit Course " << i + 1 << " : ";
		cin >> stu[n - 1].courses[i];
	}
}

void Administrator::editTeacher(int n)
{
	cout << "Edit ID : ";
	cin >> tchr[n - 1].tID;
	cout << "Edit Name : ";
	cin >> tchr[n - 1].name;
	cout << "Edit Gender : ";
	cin >> tchr[n - 1].gender;
	cout << "Edit Department : ";
	cin >> tchr[n - 1].dept;
	cout << "Edit Address : ";
	cin >> tchr[n - 1].address;
	cout << "Edit Qualification : ";
	cin >> tchr[n - 1].qualification;
}

void Administrator::editHod()
{
	cout << "Edit ID : ";
	cin >> (*hod).tID;
	cout << "Edit Name : ";
	cin >> (*hod).name;
	cout << "Edit Gender : ";
	cin >> (*hod).gender;
	cout << "Edit Department : ";
	cin >> (*hod).dept;
	cout << "Edit Address : ";
	cin >> (*hod).address;
	cout << "Edit Qualification : ";
	cin >> (*hod).qualification;
}

void Administrator::displayStudents(int n) {
	for (int i = 0; i < n; ++i) {
		cout << i + 1 << ") " << endl << "\tName : " << stu[i].name << endl;
		cout << "\t" << "Roll No. : " << stu[i].rollNo << endl;
		cout << "\t" << "Fee status : " << stu[i].feeStatus << endl;
		cout << "\t" << "Courses : " << endl;
		for (int j = 0; j < 5; ++j) {
			cout << "\t" << i + 1 << ") " << stu[i].courses[j] << endl;
		}
	}
}
void Administrator::displayTeachers(int n)
{
	for (int i = 0; i < n; ++i) {
		cout << i + 1 << ")\n\tName: " << tchr[i].name << endl;
		cout << "\tID: " << tchr[i].tID << endl;
		cout << "\tPassword: " << tchr[i].password << endl;
		cout << "\tGender: " << tchr[i].gender << endl;
		cout << "\tDepartment: " << tchr[i].dept << endl;
		cout << "\tAddress: " << tchr[i].address << endl;
		cout << "\tQualification: " << tchr[i].qualification << endl;
		cout << "\tTime Table" << endl;

		for (int j = 0; j < 5; j++)
		{

			cout << "\t" << tchr[i].lecture << "  " << tchr[i].lecDay[j] << "  " << tchr[i].lectTime[j] << endl;
		}
	}
	system("pause");
}

//student's definations
void Student::signIn() {
	cout << "Enter Username : ";
	cin >> rollNo;
	if (searchFile("student.txt", rollNo))
	{
		cout << "Enter Password : ";
		cin >> password;
		if (searchFile("student.txt", password))
		{
			cout << "Successful" << endl;
		}
		else
		{
			cout << "Wrong Password" << endl;
			signIn();
		}
	}
	else
	{
		cout << "Incorrect username" << endl;
		signIn();
	}

}

void Student::viewFeeStatus() {
	cout << "Fee Status: " << feeStatus << endl;
	system("pause");
}

void Student::viewCourses() {
	for (int i = 0; i < 5; ++i) {
		cout << courses[i] << endl;
	}
	system("pause");
}

void Student::viewAttendance() {
	for (int i = 0; i < 5; ++i)
	{
		if (attendance[i] >= 80) {
			system("color 2");//green if attendace is not less than 80%
		}
		else {
			system("color 4");//red if attendance is less than 80
		}
		cout << courses[i] << " Attendance = " << attendance[i] << "%" << endl;
		system("pause");
	}
	system("color 6");
}

void Student::viewGrade() {
	for (int i = 0; i < 5; ++i) {
		cout << courses[i] << " : " << grades[i] << endl;
	}
	system("pause");
}

void Student::viewMarks() {
	for (int i = 0; i < 5; ++i) {
		cout << courses[i] << " : " << marks[i] << endl;
	}
	system("pause");
}

void Student::file()
{
	ofstream fout;
	fout.open("student.txt", ios::app);
	if (fout.is_open())
	{
		fout << rollNo << ',' << name << ',' << password << ',' << feeStatus << ',';
		for (int i = 0; i < 5; ++i)
		{
			fout << courses[i] << ',';
		}
		fout << endl;
		fout.close();
	}
	else
		cout << "Student File Not Open" << endl;
}

//teacher deffinations
void Teacher::signIn() {
	cout << "Enter Username" << endl;
	cin >> username;
	if (searchFile("teacher.txt", username))
	{
		cout << "Enter Password" << endl;
		cin >> password;
		if (searchFile("teacher.txt", password))
		{
			cout << "Successful" << endl;
		}
		else
		{
			cout << "Wrong Password" << endl;
			signIn();
		}
	}
	else
	{
		cout << "Incorrect username" << endl;
		signIn();
	}

}

void Teacher::markAttendace(Student* s, int n) {
	// n is number of total students and we put pointer to mark all students
	for (int i = 0; i < n; ++i)
	{
		cout << s[i].getName() << endl;
		cout << "Enter Attendance Percentage" << endl;
		cin >> s[i].attendance[sr];
	}
}
void Teacher::timeTable() {
	cout << "\t\t\tTime Table" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << lecture << "  " << lecDay[i] << "  " << lectTime[i] << endl;
	}
	system("pause");
}
void Teacher::assignMarks(Student* s, int n) {
	//c is the subject index
	cout << "Input Marks of Students" << endl;
	for (size_t i = 0; i < n; i++)
	{
		cout << s[i].getName() << endl;
		cin >> s[i].marks[sr];
	}
}
void Teacher::assignGrades(Student* s, int n) {
	//c is the subject index
	cout << "Input Grade of Students" << endl;
	for (size_t i = 0; i < n; i++)
	{
		cout << s[i].getName() << endl;
		cin >> s[i].grades[sr];
	}
}

string Teacher::getName() {
	return name;
}

void Teacher::save(Student* stu, int n)
{
	for (int i = 0; i < 3; ++i) {
		system("cls");
		cout << "saving.";
		Sleep(250);
		system("cls");
		cout << "saving..";
		Sleep(250);
		system("cls");
		cout << "saving...";
		Sleep(250);
		system("cls");
	}
	remove("studentdata.txt");
	fout.open("studentdata.txt", ios::app);
	for (int j = 0; j < n; ++j) {
		if (fout.is_open())
		{
			for (int i = 0; i < 5; ++i) {
				fout << stu[j].attendance[i] << ',';
			}
			for (int i = 0; i < 5; ++i) {
				fout << stu[j].marks[i] << ',';
			}
			for (int i = 0; i < 5; ++i) {
				fout << stu[j].grades[i] << ',';
			}
			fout << endl;
			cout << "Data saved!\n";
		}
		else {
			cout << "File Not Open" << endl;
		}
	}
	fout.close();
	system("pause");
}
//HOD definations 
void Hod::signIn()
{
	cout << "Enter Username : ";
	cin >> username;
	if (searchFile("hod.txt", username))
	{
		cout << "Enter Password : ";
		cin >> password;
		if (searchFile("hod.txt", password))
		{
			cout << "Successful" << endl;
		}
		else
		{
			cout << "Wrong Password" << endl;
			signIn();
		}
	}
	else
	{
		cout << "Incorrect username" << endl;
		signIn();
	}
}

void Hod::displayStudents(Student* stu, int n)// n is the total number of students
{
	for (int i = 0; i < n; ++i) {
		cout << i + 1 << ") " << stu[i].name << endl;
	}
}


void Hod::displayTeachers(Teacher* tchr, int n)
{
	for (int i = 0; i < n; ++i) {
		cout << i + 1 << ") " << tchr[i].name << endl;
	}
}

string Hod::getName() {
	return name;
}

void Hod::file() {
	fout.open("hod.txt", ios::app);

	if (fout.is_open())
	{
		if (isTchr) {
			fout << "true";
		}
		else {
			fout << "false";
		}
		fout << ',' << username << ',' << password << ',' << tID << ',' << name << ',' << dept << ',' << gender << ',' << qualification << ',' << address << ',';
		if (isTchr)
		{
			fout << lecture << ',';
			for (int i = 0; i < 5; ++i)
			{
				fout << lecDay[i] << ',' << lectTime[i] << ',';
			}
		}
		fout << endl;
		fout.close();
	}
	else
		cout << "hod File Not Open" << endl;
}