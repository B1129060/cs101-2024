#include <iostream>
#include <string>
using namespace std;

class Fueltank{
    private:
    int m_FueltankCapacity;
    int m_Gas_grade;
    public:
    Fueltank(int FueltankCapacity = 3000, int Gas = 98){
	this->m_FueltankCapacity = FueltankCapacity;
	this->m_Gas_grade = Gas;
    }
    int fuel_up(int v, int gas){
	if(v > this->m_FueltankCapacity){
	    cout << "Error: FueltankCapacity: " << this->m_FueltankCapacity << " but fuel up: " << v << endl;
	}
	if(gas != this->m_Gas_grade){
	    cout << "Error: Gas_grade: " << gas << " Correct Gas_grade: " << this->m_Gas_grade << endl;
	return 0;
	}
	cout << "fuel_up: " << v << " Gas_grade: " << gas << endl;
	return v;
    }
    int set_Gas_grade(int Gas_grade){
	this->m_Gas_grade = Gas_grade;
	return this->m_Gas_grade;
    }		
    int get_Gas_grade(){ return this-> m_Gas_grade;}
};

class Engine{
    private:
    int m_EngineCapacity;
    int m_Horsepower;
    bool m_EngineRunning;
    public:
    Engine(int EngineCapacity = 2000, int Horsepower = 200){
        this->m_EngineCapacity = EngineCapacity;
	this->m_Horsepower = Horsepower;
	this->m_EngineRunning = false;
    }
    bool EngineStart(){
	this->m_EngineRunning = true;
	return true;
    }
    bool EngineStop(){
	this->m_EngineRunning = false;
	return true;
    }
    bool get_EngineStatus(){
	return this->m_EngineRunning;
    }
};
class Car {
    protected:
    string m_DriveMode;
    
    private:
    Engine m_Engine;
    Fueltank m_Fueltank;
    int m_MaxSeating;
    int m_price;
    int m_base;
    string m_brand;
    string m_model;
    int m_year;
    void m_UpdatePrice(int base = 500000){
        m_price = m_MaxSeating * base;
    }
    public:  
    Car(string x, string y, int z, int s){
        m_brand = x;
        m_model = y;
        m_year = z;
        m_MaxSeating = s;
        m_UpdatePrice();
        m_DriveMode = "No-wheel";
        m_base = 0;
    }
    int get_MaxSeating() { return this->m_MaxSeating;}
    int get_Price() { return this->m_price;}
    void set_base(int n){ this->m_base = n; }
    string get_brand() { return this->m_brand;} 
    bool get_EngineStatus(){ return this->m_Engine.get_EngineStatus(); }
    bool startEngine(){ return this->m_Engine.EngineStart(); }
    bool stopEngine(){ return this->m_Engine.EngineStop(); }
    int get_Gas_Grade(){ return this->m_Fueltank.get_Gas_grade(); }
    int set_Gas_grade(int gas){ 
	cout <<  "Set Gas_grade: " <<  this->m_Fueltank.set_Gas_grade(gas) << endl;
	return 1;
    }
    int fuel_up(int v, int gas){
	this->m_Fueltank.fuel_up(v, gas);
	return 1;	
    }
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
    AUDI_Car(string y, int z, int s): Car("AUDI", y, z, s){
        cout << "Constructing AUDI_Car\n";
        m_DriveMode = "Front-wheel";
    }
    string get_DriveMode() { return this->m_DriveMode;}
};

class BENZ_Car: public Car {
    public:
    BENZ_Car(string y, int z, int s): Car("BENZ", y, z, s){
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
    cout << "\n";
    
    BMW_Car car_1("X5", 2020, 6);
    cout << car_1.get_brand();
    cout << " : EngineStatus = " << car_1.get_EngineStatus() << endl;
    
    AUDI_Car car_2("A1", 2021, 2);
    car_2.startEngine();
    cout << car_2.get_brand();
    cout << " : EngineStatus = " << car_2.get_EngineStatus() << endl;
    car_2.stopEngine();
    cout << " : EngineStatus = " << car_2.get_EngineStatus() << endl;
    cout << "\n";
    
    AUDI_Car car_3("A1", 2021, 2);
    cout << car_3.get_brand() << " : Gas_grade = " << car_3.get_Gas_Grade() << endl;
    car_3.set_Gas_grade(95);
    cout << car_3.get_brand() << " : Gas_grade = " << car_3.get_Gas_Grade() << endl;
    car_3.fuel_up(300, 95);
    
    AUDI_Car car_4("A1", 2021, 2);
    cout << car_4.get_brand() << " : Gas_grade = " << car_4.get_Gas_Grade() << endl;
    car_4.set_Gas_grade(95);
    cout << car_4.get_brand() << " : Gas_grade = " << car_4.get_Gas_Grade() << endl;
    car_4.fuel_up(300, 99);
    
    AUDI_Car car_5("A1", 2021, 2);
    cout << car_5.get_brand() << " : Gas_grade = " << car_5.get_Gas_Grade() << endl;
    car_5.set_Gas_grade(95);
    cout << car_5.get_brand() << " : Gas_grade = " << car_5.get_Gas_Grade() << endl;
    car_5.fuel_up(3000000, 95);
    
    AUDI_Car car_6("A1", 2021, 2);
    cout << car_6.get_brand() << " : Gas_grade = " << car_6.get_Gas_Grade() << endl;
    car_6.set_Gas_grade(95);
    cout << car_6.get_brand() << " : Gas_grade = " << car_6.get_Gas_Grade() << endl;
    car_6.fuel_up(100000, 98);
    
	
    return 0;
}
