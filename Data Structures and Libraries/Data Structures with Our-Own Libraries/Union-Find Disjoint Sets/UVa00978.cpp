#include <cstdio>
#include <set>

int gb[100005], bb[100005];

void solve()
{
	std::multiset<int, std::greater<int>> green, blue;
	int b, sg, sb;
	
	scanf("%d %d %d", &b, &sg, &sb);
	
	int temp;
	while (sg--) {
		scanf("%d", &temp);
		green.insert(temp);
	}
	while (sb--) {
		scanf("%d", &temp);
		blue.insert(temp);
	}
	
	int min;
	while (!blue.empty() && !green.empty()) {
		min = blue.size() > green.size() ? green.size() : blue.size();
		min = min > b ? b : min;
		
		for (int i = 0; i < min; i++) {
			auto bluei = blue.begin();
			auto greeni = green.begin();
			
			bb[i] = *bluei;
			gb[i] = *greeni;
			
			blue.erase(bluei);
			green.erase(greeni);
		}
		
		for (int i = 0; i < min; i++) {
			if (gb[i] > bb[i]) green.insert(gb[i] - bb[i]);
			else if (gb[i] < bb[i]) blue.insert(bb[i] - gb[i]);
		}
	}
	
	
	
	if (!blue.empty()) {
		printf("blue wins\n");
		for (auto i = blue.begin(); i != blue.end(); i++)
			printf("%d\n", *i);
	} else if (!green.empty()) {
		printf("green wins\n");
		for (auto i = green.begin(); i != green.end(); i++)
			printf("%d\n", *i);
	} else {
		printf("green and blue died\n");
	}
}

int main()
{
	int TC;
	scanf("%d", &TC);
	
	while (TC--) {
		solve();
		
		if (TC) printf("\n");
	}
}
