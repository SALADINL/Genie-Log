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
 * @return     Entier.
 */
int Matrice::TailleLigne() const;
/**
 * @brief      Retourne le nombre de colonne de la matrice.
 *
 * @return     Entier.
 */
int Matrice::TailleColonne() const;

/**
 * @brief      Retourne le nombre de case non nulles de la matrice.
 *
 * @return     Entier.
 */
int Matrice::NombreCases() const;
/**
 * @brief      Permet d'accéder au vector private de la class. Cela va donc nous retourner la structure case à la position élément.
 *
 * @return     Structure Case par référence.
 */
Case& Matrice::operator()(int element);
/**
 * @brief      Permet d'accéder au vector private de la class. Cela va donc nous retourner la structure case à la position élément.
 *
 * @return     Structure Case.
 */
Case Matrice::operator()(int element) const;
/**
 * @brief      Surcharge de l'opérateur << qui affiche les cases de la matrice (donc seulement les cases non nulles).
 *
 * @return     Retourne un objet ostream par référence.
 */
ostream& operator<<(std::ostream& flux, const Matrice& matrice);
/**
 * @brief      La fonction Initialisation() permet à l'utilisateur d'ajouter des cases tant qu'il le veut dans la matrice.
 */
void Matrice::Initialisation();
/**
 * @brief      Fonction qui va ajouter les cases à le tableau de structure de cases.
 *
 * @param[in]  lig     Nombre de ligne de la matrice.
 * @param[in]  col     Nombre de colonne de la matrice.
 * @param      i       Ligne de la case.
 * @param      j       Colonne de la case.
 * @param      valeur  Valeur de la case.
 *
 * @return     Boolean, retourne vrai si l'utilisateur à modifier une case.
 */
 bool Init(int lig, int col, int& i, int& j, double& valeur);

 /**
 * @brief      Empêche l'utilisateur de rentrer autre chose qu'un entier pour les coordonnées de la case à modifier.
 *
 * @param[in]  i       Coordonnée d'une case ligne ou colonne.
 * @param[in]  str     Chaine de caractère qui contient l'entier à transformer.
 * @param[in]  taille  Condition à respecter. Pour éviter que la coordonnée dépasse le nombre de lignes ou de colonnes de la matrice.
 *
 * @return     Retourne un entier.
 */
int CheckAllChar(int i, string str, int taille);
/**
 * @brief      Vérifie si la chaine de caractère est valide pour la transformer en entier.
 *
 * @param[in]  mot   Chaine de caractère qui contient l'entier à transformer.
 *
 * @return     Retourne un entier.
 */
int CheckStringToInt(string mot);
/**
 * @brief      Empêche l'utilisateur de rentrer autre chose qu'un double pour la valeur de la case à modifier.
 *
 * @param[in]  mot   Chaine de caractère contenant le double à transformer.
 *
 * @return     Valeur de type double.
 */
double CheckStringToDouble(string mot);
/**
 * @brief      Permet de modifier une case en particulier, elle sera appelée dans la fonction Initialisation().
 *
 * @param[in]  ligne    Position de la ligne.
 * @param[in]  colonne  Position de la colonne.
 * @param[in]  valeur   Valeur de la case à modifier.
 *
 * @return     Boolean, retourne vrai si la case a bien été créée.
 */
bool Matrice::AjouterCase(int ligne, int colonne, double valeur);
/**
 * @brief      Permet de modifier une case en particulier, elle sera appelée dans les surcharges d'opérateurs pour éviter de re-créer une case.
 *
 * @param[in]  ligne    Nombre de la ligne
 * @param[in]  colonne  Nombre de la colonne
 * @param[in]  valeur   Valeur dans la case de la matrice
 */
void Matrice::ModifierCase(int ligne, int colonne, double valeur);
/**
 * @brief      Test si la case element existe déjà dans le tableau de structure.
 *
 * @param[in]  element  Structure de case.
 *
 * @return     Boolean
 */
bool Matrice::EstPresent(Case element);
/**
 * @brief      Tri une matrice en ordre croissant de ligne puis colonne.
 */
void Matrice::SortCases();
/**
 * @brief      Charge une matrice à partir du fichier de nom : "nom".
 *
 * @param[in]  nom   Chaine de caractère contenant le nom du fichier où est stocké la matrice sous forme LVC.
 */
void Matrice::Charger(string nom);
/**
 * @brief      Sauvegarde une matrice dans un fichier de nom : "nom".
 *
 * @param[in]  nom   Chaine de caractère contenant le nom du fichier où sera stocké la matrice sous forme LVC.
 */
void Matrice::Sauvegarder(string nom);
/**
 * @brief      Cette fonction transpose la matrice.
 */
void Matrice::Transposer();
/**
 * @brief      Cet opérateur permet de transvaser une structure de case dans une autre.
 */
Matrice Matrice::operator=(const Matrice& matrice);
/**
 * @brief      Cet opérateur permet d'ajouter deux matrices.
 */
Matrice operator+(const Matrice& matrice1,const Matrice& matrice2);
/**
 * @brief      Cet opérateur permet de soustraire deux matrices.
 */
Matrice operator-(const Matrice& matrice1,const Matrice& matrice2);
/**
 * @brief      Cet opérateur permet de multiplier deux matrices.
 */
Matrice operator*(const Matrice& matrice1,const Matrice& matrice2);
/**
 * @brief      Cet opérateur permet d'additionner la deuxième matrice directement avec la premiere.
 */
Matrice& Matrice::operator+=(const Matrice& matrice);
/**
 * @brief      Cet opérateur permet de soustraire la deuxième matrice directement avec la premiere.
 */
Matrice& Matrice::operator-=(const Matrice& matrice);

