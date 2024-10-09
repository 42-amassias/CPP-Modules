#ifndef  RPN_HPP
# define RPN_HPP

# include <string>
# include <stack>

# define OPERATOR_TABLE_SIZE (6)

class RPN
{
	public:
		static int	calculate(std::string const& expr);

	private:
		RPN(void);
		RPN(RPN const& o);
		~RPN(void);

	private:
		RPN&	operator=(RPN const& o);
		void	operator<<(char const& c);
	
	private:
		void	sub(void);
		void	add(void);
		void	div(void);
		void	mul(void);
	
	private:
		static void		(RPN::*const operatorTable[OPERATOR_TABLE_SIZE])(void);
		std::stack<int>	m_stack;
};

#endif
