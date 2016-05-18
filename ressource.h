#ifndef RESSOURCE_H
#define RESSOURCE_H

#include "enum_string_type.h"


class ressource
{
protected:
    int id;
    string titre, auteur;
    type_ressource type;
    etat etat_actuel;

public:
    ressource();
    virtual ~ressource();
    ressource(type_ressource _type, int _id, std::string _titre, std::string _auteur, etat etate);
    virtual void show() const;
    virtual void save(std::ofstream &infile) const;
    virtual bool search(std::string str) const;
    virtual void load(std::istream &file);

    string getTitre() const;
    void setTitre(const string &value);
    string getAuteur() const;
    void setAuteur(const string &value);
    type_ressource getType() const;
    void setType(const type_ressource &value);
    int getId() const;
    void setId(int value);


    etat getEtat_actuel() const;
    void setEtat_actuel(const etat &value);
};



#endif
