
#include <stack>
#include "Stack.hpp"

int main()
{
	std::stack<int> stack;
	ft::stack<int> ft_stack;

	std::cout << "size stack = " << stack.size() << std::endl;
	std::cout << "size ft_stack = " << ft_stack.size() << std::endl;
	stack.push(42);
	ft_stack.push(21);
	std::cout << "size stack = " << stack.size() << std::endl;
	std::cout << "size ft_stack = " << ft_stack.size() << std::endl;
	std::cout << "top stack = " << stack.top() << std::endl;
	std::cout << "top ft_stack = " << ft_stack.top() << std::endl;
	stack.push(88);
	ft_stack.push(99);
	std::cout << "top stack = " << stack.top() << std::endl;
	std::cout << "top ft_stack = " << ft_stack.top() << std::endl;
	stack.pop();
	ft_stack.pop();
	std::cout << "top stack = " << stack.top() << std::endl;
	std::cout << "top ft_stack = " << ft_stack.top() << std::endl;
}