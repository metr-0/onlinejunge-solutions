#include <cstdio>
#include <queue>

using qi = std::queue<int>;

void solve()
{
	qi left, right;
	
	int l, CC;
	scanf("%d %d", &l, &CC);
	l *= 100;
	
	int cl;
	char buf[10];
	while (CC--) {
		scanf("%d %s", &cl, buf);
		
		if (buf[0] == 'l') left.push(cl);
		else right.push(cl);
	}
	
	int count = 0, tl;
	bool on_right = false;
	while (!left.empty() || !right.empty()) {
		tl = l;
		if (on_right) while (!right.empty() && tl >= right.front()) {
			tl -= right.front();
			right.pop();
		} else while (!left.empty() && tl >= left.front()) {
			tl -= left.front();
			left.pop();
		}
		
		on_right = !on_right;
		count++;
	}
	
	printf("%d\n", count);
}

int main()
{
	int TC;
	scanf("%d", &TC);
	
	while (TC--) solve();
}
