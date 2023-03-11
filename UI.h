//
// Created by Vik on 18/04/2022.
//

#ifndef OOP_LAB4_UI_H
#define OOP_LAB4_UI_H

#include "Controller.h"

namespace ui{
    class PharmaUI{
    private:
        controller::PharmaController& control;

    public:  //ui ist die Interaktion zwischen Nutzer und Programm

        PharmaUI(controller::PharmaController& control);

        controller::PharmaController get_control();

        void menu();
    };
}

#endif //OOP_LAB4_UI_H
