//prak 1

#include <iostream>
#include <string>

class dvigotel {
private:
    std::string model;
public:
    dvigotel(const std::string _model) : model(_model) {
        std::cout << "создан двигатель модели " << model << std::endl;
    }

    ~dvigotel() {
        std::cout << "уничтожен двиготель модели " << model << std::endl;
    }

    void run() const {
        std::cout << "запущен двигатель модели " << model << std::endl;
    }
};

class car {
private:
    std::string brand;
    dvigotel dvijok;
public:
    car(const std::string _brand, const std::string _dvijok ) : brand(_brand), dvijok(_dvijok) {
        std::cout << "запущен автомобиль марки " << brand << std::endl;
    }

    ~car() {
        std::cout << "уничтожен автомобиль марки " << brand << std::endl;
    }

    void start() const {
        std::cout << "запущен автомобиль марки " << brand << std::endl;
        dvijok.run();
    }
};


//prak 2

#include <iostream>
#include <vector>
#include <string>

class Student {
private:
    std::string name;

public:
    Student(const std::string& _name) : name(_name) {}

    std::string getName() const {
        return name;
    }
};

class University {
private:
    std::vector<Student*> students; 

public:
    void addStudent(Student* student) {
        students.push_back(student);
    }

    void listStudents() const {
        std::cout << "Список студентов в университете:" << std::endl;
        for (const auto& student : students) {
            std::cout << "- " << student->getName() << std::endl;
        }
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    Student student1("Иван Иванов");
    Student student2("Мария Петрова");
    Student student3("Алексей Сидоров");

    University university;

    university.addStudent(&student1);
    university.addStudent(&student2);
    university.addStudent(&student3);

    university.listStudents();

    return 0;
}


//prak 3

#include <iostream>
#include <vector>
#include <string>

class Manager;

class Programmer {
private:
    std::string name;
    Manager* manager;

public:
    Programmer(const std::string& _name) : name(_name), manager(nullptr) {}

    void setManager(Manager* _manager) {
        manager = _manager;
    }

    std::string getName() const {
        return name;
    }

    Manager* getManager() const {
        return manager;
    }
};

class Manager {
private:
    std::string name;
    std::vector<Programmer*> programmers; 

public:
    Manager(const std::string& _name) : name(_name) {}

    void addProgrammer(Programmer* programmer) {
        programmers.push_back(programmer);
        programmer->setManager(this); 
    }

    void listProgrammers() const {
        std::cout << "Список программистов под управлением менеджера " << name << ":" << std::endl;
        for (const auto& programmer : programmers) {
            std::cout << "- " << programmer->getName() << std::endl;
        }
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    Manager manager("Анна Сергеевна");

    Programmer programmer1("Иван Иванов");
    Programmer programmer2("Мария Петрова");
    Programmer programmer3("Алексей Сидоров");

    manager.addProgrammer(&programmer1);
    manager.addProgrammer(&programmer2);
    manager.addProgrammer(&programmer3);

    manager.listProgrammers();

    std::cout << "Менеджер программиста " << programmer1.getName() << ": "
        << programmer1.getManager() << std::endl;

    return 0;
}
