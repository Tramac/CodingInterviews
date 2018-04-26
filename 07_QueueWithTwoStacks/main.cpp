# include <stack>
# include <stdio.h>

template <typename T> class CQueue
{
public:
	CQueue(void);
	~CQueue(void);

	void appendTail(const T& node);
	T deleteHead();
private:
	std::stack<T> stack1;
	std::stack<T> stack2;
};

template <typename T> void appendTail(const T& node)
{
	stack1.push(T);
}

template <typename T> T deleteHead()
{
	if (stack2.size() <= 0)
	{
		while (stack1.size > 0)
		{
			T& data = stack1.top();
			stack2.push(data);
			stack1.pop()
		}
	}
	if (stack2.size == 0)
		throw std::exception("queue is empty.");
	T head = stack2.top();
	stack2.pop();
	return head;
}
