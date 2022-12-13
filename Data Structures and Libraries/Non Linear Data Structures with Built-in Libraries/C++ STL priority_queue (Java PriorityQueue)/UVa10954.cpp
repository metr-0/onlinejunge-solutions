#include <cstdio>
#include <queue>

using namespace std;

void solve(int N)
{
	priority_queue<int, vector<int>, greater<int>> pq;
	
	int temp;
	while (N--) {
		scanf("%d", &temp);
		pq.push(temp);
	}
	
	int sum = 0;
	while (pq.size() > 1) {
		temp = pq.top();
		pq.pop();
		temp += pq.top();
		pq.pop();
		
		pq.push(temp);
		sum += temp;
	}
	
	printf("%d\n", sum);
}

int main()
{
	int N;
	while (scanf("%d", &N), N)
		solve(N);
}
