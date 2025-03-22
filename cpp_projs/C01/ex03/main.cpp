#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"
int main()
{   
    {
        Weapon frying = Weapon("Frying Pan");
        HumanA calvin("Calvin",frying);
        calvin.attack();
        frying.setType("Baton");
        calvin.attack();
    }

    {   
        Weapon banana = Weapon("Banana");
        HumanB mike("Mike");
        mike.attack();
        mike.setType(banana);
        mike.attack();
    }
}