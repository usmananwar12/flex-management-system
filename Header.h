#include <string>
using namespace std;

void tremove();
void sremove();

class Student
{
private:
	string name;
	string rollNo;//rollno will be username
	string password;
	float attendance[5];
	int marks[5];
	string grades[5];
	string courses[5];
	string feeStatus;
public:
	Student() {
		name = "-";
		rollNo = "-";
		password = "-";
		for (int i = 0; i < 5; ++i) {
			attendance[i] = 0;
			marks[i] = 0;
			grades[i] = "-";
			courses[i] = "-";
		}
		feeStatus = "-";
	}
	void signIn();
	void viewAttendance();
	void viewMarks();
	void viewGrade();
	void viewCourses();
	void viewFeeStatus();
	string getName() { return name; }
	void file();

	friend class Hod;
	friend class Administrator;
	friend class Teacher;
	friend int stuReadFile(Student*);
	friend void SallStore(Student* stu, int x);

};


class Teacher
{
protected:
	string name;
	string dept;
	string tID;
	string username;
	string password;
	string gender;
	string qualification;
	string address;
	string lecture;
	string lectTime[5];
	string lecDay[5];
	int sr;// sr number of the teacher 
public:
	void file();
	void signIn();
	void timeTable();
	void markAttendace(Student* s, int n);
	void assignMarks(Student* s, int n);
	void assignGrades(Student* s, int n);
	string getName();
	void save(Student*, int);

	friend class Hod;
	friend class Administrator;
	friend int TreadFile(Teacher* tchr);
	friend void allStore(Teacher* tchr, int x);
	friend void dis(Teacher* tchr, int x);
};

class Hod :public Teacher {
private:
	bool isTchr;

public:
	void signIn();
	void displayStudents(Student*, int);
	void displayTeachers(Teacher*, int);
	string getName();
	void file();
	bool get_isTchr() { return isTchr; }
	friend class Administrator;
	friend void hodReadFile(Hod&);
};

class Administrator
{
private:
	string userName;
	string password;
	Student* stu;
	Teacher* tchr;
	Hod* hod;
	//teacher and student have "has-a" relationship with administration so it will be aggrigation

public:
	Administrator() {
		userName = "";
		password = "";
		stu = nullptr;
		tchr = nullptr;
	}
	Administrator(Student*& stu, Teacher*& tchr, Hod* hod) {
		userName = "";
		password = "";
		this->stu = stu;
		this->tchr = tchr;
		this->hod = hod;
	}
	void signIn();
	void addTeacher(int);//pass the index to keep track of how many are added
	void addStudent(int);
	void addHod();
	void editStudent(int);//pass index of the student/teacher to edit
	void editTeacher(int);
	void editHod();
	void displayStudents(int);//pass the index so that we know how many are added
	void displayTeachers(int);

};