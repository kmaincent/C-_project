#include "include.h"


std::string vhs::getMaison_prod() const
{
    return maison_prod;
}

void vhs::setMaison_prod(const std::string &value)
{
    maison_prod = value;
}

int vhs::getDuree() const
{
    return duree;
}

void vhs::setDuree(int value)
{
    duree = value;
}
vhs::vhs()
{

}

vhs::vhs(type_ressource _type, int _id, std::string _titre, std::string _auteur, int _duree, std::string _maison_prod):
    ressource(_type, _id, _titre, _auteur), //ressource
    duree(_duree), maison_prod(_maison_prod) //vhs
{
}

void vhs::show() const
{
    ressource::show();
    cout<<"Duree: "<<duree<<"min"<< endl
       << "Maison de production: "<<maison_prod<<endl;
}

void vhs::save(std::ofstream &infile) const
{
    ressource::save(infile);
    infile<<duree<<endl<<maison_prod<<endl;
}

void vhs::load(std::istream &file)
{
    string tampon;
    ressource::load(file);
    cout << "Quelle est la duree de ce media?" << endl;
    do{
    getline( file, tampon);
    }while(tampon.size()==0);
    setDuree(atoi(tampon.c_str()));
    cout << "Quelle est la maison de production de ce media?" << endl;
    do{
    getline( file, tampon);
    }while(tampon.size()==0);
    setMaison_prod(tampon);
}

bool vhs::search(std::string str) const
{
    if (ressource::search(str))
        return true;
    if (duree==atoi(str.c_str()))
        return true;
    if (maison_prod.find(str)!=string::npos)
        return true;

    return false;

}
