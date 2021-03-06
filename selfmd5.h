#include <stddef.h>
#include <elf.h>

#define ADDR_TEXT 0x00400000

typedef struct elf
{
  Elf64_Ehdr      ehdr;
  Elf64_Phdr      phdrs[1];
  unsigned char   text[368];
} elf;

elf foo =
{
  /* ehdr */
  {
    { 0x7F, 'E', 'L', 'F', ELFCLASS64, ELFDATA2LSB, EV_CURRENT, ELFOSABI_SYSV,
      0, 0, 0, 0, 0, 0, 0, 0 },
    ET_EXEC, EM_X86_64, EV_CURRENT, ADDR_TEXT + offsetof(elf, text),
    offsetof(elf, phdrs), 0, 0, sizeof(Elf64_Ehdr), sizeof(Elf64_Phdr), 1,
    sizeof(Elf64_Shdr), 0, SHN_UNDEF
  },
  /* phdrs */
  {
    { PT_LOAD, PF_R | PF_W | PF_X, offsetof(elf, text),
      ADDR_TEXT + offsetof(elf, text), ADDR_TEXT + offsetof(elf, text),
      sizeof foo.text, sizeof foo.text, 4 }
  },
  /* text */
  {
    0x48, 0x83, 0xEC, 0x40, 0x31, 0xD2, 0xC6, 0x04, 0x25, 0xDA, 0x01, 0x40,
    0x00, 0x80, 0xC5, 0xFA, 0x6F, 0x05, 0x4A, 0x01, 0x00, 0x00, 0xC5, 0xF8,
    0x29, 0x44, 0x24, 0x20, 0xC5, 0xFA, 0x6F, 0x05, 0x2C, 0x01, 0x00, 0x00,
    0x8B, 0x7C, 0x24, 0x24, 0x44, 0x8B, 0x4C, 0x24, 0x20, 0x8B, 0x74, 0x24,
    0x28, 0x48, 0xC7, 0x04, 0x25, 0xF8, 0x01, 0x40, 0x00, 0xD0, 0x0E, 0x00,
    0x00, 0x44, 0x8B, 0x44, 0x24, 0x2C, 0xC5, 0xF8, 0x29, 0x44, 0x24, 0x30,
    0x89, 0xD0, 0x89, 0xD1, 0xC0, 0xF8, 0x04, 0x44, 0x0F, 0xBE, 0xD0, 0x3C,
    0x02, 0x74, 0x29, 0x3C, 0x03, 0x74, 0x36, 0xFE, 0xC8, 0x74, 0x0F, 0x89,
    0xF0, 0x41, 0x89, 0xD3, 0x44, 0x31, 0xC0, 0x21, 0xF8, 0x44, 0x31, 0xC0,
    0xEB, 0x34, 0x89, 0xF8, 0x44, 0x8D, 0x1C, 0x92, 0x31, 0xF0, 0x41, 0xFF,
    0xC3, 0x44, 0x21, 0xC0, 0x31, 0xF0, 0xEB, 0x1E, 0x89, 0xF8, 0x44, 0x8D,
    0x1C, 0x52, 0x31, 0xF0, 0x41, 0x83, 0xC3, 0x05, 0x44, 0x31, 0xC0, 0xEB,
    0x0D, 0x44, 0x89, 0xC0, 0x44, 0x6B, 0xDA, 0x07, 0xF7, 0xD0, 0x09, 0xF8,
    0x31, 0xF0, 0x41, 0x83, 0xE3, 0x0F, 0xFF, 0xC2, 0x89, 0x54, 0x24, 0x08,
    0xDB, 0x44, 0x24, 0x08, 0xD9, 0xFE, 0xD9, 0xE1, 0xD8, 0x0D, 0x96, 0x00,
    0x00, 0x00, 0x83, 0xE1, 0x03, 0x42, 0x8D, 0x0C, 0x91, 0x0F, 0xBE, 0x4C,
    0x0C, 0x30, 0xDD, 0x4C, 0x24, 0x08, 0x48, 0x8B, 0x5C, 0x24, 0x08, 0x01,
    0xD8, 0x42, 0x03, 0x04, 0x9D, 0xC0, 0x01, 0x40, 0x00, 0x44, 0x01, 0xC8,
    0x45, 0x89, 0xC1, 0xD3, 0xC0, 0x01, 0xF8, 0x83, 0xFA, 0x40, 0x74, 0x0C,
    0x41, 0x89, 0xF0, 0x89, 0xFE, 0x89, 0xC7, 0xE9, 0x58, 0xFF, 0xFF, 0xFF,
    0x44, 0x01, 0x44, 0x24, 0x20, 0x31, 0xDB, 0x01, 0x44, 0x24, 0x24, 0x01,
    0x7C, 0x24, 0x28, 0x01, 0x74, 0x24, 0x2C, 0x89, 0xD8, 0x89, 0xDA, 0xD0,
    0xE8, 0x83, 0xE2, 0x01, 0x80, 0xFA, 0x01, 0x0F, 0xB6, 0xC0, 0x19, 0xC9,
    0x0F, 0xB6, 0x44, 0x04, 0x20, 0x83, 0xE1, 0x04, 0xD3, 0xF8, 0x83, 0xE0,
    0x0F, 0x8D, 0x50, 0x30, 0x3C, 0x09, 0x7E, 0x03, 0x8D, 0x50, 0x57, 0x88,
    0x54, 0x24, 0x1F, 0x48, 0x8D, 0x74, 0x24, 0x1F, 0xB2, 0x01, 0xFF, 0xC3,
    0xBF, 0x01, 0x00, 0x00, 0x00, 0xB0, 0x01, 0x0F, 0x05, 0x80, 0xFB, 0x20,
    0x75, 0xBD, 0x31, 0xFF, 0xB0, 0x3C, 0x0F, 0x05, 0x00, 0x00, 0x80, 0x4F,
    0x07, 0x0C, 0x11, 0x16, 0x05, 0x09, 0x0E, 0x14, 0x04, 0x0B, 0x10, 0x17,
    0x06, 0x0A, 0x0F, 0x15, 0x30, 0xC8, 0x85, 0x5C, 0x43, 0x5D, 0x4A, 0x52,
    0x12, 0x7F, 0x79, 0x11, 0x99, 0xB0, 0xB0, 0xD2
  }
};
