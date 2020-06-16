#include <iostream>
#include <string>
using namespace std;

class Child
{

	friend ostream& operator<<(ostream& output, const Child &child);
public:


	Child();
	Child(string fName, string lName, int age);
	~Child();

	bool operator< (const Child &child) const;
	bool operator> (const Child &child) const;
	bool operator<= (const Child &child) const;
	bool operator>= (const Child &child) const;
	bool operator== (const Child &child) const;
	bool operator!= (const Child &child) const;
	Child operator= (const Child &child);

	string getFirstName()const;
	void setFirstName(string name);

	string getLastName()const;

	void setLastName(string name);

	int getAge()const;

	void setAge(int age);

private:
	string firstName;
	string lastName;
	int age;
};