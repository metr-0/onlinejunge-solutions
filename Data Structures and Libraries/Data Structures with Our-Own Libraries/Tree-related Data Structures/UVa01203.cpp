#include <cstdio>
#include <queue>
#include <vector>

using namespace std;
using pi = pair<int, int>;

int main()
{
	char buf[10];
	int q, period;
	
	int q_arr[3005];
	priority_queue<pi, vector<pi>, greater<pi>> pq;
	
	while (scanf("%s", buf), buf[0] != '#') {
		scanf("%d %d", &q, &period);
		pq.push({ period, q });
		q_arr[q] = period;
	}
	
	int K;
	scanf("%d", &K);
	
	pi temp;
	while (K--) {
		temp = pq.top();
		pq.pop();
		
		printf("%d\n", temp.second);
		
		temp.first += q_arr[temp.second];
		pq.push(temp);
	}
}
