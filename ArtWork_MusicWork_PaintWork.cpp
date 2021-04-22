#include <iostream>
#include <cstring>

#pragma warning(disable : 4996)

using namespace std;

class ArtWork {
private:
	int year_of_making;
	char* author;
	float price_of_work;

public:
	ArtWork(){}
	ArtWork(int year, const char* _author, float price) {
		year_of_making = year;
		author = new char[strlen(_author)];
		strcpy(author, _author);
		price_of_work = price;
	}
	ArtWork(const ArtWork& obj) {
		year_of_making = obj.year_of_making;
		author = new char[strlen(obj.author)];
		strcpy(author, obj.author);
		price_of_work = obj.price_of_work;
	}

	ArtWork& operator = (const ArtWork& obj) {
		if (this != &obj) {
			year_of_making = obj.year_of_making;
			author = new char[strlen(obj.author)];
			strcpy(author, obj.author);
			price_of_work = obj.price_of_work;
		}
		return *this;
	}
	virtual ~ArtWork() { delete[] author; }	

	int get_Year() { return year_of_making; }
	float get_Price_Of_Work() { return price_of_work; }

	virtual double price() = 0;

	bool operator == (const ArtWork& obj1) {
		return price_of_work == obj1.price_of_work;
	}

	friend ostream& operator << (ostream& out, const ArtWork& obj) {
		out << "Year of making: " << obj.year_of_making << endl;
		out << "Author: " << obj.author << endl;
		out << "Price of work: " << obj.price_of_work << endl;
		return out;
	}
};

class MusicWork : public ArtWork {
private:
	char music_genre[30];

public:
	MusicWork() {}
	MusicWork(int year, const char* _author, float price, const char* genre) : ArtWork(year, _author, price) { strcpy(music_genre, genre); }
	~MusicWork() {}
	MusicWork(const MusicWork& obj) : ArtWork(obj) {
		strcpy(music_genre, obj.music_genre);
	}

	double price() {
		if ((double)get_Year() < 1700.0 && (double)get_Year() >= 1600.0) {
			return (double)(get_Price_Of_Work() * 1.1);
		}
		else {
			return (double)get_Price_Of_Work();
		}
	}

	friend ostream& operator << (ostream& out, const MusicWork& obj) {
		return out << "Genre: " << obj.music_genre << endl;
	}
};

class PaintWork : public ArtWork {
private:
	char paint_technique[30];
	int degree_of_damage;

public:
	PaintWork(){}
	PaintWork(int year, const char* _author, float price, const char* technique, int damage) : ArtWork(year, _author, price) {
		strcpy(paint_technique, technique);
		degree_of_damage = damage;
	}
	PaintWork(const PaintWork& obj) : ArtWork(obj) {
		strcpy(paint_technique, obj.paint_technique);
		degree_of_damage = obj.degree_of_damage;
	}
	~PaintWork(){}

	int get_Damage() { return degree_of_damage; }
	
	double price() {
		double temp;
		for (double i = 0.0; i < 100.0; i++) {
			if ((double)get_Damage() == i) {
				temp = (double)(get_Price_Of_Work() * i / 100);
			}
		}
		return (double)(get_Price_Of_Work() - temp);
	}

	friend ostream& operator << (ostream& out, const PaintWork& obj) {
		out << "Technique: " << obj.paint_technique << endl;
		out << "Damage: " << obj.degree_of_damage << endl;
		return out;
	}
};

int main() {

	cout << "Paint Work: ";
	PaintWork pw(1222.0, "Picaso", 1100.0, "Aquarel", 50);
	cout << pw.price() << endl;

	cout << "Music Work: ";
	MusicWork mw(1622.0, "Beethoven", 1000.0, "Classic");
	cout << mw.price() << endl;

	return 0;
}