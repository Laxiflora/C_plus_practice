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
			return new Student(2);
			break;
		default:
			return new Person();
	}
	
}



int main(void){
	Person someone(407530016,'B');
	Student* studentA = (Student*)someone.whoAreYou(1);
	cout<<studentA->Getgrade();
	
	

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

另外,父類別無法接住子類別 ,但子類別可以接住父類別的return(但只能有父類別的member且其必須是public繼承)
然而,如果在子類別宣告時強制轉型態(見76行),則依舊可以編譯運行(在return new的地方會成功呼叫一次子類別的建構元) 


*這段code是針對clean code的listing 3-5做的測試
*書中以return格式Employee的函數來switch,然後return各Employee的子類別(ex. return new HourlyEmployee(r);)
*/ 




