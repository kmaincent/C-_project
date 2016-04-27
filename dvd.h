#ifndef DVD_H
#define DVD_H


class dvd : public vhs
{	
private:
    int nb_chap;

public:
    dvd();
    dvd(type_ressource _type, int _id, std::string _titre, std::string _auteur, int _duree, std::string _maison_prod, int _nb_chap);
    void affiche() const;
    int save(std::ofstream &infile) const;
    void load(std::ifstream &file);
    bool search(std::string str);
    int getNb_chap() const;
    void setNb_chap(int value);
};

#endif // DVD_H
