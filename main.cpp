#include "include.h"

int main(int argc, char *argv[])
{

    mediatheque media;
    string str, fonction, param;
    int pos=0;

    cout<<"Bonjour!"<<endl<<"Vous utilisez l'application eirbmedia qui reference toutes les donnees disponibles dans la bibliotheque."<<endl;

    do{
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
    while(id_function(media, fonction, param));




    /*livre book1(LIVRE, 1,"cest le boud1", "einstein", 1994, 21,"numorama", "il etait une fois");
    book1.show();
    */
    return 1;
}
