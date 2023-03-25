//
// Created by elhar on 25-03-23.
//


#include "../../headerFile/model/materials.h"

Materials::Materials(Icon newIcon) : icon(newIcon) {}

Materials::~Materials() {

}

Icon Materials::getIcon() const {
    return icon;
}

void Materials::setIcon(Icon newIcon) {
    Materials::icon = newIcon;
}
