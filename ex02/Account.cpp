/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhanenk <ikhanenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 15:50:46 by ikhanenk          #+#    #+#             */
/*   Updated: 2025/05/16 17:43:42 by ikhanenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

// static getters

int	Account::getNbAccounts(void) {return (_nbAccounts);}

int	Account::getTotalAmount(void) {return (_totalAmount);}

int	Account::getNbDeposits(void) {return (_totalNbDeposits);}

int	Account::getNbWithdrawals(void) {return (_totalNbWithdrawals);}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << " accounts:" << getNbAccounts() << ";" \
				<< "total:" << getTotalAmount() << ";" \
				<< "deposits:" << getNbDeposits() << ";" 
				<< "withdrawals:" << getNbWithdrawals() \
				<< std::endl;

}

// display

void	Account::_displayTimestamp(void)
{
	time_t timestamp = time(&timestamp);
	struct tm datetime = *localtime(&timestamp);
	std::cout << "[" << datetime.tm_year + 1900 \
				<< ((datetime.tm_mon + 1) < 10 ? "0" : "") << datetime.tm_mon + 1 \
				<< (datetime.tm_mday < 10 ? "0" : "") << datetime.tm_mday << "_" \
				<< (datetime.tm_hour < 10 ? "0" : "") << datetime.tm_hour \
				<< (datetime.tm_min < 10 ? "0" : "") << datetime.tm_min \
				<< (datetime.tm_sec < 10 ? "0" : "") << datetime.tm_sec << "]";
}

// setters

void	Account::makeDeposit(int deposit)
{
	int p_amount;

	p_amount = _amount;
	_amount += deposit;
	_totalAmount += deposit;
	if (deposit != 0)
	{
		_nbDeposits += 1;
		_totalNbDeposits += 1;
	}
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";" \
				<< "p_amount:" << p_amount << ";" \
				<< "deposit:" << deposit << ";" \
				<< "amount:" << _amount << ";" \
				<< "nb_deposits:" << _nbDeposits \
				<< std::endl;
}

int		Account::checkAmount(void) const
{
	return (_amount);
}

bool	Account::makeWithdrawal(int withdrawal)	
{
	int p_amount;

	p_amount = _amount;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";" \
				<< "p_amount:" << p_amount << ";" \
				<< "withdrawal:";
	if (p_amount - withdrawal >= 0)
	{
		_totalAmount = _totalAmount - withdrawal;
		_amount = _amount - withdrawal;
		_nbWithdrawals += 1;
		_totalNbWithdrawals += 1;
		std::cout << withdrawal << ";" \
				<< "amount:" << _amount << ";" \
				<< "nb_withdrawals:" << _nbWithdrawals \
				<< std::endl;
	}
	else
		std::cout << "refused" << std::endl;
	return (true);
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";" \
				<< "amount:" << checkAmount() << ";" \
				<< "deposits:" << _nbDeposits << ";" \
				<< "withdrawal:" << _nbWithdrawals \
				<< std::endl;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";" \
				<< "amount:" << checkAmount() << ";"
				<< "closed" << std::endl;
}

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	_nbAccounts += 1;
	_accountIndex = _nbAccounts - 1;
	_amount = initial_deposit;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";" \
				<< "amount:" << checkAmount() << ";"
				<< "created" << std::endl;
}































/*
int	main(int argc, char **argv)

{
	// ifstream read_file;
	// std::string line;

	// if (argc != 2)
	// 	return (1);
	// read_file.open ("19920104_091532.log", ios::out);
	// if (read_file.is_open())
	// {
	// 	while (getline(read_file, line))
	// 		std::cout << line << '\n';
	// }
	// else
	// 	std::cout << "Error" << std::endl;
	// if (line.empty())
	// 	std::cout << "FIle is empty" << std::endl;
	// read_file.close();
	return (0);
}
*/
