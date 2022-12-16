#include <cstdio>
#include <cstring>
#include <vector>

#define SIZE (16 * 1024 + 10)

using namespace std;

int ranks[] = { 1024, 256, 64, 16, 4, 1 };
char buf[SIZE], *str;

class SumsTree {
private:
	SumsTree *parent;
	vector<SumsTree*> childs;
	int rank;
public:
	int value;
	
	SumsTree(int r, SumsTree *p) {
		rank = r;
		value = 0;
		parent = p;
	}
	SumsTree() : SumsTree(0, NULL) {}
	
	SumsTree *get_child(int i) {
		if (i >= childs.size())
			childs.push_back(new SumsTree(rank + 1, this));
		
		return childs[i];
	}
	void fill() {
		value = ranks[rank];
	}
	void recalculate() {
		int v = 0;
		for (auto c : childs)
			v += (*c).value;
		
		if (v != value) {
			value = v;
			if (parent != NULL) (*parent).recalculate();
		}
	}
};

void set(SumsTree *tree)
{
	if (*str == 'p') {
		for (int j = 0; j < 4; j++) {
			str++;
			set((*tree).get_child(j));
		}
		(*tree).recalculate();
	} else if (*str == 'f') {
		(*tree).fill();
	}
}

void solve()
{
	SumsTree *tree = new SumsTree();
	
	scanf("%s", buf);
	str = buf;
	set(tree);
	
	scanf("%s", buf);
	str = buf;
	set(tree);
	
	printf("There are %d black pixels.\n", (*tree).value);
}

int main()
{
	int TC;
	scanf("%d", &TC);
	
	while (TC--) solve();
}
