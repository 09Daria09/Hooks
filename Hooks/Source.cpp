#include <iostream>
#include <time.h>
using namespace std;

class Stack
{
	// Нижняя и верхняя границы стека
	enum { EMPTY = -1, FULL = 20 };
	// Массив для хранения данных
	char st[FULL + 1];
	// Указатель на вершину стека
	int top;

public:
	// Конструктор
	Stack();

	// Добавление элемента
	void Push(char c);

	// Извлечение элемента
	char Pop();

	// Очистка стека
	void Clear();

	// Проверка существования элементов в стеке
	bool IsEmpty();

	// Проверка на переполнение стека
	bool IsFull();

	// Количество элементов в стеке
	int GetCount();

	char Top();

	void Output()
	{
		for (int i = 0; i < top + 1; i++)
		{
			cout << st[i] << " ";
		}
		cout << endl;
	}
};


Stack::Stack()
{
	top = EMPTY;
}

void Stack::Clear()
{
	top = EMPTY;
}

bool Stack::IsEmpty()
{
	return top == EMPTY;
}

bool Stack::IsFull()
{
	return top == FULL;
}

int Stack::GetCount()
{
	return top + 1;
}

char Stack::Top()
{
	return st[top];
}

void Stack::Push(char c)
{
	if (!IsFull())
		st[++top] = c;
}

char Stack::Pop()
{
	if (!IsEmpty())
		return st[top--];
	else
		return 0;
}

void main()
{
	srand(time(0));
	Stack ST;
	char v[20] = { "(3+5-{89}[]7" };
	cout << "Enter your expression: ";
	//cin >> v;
	int size = strlen(v);
	for (int i = 0; i < size; i++)
	{
		if (v[i] == ')' || v[i] == ']' || v[i] == '}')
		{
			ST.Push(v[i]);
		}
	}
	for (int i = 0; i < size; i++)
	{
		cout << v[i];
	}
	cout << endl;
	char b[20];
	int j = 0;
	for (int i = 0; i < size; i++)
	{
		if (v[i] == '(' || v[i] == '[' || v[i] == '{')
		{
			b[j] = v[i];
			j++;
		}
	}
	b[j] = '\0';
	int sizee;
	sizee = strlen(b);
	if (sizee != ST.GetCount())
	{
		cout << "Unequal number of brackets" << endl;
		return;
	}
	for (int i = j-1; ST.IsEmpty() != 1; i--)
	{
		if (b[i] == '(' && ST.Top() == ')'|| b[i] == '[' && ST.Top() == ']'|| b[i] == '{' && ST.Top() == '}')
		{
			ST.Pop();
	    }
		else
		{
			cout << "Syntax error: " << b[i] << endl;
			return;
		}
	}
	cout << "Everything works correctly" << endl;
}

