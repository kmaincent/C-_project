#ifndef DVD_H
#define DVD_H


class dvd : public vhs
{	
private:
    int nb_chap;

public:
    dvd();
    dvd(type_ressource _type, int _id, std::string _titre, std::string _auteur, int _duree, std::string _maison_prod, int _nb_chap, etat _etat);
    virtual void show() const;
    virtual void save(std::ofstream &infile) const;
    virtual bool search(std::string str) const;
    virtual void load(std::istream &file);

    int getNb_chap() const;
    void setNb_chap(int value);
};

#endif // DVD_H
