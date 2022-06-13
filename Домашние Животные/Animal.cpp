#include <iostream>

// базовый абстрактный класс. это то, что мы используем в качестве интерфейса
class Animal
{
public:
    Animal(char const* name) : m_name(name) {}

    // это необходимо для правильного удаления виртуальных классов
    virtual ~Animal() {}

    // с помощью этого синтаксиса мы определяем нериализованную функцию "интерфейс"
    virtual void make_sound() = 0;

protected:
    // общее поле данных
    std::string m_name;
};

// производный класс. это означает, что Собака - это более утонченная версия Животного
// обычно наследуется только от одного базового класса
class Dog : public Animal
{
public:
    // необходимо переслать аргументы конструктора
    Dog(char const* name) : Animal(name) {}

    // здесь мы реализуем интерфейс
    void make_sound() override
    {
        std::cout << m_name << " the DOG said: Woof!" << std::endl;
    }
};

// то же, что и выше, но с другой реализацией
class Cat : public Animal
{
public:
    Cat(char const* name) : Animal(name) {}

    void make_sound() override
    {
        std::cout << m_name << " the CAT said: Meow!" << std::endl;
    }
};

// Теперь мы можем использовать Animal в качестве общего типа
// Существует информация о типе среды выполнения, которая позволяет это (dynamic dispatch)
void animal_sound(Animal& a)
{
    // метод, вызываемый через универсальный интерфейс
    a.make_sound();

    // информация о типе все еще существует, мы можем извлечь исходный тип с помощью
// проверки, работает ли динамическое приведение
    auto d = dynamic_cast<Dog*>(&a);
    if (d != nullptr);

    auto c = dynamic_cast<Cat*>(&a);
    if (c != nullptr);
}

int main()
{
    auto cat = Cat("Pushok");
    auto dog = Dog("Jack");
    animal_sound(cat);
    animal_sound(dog);

    return 0;
}