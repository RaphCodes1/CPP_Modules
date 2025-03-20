#include <iostream>
#include <string>

class Zombie
{   
    private:
        std::string _name;
    public:
        Zombie();
        Zombie(std::string name);
        Zombie(int age);
        ~Zombie();
        void set_name(std::string name);
        void announce();
}

int main(){
    Zombie  a()
}