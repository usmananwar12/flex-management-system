#include "header.h" 
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <fstream>
#include <Windows.h>
#include <sstream>
#include <string>
using namespace std;


void AdminMod(Hod hod, Teacher*& tchr, Student*& stu, int& indexT, int& indexS)
{
	char input;
	Administrator admin(stu, tchr, &hod);
	system("cls");
	admin.signIn();
	do
	{
		system("cls");
		cout << setw(35) << setfill('-') << right << "Administrator" << setw(23) << "-" << endl;
		cout << setw(58 - 9) << left << "Key" << "Task" << "-----" << endl;
		cout << setw(58) << setfill('*') << "*" << setfill('-') << endl;
		cout << setw(58 - 15) << left << "1" << "Add new Teacher" << endl;
		cout << setw(58 - 15) << left << "2" << "Add new Student" << endl;
		cout << setw(58 - 7) << left << "3" << "Add HOD" << endl;
		cout << setw(58 - 20) << left << "4" << "Edit Student Details" << endl;
		cout << setw(58 - 20) << left << "5" << "Edit teacher Details" << endl;
		cout << setw(58 - 8) << left << "6" << "Edit HOD" << endl;
		cout << setw(58 - 17) << left << "7" << "View All students" << endl;
		cout << setw(58 - 17) << left << "8" << "View All teachers" << endl;
		cout << setw(58 - 6) << left << "9" << "Logout" << endl;
		input = _getch();
		system("cls");
		switch (input)
		{
		case '1':
			admin.addTeacher(indexT);
			tchr[indexT].file();
			indexT++;
			break;
		case '2':
			admin.addStudent(indexS);
			stu[indexS].file();
			system("pause");
			indexS++;
			break;
		case '3':
			admin.addHod();
			hod.file();
			break;
		case '4':
			int n;
			cout << "Input the Serial of the student that you want to edit: ";
			cin >> n;
			admin.editStudent(n);
			sremove();
			SallStore(stu, indexS);
			system("pause");
			break;

		case '5':
			int n1;
			cout << "Input the Serial of the teacher that you want to edit: ";
			cin >> n1;
			admin.editTeacher(n1);
			tremove();
			allStore(tchr, indexT);
			system("pause");
			break;
		case '6':
			admin.editHod();
			remove("hod.txt");
			hod.file();
		case '7':
			admin.displayStudents(indexS);
			system("pause");
			break;
		case '8':
			admin.displayTeachers(indexT);
			break;
		}
	} while (input != '9');
}

int TreadFile(Teacher* tchr)//reads data from file to store in data members of class teacher
{
	int index = 0;
	ifstream fin;
	fin.open("teacher.txt");
	if (fin.is_open()) {
		string line;
		while (getline(fin, line)) {
			stringstream ss(line);
			string token;
			string data[19];

			int i = 0;
			while (getline(ss, token, ',')) {
				data[i] = token;
				i++;
			}

			tchr[index].tID = data[0];
			tchr[index].password = data[1];
			tchr[index].username = data[2];
			tchr[index].name = data[3];
			tchr[index].dept = data[4];
			tchr[index].gender = data[5];
			tchr[index].qualification = data[6];
			tchr[index].address = data[7];
			tchr[index].lecture = data[8];
			int j = 9;
			for (int i = 0; i < 5; ++i)
			{
				tchr[index].lecDay[i] = data[j];
				++j;
				tchr[index].lectTime[i] = data[j];
				++j;
			}
			tchr[index].sr = index;
			index++;
		}
		fin.close();
	}
	else {
		cout << "Unable to open students' file" << endl;
	}
	return index;
}


