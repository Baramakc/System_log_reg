#include <iostream>
#include <fstream>

/*  1) Сделать в потоках начало программу и подгрузку в map(чтобы не было одинаковых имён при регестрации)
	И там в самом map искать пользователя. Из txt файлов идёт подгрузка и загрузка новых пользователей
	2) Изменения пароля и логина
	3) Может быть если забыл логин или пароль сделать проверку
*/	

class Reg_Log {
	bool reg_or_log;
	std::string username;
	std::string password;
public:
	void set_username() {
		std::cout << "Input your username: "; std::cin >> username;
	}
	void set_password() {
		std::cout << "Input your password: "; std::cin >> password;
	}
	std::string get_username() {
		return this->username;
	}
	std::string get_password() {
		return this->password;
	}

	bool get_reg_or_log() {
		return this->reg_or_log;
	}
	void registration() {
		set_username();
		set_password();
		std::ofstream fail("D:\\MyProgects\\Reg_Log\\" + get_username() + ".txt");
		fail << get_username() << std::endl << get_password();
		fail.close();
	}
	void login() {
		set_username();
		set_password();
		std::ifstream fail("D:\\MyProgects\\Reg_Log\\" + get_username() + ".txt");
		if (fail.is_open()) {
			std::string b_username;
			std::string b_password;
			fail >> b_username >> b_password;
			if (b_password == get_password()) std::cout << "You are logged!" << std::endl;
			else std::cout << "Uncorrect password!";
		}
		else std::cout << "Your account don't registration!";
	}
	void program() {
		std::cout << "Input your variant: \nRegistation - 1 \nLogin - 2" << std::endl;
		int buffer;
		do {
			std::cout << "Input: "; std::cin >> buffer;
			if (buffer == 1) reg_or_log = 1;
			else if (buffer == 2) reg_or_log = 0;
			else {
				std::cout << "Uncorrect number!" << std::endl;
			}
		} while (buffer != 1 && buffer != 2);
		if (get_reg_or_log()) registration();
		else login();
	}
};

int main() {
	Reg_Log rl;
	rl.program();
}