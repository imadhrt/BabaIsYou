//
// Created by elhar on 21-03-23.
//

#ifndef PROJET_BABA_IS_YOU_MATERIALS_H
#define PROJET_BABA_IS_YOU_MATERIALS_H
#include "enum.h"
#include "element.h"

class Materials:public Element{
private:
    Icon icon;
public:

    ~Materials() override;

    explicit Materials(Icon newIcon);

    Icon getIcon()const;
    void setIcon(Icon newIcon);



};





#endif //PROJET_BABA_IS_YOU_MATERIALS_H
