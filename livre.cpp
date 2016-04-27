#include "include.h"


std::string livre::getResume() const
{
    return resume;
}

void livre::setResume(const std::string &value)
{
    resume = value;
}

std::string livre::getCollection() const
{
    return collection;
}

void livre::setCollection(const std::string &value)
{
    collection = value;
}

int livre::getAnnee_publication() const
{
    return annee_publication;
}

void livre::setAnnee_publication(int value)
{
    annee_publication = value;
}

int livre::getNb_pages() const
{
    return nb_pages;
}

void livre::setNb_pages(int value)
{
    nb_pages = value;
}
livre::livre()
{

}

livre::livre(type_ressource _type, int _id, std::string _titre, std::string _auteur, int _annee_publi, int _nb_page, std::string _collection, std::string _resume) :
    ressource(_type, _id, _titre, _auteur), //ressource
    annee_publication(_annee_publi), nb_pages(_nb_page), collection(_collection), resume(_resume) //livre
{
}

void livre::affiche() const
{
    ressource::affiche();
    cout<<" publié en : "<<annee_publication<<endl
       <<"Composé de "<<nb_pages<<" pages"<<endl
      <<"Appartient à la collection "<<collection<<endl
     <<"Son résumé est : "<<resume<<endl;
}

void livre::save(std::ofstream &infile) const
{
    ressource::save(infile);
    infile<< annee_publication << endl
          <<nb_pages<<endl
         <<collection<<endl
        <<resume;

}

void livre::load(std::ifstream &file)
{	
    string tampon;
    ressource::load(file);
    getline( file, tampon);
    setAnnee_publication(atoi(tampon.c_str()));
    getline( file, tampon);
    setNb_pages(atoi(tampon.c_str()));
    getline( file, tampon);
    setCollection(tampon);
    getline( file, tampon);
    setResume(tampon);

}

bool livre::search(std::string str)
{
    if (ressource::search(str))
        return true;
    if (collection.find(str)!=string::npos)
        return true;
    if (resume.find(str)!=string::npos)
        return true;

    return false;

}	
