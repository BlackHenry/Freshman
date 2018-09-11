#include "stdafx.h"
#include "analyzer.h"

//Функція для перевірки змінної на ініціалізованність

bool Analyzer::init(string name) {
	for (int i = 0; i < vars.size(); i++) {
		if (vars[i].first == name)
			return true;
	}
	return false;
}

//Вираз = {ІД | Число, Мат_оператор}, ІД | Число

int Analyzer::is_expression(int position) {
	while (((code[position].first == id_type && init(code[position].second))
		|| code[position].first == num_type) && (code[position + 1].first == num_op_type
			|| (code[position + 1].first == logic_op_type && code[position + 1].second != "="))) {
		position += 2;
		if (position >= code.size()) {
			cout << "Unexpected end!\n";
			return 0;
		}
	}
	if (code[position].second == "(") {
		int a = is_expression(position + 1);
		if (!a) {
			cout << position << ": " << "Expression in parenthesis isn't valid!\n";
			return 0;
		}
		position = a;
		position++;
		if (position >= code.size()) {
			cout << "Unexpected end!\n";
			return 0;
		}
		if (code[position].second != ")") {
			cout << position << ": " << "Expected closing parenthesis in expression!\n";
			return 0;
		}
		position++;
		if (position >= code.size()) {
			cout << "Unexpected end!\n";
			return 0;
		}
		if (code[position].first == num_op_type || code[position].first == logic_op_type) {
			a = is_expression(position + 1);
			if (!a) {
				cout << position << ": " << "Expression after parenthesis isn't valid!\n";
				return 0;
			}
			return a;
		}
		else {
			return position - 1;
		}

	}

	if (!((code[position].first == id_type && init(code[position].second)) || code[position].first == num_type)) {
		cout << position << ": " << "Last argument in expression isn't valid!\n";
		return 0;
	}
	if (code[position + 1].first != num_op_type && code[position + 1].first != logic_op_type)
		return position;
	return 0;
}

//Присвоєння = ІД, ("++" | "--") | ( [Мат_оператор], "=", Вираз), ";"  

int Analyzer::is_assigment(int position) {
	if (!(code[position].first == id_type && init(code[position].second))) {
		return 0;
	}
	position++;
	if (position >= code.size()) {
		cout << "Unexpected end!\n";
		return 0;
	}
	if (code[position].first == num_op_type) {
		position++;
		if (position >= code.size()) {
			cout << "Unexpected end!\n";
			return 0;
		}
		if (code[position - 1].second == "+" || code[position - 1].second == "-") {
			if (code[position].second == code[position - 1].second) {
				position++;
				if (position >= code.size()) {
					cout << "Unexpected end!\n";
					return 0;
				}
				if (code[position].second != ";") {
					cout << "Expected semicolon after increment/decrement!\n";
					return 0;
				}
				return position;
			}
		}
	}
	if (code[position].second != "=") {
		cout << position << ": " << "Expected \"=\" after variable name!\n";
		return 0;
	}
	position++;
	if (position >= code.size()) {
		cout << "Unexpected end!\n";
		return 0;
	}
	int a = is_expression(position);
	if (!a) {
		cout << position << ": " << "Expression after \"=\" expected!\n";
		return 0;
	}
	position = a + 1;
	if (position >= code.size()) {
		cout << "Unexpected end!\n";
		return 0;
	}
	if (code[position].second != ";") {
		cout << position << ": " << "Expected semicolon after assigment!\n";
		return 0;
	}
	return position;
}

//Присвоєння без крапки з комою

