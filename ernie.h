typedef struct __attribute__((packed)) s_ernie_cmd {
    uint16_t id;
    uint8_t unk;
    uint16_t data_size;
    uint8_t data[64 - 5]; // last 2 bytes are the checksum
} s_ernie_cmd;

enum ERNIE_COMMANDS {
    ERNIE_CMD_UNK_x100 = 0x100,
    ERNIE_CMD_GET_INFO,
    ERNIE_CMD_UNLOCK_T1 = 0x103,
    ERNIE_CMD_LOCK_T1 = 0x104,
    ERNIE_CMD_GET_UNK_DATE = 0x107,
    ERNIE_CMD_UNLOCK_T8 = 0x110,
    ERNIE_CMD_UNLOCK_T4 = 0x900,
    ERNIE_CMD_LOCK_T4 = 0x901,
};

enum ERNIE_ERRORS {
    ERR_NO_ERR = 0, // command accepted/success
    ERR_UNKNOWN_CMD, // unknown, probably nonexisting command
    ERR_BAD_LENGTH,
    ERR_BAD_CHKSUM,
    ERR_NO_CRLF, // unsure, only trigger was no CRLF
    ERR_BAD_FORMAT, // unsure, only trigger was non-hex [0-9 | A-F] chars
    ERR_BLOCKED_T8 = 0x10, // blocked by command x 110
    ERR_BLOCKED_T8_2, // unknown, blocked by command x 110 ?
    ERR_BLOCKED_T1 = 0x20, // blocked by command pair x 103/104
    ERR_BAD_PARAMS = 0x32, // unknown, probably bad params
    ERR_UNKNOWN_x33, // unknown
    ERR_UNKNOWN_x40 = 0x40, // unknown
    ERR_UNKNOWN_x60 = 0x60, // unknown BUT gives payload (??)
    ERR_UNKNOWN_x92 = 0x92, // unknown
    ERR_UNKNOWN_x95 = 0x95, // unknown
    ERR_UNKNOWN_xA3 = 0xA3, // unknown
    ERR_UNKNOWN_xD0 = 0xD0, // unknown
    ERR_UNKNOWN_xD2 = 0xD2, // unknown
    ERR_UNKNOWN_xD8 = 0xD8, // unknown
    ERR_BLOCKED_T4 = 0xFF, // blocked by command pair x 900/901
};

/* existing CMDs returns with size 0:
0x100 - 0x00
0x101 - 0x00 payload some syscon/console info ex. 38508000110503010301750080400C0C last 4 bytes are random each boot
0x102 - 0x00 payload size 8
0x103 - 0x00 [UNLOCKS 0x20]
0x104 - 0x00 [LOCKS 0x20]
0x105 - 0x50 payload min size 4
0x106 - 0x00 payload 0400 (0x4)
0x107 - 0x00 payload some date string in hex, ex. 201312131552
0x108-0x109 - 0x33
0x110 - 0x00 3-step keyxchange, payload size 40 [UNLOCKS 0x10]
0x120-0x121 - 0x40
0x131-0x132 - 0xA3 [KEYSET 0x1]
0x140 - 0x00 payload 5800050058000400
0x141 - 0xD8
0x142 - 0xD0
0x143-0x144 - 0x00
0x145-0x146 - 0xD0
0x147 - 0xD2
0x150 - 0x00 payload 090001AA00000000
0x151 - 0x95
0x152 - 0x00
0x153-0x155 - 0x92
0x156 - 0x00
0x157 - 0x95
0x160 - 0x33
0x161 - 0x00 [AUTH RESET??]
0x162 - ?? [HARD RESET??]
0x163 - 0x33
0x170 - 0x00 payload 01420000250000001B0CFFFFF8000F00000000000018
0x171 - 0x00 payload 8000327FFFFF61EDF4
0x172 - 0x00 payload 1E050000FFFFFFFF00
0x180 - 0x00 payload 8D07C50F07010B015800000012FD
0x181 - 0x00 payload 110080015F01640000000000
0x182 - 0x00 [AUTH RESET??]
0x183-0x184 - 0x00
0x185 - 0x33
0x186 - 0x00 [CHANGED TO 0xFF NOT UNLOCKABLE]
0x187 - 0x33
0x188-0x189 - 0x00
0x18A - 0x00 payload 40000000
0x18B - 0x00 payload 01
0x18C - 0x00 payload 0C
0x18D - 0x00 payload 00
0x18E - 0x00 payload 01
0x190 - 0x00 payload 0100000000010000
0x1A0-0x1A1 - 0x40
0x1B0 - 0x00 payload 0000000000000000
0x1C0 - 0x00 payload 01AA00000
0x1C1 - 0xFF [NOT UNLOCKABLE]
0x1C2-0x1C3 - 0x00
0x1C4 - 0x33
0x1D0-0x1D1 - 0x98
0x1D2 - 0x00 payload 0000000000010000
0x300 - 0x00
0x301 - 0x00 payload 00000000000000000000000000000000000000000000000000000000000000000000000000000000
0x900 - 0x00 passwd in, [UNLOCKS 0xFX]
0x901 - 0x00 [LOCKS 0xFX]
0x910-0x915 - 0x33
0x916 - 0x00 payload 1B010600035402010100010000000000
0x917 - 0x00 payload 2D3A0543
0x930 - 0x00 payload 01C2
0x931 - 0x00 payload 8043
0x932 - 0x00 payload 2005A900160453000208A900
0x940 - 0x60 payload 05A9
0x941 - 0x60
0x942 - 0x60 payload FF24
0x943 - 0x60
0x944 - 0x00 payload 9801
0x945 - 0x60
0x952 - 0x00 [AUTH RESET??]
0x953 - 0x00 payload 1C000000870B830B
0x961 - 0x00 payload 8080808080808080
0x962 - 0x00 payload 0080008000800080
0x963 - 0x00 payload 00000000000000000000000000000000
0x964 - 0x00 payload 0080008000800000008000800080000000800080008000000080008000800000
0x965 - 0x00 payload 0000C0FF0000C0FF0000C0FF0000C0FF
*/
