#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    int numRefills = 0 ;
    int currentRefill = 0;
    int lastRefill;
    vector<int> stopsAndDestination(1);

    std::copy(stops.begin(), stops.end(), back_inserter(stopsAndDestination));
    stopsAndDestination.push_back(dist);

    int n = stops.size();
    while(currentRefill<=n)
    {
        lastRefill = currentRefill;
        while(  currentRefill<=n && 
                stopsAndDestination[currentRefill+1]-stopsAndDestination[lastRefill]<=tank)
        {
            currentRefill++;
        }
        if(currentRefill == lastRefill)
            return -1;
        if(currentRefill<=n)
            numRefills++;
    }
    return numRefills;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
