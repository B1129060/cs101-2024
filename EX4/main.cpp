#include <iostream>
#include <string>
using namespace std;

class Car {
    protected:
    string m_DriveMode;
    
    private:
    int m_MaxSeating;
    int m_price;
    void m_UpdatePrice(int base = 500000){
        m_price = m_MaxSeating * base;
    }
    public:
    string m_brand;
    string m_model;
    int m_year;
    
    Car(string x, string y, int z, int s){
        m_brand = x;
        m_model = y;
        m_year = z;
        m_MaxSeating = s;
        m_UpdatePrice();
        m_DriveMode = "No-wheel";
    }
    
    int get_MaxSeating() { return this->m_MaxSeating;}
    int get_Price() { return this->m_price;}
    string get_DriveMode() { return this->m_DriveMode;}
};

class BMW_Car: public Car {
    public:
    BMW_Car(string y, int z, int s): Car("BMW", y, z, s){
        cout << "Constructing BMW_Car\n";
        m_DriveMode = "Rear-wheel";
    }
    string get_DriveMode() { return this->m_DriveMode;}
};

class AUDI_Car: public Car {
    public:
    AUDI_Car(string y, int z, int s): Car("BMW", y, z, s){
        cout << "Constructing AUDI_Car\n";
        m_DriveMode = "Front-wheel";
    }
    string get_DriveMode() { return this->m_DriveMode;}
};

class BENZ_Car: public Car {
    public:
    BENZ_Car(string y, int z, int s): Car("BMW", y, z, s){
        cout << "Constructing BENZ_Car\n";
        m_DriveMode = "Front-wheel";
    }
    string get_DriveMode() { return this->m_DriveMode;}
};

int main()
{
    BMW_Car car1("model1", 2020, 5);
    cout << "BMW : Drive Mode = " << car1.get_DriveMode() << endl;
    AUDI_Car car2("model2", 2021, 8);
    cout << "AUDI : Drive Mode = " << car2.get_DriveMode() << endl;
    BENZ_Car car3("model3", 2022, 2);
    cout << "Benz : Drive Mode = " << car3.get_DriveMode() << endl;

    return 0;
}
