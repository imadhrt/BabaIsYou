//
// Created by Mamoun benmassaoud on 20/04/2023.
//

#ifndef PROJET_BABA_IS_YOU_OBSERVER_H
#define PROJET_BABA_IS_YOU_OBSERVER_H
class Observer {
public:
    /**
     * @brief destructeur
     */
    virtual ~Observer() {}
    /**
     * @brief Met a jour en fonction de se que l'obsevable fais
     */
    virtual void update() = 0;
};

#endif //PROJET_BABA_IS_YOU_OBSERVER_H
