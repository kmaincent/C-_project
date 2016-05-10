#ifndef MEDIATHEQUE_H
#define MEDIATHEQUE_H
#include "include.h"
#include "ressource.h"

class mediatheque
{
private:
    int nb_ressource, nb_livre, nb_revue, nb_cd, nb_vhs, nb_dvd, nb_docnum;
    string nom_media;
    std::vector <ressource*> base_donnees;
    std::vector <bool> base_recherche;

public:
    mediatheque();
    ~mediatheque();
    void add (std::string param);
    void save (std::string param) const;
    int load (std::string param);
    void search (std::string param);
    void list ();
    void clear ();
    void show (std::string param) const;
    void delet (std::string param);
    void reset ();
    string miseenforme(string modif, int taille);

    string getNom_media() const;
    void setNom_media(const string &value);
    void load_state(utilisateur user);
    void save_state(utilisateur user) const;
};

#endif // MEDIATHEQUE_H
