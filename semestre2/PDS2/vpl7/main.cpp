#include <iostream>
#include <list>
#include <sstream>

class MyClass
{
private:
    static int IdIncrementer;
    static int objectCounter;
    int ID;

public:
    MyClass()
    {
        this->ID = IdIncrementer++;
        objectCounter++;
    }

    MyClass(int ID)
    {
        this->ID = ID;
        objectCounter++;
    }

    ~MyClass()
    {
        objectCounter--;
    }

    int getID()
    {
        return this->ID;
    }

    static int getObjectCounter()
    {
        return objectCounter;
    }

    const void *getMemoryAddress() const
    {
        return static_cast<const void *>(this);
    }

    std::string toString() {
        std::ostringstream oss;
        oss << this->getID() << " " << this->getMemoryAddress() << std::endl;
        return oss.str();
    }
};

int MyClass::IdIncrementer = 1;
int MyClass::objectCounter = 0;

int main()
{
    std::list<MyClass *> objects;

    while (true)
    {
        char input;
        std::cin >> input;

        if (input == 'A')
        {
            MyClass *newObject = new MyClass();
            objects.push_back(newObject);
            std::cout << newObject->toString();
        }

        if (input == 'C')
        {
            int ID;
            std::cin >> ID;

            if (ID >= 0)
            {
                std::cout << "ERRO" << std::endl;
                continue;
            }

            MyClass *newObject = new MyClass(ID);
            objects.push_front(newObject);
            std::cout << newObject->toString();
        }

        if (input == 'R')
        {
            if (objects.empty())
            {
                std::cout << "ERRO" << std::endl;
                continue;
            }
            MyClass *removedObject = objects.front();
            objects.pop_front();
            std::cout << removedObject->toString();
            delete removedObject;
        }

        if (input == 'N')
            std::cout << MyClass::getObjectCounter() << std::endl;

        if (input == 'P')
        {
            int position;
            std::cin >> position;

            if (position < 1 || position > static_cast<int>(objects.size()))
            {
                std::cout << "ERRO" << std::endl;
                continue;
            }
            auto it = objects.begin();
            std::advance(it, position - 1);
            MyClass *obj = *it;
            std::cout << obj->toString();
        }
        
        if (input == 'L')
        {
            for (MyClass *obj : objects)
                std::cout << obj->toString();
        }

        if (input == 'E')
            break;
    }

    for (MyClass *obj : objects)
        delete obj;

    return 0;
}