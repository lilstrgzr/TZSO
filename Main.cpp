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

	bool operator<(const Worker& other) const {
		if (surname != other.surname)
			return surname < other.surname;
		if (name != name)
			return name < other.name;
		return number < other.number;
	}
	
	void print_workers_name() const {
		std::cout << name << " " << surname << " " << number << "\n";
	};

	void print_workers_surname() const {
		std::cout << surname << name << " "  << " " << number << "\n";
	};

	void print_workers_numbers() const {
		std::cout << number << surname << " " << name << " "  << "\n";
	};
};

bool Names(const Worker& p1, const Worker& p2) {
	return p1.getName() < p2.getName();
}


bool Surnames(const Worker& p1, const Worker& p2) {
	return p1.getSurname() < p2.getSurname();
}

bool Numbers(const Worker& p1, const Worker& p2) {
	return p1.getNumber() < p2.getNumber();
}

int main() {
	setlocale(LC_ALL, "russian");


	std::vector<Worker>managers{Worker("Иван", "Иванов", 3515454), Worker("Иван", "Сидоров", 3515422), Worker("Олег", "Сидоров", 23515423), Worker("Иван","Петров", 3515455),};


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
			std::sort(managers.begin(), managers.end(), Names);
			for (const auto& Worker : managers) {
				Worker.print_workers_name();
			}
			break;
			}
		case 2: {
			std::sort(managers.begin(), managers.end(), Surnames);
			for (const auto& Worker : managers) {
				Worker.print_workers_surname();
			}
			break;
			}
		case 3:{
			std::sort(managers.begin(), managers.end(), Numbers);
			for (const auto& Worker : managers) {
				Worker.print_workers_numbers();
			}
			break;
			}
		}
	} while (i != true);




	return 0;
}