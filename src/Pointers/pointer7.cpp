#include <iostream>
#include <memory>

class Entity
{
public:
    Entity() // constructor
    {
        std::cout << "Entidad creada" << std::endl;
    }
    ~Entity() // destructor
    {
        std::cout << "Entidad destruida" << std::endl;
    }
    void print() {}
};

int main()
{

    {
        std::unique_ptr<Entity> entity = std::make_unique<Entity>(); // Se crea un puntero único a la clase entidad
        // Crea y elimina la memoria utilizada, pero en este caso el puntero único no permite asignar a otros
        // para eso se utilizan los puntero compartidos
    }
    {
        std::weak_ptr<Entity> e0;
        {
            std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();
            e0 = sharedEntity;
        }
    }

    return 0;
}