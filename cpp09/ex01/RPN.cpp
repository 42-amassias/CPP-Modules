#include "RPN.hpp"

#include <iostream>

void	(RPN::*const RPN::operatorTable[OPERATOR_TABLE_SIZE])(void) =
{
/* ASCII: 42 => '*' */
&RPN::mul,
/* ASCII: 43 => '+' */
&RPN::add,
/* ASCII: 44 => ',' */
NULL,
/* ASCII: 45 => '-' */
&RPN::sub,
/* ASCII: 46 => '.' */
NULL,
/* ASCII: 47 => '/' */
&RPN::div,
};

int	RPN::calculate(
		std::string const& expr
		)
{
	std::string::const_iterator	itr;
	RPN							rpn;

	for (itr = expr.begin(); itr != expr.end(); ++itr)
		rpn << *itr;
	if (rpn.m_stack.size() != 1)
		throw std::exception();
	return (rpn.m_stack.top());
}

RPN::RPN(void) :
	m_stack()
{
}

RPN::RPN(
	RPN const& o
	)
{
	*this = o;
}

RPN::~RPN(void)
{
}

RPN&	RPN::operator=(
			RPN const& o
			)
{
	if (this == &o)
		return (*this);
	this->m_stack = o.m_stack;
	return (*this);
}

void	RPN::operator<<(
			char const& c
			)
{
	int	id;

	if (c == ' ')
		return ;
	if (std::isdigit(c))
	{
		m_stack.push(c - '0');
		return ;
	}
	/* MAGIC */
	id = c - 42 /* '*' */;
	if (id < 0
		|| id >= OPERATOR_TABLE_SIZE
		|| operatorTable[id] == NULL
		|| m_stack.size() < 2
		)
		throw std::exception();
	(this->*operatorTable[id])();
}

void	RPN::sub(void)
{
	int	a(m_stack.top());

	m_stack.pop();
	m_stack.top() -= a;
}

void	RPN::add(void)
{
	int	a(m_stack.top());

	m_stack.pop();
	m_stack.top() += a;
}

void	RPN::div(void)
{
	int	a(m_stack.top());

	if (a == 0)
		throw std::exception();
	m_stack.pop();
	m_stack.top() /= a;
}

void	RPN::mul(void)
{
	int	a(m_stack.top());

	m_stack.pop();
	m_stack.top() *= a;
}
