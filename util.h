#ifndef UTIL_H
#define UTIL_H
#include <QString>
typedef unsigned char byte;

void ibm2ieee(float* input, int swap);
void toibm   (long *addr, int ll);

unsigned char ebasc(unsigned char ascii);
void          ebasd(unsigned char* ascii, unsigned char* ebcd);
void          asebd(char* ebcd, char* ascii);
char          asebc(char ascii);

int setswap(int swap);

int   i4(char* buf, int nbyte);
short i2(char* buf, int nbyte);
char  i1(char* buf, int nbyte);
void f4(char *buf,int nbute);

void si4(char* buf, int nbyte,  int i);
void si2(char* buf,int nbyte, short i);
void si1(char* buf, int nbyte, char i);


int   swapi4(int   x);
short swapi2(short x);
float s4(char *buf,int nbyte);

void swapCh4(char *);
void swapCh2(char *);

int AsciiToEbcdic(int in_ebcdic_int);
int EbcdicToAscii(int in_ascii_int);
void float_to_ibm(int from[], int to[], int n, int endian);

char* qstr2char(QString str);



#endif // UTIL_H
