#pragma once

// Shim: vendor sead headers include <hostio/seadHostIONode.h>, but the
// MK8DX 4.0.0 sead fork disables hostio (see the mirrored
// sead/hostio/seadHostIONode.hpp). Redirect to the mirror so both never
// define sead::hostio::Node in the same TU.
#include "sead/hostio/seadHostIONode.hpp"
