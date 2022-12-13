#include <cstdio>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int FC;
	while (scanf("%d", &FC), FC != 0) {
		map<vector<int>, int> froshs;
		
		while (FC--) {
			vector<int> temp(5);
			
			for (int i = 0; i < 5; i++)
				scanf("%d", &temp[i]);
			
			sort(temp.begin(), temp.end());
			
			if (froshs.find(temp) != froshs.end())
				froshs[temp]++;
			else
				froshs[temp] = 1;
		}
		
		int max = 0, count = 0, v;
		for (auto f : froshs) {
			v = f.second;
			
			if (v > max) {
				max = v;
				count = v;
			} else if (v == max) {
				count += v;
			}
		}
		
		printf("%d\n", count);
	}
}
