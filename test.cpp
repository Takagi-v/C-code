#include <iostream>
#include <iomanip>

using namespace std;
/**/
int main()
{
  double totalGPA = 0.0;
  int n;
  double credit, grade, totalCredit = 0.0, totalGrade = 0.0;
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    cin >> grade >> credit;
    totalCredit += credit;
    if (grade >= 95)
      grade = 4.3;
    else if (grade >= 90)
      grade = 4.0;
    else if (grade >= 85)
      grade = 3.7;
    else if (grade >= 80)
      grade = 3.3;
    else if (grade >= 75)
      grade = 3.0;
    else if (grade >= 70)
      grade = 2.7;
    else if (grade >= 67)
      grade = 2.3;
    else if (grade >= 65)
      grade = 2.0;
    else if (grade >= 62)
      grade = 1.7;
    else if (grade >= 60)
      grade = 1.0;
    totalGrade += grade * credit;
  }
  totalGPA = totalGrade / totalCredit;
  cout << fixed << setprecision(6) << totalGPA << endl;
  return 0;
}
