#include <iostream>
#include <string>
using namespace std;
int main()
{
  string s;
  int ans = 0;
  getline(cin, s);
  for (auto cha : s)
  {
    if (cha == ' ')
    {
      ans++;
    }
    else if (cha == 'a' || cha == 'd' || cha == 'g' || cha == 'j' || cha == 'm' || cha == 'p' || cha == 't' || cha == 'w')
    {
      ans++;
    }
    else if (cha == 'b' || cha == 'e' || cha == 'h' || cha == 'k' || cha == 'n' || cha == 'q' || cha == 'u' || cha == 'x')
    {
      ans += 2;
    }
    else if (cha == 'c' || cha == 'f' || cha == 'i' || cha == 'l' || cha == 'o' || cha == 'r' || cha == 'v' || cha == 'y')
    {
      ans += 3;
    }
    else if (cha == 's' || cha == 'z')
    {
      ans += 4;
    }
  }
  cout << ans;
}