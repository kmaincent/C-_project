#include "include.h"

int main(int argc, char *argv[])
{

    mediatheque media;
    media.load("Backup.txt"); // #FAINEANT
    string str, fonction, param;
    int pos=0;

    cout<<"Bonjour!"<<endl<<"Vous utilisez l'application eirbmedia qui reference toutes les donnees disponibles dans la bibliotheque."<<endl;
    cout<<"Identifiant ?"<<endl;
    str="";
    getline(cin, str);
    utilisateur user(str);
    cout<<"Etes vous administrateur ? y/n"<<endl;
    str="";
    getline(cin, str);
    if (str=="y")
    {
        cout<<"Quel est le mot de passe?"<<endl;
        for(int i = 3; i>=0 ; i--)
        {
            str="";
            getline(cin, str);
            if(user.is_admin(str))
                break;
            cout<<"Mauvais mot de passe."<<endl
                   <<"Il vous reste "<<i<<" essai"<<endl;

        }
    }
    user.is_admin("ADMIN");
    do{
        if(user.getAdmin())
            cout<<endl<<endl<<"Bienvenu "<<user.getNom()<<" vous etes connecte en tant qu'administrateur"<<endl;
        else
            cout<<endl<<endl<<"Bienvenu "<<user.getNom()<<" vous etes connecte en tant qu'utilisateur"<<endl;

        cout<<"Veuillez entrer votre commande : "<<endl;
        do{
            str="";
            getline(cin, str);
        }
        while (str.size()==0);

        pos=str.find(' ');

        if(pos==(signed)std::string::npos)
        {
            fonction=str;
            param="";
        }
        else
        {
            fonction=str.substr(0,pos);
            param=str.substr(pos+1, str.size());
        }
    }
    while(id_function(media, user, fonction, param));




    return 1;
}
