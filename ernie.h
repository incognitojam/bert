typedef struct __attribute__((packed)) s_ernie_cmd {
    uint16_t id;
    uint8_t unk;
    uint16_t data_size;
    uint8_t data[64 - 5]; // last 2 bytes are the checksum
} s_ernie_cmd;

enum ERNIE_COMMANDS {
    ERNIE_CMD_UNK_x100 = 0x100,
    ERNIE_CMD_GET_INFO,
    ERNIE_CMD_UNK_x102,
    ERNIE_CMD_x103_UNLOCK_T1,
    ERNIE_CMD_x104_LOCK_T1,
    ERNIE_CMD_UNK_x105,
    ERNIE_CMD_GET_UNK_x106,
    ERNIE_CMD_GET_UNK_DATE,
    ERNIE_CMD_UNK_x108,
    ERNIE_CMD_UNK_x109,
    ERNIE_CMD_SET_KEYXCG = 0x110,
    ERNIE_CMD_UNK_x120,
    ERNIE_CMD_UNK_x121,
    ERNIE_CMD_GET_UNK_x140,
    ERNIE_CMD_UNK_x141,
    ERNIE_CMD_UNK_x142,
    ERNIE_CMD_UNK_x143,
    ERNIE_CMD_UNK_x144,
    ERNIE_CMD_UNK_x145,
    ERNIE_CMD_UNK_x146,
    ERNIE_CMD_UNK_x147,
    ERNIE_CMD_GET_UNK_x150,
    ERNIE_CMD_UNK_x151,
    ERNIE_CMD_UNK_x152,
    ERNIE_CMD_UNK_x153,
    ERNIE_CMD_UNK_x154,
    ERNIE_CMD_UNK_x155,
    ERNIE_CMD_UNK_x156,
    ERNIE_CMD_UNK_x157,
    ERNIE_CMD_UNK_x160,
    ERNIE_CMD_UNK_x161,
    ERNIE_CMD_UNK_x162,
    ERNIE_CMD_UNK_x163,
    ERNIE_CMD_UNK_x170,
    ERNIE_CMD_UNK_x171,
    ERNIE_CMD_UNK_x172,
    ERNIE_CMD_GET_UNK_x180,
    ERNIE_CMD_UNK_x181,
    ERNIE_CMD_UNK_x182,
    ERNIE_CMD_UNK_x183,
    ERNIE_CMD_UNK_x184,
    ERNIE_CMD_UNK_x185,
    ERNIE_CMD_UNK_x186,
    ERNIE_CMD_UNK_x187,
    ERNIE_CMD_UNK_x188,
    ERNIE_CMD_UNK_x189,
    ERNIE_CMD_UNK_x18A,
    ERNIE_CMD_UNK_x18B,
    ERNIE_CMD_UNK_x18C,
    ERNIE_CMD_UNK_x18D,
    ERNIE_CMD_UNK_x18E,
    ERNIE_CMD_UNK_x190,
    ERNIE_CMD_UNK_x1A0,
    ERNIE_CMD_UNK_x1A1,
    ERNIE_CMD_GET_UNK_x1B0,
    ERNIE_CMD_GET_UNK_x1C0,
    ERNIE_CMD_UNK_x1C1,
    ERNIE_CMD_UNK_x1C2,
    ERNIE_CMD_UNK_x1C3,
    ERNIE_CMD_UNK_x1C4,
    ERNIE_CMD_UNK_x1D0,
    ERNIE_CMD_UNK_x1D1,
    ERNIE_CMD_UNK_x1D2
};

enum ERNIE_ERRORS {
    ERR_NO_ERR = 0, // command accepted/success
    ERR_UNKNOWN_CMD, // unknown, probably nonexisting command
    ERR_BAD_LENGTH,
    ERR_BAD_CHKSUM,
    ERR_NO_CRLF, // unsure, only trigger was no CRLF
    ERR_BAD_FORMAT, // unsure, only trigger was non-hex [0-9 | A-F] chars
    ERR_BLOCKED_T2 = 0x10, // blocked by command x 110
    ERR_UNKNOWN_x11, // unknown
    ERR_BLOCKED_T1 = 0x20, // blocked by command pair x 103/104
    ERR_BAD_PARAMS = 0x32, // unknown, probably bad params
    ERR_UNKNOWN_x33, // unknown
    ERR_UNKNOWN_x40 = 0x40, // unknown
    ERR_UNKNOWN_x92 = 0x92, // unknown
    ERR_UNKNOWN_x95 = 0x95, // unknown
    ERR_UNKNOWN_xD0 = 0xD0, // unknown
    ERR_UNKNOWN_xD2 = 0xD2, // unknown
    ERR_UNKNOWN_xD8 = 0xD8, // unknown
    ERR_UNKNOWN_xFF = 0xFF, // unknown
};

/* existing CMDs returns with size 0:
0x100 - 0x00
0x101 - 0x00 payload some syscon/console info
0x102 - 0x32
0x103 - 0x00 [UNBLOCKS 0x110,0x120-0x121,0x141-0x147,0x150-0x157,0x160-0x163,0x170-0x172,0x180-0x18E,0x190,0x1A0-0x1A1,0x1B0,0x1C0-0x1C4,0x1D0-0x1D2]
0x104 - 0x00 [BLOCKS 0x110,0x120-0x121,0x141-0x147,0x150-0x157,0x160-0x163,0x170-0x172,0x180-0x18E,0x190,0x1A0-0x1A1,0x1B0,0x1C0-0x1C4,0x1D0-0x1D2]
0x105 - 0x33
0x106 - 0x00 payload 0400 (0x4)
0x107 - 0x00 payload some date string in hex, ex. 201312131552
0x108 - 0x33
0x109 - 0x33
0x110 - 0x00 3-step keyxchange, payload size 40 [UNBLOCKS 0x141-0x147,0x152-0x156]
0x120 - 0x40
0x121 - 0x40
0x140 - 0x00 payload 5800050058000400
0x141 - 0xD8
0x142 - 0xD0
0x143 - 0x00
0x144 - 0x00
0x145 - 0xD0
0x146 - 0xD0
0x147 - 0xD2
0x150 - 0x00 payload 090001AA00000000
0x151 - 0x95
0x152 - 0x00
0x152 - 0x00
0x153 - 0x92
0x154 - 0x92
0x155 - 0x92
0x156 - 0x00
0x157 - 0x95
0x160 - 0x33
0x161 - 0x00 [AUTH RESET??]

0x160-0x163 - 0x10
0x170-0x171 - 0x10
0x172 - 0x11
0x180 - 0x00 payload 8D07C50F07010B015800000012FD
0x181-0x18E - 0x10
0x190 - 0x10
0x1A0-0x1A1 - 0x40
0x1B0 - 0x00 payload 0000000000000000 (SUS)
0x1C0 - 0x00 payload 01AA00000
0x1C1 - 0xFF
0x1C2-0x1C3 - 0x00
0x1C4 - 0x33
0x1D0-0x1D1 - 0x10
0x1D2 - 0x00 payload 0000000000010000
0x900-0x901 - 0x10
0x910-0x917 - 0xFF
0x930-0x932 - 0xFF
0x940-0x945 - 0xFF
0x952-0x953 - 0xFF
0x961-0x965 - 0xFF
*/
