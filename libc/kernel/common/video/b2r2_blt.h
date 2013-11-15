/****************************************************************************
 ****************************************************************************
 ***
 ***   This header was automatically generated from a Linux kernel header
 ***   of the same name, to make information necessary for userspace to
 ***   call into the kernel available to libc.  It contains only constants,
 ***   structures, and macros generated from the original header, and thus,
 ***   contains no copyrightable information.
 ***
 ****************************************************************************
 ****************************************************************************/
#ifndef _LINUX_VIDEO_B2R2_BLT_H
#define _LINUX_VIDEO_B2R2_BLT_H

#include <linux/types.h>
#include <linux/bitops.h>

struct b2r2_blt_rect {
 __s32 x;
 __s32 y;
 __s32 width;
 __s32 height;
};

enum b2r2_blt_fmt {
 B2R2_BLT_FMT_UNUSED = 0,
 B2R2_BLT_FMT_16_BIT_ARGB4444 = 4,
 B2R2_BLT_FMT_16_BIT_ARGB1555 = 5,
 B2R2_BLT_FMT_16_BIT_RGB565 = 6,
 B2R2_BLT_FMT_24_BIT_RGB888 = 11,
 B2R2_BLT_FMT_32_BIT_ARGB8888 = 16,
 B2R2_BLT_FMT_YUV420_PACKED_PLANAR = 20,
 B2R2_BLT_FMT_YUV422_PACKED_PLANAR = 23,
 B2R2_BLT_FMT_Y_CB_Y_CR = 25,
 B2R2_BLT_FMT_CB_Y_CR_Y = 27,
 B2R2_BLT_FMT_YUV420_PACKED_SEMI_PLANAR = 39,
 B2R2_BLT_FMT_YUV422_PACKED_SEMI_PLANAR = 40,

 B2R2_BLT_FMT_32_BIT_ABGR8888 = 0x7F000000,
 B2R2_BLT_FMT_24_BIT_ARGB8565 = 0x7F000001,
 B2R2_BLT_FMT_24_BIT_YUV888 = 0x7F000002,
 B2R2_BLT_FMT_32_BIT_AYUV8888 = 0x7F000003,
 B2R2_BLT_FMT_YUV420_PACKED_SEMIPLANAR_MB_STE = 0x7F000004,
 B2R2_BLT_FMT_YUV422_PACKED_SEMIPLANAR_MB_STE = 0x7F000005,
 B2R2_BLT_FMT_1_BIT_A1 = 0x7F000006,
 B2R2_BLT_FMT_8_BIT_A8 = 0x7F000007,
 B2R2_BLT_FMT_YUV444_PACKED_PLANAR = 0x7F000008,
};

enum b2r2_blt_ptr_type {
 B2R2_BLT_PTR_NONE,
 B2R2_BLT_PTR_VIRTUAL,
 B2R2_BLT_PTR_PHYSICAL,
 B2R2_BLT_PTR_FD_OFFSET,
 B2R2_BLT_PTR_HWMEM_BUF_NAME_OFFSET,
};

struct b2r2_blt_buf {
 enum b2r2_blt_ptr_type type;
 __s32 hwmem_buf_name;
 __s32 fd;
 __u32 offset;
 __u32 len;
 void *bits;
};

struct b2r2_blt_img {
 enum b2r2_blt_fmt fmt;
 struct b2r2_blt_buf buf;
 __s32 width;
 __s32 height;
 __u32 pitch;
};

enum b2r2_blt_transform {
 B2R2_BLT_TRANSFORM_NONE = 0,
 B2R2_BLT_TRANSFORM_FLIP_H = 1,
 B2R2_BLT_TRANSFORM_FLIP_V = 2,
 B2R2_BLT_TRANSFORM_CCW_ROT_90 = 4,
 B2R2_BLT_TRANSFORM_CCW_ROT_180 = 3,
 B2R2_BLT_TRANSFORM_CCW_ROT_270 = 7,
 B2R2_BLT_TRANSFORM_FLIP_H_CCW_ROT_90 = 5,
 B2R2_BLT_TRANSFORM_FLIP_V_CCW_ROT_90 = 6,
};

