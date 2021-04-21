#include <iostream>
#include <cstring>
#pragma warning(disable : 4996)

using namespace std;

enum Zoom{ digital_zoom = 0, optical_zoom = 1 };

class Camera {
protected:
	char Model[30];
	double Base_Price;
	int Megapixel;

public:
	Camera(){}
	Camera(const char* model, double bPrice, int mPixel) : Base_Price(bPrice), Megapixel(mPixel) { strcpy(Model, model); }
	Camera(const Camera& obj) {
		strcpy(Model, obj.Model);
		Model[29] = '\0';
		Base_Price = obj.Base_Price;
		Megapixel = obj.Megapixel;
	}
	~Camera(){}

	double get_Base_Price() { return Base_Price; }
	int get_Megapixel() { return Megapixel; }

	friend ostream& operator << (ostream& out, const Camera& obj) {
		return out << obj.Model << ", " << obj.Base_Price << ", " << obj.Megapixel << endl;
	}

	virtual double price() = 0;

	friend bool operator < (Camera& obj1, Camera& obj2) {
		obj1.price() < obj2.price();
	}
};

class DSLR : public Camera {
protected:
	char Lens_Type[20];
	double Lens_Price;

public:
	DSLR(){}
	DSLR(const char* model, double bPrice, int mPixel, const char* lType, double lPrice) 
		: Camera(model, bPrice, mPixel), Lens_Price(lPrice) { strcpy(Lens_Type, lType); }
	DSLR(const DSLR& obj) : Camera(obj) {
		strcpy(Lens_Type, obj.Lens_Type);
		Lens_Type[19] = '\0';
		Lens_Price = obj.Lens_Price;
	}
	~DSLR(){}

	double price() {
		if ((double)Megapixel >= 15.0) {
			Base_Price += 15.0 / 100.0;
			return Base_Price + Lens_Price;
		}
		else {
			return Base_Price;
		}
	}

	friend ostream& operator << (ostream& out, const DSLR& obj) {
		out << (Camera&)obj;
		out << "Lens type: " << obj.Lens_Type;
		out << "Lens price: " << obj.Lens_Price;
		return out;
	}

};

class Compact : public Camera {
protected:
	bool Zoom_Type;

public:
	Compact(){}
	Compact(const char* model, double bPrice, int mPixel, bool zType) : Camera(model, bPrice, mPixel), Zoom_Type(zType){}
	Compact(const Compact& obj) : Camera(obj) { Zoom_Type = obj.Zoom_Type; }
	~Compact(){}

	double price() {
		if ((double)Megapixel >= 10.0) {
			Base_Price += 12.0 / 100.0;
			if (Zoom_Type == optical_zoom) {
				Base_Price += 10.0 / 100.0;
				return Base_Price;
			}
		}
		else {
			return Base_Price;
		}
	}

	friend ostream& operator << (ostream& out, const Compact& obj) {
		out << (Camera&)obj;
		if (obj.Zoom_Type) {
			out << "Optical" << endl;
		}
		else {
			out << "Digital" << endl;
		}
	}
};

void smallest_Price(Camera** cameraPtr, int amount) {
	Camera* temp = nullptr;
	for (int i = 0; i < amount; i++) {
		if (cameraPtr[i] < cameraPtr[i + 1]) {
			temp = cameraPtr[i];
		}
	}
	cout << temp->price() << " is the smallest price." << endl;
}

int main() {

	DSLR d1("Kodak", 30000, 5, "Small Lens", 6000);
	DSLR d2("Nicon", 35000, 15, "Medium Lens", 6500);

	Compact k1("Cannon", 12000, 12, optical_zoom);
	Compact k2("Sony", 10000, 7, digital_zoom);

	Camera** Cameras;

	Cameras = new Camera * [4];
	Cameras[0] = &d1;
	Cameras[1] = &d2;
	Cameras[2] = &k1;
	Cameras[3] = &k2;

	smallest_Price(Cameras, 4);

	return 0;
}
