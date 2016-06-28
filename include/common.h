#ifndef COMDEF_H
#define COMDEF_H

typedef  unsigned char      boolean;     /* Boolean value type. */
typedef  unsigned long int  uint32;      /* Unsigned 32 bit value */
typedef  unsigned short     uint16;      /* Unsigned 16 bit value */
typedef  unsigned char      uint8;       /* Unsigned 8  bit value */
typedef  signed long int    int32;       /* Signed 32 bit value */
typedef  signed short       int16;       /* Signed 16 bit value */
typedef  signed char        int8;        /* Signed 8  bit value */

typedef  unsigned char     byte;         /* Unsigned 8  bit value type. */
typedef  unsigned short    word;         /* Unsinged 16 bit value type. */
typedef  unsigned long     dword;        /* Unsigned 32 bit value type. */
typedef  unsigned char     u_char;       /* Unsigned 8  bit value type. */

#define  MEM_B(x) (*((byte *)(x)))
#define  MEM_W(x) (*((word *)(x)))

#define  ABS(value) (((value) >= 0) ? (value) : - (value))
#define  MAX(x,y) (((x)>(y)) ? (x) : (y))
#define  MIN(x,y) (((x) < (y)) ? (x) : (y))

#define FPOS(type,field) ((dword)&((type *)0)->field)
#define FSIZ(type,field) sizeof(((type *)0)->field)

#define FLIPW(ray) ((((word)(ray)[0]) * 256) + (ray)[1])
#define FLOPW(ray,val) (ray)[0] = ((val)/256); (ray)[1] = ((val) & 0xFF)

#define B_PTR(var)  ((byte *) (void *) &(var))
#define W_PTR(var)  ((word *) (void *) &(var))


#define WORD_LO(xxx)  ((byte) ((word)(xxx) & 255))
#define WORD_HI(xxx)  ((byte) ((word)(xxx) >> 8))

#define RND8(x) ((((x) + 7)/8) * 8)

#define UPCASE(c) (((c)>='a' && (c) <= 'z') ? ((c) + 20) : (c))

#define DECCHK(c) ((c)>='0' && (c)<='9')
#define HEXCHK(c) (((c) >= '0' && (c)<='9') ((c)>='A' && (c)<= 'F') \
                ((c)>='a' && (c)<='f'))
#define INC_SAT(val) (val=((val)+1>(val)) ? (val)+1 : (val))
#define ARR_SIZE(a)  (sizeof((a))/sizeof((a[0])))

#define MOD_BY_POWER_OF_TWO( val, mod_by ) ((dword)(val) & (dword)((mod_by)-1))

#define inp(port) (*((volatile byte *)(port)))
#define inpw(port) (*((volatile word *)(port)))
#define inpdw(port) (*((volatile dword *)(port)))
#define outp(port,val) (*((volatile byte *)(port))=((byte)(val)))
#define outpw(port, val) (*((volatile word *)(port))=((word)(val)))
#define outpdw(port, val) (*((volatile dword *)(port))=((dword)(val)))

#define CPYMEM(dst, src, n)   (((u_char *) memcpy(dst, src, n)) + (n))


#ifdef _DEBUG
#define DEBUGMSG(msg,date) printf(msg);printf(鈥?d%d%d鈥?date,_LINE_,_FILE_)
#else
#define DEBUGMSG(msg,date)
#endif

#endif

