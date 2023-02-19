#pragma once
#include "head.h"
int BFMatch(char *s, char *t);
class KMPMatch
{
	int *next_;
	int *nextval_;
	void Gennext(char *t, int n);
	void Gennextval(char *t, int n);
	int KMP(char *s, char *t, int n1, int n2);

public:
	int operator()(char *s, char *t, int n1, int n2)
	{
		next_ = new int[n2];
		nextval_ = new int[n2];
		return KMP(s, t, n1, n2);
	}
};

#include "match.ipp"