void tchrMod(Teacher* tchr, Student* stu, int indexS)
{
	int m, tchoice;
	system("cls");
	cout << "Flex Teacher\n" << endl;
	cout << "Enter You Faculty assigned serial(int sr) " << endl;
	cin >> m;
	m--;//the serial number is one less then index coz index starts with 0
	tchr[m].signIn();
	system("cls");
	cout << "\n\n\n\n\n\t\t\t\t\t\t\tWelcome " << tchr[m].getName();
	Sleep(1000);
	do {
		system("cls");
		cout << setw(35) << setfill('-') << right << "Flex  Teacher" << setw(23) << "-" << endl;
		cout << setw(58 - 9) << left << "Key" << "Task" << "-----" << endl;
		cout << setw(58) << setfill('*') << "*" << setfill('-') << endl;
		cout << setw(58 - 15) << left << "1" << "Mark Attendance" << endl;
		cout << setw(58 - 12) << left << "2" << "Assign Marks" << endl;
		cout << setw(58 - 13) << left << "3" << "Assign Grades" << endl;
		cout << setw(58 - 15) << left << "4" << "View Time Table" << endl;
		cout << setw(58 - 15) << left << "5" << "Permnently save" << endl;
		cout << setw(58 - 7) << left << "6" << "Log Out" << endl;

		cin >> tchoice;
		system("cls");
		switch (tchoice)
		{
		case 1:
			tchr[m].markAttendace(stu, indexS);
			break;
		case 2:
			tchr[m].assignMarks(stu, indexS);
			break;
		case 3:
			tchr[m].assignGrades(stu, indexS);
			break;
		case 4:
			tchr[m].timeTable();
			break;
		case 5:
			tchr[m].save(stu, indexS);
		}
	} while (tchoice != 6);
}

int stuReadFile(Student* stu)//reads data from file to store in data members of class student
{
	int index = 0;
	ifstream fin;
	fin.open("student.txt");
	if (fin.is_open()) {
		string line;
		while (getline(fin, line)) {
			stringstream ss(line);
			string token;
			string data[9]; // each line has 9 values: rollNo, name, password, feeStatus, and 5 courses

			int i = 0;
			while (getline(ss, token, ',')) {
				data[i] = token;
				i++;
			}

			stu[index].rollNo = data[0];
			stu[index].name = data[1];
			stu[index].password = data[2];
			stu[index].feeStatus = data[3];
			for (int j = 0; j < 5; j++) {
				stu[index].courses[j] = data[j + 4];
			}
			index++;
		}
		fin.close();
		int index1 = 0;
		fin.open("studentdata.txt");
		if (fin.is_open()) {
			while (getline(fin, line)) {
				stringstream ss(line);
				string token;
				string data[15];

				int i = 0;
				while (getline(ss, token, ',')) {
					data[i] = token;
					i++;
				}
				for (int i = 0; i < 5; ++i) {
					stu[index1].attendance[i] = stoi(data[i]);
				}
				for (int i = 0; i < 5; ++i) {
					stu[index1].marks[i] = stoi(data[i + 5]);
				}
				for (int i = 0; i < 5; ++i) {
					stu[index1].grades[i] =  (data[i + 10]);
				}
				index1++;
			}
		}
		else {
			cout << "error opening file or no data stored\n";
		}
	}
	else {
		cout << "Unable to open students' file" << endl;
	}
	return index;
}


void stuMod(Student* stu)
{
	int n, choice;
	system("cls");
	cout << "Flex Student\n" << endl;
	cout << "your serial number : ";
	cin >> n;
	n--;//the serial number is one less then index coz index starts with 0
	stu[n].signIn();
	system("cls");
	cout << "\n\n\n\n\n\t\t\t\t\t\t\tWelcome " << stu[n].getName();
	Sleep(1000);
	do {
		system("cls");
		cout << setw(35) << setfill('-') << right << "Flex  Student" << setw(23) << "-" << endl;
		cout << setw(58 - 9) << left << "Key" << "Task" << "-----" << endl;
		cout << setw(58) << setfill('*') << "*" << setfill('-') << endl;
		cout << setw(58 - 15) << left << "1" << "View Attendance" << endl;
		cout << setw(58 - 10) << left << "2" << "View Marks" << endl;
		cout << setw(58 - 11) << left << "3" << "View Grades" << endl;
		cout << setw(58 - 12) << left << "4" << "View Courses" << endl;
		cout << setw(58 - 15) << left << "5" << "View Fee Status" << endl;
		cout << setw(58 - 6) << left << "6" << "Logout" << endl;
		cin >> choice;
		system("cls");
		switch (choice)
		{
		case 1:
			stu[n].viewAttendance();
			break;
		case 2:
			stu[n].viewMarks();
			break;
		case 3:
			stu[n].viewGrade();
			break;
		case 4:
			stu[n].viewCourses();
			break;
		case 5:
			stu[n].viewFeeStatus();
			break;
		}
	} while (choice != 6);
}

