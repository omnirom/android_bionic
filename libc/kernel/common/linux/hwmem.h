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
#ifndef _HWMEM_H_
#define _HWMEM_H_

#ifndef _KERNEL
#include <stdint.h>
#include <sys/types.h>
#else
#include <linux/types.h>
#include <linux/mm_types.h>
#endif

#define HWMEM_DEFAULT_DEVICE_NAME "hwmem"

enum hwmem_alloc_flags {

 HWMEM_ALLOC_HINT_WRITE_COMBINE = (1 << 0),

 HWMEM_ALLOC_HINT_NO_WRITE_COMBINE = (1 << 1),

 HWMEM_ALLOC_HINT_CACHED = (1 << 2),

 HWMEM_ALLOC_HINT_UNCACHED = (1 << 3),

 HWMEM_ALLOC_HINT_CACHE_WB = (1 << 4),

 HWMEM_ALLOC_HINT_CACHE_WT = (1 << 5),

 HWMEM_ALLOC_HINT_CACHE_NAOW = (1 << 6),

 HWMEM_ALLOC_HINT_CACHE_AOW = (1 << 7),

 HWMEM_ALLOC_HINT_INNER_AND_OUTER_CACHE = (1 << 8),

 HWMEM_ALLOC_HINT_INNER_CACHE_ONLY = (1 << 9),

 HWMEM_ALLOC_RESERVED_CHI = (1 << 31),
};

enum hwmem_access {

 HWMEM_ACCESS_READ = (1 << 0),

 HWMEM_ACCESS_WRITE = (1 << 1),

 HWMEM_ACCESS_IMPORT = (1 << 2),
};

enum hwmem_mem_type {

 HWMEM_MEM_SCATTERED_SYS,

 HWMEM_MEM_CONTIGUOUS_SYS,
};

struct hwmem_region_us {
 __u32 offset;
 __u32 count;
 __u32 start;
 __u32 end;
 __u32 size;
};

struct hwmem_alloc_request {

 __u32 size;

 __u32 flags;

 __u32 default_access;

 __u32 mem_type;
};

struct hwmem_set_domain_request {

 __s32 id;

 __u32 access;

 struct hwmem_region_us region;
};

struct hwmem_pin_request {

 __s32 id;

 __u32 phys_addr;
};

struct hwmem_set_access_request {

 __s32 id;

 __u32 access;

 pid_t pid;
};

struct hwmem_get_info_request {

 __s32 id;

 __u32 size;

 __u32 mem_type;

 __u32 access;
};

#define HWMEM_ALLOC_IOC _IOW('W', 1, struct hwmem_alloc_request)

#define HWMEM_ALLOC_FD_IOC _IOW('W', 2, struct hwmem_alloc_request)

#define HWMEM_RELEASE_IOC _IO('W', 3)

#define HWMEM_SET_CPU_DOMAIN_IOC _IOW('W', 4, struct hwmem_set_domain_request)

#define HWMEM_SET_SYNC_DOMAIN_IOC _IOW('W', 5, struct hwmem_set_domain_request)

#define HWMEM_PIN_IOC _IOWR('W', 6, struct hwmem_pin_request)

#define HWMEM_UNPIN_IOC _IO('W', 7)

#define HWMEM_SET_ACCESS_IOC _IOW('W', 8, struct hwmem_set_access_request)

#define HWMEM_GET_INFO_IOC _IOWR('W', 9, struct hwmem_get_info_request)

#define HWMEM_EXPORT_IOC _IO('W', 10)

#define HWMEM_IMPORT_IOC _IO('W', 11)

#define HWMEM_IMPORT_FD_IOC _IO('W', 12)

#endif

