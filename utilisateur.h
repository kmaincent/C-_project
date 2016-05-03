#ifndef UTILISATEUR_H
#define UTILISATEUR_H

class utilisateur
{

	private :
	string nom;
	bool admin;
	
	public :
    utilisateur();
	utilisateur(string _nom);
    bool is_admin(string pass);
	string nom_user() const;
    string getNom() const;
    void setNom(const string &value);
    bool getAdmin() const;
};

#endif 	
