#include <iostream>
#include <string>

class Animal {
protected:
    std::string name;
    int age;

public:
    Animal(const std::string& name, int age) : name(name), age(age) {
        std::cout << "Animal constructor called for " << name << std::endl;
    }

    virtual ~Animal() {
        std::cout << "Animal destructor called for " << name << std::endl;
    }

    virtual std::string sound() const = 0;

    virtual void info() const {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
};

class Dog : public Animal {
private:
    std::string breed;

public:
    Dog(const std::string& name, int age, const std::string& breed) : Animal(name, age), breed(breed) {
        std::cout << "Dog constructor called for " << name << std::endl;
    }

    ~Dog() override {
        std::cout << "Dog destructor called for " << name << std::endl;
    }

    void info() const override {
        Animal::info();
        std::cout << "Breed: " << breed << std::endl;
    }

    std::string sound() const override {
        return "Woof";
    }
};

int main() {
    Animal* animal = new Dog("Buddy", 3, "Golden Retriever");
    animal->info();
    std::cout << "Sound: " << animal->sound() << std::endl;
    delete animal;
    return 0;
}
