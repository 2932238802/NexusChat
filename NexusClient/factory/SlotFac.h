#include"../Slot/ButtonSlot.h"

namespace Factory{


class SlotFac
{
    static Slot::ButtonSlot::ptr GetButtonSlot()
    {
        Slot::ButtonSlot::ptr newptr = std::make_shared<Slot::ButtonSlot>();
        return newptr;
    }
};



}
