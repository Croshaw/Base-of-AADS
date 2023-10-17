#include "Element.cpp";
template <class T>
class list {
private:
	Element<T>* _begin;
	Element<T>* _end;
	int _count;
public:
	list()
	{
		_begin = _end = nullptr;
		_count = 0;
	}
	list(T data)
	{
		_begin = new Element<T>;
		_begin->data = data;
		_begin->next = nullptr;
		_end = _begin;
		_count++;
	}
	~list() {
		Element<T>* curElem = _begin;
		while (curElem != nullptr) {
			curElem = _begin->next;
			delete _begin;
			_begin = curElem;
		}
	}
	void removeAt(int id)
	{
		if (_count < 1 || id < 0 || id >= _count)
			return;
		Element<T>* delElement;
		if (id == 0)
		{
			delElement = _begin;
			_begin = delElement->next;
		}
		else
		{
			Element<T>* preDelElement = get(id - 1);
			delElement = preDelElement->next;
			preDelElement->next = delElement->next;
			if (id + 1 == _count)
				_end = preDelElement;
		}
		delete delElement;
		_count--;
	}
	void add(T data) 
	{
		Element<T>* newElem = new Element<T>;
		newElem->data = data;
		newElem->next = nullptr;
		_end->next = newElem;
		_end = newElem;
		_count++;
	}
	Element<T>* get(int id) {
		if (_count < 1 || id < 0 || id >= _count)
			return nullptr;
		Element<T>* curElem = _begin;
		while (id > 0 && curElem != nullptr)
		{
			id--;
			curElem = curElem->next;
		}
		return curElem;
	}
	T first() {
		return _begin->data;
	}
	T last() {
		return _end->data;
	}
	int count()
	{
		return _count;
	}
};