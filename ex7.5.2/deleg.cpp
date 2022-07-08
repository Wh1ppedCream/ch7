#include <iostream>

using std::istream;
using std::ostream;
using std::cin;
using std::cout;
using std::endl;

class Date {
	friend istream& read(istream&, Date&);

	public:
		//Nondelegated constructor
		Date(int y, int m, int d) : year(y), month(m), day(d) { };

		//delegated constructors
		Date() : Date(2010, 1, 1) { };
		Date(std::istream &is) : Date() {
			read(is, *this);
		}
		
		//inline function
		ostream& print(ostream &os) {
			os << "Year: " << year << " month: " << month << " day: " << day;
			return os;
		}
	private:
		int year, month, day;
};

istream& read(istream &is, Date &now) {
	is >> now.year >> now.month >> now.day;
	return is;
}

int main()
{
	Date dat1;
	dat1.print(cout) << endl;
	Date dat2(2022, 6, 8);
	dat2.print(cout) << endl;
	Date dat3(cin);
	dat3.print(cout) << endl;
}
