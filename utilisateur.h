#ifndef UTILISATEUR_H
#define UTILISATEUR_H

class utilisateur
{

	private :
	string nom;
	bool admin;
	
	public :
	utilisateur(string _nom);
	void is_admin(string pass);	
	string nom_user() const;
};

#endif 	
