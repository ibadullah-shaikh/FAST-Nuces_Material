#define STUDENT_H
namespace N
{
	class Student
	{
		int stu,id, batch, g_year, n;
		char dis[10], course[8][10]; //Max: 8 courses.
		public:
			void Set_Stu(int);
			void Set_Data();
			void Display();
			int operator [] (int);
	};
}
