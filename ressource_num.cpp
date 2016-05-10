#include "include.h"


int ressource_num::getTaille() const
{
    return taille;
}

void ressource_num::setTaille(int value)
{
    taille = value;
}

std::string ressource_num::getFormat() const
{
    return format;
}

void ressource_num::setFormat(const std::string &value)
{
    format = value;
}

std::string ressource_num::getURL() const
{
    return URL;
}

void ressource_num::setURL(const std::string &value)
{
    URL = value;
}
ressource_num::ressource_num()
{

}

ressource_num::ressource_num(type_ressource _type, int _id, std::string _titre, std::string _auteur, int _taille, std::string _format, std::string _URL) :
    ressource(_type, _id, _titre, _auteur), //ressource
    taille(_taille), format(_format), URL(_URL) //ressource numerique
{
}

void ressource_num::show() const
{
    ressource::show();
    cout<<"Format: "<<format<<endl
       <<"Taille: "<<taille<< "Ko" <<endl
      <<"URL: "<<URL<<endl;
}

void ressource_num::save(std::ofstream &infile) const
{
    ressource::save(infile);
    infile<<format<<endl<<taille<<endl<<URL<<endl;
}

void ressource_num::load(std::istream &file)
{
    string tampon;
    ressource::load(file);
    cout << "Quel est le format de cette ressource?" << endl;
    do{
    getline( file, tampon);
    }while(tampon.size()==0);
    setFormat(tampon);
    cout << "Quelle est la taille de cette ressource? (En octets)" << endl;
    do{
    getline( file, tampon);
    }while(tampon.size()==0);
    setTaille(atoi(tampon.c_str()));
    cout << "Quem est l'URL de cette ressource?" << endl;
    do{
    getline( file, tampon);
    }while(tampon.size()==0);
    setURL(tampon);
}

bool ressource_num::search(std::string str) const
{
    if (ressource::search(str))
        return true;
    if (URL.find(str)!=string::npos)
        return true;
    return false;

}
