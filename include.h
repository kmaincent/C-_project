#ifndef INCLUDE_H
#define INCLUDE_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm>    // std::transform
using namespace std;

#include "utilisateur.h"
#include "id_function.h"
#include "enum_string_type.h"
#include "ressource.h"
#include "livre.h"
#include "revue.h"
#include "vhs.h"
#include "cd.h"
#include "dvd.h"
#include "ressource_num.h"
#include "mediatheque.h"

#define NB_DATA_RESSOURCE     4
#define NB_DATA_LIVRE         4+NB_DATA_RESSOURCE
#define NB_DATA_REVUE         3+NB_DATA_LIVRE+NB_DATA_RESSOURCE
#define NB_DATA_VHS           2+NB_DATA_RESSOURCE
#define NB_DATA_CD            1+NB_DATA_RESSOURCE+NB_DATA_VHS
#define NB_DATA_DVD           1+NB_DATA_RESSOURCE+NB_DATA_VHS
#define NB_DATA_RESSOURCE_NUM 3+NB_DATA_RESSOURCE

#endif
