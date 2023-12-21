#include <Cartridge.h>

typedef struct //typedef for cartridge context, contains file name, size of the rom, the byte data for the rom, and the rom header
{
    char filename[1024];
    u32 romSize;
    u8 *romData;
    RomHeader *header;
} CartridgeContext;

static CartridgeContext context;

static const char *ROM_TYPES[] = { //map for the types of ROMs, also found from gbdev.io
    "ROM ONLY",
    "MBC1",
    "MBC1+RAM",
    "MBC1+RAM+BATTERY",
    "0x04 ???",
    "MBC2",
    "MBC2+BATTERY",
    "0x07 ???",
    "ROM+RAM 1",
    "ROM+RAM+BATTERY 1",
    "0x0A ???",
    "MMM01",
    "MMM01+RAM",
    "MMM01+RAM+BATTERY",
    "0x0E ???",
    "MBC3+TIMER+BATTERY",
    "MBC3+TIMER+RAM+BATTERY 2",
    "MBC3",
    "MBC3+RAM 2",
    "MBC3+RAM+BATTERY 2",
    "0x14 ???",
    "0x15 ???",
    "0x16 ???",
    "0x17 ???",
    "0x18 ???",
    "MBC5",
    "MBC5+RAM",
    "MBC5+RAM+BATTERY",
    "MBC5+RUMBLE",
    "MBC5+RUMBLE+RAM",
    "MBC5+RUMBLE+RAM+BATTERY",
    "0x1F ???",
    "MBC6",
    "0x21 ???",
    "MBC7+SENSOR+RUMBLE+RAM+BATTERY",
};

static const char *licenseCode[0xA5] = { //map for the license codes, from gbdev.io
    [0x00] = "None",
    [0x01] = "Nintendo R&D1",
    [0x08] = "Capcom",
    [0x13] = "Electronic Arts",
    [0x18] = "Hudson Soft",
    [0x19] = "b-ai",
    [0x20] = "kss",
    [0x22] = "pow",
    [0x24] = "PCM Complete",
    [0x25] = "san-x",
    [0x28] = "Kemco Japan",
    [0x29] = "seta",
    [0x30] = "Viacom",
    [0x31] = "Nintendo",
    [0x32] = "Bandai",
    [0x33] = "Ocean/Acclaim",
    [0x34] = "Konami",
    [0x35] = "Hector",
    [0x37] = "Taito",
    [0x38] = "Hudson",
    [0x39] = "Banpresto",
    [0x41] = "Ubi Soft",
    [0x42] = "Atlus",
    [0x44] = "Malibu",
    [0x46] = "angel",
    [0x47] = "Bullet-Proof",
    [0x49] = "irem",
    [0x50] = "Absolute",
    [0x51] = "Acclaim",
    [0x52] = "Activision",
    [0x53] = "American sammy",
    [0x54] = "Konami",
    [0x55] = "Hi tech entertainment",
    [0x56] = "LJN",
    [0x57] = "Matchbox",
    [0x58] = "Mattel",
    [0x59] = "Milton Bradley",
    [0x60] = "Titus",
    [0x61] = "Virgin",
    [0x64] = "LucasArts",
    [0x67] = "Ocean",
    [0x69] = "Electronic Arts",
    [0x70] = "Infogrames",
    [0x71] = "Interplay",
    [0x72] = "Broderbund",
    [0x73] = "sculptured",
    [0x75] = "sci",
    [0x78] = "THQ",
    [0x79] = "Accolade",
    [0x80] = "misawa",
    [0x83] = "lozc",
    [0x86] = "Tokuma Shoten Intermedia",
    [0x87] = "Tsukuda Original",
    [0x91] = "Chunsoft",
    [0x92] = "Video system",
    [0x93] = "Ocean/Acclaim",
    [0x95] = "Varie",
    [0x96] = "Yonezawa/s’pal",
    [0x97] = "Kaneko",
    [0x99] = "Pack in soft",
    [0xA4] = "Konami (Yu-Gi-Oh!)"
};

const char *CartridgeLicenseName() //looks up the license name for the ROM, returns UNKNOWN if not on list
{
    if (context.header->newLicenseCode <= 0xA4) {
        return licenseCode[context.header->licenseCode];
    }

    return "UNKNOWN";
}

const char *CartridgeTypeName() //looks up name of the cartridge, returns UNKNOWN if not on list
{
    if (context.header->type <= 0x22) {
        return ROM_TYPES[context.header->type];
    }

    return "UNKNOWN";
}

bool LoadCartridge(char *cart) 
{
    snprintf(context.filename, sizeof(context.filename), "%s", cart); //snprintf accepts n as the max number of characters, in this case it is sizeof context
    //^^ Getting name of the cartridge

    FILE *fp = fopen(cart, "r"); //opening file

    if (!fp) //file error checking
    {
        printf("Failed to open: %s\n", cart);
        return false;
    }

    printf("Opened: %s\n", context.filename);

    fseek(fp, 0, SEEK_END); //seek EOF
    context.romSize = ftell(fp); //use ftell to get position of EOF, and set that to romSize

    rewind(fp); //go back to start of file

    context.romData = malloc(context.romSize); //allocate memory for the rom data by malloc-ing the romSize
    fread(context.romData, context.romSize, 1, fp); //read in the entire file
    fclose(fp); //close the file

    context.header = (RomHeader *)(context.romData + 0x100);
    context.header->title[15] = 0; //null terminate the end of the title just in case it is not terminated already

    printf("Cartridge Loaded:\n"); //printing out the info for the rom
    printf("\t Title    : %s\n", context.header->title);
    printf("\t Type     : %2.2X (%s)\n", context.header->type, CartridgeTypeName());
    printf("\t ROM Size : %d KB\n", 32 << context.header->romSize);
    printf("\t RAM Size : %2.2X\n", context.header->ramSize);
    printf("\t LIC Code : %2.2X (%s)\n", context.header->licenseCode, CartridgeLicenseName());
    printf("\t ROM Vers : %2.2X\n", context.header->version);

    u16 x = 0; //checksum loop found on "Cartridge Header" gbdev.io
    for (u16 i=0x0134; i<=0x014C; i++) 
    {
        x = x - context.romData[i] - 1;
    }

    printf("\t Checksum : %2.2X (%s)\n", context.header->checksum, (x & 0xFF) ? "PASSED" : "FAILED");
    //if the checksum = checksum && 0xFF, it passed the verification. otherwise it failed

    return true;
}

u8 ReadCartridge(u16 address) 
{
    //Because all rom data is loaded into memory, we can access those memory arrays easily

    return context.romData[address];
}

void WriteCartridge(u16 address, u8 value) 
{

    printf("WriteCartridge(%04X)\n", address);
}