int Analyzer::is_assigment_without_semicolon(int position) {
	if (!(code[position].first == id_type && init(code[position].second))) {
		return 0;
	}
	position++;
	if (position >= code.size()) {
		cout << "Unexpected end!\n";
		return 0;
	}
	if (code[position].first == num_op_type) {
		position++;
		if (position >= code.size()) {
			cout << "Unexpected end!\n";
			return 0;
		}
		if (code[position - 1].second == "+" || code[position - 1].second == "-") {
			if (code[position].second == code[position - 1].second) {
				return position;
			}
		}
	}
	if (code[position].second != "=") {
		cout << position << ": " << "\"=\" expected!\n";
		return 0;
	}
	position++;
	if (position >= code.size()) {
		cout << "Unexpected end!\n";
		return 0;
	}
	int a = is_expression(position);
	if (!a) {
		cout << position << ": " << "Expression after \"=\" expected!(in assigment)\n";
		return 0;
	}
	position = a;
	return position;
}

//Повернення = "return", Вираз, ";"

int Analyzer::is_return(int position) {
	if (code[position].second != "return")
		return 0;
	position++;
	if (position >= code.size()) {
		cout << "Unexpected end!\n";
		return 0;
	}
	int a = is_expression(position);
	if (!a) {
		cout << position << ": " << "Expected return value\n";
		return 0;
	}
	position = a + 1;
	if (position >= code.size()) {
		cout << "Unexpected end!\n";
		return 0;
	}
	if (code[position].second != ";") {
		cout << position << ": " << "Expected semicolon after return statement!\n";
		return 0;
	}
	return position;
}

//Оголошення = Неознач_ІД, ["=", Вираз]

int Analyzer::is_declaration(int position) {
	string name = "";
	if (code[position].first == type_type) {
		position++;
		if (position >= code.size()) {
			cout << "Unexpected end!\n";
			return 0;
		}
		if (code[position].first == id_type && !init(code[position].second)) {
			name = code[position].second;
			position++;
			if (position >= code.size()) {
				cout << "Unexpected end!\n";
				return 0;
			}
			if (code[position].second == "=") {
				position++;
				if (position >= code.size()) {
					cout << "Unexpected end!\n";
					return 0;
				}
				int a = is_expression(position);
				if (!a) {
					cout << position << ": " << "Expected expression after \"=\" (in declaration)\n";
					return 0;
				}
				position = a + 1;
				if (position >= code.size()) {
					cout << "Unexpected end!\n";
					return 0;
				}
			}
		}
	}
	else {
		return 0;
	}
	if (code[position].second == ";") {
		vars.push_back(make_pair(name, 1));
		return position;
	}
	else {
		cout << position << ": " << "Expected semicolon after declaration!\n";
		return 0;
	}
}

//If = "if", "(", Вираз, ")", Команда | "{", {Команда}, "}", ["else", Команда | "{", {Команда}, "}"]

int Analyzer::is_if(int position) {
	if (code[position].second == "if") {
		position++;
		if (position >= code.size()) {
			cout << "Unexpected end!\n";
			return 0;
		}
		if (code[position].second != "(") {
			cout << position << ": " << "Parenthesis expected after if/while!\n";
			return 0;
		}
		position++;
		if (position >= code.size()) {
			cout << "Unexpected end!\n";
			return 0;
		}
		int a = is_expression(position);
		if (!a) {
			cout << position << ": " << "Expected expression in parenthesis!\n";
			return 0;
		}
		position = a + 1;
		if (position >= code.size()) {
			cout << "Unexpected end!\n";
			return 0;
		}
		if (code[position].second != ")") {
			cout << position << ": " << "Closing parenthesis in if/while expected!\n";
			return 0;
		}
		position++;
		if (position >= code.size()) {
			cout << "Unexpected end!\n";
			return 0;
		}
		if (code[position].second == "{") {
			position++;
			if (position >= code.size()) {
				cout << "Unexpected end!\n";
				return 0;
			}
			a = is_line(position);
			while (a) {
				position = a + 1;
				if (position >= code.size()) {
					cout << "Unexpected end!\n";
					return 0;
				}
				a = is_line(position);
			}
			if (code[position].second != "}") {
				cout << position << ": " << "Closing braces expected!\n";
				return 0;
			}
		}
		else {
			a = is_line(position);
			if (!a) {
				cout << position << ": " << "Command line expected!\n";
				return 0;
			}
			position = a;
		}
	}
	else {
		return 0;
	}
	if (code[position + 1].second == "else") {
		position += 2;
		if (code[position].second == "{") {
			position++;
			if (position >= code.size()) {
				cout << "Unexpected end!\n";
				return 0;
			}
			int a = is_line(position);
			while (a) {
				position = a + 1;
				if (position >= code.size()) {
					cout << "Unexpected end!\n";
					return 0;
				}
				a = is_line(position);
			}
			if (code[position].second != "}") {
				cout << position << ": " << "Closing braces expected!\n";
				return 0;
			}
		}
		else {
			int a = is_line(position);
			if (!a) {
				cout << position << ": " << "Command line expected!\n";
				return 0;
			}
			position = a;
		}
	}
	return position;
}

