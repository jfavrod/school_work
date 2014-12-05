/**********************************************************************
//
// NAME:        Jason Favrod
//
// HOMEWORK:    7b
//
// CLASS:       ICS 212
//
// INSTRUCTOR:  Ravi Narayan
//
// DATE:
//
// FILE:        
//
// DESCRIPTION:
//
***********************************************************************/
#include "tcp.h"

struct tcpHeader header;


int main(void)
{
    int err = 0;
    short num_headers = 3;
    char file0[] = "test.bin";
    char file1[] = "test1.bin";
    char file2[] = "test2.bin";
    char *headerFiles[3] = { file0, file1, file2 };

    init_header(&header);

    short i = 0;
    while (i < num_headers)
    {
        readfile(headerFiles[i]);
        printheader();
        printf("\n");
        i++;
    }

    return err;
}


/**********************************************************************
//
//  Function name:      init_header
//
//  DESCRIPTION:        
//
//  Parameters:         
//
//  Return values:      0 : Success
//
**********************************************************************/

int init_header(struct tcpHeader *header)
{
    int err = 0;
    short i = 0;

    short field_size[NUM_FIELDS];
    field_size[SRC] = SRC_SIZE;
    field_size[DEST] = DEST_SIZE;
    field_size[SEQ] = SEQ_SIZE;
    field_size[ACK] = ACK_SIZE;
    field_size[DOFF] = DOFF_SIZE;
    field_size[CNTL] = CNTL_SIZE;
    field_size[WIN] = WIN_SIZE;
    field_size[CSUM] = CSUM_SIZE;
    field_size[URGP] = URGP_SIZE;

    header->field[SRC] = &(header->src[0]);
    header->field[DEST] = &(header->dest[0]);
    header->field[SEQ] = &(header->seq[0]);
    header->field[ACK] = &(header->ack[0]);
    header->field[DOFF] = header->doff;
    header->field[CNTL] = header->cntl;
    header->field[WIN] = &(header->win[0]);
    header->field[CSUM] = &(header->csum[0]);
    header->field[URGP] = &(header->urgp[0]);

    for (i = 0; i < NUM_FIELDS; i++)
    {
        header->field_size[i] = field_size[i];
    }

    return err;
}


/**********************************************************************
//
//  Function name:      readfile
//
//  DESCRIPTION:
//
//  Parameters:
//
//  Return values:      0 : Success
//                      2 : ENOENT
//
**********************************************************************/

int readfile(char headerFilename[])
{
    int err = 0;
    short i = 0;
    FILE *headerFile;

    if ((headerFile = fopen(headerFilename, "rb")))
    {
        for (i = 0; i < NUM_FIELDS; i++)
        {
            fread(header.field[i], 1, header.field_size[i], headerFile);
        }
        /* Set reserved portion of doff field to 0
         * move doff bits to beginning of char. */
        header.doff[0] = header.doff[0] & DOFF_MASK;
        *(header.doff) = header.doff[0] >> 4;
        /* Set reserved portion of cntl field to 0 */
        *(header.cntl) = header.cntl[0] & CNTL_MASK;
        /* Set window field to 0 */
        *(header.win) = 0;
        /* Set checksum field to 0xff */
        *(header.csum) = 0xff;
        /* Set urgent pointer field to 0 */
        *(header.urgp) = 0;

        fclose(headerFile);
    }
    else 
    {
        err = ENOENT;
    }

    return err;
}


/**********************************************************************
//
//  Function name:      printheader
//
//  DESCRIPTION:        
//
//  Parameters:         
//
//  Return values:      0 : Success
//
**********************************************************************/

void printheader(void)
{
    printf("Source: %u\nDestination: %u\nSeq No: %u\nAck No: %u\n",
            get_decval(&(header.src[0]), SRC_SIZE),
            get_decval(&(header.dest[0]), DEST_SIZE),
            get_decval(&(header.seq[0]), SEQ_SIZE),
            get_decval(&(header.ack[0]), ACK_SIZE)
            );
    printf("Data Offset: %u\nControl Flags: ", header.doff[0]);
    print_cntlflags(header.cntl[0]);
    printf("Window: %u\nChecksum: %x\nUrgent Pointer: %u\n",
            get_decval(&(header.win[0]), WIN_SIZE),
            get_decval(&(header.csum[0]), CSUM_SIZE),
            get_decval(&(header.urgp[0]), URGP_SIZE)
            );
    return;
}


/**********************************************************************
//
//  Function name:      get_decval
//
//  DESCRIPTION:        
//
//  Parameters:         
//
//  Return values:
//
**********************************************************************/

unsigned int get_decval(unsigned char *field, short size)
{
    unsigned int decval= 0;
    if (size == 2)
        decval = (field[0] << 8 | field[1]);
    if (size == 4)
        decval = (field[0] << 24 | field[1] << 16 | field[2] << 8 | field[3]);
    return decval;
}


/**********************************************************************
//
//  Function name:      print_cntlflags
//
//  DESCRIPTION:        
//
//  Parameters:         
//
//  Return values:
//
**********************************************************************/

void print_cntlflags(unsigned char cntl_field)
{
    if (cntl_field & URG_MASK)
        printf("URG ");
    if (cntl_field & ACK_MASK)
        printf("ACK ");
    if (cntl_field & PSH_MASK)
        printf("PSH ");
    if (cntl_field & RST_MASK)
        printf("RST ");
    if (cntl_field & SYN_MASK)
        printf("SYN ");
    if (cntl_field & FIN_MASK)
        printf("FIN ");
    printf("\n");
    return;
}
