#include <cstdio>
#include <queue>

using qi = std::queue<int*>;

void solve()
{
	qi left, right;
	int capacity, time, CC, total_time = 0, cars[10005];
	scanf("%d %d %d", &capacity, &time, &CC);
	
	char buf[10];
	int *temp = cars;
	for (int i = 0; i < CC; i++) {
		scanf("%d %s", temp, buf);
		if (buf[0] == 'l') left.push(temp);
		else right.push(temp);
		
		temp++;
	}
	
	bool on_right = false;
	while (!right.empty() || !left.empty()) {
		if ((right.empty() || *right.front() > total_time) && (left.empty() || *left.front() > total_time))
			total_time = (right.empty() || (!left.empty() && *right.front() > *left.front())) ? *left.front() : *right.front();
		
		if (on_right) {
			for (int i = 0; i < capacity; i++)
				if (!right.empty() && *right.front() <= total_time) {
					*right.front() = total_time + time;
					right.pop();
				} else break;
		} else {
			for (int i = 0; i < capacity; i++)
				if (!left.empty() && *left.front() <= total_time) {
					*left.front() = total_time + time;
					left.pop();
				} else break;
		}
		
		total_time += time;
		on_right = !on_right;
	}
	
	for (int i = 0; i < CC; i++)
		printf("%d\n", cars[i]);
}

int main()
{
	int TC;
	scanf("%d", &TC);
	while (TC--) {
		solve();
		
		if (TC != 0) printf("\n");
	}
}
