/**********************************************************************
 * Copyright (c) 2018 Pieter Wuille, Greg Maxwell, Gleb Naumenko      *
 * Distributed under the MIT software license, see the accompanying   *
 * file LICENSE or http://www.opensource.org/licenses/mit-license.php.*
 **********************************************************************/

/* This file was substantially auto-generated by doc/gen_params.sage. */
#include "../fielddefines.h"

#if defined(ENABLE_FIELD_INT_33) || defined(ENABLE_FIELD_INT_34) || defined(ENABLE_FIELD_INT_35) || defined(ENABLE_FIELD_INT_36) || defined(ENABLE_FIELD_INT_37) || defined(ENABLE_FIELD_INT_38) || defined(ENABLE_FIELD_INT_39) || defined(ENABLE_FIELD_INT_40)

#include "clmul_common_impl.h"

#include "../int_utils.h"
#include "../lintrans.h"
#include "../sketch_impl.h"

#endif

#include "../sketch.h"

namespace {
#ifdef ENABLE_FIELD_INT_33
// 33 bit field
typedef RecLinTrans<uint64_t, 6, 6, 6, 5, 5, 5> StatTable33;
constexpr StatTable33 SQR_TABLE_33({0x1, 0x4, 0x10, 0x40, 0x100, 0x400, 0x1000, 0x4000, 0x10000, 0x40000, 0x100000, 0x400000, 0x1000000, 0x4000000, 0x10000000, 0x40000000, 0x100000000, 0x802, 0x2008, 0x8020, 0x20080, 0x80200, 0x200800, 0x802000, 0x2008000, 0x8020000, 0x20080000, 0x80200000, 0x800401, 0x2001004, 0x8004010, 0x20010040, 0x80040100});
constexpr StatTable33 SQR2_TABLE_33({0x1, 0x10, 0x100, 0x1000, 0x10000, 0x100000, 0x1000000, 0x10000000, 0x100000000, 0x2008, 0x20080, 0x200800, 0x2008000, 0x20080000, 0x800401, 0x8004010, 0x80040100, 0x400004, 0x4000040, 0x40000400, 0x4802, 0x48020, 0x480200, 0x4802000, 0x48020000, 0x80200802, 0x2009024, 0x20090240, 0x902001, 0x9020010, 0x90200100, 0x102000004, 0x20002048});
constexpr StatTable33 SQR4_TABLE_33({0x1, 0x10000, 0x100000000, 0x2008000, 0x80040100, 0x4802, 0x48020000, 0x902001, 0x20002048, 0x20081000, 0x10400004, 0x248820, 0x88204812, 0x49020410, 0x4822081, 0x20880641, 0x6000044, 0x480300, 0x3009024, 0x90220180, 0xa00c11, 0xc104050, 0x40482608, 0x2688b024, 0xb0690344, 0x102248834, 0x8a30c912, 0xc8062518, 0x24886803, 0x684a0244, 0x294a025, 0xa020294a, 0x280a1010});
constexpr StatTable33 SQR8_TABLE_33({0x1, 0x6000044, 0x280a1010, 0x122ac8e75, 0x83209926, 0x4a7a8a1, 0xcada863d, 0x6f2ab824, 0x6b4a8654, 0x70484bd6, 0x164c04e0b, 0x2fbc1617, 0xe095e5a3, 0xeaf7847d, 0xe5625e26, 0xa6aaa3e5, 0xc0164126, 0xd06217c0, 0x1ae58d21, 0xa8600250, 0xbaf87951, 0x8e12c19a, 0xa9b413b9, 0xb75ef087, 0x17e9214d9, 0x85968f33, 0x1e299478f, 0x92bc9a0f, 0x1975d642, 0x11af0b3f1, 0x4e86ee77, 0xe75f4726, 0x38026cce});
constexpr StatTable33 SQR16_TABLE_33({0x1, 0x185df5e91, 0x193fb40eb, 0xd464f9e4, 0x1ba2d73a6, 0x1d9288c5e, 0x5de03a49, 0x1869ea37b, 0x13faaf379, 0x195d1a8f5, 0x6afd5625, 0xf9d75bab, 0xaf44fe50, 0x101034b9e, 0xcc889caf, 0x5ec7455, 0x7d232a66, 0x17dcfe2c3, 0x1c66ff8d0, 0x17107e836, 0x1939cdead, 0x9852afa0, 0x1b946909a, 0x1846638c5, 0xdd5fa94c, 0x1cb2600fe, 0x19241c856, 0x15fe05ccd, 0xc9f9a425, 0x89e0f463, 0x37b01b39, 0xab0410e0, 0x1ace4ca03});
constexpr StatTable33 QRT_TABLE_33({0xba504dd4, 0x1e2798ef2, 0x1e2798ef0, 0x6698a4ec, 0x1e2798ef4, 0x1c7f1bef0, 0x6698a4e4, 0x16da1b384, 0x1e2798ee4, 0x661ca6ec, 0x1c7f1bed0, 0x1483b87a6, 0x6698a4a4, 0x800000, 0x16da1b304, 0x1a185101c, 0x1e2798fe4, 0xaa400954, 0x661ca4ec, 0x667caeec, 0x1c7f1bad0, 0x400800, 0x1483b8fa6, 0, 0x6698b4a4, 0x1c61da4b8, 0x802000, 0x16e5dadec, 0x16da1f304, 0x62fc8eec, 0x1a185901c, 0x1661da5ec, 0x1e2788fe4});
typedef Field<uint64_t, 33, 1025, StatTable33, &SQR_TABLE_33, &SQR2_TABLE_33, &SQR4_TABLE_33, &SQR8_TABLE_33, &SQR16_TABLE_33, &QRT_TABLE_33, IdTrans, &ID_TRANS, &ID_TRANS> Field33;
typedef FieldTri<uint64_t, 33, 10, RecLinTrans<uint64_t, 6, 6, 6, 5, 5, 5>, &SQR_TABLE_33, &SQR2_TABLE_33, &SQR4_TABLE_33, &SQR8_TABLE_33, &SQR16_TABLE_33, &QRT_TABLE_33, IdTrans, &ID_TRANS, &ID_TRANS> FieldTri33;
#endif

#ifdef ENABLE_FIELD_INT_34
// 34 bit field
typedef RecLinTrans<uint64_t, 6, 6, 6, 6, 5, 5> StatTable34;
constexpr StatTable34 SQR_TABLE_34({0x1, 0x4, 0x10, 0x40, 0x100, 0x400, 0x1000, 0x4000, 0x10000, 0x40000, 0x100000, 0x400000, 0x1000000, 0x4000000, 0x10000000, 0x40000000, 0x100000000, 0x81, 0x204, 0x810, 0x2040, 0x8100, 0x20400, 0x81000, 0x204000, 0x810000, 0x2040000, 0x8100000, 0x20400000, 0x81000000, 0x204000000, 0x10000102, 0x40000408, 0x100001020});
constexpr StatTable34 SQR2_TABLE_34({0x1, 0x10, 0x100, 0x1000, 0x10000, 0x100000, 0x1000000, 0x10000000, 0x100000000, 0x204, 0x2040, 0x20400, 0x204000, 0x2040000, 0x20400000, 0x204000000, 0x40000408, 0x4001, 0x40010, 0x400100, 0x4001000, 0x40010000, 0x100081, 0x1000810, 0x10008100, 0x100081000, 0x810204, 0x8102040, 0x81020400, 0x10204102, 0x102041020, 0x20410004, 0x204100040, 0x41000008});
constexpr StatTable34 SQR4_TABLE_34({0x1, 0x10000, 0x100000000, 0x204000, 0x40000408, 0x4001000, 0x10008100, 0x81020400, 0x204100040, 0x304, 0x3040000, 0x6041, 0x60410000, 0x1000c1010, 0x10304183, 0x4181020c, 0x102042060, 0x20400001, 0x50010, 0x100100081, 0xa14204, 0x142041428, 0x14001001, 0x10038500, 0x385020400, 0x204704140, 0x41000f1c, 0xf143040, 0x3041e145, 0x1e1430410, 0x3042c5050, 0x5030448b, 0x4481120c, 0x112048120});
constexpr StatTable34 SQR8_TABLE_34({0x1, 0x102042060, 0x4481120c, 0x1523455ab, 0x307081050, 0x21410f1c, 0x275d0e309, 0x3f676408a, 0x143a54d38, 0x304100344, 0x181774550, 0x1003cd092, 0x3f36b6421, 0x164d51695, 0x3e7c7f2ab, 0x9309b234, 0x354f8d24c, 0x1f5431410, 0x142012478, 0xc5225409, 0x14033f3cf, 0x123bd530c, 0x1100ee58, 0x35490c368, 0x2e1f3dcba, 0x2018108d2, 0x3c61a735d, 0xbf8fa918, 0x282ab07ea, 0x19c32af, 0x175e54c02, 0x2e4dfe2bb, 0x3374ab928, 0x3124a055});
constexpr StatTable34 SQR16_TABLE_34({0x1, 0x3448e6f02, 0x352590eb9, 0xb173da17, 0x264977d39, 0x172d45e48, 0x1e026e5d6, 0x357b54017, 0x2925d27a4, 0x1f6a32696, 0x2f49f220c, 0x3a7383d9e, 0x28111d79b, 0x5580fcf1, 0x276ede679, 0x175b379f8, 0x34d67b66, 0xc7019416, 0x3f3d9d59f, 0x2a7c2c032, 0x2b3482ba7, 0x177cd0128, 0x1d6f4bd2e, 0x31647a632, 0x41353027, 0x56292eea, 0x2733c0501, 0x6d7ed066, 0x2f3db9a75, 0x3225bc5cc, 0x3f22da089, 0xd0a7588e, 0xb60b22d1, 0xc2fddb7e});
constexpr StatTable34 QRT_TABLE_34({0x2f973a1f6, 0x40202, 0x40200, 0x348102060, 0x40204, 0x8000420, 0x348102068, 0x1092195c8, 0x40214, 0x3f6881b6e, 0x8000400, 0x3f810383e, 0x348102028, 0x340002068, 0x109219548, 0x24015a774, 0x40314, 0x3f050343e, 0x3f688196e, 0x3f81c3a3a, 0x8000000, 0x24031a560, 0x3f810303e, 0xb08c1a12, 0x348103028, 0xb2881906, 0x340000068, 0, 0x10921d548, 0x2e131e576, 0x240152774, 0x18921d55e, 0x50314, 0x14015271c});
typedef Field<uint64_t, 34, 129, StatTable34, &SQR_TABLE_34, &SQR2_TABLE_34, &SQR4_TABLE_34, &SQR8_TABLE_34, &SQR16_TABLE_34, &QRT_TABLE_34, IdTrans, &ID_TRANS, &ID_TRANS> Field34;
typedef FieldTri<uint64_t, 34, 7, RecLinTrans<uint64_t, 6, 6, 6, 6, 5, 5>, &SQR_TABLE_34, &SQR2_TABLE_34, &SQR4_TABLE_34, &SQR8_TABLE_34, &SQR16_TABLE_34, &QRT_TABLE_34, IdTrans, &ID_TRANS, &ID_TRANS> FieldTri34;
#endif

#ifdef ENABLE_FIELD_INT_35
// 35 bit field
typedef RecLinTrans<uint64_t, 6, 6, 6, 6, 6, 5> StatTable35;
constexpr StatTable35 SQR_TABLE_35({0x1, 0x4, 0x10, 0x40, 0x100, 0x400, 0x1000, 0x4000, 0x10000, 0x40000, 0x100000, 0x400000, 0x1000000, 0x4000000, 0x10000000, 0x40000000, 0x100000000, 0x400000000, 0xa, 0x28, 0xa0, 0x280, 0xa00, 0x2800, 0xa000, 0x28000, 0xa0000, 0x280000, 0xa00000, 0x2800000, 0xa000000, 0x28000000, 0xa0000000, 0x280000000, 0x200000005});
constexpr StatTable35 SQR2_TABLE_35({0x1, 0x10, 0x100, 0x1000, 0x10000, 0x100000, 0x1000000, 0x10000000, 0x100000000, 0xa, 0xa0, 0xa00, 0xa000, 0xa0000, 0xa00000, 0xa000000, 0xa0000000, 0x200000005, 0x44, 0x440, 0x4400, 0x44000, 0x440000, 0x4400000, 0x44000000, 0x440000000, 0x400000028, 0x2a8, 0x2a80, 0x2a800, 0x2a8000, 0x2a80000, 0x2a800000, 0x2a8000000, 0x280000011});
constexpr StatTable35 SQR4_TABLE_35({0x1, 0x10000, 0x100000000, 0xa000, 0xa0000000, 0x4400, 0x44000000, 0x2a80, 0x2a800000, 0x1010, 0x10100000, 0xa0a, 0xa0a0000, 0x200000445, 0x4444000, 0x4400002a8, 0x2aaa800, 0x2a8000101, 0x1000100, 0x10000a0, 0xa000a0, 0xa00044, 0x440044, 0x400440028, 0x4002a8028, 0x2802a8011, 0x280101011, 0x1010100a, 0x100a0a0a, 0x20a0a0a05, 0x20a044445, 0x444444440, 0x44442aaa8, 0x2aaaaaaa8, 0x2aaa90001});
constexpr StatTable35 SQR8_TABLE_35({0x1, 0x2aaa800, 0x44442aaa8, 0x6400006ed, 0x64e4e4e45, 0x14544000, 0x8a145454, 0x2000034df, 0x49a749a36, 0xaa0a0000, 0x10aa0aaa, 0x1ba1a, 0x393a91ba, 0x3febaaaa9, 0x285105155, 0xa0ad9ad4, 0x269ce8d3b, 0x4de74f4e6, 0x42aaa8028, 0x4002aeea8, 0x400e46eec, 0x544e4006c, 0x145440144, 0x2abede545, 0x44309e74c, 0xa74eeda4, 0x64444ee49, 0x1aa1aaaa, 0x2b90bb1b1, 0x393902109, 0x16bc47bb2, 0x271ad1511, 0x6c8f98767, 0x69d3aa74c, 0x27790dc3b});
constexpr StatTable35 SQR16_TABLE_35({0x1, 0x4c80f98a4, 0x763684437, 0x5a1cc86a0, 0x38922db8, 0x71755e12d, 0x2ca94c627, 0x388a2bc7f, 0x406596de0, 0x1818c6958, 0x174a92efe, 0x1a80c764e, 0x2f23eacbf, 0xd611ea8, 0x64d783fd5, 0x4fdfe0798, 0x31459de8d, 0x62c889d99, 0x9c419962, 0x2d8d865b3, 0x1ac7e7ffc, 0x38a0c12f3, 0x9fbc1076, 0x6f76d3b89, 0x6e472c757, 0x5f240de42, 0x10176ecc0, 0x20c1cef8, 0x8f77f91c, 0x3f6e533b9, 0x62017c147, 0x5ce81e2fa, 0x371fe4ad9, 0x2552b5046, 0xc3f3696c});
constexpr StatTable35 QRT_TABLE_35({0x5c2038114, 0x2bf547ee8, 0x2bf547eea, 0x2bf1074e8, 0x2bf547eee, 0x1883d0736, 0x2bf1074e0, 0x100420, 0x2bf547efe, 0x400800, 0x1883d0716, 0x5e90e4a0, 0x2bf1074a0, 0x4e70ac20, 0x1004a0, 0x2f060c880, 0x2bf547ffe, 0x37d55fffe, 0x400a00, 0x3372573de, 0x1883d0316, 0x700c20, 0x5e90eca0, 0x10604880, 0x2bf1064a0, 0x18f35377e, 0x4e708c20, 0x33f557ffe, 0x1044a0, 0x1bf557ffe, 0x2f0604880, 0x200000000, 0x2bf557ffe, 0, 0x37d57fffe});
typedef Field<uint64_t, 35, 5, StatTable35, &SQR_TABLE_35, &SQR2_TABLE_35, &SQR4_TABLE_35, &SQR8_TABLE_35, &SQR16_TABLE_35, &QRT_TABLE_35, IdTrans, &ID_TRANS, &ID_TRANS> Field35;
typedef FieldTri<uint64_t, 35, 2, RecLinTrans<uint64_t, 6, 6, 6, 6, 6, 5>, &SQR_TABLE_35, &SQR2_TABLE_35, &SQR4_TABLE_35, &SQR8_TABLE_35, &SQR16_TABLE_35, &QRT_TABLE_35, IdTrans, &ID_TRANS, &ID_TRANS> FieldTri35;
#endif

#ifdef ENABLE_FIELD_INT_36
// 36 bit field
typedef RecLinTrans<uint64_t, 6, 6, 6, 6, 6, 6> StatTable36;
constexpr StatTable36 SQR_TABLE_36({0x1, 0x4, 0x10, 0x40, 0x100, 0x400, 0x1000, 0x4000, 0x10000, 0x40000, 0x100000, 0x400000, 0x1000000, 0x4000000, 0x10000000, 0x40000000, 0x100000000, 0x400000000, 0x201, 0x804, 0x2010, 0x8040, 0x20100, 0x80400, 0x201000, 0x804000, 0x2010000, 0x8040000, 0x20100000, 0x80400000, 0x201000000, 0x804000000, 0x10000402, 0x40001008, 0x100004020, 0x400010080});
constexpr StatTable36 SQR2_TABLE_36({0x1, 0x10, 0x100, 0x1000, 0x10000, 0x100000, 0x1000000, 0x10000000, 0x100000000, 0x201, 0x2010, 0x20100, 0x201000, 0x2010000, 0x20100000, 0x201000000, 0x10000402, 0x100004020, 0x40001, 0x400010, 0x4000100, 0x40001000, 0x400010000, 0x100804, 0x1008040, 0x10080400, 0x100804000, 0x8040201, 0x80402010, 0x804020100, 0x40200008, 0x402000080, 0x20000004, 0x200000040, 0x2, 0x20});
constexpr StatTable36 SQR4_TABLE_36({0x1, 0x10000, 0x100000000, 0x201000, 0x10000402, 0x4000100, 0x1008040, 0x80402010, 0x20000004, 0x200, 0x2000000, 0x4020, 0x40200000, 0x80002, 0x800020000, 0x201008000, 0x80400010, 0x4, 0x40000, 0x400000000, 0x804000, 0x40001008, 0x10000400, 0x4020100, 0x201008040, 0x80000010, 0x800, 0x8000000, 0x10080, 0x100800000, 0x200008, 0x80402, 0x804020000, 0x201000040, 0x10, 0x100000});
constexpr StatTable36 SQR8_TABLE_36({0x1, 0x80400010, 0x804020000, 0x201008, 0x2000080, 0x20000804, 0x1008000, 0x402, 0x800000, 0x200, 0x80000010, 0x804020100, 0x40201000, 0x400010000, 0x100004, 0x201000000, 0x80400, 0x100000000, 0x40000, 0x10, 0x804000100, 0x40201008, 0x2010080, 0x20000800, 0x200008040, 0x10080000, 0x4020, 0x8000000, 0x2000, 0x800000100, 0x40200008, 0x402010000, 0x100804, 0x1000040, 0x10000402, 0x804000});
constexpr StatTable36 SQR16_TABLE_36({0x1, 0x402000000, 0x100800020, 0x201000, 0x10080402, 0x800000000, 0x1008040, 0x400000, 0x20000800, 0x200, 0x400010080, 0x100000020, 0x40200000, 0x10080002, 0x20100, 0x201008000, 0x80000000, 0x100804, 0x40000, 0x2000080, 0x20, 0x40001008, 0x10000002, 0x4020000, 0x201008040, 0x2010, 0x20100800, 0x8000000, 0x400010000, 0x4000, 0x200008, 0x2, 0x804000000, 0x201000040, 0x402000, 0x20100804});
constexpr StatTable36 QRT_TABLE_36({0x40200, 0x8b0526186, 0x8b0526184, 0x240001000, 0x8b0526180, 0xcb6894d94, 0x240001008, 0xdb6880c22, 0x8b0526190, 0x8000200, 0xcb6894db4, 0x500424836, 0x240001048, 0x406cb2834, 0xdb6880ca2, 0x241200008, 0x8b0526090, 0xdb05021a6, 0x8000000, 0xdb01829b2, 0xcb68949b4, 0x1001000, 0x500424036, 0x106116406, 0x240000048, 0xcb29968a4, 0x406cb0834, 0, 0xdb6884ca2, 0x110010516, 0x241208008, 0x430434520, 0x8b0536090, 0x41208040, 0xdb05221a6, 0xb6884d14});
typedef Field<uint64_t, 36, 513, StatTable36, &SQR_TABLE_36, &SQR2_TABLE_36, &SQR4_TABLE_36, &SQR8_TABLE_36, &SQR16_TABLE_36, &QRT_TABLE_36, IdTrans, &ID_TRANS, &ID_TRANS> Field36;
typedef FieldTri<uint64_t, 36, 9, RecLinTrans<uint64_t, 6, 6, 6, 6, 6, 6>, &SQR_TABLE_36, &SQR2_TABLE_36, &SQR4_TABLE_36, &SQR8_TABLE_36, &SQR16_TABLE_36, &QRT_TABLE_36, IdTrans, &ID_TRANS, &ID_TRANS> FieldTri36;
#endif

#ifdef ENABLE_FIELD_INT_37
// 37 bit field
typedef RecLinTrans<uint64_t, 6, 6, 5, 5, 5, 5, 5> StatTable37;
constexpr StatTable37 SQR_TABLE_37({0x1, 0x4, 0x10, 0x40, 0x100, 0x400, 0x1000, 0x4000, 0x10000, 0x40000, 0x100000, 0x400000, 0x1000000, 0x4000000, 0x10000000, 0x40000000, 0x100000000, 0x400000000, 0x1000000000, 0xa6, 0x298, 0xa60, 0x2980, 0xa600, 0x29800, 0xa6000, 0x298000, 0xa60000, 0x2980000, 0xa600000, 0x29800000, 0xa6000000, 0x298000000, 0xa60000000, 0x980000053, 0x60000011f, 0x180000047c});
constexpr StatTable37 SQR2_TABLE_37({0x1, 0x10, 0x100, 0x1000, 0x10000, 0x100000, 0x1000000, 0x10000000, 0x100000000, 0x1000000000, 0x298, 0x2980, 0x29800, 0x298000, 0x2980000, 0x29800000, 0x298000000, 0x980000053, 0x180000047c, 0x4414, 0x44140, 0x441400, 0x4414000, 0x44140000, 0x441400000, 0x4140000a6, 0x140000ac6, 0x140000ac60, 0xac43e, 0xac43e0, 0xac43e00, 0xac43e000, 0xac43e0000, 0xc43e0011f, 0x43e00101a, 0x3e0010106, 0x1e00101033});
constexpr StatTable37 SQR4_TABLE_37({0x1, 0x10000, 0x100000000, 0x29800, 0x298000000, 0x44140, 0x441400000, 0xac43e, 0xac43e0000, 0x1e00101033, 0x1010011000, 0x11029a980, 0x9a982b1d3, 0x2b1c45014, 0x4501005f2, 0x1005f8ef80, 0x18efa98941, 0x9897de117, 0x1de10002ad, 0x2990398, 0x190398047c, 0x180443dee4, 0x3ded94ac6, 0x194ac071fa, 0x71c56e1a, 0x56e1adff2, 0x1adffa1690, 0x1a16a9ab31, 0x9ab0957cf, 0x957d85468, 0x18547edba2, 0x1edb9fc515, 0x1fc526c1a4, 0x6c1956aab, 0x156aa5b9d4, 0x5b9f59def, 0x159de6d961});
constexpr StatTable37 SQR8_TABLE_37({0x1, 0x18efa98941, 0x1fc526c1a4, 0x11352e16c4, 0xba7aa5340, 0x17346e075f, 0xe91c746aa, 0xe560ac1bd, 0xa4544c5d9, 0x11bd3c631f, 0xd70c4b63c, 0xfe77d107c, 0x10548e5288, 0x1183954fb3, 0x19b3aa4bb, 0x782a2943c, 0x1c19ba61de, 0x6ad01fe38, 0xa22701577, 0xb96546ca0, 0x1d7c6c8b9c, 0xffef807e2, 0x16fcc14dc2, 0x110cc4e83c, 0xc3a35629a, 0x1062330476, 0xb2e5d1de1, 0x1ca4e3d229, 0x67826b51b, 0xe7e4c36e7, 0x59f1ac963, 0x12777f22c6, 0x13963d623a, 0x9e305ac92, 0x219b91d13, 0x175bebeb0d, 0xc6b7b5572});
constexpr StatTable37 SQR16_TABLE_37({0x1, 0xcb88f2f8b, 0x1a2a0be7af, 0xb93048ada, 0x113ed92190, 0xc95a18e2b, 0x1e1cd4a85b, 0x19584a1a66, 0x1b947c28c2, 0x1b52b48e27, 0xe64e7b169, 0x14a256d011, 0xda657196d, 0x1947c1dcb4, 0x18b2fa3851, 0xae3d4171a, 0x658f1f4b9, 0x91852c314, 0x69346cf8e, 0x8224bf36c, 0x1086c810ed, 0x10419bc782, 0x57d6a4e36, 0xfbb31a43e, 0x18b502de05, 0x786795174, 0x1de0f1b7f3, 0x1d456b87dc, 0x1aabb2f3bc, 0xc5b80ef0c, 0x1ce4fd7543, 0x7ca740ca1, 0x29eaec26a, 0x1eb0b42043, 0xca3b2b17, 0x3453101c1, 0x1714c59187});
constexpr StatTable37 QRT_TABLE_37({0xa3c62e7ba, 0xdc7a0c16a, 0xdc7a0c168, 0x12f7484546, 0xdc7a0c16c, 0xa9803a20, 0x12f748454e, 0xda07064a4, 0xdc7a0c17c, 0x123908de8e, 0xa9803a00, 0x122a888a8e, 0x12f748450e, 0x6790add8, 0xda0706424, 0x12e0a0384c, 0xdc7a0c07c, 0xcb28a2c2, 0x123908dc8e, 0xd09f85e86, 0xa9803e00, 0x124d682b6e, 0x122a88828e, 0x1738711a, 0x12f748550e, 0x73035b8, 0x67908dd8, 0xa0702438, 0xda0702424, 0xe0a0b860, 0x12e0a0b84c, 0x1c7a1c060, 0xdc7a1c07c, 0, 0xcb2aa2c2, 0x100000002c, 0x12390cdc8e});
typedef Field<uint64_t, 37, 83, StatTable37, &SQR_TABLE_37, &SQR2_TABLE_37, &SQR4_TABLE_37, &SQR8_TABLE_37, &SQR16_TABLE_37, &QRT_TABLE_37, IdTrans, &ID_TRANS, &ID_TRANS> Field37;
#endif

#ifdef ENABLE_FIELD_INT_38
// 38 bit field
typedef RecLinTrans<uint64_t, 6, 6, 6, 5, 5, 5, 5> StatTable38;
constexpr StatTable38 SQR_TABLE_38({0x1, 0x4, 0x10, 0x40, 0x100, 0x400, 0x1000, 0x4000, 0x10000, 0x40000, 0x100000, 0x400000, 0x1000000, 0x4000000, 0x10000000, 0x40000000, 0x100000000, 0x400000000, 0x1000000000, 0x63, 0x18c, 0x630, 0x18c0, 0x6300, 0x18c00, 0x63000, 0x18c000, 0x630000, 0x18c0000, 0x6300000, 0x18c00000, 0x63000000, 0x18c000000, 0x630000000, 0x18c0000000, 0x2300000063, 0xc0000014a, 0x3000000528});
constexpr StatTable38 SQR2_TABLE_38({0x1, 0x10, 0x100, 0x1000, 0x10000, 0x100000, 0x1000000, 0x10000000, 0x100000000, 0x1000000000, 0x18c, 0x18c0, 0x18c00, 0x18c000, 0x18c0000, 0x18c00000, 0x18c000000, 0x18c0000000, 0xc0000014a, 0x1405, 0x14050, 0x140500, 0x1405000, 0x14050000, 0x140500000, 0x1405000000, 0x500001ef, 0x500001ef0, 0x100001ef63, 0x1ef7bc, 0x1ef7bc0, 0x1ef7bc00, 0x1ef7bc000, 0x1ef7bc0000, 0x2f7bc00129, 0x37bc00112d, 0x3bc0011027, 0x3c00110022});
constexpr StatTable38 SQR4_TABLE_38({0x1, 0x10000, 0x100000000, 0x18c00, 0x18c000000, 0x14050, 0x140500000, 0x100001ef63, 0x1ef7bc000, 0x3bc0011027, 0x110001100, 0x110194c0, 0x194c0194c, 0x194d5455, 0xd5455154f, 0x151544a193, 0x4a18c631f, 0xc6319c6ca, 0x19c6c00014, 0x18c8d, 0x18c8d0000, 0xd00014096, 0x1409ddc00, 0x1ddc01efc6, 0x1efd5ab90, 0x15ab9110e1, 0x1110fe85b2, 0x3e85ab5465, 0x2b5445c97a, 0x5c9450993, 0x50994148f, 0x141488b12a, 0x8b134ee36, 0x34ee3a8ecc, 0x3a8ee3edc8, 0x23edeef7ed, 0x2ef7de8bf9, 0x1e8bc14041});
constexpr StatTable38 SQR8_TABLE_38({0x1, 0x4a18c631f, 0x8b134ee36, 0x10b5c9474c, 0x3330e98ecb, 0x939897650, 0xd74b026b9, 0x860251dd9, 0x3afbe829b4, 0x3ae6afc308, 0x239ecafe00, 0x2acbc94749, 0x3a5770e19e, 0x4052e180b, 0x321fa15712, 0x3a8a4869ef, 0x1948598082, 0x3b1bd98542, 0xc1deb9112, 0x1b5c9242e, 0x338ba58e8b, 0x8abe06d20, 0x145bb1d2a9, 0x1d6e10fbf0, 0x197d522629, 0x2ff1bbe50d, 0xcc1594a16, 0xc94db1b03, 0x3b20e51c56, 0x101d1e5d07, 0x19472478f7, 0x269635a968, 0x2fd4a35802, 0x1b63e116b6, 0x19fdf9d22a, 0x2ef0e4d419, 0x3e80f730f4, 0x29869b04b9});
constexpr StatTable38 SQR16_TABLE_38({0x1, 0x3f5fe2afaa, 0x4216541b5, 0x33b362f56a, 0x9d630d7e1, 0x11127694c1, 0x3f8daab2d6, 0x153ca20edc, 0x22a747a3de, 0xc6ab16040, 0x19cc9a7e37, 0x449d96001, 0x45a7e7c46, 0x36d11561ce, 0x114b93f52a, 0x42a87f1b3, 0x23112a30bc, 0x400df9212, 0x3aca9544df, 0x140c4b0bcf, 0x2ae2efa6d3, 0x2f7051159c, 0x19cca2f62e, 0x102023d8c0, 0xccc793f0b, 0x2ff4789b55, 0x339e4cd9ba, 0x2b02ab5052, 0x8c1b5db82, 0x2e461e4e32, 0xd93541605, 0x1acf12087, 0x33b88dca2b, 0x1e91723c8b, 0xd81047b2b, 0x2e5e54b97c, 0x85bb507d8, 0x2145b1864b});
constexpr StatTable38 QRT_TABLE_38({0x34b0ac6430, 0x2223262fa, 0x2223262f8, 0x35554405fe, 0x2223262fc, 0x355514098a, 0x35554405f6, 0x400840, 0x2223262ec, 0x1777726532, 0x35551409aa, 0x15c06fc0, 0x35554405b6, 0x1f5303fec, 0x4008c0, 0x236a21030, 0x2223263ec, 0x1a9008c00, 0x1777726732, 0x3692c60ab6, 0x3555140daa, 0x15556007ee, 0x15c067c0, 0x14a0b030f2, 0x35554415b6, 0x227c06d168, 0x1f5301fec, 0x16c3928fc2, 0x4048c0, 0x3a942c4c0, 0x236a29030, 0x1636a2902e, 0x2223363ec, 0x3a6e898276, 0x1a9028c00, 0x6de74eb2c, 0x1777766732, 0});
typedef Field<uint64_t, 38, 99, StatTable38, &SQR_TABLE_38, &SQR2_TABLE_38, &SQR4_TABLE_38, &SQR8_TABLE_38, &SQR16_TABLE_38, &QRT_TABLE_38, IdTrans, &ID_TRANS, &ID_TRANS> Field38;
#endif

#ifdef ENABLE_FIELD_INT_39
// 39 bit field
typedef RecLinTrans<uint64_t, 6, 6, 6, 6, 5, 5, 5> StatTable39;
constexpr StatTable39 SQR_TABLE_39({0x1, 0x4, 0x10, 0x40, 0x100, 0x400, 0x1000, 0x4000, 0x10000, 0x40000, 0x100000, 0x400000, 0x1000000, 0x4000000, 0x10000000, 0x40000000, 0x100000000, 0x400000000, 0x1000000000, 0x4000000000, 0x22, 0x88, 0x220, 0x880, 0x2200, 0x8800, 0x22000, 0x88000, 0x220000, 0x880000, 0x2200000, 0x8800000, 0x22000000, 0x88000000, 0x220000000, 0x880000000, 0x2200000000, 0x800000011, 0x2000000044});
constexpr StatTable39 SQR2_TABLE_39({0x1, 0x10, 0x100, 0x1000, 0x10000, 0x100000, 0x1000000, 0x10000000, 0x100000000, 0x1000000000, 0x22, 0x220, 0x2200, 0x22000, 0x220000, 0x2200000, 0x22000000, 0x220000000, 0x2200000000, 0x2000000044, 0x404, 0x4040, 0x40400, 0x404000, 0x4040000, 0x40400000, 0x404000000, 0x4040000000, 0x400000088, 0x4000000880, 0x8888, 0x88880, 0x888800, 0x8888000, 0x88880000, 0x888800000, 0x888000011, 0x880000101, 0x800001001});
constexpr StatTable39 SQR4_TABLE_39({0x1, 0x10000, 0x100000000, 0x2200, 0x22000000, 0x404, 0x4040000, 0x400000088, 0x888800, 0x888000011, 0x100010, 0x1000100000, 0x1000022000, 0x220022000, 0x220004040, 0x40404040, 0x4040400880, 0x4008888880, 0x888888101, 0x881000001, 0x122, 0x1220000, 0x2200000022, 0x260400, 0x2604000000, 0x48c88, 0x48c880000, 0x800009889, 0x98881000, 0x810001221, 0x12201220, 0x2012200264, 0x2002604264, 0x6042604044, 0x604048c8c4, 0x48c8c8c880, 0x48c8898881, 0x988888881, 0x888802201});
constexpr StatTable39 SQR8_TABLE_39({0x1, 0x4040400880, 0x2002604264, 0xaa8022011, 0x810049ea9, 0x100100010, 0xc04008101, 0x644048ea4c, 0x18c1764441, 0x60f8e8526c, 0x22000122, 0x48c88989a3, 0xae0032001, 0x2a7aeafae5, 0x6a76641225, 0x2036245242, 0x3e9ab0308b, 0x1c49f6fe41, 0x681b069e2d, 0x4edee8cae5, 0x898c04, 0x660daa8880, 0x69cae9ccc1, 0x4881320991, 0xd06280001, 0x1cc8c8e3d9, 0x445fc65628, 0x4c889a8a49, 0x300b8caeec, 0x50d842fc94, 0x1811acb89d, 0x9d22101c, 0x2025aa407e, 0x20370a744a, 0x3cf77cb80b, 0x54a13e66e7, 0x34c17e2e04, 0x5c19fe54c1, 0x6a72cc767d});
constexpr StatTable39 SQR16_TABLE_39({0x1, 0x37214861ce, 0x689e897065, 0x5678d6ee60, 0x619da834c4, 0x28352752d3, 0x14fed69ec6, 0x5b3d4aa637, 0x682fb8da4d, 0x2ce48c5615, 0x1591ac539c, 0x72d4fbcd0, 0x346b547296, 0x1e7065d419, 0x4e6eb48571, 0x26615d4c2c, 0x60d1c6122e, 0x78d0e2a2eb, 0x52bb3e2980, 0x3c2592d0ab, 0x701ba76b58, 0x5fdf53b685, 0x57cfd2d120, 0x75559e4344, 0x3837a46907, 0x15f961a4ce, 0x397b9a03e9, 0x5a8dd4ab69, 0x3a6ab3356f, 0x215d39c25e, 0x5bbaf82443, 0x6759e3c88c, 0x3c0b862ca1, 0x37eec7e79e, 0x6ce865e38, 0x4a56a338c0, 0x5684636aee, 0x325a019126, 0x24f18a4ef6});
constexpr StatTable39 QRT_TABLE_39({0x66b02a408c, 0x100420, 0x100422, 0x14206080, 0x100426, 0x5dccefab1c, 0x14206088, 0x9fc11e5b6, 0x100436, 0x5466bea62a, 0x5dccefab3c, 0x9aa110536, 0x142060c8, 0x54739ed6e2, 0x9fc11e536, 0xe7a82c080, 0x100536, 0x4002000, 0x5466bea42a, 0x6a4022000, 0x5dccefaf3c, 0x9e8118536, 0x9aa110d36, 0x5680e080, 0x142070c8, 0x7d293c5b6, 0x54739ef6e2, 0x8d680e080, 0x9fc11a536, 0x6d282c080, 0xe7a824080, 0x800000000, 0x110536, 0x2d680e080, 0x4022000, 0, 0x5466baa42a, 0x46b03a44aa, 0x6a40a2000});
typedef Field<uint64_t, 39, 17, StatTable39, &SQR_TABLE_39, &SQR2_TABLE_39, &SQR4_TABLE_39, &SQR8_TABLE_39, &SQR16_TABLE_39, &QRT_TABLE_39, IdTrans, &ID_TRANS, &ID_TRANS> Field39;
typedef FieldTri<uint64_t, 39, 4, RecLinTrans<uint64_t, 6, 6, 6, 6, 5, 5, 5>, &SQR_TABLE_39, &SQR2_TABLE_39, &SQR4_TABLE_39, &SQR8_TABLE_39, &SQR16_TABLE_39, &QRT_TABLE_39, IdTrans, &ID_TRANS, &ID_TRANS> FieldTri39;
#endif

#ifdef ENABLE_FIELD_INT_40
// 40 bit field
typedef RecLinTrans<uint64_t, 6, 6, 6, 6, 6, 5, 5> StatTable40;
constexpr StatTable40 SQR_TABLE_40({0x1, 0x4, 0x10, 0x40, 0x100, 0x400, 0x1000, 0x4000, 0x10000, 0x40000, 0x100000, 0x400000, 0x1000000, 0x4000000, 0x10000000, 0x40000000, 0x100000000, 0x400000000, 0x1000000000, 0x4000000000, 0x39, 0xe4, 0x390, 0xe40, 0x3900, 0xe400, 0x39000, 0xe4000, 0x390000, 0xe40000, 0x3900000, 0xe400000, 0x39000000, 0xe4000000, 0x390000000, 0xe40000000, 0x3900000000, 0xe400000000, 0x900000004b, 0x400000015e});
constexpr StatTable40 SQR2_TABLE_40({0x1, 0x10, 0x100, 0x1000, 0x10000, 0x100000, 0x1000000, 0x10000000, 0x100000000, 0x1000000000, 0x39, 0x390, 0x3900, 0x39000, 0x390000, 0x3900000, 0x39000000, 0x390000000, 0x3900000000, 0x900000004b, 0x541, 0x5410, 0x54100, 0x541000, 0x5410000, 0x54100000, 0x541000000, 0x5410000000, 0x41000000dd, 0x1000000d34, 0xd379, 0xd3790, 0xd37900, 0xd379000, 0xd3790000, 0xd37900000, 0xd379000000, 0x3790000115, 0x790000111b, 0x900001111f});
constexpr StatTable40 SQR4_TABLE_40({0x1, 0x10000, 0x100000000, 0x3900, 0x39000000, 0x541, 0x5410000, 0x41000000dd, 0xd37900, 0xd379000000, 0x111001, 0x1110010000, 0x10003aa90, 0x3aa903900, 0x903900511a, 0x51051541, 0x515410de9, 0x410de9de4d, 0xe9de437815, 0x437801010e, 0x101000038, 0x383939, 0x3839390000, 0x3900057d41, 0x57d444100, 0x444100d6e5, 0xd6ebaa79, 0xebaa7911c6, 0x7911d2791a, 0xd2791102a9, 0x1102b82901, 0xb82902a972, 0x2a96bfed1, 0x6bfed16851, 0xd16859f42e, 0x59f43f61a8, 0x3f61a43794, 0xa43791de59, 0x91de42401f, 0x424000390e});
constexpr StatTable40 SQR8_TABLE_40({0x1, 0x515410de9, 0x2a96bfed1, 0x13ba41ea90, 0x45bffe2b75, 0x5836900, 0x3887d7e690, 0xd34b688712, 0xc7a3d51557, 0xd1151ada71, 0x51442a740, 0x41cc5cbdb6, 0xc61a5701e9, 0x8757946d91, 0xa99e8b9e65, 0x80a0aca777, 0xc242b5c0e9, 0x6826eccb25, 0xad687ebd2d, 0xad5c69d802, 0x7ed2f8390, 0x51fa78eedf, 0xc0718c96f6, 0xaf4672a8c2, 0xc67436f2fd, 0x56ddb12767, 0x535afb0326, 0xbce1edda33, 0xef36202f0f, 0x45d13015ec, 0x104ab11aef, 0xef96c86d49, 0xc1b790bfc9, 0x2fa610e77f, 0x2a10a27d6e, 0xca5bb10773, 0xfdaf2b4642, 0xb3b4b7e20d, 0xe8bbe4d22e, 0xf9986bd2df});
constexpr StatTable40 SQR16_TABLE_40({0x1, 0xe88450a7de, 0x3a0a56c3e8, 0x1684757d36, 0xc7f40bf3e9, 0x38aa7009c0, 0x2b6f129659, 0xd1e0fc42e5, 0x96150bc554, 0x9774ef4cc1, 0xd34eebf74d, 0x2d183441ec, 0xeedf6d1c78, 0x3f93c5d217, 0xb924305809, 0xc383bb7c14, 0x3f242bb94e, 0x9313556f6b, 0x2f5e1ecc6b, 0x2e7f9df195, 0xac8b882870, 0xd14f457f55, 0xf9f936148d, 0x719190770, 0x6838b41a21, 0xb95ff30106, 0xc1527dd1c5, 0xe858b5f9b6, 0x9368a791c2, 0x7de23878af, 0x95c610d398, 0xed0edcb032, 0x9548a680b0, 0xc133469e7b, 0x68c96ccbb2, 0x7773231ebb, 0xbd5ef4207c, 0xdf8bd59374, 0xb862414268, 0xfa62b39e42});
constexpr StatTable40 QRT_TABLE_40({0x624b3cecc, 0xbc5c3f4c6, 0xbc5c3f4c4, 0xde1603e2c, 0xbc5c3f4c0, 0xaabec06cea, 0xde1603e24, 0x6cd9f724c2, 0xbc5c3f4d0, 0xcde1743818, 0xaabec06cca, 0xa138c314ca, 0xde1603e64, 0xaafc00f01a, 0x6cd9f72442, 0xcdca11bb4, 0xbc5c3f5d0, 0xa00002001a, 0xcde1743a18, 0xdf1407b90, 0xaabec068ca, 0xc043b482c8, 0xa138c31cca, 0xcb86977e3c, 0xde1602e64, 0x604596a326, 0xaafc00d01a, 0xcc1c165d0, 0x6cd9f76442, 0x673c94da26, 0xcdca19bb4, 0x67c0940a26, 0xbc5c2f5d0, 0xa4dca19bae, 0xa00000001a, 0x1bc5c2f5d0, 0xcde1703a18, 0, 0xdf1487b90, 0x8df1487b8a});
typedef Field<uint64_t, 40, 57, StatTable40, &SQR_TABLE_40, &SQR2_TABLE_40, &SQR4_TABLE_40, &SQR8_TABLE_40, &SQR16_TABLE_40, &QRT_TABLE_40, IdTrans, &ID_TRANS, &ID_TRANS> Field40;
#endif
}

