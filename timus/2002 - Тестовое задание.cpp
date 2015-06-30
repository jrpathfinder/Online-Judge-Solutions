#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

struct Account {
	Account(int isLogin, int isDeleted, std::string login, std::string password) {
		this->isLogin = 0;
		this->isDeleted = 0;
		this->login = login;
		this->password = password;
	}

	int isLogin;
	int isDeleted;
	std::string login;
	std::string password;

	int statusDeleted() {
		return this->isDeleted;
	}

	int statusLogin() {
		return this->isLogin;
	}

	void authorization(std::string pswd) {
		if(this->password != pswd) {
			std::cout << "fail: incorrect password" << std::endl;
			return;
		}
		if(this->isLogin == 1) {
			std::cout << "fail: already logged in" << std::endl;
			return;
		}
		if(this->password == pswd) {
			std::cout << "success: user logged in" << std::endl;
			this->isLogin = 1;
			return;
		}
	}

	void logout() {
		if(this->isLogin == 0) {
			std::cout << "fail: already logged out" << std::endl;
		}
		if(this->isLogin == 1) {
			std::cout << "success: user logged out" << std::endl;
			this->isLogin = 0;
		}
	}
};

struct find_id : std::unary_function<Account, bool> {
	std::string login;
	find_id(std::string login) : login(login) { }
	bool operator()(Account const& m) const {
		return m.login == login;
	}
};

std::vector<Account> users;

int main() {
	int n;
	
#ifndef ONLINE_JUDGE
	freopen("in.txt", "rt", stdin);
#endif
	std::cin >> n;

	std::string command;
	for(int i = 0; i < n + 1; i++) {
		getline(std::cin, command);

		if( command.find("register") != std::string::npos ) {
			std::string substring = command.substr(command.find(" ") + 1);
			std::string login = substring.substr(0, substring.find(" "));
			std::string password = substring.substr(substring.find(" ") + 1);

			if(std::find_if(users.begin(), users.end(), find_id(login)) == users.end()) {
				users.push_back(Account(0, 0, login, password));
				std::cout << "success: new user added" << std::endl;
			}		
			else
				std::cout << "fail: user already exists" << std::endl;
		}

		if(command.find("login") != std::string::npos) {
			std::string substring = command.substr(command.find(" ") + 1);
			std::string login = substring.substr(0, substring.find(" "));
			std::string password = substring.substr(substring.find(" ") + 1);

			auto it = std::find_if(users.begin(), users.end(), find_id(login));
			if(it == users.end()) {
				std::cout << "fail: no such user" << std::endl;
			}		
			else {
				it->authorization(password);
			}
		}

		if(command.find("logout") != std::string::npos) {
			std::string substring = command.substr(command.find(" ") + 1);
			std::string login = substring.substr(0, substring.find(" "));
			
			auto it = std::find_if(users.begin(), users.end(), find_id(login));
			if(it == users.end()) {
				std::cout << "fail: no such user" << std::endl;
			}		
			else {
				it->logout();
			}
		}

	}
	
	return 0;
}