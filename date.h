class date{
protected:
	int year_;
	int month_;
	int day_;

public:
	date()
	date(const int& d, const int& m, const int& y);

	bool valid() const;

	int day() const;
	int month() const;
	int year() const;

	void set_day(const int& day);
	void set_month(const int& month);
	void set_year(const int& year);

	date operator ++();
	date operator ++(int);
	date operator --();
	date operator --(int);
};

bool operator == (const date&, const date&);
bool 