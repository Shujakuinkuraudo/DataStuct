#include "head.h"

int main()
{
	SeqQueue<int> s;
	_for(i,0,50)
	{
		s.EnQueue(i);
		cout << s.DeQueue() << endl;
	}
	return 0;
}