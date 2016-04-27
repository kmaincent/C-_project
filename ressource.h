#ifndef RESSOURCE_H
#define RESSOURCE_H

#include "enum_string_type.h"

class ressource
{
protected:
    string titre, auteur;
    int id;
    type_ressource type;

public:
    ressource();
    ressource(type_ressource _type, int _id, std::string _titre, std::string _auteur);
    void affiche() const;
    void save(std::ofstream &infile) const;
    bool search(std::string str) const;

    string getTitre() const;
    void setTitre(const string &value);
    string getAuteur() const;
    void setAuteur(const string &value);
    type_ressource getType() const;
    void setType(const type_ressource &value);
    void load(std::ifstream &file);
};



#endif
