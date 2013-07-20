#ifndef XEN_HH
#define XEN_HH
#include <osv/types.h>
#include <osv/pvclock-abi.hh>
#include "cpuid.hh"
#include <xen/interface/xen.h>
#include <xen/interface/memory.h>
#include <xen/interface/version.h>
#include <xen/interface/hvm/hvm_op.h>

extern char hypercall_page[];
extern uint8_t xen_features[];

// We don't support 32 bit
struct xen_vcpu_info {
    uint8_t evtchn_upcall_pending;
    uint8_t evtchn_upcall_mask;
    uint64_t evtchn_pending_sel;
    uint64_t cr2;
    uint64_t pad;
    pvclock_vcpu_time_info time;
};

struct xen_shared_info {
	struct xen_vcpu_info vcpu_info[32];

    unsigned long pad0[2 * sizeof(unsigned long) * 8];

	pvclock_wall_clock wc;

    unsigned long pad1[3];
};

namespace xen {

void xen_init(processor::features_type &features, unsigned base);
extern struct xen_shared_info xen_shared_info;
void xen_set_callback(void);

}

#endif
