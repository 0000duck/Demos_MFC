#pragma once

#include <deque>
#include <iostream>
//using namespace std;
using std::deque;

//����汾deprecated������Image_Processing��İ汾(stock.h)

template<class T>
class Stock
{
public:
	Stock(int capacity):capacity(capacity) { sz = 0; curIdx = -1; }
	~Stock(void) { stock.clear(); }
	int add(T &obj);
	int getIdx() { return curIdx; }
	const int size() const { return sz; }
	bool cur(T &);
	bool pre(T &);
	bool next(T &);
	bool first(T &);
	void clear() { stock.clear(); curIdx = -1; sz = 0; }
private:
	deque<T> stock;
	int curIdx; //��ǰָ��
	int sz; //��ǰ����
	const int capacity; //�������
};

