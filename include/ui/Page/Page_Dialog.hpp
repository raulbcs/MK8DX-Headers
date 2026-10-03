#pragma once
#include "EUIPageID.hpp"
#include "DialogReq.hpp"

#include "gear/UI/Page/UIPage.hpp"

namespace ui
{
    enum EDialogResult
    {
        NONERES,
        YES,
        NO
    };

    /*     * Wii U (32-bit) layout and are NOT valid on Switch. Field order is
     * kept as a placeholder until the offsets are re-derived from the
     * 64-bit binary.
     */
    class Page_Dialog : public gear::UIPage
    {
        public:
            uint8_t pad_120[0xC];
            bool isDialogOpen;
            uint8_t pad_12D;
            uint16_t pad_12E;
            uint8_t pad_130[0x34];
            EDialogResult m_dialogResult;

            void open_(ui::UIDialogReq &, gear::EUIPageID);
    };
}

namespace gear
{
    ui::Page_Dialog* GetUIDialog();
}
