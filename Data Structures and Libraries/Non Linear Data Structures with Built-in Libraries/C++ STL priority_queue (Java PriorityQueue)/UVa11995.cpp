#include <cstdio>
#include <stack>
#include <queue>

using namespace std;

void solve(int N)
{
	stack<int> st;
	queue<int> q;
	priority_queue<int> pq;
	
	bool stf = true, qf = true, pqf = true;
	
	int command, x;
	while (N--) {
		scanf("%d %d", &command, &x);
		
		if (command == 1) {
			if (stf) st.push(x);
			if (qf) q.push(x);
			if (pqf) pq.push(x);
		} else {
			if (stf) {
				if (!st.empty() && st.top() == x)
					st.pop();
				else stf = false;
			}
			if (qf) {
				if (!q.empty() && q.front() == x)
					q.pop();
				else qf = false;
			}
			if (pqf) {
				if (!pq.empty() && pq.top() == x)
					pq.pop();
				else pqf = false;
			}
		}
	}
	
	if (stf && qf || stf && pqf || qf && pqf)
		printf("not sure\n");
	else if (stf)
		printf("stack\n");
	else if (qf)
		printf("queue\n");
	else if (pqf)
		printf("priority queue\n");
	else
		printf("impossible\n");
}

int main()
{
	int N;
	while (scanf("%d", &N) != EOF)
		solve(N);
}
