#include <iostream>
#include <cmath>


class Range
{

private:
	double left;
	double right;
public:
	Range() {
		left = -1;
		right = 1;
	}

	bool is_valid(double l, double r) const {
		if (l > r)
		{
			return false;
		}
		else {
			return true;
		}
	}
	
	Range(double l, double r) {
		if (is_valid(l, r))
		{
			this->left = l;
			this->right = r;
		}
		else
		{
			this->left = -1;
			this->right = 1;
		}



	}

	Range(double p) {
		if (p > 0)
		{
			this->left = 0;
			this->right = p;
		}
		else {
			this->left = p;
			this->right = 0;
		}
	}

	Range(const Range& f) {
		this->left = f.left;
		this->right = f.right;
	}

	Range(const Range&& f) noexcept {
		this->left = f.left;
		this->right = f.right;
	}

	~Range() {}


	bool belongs_to_range(double p) const {
		if (p >= left && p <= right)
		{
			return true;
		}
		else {
			return false;
		}
	}

	double length() const {

		return this->right - this->left;
	}

	bool do_ranges_intersect(const Range& f) const {
		if ((left <= f.right) && (f.left <= right))
		{
			return true;
		}
		else {
			return false;
		}
	}


	bool are_ranges_equal( const Range& f) const {
		if ((left == f.left) && (right == f.right))
		{
			return true;
		}
		else {
			return false;
		}
	}

	 double get_left() const {
		return this->left;
	}

	 double get_right() const {
		return this->right;
	}

	void set_range(double l, double r) {
		if (is_valid(l, r))
		{
			left = l;
			right = r;
		}

	}

	void input_range() {

		double l = 0;
		double r = 0;

		do
		{
			std::cout << "Enter the left bound: " << std::endl;

			std::cin >> l;

			std::cout << "Enter the right bound: " << std::endl;

			std::cin >> r;

			if (is_valid(l, r))
			{
				left = l;
				right = r;
			}
		} while (!is_valid(l, r));
	}

	void print_range() const {
		std::cout << "[ " << left << " ; " << right << " ]" << std::endl;
	}

};
 


int main()
{
 

	Range r(3, 228);

	r.print_range();

	Range s (3.5, 5);

	Range t = Range();
	
	t.print_range();

	Range u = r;

	u.print_range();

	Range v;

	v.input_range();

	v.print_range();

	Range w = 5;

	w.print_range();

	bool b = r.do_ranges_intersect(s);

	bool c = r.are_ranges_equal(s);

	bool d = r.belongs_to_range(3.5);

	bool e = r.belongs_to_range(6);

	std::cout << b << " " << c << " " << d << " " << e << " " << v.length() << " " << r.are_ranges_equal(r);

}