//While = "while", "(", Вираз, ")", Команда | "{", {Команда}, "}"

int Analyzer::is_while(int position) {
	if (code[position].second == "while") {
		position++;
		if (position >= code.size()) {
			cout << "Unexpected end!\n";
			return 0;
		}
		if (code[position].second != "(") {
			cout << position << ": " << "Parenthesis expected after if/while!\n";
			return 0;
		}
		position++;
		if (position >= code.size()) {
			cout << "Unexpected end!\n";
			return 0;
		}
		int a = is_expression(position);
		if (!a) {
			cout << position << ": " << "Expected expression in parenthesis!\n";
			return 0;
		}
		position = a + 1;
		if (position >= code.size()) {
			cout << "Unexpected end!\n";
			return 0;
		}
		if (code[position].second != ")") {
			cout << position << ": " << "Closing parenthesis in if/while expected!\n";
			return 0;
		}
		position++;
		if (position >= code.size()) {
			cout << "Unexpected end!\n";
			return 0;
		}
		if (code[position].second == "{") {
			position++;
			if (position >= code.size()) {
				cout << "Unexpected end!\n";
				return 0;
			}
			a = is_line(position);
			while (a) {
				position = a + 1;
				if (position >= code.size()) {
					cout << "Unexpected end!\n";
					return 0;
				}
				a = is_line(position);
			}
			if (code[position].second != "}") {
				cout << position << ": " << "Closing braces expected!\n";
				return 0;
			}
		}
		else {
			a = is_line(position);
			if (!a) {
				cout << position << ": " << "Command line expected!\n";
				return 0;
			}
			position = a;
		}
	}
	else {
		return 0;
	}
	return position;
}


//For = "for", "(", Оголошення | Присвоєння, Вираз, Присвоєння без крапки з комою, ")", Команда | "{", {Команда}, "}" 

int Analyzer::is_for(int position) {
	if (!(code[position].second == "for")) {
		return 0;
	}
	position++;
	if (position >= code.size()) {
		cout << "Unexpected end!\n";
		return 0;
	}
	if (code[position].second != "(") {
		cout << position << ": " << "Parenthesis expected!\n";
		return 0;
	}
	position++;
	if (position >= code.size()) {
		cout << "Unexpected end!\n";
		return 0;
	}
	int a = is_assigment(position) | is_declaration(position);
	if (!a) {
		cout << position << ": " << "Declaration or assigned expected!\n";
		return 0;
	}
	position = a + 1;
	if (position >= code.size()) {
		cout << "Unexpected end!\n";
		return 0;
	}
	a = is_expression(position);
	if (!a) {
		cout << position << ": " << "Expected expression in second \"for\" argument!\n";
		return 0;
	}
	position = a + 1;
	if (position >= code.size()) {
		cout << "Unexpected end!\n";
		return 0;
	}
	if (code[position].second != ";") {
		cout << position << ": " << "Expected semicolon after second \"for\" argument!\n";
		return 0;
	}
	position++;
	if (position >= code.size()) {
		cout << "Unexpected end!\n";
		return 0;
	}
	a = is_assigment_without_semicolon(position);
	if (!a) {
		cout << position << ": " << "Expected assigment in third \"for\" argument !\n";
		return 0;
	}
	position = a + 1;
	if (position >= code.size()) {
		cout << "Unexpected end!\n";
		return 0;
	}
	if (code[position].second != ")") {
		cout << position << ": " << "Closing parenthesis expected!\n";
		return 0;
	}
	position++;
	if (position >= code.size()) {
		cout << "Unexpected end!\n";
		return 0;
	}
	if (code[position].second == "{") {
		position++;
		if (position >= code.size()) {
			cout << "Unexpected end!\n";
			return 0;
		}
		a = is_line(position);
		while (a) {
			position = a + 1;
			if (position >= code.size()) {
				cout << "Unexpected end!\n";
				return 0;
			}
			a = is_line(position);
		}
		if (code[position].second != "}") {
			cout << position << ": " << "Closing braces expected!\n";
			return 0;
		}
	}
	else {
		a = is_line(position);
		if (!a) {
			cout << position << ": " << "Command line expected!\n";
			return 0;
		}
		position = a;
	}
	return position;
}

