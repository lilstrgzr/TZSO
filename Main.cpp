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
	//Конструктор по умолчанию
	Worker() : name(" "), surname(" "), number(0) {}

	//Параметрический конструктор
	Worker(std::string name, std::string surname, unsigned number) {
		this->name = name;
		this->surname = surname;
		this->number = number;
	}

	//Геттер для имени
	std::string getName() const {
		return name;
	}

	//Геттер для фамилии
	std::string getSurname() const {
		return surname;
	}

	//Геттер для номера
	unsigned getNumber() const {
		return number;
	}

	//Оператор перегрузки < 
	bool operator<(const Worker& other) const {
		if (surname != other.surname)
			return surname < other.surname;
		if (name != name)
			return name < other.name;
		return number < other.number;
	}
	 //Функция вывода данных по имени
	void print_workers_name() const {
		std::cout << name << " " << surname << " " << number << "\n";
	};

	//Функция вывода данных по фамилии 
	void print_workers_surname() const {
		std::cout << surname << " " << name << " " << " " << number << "\n";
	};

	//Функция вывода данных по номеру
	void print_workers_numbers() const {
		std::cout << number << " " <<  surname << " " << name << " " << "\n";
	};
};

//Функция сравнения имен
bool Names(const Worker& p1, const Worker& p2) {
	return p1.getName() < p2.getName();
}

//Функция сравнения фамилий
bool Surnames(const Worker& p1, const Worker& p2) {
	return p1.getSurname() < p2.getSurname();
}

//Функция сравнения номеров
bool Numbers(const Worker& p1, const Worker& p2) {
	return p1.getNumber() < p2.getNumber();
}

int main() {
	setlocale(LC_ALL, "russian");

	//Вектор сотрудников
	std::vector<Worker>managers{Worker("Иван", "Иванов", 3515454), Worker("Иван", "Сидоров", 3515422), Worker("Олег", "Сидоров", 23515423), Worker("Иван","Петров", 3515455),};

	//Вывод в консоль исходного вектора
	std::cout << "Входной файл: \n";
	for (const auto& Worker : managers) {
		Worker.print_workers_name();
	}
	std::cout << std::endl;

	//Переменная для запуска бесконечного цикла сортировки
	bool i = false;

	//Цикл выбора параметров сортировки и самой сортировки с использованием switch
	do {
		std::cout << "Выберите способ сортировки: " << "\n";
		std::cout << "1. По Имени \n";
		std::cout << "2. По Фамилии \n";
		std::cout << "3. По номеру \n";
		int choice;
		std::cin >> choice;
		switch (choice) {
		case 1: {
			std::cout << "Вы выбрали сортировку по Имени! Ваш результат: \n";
			std::sort(managers.begin(), managers.end(), Names);
			for (const auto& Worker : managers) {
				Worker.print_workers_name();
			}
			std::cout << std::endl;
			break;
			}
		case 2: {
			std::cout << "Вы выбрали сортировку по Фамилии! Ваш результат: \n";
			std::sort(managers.begin(), managers.end(), Surnames);
			for (const auto& Worker : managers) {
				Worker.print_workers_surname();
			}
			std::cout << std::endl;
			break;
			}
		case 3:{
			std::cout << "Вы выбрали сортировку по Номеру! Ваш результат: \n";
			std::sort(managers.begin(), managers.end(), Numbers);
			for (const auto& Worker : managers) {
				Worker.print_workers_numbers();
			}
			std::cout << std::endl;
			break;
			}
		}
	} while (i != true);




	return 0;
}