Sketch* ConstructClMul5Bytes(int bits, int implementation) {
    switch (bits) {
#ifdef ENABLE_FIELD_INT_33
    case 33: return new SketchImpl<Field33>(implementation, 33);
#endif
#ifdef ENABLE_FIELD_INT_34
    case 34: return new SketchImpl<Field34>(implementation, 34);
#endif
#ifdef ENABLE_FIELD_INT_35
    case 35: return new SketchImpl<Field35>(implementation, 35);
#endif
#ifdef ENABLE_FIELD_INT_36
    case 36: return new SketchImpl<Field36>(implementation, 36);
#endif
#ifdef ENABLE_FIELD_INT_37
    case 37: return new SketchImpl<Field37>(implementation, 37);
#endif
#ifdef ENABLE_FIELD_INT_38
    case 38: return new SketchImpl<Field38>(implementation, 38);
#endif
#ifdef ENABLE_FIELD_INT_39
    case 39: return new SketchImpl<Field39>(implementation, 39);
#endif
#ifdef ENABLE_FIELD_INT_40
    case 40: return new SketchImpl<Field40>(implementation, 40);
#endif
    }
    return nullptr;
}

Sketch* ConstructClMulTri5Bytes(int bits, int implementation) {
    switch (bits) {
#ifdef ENABLE_FIELD_INT_33
    case 33: return new SketchImpl<FieldTri33>(implementation, 33);
#endif
#ifdef ENABLE_FIELD_INT_34
    case 34: return new SketchImpl<FieldTri34>(implementation, 34);
#endif
#ifdef ENABLE_FIELD_INT_35
    case 35: return new SketchImpl<FieldTri35>(implementation, 35);
#endif
#ifdef ENABLE_FIELD_INT_36
    case 36: return new SketchImpl<FieldTri36>(implementation, 36);
#endif
#ifdef ENABLE_FIELD_INT_39
    case 39: return new SketchImpl<FieldTri39>(implementation, 39);
#endif
    }
    return nullptr;
}