#ifndef _KERNEL
#define BIT(nr) (1UL << (nr))
#endif
enum b2r2_blt_flag {
 B2R2_BLT_FLAG_ASYNCH = BIT(0),
 B2R2_BLT_FLAG_DRY_RUN = BIT(1),
 B2R2_BLT_FLAG_PER_PIXEL_ALPHA_BLEND = BIT(2),
 B2R2_BLT_FLAG_GLOBAL_ALPHA_BLEND = BIT(3),
 B2R2_BLT_FLAG_SOURCE_COLOR_KEY = BIT(4),
 B2R2_BLT_FLAG_SOURCE_FILL = BIT(5),
 B2R2_BLT_FLAG_SOURCE_FILL_RAW = BIT(6),
 B2R2_BLT_FLAG_DEST_COLOR_KEY = BIT(7),
 B2R2_BLT_FLAG_SRC_IS_NOT_PREMULT = BIT(8),
 B2R2_BLT_FLAG_DITHER = BIT(9),
 B2R2_BLT_FLAG_BLUR = BIT(10),
 B2R2_BLT_FLAG_SOURCE_MASK = BIT(11),
 B2R2_BLT_FLAG_DESTINATION_CLIP = BIT(12),
 B2R2_BLT_FLAG_INHERIT_PRIO = BIT(13),
 B2R2_BLT_FLAG_SRC_NO_CACHE_FLUSH = BIT(14),
 B2R2_BLT_FLAG_SRC_MASK_NO_CACHE_FLUSH = BIT(15),
 B2R2_BLT_FLAG_DST_NO_CACHE_FLUSH = BIT(16),
 B2R2_BLT_FLAG_BG_BLEND = BIT(17),
 B2R2_BLT_FLAG_BG_NO_CACHE_FLUSH = BIT(18),
 B2R2_BLT_FLAG_REPORT_WHEN_DONE = BIT(29),
 B2R2_BLT_FLAG_REPORT_PERFORMANCE = BIT(30),
 B2R2_BLT_FLAG_CLUT_COLOR_CORRECTION = BIT(31),
};

struct b2r2_blt_req {
 __u32 size;
 enum b2r2_blt_flag flags;
 enum b2r2_blt_transform transform;
 __s32 prio;
 void *clut;
 struct b2r2_blt_img src_img;
 struct b2r2_blt_img src_mask;
 struct b2r2_blt_rect src_rect;
 __u32 src_color;
 struct b2r2_blt_img bg_img;
 struct b2r2_blt_rect bg_rect;
 struct b2r2_blt_img dst_img;
 struct b2r2_blt_rect dst_rect;
 struct b2r2_blt_rect dst_clip_rect;
 __u32 dst_color;
 __u8 global_alpha;
 __u32 report1;
 __u32 report2;
};

enum b2r2_blt_cap {
 B2R2_BLT_CAP_UNUSED = 0,

 B2R2_BLT_CAP_FMT_SOURCE,

 B2R2_BLT_CAP_FMT_SOURCE_MASK,

 B2R2_BLT_CAP_FMT_DEST,

 B2R2_BLT_CAP_PER_PIXEL_ALPHA_BLEND,

 B2R2_BLT_CAP_GLOBAL_ALPHA_BLEND,

 B2R2_BLT_CAP_SOURCE_COLOR_KEY,

 B2R2_BLT_CAP_SOURCE_FILL,

 B2R2_BLT_CAP_SOURCE_FILL_RAW,

 B2R2_BLT_CAP_DEST_COLOR_KEY,

 B2R2_BLT_CAP_DITHER,

 B2R2_BLT_CAP_BLUR,

 B2R2_BLT_CAP_MINIFICATION_LIMIT,

 B2R2_BLT_CAP_MAGNIFICATION_LIMIT,

 B2R2_BLT_CAP_SCALING_FRAC_BITS,

 B2R2_BLT_CAP_ROTATION_STEP_DEG,
};

struct b2r2_blt_query_cap {
 enum b2r2_blt_fmt fmt;
 enum b2r2_blt_cap cap;
 __u32 result;
};

struct b2r2_blt_report {
 __u32 request_id;
 __u32 report1;
 __u32 report2;
 __u32 usec_elapsed;
};

#define B2R2_BLT_IOC_MAGIC 0xb2

#define B2R2_BLT_IOC _IOW(B2R2_BLT_IOC_MAGIC, 1, struct b2r2_blt_req)

#define B2R2_BLT_SYNCH_IOC _IOW(B2R2_BLT_IOC_MAGIC, 2, int)

#define B2R2_BLT_QUERY_CAP_IOC _IOWR(B2R2_BLT_IOC_MAGIC, 3,   struct b2r2_blt_query_cap)

#endif

