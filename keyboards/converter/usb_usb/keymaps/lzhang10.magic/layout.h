#ifndef LAYOUT_H_
#define LAYOUT_H_

// Kinesis/Apple Magic Keyboard physical layout mapped onto the 10x16
// HID-keycode virtual matrix of the usb_usb converter (see
// CONVERTER_TAIL_ROW in config.h): rows 0-8 are the natural
// mapping (cell == HID usage byte, 0x00-0x8F) and row 9 is a
// packed tail row: Lang1, Lang2, then the eight modifier usages
// 0xE0-0xE7. Argument order matches info.json LAYOUT_all so
// keymap.c calls are unchanged.

#define LAYOUT_all(K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012, K013, K014, K015, K016, K017, K018, K019, K020, K021, K022, K023, K024, K025, K026, K027, K028, K029, K030, K031, K032, K033, K034, K035, K036, K037, K038, K039, K040, K041, K042, K043, K044, K045, K046, K047, K048, K049, K050, K051, K052, K053, K054, K055, K056, K057, K058, K059, K060, K061, K062, K063, K064, K065, K066, K067, K068, K069, K070, K071, K072, K073, K074, K075, K076, K077, K078, K079, K080, K081, K082, K083, K084, K085, K086, K087, K088, K089, K090, K091, K092, K093, K094, K095, K096, K097, K098, K099, K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K113, K114, K115, K116, K117, K118, K119, K120, K121, K122, K123, K124, K125, K126, K127, K128, K129, K130, K131, K132, K133, K134, K135, K136, K137, K138, K139, K140, K141) \
    { \
    { KC_NO  , KC_NO  , KC_NO  , KC_NO  , K081   , K106   , K104   , K083   ,  /* 0x00-0x15.000000 */ \
      K060   , K084   , K085   , K086   , K065   , K087   , K088   , K089    }, \
    { K108   , K107   , K066   , K067   , K058   , K061   , K082   , K062   ,  /* 0x10-0x31.000000 */ \
      K064   , K105   , K059   , K103   , K063   , K102   , K034   , K035    }, \
    { K036   , K037   , K038   , K039   , K040   , K041   , K042   , K043   ,  /* 0x20-0x47.000000 */ \
      K093   , K012   , K047   , K057   , K126   , K044   , K045   , K068    }, \
    { K069   , K070   , K092   , K090   , K091   , K033   , K109   , K110   ,  /* 0x30-0x63.000000 */ \
      K111   , K080   , K013   , K014   , K015   , K016   , K017   , K018    }, \
    { K019   , K020   , K021   , K022   , K023   , K024   , K025   , K026   ,  /* 0x40-0x79.000000 */ \
      K027   , K048   , K049   , K050   , K071   , K072   , K073   , K136    }, \
    { K134   , K135   , K114   , K051   , K052   , K053   , K054   , K077   ,  /* 0x50-0x95.000000 */ \
      K139   , K115   , K116   , K117   , K094   , K095   , K096   , K074    }, \
    { K075   , K076   , K137   , K138   , K101   , K132   , K031   , K118   ,  /* 0x60-0x111.000000 */ \
      K000   , K001   , K002   , K003   , K004   , K005   , K006   , K007    }, \
    { K008   , K009   , K010   , K011   , K119   , K032   , K078   , K098   ,  /* 0x70-0x127.000000 */ \
      K055   , K056   , K079   , K141   , K099   , K120   , K140   , K030    }, \
    { K029   , K028   , KC_NO  , KC_NO  , KC_NO  , K097   , KC_NO  , K112   ,  /* 0x80-0x143.000000 */ \
      K129   , K046   , K128   , K124   , KC_NO  , KC_NO  , KC_NO  , KC_NO   }, \
    { K127   , K125   , K121   , K100   , K123   , K122   , K133   , K113   ,  /* 0x90-0x159.000000 */ \
      K130   , K131   , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO   } \
    }

#endif // LAYOUT_H_
