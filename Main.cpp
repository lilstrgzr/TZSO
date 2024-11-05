#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

class Worker {
private:
	std::string name;
	std::string surname;
	unsigned number;
public:
	Worker() : name(" "), surname(" "), number(0) {}

	Worker(std::string name, std::string surname, unsigned number) {
		this->name = name;
		this->surname = surname;
		this->number = number;
	}

	std::string getName() const {
		return name;
	}

	std::string getSurname() const {
		return surname;
	}
	unsigned getNumber() const {
		return number;
	}

	void print_workers(){
		std::cout << name << " " << surname << " " << number << "\n\n";
	};
};

int main() {
	setlocale(LC_ALL, "russian");

	Worker W1("Иван", "Иванов", 3515454);
	Worker W2("Иван", "Сидоров", 3515422);
	Worker W3("Олег", "Сидоров", 23515423);
	Worker W4("Иван","Петров", 3515455);

	std::vector<std::string> names{W1.getName(), W2.getName(), W3.getName(), W4.getName(), };
	std::vector<std::string> surnames{ W1.getSurname(),W2.getSurname(), W3.getSurname(), W4.getSurname(), };
	std::vector<unsigned> numbers{ W1.getNumber(),W2.getNumber(), W3.getNumber(), W4.getNumber(), };

	W4.print_workers();

	bool i = false;

	do {
		std::cout << "Выберите способ сортировки: " << "\n";
		std::cout << "1. По Имени \n";
		std::cout << "2. По Фамилии \n";
		std::cout << "3. По номеру \n";
		int choice;
		std::cin >> choice;
		switch (choice) {
		case 1: {
			std::sort(begin(names), end(names));
			for (auto& names: names) {
				std::cout << names << std::endl;
			}
			break;
			}
		case 2: {
			std::sort(begin(surnames), end(surnames));
			for (auto& surnames : surnames) {
				std::cout << surnames << std::endl;
			}
			break;
			}
		case 3:{
			std::sort(begin(numbers), end(numbers));
			for (auto& numbers : numbers) {
				std::cout << numbers << std::endl;
			}
			break;
			}
		}
	} while (i != true);




	return 0;
}