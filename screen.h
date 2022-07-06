#ifndef CP5_ex7_27_h
#define CP5_ex7_27_h

#include <string>
#include <iostream>


class Screen {
	public:
		//type alias
		using pos = std::string::size_type;

		Screen() = default;    //required as screen has multiple constructors, 
				       //cursor initialized to 0
		Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht * wd, ' ') { }
		Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) { }
		

		//member functions
		char get() const              // gets character at cursor
		{
			return contents[cursor];
		}
		char get(pos ht, pos wd) const 
		{ 
			return contents[ht * width + wd]; 
		}
		
		inline Screen& set(pos, pos, char);
                inline Screen &set(char);
		
		Screen &move(pos r, pos c);	

		Screen &display(std::ostream &os) {
			do_display(os);
			return *this;
		}
		const Screen display(std::ostream &os) const {
			do_display(os);
			return *this;
		}

	private:
		void do_display(std::ostream &os) const 
		{
			os << contents << '\n';
		}

		// contents holds contents of screen, cursor is position of cursor 
		// and height and width is height and width of screen
		pos cursor = 0;
    		pos height = 0, width = 0;
    		std::string contents;
};

inline
// we can specify inline on the definition
Screen &Screen::move(pos r, pos c)
{
	pos row = r * width; // compute the row location
	cursor = row + c;
	// move cursor to the column within that row
	return *this;
	// return this object as an lvalue
}

inline Screen &Screen::set(pos row, pos col, char a) {
	contents[(row * width) + col] = a;            //set specified location to given value
	return *this;                                 // return object
}

inline Screen &Screen::set(char a) {
	contents[cursor] = a;      //set new value at cursor location
	return *this;              // return the object
}

#endif