//Параметр = Тип, ІД, [ "=", Вираз]

int Analyzer::is_param(int position) {
	if (code[position].first != type_type) {
		return 0;
	}
	position++;
	if (position >= code.size()) {
		cout << "Unexpected end!\n";
		return 0;
	}
	if (code[position].first != id_type) {
		cout << position << ": " << "Parameter id expected!\n";
		return 0;
	}

	if (code[position + 1].second == "=") {
		position++;
		if (position >= code.size()) {
			cout << "Unexpected end!\n";
			return 0;
		}
		int a = is_expression(position);
		if (!a) {
			cout << position << ": " << "Expression after \"=\" expected!\n";
			return 0;
		}
		position = a + 1;
		if (position >= code.size()) {
			cout << "Unexpected end!\n";
			return 0;
		}
	}
	return position;
}

//Функція = Тип, Неознач_ІД, "(", {Параметр},  ")", "{", {Команда}, "}"

int Analyzer::is_func(int position) {
	if (code[position].first != type_type) {
		cout << position << ": " << "Function type expected!\n";
		return 0;
	}
	position++;
	if (position >= code.size()) {
		cout << "Unexpected end!\n";
		return 0;
	}
	if (code[position].first != id_type) {
		cout << position << ": " << "Function name expected!\n";
		return 0;
	}
	position++;
	if (position >= code.size()) {
		cout << "Unexpected end!\n";
		return 0;
	}
	if (code[position].second != "(") {
		cout << position << ": " << "Opening parenthesis expected!\n";
		return 0;
	}
	position++;
	if (position >= code.size()) {
		cout << "Unexpected end!\n";
		return 0;
	}
	while (is_param(position)) {
		position = is_param(position) + 1;
	}
	if (code[position].second != ")") {
		cout << position << ": " << "Closing parenthesis expected!\n";
		return 0;
	}
	position++;
	if (position >= code.size()) {
		cout << "Unexpected end!\n";
		return 0;
	}
	if (code[position].second == "{") {
		position++;
		if (position >= code.size()) {
			cout << "Unexpected end!\n";
			return 0;
		}
		int a = is_line(position);
		while (a) {
			position = a + 1;
			if (position >= code.size()) {
				cout << "Unexpected end!\n";
				return 0;
			}
			a = is_line(position);
		}
		if (code[position].second != "}") {
			cout << position << ": " << "Closing braces expected!\n";
			return 0;
		}
	}
	else {
		cout << position << ": " << "Opening braces expected!\n";
		return 0;
	}
	return position;
}

// Команда = Оголошення | If | While | Присвоєння | Повернення

int Analyzer::is_line(int position) {
	int a = is_declaration(position);
	if (a)
		return a;
	a = is_if(position);
	if (a)
		return a;
	a = is_while(position);
	if (a)
		return a;
	a = is_for(position);
	if (a)
		return a;
	a = is_assigment(position);
	if (a)
		return a;
	a = is_return(position);
	if (a)
		return a;
	return 0;
}

Analyzer::Analyzer()
{
}


Analyzer::~Analyzer()
{
}