#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
  int start, end;
};

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  vector<int> ends;
  int point,maxEnd;
  int minIndex,maxIndex;
  for(size_t i = 0; i < segments.size(); ++i)
  {
    ends.push_back(segments[i].end);
  }

  minIndex = std::min_element(ends.begin(),ends.end())-ends.begin();
  maxIndex = std::max_element(ends.begin(),ends.end())-ends.begin();
  maxEnd = segments[maxIndex].end+1; 
  point =segments[minIndex].end; 
  points.push_back(point);
  ends[minIndex] = maxEnd;

  for (size_t i = 1; i < segments.size(); ++i) {
    minIndex = std::min_element(ends.begin(),ends.end())-ends.begin();
    if(point<segments[minIndex].start)
    {
      point = segments[minIndex].end; 
      points.push_back(point);
    }
    ends[minIndex] = maxEnd;
  }
  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
