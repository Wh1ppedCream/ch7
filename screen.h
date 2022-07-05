#include <string>


class Screen {
	public:
		using pos = std::string::size_type;

		Screen() = default;
		Screen(pos a, pos b) : height(a), width(b), contents((a * b), ' ') { };
		Screen(pos a, pos b, char c) : height(a), width(b), contents((a * b), c) { };

		char get() const
			{return contents[cursor]};
	private:
		std::string contents;
		pos cursor = 0;
		pos height = 0;
		pos width = 0;
}

