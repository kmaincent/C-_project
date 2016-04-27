#ifndef CD_H
#define CD_H


class cd : public vhs
{
private:
    int nb_pistes;

public:
    cd();
    cd(type_ressource _type, int _id, std::string _titre, std::string _auteur, int _duree, std::string _maison_prod, int _nb_pistes);
    void affiche() const;
    int save(std::ofstream &infile) const;
    void load(std::ifstream &file);
    bool search(std::string str);

    int getNb_pistes() const;
    void setNb_pistes(int value);
};

#endif // CD_H
