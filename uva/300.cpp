/*#include <cstdio>
#include <string>
#include <map>
#include <cctype>
#include <iostream>

using namespace std;

string months[] = {"pop", "no", "zip", "zotz", "tzec",
                   "xul", "yoxkin", "mol", "chen", "yax",
                   "zac", "ceh", "mac", "kankin", "muan",
                   "pax", "koyab", "cumhu"};
                   
string days[] = {"imix", "ik", "akbal", "kan", "chicchan",
                 "cimi", "manik", "lamat", "muluk", "ok",
                 "chuen", "eb", "ben", "ix", "mem",
                 "cib", "caban", "eznab", "canac", "ahau"};

int main()
{
    map<string, int> haab;
    for (int i = 0; i < 18; i++)
      haab[months[i]] = 20*i;
    haab["uayet"] = 18*20;
    
    int N;
    unsigned nod, year;
    string mon;
    //char buf[128];
    
    //fgets(buf, sizeof buf, stdin);
    //sscanf(buf, "%d", &N);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        //char b[32];
        char u = 0;
        //fgets(buf, sizeof buf, stdin);
        //sscanf(buf, "%u. %s %u", &nod, b, &year);
        cin >> nod >> u >> mon >> year;
        
        //mon = string(b);
        
        unsigned yy = year*365 + haab[mon] + nod;
        
        unsigned Tzyy = yy / 260;
        //yy = yy%260;
        unsigned Tzdn = yy%13 + 1;
        unsigned Tzmn = yy%20;

        //printf("%u %s %u\n", Tzdn, days[Tzmn].c_str(), Tzyy);
        cout<<Tzdn<<" "<<days[Tzmn]<<" "<<Tzyy<<endl; 
        
    }
    
    //while (getchar() == '\n');
    return 0;
}
*/
#include <stdio.h>
#include <string.h>
#define HAAB 365
#define TZOLKIN 260

const char
haabyear[19][10]={{"pop"},{"no"},{"zip"},{"zotz"},{"tzec"},{"xul"},{"yoxkin"},{"mol"},{"chen"},{"yax"},{"zac"},{"ceh"},{"mac"},{"kankin"},{"muan"},{"pax"},{"koyab"},{"cumhu"},{"uayet"}};
const long
haabday[19]={0,20,40,60,80,100,120,140,160,180,200,220,240,260,280,300,320,340,360};
const char
tzolkinyear[20][10]={{"imix"},{"ik"},{"akbal"},{"kan"},{"chicchan"},{"cimi"},{"manik"},{"lamat"},{"muluk"},{"ok"},{"chuen"},{"eb"},{"ben"},{"ix"},{"mem"},{"cib"},{"caban"},{"eznab"},{"canac"},{"ahau"}};

int main()
{
	long cases;
	long i,j;
	long day;
	char month[10];
	long year;
	long count;
	scanf("%ld",&cases);
	printf("%ld\n",cases);
	for(i=0;i<cases;i++)
	{
		scanf("%ld",&day);
		scanf("%s",&month);
		scanf("%s",&month);
		scanf("%ld",&year);
		for(j=0;j<19;j++)
		{
			if(strcmp(haabyear[j],month)==0)
			{
				count=day+haabday[j]+year*HAAB;
				break;
			}
		}
		printf("%ld %s %ld\n",count%13+1,tzolkinyear[count%20],(count/TZOLKIN));
	}
}
