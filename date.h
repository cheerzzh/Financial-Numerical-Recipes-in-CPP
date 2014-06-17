class date{
protected:
	int year_;
	int month_;
	int day_;

public:
	date(); // constructor
	date(const int& d, const int& m, const int& y);

	bool valid() const;

	int day() const;
	int month() const;
	int year() const;

	// 
	void set_day(const int& day);
	void set_month(const int& month);
	void set_year(const int& year);

	//increment and decrement function
	date operator ++(); //prefix
	date operator ++(int);//postfix
	date operator --();// prefix
	date operator --(int);// postfix
};

// comprasion functions
// overloading
bool operator == (const date&, const date&);
bool operator!= (const date&, const date&);
bool operator < (const date&, const date&);
bool operator >  (const date&, const date&);
bool operator<= (const date&, const date&);
bool operator>= (const date&, const date&);


