#include <cstdio>
#include <bitset>
#include <queue>
#include <stack>

using namespace std;

void solve()
{
	int N, S, Q, i, j, temp,
		time = -2, station = 1;
	scanf("%d %d %d", &N, &S, &Q);
	
	stack<int> s;
	bitset<105> bs;
	queue<int> *q_0 = new queue<int>[N], *q = q_0;
	
	for (i = 0; i < N; i++, q++) {
		scanf("%d", &j);
		bs[i] = j != 0;
		
		while (j--) {
			scanf("%d", &temp);
			(*q).push(temp);
		}
	}
	
	if (bs.none()) {
		printf("0\n");
		return;
	}
	
	q = q_0;
	while (bs.any() || !s.empty()) {
		time += 2;
		
		while (!s.empty()) {
			if (s.top() == station) {
				s.pop();
			} else if ((*q).size() < Q) {
				(*q).push(s.top());
				s.pop();
			} else break;
			
			time++;
		}
		
		while (s.size() < S && !(*q).empty()) {
			s.push((*q).front());
			(*q).pop();
			
			time++;
		}
		
		bs[station - 1] = !(*q).empty();
		
		if (station == N) station = 1, q = q_0;
		else station++, q++;
	}
	
	printf("%d\n", time);
}

int main()
{
	int TC;
	scanf("%d", &TC);
	
	while (TC--) solve();
}
