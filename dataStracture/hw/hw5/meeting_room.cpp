#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int minMeetingRooms(vector<pair<int, int>> &meetings)
{
  vector<int> starts, ends;
  for (const auto &m : meetings)
  {
    starts.push_back(m.first);
    ends.push_back(m.second);
  }

  sort(starts.begin(), starts.end());
  sort(ends.begin(), ends.end());
  int rooms = 0, maxRooms = 0;
  int s = 0, e = 0;
  while (s < starts.size())
  {
    if (starts[s] < ends[e])
    {
      rooms++;
      s++;
    }
    else
    {
      rooms--;
      e++;
    }
    maxRooms = max(maxRooms, rooms);
  }
  return maxRooms;
}

int main()
{
  int n;
  cin >> n;
  vector<pair<int, int>> meetings;
  for (int i = 0; i < n; i++)
  {
    int start, end;
    cin >> start >> end;
    meetings.push_back({start, end});
  }
  cout << minMeetingRooms(meetings) << endl;
}