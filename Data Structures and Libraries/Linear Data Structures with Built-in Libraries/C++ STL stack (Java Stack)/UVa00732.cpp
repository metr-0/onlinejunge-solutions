#include <cstdio>
#include <stack>
#include <cstring>

using namespace std;

void rec(stack<char>& target, stack<char>& sourse, stack<char>& s, char log[2100])
{
	while (true) {
		if (!target.empty() && !s.empty() && target.top() == s.top()) {
			if (!sourse.empty()) {
				stack<char> ntarget = target;
				stack<char> nsourse = sourse;
				stack<char> ns = s;
				char nlog[2100];
				memcpy(nlog, log, 2100);
				
				ns.push(nsourse.top());
				nsourse.pop();
				strcat(nlog, " i");
				
				rec(ntarget, nsourse, ns, nlog);
			}
			
			target.pop();
			s.pop();
			strcat(log, " o");
		} else if (!sourse.empty()) {
			s.push(sourse.top());
			sourse.pop();
			
			strcat(log, " i");
		} else break;
	}
	if (target.empty() && s.empty())
		puts(log + 1);
}

int main()
{
	char ssourse[500], starget[500];
	int i, l;
	stack<char> sourse, target, s;
	char log[2100];
	
	while (scanf("%s %s", ssourse, starget) != EOF) {
		sourse = stack<char>();
		l = strlen(ssourse);
		for (i = l - 1; i >= 0; i--)
			sourse.push(ssourse[i]);
		
		target = stack<char>();
		l = strlen(starget);
		for (i = l - 1; i >= 0; i--)
			target.push(starget[i]);
		
		s = stack<char>();
		log[0] = '\0';
		
		puts("[");
		rec(target, sourse, s, log);
		puts("]");
	}
}
