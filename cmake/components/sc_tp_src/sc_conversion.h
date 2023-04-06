#include "sc_struct.h"
#include "emcpose.h"

struct sc_pnt emc_pose_to_sc_pnt(struct EmcPose pose);

struct sc_dir emc_pose_to_sc_dir(struct EmcPose pose);

struct sc_ext emc_pose_to_sc_ext(struct EmcPose pose);

struct sc_pnt emc_cart_to_sc_pnt(PmCartesian pnt);

PmCartesian sc_pnt_to_emc_cart(struct sc_pnt pnt);
