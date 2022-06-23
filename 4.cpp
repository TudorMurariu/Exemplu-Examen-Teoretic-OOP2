#include <iostream>
#include <string>
#include <vector>
using namespace std;

template<typename TElem>
class ToDo{
    vector<TElem> l;
    
public:

    ToDo& operator<<(TElem el)
    {
        l.push_back(el);
        return *this;
    }
    
    void printToDoList(ostream& g)
    {
        g << "De facut : ";
        for(auto& x : l)
            g << x.getDescriere() << ";";
    }
};

class Examen{
    string nume;
    string ora;
public:
    Examen(string nume1,string ora1)
    {
        nume = nume1;
        ora = ora1;
    }
    
    string getDescriere()
    {
        return nume + " ora " + ora;
    }
};

void todolist() 
{
    ToDo<Examen> todo;
    Examen oop{ "oop scris","8:00" };
    todo << oop << Examen{"oop practic", "11:00"}; //Adauga 2 examene la todo
    std::cout << oop.getDescriere() << endl; //tipareste la consola: oop scris ora 8:00
    //itereaza elementele adaugate si tipareste la consola lista de activitati
    //in acest caz tipareste: De facut:oop scris ora 8:00;oop practic ora 11:00
    todo.printToDoList(std::cout);
}

int main()
{
    todolist();
    return 0;
}
