/* SPDX-License-Identifier: MIT-0 OR CC0-1.0 *\
\*    Authored 2024 by Peter S. Hollander    */


#ifndef PICO_BINARY_LICENSE_INFO_H_
#define PICO_BINARY_LICENSE_INFO_H_


#include "pico/binary_info/code.h"


#define BINARY_INFO_TAG_LICENSE_INFO BINARY_INFO_MAKE_TAG('L','I')

#define BINARY_INFO_ID_LI_AUTHOR  0x723f4094
#define BINARY_INFO_ID_LI_LICENSE 0xad531a90

#define bi_program_author(author) bi_string(BINARY_INFO_TAG_LICENSE_INFO, BINARY_INFO_ID_LI_AUTHOR, author)
#define bi_program_license(license) bi_string(BINARY_INFO_TAG_LICENSE_INFO, BINARY_INFO_ID_LI_LICENSE, license)

bi_decl(bi_program_feature_group(BINARY_INFO_TAG_LICENSE_INFO, BINARY_INFO_ID_LI_AUTHOR, "author"));
bi_decl(bi_program_feature_group_with_flags(BINARY_INFO_TAG_LICENSE_INFO, BINARY_INFO_ID_LI_LICENSE, "license", BI_NAMED_GROUP_SHOW_IF_EMPTY));


#endif  // PICO_BINARY_LICENSE_INFO_H_