void hodReadFile(Hod& hod) {
	int index = 0;
	ifstream fin;
	fin.open("hod.txt");
	if (fin.is_open()) {
		string line;
		while (getline(fin, line)) {
			stringstream ss(line);
			string token;
			string data[20];

			int i = 0;
			while (getline(ss, token, ',')) {
				data[i] = token;
				i++;
			}
			if (data[0] == "true") {
				hod.isTchr = true;
			}
			else if (data[0] == "false") {
				hod.isTchr = false;
			}
			hod.username = data[1];
			hod.password = data[2];
			hod.tID = data[3];
			hod.name = data[4];
			hod.dept = data[5];
			hod.gender = data[6];
			hod.qualification = data[7];
			hod.address = data[8];
			if (data[0] == "true") {
				hod.lecture = data[8];
				int j = 9;
				for (int i = 0; i < 5; ++i)
				{
					hod.lecDay[i] = data[j];
					++j;
					hod.lectTime[i] = data[j];
					++j;
				}
			}
		}

		fin.close();
	}
	else {
		cout << "Unable to open students' file" << endl;
	}
}

void hodMod(Hod hod, Student* stu, Teacher* tchr, int stuN, int tchrN)
{
	char input;
	system("cls");
	hod.signIn();
	system("cls");
	cout << "\n\n\n\n\n\t\t\t\t\t\t\tWelcome " << hod.getName();
	Sleep(1000);
	do
	{
		system("cls");
		cout << setw(35) << setfill('-') << right << "Flex  HOD" << setw(23) << "-" << endl;
		cout << setw(58 - 9) << left << "Key" << "Task" << "-----" << endl;
		cout << setw(58) << setfill('*') << "*" << setfill('-') << endl;
		cout << setw(58 - 16) << left << "1" << "Display Students" << endl;
		cout << setw(58 - 16) << left << "2" << "Dispaly Teachers" << endl;
		if (hod.get_isTchr()) {
			cout << setw(58 - 15) << left << "3" << "Mark Attendance" << endl;
			cout << setw(58 - 12) << left << "4" << "Assign Marks" << endl;
			cout << setw(58 - 13) << left << "5" << "Assign Grades" << endl;
			cout << setw(58 - 15) << left << "6" << "View Time Table" << endl;
		}

		cout << setw(58 - 13) << left << "X" << "Log Out" << endl;


		input = _getch();
		system("cls");
		switch (input) {
		case '1':
			hod.displayStudents(stu, stuN);
			system("pause");
			break;
		case '2':
			hod.displayTeachers(tchr, tchrN);
			system("pause");
			break;
		case '3':
			hod.markAttendace(stu, stuN);
			break;
		case '4':
			hod.assignMarks(stu, stuN);
			break;
		case '5':
			hod.assignGrades(stu, stuN);
			break;
		case '6':
			hod.timeTable();
		}

	} while (input != 'X' && input != 'x');

}

int main()
{
	char input;
	Teacher* tchr;
	Student* stu;
	Hod hod;
	int n_tchr, n_stu, indexS = 0, indexT = 0;
	n_tchr = 50;
	tchr = new Teacher[n_tchr];
	n_stu = 50;
	stu = new Student[n_stu];
	indexS = stuReadFile(stu);
	indexT = TreadFile(tchr);
	hodReadFile(hod);
	do
	{
		system("cls");
		//menu
		system("color 6");
		cout << setw(40) << setfill('-') << right << "Flex Management System" << setw(18) << "-" << endl;
		cout << setw(58 - 6) << left << "Key" << "Module" << endl;
		cout << setw(58) << setfill('*') << "*" << setfill('-') << endl;
		cout << setw(58 - 13) << left << "1" << "Administrator" << endl;
		cout << setw(58 - 3) << left << "2" << "HoD" << endl;
		cout << setw(58 - 8) << left << "3" << "Teachers" << endl;
		cout << setw(58 - 8) << left << "4" << "Students" << endl;
		cout << setw(58 - 4) << left << "5" << "Exit" << endl;
		input = _getch();
		switch (input)
		{
		case '1':
			AdminMod(hod, tchr, stu, indexT, indexS);
			break;
		case '2':
			hodMod(hod, stu, tchr, indexS, indexT);
			break;
		case '3':
			tchrMod(tchr, stu, indexS);
			break;
		case '4':
			stuMod(stu);
			break;
		}
	} while (input != '5');
	system("cls");
	cout << "\n\n\n\n\n\t\t\t\t\tExited Flex Management System\n\n\n\n\n" << endl;
	return 0;
}