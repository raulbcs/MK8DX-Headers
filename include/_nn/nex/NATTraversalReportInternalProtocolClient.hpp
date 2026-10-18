#pragma once

#include <_nn/nex/ClientProtocol.hpp>

namespace nn::nex {
// NATTraversalReportInternalProtocolClient (nex RTTI record 0x12f6040, base
// ClientProtocol): vptr 0x12f5d90 via GOT cell 0x1315880 (holds vt-0x10);
// no standalone C1 (built inlined inside NATTraversalRelayProtocolImpl at
// +0x98), D0 0xb179f8 (operator new(0x90)).
// extent 0x90 - details:
// doc/_nn/nex/NATTraversalReportInternalProtocolClient.md
class NATTraversalReportInternalProtocolClient : public ClientProtocol {};
}  // namespace nn::nex
