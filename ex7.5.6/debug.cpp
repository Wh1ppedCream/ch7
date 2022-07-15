class Debug {
	public:
		constexpr Debug(bool b = true) : hw(b), io(b), other(b) { }
		constexpr Debug(bool h, i, o) : hw(h), io(i), other(o) { }
		
		constexpr bool any() {return hw || io || other; }

		//no constexpr as the values will be set to be constant and it also sets the values at compile time,
		//while we might also want to change the values while running the code
		void hw_set(bool h) {
			hw = h;
		}
		void io_set(bool i) {
			io = i;
		}
		void other_set(bool o) {
			other = o;
		}

	private:
		bool hw;
		bool io;
		bool other;
};
