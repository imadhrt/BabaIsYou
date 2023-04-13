//
// Created by elhar on 21-03-23.
//

#ifndef PROJET_BABA_IS_YOU_MATERIALS_H
#define PROJET_BABA_IS_YOU_MATERIALS_H
#include "enum.h"

class Materials{
private:
    Icon icon;
public:

    ~Materials();

    explicit Materials(Icon newIcon);
    Materials()=default;
    Icon getIcon()const;
    void setIcon(Icon newIcon);



};





#endif //PROJET_BABA_IS_YOU_MATERIALS_H
