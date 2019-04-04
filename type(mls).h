#include<iostream>
#include<windows.h>
#include<string>

using namespace std;

class typem
{
	private:
		string type;
	public:
	
		typem(string t)
			{
				type=t;
			}
		void printmls(int mls)
		{
			int k=0;
		for(int n=0;k==0;n++)
			{
				if(type[n]=='|')
					break;
				cout<<type[n];
				Sleep(mls);
			}
		}
};		


