#include <iostream>
#include <fstream>

/*  1) Сделать в потоках начало программу и подгрузку в map(чтобы не было одинаковых имён при регестрации)
	И там в самом map искать пользователя. Из txt файлов идёт подгрузка и загрузка новых пользователей
	2) Удаление при перерегестрации
	3) Может быть если забыл логин или пароль сделать проверку
	4)
*/	

class Reg_Log {
	bool reg_or_log;
	std::string username;
	std::string password;
	std::string word;
public:
	void set_username() {
		std::cout << "Input your username: "; std::cin >> username;
	}
	void set_password() {
		std::cout << "Input your password: "; std::cin >> password;
	}
	void set_word() {
		std::cout << "Input your word for help: "; std::cin >> word;
	}
	std::string get_username() {
		return this->username;
	}
	std::string get_password() {
		return this->password;
	}
	std::string get_word() {
		return this->word;
	}
	bool get_reg_or_log() {
		return this->reg_or_log;
	}

	void registration() {
		set_username();
		set_password();
		set_word();
		std::ofstream fail("D:\\MyProgects\\Reg_Log\\" + get_username() + ".txt");
		fail << get_username() << std::endl << get_password() << std::endl << get_word();
		fail.close();
		std::cout << "You have registered";
	}
	void login() {
		set_username();
		set_password();
		std::ifstream fail("D:\\MyProgects\\Reg_Log\\" + get_username() + ".txt");
		if (fail.is_open()) {
			std::string b_username, b_password, b_word;
			fail >> b_username >> b_password >> b_word;

			if (b_password == get_password()) std::cout << "You are logged!" << std::endl;
			else {
				while (true) {
					std::cout << "Uncorrect password!" << std::endl;
					std::cout << "Input your variant: \nInput password again - 1 \nRecreate account - 2\n";
					int choise; std::cin >> choise;
					if (choise == 1) {
						login();
						break;
					}
					else if (choise == 2) {
						std::string exam_word;
						std::cout << "Input your word: "; std::cin >> exam_word;
						if (exam_word == b_word) {
							registration();
							break;
						}
						else {
							std::cout << "Uncorrect word!";
							break;
						}
					}
				}
				
			}
		}
		else std::cout << "Your username don't registration!" << std::endl;
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