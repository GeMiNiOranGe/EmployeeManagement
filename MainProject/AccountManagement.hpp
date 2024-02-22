#pragma once
#ifndef ACCOUNTMANAGEMENT_HPP
#define ACCOUNTMANAGEMENT_HPP

#include "Account.hpp"
#include "IReader.hpp"
#include "IWriter.hpp"

class AccountManagement :public IReader, public IWriter {
private:
	Account account;
public:
	AccountManagement(const Account & _account = Account());

	const Account & get_account();

	void read_file(std::ifstream & _fin) override;
	void write_file(std::ofstream & _fout) override;

	bool is_success_change_pass(
		std::string _username,
		std::string _current_password,
		std::string _new_password,
		std::string _confirm_new_password
	);

	void create_a_new(std::string _username);
	void delete_by(std::string _username);
};

#endif // end ACCOUNTMANAGEMENT_HPP