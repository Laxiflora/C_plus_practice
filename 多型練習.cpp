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
	
	

//            ����B 
//	Student realStudent;
//	Student* known = (Student*)realStudent.Graduate();   �j���নStduent 
//	known->Setgrade(100);
//	cout<<known->Getgrade();
//	Student test;
//	cout>>test.getID();  �p�G�Oprivate�~�ӷ|���� 
	return 0;
}

/*
���O:
C++��class inheritance �w�]�Oprivate,�Ybase class �̭���member��l���O���ɭԳ��|�ܦ�private�]�ӵL�k�ϥ�,�ҥH�ݭn�b�~�Ӯ�,�]�w��public�~��
class A:public B{...}

�t�~,�����O�L�k����l���O ,���l���O�i�H��������O��return(���u�঳�����O��member�B�䥲���Opublic�~��)
�M��,�p�G�b�l���O�ŧi�ɱj���૬�A(��76��),�h���¥i�H�sĶ�B��(�breturn new���a��|���\�I�s�@���l���O���غc��) 


*�o�qcode�O�w��clean code��listing 3-5��������
*�Ѥ��Hreturn�榡Employee����ƨ�switch,�M��return�UEmployee���l���O(ex. return new HourlyEmployee(r);)
*/ 




