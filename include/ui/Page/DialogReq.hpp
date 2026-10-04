#pragma once

#include <cstdint>
#include "EDialogType.hpp"

namespace ui
{
    class UIDialogReq
    {
        public:

            void init();
            void set(ui::EDialogType, int, int);

            UIDialogReq();
    };
}