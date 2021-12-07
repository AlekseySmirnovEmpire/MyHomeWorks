#include <iostream>
#include <vector>
#include <string>

enum eCommands
{
	ADD = 1,
	CALL,
	SMS,
	EXIT
};

class PhoneBook
{
private:
	std::string m_name = "";
	std::string m_number = "";

public:
	std::string getNumber() { return m_number; }
	std::string getName() { return m_name; }

	void setNumber(std::string& number) { m_number = number; }
	void setName(std::string& name) { m_name = name; }
};

bool isCorrectNumber(std::string& number) {

	for (int i = 2; i < number.length(); ++i) {

		if (number[i] < '0' || number[i] > '9') return false;
	}

	return (number[0] != '+' || number[1] != '7') && number.length() == 12;
}

bool isNumberNew(std::string& number, std::vector<PhoneBook>& book) {

	if (book.size() != 0) {

		for (int i = 0; i < book.size(); ++i) {

			if (number == book[i].getNumber()) return false;
		}
	}

	return true;
}

bool isNewContact(std::string& name, std::vector<PhoneBook>& book) {

	if (book.size() != 0) {

		for (int i = 0; i < book.size(); ++i) {

			if (name == book[i].getName()) return false;
		}
	}

	return true;
}

class Phone
{
private:
	std::vector<PhoneBook> m_phoneBook;

public:
	void addNumber() {
		std::cout << "Write new number: ";
		std::string inputNumber;
		std::getline(std::cin, inputNumber);

		while (!isNumberNew(inputNumber, m_phoneBook)) {

			std::cout << "Number is already in book! Write another one: ";
			std::getline(std::cin, inputNumber);
		}

		std::cout << "Write name of contact: ";
		std::string inputName;
		std::getline(std::cin, inputName);

		while (!isNewContact(inputName, m_phoneBook)) {

			std::cout << "Contact is already in book! Write another one: ";
			std::getline(std::cin, inputName);
		}

		PhoneBook* temp = new PhoneBook;

		temp->setName(inputName);

		temp->setNumber(inputNumber);

		m_phoneBook.push_back(*temp);

		delete temp;
		temp = nullptr;

		std::cout << "NEW CONTACT ADDED!" << std::endl;
	}

	void callNumber() {

		if (m_phoneBook.size() > 0) {
			std::cout << "Write number (or name) of contact: ";
			std::string input;
			std::getline(std::cin, input);

			bool isFound = false;

			for (int i = 0; i < m_phoneBook.size(); ++i) {

				if (isCorrectNumber(input)) {

					if (m_phoneBook[i].getNumber() == input) {

						std::cout << "Calling to " << m_phoneBook[i].getNumber() << " ..." << std::endl;

						isFound = true;

						break;
					}
				}
				else {

					if (m_phoneBook[i].getName() == input) {

						std::cout << "Calling to " << m_phoneBook[i].getNumber() << " ..." << std::endl;

						isFound = true;

						break;
					}
				}
			}

			std::cout << "No match found!" << std::endl;

		}
		else std::cout << "PhoneBook is empty!" << std::endl;
	}

	void smsNumber() {

		if (m_phoneBook.size() > 0) {
			std::cout << "Write number (or name) of contact: ";
			std::string input;
			std::getline(std::cin, input);

			bool isFound = false;

			for (int i = 0; i < m_phoneBook.size(); ++i) {

				if (isCorrectNumber(input)) {

					if (m_phoneBook[i].getNumber() == input) {

						std::cout << "Message: ";
						std::string message;
						std::getline(std::cin, message);

						std::cout << "Sending to " << m_phoneBook[i].getNumber();

						isFound = true;

						break;
					}
				}
				else {

					if (m_phoneBook[i].getName() == input) {

						std::cout << "Message: ";
						std::string message;
						std::getline(std::cin, message);

						std::cout << "Sending to " << m_phoneBook[i].getName();

						isFound = true;

						break;
					}
				}
			}

			if (!isFound) std::cout << "No match found!" << std::endl;
		}
		else std::cout << "PhoneBook is empty!" << std::endl;
	}
};

void showMenu() {
	std::cout << ADD << ". Add new contact;" << std::endl;
	std::cout << CALL << ". Call contact from phone book;" << std::endl;
	std::cout << SMS << ". Write SMS for contact;" << std::endl;
	std::cout << EXIT << ". Exit programm;" << std::endl;

	std::cout << "Input number of command you wish to do: ";
}


int main() {

	Phone userPhone;

	int userInput;

	do {

		showMenu();
		std::cin >> userInput;
		std::cin.ignore();

		switch (userInput)
		{
		case ADD:
			system("cls");
			userPhone.addNumber();
			break;

		case CALL:
			system("cls");
			userPhone.callNumber();
			break;

		case SMS:
			system("cls");
			userPhone.smsNumber();
			break;

		case EXIT:
			system("cls");
			break;

		default:
			system("cls");
			std::cout << "Wrong input, try again!" << std::endl;
			break;
		}

		std::cout << "-------------------------------------------------" << std::endl;

	} while (userInput != EXIT);

	std::cout << "==================GOODBYE!===================" << std::endl;
}