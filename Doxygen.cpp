/**
* \file Matrice.cpp
* \brief Librairie de gestion de matrice
* \author Léo Saladin
* \version 1
* \date 26 avril 2016
*/

/**
 * @brief      Contructeur a deux arguments, créer un tableau de structure. Les arguments définissent le nombre de lignes et colonnes de la matrice creuse.
 *
 * @param[in]  ligne    Nombre de ligne de la matrice.
 * @param[in]  colonne  Nombre de colonne de la matrice.
 */
 Matrice::Matrice(int ligne, int colonne);
 /**
 * @brief      Contructeur a un argument, chargeant une matrice à partir d'un string.
 *
 * @param[in]  nom   Chaine de caractère comportant le nom du fichier à charger.
 */
Matrice::Matrice(string nom);
/**
 * @brief      Destructeur vide car il n'y a aucun élément dynamique à détruire.
 */
Matrice::~Matrice();
/**
 * @brief      Retourne le nombre de ligne de la matrice.
 *
 * @return     Entier
 */
int Matrice::TailleLigne();
/**
 * @brief      Retourne le nombre de colonne de la matrice.
 *
 * @return     Entier
 */
int Matrice::TailleColonne();

/**
 * @brief      Retourne le nombre de case non nulles de la matrice.
 *
 * @return     Entier
 */
int Matrice::NombreCases();
/**
 * @brief      Permet d'accéder au vector private de la class. 
 *
 * @param      Position de la case (integer) 
 *
 * @return     Structure Case par référence
 */
Case& Matrice::operator()(int element);
/**
 * @brief      Retourne la case
 *
 * @param      Position de la case (integer) 
 *
 * @return     Structure Case
 */
Case Matrice::operator()(int element);
/**
 * @brief      Opérateur qui affiche le contenu d'une matrice, seulement les cases pleines
 *
 */
ostream& operator<<(std::ostream& flux, const Matrice& matrice);
/**
 * @brief      Initialisation une matrice tant que l'utilisateur veut ajouter des cases
 */
void Matrice::Initialisation();
/**
 * @brief      Fonction qui va créer une matrice
 *
 * @param[in]  lig     Total de ligne de la matrice
 * @param[in]  col     Total de colonne de la matrice
 * @param      i       Ligne de la case
 * @param      j       Colonne de la case
 * @param      valeur  Valeur de la case
 *
 * @return     Boolean, retourne vrai si c'est possible
 */
 bool Init(int lig, int col, int& i, int& j, double& valeur);

 /**
 * @brief      Oblige de rentrer de les bon types de valeur
 *
 * @param[in]  i       Coordonnée d'une case ligne ou colonne
 * @param[in]  str     Chaine de caractère
 * @param[in]  taille  Total de ligne ou colonne
 *
 * @return     Boolean, retourne vrai si le condition est respecté
 */
int CheckAllChar(int i, string str, int taille);
/**
 * @brief      Vérifie si on peut rentrer que des valeur de type integer
 *
 * @param[in]  mot   Chaine de caractère
 *
 * @return     Retourne un entier
 */
int CheckStringToInt(string mot);
/**
 * @brief      Vérifie si on peut rentrer que des valeur de type double
 *
 * @param[in]  mot   Chaine de caractère
 *
 * @return     Valeur de type double
 */
double CheckStringToDouble(string mot);
/**
 * @brief      Permet de modifier une case en particulier, elle sera appelée dans la fonction Initialisation()
 *
 * @param[in]  ligne    Nombre de la ligne
 * @param[in]  colonne  Nombre de la colonne
 * @param[in]  valeur   Valeur dans la case de la matrice
 *
 * @return     Boolean, retourne vrai si la case a bien été créer
 */
bool Matrice::AjouterCase(int ligne, int colonne, double valeur);
/**
 * @brief      Permet de modifier une case en particulier, elle sera appelée dans la fonction Initialisation()
 *
 * @param[in]  ligne    Nombre de la ligne
 * @param[in]  colonne  Nombre de la colonne
 * @param[in]  valeur   Valeur dans la case de la matrice
 */
void Matrice::ModifierCase(int ligne, int colonne, double valeur);
/**
 * @brief      Teste si la structure en argument existe
 *
 * @param[in]  element  Structure de case
 *
 * @return     Boolean
 */
bool Matrice::EstPresent(Case element);
/**
 * @brief      Trie une matrice en ordre croissant de ligne puis colonne
 */
void Matrice::SortCases();
/**
 * @brief      Charge une matrice en fonction d'une chaine de caractère
 *
 * @param[in]  nom   Chaine de caractère
 */
void Matrice::Charger(string nom);
/**
 * @brief      Sauvegarde une matrice en fonction d'une chaine de caractère
 *
 * @param[in]  nom   Chaine de caractère
 */
void Matrice::Sauvegarder(string nom);
/**
 * @brief      Transpose la matrice
 */
void Matrice::Transposer();
/**
 * @brief      Opérateur d'égalité entre deux matrices
 */
Matrice Matrice::operator=(const Matrice& matrice);
/**
 * @brief      Opérateur d'addition entre deux matrices
 */
Matrice operator+(const Matrice& matrice1,const Matrice& matrice2);
/**
 * @brief      Opérateur de soustraction entre deux matrices
 */
Matrice operator-(const Matrice& matrice1,const Matrice& matrice2);
/**
 * @brief      Opérateur de multiplication entre deux matrices
 */
Matrice operator*(const Matrice& matrice1,const Matrice& matrice2);
/**
 * @brief      Opérateur matricielle de soustraction égale
 */
Matrice& Matrice::operator-=(const Matrice& matrice);