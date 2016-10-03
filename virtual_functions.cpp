#include <iostream>

class Person{
	
public:
	virtual void name(){
		std::cout << "I am a person\n";
	}
};

class Student : public Person {
public:
	void name(){
		std::cout << "I am a student\n";
	}
};

int main(){
	Student* st = new Student();
	st->name();
	Person* st2 = new Student();
	st2->name();
}
