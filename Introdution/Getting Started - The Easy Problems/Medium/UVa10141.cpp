#include <cstdio>
#include <cstring>

int main()
{
	int RC, PC, rc, max_rc, i = 0;
	float price, s_price;
	char buf[85], name[85], s_name[85];
	
	while (gets(buf), sscanf(buf, "%d %d", &RC, &PC),
			RC != 0 || PC != 0) {
		max_rc = -1;
		
		while (RC--) {
			gets(buf);
		}
		
		while (PC--) {
			gets(name);
			gets(buf);
			sscanf(buf, "%e %d", &price, &rc);
			
			if (rc > max_rc || (rc == max_rc && price < s_price)) {
				max_rc = rc;
				s_price = price;
				memcpy(s_name, name, 85);
			}
			
			while (rc--) {
				gets(buf);
			}
		}
		
		if (i != 0)
			printf("\n");
		printf("RFP #%d\n%s\n", ++i, s_name);
	}
}
