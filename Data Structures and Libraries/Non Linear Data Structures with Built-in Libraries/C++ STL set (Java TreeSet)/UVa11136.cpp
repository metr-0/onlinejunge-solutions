#include <cstdio>
#include <set>

void solve(int DC)
{
	std::multiset<int> mset;
	long long sum = 0;
	
	int BC, temp;
	while (DC--) {
		scanf("%d", &BC);
		
		while (BC--) {
			scanf("%d", &temp);
			mset.insert(temp);
		}
		
		auto min = mset.begin();
		auto max = --mset.end();
		
		sum += *max - *min;
		
		mset.erase(min);
		mset.erase(max);
	}
	
	printf("%lld\n", sum);
}

int main()
{
	int DC;
	
	while (scanf("%d", &DC), DC)
		solve(DC);
}
