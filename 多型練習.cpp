#include <iostream>
#include <cstdlib>
using namespace std;

class Person{
	protected:
		int id;
		char gender;
	public:
		Person(int,char);
		Person(int);
		Person();
		Person* whoAreYou(int);
		int getID();

};

int Person::getID(){
	return id;
}

Person::Person(int in_id,char in_gen){
	id=in_id;
	gender=in_gen;
}

Person::Person(int input){
	
}

Person::Person(){
	id=0;
}


class Student:public Person{
	private:
		int grade;
	public:
		Student();
		Student(int);
		Person* Graduate();
		int Getgrade(){return grade;}
		void Setgrade(int input){grade = input;}
};

Student::Student(int input){
	grade = input;
}

Student::Student(){
	grade = 1;
}

Person* Student::Graduate(){
	return new Person(); 
}



Person* Person::whoAreYou(int option){
	switch(option){
		case 1:
			return new Student();
			break;
		default:
			return new Person();
	}
	
}



int main(void){
	Person someone(407530016,'B');
	Person* studentA = someone.whoAreYou(1);

//            測試B 
//	Student realStudent;
//	Student* known = (Student*)realStudent.Graduate();   強制轉成Stduent 
//	known->Setgrade(100);
//	cout<<known->Getgrade();
//	Student test;
//	cout>>test.getID();  如果是private繼承會報錯 
	return 0;
}

/*
筆記:
C++的class inheritance 預設是private,即base class 裡面的member到子類別的時候都會變成private因而無法使用,所以需要在繼承時,設定為public繼承
class A:public B{...}

另外,父類別無法接住子類別 ,但子類別可以接住父類別的return

*這段code是針對clean code的listing 3-5做的測試,測試證明書裡的程式的確設計有誤
*書中以return格式Employee的函數來switch,然後return各Employee的子類別(ex. return new HourlyEmployee(r);)
*/ 




