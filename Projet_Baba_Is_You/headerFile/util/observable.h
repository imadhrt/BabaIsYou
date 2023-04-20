//
// Created by Mamoun benmassaoud on 20/04/2023.
//

#ifndef PROJET_BABA_IS_YOU_OBSERVABLE_H
#define PROJET_BABA_IS_YOU_OBSERVABLE_H

#include "observer.h"

/**
 * @brief est observé par l'observer
 */
class Observable {
public:
    /**
     * @brief destructeur
     */
    virtual ~Observable() {}
    /**
     * @brief rajoute un observer a la liste d'observer qui peuvent mettre a jour le contenu
     * de l'objet courant
     * @param observer l'observer à rajouter dans la liste
     */
    virtual void registerObserver(Observer *observer) = 0;
    /**
     * @brief Permet de retirer le dernier observer de la liste
     */
    virtual void unregisterObserver() = 0;
    /**
     * @brief Préviens l'observer que un changement à été fait
     */
    virtual void notifyObservers() = 0;
};
#endif //PROJET_BABA_IS_YOU_OBSERVABLE_H
