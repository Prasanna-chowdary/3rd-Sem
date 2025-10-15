#include<iostream>
using namespace std;
class Student
{
  private:
        int rollno;
		int marks;
  public:
        string name;
		string branch;
	    
		Student(int r,int m,string n,string b)	
		{
			rollno=r;
			marks=m;
			name=n;
			branch=b;
		}
	    void setMarks(int m)
	    {
	    	marks = m;
		}
		int getMarks()
		{
			return marks;
		}
		void displayDetails()
		{
			cout<<"Name:" << name <<endl;
			cout<<"Branch:"<< branch <<endl;
			cout<<"Roll number:"<<rollno<<endl;
			cout<<"Marks:"<<marks<<endl;
		}
};
int main()
{
    
	Student s1(42,95,"Prasanna","AIML");
	s1.displayDetails();
	s1.setMarks(100);
	cout<< "\nUpdated Marks: "<<s1.getMarks() <<endl;
}
