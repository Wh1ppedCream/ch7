class Debug {
	public:
		constexpr Debug(bool b = true) : hw(b), io(b), other(b) { }
		constexpr Debug(bool h, i, o) : hw(h), io(i), other(o) { }

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
