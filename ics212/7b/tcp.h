#include <stdio.h>
#include <string.h>
#include <errno.h>

#define NUM_FIELDS 9
#define MAX_FIELD_SIZE 4

#define SRC_SIZE 2      /* Two bytes for src.   */
#define DEST_SIZE 2     /* Two bytes for dest.  */
#define SEQ_SIZE 4      /* Four bytes for seq.  */
#define ACK_SIZE 4      /* Four bytes for ack   */ 
#define DOFF_SIZE 1     /* A byte for doff.     */
#define CNTL_SIZE 1     /* A byte for cntl.     */
#define WIN_SIZE 2      /* Two bytes for win.   */
#define CSUM_SIZE 2     /* Two bytes for csum.  */
#define URGP_SIZE 2     /* Two bytes for urgp.  */

#define DOFF_MASK 0xf0
#define CNTL_MASK 0x3f
#define URG_MASK 0x20
#define ACK_MASK 0x10
#define PSH_MASK 0x8
#define RST_MASK 0x4
#define SYN_MASK 0x2
#define FIN_MASK 0x1

enum fieldpos { SRC, DEST, SEQ, ACK, DOFF, CNTL, WIN, CSUM, URGP };

struct tcpHeader {
    unsigned char *field[NUM_FIELDS];
    short field_size[NUM_FIELDS];
    unsigned char src[SRC_SIZE];
    unsigned char dest[DEST_SIZE];
    unsigned char seq[SEQ_SIZE];
    unsigned char ack[ACK_SIZE];
    unsigned char doff[DOFF_SIZE];
    unsigned char cntl[CNTL_SIZE];
    unsigned char win[WIN_SIZE];
    unsigned char csum[CSUM_SIZE];
    unsigned char urgp[URGP_SIZE];
};

int init_header(struct tcpHeader *header);
int readfile(char[]);
void printheader(void);
unsigned int get_decval(unsigned char *field, short size);
void print_cntlflags(unsigned char cntl_field);
