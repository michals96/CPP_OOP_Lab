#include"Main.h"
void ObiektMiotajacy::Rzuc()
{
    delete this;
    //typ1 *tmp=new typ1;
    throw new typ1;
}
void Przetworz(ObiektMiotajacy *obj)
{
    std::cout << "Przetworz - wyjatek typu "<< obj->getVal()<<" o adresie "<< obj<<std::endl;
    delete obj;
    //typ4 *tmp=new typ4;
    throw new typ4;
}