//zadanie 1
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Employee {
protected:
    string name; 
    double salary; 
    double bonus;

public:
    
    Employee(const std::string& _name, double _salary, double _bonus) : name(_name), salary(_salary), bonus(_bonus) {}

    
    virtual void printInfo() const {
        cout << "сотрудник: " << name << "\n зарплата: " << salary << "\n надбавка: " << bonus << "\n общая сумма: " << (salary + bonus) << endl;
    }

    
    virtual ~Employee() {}
};

class Manager : public Employee {
public:
    
    Manager(const std::string& _name, double _salary, double _bonus) : Employee(_name, _salary, _bonus) {}

    
    void printInfo() const override {
        cout << "менеджер: " << name << "\n зарплата: " << salary << "\n надбавка: " << bonus << "\n общая сумма: " << (salary + bonus) << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    Employee* emp1 = new Employee("Мамкин А.", 50000, 4000);
    emp1->printInfo();

    Employee* mgr1 = new Manager("Плотников А.", 70000, 5000);
    mgr1->printInfo();

    delete emp1; 
    delete mgr1; 

    return 0;
}

//zadanie 2
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Person {
protected:
    string name; 
    int age;          

public:
    Person(const string& name, int age) : name(name), age(age) {}

    virtual void printInfo() const {
        cout << "Имя: " << name << "\nВозраст: " << age << endl;
    }

    virtual ~Person() {}
};

class Student : virtual public Person {
protected:
    string university;

public:
    Student(const string& name, int age, const string& university)
        : Person(name, age), university(university) {}

    void printInfo() const override {
        Person::printInfo();
        cout << "Университет: " << university << endl;
    }
};

class Worker : virtual public Person {
protected:
    string company; 

public:
    Worker(const string& name, int age, const string& company)
        : Person(name, age), company(company) {}

    void printInfo() const override {
        Person::printInfo();
        cout << "Компания: " << company << endl;
    }
};

class Intern : public Student, public Worker {
public:
    Intern(const string& name, int age, const string& university, const string& company)
        : Person(name, age), Student(name, age, university), Worker(name, age, company) {}

    void printInfo() const override {
        Student::printInfo();
        Worker::printInfo();
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    Intern intern("Алексей Смирнов", 21, "МГУ", "ТехноЛаб");
    intern.printInfo();

    return 0;
}
