#include <string>
#include <iostream>

class Person;
std::istream& read(std::istream&, Person);

class Person {
	friend std::istream& read(std::istream&, Person);
	friend std::ostream& print(std::ostream& const Person);

	public:
	//Constructors:
	Person(const std::string &str) : name(str) { };
	Person() : default;
	Person(const std::string &str1, const std::string &str2) : name(str1), address(str2) { };
	Person(std::istream &is) {
		read(is, *this);
	}

	//member functions:
	std::string get_name() const {
		return name;
	}
	std::string get_address() const {
		return address;
	}
	
	private:
	//data:
	std::string name;
	std::string address;
};

std::istream& read(std::istream& is, Person &per) {
	is >> per.name >> per.address;
	return is;
}

std::ostream& print(std::ostream& os,const Person &pir) {
	os << pir.name << " " << pir.address;
	return os;
}

