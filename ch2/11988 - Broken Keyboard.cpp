#include<iostream>
#include<list>

using namespace std;

void printList(list<char> lst)
{
	list<char> lst2;
	list<char>::iterator it, it2, it3;
	list<char>::reverse_iterator it4;
	char temp;
	for(it = lst.begin(); it != lst.end(); )
	{
		if(*it=='[')
		{
			it3=it;
			it++;
			lst.erase(it3);
			lst2.list::clear();
			while(*it != '[' && *it!=']' && it != lst.end())
			{
				temp = *it;
				it3 = it;
				it++;
				lst.erase(it3);
				lst2.push_back(temp);
			}
			for(it4 = lst2.rbegin(); it4 != lst2.rend(); it4++)
				lst.push_front(*it4);
		}
		else
			it++;
	}
	lst.remove(']');
	for(it = lst.begin(); it!= lst.end(); it++)
		cout << *it;
}

int main()
{
	char in;
	list<char> lst;
	while(true)
	{
		if(scanf("%c", &in) == EOF)
			return 0;


		if(in == '\n')
		{
			printList(lst);
			lst.list::clear();
			cout << endl;
			continue;
		}
		lst.push_back(in);
	}
}
