//
// Created by elhar on 25-03-23.
//


#include "../../headerFile/model/materials.h"

/**
 * Constructeur de la classe Materials.
 *
 * @param newIcon L'icône du nouveau matériau à créer.
 */
Materials::Materials(Icon newIcon) : icon(newIcon) {}

/**
 * Destructeur de la classe Materials.
 */
Materials::~Materials() {}

/**
 * Opérateur d'égalité pour la classe Materials.
 *
 * @param rhs L'autre instance de Materials à comparer.
 * @return true si les icônes des deux instances sont égales, sinon false.
 */
bool Materials::operator==(const Materials &rhs) const {
    return icon == rhs.icon;
}

/**
 * Opérateur de différence pour la classe Materials.
 *
 * @param rhs L'autre instance de Materials à comparer.
 * @return true si les icônes des deux instances sont différentes, sinon false.
 */
bool Materials::operator!=(const Materials &rhs) const {
    return !(rhs == *this);
}

/**
 *  Accesseur pour l'icône du matériau.
 *
 * @return L'icône du matériau.
 */
Icon Materials::getIcon() const {
    return icon;
}

/**
 *  Mutateur pour l'icône du matériau.
 *
 * @param newIcon La nouvelle icône à attribuer au matériau.
 */
void Materials::setIcon(Icon newIcon) {
    Materials::icon = newIcon;
}
