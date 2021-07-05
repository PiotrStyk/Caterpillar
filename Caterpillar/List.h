

struct ListElement
{
	ListElement * next, *prev;
	char key;
};
class List 
{
private:
	ListElement * front, * back;
public:
	List();
	~List();
	void push_front(ListElement *s);
	void push_back(ListElement *s);
	ListElement * pop_front();
	ListElement * pop_back();

};