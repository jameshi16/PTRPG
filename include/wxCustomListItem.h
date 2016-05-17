#ifndef WXCUSTOMLISTITEM_H
#define WXCUSTOMLISTITEM_H

#include <wx/listctrl.h>
#include <Item.h>

//To store item too
class wxCustomListItem : public wxListItem
{
    public:
        void setPairedItem(Item* item)
        {
            m_item = item;
        }

        Item* getPairedItem()
        {
            return m_item;
        }

    protected:

    private:
        Item* m_item = 0; //zeros the pointer
};

#endif // WXCUSTOMLISTITEM_H
