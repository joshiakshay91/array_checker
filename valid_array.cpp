#include<iostream>
#include<vector>
#include<queue>
#include<list>
using namespace std;
void validty_check();
vector<int> input;
list<int> visited;
list<int> answer;
int curr,pos,jump,size,i;
int main()
{
	int inp=999;
	cout<<"Give input array number hit enter after each number and 0 to terminate input:"<<endl;
	while(inp!=0)
	{
		cin>>inp;
		if(inp !=0) input.push_back(inp);
	}
	size=input.size();//0 to size-1 are indexes
	for(i=0;i<size;i++)
	{
		curr=i;
		pos=input[i];
		validty_check();
		if(visited.size()==size)
		{
			answer.push_back(input[i]);
		}
		while(!visited.empty())
		{
			visited.pop_front();
		}
	}

	if(answer.empty())
	{
		cout<<"No answer"<<endl;
	}
	else
	{
		cout<<"Answer: ";
		while(!answer.empty())
		{
			cout<<answer.front()<<", ";
			answer.pop_front();
		}
		cout<<endl;
	}

	return 0;
}
bool visited_queue(int a)
{
	for(list<int>:: iterator it=visited.begin();it != visited.end();it++)
	{
		if(a==(*it)) return true;
	}
	return false;
}
void validty_check()
{
	if(visited.size()>=size) return;
	visited.push_back(i);
		jump=pos+curr;
		if(jump>(size-1))
		{
			jump=jump-size;
		}
		if(!visited_queue(jump))
		{
			pos=input[pos];
			curr=jump;
			visited.push_back(curr);
		}
		else
		{
			jump=pos-curr;
			if(jump<0)
			{
				jump=size+jump;
			}
			if(!visited_queue(jump))
			{
				pos=input[pos];
				curr=jump;
				visited.push_back(curr);
			}else{
				return;
			}
		}
    validty_check();
}
