// ---- Simple keycodes ---

// Modtaps n stuff
#define CTL_ESC     MT(MOD_LCTL, KC_ESC)
#define KC_UNDSC    LSFT(KC_MINUS)
#define SPC_MEH     MEH_T(KC_SPC)
#define SPC_NAV     LT(_NAVIGATION, KC_SPC)

// Layer Keys
#define BASE        TO(_BASE)
#define COLEMAK     TO(_COLEMAK)
#define SYMB        MO(_SYMBOLS)
#define NAVI        MO(_NAVIGATION)
#define NUMBMO      MO(_NUMBERS)
#define NUMBTO      TO(_NUMBERS)
#define FUNC        MO(_FUNCTION)
#define GAMING      TO(_GAMING)

// HomeRow Mods
#define HRM_J       MT(MOD_RSFT, KC_J)
#define HRM_K       MT(MOD_RCTL, KC_K)
#define HRM_L       MT(MOD_LALT, KC_L)
#define HRM_S       MT(MOD_LALT, KC_S)
#define HRM_D       MT(MOD_LCTL, KC_D)
#define HRM_F       MT(MOD_LSFT, KC_F)
#define HRM_Tc      MT(MOD_LSFT, KC_T)
#define HRM_Sc      MT(MOD_LCTL, KC_S)
#define HRM_Rc      MT(MOD_LALT, KC_R)
#define HRM_Nc      MT(MOD_RSFT, KC_N)
#define HRM_Ec      MT(MOD_RCTL, KC_E)
#define HRM_Ic      MT(MOD_LALT, KC_I)


#define KC_IJ