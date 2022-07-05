#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>
#include <iostream>

using std::istream;
using std::ostream;

struct Sales_data;
istream& read(istream&, Sales_data&);

struct Sales_data {
	friend Sales_data add(Sales_data&, Sales_data&);
	friend istream& read(istream&, Sales_data&);
	friend ostream& print(ostream&, Sales_data&);

	public:
	//constructors:
	Sales_data() : price_ave(0.0), units_sold(0), revenue(0.0) { };
	Sales_data(const std::string &s) : bookNo(s) { };
	Sales_data(const std::string &s, double a, unsigned u) :
	       	bookNo(s), price_ave(a), units_sold(u), revenue(u * a) { };
	Sales_data(istream &is) {
		read(is, *this);
	}



	//member function in class type
	double avg_price() const;
	std::string isbn() const {
		return bookNo;
	};
	Sales_data& combine(const Sales_data &rhs);

	private:
	std::string bookNo;
	double price_ave = 0.0;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

//adds the ()'d sales_data to the called one
Sales_data& Sales_data::combine(const Sales_data& rhs) {
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

inline double Sales_data::avg_price() const
{
	return ((units_sold == 0) ? 0 : revenue / units_sold);
}

//class-related non-member functions:
Sales_data add(Sales_data& lhs, Sales_data& rhs) {
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}

istream& read(istream &is, Sales_data &rhs) {
	is >> rhs.bookNo >> rhs.price_ave >> rhs.units_sold;
	rhs.revenue = rhs.price_ave * rhs.units_sold;
	return is;
}

ostream& print(ostream &os, Sales_data &rhs) {
	os << rhs.isbn() << " " << rhs.units_sold << " ";
	os << rhs.revenue;
	return os;
}

#endif
