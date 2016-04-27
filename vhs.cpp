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

void vhs::affiche() const
{
    ressource::affiche();
    cout<<" de durée "<<duree<<" dont la maison de production est : "<<maison_prod<<endl;
}

int vhs::save(std::ofstream &infile) const
{
    ressource::save(infile);
    infile<<duree<<endl<<maison_prod<<endl;
}

void vhs::load(std::ifstream &file)
{
    string tampon;
    ressource::load(file);
    getline( file, tampon);
    setDuree(atoi(tampon.c_str()));
    getline( file, tampon);
    setMaison_prod(tampon);
}

bool vhs::search(std::string str)
{
    if (ressource::search(str))
        return true;
    if (maison_prod.find(str)!=string::npos)
        return true;

    return false;

}
