#include <iostream>
#include <algorithm>

using namespace std;

class Student
{
	public :
		string name;
		int score;
		Student(string name, int score)
		{
			this->name = name;
			this->score = score;
		}
		
		bool operator < (Student &student)
		{
			return this->score < student.score;
		}
};

bool compare(int a, int b)
{
	return a > b; 
}

int main(void)
{
	Student students[] = {
		Student("a", 90),
		Student("b", 80),
		Student("c", 70),
		Student("d", 60),
	};
	
	sort(students, students +5);
	
	for(int i = 0; i < 4; i++)
	{
		cout << students[i].name << ' ';
	}
}
