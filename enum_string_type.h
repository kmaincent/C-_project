#ifndef ENUM_STRING_TYPE_H
#define ENUM_STRING_TYPE_H

enum type_ressource {LIVRE, REVUE, CD, VHS, DVD, RESSOURCE_NUM, ERROR_RES};
const std::string  type_string[]={"LIVRE", "REVUE", "CD", "VHS", "DVD", "RESSOURCE NUM"};


enum etat {DISPONIBLE, EMPRUNTE, RESERVE, ERROR_ET};
const std::string etat_string[]={"DISPONIBLE", "RESERVE", "EMPRUNTE"};

type_ressource enum_string_type(std::string str_type);
std::string enum_string_type(type_ressource enum_type);

etat enum_string_etat(std::string str_type);
std::string enum_string_etat (etat enum_etat);

#endif //ENUM_STRING_TYPE_H
